#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "seq/famous/gray_code.hpp"

void test() {
  FOR(LOG, 10) {
    auto G = gray_code(LOG);
    FOR(i, len(G) - 1) {
      int j = (i + 1 == len(G) ? 0 : i + 1);
      int x = G[i] ^ G[j];
      assert(popcnt(x) == 1);
    }
    assert(len(G) == 1 << LOG);
    UNIQUE(G);
    assert(len(G) == 1 << LOG);
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
