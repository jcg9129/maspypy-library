---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind.hpp
    title: ds/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/manhattan_mst.test.cpp
    title: test/library_checker/graph/manhattan_mst.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n  \
    \  int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm, int to, T\
    \ cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <=\
    \ to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost,\
    \ i});\n    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool\
    \ wt = false, int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int\
    \ M, bool wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n    \
    \  INT(a, b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n\
    \      } else {\n        T c;\n        read(c);\n        add(a, b, c);\n     \
    \ }\n    }\n    build();\n  }\n\n  void read_parent(int off = 1) {\n    for (int\
    \ v = 1; v < N; ++v) {\n      INT(p);\n      p -= off;\n      add(p, v);\n   \
    \ }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared\
    \ = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0;\
    \ v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto counter = indptr;\n  \
    \  csr_edges.resize(indptr.back() + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++]\
    \ = e;\n      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to,\
    \ e.frm, e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const\
    \ {\n    assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\
    \n  vc<int> deg_array() {\n    static vc<int> deg;\n    if (deg.empty()) {\n \
    \     deg.resize(N);\n      for (auto&& e: edges) deg[e.frm]++, deg[e.to]++;\n\
    \    }\n    return deg;\n  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n\
    \    static vector<int> indeg, outdeg;\n    if (indeg.empty()) {\n      indeg.resize(N);\n\
    \      outdeg.resize(N);\n      for (auto&& e: edges) { indeg[e.to]++, outdeg[e.frm]++;\
    \ }\n    }\n    return {indeg, outdeg};\n  }\n\n  int deg(int v) {\n    static\
    \ vc<int> deg;\n    if (deg.empty()) deg = deg_array();\n    return deg[v];\n\
    \  }\n\n  pair<int, int> deg_inout(int v) {\n    static vc<int> indeg, outdeg;\n\
    \    if (indeg.empty()) tie(indeg, outdeg) = deg_array_inout();\n    return {indeg[v],\
    \ outdeg[v]};\n  }\n\n  int in_deg(int v) { return deg_inout(v).fi; }\n  int out_deg(int\
    \ v) { return deg_inout(v).se; }\n\n  void debug() {\n    print(\"Graph\");\n\
    \    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e:\
    \ edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n};\n#line 2 \"ds/unionfind.hpp\"\
    \n\nstruct UnionFind {\n  int n;\n  int n_comp;\n  std::vector<int> size, par;\n\
    \  UnionFind(int n) : n(n), n_comp(n), size(n, 1), par(n) {\n    std::iota(par.begin(),\
    \ par.end(), 0);\n  }\n  int find(int x) {\n    assert(0 <= x && x < n);\n   \
    \ while (par[x] != x) {\n      par[x] = par[par[x]];\n      x = par[x];\n    }\n\
    \    return x;\n  }\n\n  int operator[](int x) { return find(x); }\n\n  bool merge(int\
    \ x, int y) {\n    x = find(x);\n    y = find(y);\n    if (x == y) { return false;\
    \ }\n    n_comp--;\n    if (size[x] < size[y]) std::swap(x, y);\n    size[x] +=\
    \ size[y];\n    size[y] = 0;\n    par[y] = x;\n    return true;\n  }\n\n  std::vector<int>\
    \ find_all() {\n    std::vector<int> A(n);\n    for (int i = 0; i < n; ++i) A[i]\
    \ = find(i);\n    return A;\n  }\n\n  void reset() {\n    n_comp = n;\n    size.assign(n,\
    \ 1);\n    std::iota(par.begin(), par.end(), 0);\n  }\n};\n#line 3 \"geo/manhattan_mst.hpp\"\
    \n\ntemplate <typename T>\nGraph<T, 0> Manhattan_MST(vc<pair<T, T>>& XY) {\n \
    \ int N = XY.size();\n  vc<tuple<T, int, int>> dat;\n  dat.reserve(4 * N);\n \
    \ vc<int> idx(N);\n  iota(all(idx), 0);\n\n  FOR(a, 2) {\n    for (auto&& [x,\
    \ y]: XY) x = -x;\n    FOR(b, 2) {\n      for (auto&& [x, y]: XY) swap(x, y);\n\
    \      sort(all(idx), [&](const int& i, const int& j) -> bool {\n        return\
    \ XY[i].fi + XY[i].se < XY[j].fi + XY[j].se;\n      });\n\n      map<T, int> MP;\n\
    \      for (const int i: idx) {\n        auto& [x, y] = XY[i];\n        for (auto\
    \ it = MP.lower_bound(-y); it != MP.end(); it = MP.erase(it)) {\n          const\
    \ int j = it->se;\n          auto& [xj, yj] = XY[j];\n          const int dx =\
    \ x - xj;\n          const int dy = y - yj;\n          if (dy > dx) break;\n \
    \         dat.eb(dx + dy, i, j);\n        }\n        MP[-y] = i;\n      }\n  \
    \  }\n  }\n\n  sort(all(dat));\n  Graph<T, 0> G(N);\n  UnionFind uf(N);\n  for\
    \ (auto&& [cost, i, j]: dat) {\n    if (uf.merge(i, j)) G.add(i, j, cost);\n \
    \ }\n  G.build();\n  return G;\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"ds/unionfind.hpp\"\n\ntemplate <typename\
    \ T>\nGraph<T, 0> Manhattan_MST(vc<pair<T, T>>& XY) {\n  int N = XY.size();\n\
    \  vc<tuple<T, int, int>> dat;\n  dat.reserve(4 * N);\n  vc<int> idx(N);\n  iota(all(idx),\
    \ 0);\n\n  FOR(a, 2) {\n    for (auto&& [x, y]: XY) x = -x;\n    FOR(b, 2) {\n\
    \      for (auto&& [x, y]: XY) swap(x, y);\n      sort(all(idx), [&](const int&\
    \ i, const int& j) -> bool {\n        return XY[i].fi + XY[i].se < XY[j].fi +\
    \ XY[j].se;\n      });\n\n      map<T, int> MP;\n      for (const int i: idx)\
    \ {\n        auto& [x, y] = XY[i];\n        for (auto it = MP.lower_bound(-y);\
    \ it != MP.end(); it = MP.erase(it)) {\n          const int j = it->se;\n    \
    \      auto& [xj, yj] = XY[j];\n          const int dx = x - xj;\n          const\
    \ int dy = y - yj;\n          if (dy > dx) break;\n          dat.eb(dx + dy, i,\
    \ j);\n        }\n        MP[-y] = i;\n      }\n    }\n  }\n\n  sort(all(dat));\n\
    \  Graph<T, 0> G(N);\n  UnionFind uf(N);\n  for (auto&& [cost, i, j]: dat) {\n\
    \    if (uf.merge(i, j)) G.add(i, j, cost);\n  }\n  G.build();\n  return G;\n\
    }\n"
  dependsOn:
  - graph/base.hpp
  - ds/unionfind.hpp
  isVerificationFile: false
  path: geo/manhattan_mst.hpp
  requiredBy: []
  timestamp: '2022-08-29 20:13:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/manhattan_mst.test.cpp
documentation_of: geo/manhattan_mst.hpp
layout: document
redirect_from:
- /library/geo/manhattan_mst.hpp
- /library/geo/manhattan_mst.hpp.html
title: geo/manhattan_mst.hpp
---
