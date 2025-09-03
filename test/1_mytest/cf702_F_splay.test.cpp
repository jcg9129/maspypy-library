#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "alg/monoid/add_pair.hpp"
#include "ds/splaytree/splaytree_acted_set.hpp"

// (所持金, 操作回数, query index)
struct AS {
  using Monoid_A = Monoid_Add_Pair<int>;
  using A = Monoid_A::value_type;
  using S = tuple<int, int, int>;
  static S act(const S& s, const A& x) {
    auto [a, b, c] = s;
    return {a + x.fi, b + x.se, c};
  }
};

vc<int> solve_cf702F(vc<pair<int, int>> CQ, vc<int> query) {
  const int Q = len(query);
  sort(all(CQ), [&](auto& a, auto& b) -> bool {
    if (a.se != b.se) return a.se > b.se;
    return a.fi < b.fi;
  });
  using T = tuple<int, int, int>;
  vc<T> dat(Q);
  FOR(q, Q) {
    int x = query[q];
    dat[q] = {x, 0, q};
  }
  sort(all(dat));

  const int MAX = 500'000;

  SplayTree_ActedSet<AS> X(MAX);
  using np = decltype(X)::np;
  using S = typename AS::S;
  np root = X.new_node(dat);

  FOR(i, len(CQ)) {
    ll c = CQ[i].fi;
    np nm, nr;
    tie(root, nr) = X.split_max_right(root, [&](S& s) { return get<0>(s) < c; });
    X.apply(nr, {-c, 1});
    tie(nm, nr) = X.split_max_right(nr, [&](S& s) { return get<0>(s) < c; });
    for (auto&& [aa, bb, cc]: X.get_all(nm)) assert(aa < c);
    for (auto&& [aa, bb, cc]: X.get_all(nr)) assert(aa >= c);
    for (auto [val, cnt, idx]: X.get_all(nm)) {
      ll t = val;
      auto [l_root, r_root] = X.split_max_right(root, [&](S& s) { return get<0>(s) < t; });
      root = X.merge(l_root, X.new_node({val, cnt, idx}));
      root = X.merge(root, r_root);
    }
    root = X.merge(root, nr);
  }
  vc<int> ANS(Q);
  for (auto [val, cnt, idx]: X.get_all(root)) { ANS[idx] = cnt; }
  return ANS;
}

void test_1() {
  vc<pair<int, int>> CQ;
  CQ.eb(7, 5);
  CQ.eb(3, 5);
  CQ.eb(4, 3);
  vc<int> query = {13, 14};
  vc<int> ANS = solve_cf702F(CQ, query);
  assert(ANS == vc<int>({2, 3}));
}

void test_2() {
  vc<pair<int, int>> CQ;
  CQ.eb(100, 500);
  CQ.eb(50, 499);
  vc<int> query = {50, 200, 150, 100};
  vc<int> ANS = solve_cf702F(CQ, query);
  assert(ANS == vc<int>({1, 2, 2, 1}));
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test_1();
  test_2();
  solve();

  return 0;
}
