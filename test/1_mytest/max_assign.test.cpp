#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "alg/acted_monoid/max_assign.hpp"
#include "random/base.hpp"
#include "ds/segtree/lazy_segtree.hpp"

void test() {
  int N = RNG(1, 100);
  vc<int> A(N);
  FOR(i, N) A[i] = RNG(1, 100);
  Lazy_SegTree<ActedMonoid_Max_Assign<int, -1>> seg(A);
  int Q = RNG(1, 100);
  FOR(Q) {
    ll t = RNG(0, 2);
    ll L = RNG(0, N);
    ll R = RNG(0, N);
    if (L > R) swap(L, R);
    ++R;
    if (t == 1) {
      ll x = RNG(1, 100);
      FOR(i, L, R) A[i] = x;
      seg.apply(L, R, x);
    }
    if (t == 2) {
      vc<int> B = {A.begin() + L, A.begin() + R};
      assert(seg.prod(L, R) == MAX(B));
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);
  FOR(100) test();
  solve();

  return 0;
}
