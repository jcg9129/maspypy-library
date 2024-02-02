---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/centroid_decomposition_old.hpp
    title: graph/centroid_decomposition_old.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1769.test.cpp
    title: test/yukicoder/1769.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1796.test.cpp
    title: test/yukicoder/1796.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n#endif\n\n  void build() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges)\
    \ {\n      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n  \
    \  }\n    for (int v = 0; v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n\
    \      print(\"frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to,\
    \ e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n      print(\"\
    frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to,\
    \ e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\
    \n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n\
    \    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) != M)\
    \ used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] = i;\n\
    \    Graph<T, directed> G(n);\n    vc<int> history;\n    FOR(i, n) {\n      for\
    \ (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          history.eb(e.id);\n          used_e[e.id] = 1;\n          int eid =\
    \ (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost, eid);\n\
    \        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for (auto&&\
    \ eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\nprivate:\n\
    \  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n   \
    \ for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 2 \"graph/find_centroid.hpp\"\n\r\n// (v,w) or (v,-1)\r\ntemplate <typename\
    \ GT>\r\npair<int, int> find_centroids(GT& G) {\r\n  int N = G.N;\r\n  vc<int>\
    \ par(N, -1);\r\n  vc<int> V(N);\r\n  vc<int> sz(N);\r\n  int l = 0, r = 0;\r\n\
    \  V[r++] = 0;\r\n  while (l < r) {\r\n    int v = V[l++];\r\n    for (auto&&\
    \ e: G[v])\r\n      if (e.to != par[v]) {\r\n        par[e.to] = v;\r\n      \
    \  V[r++] = e.to;\r\n      }\r\n  }\r\n  FOR_R(i, N) {\r\n    int v = V[i];\r\n\
    \    sz[v] += 1;\r\n    int p = par[v];\r\n    if (p != -1) sz[p] += sz[v];\r\n\
    \  }\r\n\r\n  int M = N / 2;\r\n  auto check = [&](int v) -> bool {\r\n    if\
    \ (N - sz[v] > M) return false;\r\n    for (auto&& e: G[v]) {\r\n      if (e.to\
    \ != par[v] && sz[e.to] > M) return false;\r\n    }\r\n    return true;\r\n  };\r\
    \n  pair<int, int> ANS = {-1, -1};\r\n  FOR(v, N) if (check(v)) {\r\n    if (ANS.fi\
    \ != -1) {\r\n      ANS.se = v;\r\n    } else {\r\n      ANS.fi = v;\r\n    }\r\
    \n  }\r\n  return ANS;\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\n// (v,w) or (v,-1)\r\ntemplate <typename\
    \ GT>\r\npair<int, int> find_centroids(GT& G) {\r\n  int N = G.N;\r\n  vc<int>\
    \ par(N, -1);\r\n  vc<int> V(N);\r\n  vc<int> sz(N);\r\n  int l = 0, r = 0;\r\n\
    \  V[r++] = 0;\r\n  while (l < r) {\r\n    int v = V[l++];\r\n    for (auto&&\
    \ e: G[v])\r\n      if (e.to != par[v]) {\r\n        par[e.to] = v;\r\n      \
    \  V[r++] = e.to;\r\n      }\r\n  }\r\n  FOR_R(i, N) {\r\n    int v = V[i];\r\n\
    \    sz[v] += 1;\r\n    int p = par[v];\r\n    if (p != -1) sz[p] += sz[v];\r\n\
    \  }\r\n\r\n  int M = N / 2;\r\n  auto check = [&](int v) -> bool {\r\n    if\
    \ (N - sz[v] > M) return false;\r\n    for (auto&& e: G[v]) {\r\n      if (e.to\
    \ != par[v] && sz[e.to] > M) return false;\r\n    }\r\n    return true;\r\n  };\r\
    \n  pair<int, int> ANS = {-1, -1};\r\n  FOR(v, N) if (check(v)) {\r\n    if (ANS.fi\
    \ != -1) {\r\n      ANS.se = v;\r\n    } else {\r\n      ANS.fi = v;\r\n    }\r\
    \n  }\r\n  return ANS;\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/find_centroid.hpp
  requiredBy:
  - graph/centroid_decomposition_old.hpp
  timestamp: '2023-11-07 22:29:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1796.test.cpp
  - test/yukicoder/1769.test.cpp
documentation_of: graph/find_centroid.hpp
layout: document
redirect_from:
- /library/graph/find_centroid.hpp
- /library/graph/find_centroid.hpp.html
title: graph/find_centroid.hpp
---