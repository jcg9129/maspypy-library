#define PROBLEM "https://yukicoder.me/problems/no/899"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/ds/bfs_numbering.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "alg/acted_monoid/sum_mul.hpp"

void solve() {
  LL(N);
  Graph<int> G(N);
  G.read_tree(0, 0);

  BFS_Numbering<decltype(G)> BFS(G);
  auto &ID = BFS.ID;
  vi seg_raw(N);

  FOR(v, N) {
    LL(a);
    seg_raw[ID[v]] = a;
  }

  using AM = ActedMonoid_Sum_Mul<ll>;
  Lazy_SegTree<AM> seg(seg_raw);

  LL(Q);
  FOR(_, Q) {
    LL(v);
    ll p = BFS.parent[v];
    ll pp = (p == -1 ? -1 : BFS.parent[p]);
    ll x = 0;
    if (pp >= 0) x += seg.get(ID[pp]), seg.set(ID[pp], 0);
    if (p >= 0) {
      x += seg.get(ID[p]), seg.set(ID[p], 0);
      auto [l, r] = BFS.calc_range(p, BFS.depth[p] + 1);
      x += seg.prod(l, r), seg.apply(l, r, 0);
    }
    FOR(d, 3) {
      auto [l, r] = BFS.calc_range(v, BFS.depth[v] + d);
      x += seg.prod(l, r), seg.apply(l, r, 0);
    }
    print(x);
    seg.set(ID[v], x);
  }
}

signed main() {
  solve();
  return 0;
}
