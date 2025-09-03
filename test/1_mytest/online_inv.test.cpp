#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "mod/modint.hpp"
#include "random/base.hpp"
#include "poly/fps_inv.hpp"
#include "poly/online/online_inv.hpp"

using mint = modint998;

void test() {
  auto gen = [&](int n) -> vc<mint> {
    vc<mint> f(n + 1);
    FOR(i, n + 1) f[i] = RNG(mint::get_mod());
    return f;
  };
  FOR(n, 1000) {
    vc<mint> f = gen(n);
    f[0] = mint(1);
    vc<mint> g = fps_inv<mint>(f);
    Online_Inv<mint> X;
    FOR(i, n + 1) { assert(g[i] == X.query(i, f[i])); }
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