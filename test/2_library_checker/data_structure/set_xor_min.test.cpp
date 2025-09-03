#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/binary_trie.hpp"
#include "ds/hashmap.hpp"

void solve() {
  INT(Q);
  HashMap<char> MP(Q);
  Binary_Trie<30, false, 1'000'000, int, int> X;
  using np = decltype(X)::np;
  np root = nullptr;
  FOR(Q) {
    INT(t, x);
    if (t == 0) {
      if (MP[x] == 0) {
        MP[x] = 1;
        root = X.add(root, x, 1);
      }
    }
    if (t == 1) {
      if (MP[x] == 1) {
        MP[x] = 0;
        root = X.add(root, x, -1);
      }
    }
    if (t == 2) { print(X.min(root, x)); }
  }
}

signed main() {
  solve();
  return 0;
}
