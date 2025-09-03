#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "random/base.hpp"

#include "mod/modint.hpp"

using mint = modint998;

void test() {
  FOR(100000) {
    int n = RNG(0, 1000);
    int k = RNG(0, 1000);
    mint a = C<mint>(n, k);
    mint b = C<mint, 0, 1>(n, k);
    mint c = C<mint, 1, 0>(n, k);
    assert(a == b && b == c);
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
