#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "linalg/blackbox/min_poly.hpp"
#include "linalg/matrix_mul.hpp"

using mint = modint998;

void test() {
  vc<tuple<int, int, mint>> A;
  A.eb(0, 0, 1);
  A.eb(0, 1, 2);
  A.eb(1, 0, 3);
  A.eb(1, 1, 4);
  vc<mint> f = blackbox_min_poly<mint>(2, [&](vc<mint> f) -> vc<mint> {
    vc<mint> g(2);
    for (auto& [a, b, c]: A) g[b] += f[a] * c;
    return g;
  });
  assert(f == vc<mint>({mint(-2), mint(-5), mint(1)}));

  A.clear();
  A.eb(0, 1, 1);
  f = blackbox_min_poly<mint>(2, [&](vc<mint> f) -> vc<mint> {
    vc<mint> g(2);
    for (auto& [a, b, c]: A) g[b] += f[a] * c;
    return g;
  });
  assert(f == vc<mint>({mint(0), mint(0), mint(1)}));

  A.clear();
  f = blackbox_min_poly<mint>(2, [&](vc<mint> f) -> vc<mint> {
    vc<mint> g(2);
    for (auto& [a, b, c]: A) g[b] += f[a] * c;
    return g;
  });
  assert(f == vc<mint>({mint(0), mint(1)}));

  A.clear();
  f = blackbox_min_poly<mint>(0, [&](vc<mint> f) -> vc<mint> {
    vc<mint> g(0);
    for (auto& [a, b, c]: A) g[b] += f[a] * c;
    return g;
  });
  assert(f == vc<mint>({mint(1)}));

  A.clear();
  A.eb(0, 1, 1);
  A.eb(0, 2, 1);
  A.eb(1, 2, 1);
  f = blackbox_min_poly<mint>(3, [&](vc<mint> f) -> vc<mint> {
    vc<mint> g(3);
    for (auto& [a, b, c]: A) g[b] += f[a] * c;
    return g;
  });
  assert(f == vc<mint>({mint(0), mint(0), mint(0), mint(1)}));

  A.clear();
  f = blackbox_min_poly<mint>(3, [&](vc<mint> a) -> vc<mint> {
    vc<mint> b(3);
    for (auto&& [i, j, x]: A) b[j] += a[i] * x;
    return b;
  });
  assert(f == vc<mint>({mint(0), mint(1)}));

  // random matrix
  FOR(N, 1, 20) {
    vv(mint, mat, N, N);
    FOR(i, N) FOR(j, N) mat[i][j] = RNG(0, 998244353);
    A.clear();
    FOR(i, N) FOR(j, N) A.eb(i, j, mat[i][j]);
    f = blackbox_min_poly<mint>(N, [&](vc<mint> a) -> vc<mint> {
      vc<mint> b(N);
      for (auto&& [i, j, x]: A) b[j] += a[i] * x;
      return b;
    });
    vv(mint, B, N, N);
    FOR(i, N) B[i][i] = 1;
    vv(mint, C, N, N);
    FOR(d, len(f)) {
      FOR(i, N) FOR(j, N) C[i][j] += f[d] * B[i][j];
      B = matrix_mul(mat, B);
    }
    FOR(i, N) FOR(j, N) assert(C[i][j] == mint(0));
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