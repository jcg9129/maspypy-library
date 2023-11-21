---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/vs_to_es.hpp
    title: graph/vs_to_es.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/arc157a.test.cpp
    title: test_atcoder/arc157a.test.cpp
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
    #line 2 \"graph/vs_to_es.hpp\"\n\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\
    \ntemplate <typename Val, int LOG = 20, bool KEEP_IDS = false>\r\nstruct HashMap\
    \ {\r\n  static constexpr int N = (1 << LOG);\r\n  u64* key;\r\n  Val* val;\r\n\
    \  vc<int> IDS;\r\n  bitset<N> used;\r\n  const int shift;\r\n  const u64 r =\
    \ 11995408973635179863ULL;\r\n  HashMap() : key(new u64[N]), val(new Val[N]),\
    \ shift(64 - LOG) {}\r\n  u32 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM\r\
    \n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n \
    \   return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    int i = index(k);\r\n    if (!used[i]) {\r\n      used[i] =\
    \ 1, key[i] = k, val[i] = Val{};\r\n      if constexpr (KEEP_IDS) IDS.eb(i);\r\
    \n    }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value)\
    \ {\r\n    int i = index(k);\r\n    if (!used[i]) return default_value;\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\
    \n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  void reset() {\r\n    static_assert(KEEP_IDS);\r\
    \n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  //\
    \ f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F f) {\r\n  \
    \  static_assert(KEEP_IDS);\r\n    for (auto&& i: IDS) f(key[i], val[i]);\r\n\
    \  }\r\n};\r\n#line 4 \"graph/vs_to_es.hpp\"\n\ntemplate <typename GT>\nvc<int>\
    \ vs_to_es(GT& G, vc<int>& vs, bool allow_use_twice = false) {\n  assert(!vs.empty());\n\
    \n  static HashMap<int, 20, true> MP;\n  MP.reset();\n  vc<int> nxt(G.M, -1);\n\
    \n  auto get = [&](ll a, ll b) -> u64 {\n    if (GT::is_directed && a > b) swap(a,\
    \ b);\n    return a * G.N + b;\n  };\n\n  FOR(eid, G.M) {\n    u64 k = get(G.edges[eid].frm,\
    \ G.edges[eid].to);\n    int x = MP[k];\n    nxt[eid] = x, MP[k] = eid;\n  }\n\
    \  int n = len(vs);\n  vc<int> es(n - 1);\n  FOR(i, n - 1) {\n    u64 k = get(vs[i],\
    \ vs[i + 1]);\n    int eid = MP.get(k, -1);\n    assert(eid != -1);\n    es[i]\
    \ = eid;\n    if (!allow_use_twice) { MP[k] = nxt[eid]; }\n  }\n  return es;\n\
    }\n#line 3 \"graph/eulerwalk.hpp\"\n\r\n// (vs, es) or empty\r\ntemplate <typename\
    \ GT>\r\npair<vc<int>, vc<int>> euler_walk(GT& G, int s = -1) {\r\n  const int\
    \ N = G.N, M = G.M;\r\n  assert(G.is_prepared());\r\n  assert(N > 0);\r\n\r\n\
    \  if (s == -1) {\r\n    vc<int> deg(N);\r\n    for (auto&& e: G.edges) {\r\n\
    \      if constexpr (GT::is_directed) {\r\n        deg[e.frm]++, deg[e.to]--;\r\
    \n      } else {\r\n        deg[e.frm]++, deg[e.to]++;\r\n      }\r\n    }\r\n\
    \    if constexpr (GT::is_directed) {\r\n      s = max_element(all(deg)) - deg.begin();\r\
    \n      if (deg[s] == 0) s = (M == 0 ? 0 : G.edges[0].frm);\r\n    } else {\r\n\
    \      s = [&]() -> int {\r\n        FOR(v, N) if (deg[v] & 1) return v;\r\n \
    \       return (M == 0 ? 0 : G.edges[0].frm);\r\n      }();\r\n    }\r\n  }\r\n\
    \r\n  if (M == 0) return {{s}, {}};\r\n  vc<int> D(N), its(N), eu(M), vs, st =\
    \ {s};\r\n  FOR(v, N) its[v] = G.indptr[v];\r\n  ++D[s];\r\n  while (!st.empty())\
    \ {\r\n    int x = st.back(), y, e, &it = its[x], end = G.indptr[x + 1];\r\n \
    \   if (it == end) {\r\n      vs.eb(x);\r\n      st.pop_back();\r\n      continue;\r\
    \n    }\r\n    auto& ee = G.csr_edges[it++];\r\n    y = ee.to, e = ee.id;\r\n\
    \    if (!eu[e]) {\r\n      D[x]--, D[y]++;\r\n      eu[e] = 1;\r\n      st.eb(y);\r\
    \n    }\r\n  }\r\n  for (auto&& x: D)\r\n    if (x < 0) return {{}, {}};\r\n \
    \ if (len(vs) != M + 1) return {{}, {}};\r\n  reverse(all(vs));\r\n  auto es =\
    \ vs_to_es(G, vs, false);\r\n  return {vs, es};\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n#include \"graph/vs_to_es.hpp\"\r\n\r\n//\
    \ (vs, es) or empty\r\ntemplate <typename GT>\r\npair<vc<int>, vc<int>> euler_walk(GT&\
    \ G, int s = -1) {\r\n  const int N = G.N, M = G.M;\r\n  assert(G.is_prepared());\r\
    \n  assert(N > 0);\r\n\r\n  if (s == -1) {\r\n    vc<int> deg(N);\r\n    for (auto&&\
    \ e: G.edges) {\r\n      if constexpr (GT::is_directed) {\r\n        deg[e.frm]++,\
    \ deg[e.to]--;\r\n      } else {\r\n        deg[e.frm]++, deg[e.to]++;\r\n   \
    \   }\r\n    }\r\n    if constexpr (GT::is_directed) {\r\n      s = max_element(all(deg))\
    \ - deg.begin();\r\n      if (deg[s] == 0) s = (M == 0 ? 0 : G.edges[0].frm);\r\
    \n    } else {\r\n      s = [&]() -> int {\r\n        FOR(v, N) if (deg[v] & 1)\
    \ return v;\r\n        return (M == 0 ? 0 : G.edges[0].frm);\r\n      }();\r\n\
    \    }\r\n  }\r\n\r\n  if (M == 0) return {{s}, {}};\r\n  vc<int> D(N), its(N),\
    \ eu(M), vs, st = {s};\r\n  FOR(v, N) its[v] = G.indptr[v];\r\n  ++D[s];\r\n \
    \ while (!st.empty()) {\r\n    int x = st.back(), y, e, &it = its[x], end = G.indptr[x\
    \ + 1];\r\n    if (it == end) {\r\n      vs.eb(x);\r\n      st.pop_back();\r\n\
    \      continue;\r\n    }\r\n    auto& ee = G.csr_edges[it++];\r\n    y = ee.to,\
    \ e = ee.id;\r\n    if (!eu[e]) {\r\n      D[x]--, D[y]++;\r\n      eu[e] = 1;\r\
    \n      st.eb(y);\r\n    }\r\n  }\r\n  for (auto&& x: D)\r\n    if (x < 0) return\
    \ {{}, {}};\r\n  if (len(vs) != M + 1) return {{}, {}};\r\n  reverse(all(vs));\r\
    \n  auto es = vs_to_es(G, vs, false);\r\n  return {vs, es};\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  - graph/vs_to_es.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: graph/eulerwalk.hpp
  requiredBy: []
  timestamp: '2023-11-21 19:08:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/arc157a.test.cpp
documentation_of: graph/eulerwalk.hpp
layout: document
redirect_from:
- /library/graph/eulerwalk.hpp
- /library/graph/eulerwalk.hpp.html
title: graph/eulerwalk.hpp
---
