#define PROBLEM "https://yukicoder.me/problems/no/1441"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/splaytree/splaytree_monoid.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  SplayTree_Monoid<Monoid_Add<ll>> ST(N);
  auto root = ST.new_node(A);
  FOR(Q) {
    LL(t, l, r);
    --l;
    if (t == 1) {
      ST.goto_between(root, l, r);
      root->l = nullptr;
      root->r = nullptr;
      root->x = root->prod;
      root->update();
      ST.splay(root, true);
    }
    if (t == 2) { print(ST.prod(root, l, r)); }
  }
}

signed main() {
  solve();
  return 0;
}