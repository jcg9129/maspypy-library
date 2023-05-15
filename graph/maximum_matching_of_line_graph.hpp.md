---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/matching_line_graph.test.cpp
    title: test/mytest/matching_line_graph.test.cpp
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
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  // G \u306B\u304A\u3051\u308B\
    \u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\
    \u306A\u308B\u3088\u3046\u306B\u3059\u308B\n  Graph<T, directed> rearrange(vc<int>\
    \ V) {\n    int n = len(V);\n    map<int, int> MP;\n    FOR(i, n) MP[V[i]] = i;\n\
    \    Graph<T, directed> G(n);\n    for (auto&& e: edges) {\n      if (MP.count(e.frm)\
    \ && MP.count(e.to)) {\n        G.add(MP[e.frm], MP[e.to], e.cost);\n      }\n\
    \    }\n    G.build();\n    return G;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"graph/maximum_matching_of_line_graph.hpp\"\
    \n\n// \u540C\u3058\u9802\u70B9\u306B\u63A5\u7D9A\u3059\u308B 2 \u8FBA\u3092\u30DE\
    \u30C3\u30C1\u3067\u304D\u308B\ntemplate <typename GT>\nvc<pair<int, int>> maximum_matching_of_line_graph(GT&\
    \ G) {\n  assert(!G.is_directed());\n  assert(G.is_prepared());\n  const int N\
    \ = G.N, M = G.M;\n  vc<pair<int, int>> ANS;\n  vc<int> V;\n  vc<int> par(N, -1);\
    \ // eid\n  {\n    vc<int> done(N);\n    FOR(v, N) {\n      if (done[v]) continue;\n\
    \      int cnt = 0;\n      auto dfs = [&](auto& dfs, int v, int p) -> void {\n\
    \        V.eb(v);\n        par[v] = p;\n        done[v] = 1;\n        for (auto&&\
    \ e: G[v]) {\n          ++cnt;\n          if (done[e.to]) continue;\n        \
    \  dfs(dfs, e.to, v);\n        }\n      };\n      dfs(dfs, v, -1);\n    }\n  }\n\
    \  vc<int> ord(N);\n  FOR(i, N) ord[V[i]] = i;\n  vc<int> done(M);\n  FOR_R(i,\
    \ N) {\n    int v = V[i];\n    vc<int> down;\n    int up = -1;\n    for (auto&&\
    \ e: G[v]) {\n      if (done[e.id]) continue;\n      if (up == -1 && e.to == par[v])\
    \ up = e.id;\n      if (ord[e.to] > ord[v]) down.eb(e.id);\n    }\n    while (len(down)\
    \ >= 2) {\n      auto i = POP(down);\n      auto j = POP(down);\n      ANS.eb(i,\
    \ j);\n      done[i] = done[j] = 1;\n    }\n    if (len(down) == 0) continue;\n\
    \    if (up != -1) {\n      int x = up;\n      int y = down[0];\n      done[x]\
    \ = done[y] = 1;\n      ANS.eb(x, y);\n    }\n  }\n  return ANS;\n}\n"
  code: "#include \"graph/base.hpp\"\n\n// \u540C\u3058\u9802\u70B9\u306B\u63A5\u7D9A\
    \u3059\u308B 2 \u8FBA\u3092\u30DE\u30C3\u30C1\u3067\u304D\u308B\ntemplate <typename\
    \ GT>\nvc<pair<int, int>> maximum_matching_of_line_graph(GT& G) {\n  assert(!G.is_directed());\n\
    \  assert(G.is_prepared());\n  const int N = G.N, M = G.M;\n  vc<pair<int, int>>\
    \ ANS;\n  vc<int> V;\n  vc<int> par(N, -1); // eid\n  {\n    vc<int> done(N);\n\
    \    FOR(v, N) {\n      if (done[v]) continue;\n      int cnt = 0;\n      auto\
    \ dfs = [&](auto& dfs, int v, int p) -> void {\n        V.eb(v);\n        par[v]\
    \ = p;\n        done[v] = 1;\n        for (auto&& e: G[v]) {\n          ++cnt;\n\
    \          if (done[e.to]) continue;\n          dfs(dfs, e.to, v);\n        }\n\
    \      };\n      dfs(dfs, v, -1);\n    }\n  }\n  vc<int> ord(N);\n  FOR(i, N)\
    \ ord[V[i]] = i;\n  vc<int> done(M);\n  FOR_R(i, N) {\n    int v = V[i];\n   \
    \ vc<int> down;\n    int up = -1;\n    for (auto&& e: G[v]) {\n      if (done[e.id])\
    \ continue;\n      if (up == -1 && e.to == par[v]) up = e.id;\n      if (ord[e.to]\
    \ > ord[v]) down.eb(e.id);\n    }\n    while (len(down) >= 2) {\n      auto i\
    \ = POP(down);\n      auto j = POP(down);\n      ANS.eb(i, j);\n      done[i]\
    \ = done[j] = 1;\n    }\n    if (len(down) == 0) continue;\n    if (up != -1)\
    \ {\n      int x = up;\n      int y = down[0];\n      done[x] = done[y] = 1;\n\
    \      ANS.eb(x, y);\n    }\n  }\n  return ANS;\n}\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/maximum_matching_of_line_graph.hpp
  requiredBy: []
  timestamp: '2023-05-16 02:08:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/matching_line_graph.test.cpp
documentation_of: graph/maximum_matching_of_line_graph.hpp
layout: document
redirect_from:
- /library/graph/maximum_matching_of_line_graph.hpp
- /library/graph/maximum_matching_of_line_graph.hpp.html
title: graph/maximum_matching_of_line_graph.hpp
---
