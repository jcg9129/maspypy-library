---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/bfs01.hpp
    title: graph/bfs01.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/string/number_of_substrings2.test.cpp
    title: test/library_checker/string/number_of_substrings2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/bfs01.hpp\"\
    \n\ntemplate <typename Graph>\npair<vc<ll>, vc<int>> bfs01(Graph& G, ll v) {\n\
    \  assert(G.is_prepared());\n  int N = G.N;\n  vc<ll> dist(N, -1);\n  vc<int>\
    \ par(N, -1);\n  deque<int> que;\n\n  dist[v] = 0;\n  que.push_front(v);\n  while\
    \ (!que.empty()) {\n    auto v = que.front();\n    que.pop_front();\n    for (auto&&\
    \ e: G[v]) {\n      if (dist[e.to] == -1 || dist[e.to] > dist[e.frm] + e.cost)\
    \ {\n        dist[e.to] = dist[e.frm] + e.cost;\n        par[e.to] = e.frm;\n\
    \        if (e.cost == 0)\n          que.push_front(e.to);\n        else\n   \
    \       que.push_back(e.to);\n      }\n    }\n  }\n  return {dist, par};\n}\n\n\
    // \u591A\u70B9\u30B9\u30BF\u30FC\u30C8\u3002[dist, par, root]\ntemplate <typename\
    \ Graph>\ntuple<vc<ll>, vc<int>, vc<int>> bfs01(Graph& G, vc<int> vs) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  vc<ll> dist(N, -1);\n  vc<int> par(N, -1);\n  vc<int> root(N,\
    \ -1);\n  deque<int> que;\n\n  for (auto&& v: vs) {\n    dist[v] = 0;\n    root[v]\
    \ = v;\n    que.push_front(v);\n  }\n\n  while (!que.empty()) {\n    auto v =\
    \ que.front();\n    que.pop_front();\n    for (auto&& e: G[v]) {\n      if (dist[e.to]\
    \ == -1 || dist[e.to] > dist[e.frm] + e.cost) {\n        dist[e.to] = dist[e.frm]\
    \ + e.cost;\n        root[e.to] = root[e.frm];\n        par[e.to] = e.frm;\n \
    \       if (e.cost == 0)\n          que.push_front(e.to);\n        else\n    \
    \      que.push_back(e.to);\n      }\n    }\n  }\n  return {dist, par, root};\n\
    }\n#line 3 \"string/suffix_automation.hpp\"\n\ntemplate <int sigma = 26>\nstruct\
    \ Suffix_Automation {\n  struct Node {\n    array<int, sigma> next; // automation\
    \ \u306E\u9077\u79FB\u5148\n    int link;               // suffix link\n    int\
    \ size;               // node \u304C\u53D7\u7406\u3059\u308B\u6700\u9577\u6587\
    \u5B57\u5217\u306E\u9577\u3055\n    Node(int link, int size) : link(link), size(size)\
    \ { fill(all(next), -1); }\n  };\n\n  vc<Node> nodes;\n  int last; // \u6587\u5B57\
    \u5217\u5168\u4F53\u3092\u5165\u308C\u305F\u3068\u304D\u306E\u884C\u304D\u5148\
    \n\n  Suffix_Automation() {\n    nodes.eb(Node(-1, 0));\n    last = 0;\n  }\n\n\
    \  void add(char c0, char off) {\n    int c = c0 - 'a';\n    int new_node = len(nodes);\n\
    \    nodes.eb(Node(-1, nodes[last].size + 1));\n    int p = last;\n    while (p\
    \ != -1 && nodes[p].next[c] == -1) {\n      nodes[p].next[c] = new_node;\n   \
    \   p = nodes[p].link;\n    }\n    int q = (p == -1 ? 0 : nodes[p].next[c]);\n\
    \    if (p == -1 || nodes[p].size + 1 == nodes[q].size) {\n      nodes[new_node].link\
    \ = q;\n    } else {\n      int new_q = len(nodes);\n      nodes.eb(Node(nodes[q].link,\
    \ nodes[p].size + 1));\n      nodes.back().next = nodes[q].next;\n      nodes[q].link\
    \ = new_q;\n      nodes[new_node].link = new_q;\n      while (p != -1 && nodes[p].next[c]\
    \ == q) {\n        nodes[p].next[c] = new_q;\n        p = nodes[p].link;\n   \
    \   }\n    }\n    last = new_node;\n  }\n\n  Graph<int, 1> calc_DAG() {\n    int\
    \ n = len(nodes);\n    Graph<int, 1> G(n);\n    FOR(v, n) {\n      for (auto&&\
    \ to: nodes[v].next)\n        if (to != -1) { G.add(v, to); }\n    }\n    G.build();\n\
    \    return G;\n  }\n\n  Graph<int, 1> calc_tree() {\n    int n = len(nodes);\n\
    \    Graph<int, 1> G(n);\n    G.resize(n);\n    FOR(v, 1, n) {\n      int p =\
    \ nodes[v].link;\n      G.add(p, v);\n    }\n    G.build();\n    return G;\n \
    \ }\n\n  ll count_substring() {\n    // \u3042\u308B\u30CE\u30FC\u30C9\u306B\u3064\
    \u3044\u3066\u3001\u6700\u77ED\u30D1\u30B9\u3068\u6700\u9577\u30D1\u30B9\u306E\
    \u9593\u306E\u6587\u5B57\u5217\u9577\u304C\u5BFE\u5FDC\u3059\u308B\u3002\n   \
    \ // \u6700\u9577\u30D1\u30B9\u306F link \u304C\u6301\u3063\u3066\u3044\u308B\u306E\
    \u3067\u3001\u6700\u77ED\u30D1\u30B9\u3092\u6C42\u3081\u308C\u3070\u3088\u3044\
    \u3002\n    auto G = calc_DAG();\n    int n = G.N;\n    auto [dist, par] = bfs01(G,\
    \ 0);\n    ll ANS = 0;\n    FOR(i, 1, n) { ANS += nodes[i].size - dist[i] + 1;\
    \ }\n    return ANS;\n  }\n};\n"
  code: "#include \"graph/base.hpp\"\n#include \"graph/bfs01.hpp\"\n\ntemplate <int\
    \ sigma = 26>\nstruct Suffix_Automation {\n  struct Node {\n    array<int, sigma>\
    \ next; // automation \u306E\u9077\u79FB\u5148\n    int link;               //\
    \ suffix link\n    int size;               // node \u304C\u53D7\u7406\u3059\u308B\
    \u6700\u9577\u6587\u5B57\u5217\u306E\u9577\u3055\n    Node(int link, int size)\
    \ : link(link), size(size) { fill(all(next), -1); }\n  };\n\n  vc<Node> nodes;\n\
    \  int last; // \u6587\u5B57\u5217\u5168\u4F53\u3092\u5165\u308C\u305F\u3068\u304D\
    \u306E\u884C\u304D\u5148\n\n  Suffix_Automation() {\n    nodes.eb(Node(-1, 0));\n\
    \    last = 0;\n  }\n\n  void add(char c0, char off) {\n    int c = c0 - 'a';\n\
    \    int new_node = len(nodes);\n    nodes.eb(Node(-1, nodes[last].size + 1));\n\
    \    int p = last;\n    while (p != -1 && nodes[p].next[c] == -1) {\n      nodes[p].next[c]\
    \ = new_node;\n      p = nodes[p].link;\n    }\n    int q = (p == -1 ? 0 : nodes[p].next[c]);\n\
    \    if (p == -1 || nodes[p].size + 1 == nodes[q].size) {\n      nodes[new_node].link\
    \ = q;\n    } else {\n      int new_q = len(nodes);\n      nodes.eb(Node(nodes[q].link,\
    \ nodes[p].size + 1));\n      nodes.back().next = nodes[q].next;\n      nodes[q].link\
    \ = new_q;\n      nodes[new_node].link = new_q;\n      while (p != -1 && nodes[p].next[c]\
    \ == q) {\n        nodes[p].next[c] = new_q;\n        p = nodes[p].link;\n   \
    \   }\n    }\n    last = new_node;\n  }\n\n  Graph<int, 1> calc_DAG() {\n    int\
    \ n = len(nodes);\n    Graph<int, 1> G(n);\n    FOR(v, n) {\n      for (auto&&\
    \ to: nodes[v].next)\n        if (to != -1) { G.add(v, to); }\n    }\n    G.build();\n\
    \    return G;\n  }\n\n  Graph<int, 1> calc_tree() {\n    int n = len(nodes);\n\
    \    Graph<int, 1> G(n);\n    G.resize(n);\n    FOR(v, 1, n) {\n      int p =\
    \ nodes[v].link;\n      G.add(p, v);\n    }\n    G.build();\n    return G;\n \
    \ }\n\n  ll count_substring() {\n    // \u3042\u308B\u30CE\u30FC\u30C9\u306B\u3064\
    \u3044\u3066\u3001\u6700\u77ED\u30D1\u30B9\u3068\u6700\u9577\u30D1\u30B9\u306E\
    \u9593\u306E\u6587\u5B57\u5217\u9577\u304C\u5BFE\u5FDC\u3059\u308B\u3002\n   \
    \ // \u6700\u9577\u30D1\u30B9\u306F link \u304C\u6301\u3063\u3066\u3044\u308B\u306E\
    \u3067\u3001\u6700\u77ED\u30D1\u30B9\u3092\u6C42\u3081\u308C\u3070\u3088\u3044\
    \u3002\n    auto G = calc_DAG();\n    int n = G.N;\n    auto [dist, par] = bfs01(G,\
    \ 0);\n    ll ANS = 0;\n    FOR(i, 1, n) { ANS += nodes[i].size - dist[i] + 1;\
    \ }\n    return ANS;\n  }\n};\n"
  dependsOn:
  - graph/base.hpp
  - graph/bfs01.hpp
  isVerificationFile: false
  path: string/suffix_automation.hpp
  requiredBy: []
  timestamp: '2022-08-30 23:27:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/string/number_of_substrings2.test.cpp
documentation_of: string/suffix_automation.hpp
layout: document
redirect_from:
- /library/string/suffix_automation.hpp
- /library/string/suffix_automation.hpp.html
title: string/suffix_automation.hpp
---
