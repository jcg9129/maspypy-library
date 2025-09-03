#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "alg/acted_monoid/min_assign.hpp"
#include "ds/randomized_bst/rbst_acted_monoid.hpp"
#include "random/base.hpp"

void test() {
  using AM = ActedMonoid_Min_Assign<int, -1>;
  using MonoX = typename AM::Monoid_X;

  RBST_ActedMonoid<AM, false> X(100);
  FOR(1000) {
    X.reset();
    int N = RNG(1, 20);
    int Q = RNG(1, 1000);
    vc<int> A(N);
    FOR(i, N) A[i] = RNG(1, 100);
    auto root = X.new_node(A);

    FOR(Q) {
      int t = RNG(0, 7);
      if (t == 0) {
        int i = RNG(0, N);
        assert(A[i] == X.get(root, i));
      }
      if (t == 1) {
        int i = RNG(0, N);
        int x = RNG(1, 100);
        root = X.set(root, i, x);
        A[i] = x;
      }
      if (t == 2) {
        int i = RNG(0, N);
        int x = RNG(1, 100);
        root = X.multiply(root, i, x);
        A[i] = MonoX::op(A[i], x);
      }
      if (t == 3) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        vc<int> B = {A.begin() + L, A.begin() + R};
        assert(X.prod(root, L, R) == MIN(B));
      }
      if (t == 4) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        root = X.reverse(root, L, R);
        reverse(A.begin() + L, A.begin() + R);
      }
      if (t == 5) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        int x = RNG(1, 100);
        FOR(i, L, R) A[i] = x;
        root = X.apply(root, L, R, x);
      }
      if (t == 6) {
        vc<int> B = X.get_all(root);
        assert(A == B);
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();

  return 0;
}
