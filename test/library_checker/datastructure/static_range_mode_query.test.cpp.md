---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/rollback_mo.hpp
    title: ds/offline_query/rollback_mo.hpp
  - icon: ':heavy_check_mark:'
    path: ds/to_small_key.hpp
    title: ds/to_small_key.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_mode_query
    links:
    - https://judge.yosupo.jp/problem/static_range_mode_query
  bundledCode: "#line 1 \"test/library_checker/datastructure/static_range_mode_query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\n\
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
    \ yes(!t); }\r\n#line 5 \"test/library_checker/datastructure/static_range_mode_query.test.cpp\"\
    \n\n#line 1 \"ds/offline_query/rollback_mo.hpp\"\n// https://codeforces.com/contest/620/problem/F\n\
    // (10^5,3*10^5), mo+fastset 1300ms\n// https://codeforces.com/problemset/submission/765/240821486\n\
    struct Rollback_Mo {\n  vc<pair<int, int>> LR;\n  void add(int L, int R) { LR.emplace_back(L,\
    \ R); }\n\n  template <typename AL, typename AR, typename F1, typename F2, typename\
    \ F3,\n            typename O>\n  void calc(AL add_left, AR add_right, F1 reset,\
    \ F2 save, F3 rollback,\n            O query) {\n    const int Q = len(LR);\n\
    \    if (Q == 0) return;\n    int N = 0;\n    for (auto &&[L, R]: LR) chmax(N,\
    \ R);\n    const int b_num = sqrt(Q);\n    const int b_sz = ceil(N, b_num);\n\
    \    vvc<int> QID((N - 1) / b_sz + 1);\n    // \u5DE6\u7AEF\u306E\u5C5E\u3059\u308B\
    \u30D6\u30ED\u30C3\u30AF\u3067\u5206\u985E\n    // \u5DE6\u7AEF\u3068\u53F3\u7AEF\
    \u304C\u540C\u3058\u30D6\u30ED\u30C3\u30AF\u306B\u5C5E\u3059\u308B\u3082\u306E\
    \u306F\u3001\u5148\u306B\u51E6\u7406\u3057\u3066\u3057\u307E\u3046\u3002\n   \
    \ auto naive = [&](int qid) -> void {\n      save();\n      auto [L, R] = LR[qid];\n\
    \      FOR(i, L, R) add_right(i);\n      query(qid);\n      rollback();\n    };\n\
    \n    FOR(qid, Q) {\n      auto [L, R] = LR[qid];\n      int iL = L / b_sz, iR\
    \ = R / b_sz;\n      if (iL == iR) {\n        naive(qid);\n        continue;\n\
    \      }\n      QID[iL].eb(qid);\n    }\n\n    FOR(iL, len(QID)) {\n      auto\
    \ &I = QID[iL];\n      if (I.empty()) continue;\n      sort(all(I),\n        \
    \   [&](auto &a, auto &b) -> bool { return LR[a].se < LR[b].se; });\n      int\
    \ LMAX = 0;\n      for (auto &&qid: I) {\n        auto [L, R] = LR[qid];\n   \
    \     chmax(LMAX, L);\n      }\n      reset();\n      int l = LMAX, r = LMAX;\n\
    \      for (auto &&qid: I) {\n        auto [L, R] = LR[qid];\n        while (r\
    \ < R) add_right(r++);\n        save();\n        while (L < l) add_left(--l);\n\
    \        query(qid);\n        rollback();\n        l = LMAX;\n      }\n    }\n\
    \  }\n};\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename\
    \ Val, int LOG = 20, bool KEEP_IDS = false>\r\nstruct HashMap {\r\n  static constexpr\
    \ int N = (1 << LOG);\r\n  u64* key;\r\n  Val* val;\r\n  vc<int> IDS;\r\n  bitset<N>\
    \ used;\r\n  const int shift;\r\n  const u64 r = 11995408973635179863ULL;\r\n\
    \  HashMap() : key(new u64[N]), val(new Val[N]), shift(64 - LOG) {}\r\n  u32 hash(u64\
    \ x) {\r\n    static const u64 FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    int i = index(k);\r\n    if (!used[i]) {\r\n      used[i] =\
    \ 1, key[i] = k, val[i] = Val{};\r\n      if constexpr (KEEP_IDS) IDS.eb(i);\r\
    \n    }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value)\
    \ {\r\n    int i = index(k);\r\n    return (used[i] ? val[i] : default_value);\r\
    \n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\n    return\
    \ used[i] && key[i] == k;\r\n  }\r\n\r\n  void reset() {\r\n    static_assert(KEEP_IDS);\r\
    \n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  //\
    \ f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F f) {\r\n  \
    \  static_assert(KEEP_IDS);\r\n    for (auto&& i: IDS) f(key[i], val[i]);\r\n\
    \  }\r\n};\r\n#line 2 \"ds/to_small_key.hpp\"\n\n// [30,10,20,30] -> [0,1,2,0]\
    \ etc.\ntemplate <int LOG = 20, bool USE_RESET = false>\nstruct To_Small_Key {\n\
    \  int kind = 0;\n  HashMap<int, LOG, true> MP;\n\n  int set_key(u64 x) {\n  \
    \  int idx = MP.index(x);\n    if (!MP.used[idx]) {\n      MP.used[idx] = 1;\n\
    \      MP.key[idx] = x;\n      MP.val[idx] = kind++;\n    }\n    return MP.val[idx];\n\
    \  }\n\n  int query(u64 x) { return MP.get(x, -1); }\n\n  void reset() {\n   \
    \ static_assert(USE_RESET);\n    MP.reset();\n  }\n};\n#line 8 \"test/library_checker/datastructure/static_range_mode_query.test.cpp\"\
    \n\nvoid solve() {\n  INT(N, Q);\n  VEC(int, A, N);\n  vc<int> key = A;\n  UNIQUE(key);\n\
    \  for (auto& x: A) x = LB(key, x);\n\n  Rollback_Mo mo;\n  FOR(Q) {\n    LL(L,\
    \ R);\n    mo.add(L, R);\n  }\n  vc<pair<int, int>> ANS(Q);\n\n  vc<int> CNT(N);\n\
    \  int max_cnt = 0;\n  int max_key = 0;\n  vc<int> history;\n\n  auto add = [&](int\
    \ i) -> void {\n    int x = A[i];\n    history.eb(x);\n    CNT[x]++;\n    if (chmax(max_cnt,\
    \ CNT[x])) max_key = x;\n  };\n\n  auto reset = [&]() -> void {\n    for (auto&\
    \ x: history) CNT[x] = 0;\n    history.clear();\n    max_cnt = 0, max_key = 0;\n\
    \  };\n\n  int save_cnt = 0, save_key = 0;\n  int save_time = 0;\n  auto save\
    \ = [&]() -> void {\n    save_time = len(history);\n    save_cnt = max_cnt, save_key\
    \ = max_key;\n  };\n\n  auto rb = [&]() -> void {\n    while (len(history) > save_time)\
    \ {\n      int x = POP(history);\n      CNT[x]--;\n    }\n    max_cnt = save_cnt,\
    \ max_key = save_key;\n  };\n\n  auto query = [&](int q) -> void { ANS[q] = {key[max_key],\
    \ max_cnt}; };\n\n  mo.calc(add, add, reset, save, rb, query);\n  for (auto& x:\
    \ ANS) print(x);\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/offline_query/rollback_mo.hpp\"\
    \n#include \"ds/to_small_key.hpp\"\n\nvoid solve() {\n  INT(N, Q);\n  VEC(int,\
    \ A, N);\n  vc<int> key = A;\n  UNIQUE(key);\n  for (auto& x: A) x = LB(key, x);\n\
    \n  Rollback_Mo mo;\n  FOR(Q) {\n    LL(L, R);\n    mo.add(L, R);\n  }\n  vc<pair<int,\
    \ int>> ANS(Q);\n\n  vc<int> CNT(N);\n  int max_cnt = 0;\n  int max_key = 0;\n\
    \  vc<int> history;\n\n  auto add = [&](int i) -> void {\n    int x = A[i];\n\
    \    history.eb(x);\n    CNT[x]++;\n    if (chmax(max_cnt, CNT[x])) max_key =\
    \ x;\n  };\n\n  auto reset = [&]() -> void {\n    for (auto& x: history) CNT[x]\
    \ = 0;\n    history.clear();\n    max_cnt = 0, max_key = 0;\n  };\n\n  int save_cnt\
    \ = 0, save_key = 0;\n  int save_time = 0;\n  auto save = [&]() -> void {\n  \
    \  save_time = len(history);\n    save_cnt = max_cnt, save_key = max_key;\n  };\n\
    \n  auto rb = [&]() -> void {\n    while (len(history) > save_time) {\n      int\
    \ x = POP(history);\n      CNT[x]--;\n    }\n    max_cnt = save_cnt, max_key =\
    \ save_key;\n  };\n\n  auto query = [&](int q) -> void { ANS[q] = {key[max_key],\
    \ max_cnt}; };\n\n  mo.calc(add, add, reset, save, rb, query);\n  for (auto& x:\
    \ ANS) print(x);\n}\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/offline_query/rollback_mo.hpp
  - ds/to_small_key.hpp
  - ds/hashmap.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/static_range_mode_query.test.cpp
  requiredBy: []
  timestamp: '2024-01-21 19:07:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/static_range_mode_query.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/static_range_mode_query.test.cpp
- /verify/test/library_checker/datastructure/static_range_mode_query.test.cpp.html
title: test/library_checker/datastructure/static_range_mode_query.test.cpp
---