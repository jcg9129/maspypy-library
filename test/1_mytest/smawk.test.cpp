#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "convex/smawk.hpp"

void test() {
  vv(int, A, 4, 5);
  A[0] = {0, 1, 3, 2, 4};
  A[1] = {0, 2, 4, 3, 1};
  A[2] = {1, 3, 4, 2, 0};
  A[3] = {4, 2, 3, 1, 0};
  auto f = [&](int i, int j, int k) -> int { return A[i][j] > A[i][k]; };

  vc<int> I = smawk(4, 5, f);
  vc<int> J = {0, 0, 4, 4};
  assert(I == J);
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