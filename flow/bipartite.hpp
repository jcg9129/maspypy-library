#include "graph/base.hpp"
#include "graph/check_bipartite.hpp"
#include "graph/strongly_connected_component.hpp"

template <typename GT>
struct BipartiteMatching {
  int N;
  GT& G;
  vc<int> color;
  vc<int> dist, match;
  vc<int> vis;

  BipartiteMatching(GT& G) : N(G.N), G(G), dist(G.N, -1), match(G.N, -1) {
    color = check_bipartite(G);
    assert(!color.empty());
    while (1) {
      bfs();
      vis.assign(N, false);
      int flow = 0;
      FOR(v, N) if (!color[v] && match[v] == -1 && dfs(v))++ flow;
      if (!flow) break;
    }
  }

  BipartiteMatching(GT& G, vc<int> color)
      : N(G.N), G(G), color(color), dist(G.N, -1), match(G.N, -1) {
    while (1) {
      bfs();
      vis.assign(N, false);
      int flow = 0;
      FOR(v, N) if (!color[v] && match[v] == -1 && dfs(v))++ flow;
      if (!flow) break;
    }
  }

  void bfs() {
    dist.assign(N, -1);
    queue<int> que;
    FOR(v, N) if (!color[v] && match[v] == -1) que.emplace(v), dist[v] = 0;
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto&& e: G[v]) {
        dist[e.to] = 0;
        int w = match[e.to];
        if (w != -1 && dist[w] == -1) dist[w] = dist[v] + 1, que.emplace(w);
      }
    }
  }

  bool dfs(int v) {
    vis[v] = 1;
    for (auto&& e: G[v]) {
      int w = match[e.to];
      if (w == -1 || (!vis[w] && dist[w] == dist[v] + 1 && dfs(w))) {
        match[e.to] = v, match[v] = e.to;
        return true;
      }
    }
    return false;
  }

  vc<pair<int, int>> matching() {
    vc<pair<int, int>> res;
    FOR(v, N) if (v < match[v]) res.eb(v, match[v]);
    return res;
  }

  vc<int> vertex_cover() {
    vc<int> res;
    FOR(v, N) if (color[v] ^ (dist[v] == -1)) { res.eb(v); }
    return res;
  }

  vc<int> independent_set() {
    vc<int> res;
    FOR(v, N) if (!(color[v] ^ (dist[v] == -1))) { res.eb(v); }
    return res;
  }

  vc<int> edge_cover() {
    vc<bool> done(N);
    vc<int> res;
    for (auto&& e: G.edges) {
      if (done[e.frm] || done[e.to]) continue;
      if (match[e.frm] == e.to) {
        res.eb(e.id);
        done[e.frm] = done[e.to] = 1;
      }
    }
    for (auto&& e: G.edges) {
      if (!done[e.frm]) {
        res.eb(e.id);
        done[e.frm] = 1;
      }
      if (!done[e.to]) {
        res.eb(e.id);
        done[e.to] = 1;
      }
    }
    sort(all(res));
    return res;
  }

  /* Dulmage–Mendelsohn decomposition
  http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf
  https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp.html
  - 最大マッチングとしてありうるもの：同じ W を持つ点のみ
  - color=0 から 1 への辺：W(l) <= W(r)
  - color=0 かつ W=0 の点：必ず使われる
  - color=1 かつ W=K の点：必ず使われる
  - 1 <= k < K：任意の最大マッチングについて、すべての点が使われる
  - color=0 の点が必ず使われる：W=0,1,...,K-1
  - color=1 の点が必ず使われる：W=1,2,...,K
  - 辺uvが必ず使われる：同じ W を持つ辺が唯一
  */
  pair<int, vc<int>> DM_decomposition() {
    // 非飽和点からの探索
    vc<int> W(N, -1);
    int INF = N + 10;
    vc<int> que;
    auto add = [&](int v, int x) -> void {
      if (W[v] == -1) {
        W[v] = x;
        que.eb(v);
      }
    };
    FOR(v, N) if (match[v] == -1 && color[v] == 0) add(v, 0);
    FOR(v, N) if (match[v] == -1 && color[v] == 1) add(v, INF);
    while (len(que)) {
      auto v = pick(que);
      if (match[v] != -1) add(match[v], W[v]);
      if (color[v] == 0 && W[v] == 0) {
        for (auto&& e: G[v]) { add(e.to, W[v]); }
      }
      if (color[v] == 1 && W[v] == INF) {
        for (auto&& e: G[v]) { add(e.to, W[v]); }
      }
    }
    // 残った点からなるグラフを作って強連結成分分解
    vc<int> V;
    FOR(v, N) if (W[v] == -1) V.eb(v);
    int n = len(V);
    Graph<bool, 1> DG(n);
    FOR(i, n) {
      int v = V[i];
      if (match[v] != -1) {
        int j = LB(V, match[v]);
        DG.add(i, j);
      }
      if (color[v] == 0) {
        for (auto&& e: G[v]) {
          if (W[e.to] != -1 || e.to == match[v]) continue;
          int j = LB(V, e.to);
          DG.add(i, j);
        }
      }
    }
    DG.build();
    auto [K, comp] = strongly_connected_component(DG);
    K += 1;
    // 答
    FOR(i, n) { W[V[i]] = 1 + comp[i]; }
    FOR(v, N) if (W[v] == INF) W[v] = K;
    return {K, W};
  }

  void debug() {
    print("match", match);
    print("min vertex covor", vertex_cover());
    print("max indep set", independent_set());
    print("min edge cover", edge_cover());
  }
};