---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/add_remove_query.hpp
    title: ds/offline_query/add_remove_query.hpp
  - icon: ':heavy_check_mark:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/rollback_unionfind.hpp
    title: ds/unionfind/rollback_unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/add_remove_query.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    \ yes(!t); }\r\n#line 1 \"ds/offline_query/add_remove_query.hpp\"\n/*\n\u30FB\u6642\
    \u523B t \u306B x \u3092\u8FFD\u52A0\u3059\u308B\n\u30FB\u6642\u523B t \u306B\
    \ x \u3092\u524A\u9664\u3059\u308B\n\u304C\u3042\u308B\u3068\u304D\u306B,\n\u30FB\
    \u6642\u523B [l, r) \u306B x \u3092\u8FFD\u52A0\u3059\u308B\n\u306B\u5909\u63DB\
    \u3059\u308B. \u540C\u3058\u30AD\u30FC\u304C\u8907\u6570\u56DE\u6765\u308B\u3068\
    \u56F0\u308B\u306E\u3067\u9069\u5F53\u306A\u30E9\u30D9\u30EB\u3092\u3064\u3051\
    \u3066\u304A\u3053\u3046.\n*/\ntemplate <typename X, bool monotone>\nstruct Add_Remove_Query\
    \ {\n  map<X, int> MP;\n  vc<tuple<int, int, X>> dat;\n  map<X, vc<int>> ADD;\n\
    \  map<X, vc<int>> RM;\n\n  void add(int time, X x) {\n    if (monotone) return\
    \ add_monotone(time, x);\n    ADD[x].eb(time);\n  }\n  void remove(int time, X\
    \ x) {\n    if (monotone) return remove_monotone(time, x);\n    RM[x].eb(time);\n\
    \  }\n\n  // \u3059\u3079\u3066\u306E\u30AF\u30A8\u30EA\u304C\u7D42\u308F\u3063\
    \u305F\u73FE\u5728\u6642\u523B\u3092\u6E21\u3059\n  vc<tuple<int, int, X>> calc(int\
    \ time) {\n    if (monotone) return calc_monotone(time);\n    vc<tuple<int, int,\
    \ X>> dat;\n    for (auto&& [x, A]: ADD) {\n      vc<int> B;\n      if (RM.count(x))\
    \ {\n        B = RM[x];\n        RM.erase(x);\n      }\n      if (len(B) < len(A))\
    \ B.eb(time);\n      assert(len(A) == len(B));\n\n      sort(all(A));\n      sort(all(B));\n\
    \      FOR(i, len(A)) {\n        assert(A[i] <= B[i]);\n        if (A[i] < B[i])\
    \ dat.eb(A[i], B[i], x);\n      }\n    }\n    assert(len(RM) == 0);\n    return\
    \ dat;\n  }\n\nprivate:\n  void add_monotone(int time, X x) {\n    assert(!MP.count(x));\n\
    \    MP[x] = time;\n  }\n  void remove_monotone(int time, X x) {\n    auto it\
    \ = MP.find(x);\n    assert(it != MP.end());\n    int t = (*it).se;\n    MP.erase(it);\n\
    \    if (t == time) return;\n    dat.eb(t, time, x);\n  }\n  vc<tuple<int, int,\
    \ X>> calc_monotone(int time) {\n    for (auto&& [x, t]: MP) {\n      if (t ==\
    \ time) continue;\n      dat.eb(t, time, x);\n    }\n    return dat;\n  }\n};\n\
    #line 2 \"ds/rollback_array.hpp\"\n\r\ntemplate <typename T>\r\nstruct Rollback_Array\
    \ {\r\n  int N;\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\n\r\n  Rollback_Array()\
    \ {}\r\n  Rollback_Array(vc<T> x) : N(len(x)), dat(x) {}\r\n  Rollback_Array(int\
    \ N) : N(N), dat(N) {}\r\n  template <typename F>\r\n  Rollback_Array(int N, F\
    \ f) : N(N) {\r\n    dat.reserve(N);\r\n    FOR(i, N) dat.eb(f(i));\r\n  }\r\n\
    \r\n  int time() { return len(history); }\r\n  void rollback(int t) {\r\n    FOR_R(i,\
    \ t, time()) {\r\n      auto& [idx, v] = history[i];\r\n      dat[idx] = v;\r\n\
    \    }\r\n    history.resize(t);\r\n  }\r\n  T get(int idx) { return dat[idx];\
    \ }\r\n  void set(int idx, T x) {\r\n    history.eb(idx, dat[idx]);\r\n    dat[idx]\
    \ = x;\r\n  }\r\n\r\n  vc<T> get_all() {\r\n    vc<T> res(N);\r\n    FOR(i, N)\
    \ res[i] = get(i);\r\n    return res;\r\n  }\r\n};\r\n#line 2 \"ds/unionfind/rollback_unionfind.hpp\"\
    \n\r\nstruct Rollback_UnionFind {\r\n  Rollback_Array<int> dat; // parent or size\r\
    \n\r\n  Rollback_UnionFind(int n) : dat(vc<int>(n, -1)) {}\r\n\r\n  int operator[](int\
    \ v) {\r\n    while (dat.get(v) >= 0) v = dat.get(v);\r\n    return v;\r\n  }\r\
    \n\r\n  ll size(int v) { return -dat.get((*this)[v]); }\r\n  int time() { return\
    \ dat.time(); }\r\n  void rollback(int t) { dat.rollback(t); }\r\n  void reset()\
    \ { rollback(0); }\r\n\r\n  bool merge(int a, int b) {\r\n    a = (*this)[a],\
    \ b = (*this)[b];\r\n    if (a == b) return false;\r\n    if (dat.get(a) > dat.get(b))\
    \ swap(a, b);\r\n    dat.set(a, dat.get(a) + dat.get(b));\r\n    dat.set(b, a);\r\
    \n    return true;\r\n  }\r\n};\r\n#line 8 \"test/library_checker/datastructure/add_remove_query.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A0, N);\n  using P = pair<int, int>;\n\
    \n  vc<int> query;\n\n  Add_Remove_Query<P, true> X;\n  FOR(Q) {\n    LL(t);\n\
    \    if (t == 0) {\n      LL(a, b);\n      if (a > b) swap(a, b);\n      P e =\
    \ {a, b};\n      X.add(len(query), e);\n    }\n    if (t == 1) {\n      LL(a,\
    \ b);\n      if (a > b) swap(a, b);\n      P e = {a, b};\n      X.remove(len(query),\
    \ e);\n    }\n    if (t == 2) {\n      LL(v, x);\n      P p = {~v, x};\n     \
    \ X.add(len(query), p);\n    }\n    if (t == 3) {\n      LL(v);\n      query.eb(v);\n\
    \    }\n  }\n\n  auto upd = X.calc(len(query));\n  Q = len(query);\n  vi ANS(Q);\n\
    \  vc<int> I(len(upd));\n  iota(all(I), 0);\n\n  Rollback_Array<ll> A(A0);\n \
    \ Rollback_UnionFind uf(N);\n\n  auto dfs = [&](auto& dfs, vc<int>& I, int begin,\
    \ int end) -> void {\n    int a_time = A.time();\n    int uf_time = uf.time();\n\
    \n    vc<int> IL, IR;\n    int mid = (begin + end) / 2;\n    // \u533A\u9593\u3092\
    \u5B8C\u5168\u306B\u542B\u3080\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\
    \u3059\u308B\u3002\n    // \u90E8\u5206\u7684\u306B\u4EA4\u308F\u308B\u30AF\u30A8\
    \u30EA\u3092 J \u306B\u5165\u308C\u308B\n    for (auto&& i: I) {\n      auto [a,\
    \ b, X] = upd[i];\n      if (a <= begin && end <= b) {\n        // update\n  \
    \      auto [u, v] = X;\n        if (u < 0) {\n          int i = uf[~u];\n   \
    \       A.set(i, A.get(i) + v);\n        } else {\n          u = uf[u], v = uf[v];\n\
    \          if (u != v) {\n            uf.merge(u, v);\n            int r = uf[u];\n\
    \            A.set(r, A.get(u) + A.get(v));\n          }\n        }\n        continue;\n\
    \      }\n      if (a < mid) IL.eb(i);\n      if (mid < b) IR.eb(i);\n    }\n\
    \    if (begin + 1 == end) {\n      // \u6C42\u5024\u30AF\u30A8\u30EA\n      int\
    \ v = query[begin];\n      ANS[begin] = A.get(uf[v]);\n    } else {\n      dfs(dfs,\
    \ IL, begin, mid);\n      dfs(dfs, IR, mid, end);\n    }\n    A.rollback(a_time);\n\
    \    uf.rollback(uf_time);\n  };\n  dfs(dfs, I, 0, Q);\n\n  for (auto&& x: ANS)\
    \ print(x);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/offline_query/add_remove_query.hpp\"\
    \n#include \"ds/rollback_array.hpp\"\n#include \"ds/unionfind/rollback_unionfind.hpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A0, N);\n  using P = pair<int, int>;\n\
    \n  vc<int> query;\n\n  Add_Remove_Query<P, true> X;\n  FOR(Q) {\n    LL(t);\n\
    \    if (t == 0) {\n      LL(a, b);\n      if (a > b) swap(a, b);\n      P e =\
    \ {a, b};\n      X.add(len(query), e);\n    }\n    if (t == 1) {\n      LL(a,\
    \ b);\n      if (a > b) swap(a, b);\n      P e = {a, b};\n      X.remove(len(query),\
    \ e);\n    }\n    if (t == 2) {\n      LL(v, x);\n      P p = {~v, x};\n     \
    \ X.add(len(query), p);\n    }\n    if (t == 3) {\n      LL(v);\n      query.eb(v);\n\
    \    }\n  }\n\n  auto upd = X.calc(len(query));\n  Q = len(query);\n  vi ANS(Q);\n\
    \  vc<int> I(len(upd));\n  iota(all(I), 0);\n\n  Rollback_Array<ll> A(A0);\n \
    \ Rollback_UnionFind uf(N);\n\n  auto dfs = [&](auto& dfs, vc<int>& I, int begin,\
    \ int end) -> void {\n    int a_time = A.time();\n    int uf_time = uf.time();\n\
    \n    vc<int> IL, IR;\n    int mid = (begin + end) / 2;\n    // \u533A\u9593\u3092\
    \u5B8C\u5168\u306B\u542B\u3080\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\
    \u3059\u308B\u3002\n    // \u90E8\u5206\u7684\u306B\u4EA4\u308F\u308B\u30AF\u30A8\
    \u30EA\u3092 J \u306B\u5165\u308C\u308B\n    for (auto&& i: I) {\n      auto [a,\
    \ b, X] = upd[i];\n      if (a <= begin && end <= b) {\n        // update\n  \
    \      auto [u, v] = X;\n        if (u < 0) {\n          int i = uf[~u];\n   \
    \       A.set(i, A.get(i) + v);\n        } else {\n          u = uf[u], v = uf[v];\n\
    \          if (u != v) {\n            uf.merge(u, v);\n            int r = uf[u];\n\
    \            A.set(r, A.get(u) + A.get(v));\n          }\n        }\n        continue;\n\
    \      }\n      if (a < mid) IL.eb(i);\n      if (mid < b) IR.eb(i);\n    }\n\
    \    if (begin + 1 == end) {\n      // \u6C42\u5024\u30AF\u30A8\u30EA\n      int\
    \ v = query[begin];\n      ANS[begin] = A.get(uf[v]);\n    } else {\n      dfs(dfs,\
    \ IL, begin, mid);\n      dfs(dfs, IR, mid, end);\n    }\n    A.rollback(a_time);\n\
    \    uf.rollback(uf_time);\n  };\n  dfs(dfs, I, 0, Q);\n\n  for (auto&& x: ANS)\
    \ print(x);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/offline_query/add_remove_query.hpp
  - ds/rollback_array.hpp
  - ds/unionfind/rollback_unionfind.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/add_remove_query.test.cpp
  requiredBy: []
  timestamp: '2023-12-29 11:33:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/add_remove_query.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/add_remove_query.test.cpp
- /verify/test/library_checker/datastructure/add_remove_query.test.cpp.html
title: test/library_checker/datastructure/add_remove_query.test.cpp
---