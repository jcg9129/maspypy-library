#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "nt/coprime_factorization.hpp"

void test() {
  FOR(N, 0, 100) {
    vc<ll> dat(N);
    FOR(i, N) dat[i] = RNG(1, infty<ll>);
    auto [basis, pfs] = coprime_factorization(dat);
    FOR(j, len(basis)) FOR(i, j) { assert(gcd(basis[i], basis[j]) == 1); }
    FOR(i, N) {
      ll x = 1;
      for (auto&& [pid, exp]: pfs[i]) { FOR(exp) x *= basis[pid]; }
      assert(x == dat[i]);
    }
  }

  FOR(N, 0, 100) {
    vc<ll> dat(N);
    FOR(i, N) dat[i] = RNG(1, 20);
    auto [basis, pfs] = coprime_factorization(dat);
    FOR(j, len(basis)) FOR(i, j) { assert(gcd(basis[i], basis[j]) == 1); }
    FOR(i, N) {
      ll x = 1;
      for (auto&& [pid, exp]: pfs[i]) { FOR(exp) x *= basis[pid]; }
      assert(x == dat[i]);
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
