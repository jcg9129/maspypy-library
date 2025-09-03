#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/dynamic_array.hpp"

void solve() {
  LL(Q);
  vc<int> L, R;

  Dynamic_Array<int, true> X(2000000, 0);
  using np = typename decltype(X)::np;
  vc<np> roots;

  roots.eb(X.new_root());
  L.eb(0), R.eb(0);

  FOR(Q) {
    LL(t, k);
    ++k;
    np root = roots[k];
    int l = L[k], r = R[k];

    if (t == 0) {
      INT(x);
      root = X.set(root, r++, x);
    }
    if (t == 1) { print(X.get(root, l++)); }
    roots.eb(root);
    L.eb(l), R.eb(r);
  }
}

signed main() {
  solve();
  return 0;
}
