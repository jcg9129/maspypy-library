#define PROBLEM "https://yukicoder.me/problems/no/1036"

#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_segtree.hpp"
#include "alg/monoid/gcd.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  auto f = [&](ll L, ll R) -> ll { return 0; };
  Dynamic_SegTree<Monoid_Gcd<ll>, false, decltype(f)> seg(0, N, f);
  seg.reserve(2 * N);
  int root = seg.new_node(A);

  ll ANS1 = 0;
  FOR(L, N) {
    auto check = [&](auto e) -> bool { return e != 1; };
    auto R = seg.max_right(root, check, L);
    ANS1 += N - R;
  }
  ll ANS2 = 0;
  FOR(R, 1, N + 1) {
    auto check = [&](auto e) -> bool { return e != 1; };
    auto L = seg.min_left(root, check, R);
    ANS2 += L;
  }
  assert(ANS1 == ANS2);
  print(ANS1);
}

signed main() {
  solve();
  return 0;
}
