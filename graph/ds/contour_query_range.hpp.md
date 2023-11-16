---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/centroid_decomposition.hpp
    title: graph/centroid_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/bfs01.hpp
    title: graph/shortest_path/bfs01.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/library_checker/datastructure/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp
    title: test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1038.test.cpp
    title: test/yukicoder/1038.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    #line 3 \"graph/shortest_path/bfs01.hpp\"\n\ntemplate <typename T, typename GT>\n\
    pair<vc<T>, vc<int>> bfs01(GT& G, int v) {\n  assert(G.is_prepared());\n  int\
    \ N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  deque<int> que;\n\
    \n  dist[v] = 0;\n  que.push_front(v);\n  while (!que.empty()) {\n    auto v =\
    \ que.front();\n    que.pop_front();\n    for (auto&& e: G[v]) {\n      if (dist[e.to]\
    \ == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {\n        dist[e.to] = dist[e.frm]\
    \ + e.cost;\n        par[e.to] = e.frm;\n        if (e.cost == 0)\n          que.push_front(e.to);\n\
    \        else\n          que.push_back(e.to);\n      }\n    }\n  }\n  return {dist,\
    \ par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\u30C8\u3002[dist, par, root]\n\
    template <typename T, typename GT>\ntuple<vc<T>, vc<int>, vc<int>> bfs01(GT& G,\
    \ vc<int> vs) {\n  assert(G.is_prepared());\n  int N = G.N;\n  vc<T> dist(N, infty<T>);\n\
    \  vc<int> par(N, -1);\n  vc<int> root(N, -1);\n  deque<int> que;\n\n  for (auto&&\
    \ v: vs) {\n    dist[v] = 0;\n    root[v] = v;\n    que.push_front(v);\n  }\n\n\
    \  while (!que.empty()) {\n    auto v = que.front();\n    que.pop_front();\n \
    \   for (auto&& e: G[v]) {\n      if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm]\
    \ + e.cost) {\n        dist[e.to] = dist[e.frm] + e.cost;\n        root[e.to]\
    \ = root[e.frm];\n        par[e.to] = e.frm;\n        if (e.cost == 0)\n     \
    \     que.push_front(e.to);\n        else\n          que.push_back(e.to);\n  \
    \    }\n    }\n  }\n  return {dist, par, root};\n}\n#line 3 \"graph/centroid_decomposition.hpp\"\
    \n\n/*\n\u9802\u70B9\u30D9\u30FC\u30B9\u306E\u91CD\u5FC3\u5206\u89E3\nf(par, V,\
    \ indptr)\n*/\ntemplate <typename F>\nvoid centroid_decomposition_0_dfs(vc<int>&\
    \ par, vc<int>& vs, F f) {\n  const int N = len(par);\n  assert(N >= 1);\n  int\
    \ c = -1;\n  vc<int> sz(N, 1);\n  FOR_R(i, N) {\n    if (sz[i] >= ceil<int>(N,\
    \ 2)) {\n      c = i;\n      break;\n    }\n    sz[par[i]] += sz[i];\n  }\n  vc<int>\
    \ color(N);\n  vc<int> V = {c};\n  int nc = 1;\n  FOR(v, 1, N) {\n    if (par[v]\
    \ == c) { V.eb(v), color[v] = nc++; }\n  }\n  if (c > 0) {\n    for (int a = par[c];\
    \ a != -1; a = par[a]) { color[a] = nc, V.eb(a); }\n    ++nc;\n  }\n  FOR(i, N)\
    \ {\n    if (i != c && color[i] == 0) color[i] = color[par[i]], V.eb(i);\n  }\n\
    \  vc<int> indptr(nc + 1);\n  FOR(i, N) indptr[1 + color[i]]++;\n  FOR(i, nc)\
    \ indptr[i + 1] += indptr[i];\n  vc<int> counter = indptr;\n  vc<int> ord(N);\n\
    \  for (auto& v: V) { ord[counter[color[v]]++] = v; }\n  vc<int> new_idx(N);\n\
    \  FOR(i, N) new_idx[ord[i]] = i;\n  vc<int> name(N);\n  FOR(i, N) name[new_idx[i]]\
    \ = vs[i];\n  {\n    vc<int> tmp(N, -1);\n    FOR(i, 1, N) {\n      int a = new_idx[i],\
    \ b = new_idx[par[i]];\n      if (a > b) swap(a, b);\n      tmp[b] = a;\n    }\n\
    \    swap(par, tmp);\n  }\n  f(par, name, indptr);\n  FOR(k, 1, nc) {\n    int\
    \ L = indptr[k], R = indptr[k + 1];\n    vc<int> par1(R - L, -1);\n    vc<int>\
    \ name1(R - L, -1);\n    name1[0] = name[0];\n    FOR(i, L, R) name1[i - L] =\
    \ name[i];\n    FOR(i, L, R) { par1[i - L] = max(par[i] - L, -1); }\n    centroid_decomposition_0_dfs(par1,\
    \ name1, f);\n  }\n}\n\n/*\nhttps://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d\n\
    centroid_decomposition_1\uFF1A\u9577\u3055 2 \u4EE5\u4E0A\u306E\u30D1\u30B9\u5168\
    \u4F53\nf(par, V, n1, n2)\n[1,1+n1]: color 1\n[1+n1,1+n1+n2]: color 2\n*/\ntemplate\
    \ <typename F>\nvoid centroid_decomposition_1_dfs(vc<int>& par, vc<int> vs, F\
    \ f) {\n  const int N = len(par);\n  assert(N > 1);\n  if (N == 2) { return; }\n\
    \  int c = -1;\n  vc<int> sz(N, 1);\n  FOR_R(i, N) {\n    if (sz[i] >= ceil<int>(N,\
    \ 2)) {\n      c = i;\n      break;\n    }\n    sz[par[i]] += sz[i];\n  }\n  vc<int>\
    \ color(N, -1);\n  int take = 0;\n  vc<int> ord(N, -1);\n  ord[c] = 0;\n  int\
    \ p = 1;\n  FOR(v, 1, N) {\n    if (par[v] == c && take + sz[v] <= floor<int>(N\
    \ - 1, 2)) {\n      color[v] = 0, ord[v] = p++, take += sz[v];\n    }\n  }\n \
    \ FOR(i, 1, N) {\n    if (color[par[i]] == 0) color[i] = 0, ord[i] = p++;\n  }\n\
    \  int n0 = p - 1;\n  for (int a = par[c]; a != -1; a = par[a]) { color[a] = 1,\
    \ ord[a] = p++; }\n  FOR(i, N) {\n    if (i != c && color[i] == -1) color[i] =\
    \ 1, ord[i] = p++;\n  }\n  assert(p == N);\n  int n1 = N - 1 - n0;\n  vc<int>\
    \ par0(n0 + 1, -1), par1(n1 + 1, -1), par2(N, -1);\n  vc<int> V0(n0 + 1), V1(n1\
    \ + 1), V2(N);\n  FOR(v, N) {\n    int i = ord[v];\n    V2[i] = vs[v];\n    if\
    \ (color[v] != 1) { V0[i] = vs[v]; }\n    if (color[v] != 0) { V1[max(i - n0,\
    \ 0)] = vs[v]; }\n  }\n  FOR(v, 1, N) {\n    int a = ord[v], b = ord[par[v]];\n\
    \    if (a > b) swap(a, b);\n    par2[b] = a;\n    if (color[v] != 1 && color[par[v]]\
    \ != 1) par0[b] = a;\n    if (color[v] != 0 && color[par[v]] != 0)\n      par1[max(b\
    \ - n0, 0)] = max(a - n0, 0);\n  }\n  f(par2, V2, n0, n1);\n  centroid_decomposition_1_dfs(par0,\
    \ V0, f);\n  centroid_decomposition_1_dfs(par1, V1, f);\n}\n\n/*\nhttps://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d\n\
    f(par2, V2, color)\ncolor in [-1,0,1], -1 is virtual.\n*/\ntemplate <typename\
    \ F>\nvoid centroid_decomposition_2_dfs(vc<int>& par, vc<int>& vs, vc<int>& real,\n\
    \                                  F f) {\n  const int N = len(par);\n  assert(N\
    \ > 1);\n  if (N == 2) {\n    if (real[0] && real[1]) {\n      vc<int> color =\
    \ {0, 1};\n      f(par, vs, color);\n    }\n    return;\n  }\n  int c = -1;\n\
    \  vc<int> sz(N, 1);\n  FOR_R(i, N) {\n    if (sz[i] >= ceil<int>(N, 2)) {\n \
    \     c = i;\n      break;\n    }\n    sz[par[i]] += sz[i];\n  }\n  vc<int> color(N,\
    \ -1);\n  int take = 0;\n  vc<int> ord(N, -1);\n  ord[c] = 0;\n  int p = 1;\n\
    \  FOR(v, 1, N) {\n    if (par[v] == c && take + sz[v] <= floor<int>(N - 1, 2))\
    \ {\n      color[v] = 0, ord[v] = p++, take += sz[v];\n    }\n  }\n  FOR(i, 1,\
    \ N) {\n    if (color[par[i]] == 0) color[i] = 0, ord[i] = p++;\n  }\n  int n0\
    \ = p - 1;\n  for (int a = par[c]; a != -1; a = par[a]) { color[a] = 1, ord[a]\
    \ = p++; }\n  FOR(i, N) {\n    if (i != c && color[i] == -1) color[i] = 1, ord[i]\
    \ = p++;\n  }\n  assert(p == N);\n  int n1 = N - 1 - n0;\n  vc<int> par0(n0 +\
    \ 1, -1), par1(n1 + 1, -1), par2(N, -1);\n  vc<int> V0(n0 + 1), V1(n1 + 1), V2(N);\n\
    \  vc<int> rea0(n0 + 1), rea1(n1 + 1), rea2(N);\n  FOR(v, N) {\n    int i = ord[v];\n\
    \    V2[i] = vs[v], rea2[i] = real[v];\n    if (color[v] != 1) { V0[i] = vs[v],\
    \ rea0[i] = real[v]; }\n    if (color[v] != 0) {\n      V1[max(i - n0, 0)] = vs[v],\
    \ rea1[max(i - n0, 0)] = real[v];\n    }\n  }\n  FOR(v, 1, N) {\n    int a = ord[v],\
    \ b = ord[par[v]];\n    if (a > b) swap(a, b);\n    par2[b] = a;\n    if (color[v]\
    \ != 1 && color[par[v]] != 1) par0[b] = a;\n    if (color[v] != 0 && color[par[v]]\
    \ != 0)\n      par1[max(b - n0, 0)] = max(a - n0, 0);\n  }\n  if (real[c]) {\n\
    \    color.assign(N, -1);\n    color[0] = 0;\n    FOR(i, 1, N) color[i] = rea2[i]\
    \ ? 1 : -1;\n    f(par2, V2, color);\n    rea0[0] = rea1[0] = rea2[0] = 0;\n \
    \ }\n  color.assign(N, -1);\n  FOR(i, 1, N) if (rea2[i]) color[i] = (i <= n0 ?\
    \ 0 : 1);\n  f(par2, V2, color);\n  centroid_decomposition_2_dfs(par0, V0, rea0,\
    \ f);\n  centroid_decomposition_2_dfs(par1, V1, rea1, f);\n}\n\n// f(par, V, color)\n\
    // V: label in original tree, dfs order\n// color in [-1,0,1], color=-1: virtual\n\
    template <int MODE, typename GT, typename F>\nvoid centroid_decomposition(GT&\
    \ G, F f) {\n  const int N = G.N;\n  if (N == 1) return;\n  vc<int> V(N), par(N,\
    \ -1);\n  int l = 0, r = 0;\n  V[r++] = 0;\n  while (l < r) {\n    int v = V[l++];\n\
    \    for (auto& e: G[v]) {\n      if (e.to != par[v]) V[r++] = e.to, par[e.to]\
    \ = v;\n    }\n  }\n  assert(r == N);\n  vc<int> new_idx(N);\n  FOR(i, N) new_idx[V[i]]\
    \ = i;\n  vc<int> tmp(N, -1);\n  FOR(i, 1, N) {\n    int j = par[i];\n    tmp[new_idx[i]]\
    \ = new_idx[j];\n  }\n  swap(par, tmp);\n  static_assert(MODE == 0 || MODE ==\
    \ 1 || MODE == 2);\n  if constexpr (MODE == 0) { centroid_decomposition_0_dfs(par,\
    \ V, f); }\n  elif constexpr(MODE == 1) { centroid_decomposition_1_dfs(par, V,\
    \ f); }\n  else {\n    vc<int> real(N, 1);\n    centroid_decomposition_2_dfs(par,\
    \ V, real, f);\n  }\n}\n#line 2 \"graph/ds/contour_query_range.hpp\"\n\n// \u8DDD\
    \u96E2 0 \u306F\u542B\u3081\u3066\u3044\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\
    \uFF01\ntemplate <typename GT, bool WEIGHTED>\nstruct Contour_Query_Range {\n\
    \  using WT = std::conditional_t<WEIGHTED, typename GT::cost_type, int>;\n  int\
    \ N;\n  vc<int> V;\n  vc<int> comp;\n  vc<WT> dep;\n  vc<int> info_idx, info_indptr;\n\
    \  vc<int> comp_range;\n\n  Contour_Query_Range(GT& G0) : N(G0.N) {\n    int p\
    \ = 0;\n    comp_range = {0};\n    auto f = [&](vc<int>& par, vc<int>& vs, vc<int>&\
    \ color) -> void {\n      const int n = len(par);\n      vc<WT> dist(n);\n   \
    \   vc<int> A, B;\n      FOR(v, 1, n) {\n        static_assert(!WEIGHTED);\n \
    \       dist[v] = dist[par[v]] + 1;\n      }\n      FOR(v, n) {\n        if (color[v]\
    \ == 0) A.eb(v);\n        if (color[v] == 1) B.eb(v);\n      }\n      if (A.empty()\
    \ || B.empty()) return;\n      int mx_A = 0, mx_B = 0;\n      for (auto& v: A)\
    \ {\n        V.eb(vs[v]), comp.eb(p), dep.eb(dist[v]), chmax(mx_A, dist[v]);\n\
    \      }\n      comp_range.eb(comp_range.back() + mx_A + 1), ++p;\n      for (auto&\
    \ v: B) {\n        V.eb(vs[v]), comp.eb(p), dep.eb(dist[v]), chmax(mx_B, dist[v]);\n\
    \      }\n      comp_range.eb(comp_range.back() + mx_B + 1), ++p;\n    };\n  \
    \  centroid_decomposition<2>(G0, f);\n    info_indptr.assign(N + 1, 0);\n    for\
    \ (auto& v: V) info_indptr[1 + v]++;\n    FOR(v, N) { info_indptr[v + 1] += info_indptr[v];\
    \ }\n    auto counter = info_indptr;\n    info_idx.resize(info_indptr.back());\n\
    \    FOR(i, len(V)) { info_idx[counter[V[i]]++] = i; }\n  }\n\n  int size() {\
    \ return comp_range.back(); }\n\n  vc<pair<int, int>> get_contour_range(int v,\
    \ WT l, WT r) {\n    vc<pair<int, int>> res;\n    FOR(k, info_indptr[v], info_indptr[v\
    \ + 1]) {\n      int idx = info_idx[k];\n      int p = comp[idx] ^ 1;\n      int\
    \ lo = l - dep[idx], hi = r - dep[idx];\n      int L = comp_range[p], R = comp_range[p\
    \ + 1];\n      int n = R - L;\n      chmax(lo, 0), chmin(hi, n);\n      if (lo\
    \ < hi) { res.eb(comp_range[p] + lo, comp_range[p] + hi); }\n    }\n    return\
    \ res;\n  }\n\n  vc<int> get_indices(int v) {\n    vc<int> res;\n    FOR(k, info_indptr[v],\
    \ info_indptr[v + 1]) {\n      int idx = info_idx[k];\n      int p = comp[idx];\n\
    \      res.eb(comp_range[p] + dep[idx]);\n    }\n    return res;\n  }\n};\n"
  code: "#include \"graph/centroid_decomposition.hpp\"\n\n// \u8DDD\u96E2 0 \u306F\
    \u542B\u3081\u3066\u3044\u306A\u3044\u3053\u3068\u306B\u6CE8\u610F\uFF01\ntemplate\
    \ <typename GT, bool WEIGHTED>\nstruct Contour_Query_Range {\n  using WT = std::conditional_t<WEIGHTED,\
    \ typename GT::cost_type, int>;\n  int N;\n  vc<int> V;\n  vc<int> comp;\n  vc<WT>\
    \ dep;\n  vc<int> info_idx, info_indptr;\n  vc<int> comp_range;\n\n  Contour_Query_Range(GT&\
    \ G0) : N(G0.N) {\n    int p = 0;\n    comp_range = {0};\n    auto f = [&](vc<int>&\
    \ par, vc<int>& vs, vc<int>& color) -> void {\n      const int n = len(par);\n\
    \      vc<WT> dist(n);\n      vc<int> A, B;\n      FOR(v, 1, n) {\n        static_assert(!WEIGHTED);\n\
    \        dist[v] = dist[par[v]] + 1;\n      }\n      FOR(v, n) {\n        if (color[v]\
    \ == 0) A.eb(v);\n        if (color[v] == 1) B.eb(v);\n      }\n      if (A.empty()\
    \ || B.empty()) return;\n      int mx_A = 0, mx_B = 0;\n      for (auto& v: A)\
    \ {\n        V.eb(vs[v]), comp.eb(p), dep.eb(dist[v]), chmax(mx_A, dist[v]);\n\
    \      }\n      comp_range.eb(comp_range.back() + mx_A + 1), ++p;\n      for (auto&\
    \ v: B) {\n        V.eb(vs[v]), comp.eb(p), dep.eb(dist[v]), chmax(mx_B, dist[v]);\n\
    \      }\n      comp_range.eb(comp_range.back() + mx_B + 1), ++p;\n    };\n  \
    \  centroid_decomposition<2>(G0, f);\n    info_indptr.assign(N + 1, 0);\n    for\
    \ (auto& v: V) info_indptr[1 + v]++;\n    FOR(v, N) { info_indptr[v + 1] += info_indptr[v];\
    \ }\n    auto counter = info_indptr;\n    info_idx.resize(info_indptr.back());\n\
    \    FOR(i, len(V)) { info_idx[counter[V[i]]++] = i; }\n  }\n\n  int size() {\
    \ return comp_range.back(); }\n\n  vc<pair<int, int>> get_contour_range(int v,\
    \ WT l, WT r) {\n    vc<pair<int, int>> res;\n    FOR(k, info_indptr[v], info_indptr[v\
    \ + 1]) {\n      int idx = info_idx[k];\n      int p = comp[idx] ^ 1;\n      int\
    \ lo = l - dep[idx], hi = r - dep[idx];\n      int L = comp_range[p], R = comp_range[p\
    \ + 1];\n      int n = R - L;\n      chmax(lo, 0), chmin(hi, n);\n      if (lo\
    \ < hi) { res.eb(comp_range[p] + lo, comp_range[p] + hi); }\n    }\n    return\
    \ res;\n  }\n\n  vc<int> get_indices(int v) {\n    vc<int> res;\n    FOR(k, info_indptr[v],\
    \ info_indptr[v + 1]) {\n      int idx = info_idx[k];\n      int p = comp[idx];\n\
    \      res.eb(comp_range[p] + dep[idx]);\n    }\n    return res;\n  }\n};"
  dependsOn:
  - graph/centroid_decomposition.hpp
  - graph/base.hpp
  - graph/shortest_path/bfs01.hpp
  isVerificationFile: false
  path: graph/ds/contour_query_range.hpp
  requiredBy: []
  timestamp: '2023-11-15 20:12:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1038.test.cpp
  - test/library_checker/datastructure/vertex_add_range_contour_sum_on_tree.test.cpp
  - test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp
documentation_of: graph/ds/contour_query_range.hpp
layout: document
redirect_from:
- /library/graph/ds/contour_query_range.hpp
- /library/graph/ds/contour_query_range.hpp.html
title: graph/ds/contour_query_range.hpp
---