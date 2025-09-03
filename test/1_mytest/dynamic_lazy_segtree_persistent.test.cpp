#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "alg/acted_monoid/summax_assign.hpp"
#include "ds/segtree/dynamic_lazy_segtree.hpp"
#include "random/base.hpp"

void test() {
  using AM = ActedMonoid_SumMax_Assign<int, -1>;
  using P = typename AM::X;

  FOR(100) {
    int N = RNG(1, 1000);

    vvc<int> AA;
    AA.eb(vc<int>(N, 10));
    Dynamic_Lazy_SegTree<AM, true> X(30000, 0, N, [](ll l, ll r) -> P { return {10 * (r - l), 10}; });
    using np = typename decltype(X)::np;

    int Q = RNG(1, 1000);
    vc<np> roots;
    roots.eb(X.new_node(0, N));

    FOR(Q) {
      int time = RNG(0, len(roots));
      vc<int> A = AA[time];
      np root = roots[time];
      int L = RNG(0, N);
      int R = RNG(0, N);
      if (L > R) swap(L, R);
      ++R;

      int t = RNG(0, 4);
      if (t == 0) {
        int i = RNG(0, N);
        int x = RNG(1, 100);
        root = X.set(root, i, {x, x});
        A[i] = x;
      }
      if (t == 1) {
        vc<int> B = {A.begin() + L, A.begin() + R};
        assert(X.prod(root, L, R).fi == SUM<int>(B));
        assert(X.prod(root, L, R).se == MAX(B));
      }
      if (t == 2) {
        int x = RNG(1, 100);
        FOR(i, L, R) A[i] = x;
        root = X.apply(root, L, R, x);
      }
      if (t == 3) {
        // max_right
        int LIM = R;
        auto check = [&](auto e) -> bool { return e.se <= LIM; };
        int naive = [&]() -> int {
          ll mx = 0;
          FOR(i, L, N) {
            chmax(mx, A[i]);
            if (mx > LIM) return i;
          }
          return N;
        }();

        assert(naive == X.max_right(root, check, L));
      }

      AA.eb(A);
      roots.eb(root);
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
