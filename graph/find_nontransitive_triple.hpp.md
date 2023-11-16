---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/967/problem/F
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
    #line 3 \"graph/find_nontransitive_triple.hpp\"\n\r\n// ab, bc \u8FBA\u306F\u3042\
    \u308B\u304C ac \u8FBA\u306F\u306A\u3044\u3088\u3046\u306A 3 \u3064\u7D44 (a,b,c)\
    \ \u3092\u63A2\u3059\u3002\r\n// \u306A\u3051\u308C\u3070 {-1,-1,-1}\r\n// \u4E0D\
    \u53EF\u80FD\uFF1A\u5B8C\u5168\u30B0\u30E9\u30D5, \u8FBA\u304C\u5168\u90E8\u72EC\
    \u7ACB\r\n// example: https://codeforces.com/contest/967/problem/F\r\ntemplate\
    \ <typename Graph>\r\ntuple<int, int, int> find_nontransitive_triple(Graph& G)\
    \ {\r\n  int N = G.N;\r\n  assert(G.is_prepared());\r\n  assert(!G.is_directed());\r\
    \n  vc<int> done(N);\r\n  vc<int> que;\r\n  FOR(root, N) {\r\n    if (done[root])\
    \ continue;\r\n    que = {root};\r\n    int p = 0;\r\n    while (p < len(que))\
    \ {\r\n      int v = que[p++];\r\n      done[v] = 2;\r\n      ll s = 0;\r\n  \
    \    for (auto&& e: G[v]) {\r\n        int to = e.to;\r\n        if (done[to]\
    \ == 0) {\r\n          done[to] = 1;\r\n          que.eb(to);\r\n        }\r\n\
    \        elif (done[to] == 2) { ++s; }\r\n      }\r\n      if (s == p - 1) continue;\r\
    \n      assert(p >= 3);\r\n      int c = v;\r\n      int a = -1;\r\n      int\
    \ b = -1;\r\n      for (auto&& e: G[v]) done[e.to] = 0;\r\n      FOR(i, p - 1)\
    \ {\r\n        int x = que[i];\r\n        if (done[x] == 2) a = x;\r\n       \
    \ if (done[x] == 0) b = x;\r\n      }\r\n      assert(a != -1);\r\n      assert(b\
    \ != -1);\r\n      return {a, b, c};\r\n    }\r\n  }\r\n  return {-1, -1, -1};\r\
    \n}\r\n"
  code: "#pragma once\r\n#include \"graph/base.hpp\"\r\n\r\n// ab, bc \u8FBA\u306F\
    \u3042\u308B\u304C ac \u8FBA\u306F\u306A\u3044\u3088\u3046\u306A 3 \u3064\u7D44\
    \ (a,b,c) \u3092\u63A2\u3059\u3002\r\n// \u306A\u3051\u308C\u3070 {-1,-1,-1}\r\
    \n// \u4E0D\u53EF\u80FD\uFF1A\u5B8C\u5168\u30B0\u30E9\u30D5, \u8FBA\u304C\u5168\
    \u90E8\u72EC\u7ACB\r\n// example: https://codeforces.com/contest/967/problem/F\r\
    \ntemplate <typename Graph>\r\ntuple<int, int, int> find_nontransitive_triple(Graph&\
    \ G) {\r\n  int N = G.N;\r\n  assert(G.is_prepared());\r\n  assert(!G.is_directed());\r\
    \n  vc<int> done(N);\r\n  vc<int> que;\r\n  FOR(root, N) {\r\n    if (done[root])\
    \ continue;\r\n    que = {root};\r\n    int p = 0;\r\n    while (p < len(que))\
    \ {\r\n      int v = que[p++];\r\n      done[v] = 2;\r\n      ll s = 0;\r\n  \
    \    for (auto&& e: G[v]) {\r\n        int to = e.to;\r\n        if (done[to]\
    \ == 0) {\r\n          done[to] = 1;\r\n          que.eb(to);\r\n        }\r\n\
    \        elif (done[to] == 2) { ++s; }\r\n      }\r\n      if (s == p - 1) continue;\r\
    \n      assert(p >= 3);\r\n      int c = v;\r\n      int a = -1;\r\n      int\
    \ b = -1;\r\n      for (auto&& e: G[v]) done[e.to] = 0;\r\n      FOR(i, p - 1)\
    \ {\r\n        int x = que[i];\r\n        if (done[x] == 2) a = x;\r\n       \
    \ if (done[x] == 0) b = x;\r\n      }\r\n      assert(a != -1);\r\n      assert(b\
    \ != -1);\r\n      return {a, b, c};\r\n    }\r\n  }\r\n  return {-1, -1, -1};\r\
    \n}\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/find_nontransitive_triple.hpp
  requiredBy: []
  timestamp: '2023-11-07 22:29:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/find_nontransitive_triple.hpp
layout: document
redirect_from:
- /library/graph/find_nontransitive_triple.hpp
- /library/graph/find_nontransitive_triple.hpp.html
title: graph/find_nontransitive_triple.hpp
---