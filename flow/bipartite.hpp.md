---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_vertex_coloring.hpp
    title: graph/bipartite_vertex_coloring.hpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_edge_coloring.hpp
    title: graph/bipartite_edge_coloring.hpp
  - icon: ':heavy_check_mark:'
    path: graph/maximum_antichain.hpp
    title: graph/maximum_antichain.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1566.test.cpp
    title: test/aoj/1566.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_2.test.cpp
    title: test/aoj/2251_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/bipartite_edge_coloring.test.cpp
    title: test/library_checker/graph/bipartite_edge_coloring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/bipartitematching.test.cpp
    title: test/library_checker/graph/bipartitematching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/matching_ve.test.cpp
    title: test/mytest/matching_ve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/tutte.test.cpp
    title: test/mytest/tutte.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1479.test.cpp
    title: test/yukicoder/1479.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1744.test.cpp
    title: test/yukicoder/1744.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1745.test.cpp
    title: test/yukicoder/1745.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc237ex.test.cpp
    title: test_atcoder/abc237ex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc274g.test.cpp
    title: test_atcoder/abc274g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf
    - https://en.wikipedia.org/wiki/Dulmage%E2%80%93Mendelsohn_decomposition
    - https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp.html
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n#endif\n\n  void build() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges)\
    \ {\n      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n  \
    \  }\n    for (int v = 0; v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n\
    \      print(\"frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to,\
    \ e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n      print(\"\
    frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to,\
    \ e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\
    \n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n\
    \    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) != M)\
    \ used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] = i;\n\
    \    Graph<T, directed> G(n);\n    vc<int> history;\n    FOR(i, n) {\n      for\
    \ (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          history.eb(e.id);\n          used_e[e.id] = 1;\n          int eid =\
    \ (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost, eid);\n\
    \        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for (auto&&\
    \ eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\nprivate:\n\
    \  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n   \
    \ for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 2 \"graph/bipartite_vertex_coloring.hpp\"\n\r\n#line 2 \"ds/unionfind/unionfind.hpp\"\
    \n\nstruct UnionFind {\n  int n, n_comp;\n  vc<int> dat; // par or (-size)\n \
    \ UnionFind(int n = 0) { build(n); }\n\n  void build(int m) {\n    n = m, n_comp\
    \ = m;\n    dat.assign(n, -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int\
    \ x) {\n    while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp <\
    \ 0) { return dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n\
    \  ll size(int x) {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int\
    \ x, int y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n\
    \    if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n};\n#line 5 \"graph/bipartite_vertex_coloring.hpp\"\n\r\
    \n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306A\u304B\u3063\u305F\u5834\u5408\u306B\
    \u306F empty\r\ntemplate <typename GT>\r\nvc<int> bipartite_vertex_coloring(GT&\
    \ G) {\r\n  assert(!GT::is_directed);\r\n  assert(G.is_prepared());\r\n\r\n  int\
    \ n = G.N;\r\n  UnionFind uf(2 * n);\r\n  for (auto&& e: G.edges) {\r\n    int\
    \ u = e.frm, v = e.to;\r\n    if (e.cost == 0) uf.merge(u, v), uf.merge(u + n,\
    \ v + n);\r\n    if (e.cost != 0) uf.merge(u + n, v), uf.merge(u, v + n);\r\n\
    \  }\r\n\r\n  vc<int> color(2 * n, -1);\r\n  FOR(v, n) if (uf[v] == v && color[uf[v]]\
    \ < 0) {\r\n    color[uf[v]] = 0;\r\n    color[uf[v + n]] = 1;\r\n  }\r\n  FOR(v,\
    \ n) color[v] = color[uf[v]];\r\n  color.resize(n);\r\n  FOR(v, n) if (uf[v] ==\
    \ uf[v + n]) return {};\r\n  return color;\r\n}\r\n#line 3 \"graph/strongly_connected_component.hpp\"\
    \n\ntemplate <typename GT>\npair<int, vc<int>> strongly_connected_component(GT&\
    \ G) {\n  static_assert(GT::is_directed);\n  assert(G.is_prepared());\n  int N\
    \ = G.N;\n  int C = 0;\n  vc<int> comp(N), low(N), ord(N, -1), path;\n  int now\
    \ = 0;\n\n  auto dfs = [&](auto& dfs, int v) -> void {\n    low[v] = ord[v] =\
    \ now++;\n    path.eb(v);\n    for (auto&& [frm, to, cost, id]: G[v]) {\n    \
    \  if (ord[to] == -1) {\n        dfs(dfs, to), chmin(low[v], low[to]);\n     \
    \ } else {\n        chmin(low[v], ord[to]);\n      }\n    }\n    if (low[v] ==\
    \ ord[v]) {\n      while (1) {\n        int u = POP(path);\n        ord[u] = N,\
    \ comp[u] = C;\n        if (u == v) break;\n      }\n      ++C;\n    }\n  };\n\
    \  FOR(v, N) {\n    if (ord[v] == -1) dfs(dfs, v);\n  }\n  FOR(v, N) comp[v] =\
    \ C - 1 - comp[v];\n  return {C, comp};\n}\n\ntemplate <typename GT>\nGraph<int,\
    \ 1> scc_dag(GT& G, int C, vc<int>& comp) {\n  Graph<int, 1> DAG(C);\n  vvc<int>\
    \ edges(C);\n  for (auto&& e: G.edges) {\n    int x = comp[e.frm], y = comp[e.to];\n\
    \    if (x == y) continue;\n    edges[x].eb(y);\n  }\n  FOR(c, C) {\n    UNIQUE(edges[c]);\n\
    \    for (auto&& to: edges[c]) DAG.add(c, to);\n  }\n  DAG.build();\n  return\
    \ DAG;\n}\n#line 4 \"flow/bipartite.hpp\"\n\r\ntemplate <typename GT>\r\nstruct\
    \ BipartiteMatching {\r\n  int N;\r\n  GT& G;\r\n  vc<int> color;\r\n  vc<int>\
    \ dist, match;\r\n  vc<int> vis;\r\n\r\n  BipartiteMatching(GT& G) : N(G.N), G(G),\
    \ dist(G.N, -1), match(G.N, -1) {\r\n    if (N == 0) return;\r\n    color = bipartite_vertex_coloring(G);\r\
    \n    assert(!color.empty());\r\n    while (1) {\r\n      bfs();\r\n      vis.assign(N,\
    \ false);\r\n      int flow = 0;\r\n      FOR(v, N) if (!color[v] && match[v]\
    \ == -1 && dfs(v))++ flow;\r\n      if (!flow) break;\r\n    }\r\n  }\r\n\r\n\
    \  BipartiteMatching(GT& G, vc<int> color)\r\n      : N(G.N), G(G), color(color),\
    \ dist(G.N, -1), match(G.N, -1) {\r\n    while (1) {\r\n      bfs();\r\n     \
    \ vis.assign(N, false);\r\n      int flow = 0;\r\n      FOR(v, N) if (!color[v]\
    \ && match[v] == -1 && dfs(v))++ flow;\r\n      if (!flow) break;\r\n    }\r\n\
    \  }\r\n\r\n  void bfs() {\r\n    dist.assign(N, -1);\r\n    queue<int> que;\r\
    \n    FOR(v, N) if (!color[v] && match[v] == -1) que.emplace(v), dist[v] = 0;\r\
    \n    while (!que.empty()) {\r\n      int v = que.front();\r\n      que.pop();\r\
    \n      for (auto&& e: G[v]) {\r\n        dist[e.to] = 0;\r\n        int w = match[e.to];\r\
    \n        if (w != -1 && dist[w] == -1) dist[w] = dist[v] + 1, que.emplace(w);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  bool dfs(int v) {\r\n    vis[v] = 1;\r\n  \
    \  for (auto&& e: G[v]) {\r\n      int w = match[e.to];\r\n      if (w == -1 ||\
    \ (!vis[w] && dist[w] == dist[v] + 1 && dfs(w))) {\r\n        match[e.to] = v,\
    \ match[v] = e.to;\r\n        return true;\r\n      }\r\n    }\r\n    return false;\r\
    \n  }\r\n\r\n  vc<pair<int, int>> matching() {\r\n    vc<pair<int, int>> res;\r\
    \n    FOR(v, N) if (v < match[v]) res.eb(v, match[v]);\r\n    return res;\r\n\
    \  }\r\n\r\n  vc<int> vertex_cover() {\r\n    vc<int> res;\r\n    FOR(v, N) if\
    \ (color[v] ^ (dist[v] == -1)) { res.eb(v); }\r\n    return res;\r\n  }\r\n\r\n\
    \  vc<int> independent_set() {\r\n    vc<int> res;\r\n    FOR(v, N) if (!(color[v]\
    \ ^ (dist[v] == -1))) { res.eb(v); }\r\n    return res;\r\n  }\r\n\r\n  vc<int>\
    \ edge_cover() {\r\n    vc<bool> done(N);\r\n    vc<int> res;\r\n    for (auto&&\
    \ e: G.edges) {\r\n      if (done[e.frm] || done[e.to]) continue;\r\n      if\
    \ (match[e.frm] == e.to) {\r\n        res.eb(e.id);\r\n        done[e.frm] = done[e.to]\
    \ = 1;\r\n      }\r\n    }\r\n    for (auto&& e: G.edges) {\r\n      if (!done[e.frm])\
    \ {\r\n        res.eb(e.id);\r\n        done[e.frm] = 1;\r\n      }\r\n      if\
    \ (!done[e.to]) {\r\n        res.eb(e.id);\r\n        done[e.to] = 1;\r\n    \
    \  }\r\n    }\r\n    sort(all(res));\r\n    return res;\r\n  }\r\n\r\n  /* Dulmage\u2013\
    Mendelsohn decomposition\r\n  https://en.wikipedia.org/wiki/Dulmage%E2%80%93Mendelsohn_decomposition\r\
    \n  http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf\r\
    \n  https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp.html\r\
    \n  - \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u3068\u3057\u3066\u3042\u308A\
    \u3046\u308B iff \u540C\u3058 W \u3092\u6301\u3064\r\n  - \u8FBA uv \u304C\u5FC5\
    \u305A\u4F7F\u308F\u308C\u308B\uFF1A\u540C\u3058 W \u3092\u6301\u3064\u8FBA\u304C\
    \u552F\u4E00\r\n  - color=0 \u304B\u3089 1 \u3078\u306E\u8FBA\uFF1AW[l] <= W[r]\r\
    \n  - color=0 \u306E\u70B9\u304C\u5FC5\u305A\u4F7F\u308F\u308C\u308B\uFF1AW=1,2,...,K\r\
    \n  - color=1 \u306E\u70B9\u304C\u5FC5\u305A\u4F7F\u308F\u308C\u308B\uFF1AW=0,1,...,K-1\r\
    \n  */\r\n  pair<int, vc<int>> DM_decomposition() {\r\n    // \u975E\u98FD\u548C\
    \u70B9\u304B\u3089\u306E\u63A2\u7D22\r\n    vc<int> W(N, -1);\r\n    vc<int> que;\r\
    \n    auto add = [&](int v, int x) -> void {\r\n      if (W[v] == -1) {\r\n  \
    \      W[v] = x;\r\n        que.eb(v);\r\n      }\r\n    };\r\n    FOR(v, N) if\
    \ (match[v] == -1 && color[v] == 0) add(v, 0);\r\n    FOR(v, N) if (match[v] ==\
    \ -1 && color[v] == 1) add(v, infty<int>);\r\n    while (len(que)) {\r\n     \
    \ auto v = POP(que);\r\n      if (match[v] != -1) add(match[v], W[v]);\r\n   \
    \   if (color[v] == 0 && W[v] == 0) {\r\n        for (auto&& e: G[v]) { add(e.to,\
    \ W[v]); }\r\n      }\r\n      if (color[v] == 1 && W[v] == infty<int>) {\r\n\
    \        for (auto&& e: G[v]) { add(e.to, W[v]); }\r\n      }\r\n    }\r\n   \
    \ // \u6B8B\u3063\u305F\u70B9\u304B\u3089\u306A\u308B\u30B0\u30E9\u30D5\u3092\u4F5C\
    \u3063\u3066\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\r\n    vc<int> V;\r\n \
    \   FOR(v, N) if (W[v] == -1) V.eb(v);\r\n    int n = len(V);\r\n    Graph<bool,\
    \ 1> DG(n);\r\n    FOR(i, n) {\r\n      int v = V[i];\r\n      if (match[v] !=\
    \ -1) {\r\n        int j = LB(V, match[v]);\r\n        DG.add(i, j);\r\n     \
    \ }\r\n      if (color[v] == 0) {\r\n        for (auto&& e: G[v]) {\r\n      \
    \    if (W[e.to] != -1 || e.to == match[v]) continue;\r\n          int j = LB(V,\
    \ e.to);\r\n          DG.add(i, j);\r\n        }\r\n      }\r\n    }\r\n    DG.build();\r\
    \n    auto [K, comp] = strongly_connected_component(DG);\r\n    K += 1;\r\n  \
    \  // \u7B54\r\n    FOR(i, n) { W[V[i]] = 1 + comp[i]; }\r\n    FOR(v, N) if (W[v]\
    \ == infty<int>) W[v] = K;\r\n    return {K, W};\r\n  }\r\n\r\n#ifdef FASTIO\r\
    \n  void debug() {\r\n    print(\"match\", match);\r\n    print(\"min vertex covor\"\
    , vertex_cover());\r\n    print(\"max indep set\", independent_set());\r\n   \
    \ print(\"min edge cover\", edge_cover());\r\n  }\r\n#endif\r\n};\r\n"
  code: "#include \"graph/base.hpp\"\r\n#include \"graph/bipartite_vertex_coloring.hpp\"\
    \r\n#include \"graph/strongly_connected_component.hpp\"\r\n\r\ntemplate <typename\
    \ GT>\r\nstruct BipartiteMatching {\r\n  int N;\r\n  GT& G;\r\n  vc<int> color;\r\
    \n  vc<int> dist, match;\r\n  vc<int> vis;\r\n\r\n  BipartiteMatching(GT& G) :\
    \ N(G.N), G(G), dist(G.N, -1), match(G.N, -1) {\r\n    if (N == 0) return;\r\n\
    \    color = bipartite_vertex_coloring(G);\r\n    assert(!color.empty());\r\n\
    \    while (1) {\r\n      bfs();\r\n      vis.assign(N, false);\r\n      int flow\
    \ = 0;\r\n      FOR(v, N) if (!color[v] && match[v] == -1 && dfs(v))++ flow;\r\
    \n      if (!flow) break;\r\n    }\r\n  }\r\n\r\n  BipartiteMatching(GT& G, vc<int>\
    \ color)\r\n      : N(G.N), G(G), color(color), dist(G.N, -1), match(G.N, -1)\
    \ {\r\n    while (1) {\r\n      bfs();\r\n      vis.assign(N, false);\r\n    \
    \  int flow = 0;\r\n      FOR(v, N) if (!color[v] && match[v] == -1 && dfs(v))++\
    \ flow;\r\n      if (!flow) break;\r\n    }\r\n  }\r\n\r\n  void bfs() {\r\n \
    \   dist.assign(N, -1);\r\n    queue<int> que;\r\n    FOR(v, N) if (!color[v]\
    \ && match[v] == -1) que.emplace(v), dist[v] = 0;\r\n    while (!que.empty())\
    \ {\r\n      int v = que.front();\r\n      que.pop();\r\n      for (auto&& e:\
    \ G[v]) {\r\n        dist[e.to] = 0;\r\n        int w = match[e.to];\r\n     \
    \   if (w != -1 && dist[w] == -1) dist[w] = dist[v] + 1, que.emplace(w);\r\n \
    \     }\r\n    }\r\n  }\r\n\r\n  bool dfs(int v) {\r\n    vis[v] = 1;\r\n    for\
    \ (auto&& e: G[v]) {\r\n      int w = match[e.to];\r\n      if (w == -1 || (!vis[w]\
    \ && dist[w] == dist[v] + 1 && dfs(w))) {\r\n        match[e.to] = v, match[v]\
    \ = e.to;\r\n        return true;\r\n      }\r\n    }\r\n    return false;\r\n\
    \  }\r\n\r\n  vc<pair<int, int>> matching() {\r\n    vc<pair<int, int>> res;\r\
    \n    FOR(v, N) if (v < match[v]) res.eb(v, match[v]);\r\n    return res;\r\n\
    \  }\r\n\r\n  vc<int> vertex_cover() {\r\n    vc<int> res;\r\n    FOR(v, N) if\
    \ (color[v] ^ (dist[v] == -1)) { res.eb(v); }\r\n    return res;\r\n  }\r\n\r\n\
    \  vc<int> independent_set() {\r\n    vc<int> res;\r\n    FOR(v, N) if (!(color[v]\
    \ ^ (dist[v] == -1))) { res.eb(v); }\r\n    return res;\r\n  }\r\n\r\n  vc<int>\
    \ edge_cover() {\r\n    vc<bool> done(N);\r\n    vc<int> res;\r\n    for (auto&&\
    \ e: G.edges) {\r\n      if (done[e.frm] || done[e.to]) continue;\r\n      if\
    \ (match[e.frm] == e.to) {\r\n        res.eb(e.id);\r\n        done[e.frm] = done[e.to]\
    \ = 1;\r\n      }\r\n    }\r\n    for (auto&& e: G.edges) {\r\n      if (!done[e.frm])\
    \ {\r\n        res.eb(e.id);\r\n        done[e.frm] = 1;\r\n      }\r\n      if\
    \ (!done[e.to]) {\r\n        res.eb(e.id);\r\n        done[e.to] = 1;\r\n    \
    \  }\r\n    }\r\n    sort(all(res));\r\n    return res;\r\n  }\r\n\r\n  /* Dulmage\u2013\
    Mendelsohn decomposition\r\n  https://en.wikipedia.org/wiki/Dulmage%E2%80%93Mendelsohn_decomposition\r\
    \n  http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf\r\
    \n  https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp.html\r\
    \n  - \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u3068\u3057\u3066\u3042\u308A\
    \u3046\u308B iff \u540C\u3058 W \u3092\u6301\u3064\r\n  - \u8FBA uv \u304C\u5FC5\
    \u305A\u4F7F\u308F\u308C\u308B\uFF1A\u540C\u3058 W \u3092\u6301\u3064\u8FBA\u304C\
    \u552F\u4E00\r\n  - color=0 \u304B\u3089 1 \u3078\u306E\u8FBA\uFF1AW[l] <= W[r]\r\
    \n  - color=0 \u306E\u70B9\u304C\u5FC5\u305A\u4F7F\u308F\u308C\u308B\uFF1AW=1,2,...,K\r\
    \n  - color=1 \u306E\u70B9\u304C\u5FC5\u305A\u4F7F\u308F\u308C\u308B\uFF1AW=0,1,...,K-1\r\
    \n  */\r\n  pair<int, vc<int>> DM_decomposition() {\r\n    // \u975E\u98FD\u548C\
    \u70B9\u304B\u3089\u306E\u63A2\u7D22\r\n    vc<int> W(N, -1);\r\n    vc<int> que;\r\
    \n    auto add = [&](int v, int x) -> void {\r\n      if (W[v] == -1) {\r\n  \
    \      W[v] = x;\r\n        que.eb(v);\r\n      }\r\n    };\r\n    FOR(v, N) if\
    \ (match[v] == -1 && color[v] == 0) add(v, 0);\r\n    FOR(v, N) if (match[v] ==\
    \ -1 && color[v] == 1) add(v, infty<int>);\r\n    while (len(que)) {\r\n     \
    \ auto v = POP(que);\r\n      if (match[v] != -1) add(match[v], W[v]);\r\n   \
    \   if (color[v] == 0 && W[v] == 0) {\r\n        for (auto&& e: G[v]) { add(e.to,\
    \ W[v]); }\r\n      }\r\n      if (color[v] == 1 && W[v] == infty<int>) {\r\n\
    \        for (auto&& e: G[v]) { add(e.to, W[v]); }\r\n      }\r\n    }\r\n   \
    \ // \u6B8B\u3063\u305F\u70B9\u304B\u3089\u306A\u308B\u30B0\u30E9\u30D5\u3092\u4F5C\
    \u3063\u3066\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\r\n    vc<int> V;\r\n \
    \   FOR(v, N) if (W[v] == -1) V.eb(v);\r\n    int n = len(V);\r\n    Graph<bool,\
    \ 1> DG(n);\r\n    FOR(i, n) {\r\n      int v = V[i];\r\n      if (match[v] !=\
    \ -1) {\r\n        int j = LB(V, match[v]);\r\n        DG.add(i, j);\r\n     \
    \ }\r\n      if (color[v] == 0) {\r\n        for (auto&& e: G[v]) {\r\n      \
    \    if (W[e.to] != -1 || e.to == match[v]) continue;\r\n          int j = LB(V,\
    \ e.to);\r\n          DG.add(i, j);\r\n        }\r\n      }\r\n    }\r\n    DG.build();\r\
    \n    auto [K, comp] = strongly_connected_component(DG);\r\n    K += 1;\r\n  \
    \  // \u7B54\r\n    FOR(i, n) { W[V[i]] = 1 + comp[i]; }\r\n    FOR(v, N) if (W[v]\
    \ == infty<int>) W[v] = K;\r\n    return {K, W};\r\n  }\r\n\r\n#ifdef FASTIO\r\
    \n  void debug() {\r\n    print(\"match\", match);\r\n    print(\"min vertex covor\"\
    , vertex_cover());\r\n    print(\"max indep set\", independent_set());\r\n   \
    \ print(\"min edge cover\", edge_cover());\r\n  }\r\n#endif\r\n};\r\n"
  dependsOn:
  - graph/base.hpp
  - graph/bipartite_vertex_coloring.hpp
  - ds/unionfind/unionfind.hpp
  - graph/strongly_connected_component.hpp
  isVerificationFile: false
  path: flow/bipartite.hpp
  requiredBy:
  - graph/bipartite_edge_coloring.hpp
  - graph/maximum_antichain.hpp
  timestamp: '2023-11-10 11:57:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1479.test.cpp
  - test/yukicoder/1744.test.cpp
  - test/yukicoder/1745.test.cpp
  - test/mytest/tutte.test.cpp
  - test/mytest/matching_ve.test.cpp
  - test/library_checker/graph/bipartitematching.test.cpp
  - test/library_checker/graph/bipartite_edge_coloring.test.cpp
  - test/aoj/1566.test.cpp
  - test/aoj/2251_2.test.cpp
  - test_atcoder/abc237ex.test.cpp
  - test_atcoder/abc274g.test.cpp
documentation_of: flow/bipartite.hpp
layout: document
redirect_from:
- /library/flow/bipartite.hpp
- /library/flow/bipartite.hpp.html
title: flow/bipartite.hpp
---