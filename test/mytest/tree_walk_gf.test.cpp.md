---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
    title: graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/static_toptree.hpp
    title: graph/ds/static_toptree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/bfs01.hpp
    title: graph/shortest_path/bfs01.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_walk_generating_function.hpp
    title: graph/tree_walk_generating_function.hpp
  - icon: ':question:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_all.hpp
    title: poly/convolution_all.hpp
  - icon: ':question:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/fps_div.hpp
    title: poly/fps_div.hpp
  - icon: ':question:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/random_graph.hpp
    title: random/random_graph.hpp
  - icon: ':heavy_check_mark:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/tree_walk_gf.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n\n// \u53C2\u8003 https://codeforces.com/blog/entry/96344\n\
    // bmi,bmi2,lzcnt \u306F ucup \u3067\u30B3\u30F3\u30D1\u30A4\u30EB\u30A8\u30E9\
    \u30FC\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\n\
    template <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate\
    \ <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define overload4(a,\
    \ b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__,\
    \ FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload3(__VA_ARGS__,\
    \ FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define FOR_subset(t, s) \\\n  for (ll\
    \ t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n#define all(x) x.begin(),\
    \ x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\
    \n#define stoi stoll\n\nint popcnt(int x) { return __builtin_popcount(x); }\n\
    int popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_mod_2(int x) { return __builtin_parity(x); }\nint popcnt_mod_2(u32\
    \ x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll x) { return __builtin_parityll(x);\
    \ }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x); }\n// (0, 1, 2, 3,\
    \ 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n \
    \ T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
    \ &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate\
    \ <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok = true)\
    \ {\n  if (check_ok) assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate\
    \ <typename F>\ndouble binary_search_real(F check, double ok, double ng, int iter\
    \ = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok :\
    \ ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline\
    \ bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char)\
    \ {\n  vc<int> A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] -\
    \ first_char : -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T>\
    \ cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N +\
    \ 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n\
    \  return B;\n}\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n#endif\n#line 3 \"test/mytest/tree_walk_gf.test.cpp\"\n\n#line\
    \ 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n\
    \  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed = false>\n\
    struct Graph {\n  static constexpr bool is_directed = directed;\n  int N, M;\n\
    \  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n\
    \  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg,\
    \ vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n  \
    \  int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph() :\
    \ N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n\
    \  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
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
    #line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\
    \n\ntemplate <typename T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) swap(A[i],\
    \ A[RNG(0, i + 1)]);\n}\n#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind\
    \ {\n  int n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0)\
    \ { build(n); }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n,\
    \ -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n   \
    \ while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return\
    \ dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int\
    \ x) {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int\
    \ y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n \
    \   if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n};\n#line 5 \"random/random_graph.hpp\"\n\nvoid random_relabel(int\
    \ N, vc<pair<int, int>>& G) {\n  shuffle(G);\n  vc<int> A(N);\n  FOR(i, N) A[i]\
    \ = i;\n  shuffle(A);\n  for (auto& [a, b]: G) a = A[a], b = A[b];\n}\n\ntemplate\
    \ <int DIRECTED>\nvc<pair<int, int>> random_graph(int n, bool simple) {\n  vc<pair<int,\
    \ int>> G, cand;\n  FOR(a, n) FOR(b, n) {\n    if (simple && a == b) continue;\n\
    \    if (!DIRECTED && a > b) continue;\n    cand.eb(a, b);\n  }\n  int m = RNG(0,\
    \ len(cand) + 1);\n  set<int> ss;\n  FOR(m) {\n    while (1) {\n      int i =\
    \ RNG(0, len(cand));\n      if (simple && ss.count(i)) continue;\n      ss.insert(i);\n\
    \      auto [a, b] = cand[i];\n      G.eb(a, b);\n      break;\n    }\n  }\n \
    \ random_relabel(n, G);\n  return G;\n}\n\nvc<pair<int, int>> random_tree(int\
    \ n) {\n  vc<pair<int, int>> G;\n  FOR(i, 1, n) { G.eb(RNG(0, i), i); }\n  random_relabel(n,\
    \ G);\n  return G;\n}\n\n// EDGE = true: \u5404\u8FBA\u304C\u552F\u4E00\u306E\u30B5\
    \u30A4\u30AF\u30EB\uFF08\u95A2\u7BC0\u70B9\u3067\u30B5\u30A4\u30AF\u30EB\u307E\
    \u305F\u306F\u8FBA\uFF09\n// EDGE = false\uFF1A \u5404\u9802\u70B9\u304C\u552F\
    \u4E00\u306E\u30B5\u30A4\u30AF\u30EB\uFF08\u6A4B\u3067\u30B5\u30A4\u30AF\u30EB\
    \u307E\u305F\u306F\u8FBA\uFF09\nvc<pair<int, int>> random_cactus(int N, bool EDGE)\
    \ {\n  if (!EDGE) {\n    // n \u9802\u70B9\u3092 1 \u307E\u305F\u306F 3 \u4EE5\
    \u4E0A\u306B\u5206\u5272\n    vvc<int> A;\n    int n = RNG(1, N + 1);\n    vc<int>\
    \ S(n, 1);\n    int rest = N - n;\n    while (rest > 0) {\n      int k = RNG(0,\
    \ n);\n      if (S[k] == 1) {\n        if (rest == 1) {\n          S.eb(1), rest\
    \ = 0;\n        } else {\n          S[k] += 2, rest -= 2;\n        }\n      }\
    \ else {\n        S[k]++, rest--;\n      }\n    }\n    n = len(S);\n    int p\
    \ = 0;\n    FOR(i, n) {\n      vc<int> C;\n      FOR(v, p, p + S[i]) C.eb(v);\n\
    \      A.eb(C);\n      p += S[i];\n    }\n    int m = len(A);\n    auto H = random_tree(m);\n\
    \    vc<pair<int, int>> G;\n    FOR(i, m) {\n      vc<int>& V = A[i];\n      if\
    \ (len(V) == 1) continue;\n      FOR(k, len(V)) { G.eb(V[k], V[(1 + k) % len(V)]);\
    \ }\n    }\n    for (auto& [c1, c2]: H) {\n      int a = A[c1][RNG(0, len(A[c1]))];\n\
    \      int b = A[c2][RNG(0, len(A[c2]))];\n      G.eb(a, b);\n    }\n    random_relabel(N,\
    \ G);\n    return G;\n  }\n  assert(EDGE);\n  if (N == 1) return {};\n  int n\
    \ = RNG(1, N);\n  vc<int> S(n, 2);\n  int rest = N - 1 - n;\n  while (rest > 0)\
    \ {\n    int k = RNG(0, n);\n    S[k]++, --rest;\n  }\n  vvc<int> A;\n  int p\
    \ = 0;\n  FOR(i, n) {\n    vc<int> C;\n    FOR(v, p, p + S[i]) C.eb(v);\n    A.eb(C);\n\
    \    p += S[i];\n  }\n  assert(p == N + n - 1);\n  UnionFind uf(p);\n  auto H\
    \ = random_tree(n);\n  for (auto& [c1, c2]: H) {\n    int a = A[c1][RNG(0, len(A[c1]))];\n\
    \    int b = A[c2][RNG(0, len(A[c2]))];\n    uf.merge(a, b);\n  }\n  vc<int> new_idx(p);\n\
    \  int x = 0;\n  FOR(i, p) if (uf[i] == i) new_idx[i] = x++;\n  assert(x == N);\n\
    \  FOR(i, p) new_idx[i] = new_idx[uf[i]];\n  vc<pair<int, int>> G;\n  FOR(i, n)\
    \ {\n    vc<int>& V = A[i];\n    for (auto& v: V) v = new_idx[v];\n    if (len(V)\
    \ == 2) {\n      G.eb(V[0], V[1]);\n    } else {\n      FOR(k, len(V)) { G.eb(V[k],\
    \ V[(1 + k) % len(V)]); }\n    }\n  }\n  random_relabel(N, G);\n  return G;\n\
    }\n#line 1 \"graph/tree_walk_generating_function.hpp\"\n\n#line 2 \"graph/tree.hpp\"\
    \n\r\n#line 4 \"graph/tree.hpp\"\n\r\n// HLD euler tour \u3092\u3068\u3063\u3066\
    \u3044\u308D\u3044\u308D\u3002\r\ntemplate <typename GT>\r\nstruct Tree {\r\n\
    \  using Graph_type = GT;\r\n  GT &G;\r\n  using WT = typename GT::cost_type;\r\
    \n  int N;\r\n  vector<int> LID, RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\
    \n  vc<WT> depth_weighted;\r\n\r\n  Tree(GT &G, int r = 0, bool hld = 1) : G(G)\
    \ { build(r, hld); }\r\n\r\n  void build(int r = 0, bool hld = 1) {\r\n    if\
    \ (r == -1) return; // build \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\r\
    \n    N = G.N;\r\n    LID.assign(N, -1), RID.assign(N, -1), head.assign(N, r);\r\
    \n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\r\n    depth.assign(N,\
    \ -1), depth_weighted.assign(N, 0);\r\n    assert(G.is_prepared());\r\n    int\
    \ t1 = 0;\r\n    dfs_sz(r, -1, hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\r\n  void\
    \ dfs_sz(int v, int p, bool hld) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\
    \n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l\
    \ = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\n    //\
    \ \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n\
    \    for (int i = r - 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to]\
    \ == -1) swap(csr[i], csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for\
    \ (int i = l; i < r; ++i) {\r\n      auto e = csr[i];\r\n      if (depth[e.to]\
    \ != -1) continue;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\
    \n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to, v, hld);\r\n      sz[v] += sz[e.to];\r\
    \n      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\
    \n    }\r\n  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&e: G[v]) {\r\n      if (depth[e.to] <= depth[v]) continue;\r\n\
    \      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n    \
    \  dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int> heavy_path_at(int v)\
    \ {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int a = P.back();\r\n\
    \      for (auto &&e: G[a]) {\r\n        if (e.to != parent[a] && head[e.to] ==\
    \ v) {\r\n          P.eb(e.to);\r\n          break;\r\n        }\r\n      }\r\n\
    \      if (P.back() == a) break;\r\n    }\r\n    return P;\r\n  }\r\n\r\n  int\
    \ heavy_child(int v) {\r\n    int k = LID[v] + 1;\r\n    if (k == N) return -1;\r\
    \n    int w = V[k];\r\n    return (parent[w] == v ? w : -1);\r\n  }\r\n\r\n  int\
    \ e_to_v(int eid) {\r\n    auto e = G.edges[eid];\r\n    return (parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\
    \n\r\n  int ELID(int v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v)\
    \ { return 2 * RID[v] - depth[v] - 1; }\r\n\r\n  // \u76EE\u6A19\u5730\u70B9\u3078\
    \u9032\u3080\u500B\u6570\u304C k\r\n  int LA(int v, int k) {\r\n    assert(k <=\
    \ depth[v]);\r\n    while (1) {\r\n      int u = head[v];\r\n      if (LID[v]\
    \ - k >= LID[u]) return V[LID[v] - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n\
    \      v = parent[u];\r\n    }\r\n  }\r\n  int la(int u, int v) { return LA(u,\
    \ v); }\r\n\r\n  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\
    \n      if (LID[u] > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return\
    \ u;\r\n    }\r\n  }\r\n  // root \u3092\u6839\u3068\u3057\u305F\u5834\u5408\u306E\
    \ lca\r\n  int LCA_root(int u, int v, int root) {\r\n    return LCA(u, v) ^ LCA(u,\
    \ root) ^ LCA(v, root);\r\n  }\r\n  int lca(int u, int v) { return LCA(u, v);\
    \ }\r\n  int lca_root(int u, int v, int root) { return LCA_root(u, v, root); }\r\
    \n\r\n  int subtree_size(int v, int root = -1) {\r\n    if (root == -1) return\
    \ RID[v] - LID[v];\r\n    if (v == root) return N;\r\n    int x = jump(v, root,\
    \ 1);\r\n    if (in_subtree(v, x)) return RID[v] - LID[v];\r\n    return N - RID[x]\
    \ + LID[x];\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\
    \n    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  WT dist_weighted(int\
    \ a, int b) {\r\n    int c = LCA(a, b);\r\n    return depth_weighted[a] + depth_weighted[b]\
    \ - WT(2) * depth_weighted[c];\r\n  }\r\n\r\n  // a is in b\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int jump(int\
    \ a, int b, ll k) {\r\n    if (k == 1) {\r\n      if (a == b) return -1;\r\n \
    \     return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\
    \n    }\r\n    int c = LCA(a, b);\r\n    int d_ac = depth[a] - depth[c];\r\n \
    \   int d_bc = depth[b] - depth[c];\r\n    if (k > d_ac + d_bc) return -1;\r\n\
    \    if (k <= d_ac) return LA(a, k);\r\n    return LA(b, d_ac + d_bc - k);\r\n\
    \  }\r\n\r\n  vc<int> collect_child(int v) {\r\n    vc<int> res;\r\n    for (auto\
    \ &&e: G[v])\r\n      if (e.to != parent[v]) res.eb(e.to);\r\n    return res;\r\
    \n  }\r\n\r\n  vc<int> collect_light(int v) {\r\n    vc<int> res;\r\n    bool\
    \ skip = true;\r\n    for (auto &&e: G[v])\r\n      if (e.to != parent[v]) {\r\
    \n        if (!skip) res.eb(e.to);\r\n        skip = false;\r\n      }\r\n   \
    \ return res;\r\n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int u,\
    \ int v, bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\"\u533A\
    \u9593\u5217\u3002\r\n    vc<pair<int, int>> up, down;\r\n    while (1) {\r\n\
    \      if (head[u] == head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n    \
    \    down.eb(LID[head[v]], LID[v]);\r\n        v = parent[head[v]];\r\n      }\
    \ else {\r\n        up.eb(LID[u], LID[head[u]]);\r\n        u = parent[head[u]];\r\
    \n      }\r\n    }\r\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\
    \n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\
    \n    up.insert(up.end(), all(down));\r\n    return up;\r\n  }\r\n\r\n  vc<int>\
    \ restore_path(int u, int v) {\r\n    vc<int> P;\r\n    for (auto &&[a, b]: get_path_decomposition(u,\
    \ v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i, a, b + 1) P.eb(V[i]);\r\n\
    \      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\n      }\r\n    }\r\
    \n    return P;\r\n  }\r\n};\r\n#line 2 \"graph/ds/static_toptree.hpp\"\n\n/*\n\
    tute \u3055\u3093\u306E\u5B9F\u88C5 https://yukicoder.me/submissions/838092 \u3092\
    \u53C2\u8003\u306B\u3057\u3066\u3044\u308B.\n\u3044\u308F\u3086\u308B toptree\
    \ \uFF08\u8FBA\u304B\u3089\u306F\u3058\u3081\u3066\u30DE\u30FC\u30B8\u904E\u7A0B\
    \u3092\u6728\u306B\u3059\u308B\uFF09\u3068\u306F\u5C11\u3057\u7570\u306A\u308B\
    \u306F\u305A.\n\u6728\u3092\u300Cheavy path \u4E0A\u306E\u8FBA\u3067\u5206\u5272\
    \u300D\u300C\u6839\u3092 virtual \u306B\u3059\u308B\u300D\n\u300Clight edges \u306E\
    \u5206\u5272\u300D\u300Clight edge \u3092\u6D88\u3059\u300D\u3067\u9802\u70B9\u306B\
    \u5206\u5272\u3057\u3066\u3044\u304F.\n\u9006\u306B\u305F\u3069\u308C\u3070\uFF0C\
    1 \u9802\u70B9\u304B\u3089\u306F\u3058\u3081\u3066\u6728\u5168\u4F53\u3092\u4F5C\
    \u308B\u9AD8\u3055 O(logN) \u306E\u6728\u306B\u306A\u308B.\n\u9AD8\u3055\u306B\
    \u3064\u3044\u3066\uFF1Ahttps://www.mathenachia.blog/mergetech-and-logn/\n\u30FB\
    lch == rch == -1\uFF1A\u9802\u70B9\n\u30FBrch == -1\uFF1A\n  \u30FBheavy \u306A\
    \u3089 light \u306E\u96C6\u7D04\u306B\u9802\u70B9\u3092\u4ED8\u52A0\u3057\u305F\
    \u3082\u306E\n  \u30FBlight \u306A\u3089 \u6839\u4ED8\u304D\u6728\u306B light\
    \ edge \u3092\u4ED8\u52A0\u3057\u305F\u3082\u306E\n\u30FB\u5B50\u304C 2 \u3064\
    \n  \u30FBheavy \u306A\u3089 heavy path \u3092\u8FBA\u3067\u7D50\u5408\u3057\u305F\
    \u3082\u306E\n  \u30FBlight \u306A\u3089 light edge \u305F\u3061\u306E\u30DE\u30FC\
    \u30B8\n*/\ntemplate <typename TREE>\nstruct Static_TopTree {\n  TREE &tree;\n\
    \n  vc<int> par, lch, rch, A, B;\n  vc<bool> heavy;\n\n  Static_TopTree(TREE &tree)\
    \ : tree(tree) {\n    int root = tree.V[0];\n    build(root);\n    // relabel\n\
    \    int n = len(par);\n    reverse(all(par)), reverse(all(lch)), reverse(all(rch)),\
    \ reverse(all(A)),\n        reverse(all(B)), reverse(all(heavy));\n    for (auto\
    \ &x: par) x = (x == -1 ? -1 : n - 1 - x);\n    for (auto &x: lch) x = (x == -1\
    \ ? -1 : n - 1 - x);\n    for (auto &x: rch) x = (x == -1 ? -1 : n - 1 - x);\n\
    \  }\n\n  // \u6728\u5168\u4F53\u3067\u306E\u96C6\u7D04\u5024\u3092\u5F97\u308B\
    \n  // from_vertex(v)\n  // add_vertex(x, v)\n  // add_edge(x, u, v)  : u \u304C\
    \u89AA\n  // merge_light(x, y)\n  // merge_heavy(x, y, a, b, c, d)  : [a,b] +\
    \ [c,d] = [a,d]\n  template <typename Data, typename F1, typename F2, typename\
    \ F3, typename F4,\n            typename F5>\n  Data tree_dp(F1 from_vertex, F2\
    \ add_vertex, F3 add_edge, F4 merge_light,\n               F5 merge_heavy) {\n\
    \    auto dfs = [&](auto &dfs, int k) -> Data {\n      if (lch[k] == -1 && rch[k]\
    \ == -1) { return from_vertex(A[k]); }\n      if (rch[k] == -1) {\n        Data\
    \ x = dfs(dfs, lch[k]);\n        if (heavy[k]) {\n          return add_vertex(x,\
    \ A[k]);\n        } else {\n          return add_edge(x, A[k], B[lch[k]]);\n \
    \       }\n      }\n      Data x = dfs(dfs, lch[k]);\n      Data y = dfs(dfs,\
    \ rch[k]);\n      if (heavy[k]) {\n        return merge_heavy(x, y, A[lch[k]],\
    \ B[lch[k]], A[rch[k]], B[rch[k]]);\n      }\n      return merge_light(x, y);\n\
    \    };\n    return dfs(dfs, 0);\n  }\n\nprivate:\n  int add_node(int l, int r,\
    \ int a, int b, bool h) {\n    int ret = len(par);\n    par.eb(-1), lch.eb(l),\
    \ rch.eb(r), A.eb(a), B.eb(b), heavy.eb(h);\n    if (l != -1) par[l] = ret;\n\
    \    if (r != -1) par[r] = ret;\n    return ret;\n  }\n\n  int build(int v) {\n\
    \    // v \u306F heavy path \u306E\u6839\u306A\u306E\u3067 v \u3092\u6839\u3068\
    \u3059\u308B\u90E8\u5206\u6728\u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\
    \u3092\u4F5C\u308B\n    assert(tree.head[v] == v);\n    auto path = tree.heavy_path_at(v);\n\
    \    reverse(all(path));\n\n    auto dfs = [&](auto &dfs, int l, int r) -> int\
    \ {\n      // path[l:r)\n      if (l + 1 < r) {\n        int m = (l + r) / 2;\n\
    \        int x = dfs(dfs, l, m);\n        int y = dfs(dfs, m, r);\n        return\
    \ add_node(x, y, path[l], path[r - 1], true);\n      }\n      assert(r == l +\
    \ 1);\n      int me = path[l];\n      // sz, idx\n      pqg<pair<int, int>> que;\n\
    \      for (auto &to: tree.collect_light(me)) {\n        int x = build(to);\n\
    \        int y = add_node(x, -1, me, me, false);\n        que.emplace(tree.subtree_size(to),\
    \ y);\n      }\n      if (que.empty()) { return add_node(-1, -1, me, me, true);\
    \ }\n      while (len(que) >= 2) {\n        auto [s1, x] = POP(que);\n       \
    \ auto [s2, y] = POP(que);\n        int z = add_node(x, y, me, me, false);\n \
    \       que.emplace(s1 + s2, z);\n      }\n      auto [s, x] = POP(que);\n   \
    \   return add_node(x, -1, me, me, true);\n    };\n    return dfs(dfs, 0, len(path));\n\
    \  }\n};\n#line 3 \"graph/shortest_path/bfs01.hpp\"\n\ntemplate <typename T, typename\
    \ GT>\npair<vc<T>, vc<int>> bfs01(GT& G, int v) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  deque<int>\
    \ que;\n\n  dist[v] = 0;\n  que.push_front(v);\n  while (!que.empty()) {\n   \
    \ auto v = que.front();\n    que.pop_front();\n    for (auto&& e: G[v]) {\n  \
    \    if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {\n    \
    \    dist[e.to] = dist[e.frm] + e.cost;\n        par[e.to] = e.frm;\n        if\
    \ (e.cost == 0)\n          que.push_front(e.to);\n        else\n          que.push_back(e.to);\n\
    \      }\n    }\n  }\n  return {dist, par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\
    \u30C8\u3002[dist, par, root]\ntemplate <typename T, typename GT>\ntuple<vc<T>,\
    \ vc<int>, vc<int>> bfs01(GT& G, vc<int> vs) {\n  assert(G.is_prepared());\n \
    \ int N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  vc<int> root(N,\
    \ -1);\n  deque<int> que;\n\n  for (auto&& v: vs) {\n    dist[v] = 0;\n    root[v]\
    \ = v;\n    que.push_front(v);\n  }\n\n  while (!que.empty()) {\n    auto v =\
    \ que.front();\n    que.pop_front();\n    for (auto&& e: G[v]) {\n      if (dist[e.to]\
    \ == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {\n        dist[e.to] = dist[e.frm]\
    \ + e.cost;\n        root[e.to] = root[e.frm];\n        par[e.to] = e.frm;\n \
    \       if (e.cost == 0)\n          que.push_front(e.to);\n        else\n    \
    \      que.push_back(e.to);\n      }\n    }\n  }\n  return {dist, par, root};\n\
    }\n#line 4 \"graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp\"\n\n\
    // det(I-xA) \u306E\u8A08\u7B97 (\u56FA\u6709\u591A\u9805\u5F0F\u306E reverse\
    \ \u306B\u306A\u3063\u3066\u3044\u308B)\n// weight(i,j)\uFF1AA[i][j]\n// \u5076\
    \u6570\u6B21\u3060\u3051\u3057\u304B\u51FA\u3066\u3053\u306A\u3044\u306E\u3067\
    \ loop \u3042\u308A\u3088\u308A\u9AD8\u901F\ntemplate <typename mint, typename\
    \ F>\nvc<mint> characteristic_poly_of_tree_adjacency_matrix_not_allow_loop(\n\
    \    Graph<int, 0>& G, F weight) {\n  // int N = G.N;\n  // vv(mint, A, N, N);\n\
    \  // vv(mint, B, N, N);\n  // FOR(i, N) A[i][i] = 1;\n  // FOR(i, N) {\n  //\
    \   for (auto& e: G[i]) { B[i][e.to] = -weight(i, e.to); }\n  // }\n  // return\
    \ det_A_plus_xB(A, B);\n  using poly = vc<mint>;\n  Tree<Graph<int, 0>> tree(G);\n\
    \  Static_TopTree<decltype(tree)> STT(tree);\n\n  using Data = array<array<poly,\
    \ 2>, 2>;\n  auto add = [&](poly& f, poly& g, int s, mint wt = 1) -> void {\n\
    \    if (g.empty()) return;\n    if (len(f) < len(g) + s) f.resize(len(g) + s);\n\
    \    FOR(i, len(g)) f[s + i] += g[i] * wt;\n  };\n  auto from_vertex = [&](int\
    \ v) -> Data {\n    Data X;\n    X[0][0] = poly{mint(1)};\n    return X;\n  };\n\
    \  auto add_vertex = [&](Data& X, int v) -> Data { return X; };\n  auto add_edge\
    \ = [&](Data& X, int u, int v) -> Data {\n    mint wt = -weight(u, v) * weight(v,\
    \ u);\n    Data Y;\n    FOR(a, 2) {\n      add(Y[0][0], X[a][0], 0);\n      add(Y[1][1],\
    \ X[a][0], 1, wt);\n      add(Y[0][0], X[a][1], 0);\n    }\n    return Y;\n  };\n\
    \  auto merge_light = [&](Data& X, Data& Y) -> Data {\n    poly &X0 = X[0][0],\
    \ &X1 = X[1][1];\n    poly &Y0 = Y[0][0], &Y1 = Y[1][1];\n    poly A = convolution(X0,\
    \ Y0);\n    poly B = convolution(X0, Y1);\n    poly C = convolution(X1, Y0);\n\
    \    Data Z;\n    add(Z[0][0], A, 0), add(Z[1][1], B, 0), add(Z[1][1], C, 0);\n\
    \    return Z;\n  };\n  auto merge_heavy\n      = [&](Data& X, Data& Y, int va,\
    \ int vb, int vc, int vd) -> Data {\n    Data Z;\n    mint wt = -weight(vb, vc)\
    \ * weight(vc, vb);\n    FOR(a, 2) FOR(d, 2) {\n      poly f0 = X[a][0], &f1 =\
    \ X[a][1];\n      poly g0 = Y[0][d], &g1 = Y[1][d];\n      // \u8FBA\u3092\u4F7F\
    \u3046\n      poly f = convolution(f0, g0);\n      int x = (va != vb ? a : 1);\n\
    \      int y = (vc != vd ? d : 1);\n      add(Z[x][y], f, 1, wt);\n      // \u8FBA\
    \u3092\u4F7F\u308F\u306A\u3044\n      add(f0, f1, 0), add(g0, g1, 0);\n      f\
    \ = convolution(f0, g0);\n      add(Z[a][d], f, 0);\n    }\n    return Z;\n  };\n\
    \n  Data X = STT.tree_dp<Data>(from_vertex, add_vertex, add_edge, merge_light,\n\
    \                             merge_heavy);\n  vc<mint> ANS(G.N + 1);\n  FOR(a,\
    \ 2) FOR(b, 2) {\n    FOR(i, len(X[a][b])) { ANS[2 * i] += X[a][b][i]; }\n  }\n\
    \  return ANS;\n}\n\ntemplate <typename mint, typename F>\nvc<mint> characteristic_poly_of_tree_adjacency_matrix_allow_loop(\n\
    \    Graph<int, 0>& G, F weight) {\n  // \u70B9\u3068\u30DE\u30C3\u30C1\u30F3\u30B0\
    \u306B\u5206\u89E3\n  // \u30DE\u30C3\u30C1\u30F3\u30B0\uFF1A-w[i][j]w[j][i]x^2\n\
    \  // \u70B9\uFF1A1-w[i][i]x\n  using poly = vc<mint>;\n  Tree<Graph<int, 0>>\
    \ tree(G);\n  Static_TopTree<decltype(tree)> STT(tree);\n\n  using Data = array<array<poly,\
    \ 2>, 2>;\n  auto add = [&](poly& f, poly& g, int s, mint wt = 1) -> void {\n\
    \    if (g.empty()) return;\n    if (len(f) < len(g) + s) f.resize(len(g) + s);\n\
    \    FOR(i, len(g)) f[s + i] += g[i] * wt;\n  };\n  auto from_vertex = [&](int\
    \ v) -> Data {\n    mint wt = weight(v, v);\n    Data X;\n    X[0][0] = poly{mint(1)};\n\
    \    X[1][1] = poly{mint(1), -wt};\n    return X;\n  };\n  auto add_vertex = [&](Data&\
    \ X, int v) -> Data {\n    mint wt = weight(v, v);\n    // 1-wtx\n    add(X[1][1],\
    \ X[0][0], 0, mint(1));\n    add(X[1][1], X[0][0], 1, -wt);\n    return X;\n \
    \ };\n  auto add_edge = [&](Data& X, int u, int v) -> Data {\n    if (X[0][1].empty())\
    \ { X[1][0] = X[0][0]; }\n    mint wt = weight(u, v) * weight(v, u);\n    Data\
    \ Y;\n    add(Y[1][1], X[1][0], 2, -wt);\n    add(Y[0][0], X[1][1], 0);\n    return\
    \ Y;\n  };\n  auto merge_light = [&](Data& X, Data& Y) -> Data {\n    poly &X0\
    \ = X[0][0], &X1 = X[1][1];\n    poly &Y0 = Y[0][0], &Y1 = Y[1][1];\n    poly\
    \ A = convolution(X0, Y0);\n    poly B = convolution(X0, Y1);\n    poly C = convolution(X1,\
    \ Y0);\n    Data Z;\n    add(Z[0][0], A, 0), add(Z[1][1], B, 0), add(Z[1][1],\
    \ C, 0);\n    return Z;\n  };\n  auto merge_heavy\n      = [&](Data& X, Data&\
    \ Y, int va, int vb, int vc, int vd) -> Data {\n    Data Z;\n    mint wt = weight(vb,\
    \ vc) * weight(vc, vb);\n    FOR(a, 2) FOR(b, 2) FOR(c, 2) FOR(d, 2) {\n     \
    \ bool non_use = 1;\n      bool use = (b == 0) && (c == 0);\n      if (va != vb\
    \ && b == 0) non_use = 0;\n      if (vc != vd && c == 0) non_use = 0;\n      if\
    \ (!non_use && !use) continue;\n      poly f = convolution(X[a][b], Y[c][d]);\n\
    \      if (non_use) add(Z[a][d], f, 0);\n      if (use) {\n        int x = (va\
    \ != vb ? a : 1);\n        int y = (vc != vd ? d : 1);\n        add(Z[x][y], f,\
    \ 2, -wt);\n      }\n    }\n    return Z;\n  };\n\n  Data X = STT.tree_dp<Data>(from_vertex,\
    \ add_vertex, add_edge, merge_light,\n                             merge_heavy);\n\
    \  poly& ANS = X[1][1];\n  return ANS;\n}\n\n// det(I-xA) \u306E\u8A08\u7B97 (\u56FA\
    \u6709\u591A\u9805\u5F0F\u306E reverse \u306B\u306A\u3063\u3066\u3044\u308B)\n\
    // weight(i,j)\uFF1AA[i][j]\ntemplate <bool ALLOW_LOOP, typename mint, typename\
    \ F>\nvc<mint> characteristic_poly_of_tree_adjacency_matrix(Graph<int, 0>& G,\n\
    \                                                      F weight) {\n  if constexpr\
    \ (ALLOW_LOOP) {\n    return characteristic_poly_of_tree_adjacency_matrix_allow_loop<mint>(\n\
    \        G, weight);\n  } else {\n    return characteristic_poly_of_tree_adjacency_matrix_not_allow_loop<mint>(\n\
    \        G, weight);\n  }\n}\n#line 2 \"poly/convolution_all.hpp\"\n\r\n#line\
    \ 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class T>\n\
    \  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n  template\
    \ <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate <class\
    \ T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint>\
    \ dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1)\
    \ * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head, class...\
    \ Tail>\nmint multinomial(Head &&head, Tail &&... tail) {\n  return fact<mint>(head)\
    \ * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\ntemplate <typename mint>\n\
    mint C_dense(int n, int k) {\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n\
    \  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1)\
    \ : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if\
    \ (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k +\
    \ 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n\
    \    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j,\
    \ W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n\
    }\n\ntemplate <typename mint, bool large = false, bool dense = false>\nmint C(ll\
    \ n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr\
    \ (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n\
    \ >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) { return (d == 0 ? mint(1)\
    \ : mint(0)); }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n#line 3 \"\
    mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static constexpr u32\
    \ umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n\n  static\
    \ modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n  }\n  constexpr\
    \ modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod) {}\n  constexpr\
    \ modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x) : val(x % umod)\
    \ {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr\
    \ modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(i128\
    \ x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const modint &other)\
    \ const { return val < other.val; }\n  modint &operator+=(const modint &p) {\n\
    \    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n  }\n  modint\
    \ &operator-=(const modint &p) {\n    if ((val += umod - p.val) >= umod) val -=\
    \ umod;\n    return *this;\n  }\n  modint &operator*=(const modint &p) {\n   \
    \ val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint &operator/=(const\
    \ modint &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  modint operator-()\
    \ const { return modint::raw(val ? mod - val : u32(0)); }\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n  modint operator*(const modint &p)\
    \ const { return modint(*this) *= p; }\n  modint operator/(const modint &p) const\
    \ { return modint(*this) /= p; }\n  bool operator==(const modint &p) const { return\
    \ val == p.val; }\n  bool operator!=(const modint &p) const { return val != p.val;\
    \ }\n  modint inverse() const {\n    int a = val, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll n) const {\n  \
    \  assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n      if\
    \ (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r \u306F\
    \ 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info() {\n\
    \    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161) return\
    \ {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod == 754974721)\
    \ return {24, 362};\n    if (mod == 880803841) return {23, 211};\n    if (mod\
    \ == 943718401) return {22, 663003469};\n    if (mod == 998244353) return {23,\
    \ 31};\n    if (mod == 1045430273) return {20, 363};\n    if (mod == 1051721729)\
    \ return {20, 330};\n    if (mod == 1053818881) return {20, 2789};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"mod/mod_inv.hpp\"\n\r\n// long \u3067\u3082\u5927\u4E08\u592B\r\n//\
    \ (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\
    \u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\
    \r\nll mod_inv(ll val, ll mod) {\r\n  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\
    \n  val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1,\
    \ v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n\
    #line 1 \"mod/crt3.hpp\"\n\nconstexpr u32 mod_pow_constexpr(u64 a, u64 n, u32\
    \ mod) {\n  a %= mod;\n  u64 res = 1;\n  FOR(32) {\n    if (n & 1) res = res *\
    \ a % mod;\n    a = a * a % mod, n /= 2;\n  }\n  return res;\n}\n\ntemplate <typename\
    \ T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0\
    \ < p1 && p1 < p2);\n  static constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 -\
    \ 2, p1);\n  static constexpr u64 x01_2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  u64 c = (a1 - a0 + p1) * x0_1 % p1;\n  u64 a = a0 + c * p0;\n\
    \  c = (a2 - a % p2 + p2) * x01_2 % p2;\n  return T(a) + T(c) * T(p0) * T(p1);\n\
    }\n#line 2 \"poly/convolution_naive.hpp\"\n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\r\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\r\n\
    \  int n = int(a.size()), m = int(b.size());\r\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\r\n  if (n == 0) return {};\r\n  vector<T> ans(n + m - 1);\r\n  FOR(i, n)\
    \ FOR(j, m) ans[i + j] += a[i] * b[j];\r\n  return ans;\r\n}\r\n\r\ntemplate <class\
    \ T, typename enable_if<has_mod<T>::value>::type* = nullptr>\r\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()), m = int(b.size());\r\
    \n  if (n > m) return convolution_naive<T>(b, a);\r\n  if (n == 0) return {};\r\
    \n  vc<T> ans(n + m - 1);\r\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\r\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\r\n      int s = max(0, k - m + 1);\r\
    \n      int t = min(n, k + 1);\r\n      u64 sm = 0;\r\n      for (int i = s; i\
    \ < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\n      ans[k] = sm;\r\n\
    \    }\r\n  } else {\r\n    for (int k = 0; k < n + m - 1; ++k) {\r\n      int\
    \ s = max(0, k - m + 1);\r\n      int t = min(n, k + 1);\r\n      u128 sm = 0;\r\
    \n      for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\
    \n      ans[k] = T::raw(sm % T::get_mod());\r\n    }\r\n  }\r\n  return ans;\r\
    \n}\r\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n// \u4EFB\u610F\u306E\u74B0\
    \u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T> convolution_karatsuba(const\
    \ vc<T>& f, const vc<T>& g) {\n  const int thresh = 30;\n  if (min(len(f), len(g))\
    \ <= thresh) return convolution_naive(f, g);\n  int n = max(len(f), len(g));\n\
    \  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n  if (len(f) < m) f1 = f;\n \
    \ if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n  if (len(f) >= m) f2 = {f.begin()\
    \ + m, f.end()};\n  if (len(g) < m) g1 = g;\n  if (len(g) >= m) g1 = {g.begin(),\
    \ g.begin() + m};\n  if (len(g) >= m) g2 = {g.begin() + m, g.end()};\n  vc<T>\
    \ a = convolution_karatsuba(f1, g1);\n  vc<T> b = convolution_karatsuba(f2, g2);\n\
    \  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i, len(g2)) g1[i] += g2[i];\n  vc<T>\
    \ c = convolution_karatsuba(f1, g1);\n  vc<T> F(len(f) + len(g) - 1);\n  assert(2\
    \ * m + len(b) <= len(F));\n  FOR(i, len(a)) F[i] += a[i], c[i] -= a[i];\n  FOR(i,\
    \ len(b)) F[2 * m + i] += b[i], c[i] -= b[i];\n  if (c.back() == T(0)) c.pop_back();\n\
    \  FOR(i, len(c)) if (c[i] != T(0)) F[m + i] += c[i];\n  return F;\n}\n#line 2\
    \ \"poly/ntt.hpp\"\n\r\ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool\
    \ inverse) {\r\n  assert(mint::can_ntt());\r\n  const int rank2 = mint::ntt_info().fi;\r\
    \n  const int mod = mint::get_mod();\r\n  static array<mint, 30> root, iroot;\r\
    \n  static array<mint, 30> rate2, irate2;\r\n  static array<mint, 30> rate3, irate3;\r\
    \n\r\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\r\n\r\n  static\
    \ bool prepared = 0;\r\n  if (!prepared) {\r\n    prepared = 1;\r\n    root[rank2]\
    \ = mint::ntt_info().se;\r\n    iroot[rank2] = mint(1) / root[rank2];\r\n    FOR_R(i,\
    \ rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\r\n    }\r\n    mint prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 2; i++) {\r\n      rate2[i] = root[i + 2] * prod;\r\n  \
    \    irate2[i] = iroot[i + 2] * iprod;\r\n      prod *= iroot[i + 2];\r\n    \
    \  iprod *= root[i + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 3; i++) {\r\n      rate3[i] = root[i + 3] * prod;\r\n  \
    \    irate3[i] = iroot[i + 3] * iprod;\r\n      prod *= iroot[i + 3];\r\n    \
    \  iprod *= root[i + 3];\r\n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\n \
    \ int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  if (!inverse) {\r\n    int\
    \ len = 0;\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n        int\
    \ p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1 << len)\
    \ {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\n   \
    \         auto l = a[i + offset];\r\n            auto r = a[i + offset + p] *\
    \ rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= rate2[topbit(~s & -~s)];\r\n   \
    \     }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len -\
    \ 2);\r\n        mint rot = 1, imag = root[2];\r\n        for (int s = 0; s <\
    \ (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint rot3\
    \ = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for (int\
    \ i = 0; i < p; i++) {\r\n            u64 mod2 = u64(mod) * mod;\r\n         \
    \   u64 a0 = a[i + offset].val;\r\n            u64 a1 = u64(a[i + offset + p].val)\
    \ * rot.val;\r\n            u64 a2 = u64(a[i + offset + 2 * p].val) * rot2.val;\r\
    \n            u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\r\n        \
    \    u64 a1na3imag = (a1 + mod2 - a3) % mod * imag.val;\r\n            u64 na2\
    \ = mod2 - a2;\r\n            a[i + offset] = a0 + a2 + a1 + a3;\r\n         \
    \   a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i\
    \ + offset + 2 * p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 *\
    \ p] = a0 + na2 + (mod2 - a1na3imag);\r\n          }\r\n          rot *= rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            u64 l = a[i + offset].val;\r\n            u64 r = a[i + offset +\
    \ p].val;\r\n            a[i + offset] = l + r;\r\n            a[i + offset +\
    \ p] = (mod + l - r) * irot.val;\r\n          }\r\n          irot *= irate2[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len--;\r\n      } else {\r\n        int p =\
    \ 1 << (h - len);\r\n        mint irot = 1, iimag = iroot[2];\r\n        FOR(s,\
    \ (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n          mint\
    \ irot3 = irot2 * irot;\r\n          int offset = s << (h - len + 2);\r\n    \
    \      for (int i = 0; i < p; i++) {\r\n            u64 a0 = a[i + offset + 0\
    \ * p].val;\r\n            u64 a1 = a[i + offset + 1 * p].val;\r\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\r\n            u64 a3 = a[i + offset + 3\
    \ * p].val;\r\n            u64 x = (mod + a2 - a3) * iimag.val % mod;\r\n    \
    \        a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset + 1 *\
    \ p] = (a0 + mod - a1 + x) * irot.val;\r\n            a[i + offset + 2 * p] =\
    \ (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\r\n            a[i + offset + 3 *\
    \ p] = (a0 + 2 * mod - a1 - x) * irot3.val;\r\n          }\r\n          irot *=\
    \ irate3[topbit(~s & -~s)];\r\n        }\r\n        len -= 2;\r\n      }\r\n \
    \   }\r\n  }\r\n}\r\n#line 1 \"poly/fft.hpp\"\nnamespace CFFT {\r\nusing real\
    \ = double;\r\n\r\nstruct C {\r\n  real x, y;\r\n\r\n  C() : x(0), y(0) {}\r\n\
    \r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline C operator+(const C& c) const\
    \ { return C(x + c.x, y + c.y); }\r\n  inline C operator-(const C& c) const {\
    \ return C(x - c.x, y - c.y); }\r\n  inline C operator*(const C& c) const {\r\n\
    \    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\n\r\n  inline C\
    \ conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI = acosl(-1);\r\n\
    int base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int> rev = {0, 1};\r\
    \n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\n  rev.resize(1\
    \ << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0; i < (1 << nbase);\
    \ i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\r\n  }\r\
    \n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1 << (base + 1));\r\
    \n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\n      rts[i <<\
    \ 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1 << base));\r\n\
    \      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n    }\r\n    ++base;\r\
    \n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n & (n - 1)) ==\
    \ 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\n  int shift\
    \ = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i < (rev[i] >>\
    \ shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int k = 1; k <\
    \ n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n      for (int\
    \ j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\n       \
    \ a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n      }\r\
    \n    }\r\n  }\r\n}\r\n} // namespace CFFT\n#line 9 \"poly/convolution.hpp\"\n\
    \r\ntemplate <class mint>\r\nvector<mint> convolution_ntt(vector<mint> a, vector<mint>\
    \ b) {\r\n  if (a.empty() || b.empty()) return {};\r\n  int n = int(a.size()),\
    \ m = int(b.size());\r\n  int sz = 1;\r\n  while (sz < n + m - 1) sz *= 2;\r\n\
    \r\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\u5272\
    \u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\u306E\
    \u3067\u3002\r\n  if ((n + m - 3) <= sz / 2) {\r\n    auto a_last = a.back(),\
    \ b_last = b.back();\r\n    a.pop_back(), b.pop_back();\r\n    auto c = convolution(a,\
    \ b);\r\n    c.resize(n + m - 1);\r\n    c[n + m - 2] = a_last * b_last;\r\n \
    \   FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;\r\n    FOR(i, len(b)) c[i +\
    \ len(a)] += b[i] * a_last;\r\n    return c;\r\n  }\r\n\r\n  a.resize(sz), b.resize(sz);\r\
    \n  bool same = a == b;\r\n  ntt(a, 0);\r\n  if (same) {\r\n    b = a;\r\n  }\
    \ else {\r\n    ntt(b, 0);\r\n  }\r\n  FOR(i, sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\
    \n  a.resize(n + m - 1);\r\n  return a;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvector<mint> convolution_garner(const vector<mint>& a, const vector<mint>& b)\
    \ {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  static\
    \ constexpr int p0 = 167772161;\r\n  static constexpr int p1 = 469762049;\r\n\
    \  static constexpr int p2 = 754974721;\r\n  using mint0 = modint<p0>;\r\n  using\
    \ mint1 = modint<p1>;\r\n  using mint2 = modint<p2>;\r\n  vc<mint0> a0(n), b0(m);\r\
    \n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i]\
    \ = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i] = b[i].val,\
    \ b1[i] = b[i].val, b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\r\n  auto c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  vc<mint> c(len(c0));\r\n  FOR(i, n + m - 1) {\r\n    c[i] = CRT3<mint,\
    \ p0, p1, p2>(c0[i].val, c1[i].val, c2[i].val);\r\n  }\r\n  return c;\r\n}\r\n\
    \r\ntemplate <typename R>\r\nvc<double> convolution_fft(const vc<R>& a, const\
    \ vc<R>& b) {\r\n  using C = CFFT::C;\r\n  int need = (int)a.size() + (int)b.size()\
    \ - 1;\r\n  int nbase = 1;\r\n  while ((1 << nbase) < need) nbase++;\r\n  CFFT::ensure_base(nbase);\r\
    \n  int sz = 1 << nbase;\r\n  vector<C> fa(sz);\r\n  for (int i = 0; i < sz; i++)\
    \ {\r\n    double x = (i < (int)a.size() ? a[i] : 0);\r\n    double y = (i < (int)b.size()\
    \ ? b[i] : 0);\r\n    fa[i] = C(x, y);\r\n  }\r\n  CFFT::fft(fa, sz);\r\n  C r(0,\
    \ -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\r\n  for (int i = 0; i <= (sz >> 1);\
    \ i++) {\r\n    int j = (sz - i) & (sz - 1);\r\n    C z = (fa[j] * fa[j] - (fa[i]\
    \ * fa[i]).conj()) * r;\r\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\r\n    fa[i] = z;\r\n  }\r\n  for (int i = 0; i < (sz >> 1); i++) {\r\n\
    \    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\r\n    C A1 = (fa[i] - fa[i + (sz\
    \ >> 1)]) * t * CFFT::rts[(sz >> 1) + i];\r\n    fa[i] = A0 + A1 * s;\r\n  }\r\
    \n  CFFT::fft(fa, sz >> 1);\r\n  vector<double> ret(need);\r\n  for (int i = 0;\
    \ i < need; i++) {\r\n    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\r\n\
    \  }\r\n  return ret;\r\n}\r\n\r\nvector<ll> convolution(const vector<ll>& a,\
    \ const vector<ll>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (min(n, m) <= 2500) return convolution_naive(a, b);\r\n  ll abs_sum_a\
    \ = 0, abs_sum_b = 0;\r\n  ll LIM = 1e15;\r\n  FOR(i, n) abs_sum_a = min(LIM,\
    \ abs_sum_a + abs(a[i]));\r\n  FOR(i, m) abs_sum_b = min(LIM, abs_sum_b + abs(b[i]));\r\
    \n  if (i128(abs_sum_a) * abs_sum_b < 1e15) {\r\n    vc<double> c = convolution_fft<ll>(a,\
    \ b);\r\n    vc<ll> res(len(c));\r\n    FOR(i, len(c)) res[i] = ll(floor(c[i]\
    \ + .5));\r\n    return res;\r\n  }\r\n\r\n  static constexpr unsigned long long\
    \ MOD1 = 754974721; // 2^24\r\n  static constexpr unsigned long long MOD2 = 167772161;\
    \ // 2^25\r\n  static constexpr unsigned long long MOD3 = 469762049; // 2^26\r\
    \n  static constexpr unsigned long long M2M3 = MOD2 * MOD3;\r\n  static constexpr\
    \ unsigned long long M1M3 = MOD1 * MOD3;\r\n  static constexpr unsigned long long\
    \ M1M2 = MOD1 * MOD2;\r\n  static constexpr unsigned long long M1M2M3 = MOD1 *\
    \ MOD2 * MOD3;\r\n\r\n  static const unsigned long long i1 = mod_inv(MOD2 * MOD3,\
    \ MOD1);\r\n  static const unsigned long long i2 = mod_inv(MOD1 * MOD3, MOD2);\r\
    \n  static const unsigned long long i3 = mod_inv(MOD1 * MOD2, MOD3);\r\n\r\n \
    \ using mint1 = modint<MOD1>;\r\n  using mint2 = modint<MOD2>;\r\n  using mint3\
    \ = modint<MOD3>;\r\n\r\n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\
    \n  vc<mint3> a3(n), b3(m);\r\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i], a3[i] =\
    \ a[i];\r\n  FOR(i, m) b1[i] = b[i], b2[i] = b[i], b3[i] = b[i];\r\n\r\n  auto\
    \ c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  auto c3 = convolution_ntt<mint3>(a3, b3);\r\n\r\n  vc<ll> c(n + m\
    \ - 1);\r\n  FOR(i, n + m - 1) {\r\n    u64 x = 0;\r\n    x += (c1[i].val * i1)\
    \ % MOD1 * M2M3;\r\n    x += (c2[i].val * i2) % MOD2 * M1M3;\r\n    x += (c3[i].val\
    \ * i3) % MOD3 * M1M2;\r\n    ll diff = c1[i].val - ((long long)(x) % (long long)(MOD1));\r\
    \n    if (diff < 0) diff += MOD1;\r\n    static constexpr unsigned long long offset[5]\r\
    \n        = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\r\n    x -= offset[diff %\
    \ 5];\r\n    c[i] = x;\r\n  }\r\n  return c;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvc<mint> convolution(const vc<mint>& a, const vc<mint>& b) {\r\n  int n = len(a),\
    \ m = len(b);\r\n  if (!n || !m) return {};\r\n  if (mint::can_ntt()) {\r\n  \
    \  if (min(n, m) <= 50) return convolution_karatsuba<mint>(a, b);\r\n    return\
    \ convolution_ntt(a, b);\r\n  }\r\n  if (min(n, m) <= 200) return convolution_karatsuba<mint>(a,\
    \ b);\r\n  return convolution_garner(a, b);\r\n}\r\n#line 4 \"poly/convolution_all.hpp\"\
    \n\r\ntemplate <typename T>\r\nvc<T> convolution_all(vc<vc<T>>& polys) {\r\n \
    \ if (len(polys) == 0) return {T(1)};\r\n  while (1) {\r\n    int n = len(polys);\r\
    \n    if (n == 1) break;\r\n    int m = ceil(n, 2);\r\n    FOR(i, m) {\r\n   \
    \   if (2 * i + 1 == n) {\r\n        polys[i] = polys[2 * i];\r\n      } else\
    \ {\r\n        polys[i] = convolution(polys[2 * i], polys[2 * i + 1]);\r\n   \
    \   }\r\n    }\r\n    polys.resize(m);\r\n  }\r\n  return polys[0];\r\n}\r\n#line\
    \ 4 \"graph/tree_walk_generating_function.hpp\"\n\n// \u30EB\u30FC\u30D7\u306A\
    \u3057\uFF1A1700ms(N=10^5)\n// \u30EB\u30FC\u30D7\u3042\u308A\uFF1A3900ms(N=10^5)\n\
    template <bool ALLOW_LOOP, typename mint, typename F>\npair<vc<mint>, vc<mint>>\
    \ tree_walk_generating_function(Graph<int, 0>& G, int s,\n                   \
    \                                    int t, F weight) {\n  int N = G.N;\n  //\
    \ \u5206\u6BCD\n  auto f = characteristic_poly_of_tree_adjacency_matrix<ALLOW_LOOP,\
    \ mint>(\n      G, weight);\n  // \u5206\u5B50\n  // (s,t) \u30D1\u30B9\u306B\u6CBF\
    \u3063\u3066\u6210\u5206\u3092\u304B\u3051\u305F\u3082\u306E\u306E\u7B26\u53F7\
    \u8ABF\u6574 + \u4ED6\u306E\u6210\u5206\n  using poly = vc<mint>;\n  vc<poly>\
    \ polys;\n  pair<int, mint> path_poly = {0, mint(1)};\n  vc<bool> on_path(N);\n\
    \  auto [dist, par] = bfs01<int>(G, s);\n  on_path[t] = 1;\n  while (t != s) {\n\
    \    mint w = weight(par[t], t);\n    t = par[t], on_path[t] = 1;\n    path_poly.fi\
    \ += 1, path_poly.se *= w; // +wx\n  }\n  UnionFind uf(N);\n  for (auto& e: G.edges)\
    \ {\n    if (on_path[e.frm] || on_path[e.to]) continue;\n    uf.merge(e.frm, e.to);\n\
    \  }\n  vvc<int> comp(N);\n  FOR(v, N) comp[uf[v]].eb(v);\n  FOR(r, N) {\n   \
    \ if (on_path[r] || uf[r] != r) continue;\n    vc<int>& V = comp[r];\n    Graph<int,\
    \ 0> H = G.rearrange(V);\n    poly f = characteristic_poly_of_tree_adjacency_matrix<ALLOW_LOOP,\
    \ mint>(\n        H, [&](int i, int j) -> mint { return weight(V[i], V[j]); });\n\
    \    polys.eb(f);\n  }\n  poly B = convolution_all<mint>(polys);\n  int m = path_poly.fi;\n\
    \  poly g(len(B) + m);\n  FOR(i, len(B)) g[m + i] = path_poly.se * B[i];\n  return\
    \ {g, f};\n}\n#line 2 \"poly/fps_div.hpp\"\n\n#line 2 \"poly/count_terms.hpp\"\
    \ntemplate<typename mint>\r\nint count_terms(const vc<mint>& f){\r\n  int t =\
    \ 0;\r\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\n  return t;\r\n}\n#line 4\
    \ \"poly/fps_inv.hpp\"\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_sparse(const\
    \ vc<mint>& f) {\r\n  int N = len(f);\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i,\
    \ 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\r\n  vc<mint> g(N);\r\n  mint g0\
    \ = mint(1) / f[0];\r\n  g[0] = g0;\r\n  FOR(n, 1, N) {\r\n    mint rhs = 0;\r\
    \n    for (auto&& [k, fk]: dat) {\r\n      if (k > n) break;\r\n      rhs -= fk\
    \ * g[n - k];\r\n    }\r\n    g[n] = rhs * g0;\r\n  }\r\n  return g;\r\n}\r\n\r\
    \ntemplate <typename mint>\r\nvc<mint> fps_inv_dense_ntt(const vc<mint>& F) {\r\
    \n  vc<mint> G = {mint(1) / F[0]};\r\n  ll N = len(F), n = 1;\r\n  G.reserve(N);\r\
    \n  while (n < N) {\r\n    vc<mint> f(2 * n), g(2 * n);\r\n    FOR(i, min(N, 2\
    \ * n)) f[i] = F[i];\r\n    FOR(i, n) g[i] = G[i];\r\n    ntt(f, false), ntt(g,\
    \ false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\n    FOR(i,\
    \ n) f[i] = 0;\r\n    ntt(f, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n  \
    \  ntt(f, true);\r\n    FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\r\n    n *= 2;\r\
    \n  }\r\n  return G;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_dense(const\
    \ vc<mint>& F) {\r\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\r\n  const\
    \ int N = len(F);\r\n  vc<mint> R = {mint(1) / F[0]};\r\n  vc<mint> p;\r\n  int\
    \ m = 1;\r\n  while (m < N) {\r\n    p = convolution(R, R);\r\n    p.resize(m\
    \ + m);\r\n    vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\r\n    p =\
    \ convolution(p, f);\r\n    R.resize(m + m);\r\n    FOR(i, m + m) R[i] = R[i]\
    \ + R[i] - p[i];\r\n    m += m;\r\n  }\r\n  R.resize(N);\r\n  return R;\r\n}\r\
    \n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv(const vc<mint>& f) {\r\n  assert(f[0]\
    \ != mint(0));\r\n  int n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 160\
    \ : 820);\r\n  return (n <= t ? fps_inv_sparse<mint>(f) : fps_inv_dense<mint>(f));\r\
    \n}\r\n#line 5 \"poly/fps_div.hpp\"\n\n// f/g. f \u306E\u9577\u3055\u3067\u51FA\
    \u529B\u3055\u308C\u308B.\ntemplate <typename mint, bool SPARSE = false>\nvc<mint>\
    \ fps_div(vc<mint> f, vc<mint> g) {\n  if (SPARSE || count_terms(g) < 200) return\
    \ fps_div_sparse(f, g);\n  int n = len(f);\n  g.resize(n);\n  g = fps_inv<mint>(g);\n\
    \  f = convolution(f, g);\n  f.resize(n);\n  return f;\n}\n\n// f/g \u305F\u3060\
    \u3057 g \u306F sparse\ntemplate <typename mint>\nvc<mint> fps_div_sparse(vc<mint>\
    \ f, vc<mint>& g) {\n  if (g[0] != mint(1)) {\n    mint cf = g[0].inverse();\n\
    \    for (auto&& x: f) x *= cf;\n    for (auto&& x: g) x *= cf;\n  }\n\n  vc<pair<int,\
    \ mint>> dat;\n  FOR(i, 1, len(g)) if (g[i] != mint(0)) dat.eb(i, -g[i]);\n  FOR(i,\
    \ len(f)) {\n    for (auto&& [j, x]: dat) {\n      if (i >= j) f[i] += x * f[i\
    \ - j];\n    }\n  }\n  return f;\n}\n#line 7 \"test/mytest/tree_walk_gf.test.cpp\"\
    \n\nusing mint = modint998;\n\ntemplate <bool ALLOW_LOOP>\nvoid test() {\n  FOR(N,\
    \ 1, 30) {\n    FOR(50) {\n      Graph<int, 0> G(N);\n      vv(mint, mat, N, N);\n\
    \      for (auto& [a, b]: random_tree(N)) {\n        G.add(a, b);\n        mat[a][b]\
    \ = RNG(0, mint::get_mod());\n        mat[b][a] = RNG(0, mint::get_mod());\n \
    \     }\n      G.build();\n      if (ALLOW_LOOP) { FOR(v, N) mat[v][v] = RNG(mint::get_mod());\
    \ }\n      int s = RNG(0, N), t = RNG(0, N);\n      int LIM = 200;\n      vc<mint>\
    \ ANS(LIM + 1);\n      vc<mint> dp(N);\n      dp[s] = 1;\n      FOR(k, LIM) {\n\
    \        ANS[k] = dp[t];\n        vc<mint> newdp(N);\n        FOR(a, N) FOR(b,\
    \ N) newdp[b] += dp[a] * mat[a][b];\n        swap(dp, newdp);\n        ANS[k +\
    \ 1] = dp[t];\n      }\n      auto [f, g] = tree_walk_generating_function<ALLOW_LOOP,\
    \ mint>(\n          G, s, t, [&](int i, int j) -> mint { return mat[i][j]; });\n\
    \      f.resize(LIM + 1);\n      g.resize(LIM + 1);\n      f = fps_div(f, g);\n\
    \      assert(f == ANS);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << '\\n';\n}\n\nsigned main() {\n  test<0>();\n\
    \  test<1>();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/random_graph.hpp\"\n#include \"graph/tree_walk_generating_function.hpp\"\
    \n#include \"poly/fps_div.hpp\"\n\nusing mint = modint998;\n\ntemplate <bool ALLOW_LOOP>\n\
    void test() {\n  FOR(N, 1, 30) {\n    FOR(50) {\n      Graph<int, 0> G(N);\n \
    \     vv(mint, mat, N, N);\n      for (auto& [a, b]: random_tree(N)) {\n     \
    \   G.add(a, b);\n        mat[a][b] = RNG(0, mint::get_mod());\n        mat[b][a]\
    \ = RNG(0, mint::get_mod());\n      }\n      G.build();\n      if (ALLOW_LOOP)\
    \ { FOR(v, N) mat[v][v] = RNG(mint::get_mod()); }\n      int s = RNG(0, N), t\
    \ = RNG(0, N);\n      int LIM = 200;\n      vc<mint> ANS(LIM + 1);\n      vc<mint>\
    \ dp(N);\n      dp[s] = 1;\n      FOR(k, LIM) {\n        ANS[k] = dp[t];\n   \
    \     vc<mint> newdp(N);\n        FOR(a, N) FOR(b, N) newdp[b] += dp[a] * mat[a][b];\n\
    \        swap(dp, newdp);\n        ANS[k + 1] = dp[t];\n      }\n      auto [f,\
    \ g] = tree_walk_generating_function<ALLOW_LOOP, mint>(\n          G, s, t, [&](int\
    \ i, int j) -> mint { return mat[i][j]; });\n      f.resize(LIM + 1);\n      g.resize(LIM\
    \ + 1);\n      f = fps_div(f, g);\n      assert(f == ANS);\n    }\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << '\\n';\n}\n\n\
    signed main() {\n  test<0>();\n  test<1>();\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/random_graph.hpp
  - graph/base.hpp
  - random/base.hpp
  - random/shuffle.hpp
  - ds/unionfind/unionfind.hpp
  - graph/tree_walk_generating_function.hpp
  - graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
  - graph/ds/static_toptree.hpp
  - graph/tree.hpp
  - graph/shortest_path/bfs01.hpp
  - poly/convolution_all.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  - poly/fps_div.hpp
  - poly/count_terms.hpp
  - poly/fps_inv.hpp
  isVerificationFile: true
  path: test/mytest/tree_walk_gf.test.cpp
  requiredBy: []
  timestamp: '2024-02-02 01:26:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/tree_walk_gf.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/tree_walk_gf.test.cpp
- /verify/test/mytest/tree_walk_gf.test.cpp.html
title: test/mytest/tree_walk_gf.test.cpp
---