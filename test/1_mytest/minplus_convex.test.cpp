#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "random/base.hpp"
#include "convex/minplus_convolution.hpp"

vc<int> gen(int L, int N, int R, bool convex) {
  vc<int> A(N);
  FOR(i, N) A[i] = RNG(-100, 100);
  if (!convex) return A;
  sort(all(A));
  A = cumsum<int>(A);
  FOR(L) A.insert(A.begin(), infty<int>);
  FOR(R) A.insert(A.end(), infty<int>);
  return A;
}

vc<int> naive(vc<int> A, vc<int> B) {
  int N = len(A), M = len(B);
  vc<int> C(N + M - 1, infty<int>);
  FOR(i, N) FOR(j, M) {
    if (A[i] == infty<int> || B[j] == infty<int>) continue;
    chmin(C[i + j], A[i] + B[j]);
  }
  return C;
}

void test() {
  FOR(a1, 5) FOR(b1, 1, 10) FOR(c1, 5) {
    vc<int> A = gen(a1, b1, c1, true);
    FOR(a2, 5) FOR(b2, 1, 10) FOR(c2, 5) {
      vc<int> B = gen(a2, b2, c2, true);
      vc<int> C = minplus_convolution<int, 1, 1>(A, B);
      assert(naive(A, B) == C);
    }
  }
  FOR(a1, 5) FOR(b1, 1, 10) FOR(c1, 5) {
    vc<int> A = gen(a1, b1, c1, true);
    FOR(a2, 5) FOR(b2, 1, 10) FOR(c2, 5) {
      vc<int> B = gen(a2, b2, c2, false);
      vc<int> C = minplus_convolution<int, 1, false>(A, B);
      assert(naive(A, B) == C);
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
