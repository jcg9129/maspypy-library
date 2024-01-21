#define PROBLEM "https://judge.yosupo.jp/problem/count_points_in_triangle"

#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/eulerwalk.hpp"

void solve() {
  LL(N, M);
  Graph<int, 1> G(N);
  G.read_graph(M, 0, 0);
  auto [vs, es] = euler_walk(G);
  if (vs.empty()) return No();
  Yes();
  print(vs);
  print(es);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}