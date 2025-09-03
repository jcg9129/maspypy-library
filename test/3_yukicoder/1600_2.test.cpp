#define PROBLEM "https://yukicoder.me/problems/no/1600"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/wavelet_matrix/wavelet_matrix_2d_range.hpp"
#include "ds/static_range_product.hpp"

#include "alg/monoid/min.hpp"
#include "graph/tree.hpp"
#include "ds/unionfind/unionfind.hpp"

#include "mod/modint.hpp"
using mint = modint107;

void solve() {
  LL(N, M);
  Graph<mint, 0> G(N);
  UnionFind uf(N);
  vc<pair<int, int>> edges;
  vc<bool> in_G(M);
  mint wt = 1;
  FOR(i, M) {
    LL(a, b);
    --a, --b;
    edges.eb(a, b);
    wt += wt;
    if (uf.merge(a, b)) {
      in_G[i] = 1;
      G.add(a, b, wt);
    }
  }
  G.build();

  Tree<decltype(G)> tree(G);
  auto& par = tree.parent;
  vc<int> X, Y, W;
  FOR(e, M) {
    if (in_G[e]) continue;
    auto [a, b] = edges[e];
    a = tree.LID[a], b = tree.LID[b];
    if (a > b) swap(a, b);
    X.eb(a), Y.eb(b), W.eb(e);
  }

  using Mono = Monoid_Min<int>;
  using ST = Sparse_Table<Mono>;
  Wavelet_Matrix_2D_Range<int, true, true, Static_Range_Product<Mono, ST>> seg(
      len(X), [&](int i) -> tuple<int, int, int> {
        return {X[i], Y[i], W[i]};
      });

  LL(Q);
  FOR(Q) {
    LL(u, v, idx);
    --u, --v, --idx;
    auto [x, y] = edges[idx];
    if (par[y] == x) swap(x, y);
    bool in_u = tree.in_subtree(u, x);
    bool in_v = tree.in_subtree(v, x);
    if (!in_G[idx] || in_u == in_v) {
      print(tree.dist_weighted(u, v));
      continue;
    }
    // 木の外に出る移動が必要
    int l = tree.LID[x], r = tree.RID[x];
    int min_i = Mono::op(seg.prod(0, l, l, r), seg.prod(l, r, r, N));
    if (min_i == Mono::unit()) {
      print(-1);
      continue;
    }
    auto [p, q] = edges[min_i];
    bool in_p = tree.in_subtree(p, x);
    if (!in_u) swap(u, v);
    if (!in_p) swap(p, q);
    mint ANS = tree.dist_weighted(u, p) + tree.dist_weighted(v, q);
    ANS += mint(2).pow(min_i + 1);
    print(ANS);
  }
}

signed main() {
  solve();
  return 0;
}
