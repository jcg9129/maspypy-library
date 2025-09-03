#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "my_template.hpp"

#include "other/io.hpp"

#include "ds/unionfind/dynamic_unionfind.hpp"

void solve() {
  LL(N, Q);

  Dynamic_UnionFind<true> uf(Q);
  using np = typename decltype(uf)::np;
  vc<np> roots;

  roots.eb(uf.new_root());

  FOR(Q) {
    LL(t, k, u, v);
    ++k;
    auto root = roots[k];
    if (t == 0) {
      root = uf.merge(root, u, v).fi;
    } else {
      bool ok = uf.root(root, u) == uf.root(root, v);
      print(ok ? 1 : 0);
    }
    roots.eb(root);
  }
}

signed main() {
  solve();

  return 0;
}