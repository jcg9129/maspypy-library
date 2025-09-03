#define PROBLEM "https://yukicoder.me/problems/no/1141"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/cumsum_2d.hpp"

using mint = modint107;

struct Group {
  using X = pair<mint, int>;
  using value_type = X;
  static const X op(const X &x, const X &y) noexcept {
    return {x.fi * y.fi, x.se + y.se};
  }
  static const X inverse(const X &x) noexcept {
    return {(x.fi).inverse(), -x.se};
  }
  // static constexpr X power(const X &x, ll n) noexcept { return n * x; }
  static constexpr X unit() { return {mint(1), 0}; }
  static constexpr bool commute = true;
};

void solve() {
  LL(H, W);
  vv(Group::X, A, H, W);
  Cumsum_2D<Group> CS(H, W, [&](int x, int y) -> pair<mint, int> {
    INT(a);
    if (a == 0) return {mint(1), 1};
    return {mint(a), 0};
  });
  LL(Q);
  FOR(Q) {
    LL(a, b);
    --a, --b;
    auto x = Group::unit();
    x = Group::op(x, CS.sum(0, a, 0, b));
    x = Group::op(x, CS.sum(a + 1, H, 0, b));
    x = Group::op(x, CS.sum(0, a, b + 1, W));
    x = Group::op(x, CS.sum(a + 1, H, b + 1, W));
    print(x.se ? mint(0) : x.fi);
  }
}

signed main() {
  solve();
  return 0;
}
