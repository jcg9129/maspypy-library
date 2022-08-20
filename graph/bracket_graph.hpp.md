---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1778_bracket_graph.test.cpp
    title: test/yukicoder/1778_bracket_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 2 \"graph/bracket_graph.hpp\"\n\r\n// \u30AB\u30C3\u30B3\
    \u5217\u3092\u30B0\u30E9\u30D5\u306B\u3059\u308B\u3002\u5404\u9802\u70B9\u306E\
    \u7BC4\u56F2\u3092\u8868\u3059\u914D\u5217 LR \u3082\u4F5C\u308B\u3002\r\n// \u5168\
    \u4F53\u3092\u8868\u3059\u6839\u30CE\u30FC\u30C9\u3082\u4F5C\u3063\u3066\u3001\
    N+1\u9802\u70B9\u3002\r\n// ()() \u2192 [0,4), [0,2), [2,4)\r\npair<Graph<int,\
    \ 0>, vc<pair<int, int>>> bracket_graph(string& S) {\r\n  int N = len(S) / 2;\r\
    \n  Graph<int, 0> G(N + 1);\r\n  vc<pair<int, int>> LR(N + 1);\r\n  int now =\
    \ 0;\r\n  int nxt = 1;\r\n  LR[0] = {0, len(S)};\r\n  vc<int> par(N + 1, -1);\r\
    \n  FOR(i, len(S)) {\r\n    assert(S[i] == '(' || S[i] == ')');\r\n    if (S[i]\
    \ == '(') {\r\n      G.add(now, nxt);\r\n      par[nxt] = now;\r\n      LR[nxt].fi\
    \ = i;\r\n      now = nxt;\r\n      nxt++;\r\n    }\r\n    if (S[i] == ')') {\r\
    \n      LR[now].se = i + 1;\r\n      now = par[now];\r\n    }\r\n  }\r\n  assert(now\
    \ == 0);\r\n  G.build();\r\n  return {G, LR};\r\n}\n"
  code: "#include \"graph/base.hpp\"\r\n\r\n// \u30AB\u30C3\u30B3\u5217\u3092\u30B0\
    \u30E9\u30D5\u306B\u3059\u308B\u3002\u5404\u9802\u70B9\u306E\u7BC4\u56F2\u3092\
    \u8868\u3059\u914D\u5217 LR \u3082\u4F5C\u308B\u3002\r\n// \u5168\u4F53\u3092\u8868\
    \u3059\u6839\u30CE\u30FC\u30C9\u3082\u4F5C\u3063\u3066\u3001N+1\u9802\u70B9\u3002\
    \r\n// ()() \u2192 [0,4), [0,2), [2,4)\r\npair<Graph<int, 0>, vc<pair<int, int>>>\
    \ bracket_graph(string& S) {\r\n  int N = len(S) / 2;\r\n  Graph<int, 0> G(N +\
    \ 1);\r\n  vc<pair<int, int>> LR(N + 1);\r\n  int now = 0;\r\n  int nxt = 1;\r\
    \n  LR[0] = {0, len(S)};\r\n  vc<int> par(N + 1, -1);\r\n  FOR(i, len(S)) {\r\n\
    \    assert(S[i] == '(' || S[i] == ')');\r\n    if (S[i] == '(') {\r\n      G.add(now,\
    \ nxt);\r\n      par[nxt] = now;\r\n      LR[nxt].fi = i;\r\n      now = nxt;\r\
    \n      nxt++;\r\n    }\r\n    if (S[i] == ')') {\r\n      LR[now].se = i + 1;\r\
    \n      now = par[now];\r\n    }\r\n  }\r\n  assert(now == 0);\r\n  G.build();\r\
    \n  return {G, LR};\r\n}"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/bracket_graph.hpp
  requiredBy: []
  timestamp: '2022-08-18 17:59:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1778_bracket_graph.test.cpp
documentation_of: graph/bracket_graph.hpp
layout: document
redirect_from:
- /library/graph/bracket_graph.hpp
- /library/graph/bracket_graph.hpp.html
title: graph/bracket_graph.hpp
---
