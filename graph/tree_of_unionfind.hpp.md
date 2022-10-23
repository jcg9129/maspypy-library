---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind.hpp
    title: ds/unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1451.test.cpp
    title: test/yukicoder/1451.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void resize(int n) { N = n; }\n\n  void add(int frm, int to, T cost\
    \ = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to &&\
    \ to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n\
    \    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n\n  void read_parent(int off = 1) {\n    for (int v\
    \ = 1; v < N; ++v) {\n      INT(p);\n      p -= off;\n      add(p, v);\n    }\n\
    \    build();\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared =\
    \ true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0;\
    \ v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto counter = indptr;\n  \
    \  csr_edges.resize(indptr.back() + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++]\
    \ = e;\n      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to,\
    \ e.frm, e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const\
    \ {\n    assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\
    \n  vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\nprivate:\n  void calc_deg()\
    \ {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"ds/unionfind.hpp\"\
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
    \ 1);\n    std::iota(par.begin(), par.end(), 0);\n  }\n};\n#line 3 \"graph/tree_of_unionfind.hpp\"\
    \n\r\n/*\r\n\u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u6728\u3092\u69CB\
    \u7BC9\u3059\u308B\r\nq \u56DE\u76EE\u306B\u30DE\u30FC\u30B8\u3057\u3066\u3067\
    \u304D\u308B\u6210\u5206\uFF1AN+q\r\nadd_root = true \u306E\u5834\u5408\uFF1A\u6700\
    \u5F8C\u306B\u5168\u90E8\u3092\u30DE\u30FC\u30B8\u3057\u3066\u3001\u6839 N+Q \u3092\
    \u8FFD\u52A0\u3059\u308B\r\n*/\r\nGraph<int> tree_of_unionfind(int N, vc<pair<int,\
    \ int>> query, bool add_root) {\r\n  UnionFind uf(N + len(query));\r\n  vc<int>\
    \ root(N);\r\n  iota(all(root), 0);\r\n  int Q = len(query);\r\n  Graph<int> G(N\
    \ + Q + add_root);\r\n  FOR(q, Q) {\r\n    int v = N + q;\r\n    auto [a, b] =\
    \ query[q];\r\n    a = uf[a], b = uf[b];\r\n    G.add(v, root[a]);\r\n    if (b\
    \ != a) G.add(v, root[b]);\r\n    uf.merge(a, b);\r\n    uf.merge(b, v);\r\n \
    \   root[uf[v]] = v;\r\n  }\r\n  if (add_root) {\r\n    int r = N + Q;\r\n   \
    \ FOR(v, N) if (uf[v] == v) G.add(r, root[v]);\r\n  }\r\n  G.build();\r\n  return\
    \ G;\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n#include \"ds/unionfind.hpp\"\r\n\r\n/*\r\n\
    \u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u6728\u3092\u69CB\u7BC9\u3059\
    \u308B\r\nq \u56DE\u76EE\u306B\u30DE\u30FC\u30B8\u3057\u3066\u3067\u304D\u308B\
    \u6210\u5206\uFF1AN+q\r\nadd_root = true \u306E\u5834\u5408\uFF1A\u6700\u5F8C\u306B\
    \u5168\u90E8\u3092\u30DE\u30FC\u30B8\u3057\u3066\u3001\u6839 N+Q \u3092\u8FFD\u52A0\
    \u3059\u308B\r\n*/\r\nGraph<int> tree_of_unionfind(int N, vc<pair<int, int>> query,\
    \ bool add_root) {\r\n  UnionFind uf(N + len(query));\r\n  vc<int> root(N);\r\n\
    \  iota(all(root), 0);\r\n  int Q = len(query);\r\n  Graph<int> G(N + Q + add_root);\r\
    \n  FOR(q, Q) {\r\n    int v = N + q;\r\n    auto [a, b] = query[q];\r\n    a\
    \ = uf[a], b = uf[b];\r\n    G.add(v, root[a]);\r\n    if (b != a) G.add(v, root[b]);\r\
    \n    uf.merge(a, b);\r\n    uf.merge(b, v);\r\n    root[uf[v]] = v;\r\n  }\r\n\
    \  if (add_root) {\r\n    int r = N + Q;\r\n    FOR(v, N) if (uf[v] == v) G.add(r,\
    \ root[v]);\r\n  }\r\n  G.build();\r\n  return G;\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  - ds/unionfind.hpp
  isVerificationFile: false
  path: graph/tree_of_unionfind.hpp
  requiredBy: []
  timestamp: '2022-09-16 10:29:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1451.test.cpp
documentation_of: graph/tree_of_unionfind.hpp
layout: document
redirect_from:
- /library/graph/tree_of_unionfind.hpp
- /library/graph/tree_of_unionfind.hpp.html
title: graph/tree_of_unionfind.hpp
---
