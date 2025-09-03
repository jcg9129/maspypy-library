#define PROBLEM "https://yukicoder.me/problems/no/1269"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/trie.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  LL(N, L, R);
  vi F = {1, 2};
  while (F.back() <= R) F.eb(F[len(F) - 2] + F[len(F) - 1]);
  {
    vi tmp;
    for (auto&& x: F)
      if (L <= x && x <= R) tmp.eb(x);
    F = tmp;
  }
  Trie<10> X;
  for (auto&& f: F) {
    string s = to_string(f);
    X.add(s, '0');
  }
  X.calc_suffix_link();

  ll n = X.n_node;
  vc<bool> ng(n);
  for (auto&& v: X.words) ng[v] = 1;
  for (auto&& v: X.BFS)
    if (v) {
      int p = X.nodes[v].suffix_link;
      if (ng[p]) ng[v] = 1;
    }

  vc<mint> dp(n);
  dp[0] = 1;
  FOR(N) {
    vc<mint> newdp(n);
    FOR(v, n) {
      FOR(d, 10) {
        int to = X.nodes[v].nxt[d];
        if (ng[to]) continue;
        assert(0 <= to && to < n);
        newdp[to] += dp[v];
      }
    }
    swap(dp, newdp);
  }
  print(SUM<mint>(dp) - mint(1));
}

signed main() {
  solve();
  return 0;
}
