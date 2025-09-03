#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "random/base.hpp"
#include "mod/max_of_linear_segments.hpp"

pair<vc<int>, vc<int>> naive(int a, int b, int mod) {
  assert(0 <= a && a < mod);
  assert(0 <= b && b < mod);
  vc<int> A;
  int last_y = b;
  FOR(x, 1, mod + 1) {
    int y = (ll(a) * x + b) % mod;
    if (chmax(last_y, y)) A.eb(x);
  }
  vc<int> X = {0};
  vc<int> DX;
  int dx = -1;
  for (auto&& x: A) {
    if (X.back() + dx == x) {
      X.back() = x;
    } else {
      dx = x - X.back();
      DX.eb(dx);
      X.eb(x);
    }
  }
  return {X, DX};
}

void test() {
  FOR(mod, 1, 1000) {
    FOR(10) {
      int a = RNG(0, mod);
      int b = RNG(0, mod);
      auto [X1, DX1] = naive(a, b, mod);
      auto [X2, DX2] = max_of_linear_segments(a, b, mod);
      assert(X1 == X2);
      assert(DX1 == DX2);
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
