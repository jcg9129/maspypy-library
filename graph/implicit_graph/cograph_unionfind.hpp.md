---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':x:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid\
    \ = 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e)\
    \ != M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]]\
    \ = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n    FOR(i, n) {\n\
    \      for (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n\
    \        int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b]\
    \ != -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n       \
    \   int eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b],\
    \ e.cost, eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n\
    \    for (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n\
    \  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int n, n_comp;\n\
    \  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n); }\n\n  void\
    \ build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n  }\n\n  void\
    \ reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x] >= 0)\
    \ {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n     \
    \ x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n    x = (*this)[x];\n\
    \    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n    x = (*this)[x],\
    \ y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x] < -dat[y]) swap(x,\
    \ y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return true;\n  }\n};\n\
    #line 1 \"ds/fastset.hpp\"\n// 64-ary tree\r\n// space: (N/63) * u64\r\nstruct\
    \ FastSet {\r\n  static constexpr u32 B = 64;\r\n  int n, log;\r\n  vvc<u64> seg;\r\
    \n\r\n  FastSet() {}\r\n  FastSet(int n) { build(n); }\r\n\r\n  template <typename\
    \ F>\r\n  FastSet(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\r\n  void build(int\
    \ m) {\r\n    seg.clear();\r\n    n = m;\r\n    do {\r\n      seg.push_back(vc<u64>((m\
    \ + B - 1) / B));\r\n      m = (m + B - 1) / B;\r\n    } while (m > 1);\r\n  \
    \  log = len(seg);\r\n  }\r\n  template <typename F>\r\n  void build(int n, F\
    \ f) {\r\n    build(n);\r\n    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i %\
    \ B); }\r\n    FOR(h, log - 1) {\r\n      FOR(i, len(seg[h])) {\r\n        seg[h\
    \ + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\r\n      }\r\n    }\r\n  }\r\
    \n\r\n  bool operator[](int i) const { return seg[0][i / B] >> (i % B) & 1; }\r\
    \n  void insert(int i) {\r\n    for (int h = 0; h < log; h++) {\r\n      seg[h][i\
    \ / B] |= u64(1) << (i % B), i /= B;\r\n    }\r\n  }\r\n  void add(int i) { insert(i);\
    \ }\r\n  void erase(int i) {\r\n    u64 x = 0;\r\n    for (int h = 0; h < log;\
    \ h++) {\r\n      seg[h][i / B] &= ~(u64(1) << (i % B));\r\n      seg[h][i / B]\
    \ |= x << (i % B);\r\n      x = bool(seg[h][i / B]);\r\n      i /= B;\r\n    }\r\
    \n  }\r\n  void remove(int i) { erase(i); }\r\n\r\n  // min[x,n) or n\r\n  int\
    \ next(int i) {\r\n    assert(i < n);\r\n    chmax(i, 0);\r\n    for (int h =\
    \ 0; h < log; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      u64\
    \ d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\
    \n        continue;\r\n      }\r\n      i += lowbit(d);\r\n      for (int g =\
    \ h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += lowbit(seg[g][i / B]);\r\
    \n      }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n  // max\
    \ [0,x], or -1\r\n  int prev(int i) {\r\n    assert(i >= 0);\r\n    if (i >= n)\
    \ i = n - 1;\r\n    for (int h = 0; h < log; h++) {\r\n      if (i == -1) break;\r\
    \n      u64 d = seg[h][i / B] << (63 - i % B);\r\n      if (!d) {\r\n        i\
    \ = i / B - 1;\r\n        continue;\r\n      }\r\n      i -= __builtin_clzll(d);\r\
    \n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i +=\
    \ topbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return\
    \ -1;\r\n  }\r\n\r\n  // [l, r)\r\n  template <typename F>\r\n  void enumerate(int\
    \ l, int r, F f) {\r\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\r\
    \n  }\r\n\r\n  string to_string() {\r\n    string s(n, '?');\r\n    for (int i\
    \ = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\r\n    return s;\r\n  }\r\n\
    };\n#line 4 \"graph/implicit_graph/cograph_unionfind.hpp\"\n\ntemplate <typename\
    \ GT>\nUnionFind cograph_unionfind(GT& G) {\n  const int N = G.N;\n  UnionFind\
    \ uf(N);\n  FastSet ss(N);\n  FOR(v, N) ss.insert(v);\n\n  vc<int> que;\n  FOR(v,\
    \ N) {\n    if (!ss[v]) continue;\n    que.eb(v);\n    while (len(que)) {\n  \
    \    int a = POP(que);\n      vc<int> tmp;\n      for (auto&& e: G[a]) {\n   \
    \     if (ss[e.to]) tmp.eb(e.to);\n      }\n      for (auto&& x: tmp) ss.erase(x);\n\
    \      ss.enumerate(0, N, [&](int to) -> void {\n        ss.erase(to);\n     \
    \   que.eb(to);\n        uf.merge(a, to);\n      });\n      for (auto&& x: tmp)\
    \ ss.insert(x);\n    }\n  }\n  return uf;\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\n#include\
    \ \"ds/fastset.hpp\"\n\ntemplate <typename GT>\nUnionFind cograph_unionfind(GT&\
    \ G) {\n  const int N = G.N;\n  UnionFind uf(N);\n  FastSet ss(N);\n  FOR(v, N)\
    \ ss.insert(v);\n\n  vc<int> que;\n  FOR(v, N) {\n    if (!ss[v]) continue;\n\
    \    que.eb(v);\n    while (len(que)) {\n      int a = POP(que);\n      vc<int>\
    \ tmp;\n      for (auto&& e: G[a]) {\n        if (ss[e.to]) tmp.eb(e.to);\n  \
    \    }\n      for (auto&& x: tmp) ss.erase(x);\n      ss.enumerate(0, N, [&](int\
    \ to) -> void {\n        ss.erase(to);\n        que.eb(to);\n        uf.merge(a,\
    \ to);\n      });\n      for (auto&& x: tmp) ss.insert(x);\n    }\n  }\n  return\
    \ uf;\n}"
  dependsOn:
  - graph/base.hpp
  - ds/unionfind/unionfind.hpp
  - ds/fastset.hpp
  isVerificationFile: false
  path: graph/implicit_graph/cograph_unionfind.hpp
  requiredBy: []
  timestamp: '2023-11-06 14:40:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/implicit_graph/cograph_unionfind.hpp
layout: document
redirect_from:
- /library/graph/implicit_graph/cograph_unionfind.hpp
- /library/graph/implicit_graph/cograph_unionfind.hpp.html
title: graph/implicit_graph/cograph_unionfind.hpp
---
