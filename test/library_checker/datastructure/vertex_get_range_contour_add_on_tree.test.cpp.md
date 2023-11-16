---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/centroid_decomposition.hpp
    title: graph/centroid_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/contour_query_range.hpp
    title: graph/ds/contour_query_range.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/bfs01.hpp
    title: graph/shortest_path/bfs01.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree
    links:
    - https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree
  bundledCode: "#line 1 \"test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree\"\
    \n\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
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
    \  return B;\n}\n#endif\n#line 1 \"other/io.hpp\"\n#define FASTIO\r\n#include\
    \ <unistd.h>\r\n\r\n// https://judge.yosupo.jp/submission/21623\r\nnamespace fastio\
    \ {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\nchar obuf[SZ];\r\
    \nchar out[100];\r\n// pointer of ibuf, obuf\r\nuint32_t pil = 0, pir = 0, por\
    \ = 0;\r\n\r\nstruct Pre {\r\n  char num[10000][4];\r\n  constexpr Pre() : num()\
    \ {\r\n    for (int i = 0; i < 10000; i++) {\r\n      int n = i;\r\n      for\
    \ (int j = 3; j >= 0; j--) {\r\n        num[i][j] = n % 10 | '0';\r\n        n\
    \ /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr pre;\r\n\r\ninline void load()\
    \ {\r\n  memcpy(ibuf, ibuf + pil, pir - pil);\r\n  pir = pir - pil + fread(ibuf\
    \ + pir - pil, 1, SZ - pir + pil, stdin);\r\n  pil = 0;\r\n  if (pir < SZ) ibuf[pir++]\
    \ = '\\n';\r\n}\r\n\r\ninline void flush() {\r\n  fwrite(obuf, 1, por, stdout);\r\
    \n  por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n  do {\r\n    if (pil + 1 > pir)\
    \ load();\r\n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\n}\r\n\r\nvoid\
    \ rd(string &x) {\r\n  x.clear();\r\n  char c;\r\n  do {\r\n    if (pil + 1 >\
    \ pir) load();\r\n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\n  do {\r\n\
    \    x += c;\r\n    if (pil == pir) load();\r\n    c = ibuf[pil++];\r\n  } while\
    \ (!isspace(c));\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T &x) {\r\n\
    \  string s;\r\n  rd(s);\r\n  x = stod(s);\r\n}\r\n\r\ntemplate <typename T>\r\
    \nvoid rd_integer(T &x) {\r\n  if (pil + 100 > pir) load();\r\n  char c;\r\n \
    \ do\r\n    c = ibuf[pil++];\r\n  while (c < '-');\r\n  bool minus = 0;\r\n  if\
    \ constexpr (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if (c == '-')\
    \ { minus = 1, c = ibuf[pil++]; }\r\n  }\r\n  x = 0;\r\n  while ('0' <= c) { x\
    \ = x * 10 + (c & 15), c = ibuf[pil++]; }\r\n  if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n    if (minus) x = -x;\r\n  }\r\n}\r\n\r\nvoid rd(int\
    \ &x) { rd_integer(x); }\r\nvoid rd(ll &x) { rd_integer(x); }\r\nvoid rd(i128\
    \ &x) { rd_integer(x); }\r\nvoid rd(u32 &x) { rd_integer(x); }\r\nvoid rd(u64\
    \ &x) { rd_integer(x); }\r\nvoid rd(u128 &x) { rd_integer(x); }\r\nvoid rd(double\
    \ &x) { rd_real(x); }\r\nvoid rd(long double &x) { rd_real(x); }\r\nvoid rd(f128\
    \ &x) { rd_real(x); }\r\n\r\ntemplate <class T, class U>\r\nvoid rd(pair<T, U>\
    \ &p) {\r\n  return rd(p.first), rd(p.second);\r\n}\r\ntemplate <size_t N = 0,\
    \ typename T>\r\nvoid rd_tuple(T &t) {\r\n  if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n    auto &x = std::get<N>(t);\r\n    rd(x);\r\n    rd_tuple<N + 1>(t);\r\
    \n  }\r\n}\r\ntemplate <class... T>\r\nvoid rd(tuple<T...> &tpl) {\r\n  rd_tuple(tpl);\r\
    \n}\r\n\r\ntemplate <size_t N = 0, typename T>\r\nvoid rd(array<T, N> &x) {\r\n\
    \  for (auto &d: x) rd(d);\r\n}\r\ntemplate <class T>\r\nvoid rd(vc<T> &x) {\r\
    \n  for (auto &d: x) rd(d);\r\n}\r\n\r\nvoid read() {}\r\ntemplate <class H, class...\
    \ T>\r\nvoid read(H &h, T &... t) {\r\n  rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const\
    \ char c) {\r\n  if (por == SZ) flush();\r\n  obuf[por++] = c;\r\n}\r\nvoid wt(const\
    \ string s) {\r\n  for (char c: s) wt(c);\r\n}\r\nvoid wt(const char *s) {\r\n\
    \  size_t len = strlen(s);\r\n  for (size_t i = 0; i < len; i++) wt(s[i]);\r\n\
    }\r\n\r\ntemplate <typename T>\r\nvoid wt_integer(T x) {\r\n  if (por > SZ - 100)\
    \ flush();\r\n  if (x < 0) { obuf[por++] = '-', x = -x; }\r\n  int outi;\r\n \
    \ for (outi = 96; x >= 10000; outi -= 4) {\r\n    memcpy(out + outi, pre.num[x\
    \ % 10000], 4);\r\n    x /= 10000;\r\n  }\r\n  if (x >= 1000) {\r\n    memcpy(obuf\
    \ + por, pre.num[x], 4);\r\n    por += 4;\r\n  } else if (x >= 100) {\r\n    memcpy(obuf\
    \ + por, pre.num[x] + 1, 3);\r\n    por += 3;\r\n  } else if (x >= 10) {\r\n \
    \   int q = (x * 103) >> 10;\r\n    obuf[por] = q | '0';\r\n    obuf[por + 1]\
    \ = (x - q * 10) | '0';\r\n    por += 2;\r\n  } else\r\n    obuf[por++] = x |\
    \ '0';\r\n  memcpy(obuf + por, out + outi + 4, 96 - outi);\r\n  por += 96 - outi;\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvoid wt_real(T x) {\r\n  ostringstream oss;\r\
    \n  oss << fixed << setprecision(15) << double(x);\r\n  string s = oss.str();\r\
    \n  wt(s);\r\n}\r\n\r\nvoid wt(int x) { wt_integer(x); }\r\nvoid wt(ll x) { wt_integer(x);\
    \ }\r\nvoid wt(i128 x) { wt_integer(x); }\r\nvoid wt(u32 x) { wt_integer(x); }\r\
    \nvoid wt(u64 x) { wt_integer(x); }\r\nvoid wt(u128 x) { wt_integer(x); }\r\n\
    void wt(double x) { wt_real(x); }\r\nvoid wt(long double x) { wt_real(x); }\r\n\
    void wt(f128 x) { wt_real(x); }\r\n\r\ntemplate <class T, class U>\r\nvoid wt(const\
    \ pair<T, U> val) {\r\n  wt(val.first);\r\n  wt(' ');\r\n  wt(val.second);\r\n\
    }\r\ntemplate <size_t N = 0, typename T>\r\nvoid wt_tuple(const T t) {\r\n  if\
    \ constexpr (N < std::tuple_size<T>::value) {\r\n    if constexpr (N > 0) { wt('\
    \ '); }\r\n    const auto x = std::get<N>(t);\r\n    wt(x);\r\n    wt_tuple<N\
    \ + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\nvoid wt(tuple<T...> tpl) {\r\
    \n  wt_tuple(tpl);\r\n}\r\ntemplate <class T, size_t S>\r\nvoid wt(const array<T,\
    \ S> val) {\r\n  auto n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n\
    \    if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\ntemplate <class T>\r\n\
    void wt(const vector<T> val) {\r\n  auto n = val.size();\r\n  for (size_t i =\
    \ 0; i < n; i++) {\r\n    if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\n\r\
    \nvoid print() { wt('\\n'); }\r\ntemplate <class Head, class... Tail>\r\nvoid\
    \ print(Head &&head, Tail &&... tail) {\r\n  wt(head);\r\n  if (sizeof...(Tail))\
    \ wt(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\n// gcc expansion. called\
    \ automaticall after main.\r\nvoid __attribute__((destructor)) _d() { flush();\
    \ }\r\n} // namespace fastio\r\nusing fastio::read;\r\nusing fastio::print;\r\n\
    using fastio::flush;\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n\
    \  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define U32(...)   \\\r\n  u32 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ U64(...)   \\\r\n  u64 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)\
    \      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)\
    \   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)  \
    \    \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n#line 6 \"test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp\"\
    \n\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct Monoid_Add\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return\
    \ X(n) * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\n\n\
    template <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ E = typename G::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree()\
    \ {}\n  FenwickTree(int n) { build(n); }\n  template <typename F>\n  FenwickTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m, G::unit());\n    total\
    \ = G::unit();\n  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int\
    \ i) -> E { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n    total = G::unit();\n\
    \    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int\
    \ j = i + (i & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j -\
    \ 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n  E prod_all() { return total;\
    \ }\n  E sum_all() { return total; }\n  E sum(int k) { return prefix_sum(k); }\n\
    \  E prod(int k) { return prefix_prod(k); }\n  E prefix_sum(int k) { return prefix_prod(k);\
    \ }\n  E prefix_prod(int k) {\n    chmin(k, n);\n    E ret = G::unit();\n    for\
    \ (; k > 0; k -= k & -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n  }\n\
    \  E sum(int L, int R) { return prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L,\
    \ 0), chmin(R, n);\n    if (L == 0) return prefix_prod(R);\n    assert(0 <= L\
    \ && L <= R && R <= n);\n    E pos = G::unit(), neg = G::unit();\n    while (L\
    \ < R) { pos = G::op(pos, dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg\
    \ = G::op(neg, dat[L - 1]), L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n\n  template <class\
    \ F>\n  int max_right(const F check) {\n    assert(check(G::unit()));\n    int\
    \ i = 0;\n    E s = G::unit();\n    int k = 1;\n    while (2 * k <= n) k *= 2;\n\
    \    while (k) {\n      if (i + k - 1 < len(dat)) {\n        E t = G::op(s, dat[i\
    \ + k - 1]);\n        if (check(t)) { i += k, s = t; }\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  // check(i, x)\n  template <class F>\n  int max_right_with_index(const\
    \ F check) {\n    assert(check(0, G::unit()));\n    int i = 0;\n    E s = G::unit();\n\
    \    int k = 1;\n    while (2 * k <= n) k *= 2;\n    while (k) {\n      if (i\
    \ + k - 1 < len(dat)) {\n        E t = G::op(s, dat[i + k - 1]);\n        if (check(i\
    \ + k, t)) { i += k, s = t; }\n      }\n      k >>= 1;\n    }\n    return i;\n\
    \  }\n\n  int kth(E k) {\n    return max_right([&k](E x) -> bool { return x <=\
    \ k; });\n  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int,\
    \ bool directed = false>\nstruct Graph {\n  static constexpr bool is_directed\
    \ = directed;\n  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n\
    \  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n\
    \  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges\
    \ {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l),\
    \ r(r) {}\n\n    const edge_type* begin() const {\n      if (l == r) { return\
    \ 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type* end() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n\
    \  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int\
    \ N) : N(N), M(0), prepared(0) {}\n\n  void build(int n) {\n    N = n, M = 0;\n\
    \    prepared = 0;\n    edges.clear();\n    indptr.clear();\n    csr_edges.clear();\n\
    \    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n  }\n\n \
    \ void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef\
    \ FASTIO\n  // wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N\
    \ - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n\
    \    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v + 1]\
    \ += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
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
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n\
    \  vc<bool> used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\
    \u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308B\n  // {G, es}\n  Graph<T, directed> rearrange(vc<int> V, bool\
    \ keep_eid = 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e)\
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
    \      res.eb(comp_range[p] + dep[idx]);\n    }\n    return res;\n  }\n};\n#line\
    \ 9 \"test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp\"\
    \n\n#line 11 \"test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp\"\
    \n\nvoid solve() {\n  INT(N, Q);\n  VEC(ll, A, N);\n  Graph<int, 0> G(N);\n  G.read_tree(0,\
    \ 0);\n  Contour_Query_Range<decltype(G), false> CQ(G);\n  FenwickTree<Monoid_Add<ll>>\
    \ bit(len(CQ) + 1);\n\n  auto apply = [&](int v, int l, int r, int x) -> void\
    \ {\n    for (auto& [a, b]: CQ.get_contour_range(v, l, r)) {\n      bit.add(a,\
    \ x), bit.add(b, -x);\n    }\n    if (l <= 0 && 0 < r) A[v] += x;\n  };\n\n  auto\
    \ get = [&](int v) -> ll {\n    ll ans = A[v];\n    for (auto& i: CQ.get_indices(v))\
    \ { ans += bit.sum(i + 1); }\n    return ans;\n  };\n\n  FOR(Q) {\n    INT(t);\n\
    \    if (t == 0) {\n      INT(v, l, r, x);\n      apply(v, l, r, x);\n    }\n\
    \    if (t == 1) {\n      INT(v);\n      print(get(v));\n    }\n  }\n}\n\nsigned\
    \ main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/fenwicktree/fenwicktree.hpp\"\
    \n#include \"graph/ds/contour_query_range.hpp\"\n\n#include \"alg/monoid/add.hpp\"\
    \n\nvoid solve() {\n  INT(N, Q);\n  VEC(ll, A, N);\n  Graph<int, 0> G(N);\n  G.read_tree(0,\
    \ 0);\n  Contour_Query_Range<decltype(G), false> CQ(G);\n  FenwickTree<Monoid_Add<ll>>\
    \ bit(len(CQ) + 1);\n\n  auto apply = [&](int v, int l, int r, int x) -> void\
    \ {\n    for (auto& [a, b]: CQ.get_contour_range(v, l, r)) {\n      bit.add(a,\
    \ x), bit.add(b, -x);\n    }\n    if (l <= 0 && 0 < r) A[v] += x;\n  };\n\n  auto\
    \ get = [&](int v) -> ll {\n    ll ans = A[v];\n    for (auto& i: CQ.get_indices(v))\
    \ { ans += bit.sum(i + 1); }\n    return ans;\n  };\n\n  FOR(Q) {\n    INT(t);\n\
    \    if (t == 0) {\n      INT(v, l, r, x);\n      apply(v, l, r, x);\n    }\n\
    \    if (t == 1) {\n      INT(v);\n      print(get(v));\n    }\n  }\n}\n\nsigned\
    \ main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  - graph/ds/contour_query_range.hpp
  - graph/centroid_decomposition.hpp
  - graph/base.hpp
  - graph/shortest_path/bfs01.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp
  requiredBy: []
  timestamp: '2023-11-15 20:12:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp
- /verify/test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp.html
title: test/library_checker/datastructure/vertex_get_range_contour_add_on_tree.test.cpp
---