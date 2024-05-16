---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = ll(infty<int>) * infty<int> * 2;\ntemplate <>\nconstexpr u32 infty<u32> =\
    \ infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\n\
    constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\ntemplate <>\nconstexpr\
    \ double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long double infty<long\
    \ double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    using fastio::flush;\r\n\r\n#define SHOW(x) print(#x, \"=\", (x)), flush()\r\n\
    \r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    #define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ U32(...)   \\\r\n  u32 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define U64(...)\
    \   \\\r\n  u64 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)   \
    \   \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)\
    \   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)  \
    \    \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n#line 5 \"test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp\"\
    \n\n#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  vc<pair<u32, u32>> dat;\n\
    \  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }\n\n  void set(int\
    \ i) { dat[i >> 5].fi |= u32(1) << (i & 31); }\n\n  void build() {\n    FOR(i,\
    \ len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n\n  // [0,\
    \ k) \u5185\u306E 1 \u306E\u500B\u6570\n  int rank(int k, bool f = 1) {\n    auto\
    \ [a, b] = dat[k >> 5];\n    int ret = b + popcnt(a & ((u32(1) << (k & 31)) -\
    \ 1));\n    return (f ? ret : k - ret);\n  }\n};\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
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
    \  }\n\n  vc<E> get_all() {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i,\
    \ i + 1);\n    return res;\n  }\n\n  void add(int k, E x) { multiply(k, x); }\n\
    \  void multiply(int k, E x) {\n    static_assert(G::commute);\n    total = G::op(total,\
    \ x);\n    for (++k; k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n\
    \  }\n\n  template <class F>\n  int max_right(const F check, int L = 0) {\n  \
    \  assert(check(G::unit()));\n    E s = G::unit();\n    int i = L;\n    // 2^k\
    \ \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n   \
    \     if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i - 1])), i -= 1; }\n    \
    \    if (i == 0) { return topbit(n) + 1; }\n        int k = lowbit(i) - 1;\n \
    \       if (i + (1 << k) > n) return k;\n        E t = G::op(s, dat[i + (1 <<\
    \ k) - 1]);\n        if (!check(t)) { return k; }\n        s = G::op(s, G::inverse(dat[i\
    \ - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n      --k;\n     \
    \ if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s, dat[i + (1 << k)\
    \ - 1]);\n        if (check(t)) { i += (1 << k), s = t; }\n      }\n    }\n  \
    \  return i;\n  }\n\n  // check(i, x)\n  template <class F>\n  int max_right_with_index(const\
    \ F check, int L = 0) {\n    assert(check(L, G::unit()));\n    E s = G::unit();\n\
    \    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]()\
    \ {\n      while (1) {\n        if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i\
    \ - 1])), i -= 1; }\n        if (i == 0) { return topbit(n) + 1; }\n        int\
    \ k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n        E t = G::op(s,\
    \ dat[i + (1 << k) - 1]);\n        if (!check(i + (1 << k), t)) { return k; }\n\
    \        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n      }\n    }();\n\
    \    while (k) {\n      --k;\n      if (i + (1 << k) - 1 < len(dat)) {\n     \
    \   E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (check(i + (1 << k), t))\
    \ { i += (1 << k), s = t; }\n      }\n    }\n    return i;\n  }\n\n  template\
    \ <class F>\n  int min_left(const F check, int R) {\n    assert(check(G::unit()));\n\
    \    E s = G::unit();\n    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\
    \u308D\u307E\u3067\u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s))\
    \ {\n      s = G::op(s, dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n\
    \    }\n    if (check(s)) {\n      assert(i == 0);\n      return 0;\n    }\n \
    \   // 2^k \u9032\u3080\u3068 ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\
    \u6301\u3057\u3066\u9032\u3080\n    while (k) {\n      --k;\n      E t = G::op(s,\
    \ G::inverse(dat[i + (1 << k) - 1]));\n      if (!check(t)) { i += (1 << k), s\
    \ = t; }\n    }\n    return i + 1;\n  }\n\n  int kth(E k, int L = 0) {\n    return\
    \ max_right([&k](E x) -> bool { return x <= k; }, L);\n  }\n};\n#line 3 \"ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp\"\
    \n\ntemplate <typename Monoid, typename XY, bool SMALL_X, bool SMALL_Y>\nstruct\
    \ Wavelet_Matrix_2D_Range_Dynamic_AbelGroup {\n  // \u70B9\u7FA4\u3092 Y \u6607\
    \u9806\u306B\u4E26\u3079\u308B.\n  // X \u3092\u6574\u6570\u306B\u306A\u304A\u3057\
    \u3066 binary trie \u307F\u305F\u3044\u306B\u632F\u308A\u5206\u3051\u308B\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n  static_assert(MX::commute);\n\
    \n  template <bool SMALL>\n  struct TO_IDX {\n    vc<XY> key;\n    XY mi, ma;\n\
    \    vc<int> dat;\n\n    void build(vc<XY>& X) {\n      if constexpr (SMALL) {\n\
    \        mi = (X.empty() ? 0 : MIN(X));\n        ma = (X.empty() ? 0 : MAX(X));\n\
    \        dat.assign(ma - mi + 2, 0);\n        for (auto& x: X) { dat[x - mi +\
    \ 1]++; }\n        FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n      } else {\n\
    \        key = X;\n        sort(all(key));\n      }\n    }\n    int operator()(XY\
    \ x) {\n      if constexpr (SMALL) {\n        return dat[clamp<XY>(x - mi, 0,\
    \ ma - mi + 1)];\n      } else {\n        return LB(key, x);\n      }\n    }\n\
    \  };\n\n  TO_IDX<SMALL_X> XtoI;\n  TO_IDX<SMALL_Y> YtoI;\n\n  int N, lg;\n  vector<int>\
    \ mid;\n  vector<Bit_Vector> bv;\n  vc<int> new_idx;\n  vc<int> A;\n  // \u5404\
    \u6BB5\u306B fenwick tree\n  vc<FenwickTree<Monoid>> dat;\n\n  template <typename\
    \ F>\n  Wavelet_Matrix_2D_Range_Dynamic_AbelGroup(int N, F f) {\n    build(N,\
    \ f);\n  }\n\n  template <typename F>\n  void build(int N_, F f) {\n    N = N_;\n\
    \    if (N == 0) {\n      lg = 0;\n      return;\n    }\n    vc<XY> tmp(N), Y(N);\n\
    \    vc<X> S(N);\n    FOR(i, N) tie(tmp[i], Y[i], S[i]) = f(i);\n    auto I =\
    \ argsort(Y);\n    tmp = rearrange(tmp, I), Y = rearrange(Y, I), S = rearrange(S,\
    \ I);\n    XtoI.build(tmp), YtoI.build(Y);\n    new_idx.resize(N);\n    FOR(i,\
    \ N) new_idx[I[i]] = i;\n\n    // \u3042\u3068\u306F\u666E\u901A\u306B\n    lg\
    \ = __lg(XtoI(MAX(tmp) + 1)) + 1;\n    mid.resize(lg), bv.assign(lg, Bit_Vector(N));\n\
    \    dat.resize(lg);\n    A.resize(N);\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n\n\
    \    vc<XY> A0(N), A1(N);\n    vc<X> S0(N), S1(N);\n    FOR_R(d, lg) {\n     \
    \ int p0 = 0, p1 = 0;\n      FOR(i, N) {\n        bool f = (A[i] >> d & 1);\n\
    \        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }\n        if (f) { S1[p1]\
    \ = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }\n      }\n      mid[d] = p0;\n\
    \      bv[d].build();\n      swap(A, A0), swap(S, S0);\n      FOR(i, p1) A[p0\
    \ + i] = A1[i], S[p0 + i] = S1[i];\n      dat[d].build(N, [&](int i) -> X { return\
    \ S[i]; });\n    }\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n  }\n\n  int count(XY\
    \ x1, XY x2, XY y1, XY y2) {\n    if (N == 0) return 0;\n    x1 = XtoI(x1), x2\
    \ = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    return count_inner(y1, y2,\
    \ x2) - count_inner(y1, y2, x1);\n  }\n\n  X prod(XY x1, XY x2, XY y1, XY y2)\
    \ { return sum(x1, x2, y1, y2); }\n  X sum(XY x1, XY x2, XY y1, XY y2) {\n   \
    \ if (N == 0) return MX::unit();\n    assert(x1 <= x2 && y1 <= y2);\n    x1 =\
    \ XtoI(x1), x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    X add = sum_inner(y1,\
    \ y2, x2);\n    X sub = sum_inner(y1, y2, x1);\n    return MX::op(add, MX::inverse(sub));\n\
    \  }\n\n  X prefix_prod(XY x, XY y) { return prefix_sum(x, y); }\n  X prefix_sum(XY\
    \ x, XY y) {\n    if (N == 0) return MX::unit();\n    return sum_inner(0, YtoI(y),\
    \ XtoI(x));\n  }\n\n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E\
    \ index\n  void add(int i, X x) {\n    assert(0 <= i && i < N);\n    i = new_idx[i];\n\
    \    int a = A[i];\n    FOR_R(d, lg) {\n      if (a >> d & 1) {\n        i = mid[d]\
    \ + bv[d].rank(i, 1);\n      } else {\n        i = bv[d].rank(i, 0);\n      }\n\
    \      dat[d].add(i, x);\n    }\n  }\n\nprivate:\n  int count_inner(int L, int\
    \ R, int x) {\n    int cnt = 0;\n    FOR_R(d, lg) {\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\n      if (x >> d & 1) {\n        cnt += r0 - l0,\
    \ L += mid[d] - l0, R += mid[d] - r0;\n      } else {\n        L = l0, R = r0;\n\
    \      }\n    }\n    return cnt;\n  }\n\n  X sum_inner(int L, int R, int x) {\n\
    \    if (x == 0) return MX::unit();\n    X sm = MX::unit();\n    FOR_R(d, lg)\
    \ {\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n      if (x >> d\
    \ & 1) {\n        sm = MX::op(sm, dat[d].sum(l0, r0));\n        L += mid[d] -\
    \ l0, R += mid[d] - r0;\n      } else {\n        L = l0, R = r0;\n      }\n  \
    \  }\n    return sm;\n  }\n};\n#line 7 \"test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  vc<u32> X(N), Y(N);\n  vc<u64> W(N);\n  FOR(i,\
    \ N) read(X[i], Y[i], W[i]);\n  using QQ = tuple<u32, u32, u32, u32>;\n  vc<QQ>\
    \ query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      U32(x, y, w);\n\
    \      X.eb(x);\n      Y.eb(y);\n      W.eb(0);\n      query[q] = mt(-1, x, y,\
    \ w);\n    } else {\n      U32(a, b, c, d);\n      query[q] = mt(a, c, b, d);\n\
    \    }\n  }\n\n  Wavelet_Matrix_2D_Range_Dynamic_AbelGroup<Monoid_Add<ll>, int,\
    \ false, false>\n      WM(len(X), [&](int i) -> tuple<int, int, ll> {\n      \
    \  return {X[i], Y[i], W[i]};\n      });\n  int idx = N;\n  FOR(q, Q) {\n    auto\
    \ [a, b, c, d] = query[q];\n    if (a == u32(-1)) {\n      WM.add(idx++, d);\n\
    \    } else {\n      print(WM.sum(a, b, c, d));\n    }\n  }\n}\n\nsigned main()\
    \ {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  vc<u32> X(N), Y(N);\n  vc<u64> W(N);\n  FOR(i,\
    \ N) read(X[i], Y[i], W[i]);\n  using QQ = tuple<u32, u32, u32, u32>;\n  vc<QQ>\
    \ query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      U32(x, y, w);\n\
    \      X.eb(x);\n      Y.eb(y);\n      W.eb(0);\n      query[q] = mt(-1, x, y,\
    \ w);\n    } else {\n      U32(a, b, c, d);\n      query[q] = mt(a, c, b, d);\n\
    \    }\n  }\n\n  Wavelet_Matrix_2D_Range_Dynamic_AbelGroup<Monoid_Add<ll>, int,\
    \ false, false>\n      WM(len(X), [&](int i) -> tuple<int, int, ll> {\n      \
    \  return {X[i], Y[i], W[i]};\n      });\n  int idx = N;\n  FOR(q, Q) {\n    auto\
    \ [a, b, c, d] = query[q];\n    if (a == u32(-1)) {\n      WM.add(idx++, d);\n\
    \    } else {\n      print(WM.sum(a, b, c, d));\n    }\n  }\n}\n\nsigned main()\
    \ {\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp
  - ds/bit_vector.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
  requiredBy: []
  timestamp: '2024-05-14 16:33:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp.html
title: test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
---
