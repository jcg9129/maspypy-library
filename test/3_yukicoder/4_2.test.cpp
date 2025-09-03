#define PROBLEM "https://yukicoder.me/problems/no/4"
#include "my_template.hpp"
#include "other/io.hpp"
#include "knapsack/subset_sum.hpp"

void solve() {
  LL(N);
  VEC(int, A, N);
  ll S = SUM<int>(A);
  auto I = subset_sum<int>(A, S / 2);
  bool can = (S == 0 || len(I) > 0);
  if (can && S % 2 == 0) {
    print("possible");
  } else {
    print("impossible");
  }
}

signed main() {
  solve();
  return 0;
}
