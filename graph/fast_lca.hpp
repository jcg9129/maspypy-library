#include "graph/tree.hpp"
#include "alg/monoid/min_idx.hpp"
#include "alg/monoid/min.hpp"
#include "ds/static_range_product.hpp"

template <typename TREE>
struct Fast_Lca {
  TREE& tree;
  using Mono = Monoid_Min<int>;
  Sparse_Table<Monoid_Min<int>> seg;
  vc<int> pos;

  Fast_Lca(TREE& tree) : tree(tree) {
    int N = tree.N;
    pos.resize(N);
    vc<int> dat(2 * N);
    FOR(v, N) {
      int a = tree.ELID(v);
      int b = tree.ERID(v);
      pos[v] = a;
      dat[a] = tree.LID[v];
      dat[b] = (v == tree.V[0] ? -1 : tree.LID[tree.parent[v]]);
    }
    seg.build(dat);
  }

  int dist(int a, int b) {
    int c = lca(a, b);
    return tree.depth[a] + tree.depth[b] - 2 * tree.depth[c];
  }

  int lca(int a, int b) {
    int p = pos[a], q = pos[b];
    if (p > q) swap(p, q);
    return tree.V[seg.prod(p, q + 1)];
  }
};