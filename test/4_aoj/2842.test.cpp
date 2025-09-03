#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/fenwicktree/fenwicktree_2d_dense.hpp"

void solve() {
  LL(H, W, T, Q);
  deque<tuple<ll, ll, ll>> que;
  vv(ll, time, H, W, infty<ll>);

  FenwickTree_2D_Dense<Monoid_Add<ll>> A(H, W);
  FenwickTree_2D_Dense<Monoid_Add<ll>> B(H, W);

  deque<tuple<ll, ll, ll>> end;

  FOR(Q) {
    LL(t, c, x, y);
    --x, --y;
    while (len(end) && get<2>(end.front()) <= t) {
      auto [x, y, t] = end.front();
      end.pop_front();
      A.add(x, y, 1);
      B.add(x, y, -1);
    }
    if (c == 0) {
      B.add(x, y, 1);
      end.eb(x, y, t + T);
    }
    elif (c == 1) {
      if (A.sum(x, x + 1, y, y + 1)) A.add(x, y, -1);
    }
    elif (c == 2) {
      LL(x2, y2);
      print(A.sum(x, x2, y, y2), B.sum(x, x2, y, y2));
    }
  }
}

signed main() {
  solve();
  return 0;
}
