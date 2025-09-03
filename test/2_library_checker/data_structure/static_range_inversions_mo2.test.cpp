#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree.hpp"
#include "ds/offline_query/rollback_mo.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  vi key = A;
  UNIQUE(key);

  for (auto&& x: A) x = LB(key, x);
  ll K = len(key);
  FenwickTree<Monoid_Add<int>> bit(K);

  Rollback_Mo mo;
  vi ANS(Q);
  FOR(Q) {
    LL(L, R);
    mo.add(L, R);
  }

  ll inv = 0;
  ll tinv = 0;
  ll t = 0;
  vc<int> history;
  auto add_l = [&](int i) -> void {
    int x = A[i];
    inv += bit.sum(x);
    bit.add(x, +1);
    history.eb(x);
  };
  auto add_r = [&](int i) -> void {
    int x = A[i];
    inv += bit.sum_all() - bit.sum(x + 1);
    bit.add(x, +1);
    history.eb(x);
  };
  auto rb = [&](int t) -> void {
    while (len(history) > t) { bit.add(POP(history), -1); }
  };
  auto reset = [&]() -> void {
    rb(0);
    inv = 0;
  };
  auto save = [&]() -> void {
    t = len(history);
    tinv = inv;
  };
  auto rollback = [&]() -> void {
    rb(t);
    inv = tinv;
  };
  auto calc = [&](int i) -> void { ANS[i] = inv; };
  mo.calc(add_l, add_r, reset, save, rollback, calc);
  for (auto&& x: ANS) print(x);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}