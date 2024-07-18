---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':heavy_check_mark:'
    path: string/double_ended_palindromic_tree.hpp
    title: string/double_ended_palindromic_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/palindromes_in_deque
    links:
    - https://judge.yosupo.jp/problem/palindromes_in_deque
  bundledCode: "#line 1 \"test/library_checker/string/palindromes_in_deque.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/palindromes_in_deque\"\n#line\
    \ 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    using fastio::flush;\r\n\r\n#if defined(LOCAL)\r\n#define SHOW(...) \\\r\n  SHOW_IMPL(__VA_ARGS__,\
    \ SHOW4, SHOW3, SHOW2, SHOW1)(__VA_ARGS__)\r\n#define SHOW_IMPL(_1, _2, _3, _4,\
    \ NAME, ...) NAME\r\n#define SHOW1(x) print(#x, \"=\", (x)), flush()\r\n#define\
    \ SHOW2(x, y) print(#x, \"=\", (x), #y, \"=\", (y)), flush()\r\n#define SHOW3(x,\
    \ y, z) print(#x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z)), flush()\r\n#define\
    \ SHOW4(x, y, z, w) \\\r\n  print(#x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z),\
    \ #w, \"=\", (w)), flush()\r\n#else\r\n#define SHOW(...)\r\n#endif\r\n\r\n#define\
    \ INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)\
    \   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define U32(...)   \\\
    \r\n  u32 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define U64(...)   \\\r\n\
    \  u64 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)      \\\r\n\
    \  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)   \\\r\n\
    \  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)      \\\r\n\
    \  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type, name,\
    \ size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define VV(type,\
    \ name, h, w)                     \\\r\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"\
    ); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print(t ? \"\
    Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool t = 1)\
    \ { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\r\n#line\
    \ 4 \"test/library_checker/string/palindromes_in_deque.test.cpp\"\n\n#line 1 \"\
    string/double_ended_palindromic_tree.hpp\"\n// https://arxiv.org/abs/2210.02292\n\
    // https://codeforces.com/contest/1738/submission/263034583\ntemplate <int sigma,\
    \ char offset>\nstruct Double_Ended_Palindromic_Tree {\n  struct Node {\n    array<int,\
    \ sigma> TO; // \u4E21\u7AEF\u306B\u3042\u308B\u6587\u5B57\u3092\u8FFD\u52A0\u3057\
    \u3066\u3067\u304D\u308B\u56DE\u6587\n    int par;              // \u4E21\u7AEF\
    \u306B\u3042\u308B\u6587\u5B57\u3092\u9664\u3044\u3066\u3067\u304D\u308B\u56DE\
    \u6587\n    int link;             // longest suffix palindrome \u30CE\u30FC\u30C9\
    \n    int length;           // \u305D\u306E\u56DE\u6587\u306E\u9577\u3055\n  \
    \  int cnt;\n    int linkcnt; // suffix link tree \u3067\u306E\u5B50\u306E\u500B\
    \u6570\n\n    // link \u306E\u8A08\u7B97\u3092\u30E1\u30E2\u5316\u3057\u305F\u3082\
    \u306E\n    // str(v)+c \u306E longest palindrome suffix = c+str(w)+c \u3068\u306A\
    \u308B w\n    array<int, sigma> direct_link;\n  };\n  static constexpr int ODD\
    \ = 0, EVEN = 1;\n  vc<Node> nodes;\n  vc<int> FREE; // Node \u304C\u524A\u9664\
    \u6E08\u3067\u4F7F\u308F\u308C\u3066\u3044\u306A\u3044 index\n\n  // \u6587\u5B57\
    \u5217\u306E position \u3054\u3068\u306B\u6301\u3064\u3082\u306E\n  struct T {\n\
    \    int c;\n    // \u305D\u306E\u6587\u5B57\u304B\u3089\u5DE6\u53F3\u306B\u4F38\
    \u3073\u308B\u6975\u5927\u56DE\u6587\u304C surface \u306A\u3089\u3070\u305D\u306E\
    \ node\n    // surface \u3067\u306A\u3044\u306A\u3089\u3070 EVEN\n    int left_surface,\
    \ right_surface;\n  };\n\n  int mod, mask;\n  vc<T> dat;\n  int L = 0, R = 0;\
    \ // global index range\n  int num_node = 0;\n\n  int new_node(int par, int link,\
    \ int length, int c = -1) {\n    ++num_node;\n    Node n;\n    fill(all(n.TO),\
    \ -1);\n    fill(all(n.direct_link), -1);\n    n.par = par, n.link = link, n.length\
    \ = length;\n    n.linkcnt = n.cnt = 0;\n    if (link != -1) nodes[link].linkcnt\
    \ += 1;\n    int p = 0;\n    if (FREE.empty()) {\n      p = len(nodes);\n    \
    \  nodes.eb(n);\n    } else {\n      p = POP(FREE);\n      nodes[p] = n;\n   \
    \ }\n    if (par != -1) nodes[par].TO[c] = p;\n    return p;\n  }\n\n  void remove_node(int\
    \ nid, int c) {\n    --num_node;\n    int pid = nodes[nid].par;\n    assert(nodes[pid].TO[c]\
    \ == nid);\n    nodes[pid].TO[c] = -1;\n    int k = nodes[nid].link;\n    nodes[k].linkcnt\
    \ -= 1;\n    if (nodes[k].linkcnt == 0) FREE.eb(nid);\n  }\n\n  Double_Ended_Palindromic_Tree(int\
    \ max_size) { // odd, even\n    assert(ODD == new_node(-1, -1, -1));\n    assert(EVEN\
    \ == new_node(-1, 0, 0));\n    nodes[ODD].cnt = infty<int>, nodes[EVEN].cnt =\
    \ infty<int>;\n    mod = 4;\n    while (mod < max_size) mod *= 2;\n    dat.resize(mod);\n\
    \    mask = mod - 1;\n  }\n\n  int suffix_node() {\n    return (L == R ? EVEN\
    \ : dat[(R - 1) & mask].left_surface);\n  }\n  int prefix_node() { return (L ==\
    \ R ? EVEN : dat[L & mask].right_surface); }\n\n  void push_back(int c) {\n  \
    \  assert(R - L <= mask);\n    c -= offset;\n    int v = suffix_node();\n    dat[R\
    \ & mask].c = c;\n    // update palindromic tree, v <- nxt suffix node\n    v\
    \ = [&]() -> int {\n      auto dfs = [&](auto& dfs, int v) -> int {\n        //\
    \ str(v)+c \u306E longest suffix palindrome = c+str(w)+c\n        int& w = nodes[v].direct_link[c];\n\
    \        if (w != -1) { return w; }\n        int p = nodes[v].link;\n        int\
    \ j = R - 1 - nodes[p].length;\n        if (L <= j && j <= R && dat[j & mask].c\
    \ == c) { return w = p; }\n        return w = dfs(dfs, p);\n      };\n      //\
    \ \u3044\u307E\u306E\u30CE\u30FC\u30C9\u306B\u8DB3\u305B\u306A\u3044\u306A\u3089\
    \u623B\u308B\n      int j = R - 1 - nodes[v].length;\n      if (!(L <= j && j\
    \ <= R && dat[j & mask].c == c)) { v = dfs(dfs, v); }\n      // c+str(v)+c \u3092\
    \u4F5C\u308B\n      if (nodes[v].TO[c] != -1) { return nodes[v].TO[c]; }\n   \
    \   int link = (v == ODD ? EVEN : nodes[dfs(dfs, v)].TO[c]);\n      return new_node(v,\
    \ link, nodes[v].length + 2, c);\n    }();\n    dat[R & mask].right_surface =\
    \ EVEN;\n    dat[(R - nodes[v].length + 1) & mask].right_surface = v;\n    dat[R\
    \ & mask].left_surface = v;\n    int w = nodes[v].link;\n\n    int k = (R - nodes[v].length\
    \ + nodes[w].length);\n    if (nodes[w].length >= 1 && dat[k & mask].left_surface\
    \ == w) {\n      dat[k & mask].left_surface = EVEN;\n    }\n    ++R, nodes[v].cnt\
    \ += 1;\n  }\n\n  void pop_back() {\n    assert(L < R);\n    int v = suffix_node();\n\
    \    int w = nodes[v].link;\n    int k = R - 1 - nodes[v].length + nodes[w].length;\n\
    \    if (nodes[dat[k & mask].left_surface].length < nodes[w].length) {\n     \
    \ dat[k & mask].left_surface = w;\n      dat[(k - nodes[w].length + 1) & mask].right_surface\
    \ = w;\n    } else {\n      dat[(k - nodes[w].length + 1) & mask].right_surface\
    \ = EVEN;\n    }\n    nodes[v].cnt--;\n    if (nodes[v].linkcnt == 0 && nodes[v].cnt\
    \ == 0) {\n      remove_node(v, dat[(R - 1) & mask].c);\n    }\n    --R;\n  }\n\
    \n  void push_front(int c) {\n    assert(R - L <= mask);\n    c -= offset;\n \
    \   int v = prefix_node();\n    dat[(L - 1) & mask].c = c;\n    // update palindromic\
    \ tree, v <- nxt suffix node\n    v = [&]() -> int {\n      auto dfs = [&](auto&\
    \ dfs, int v) -> int {\n        // str(v)+c \u306E longest suffix palindrome =\
    \ c+str(w)+c\n        int& w = nodes[v].direct_link[c];\n        if (w != -1)\
    \ { return w; }\n        int p = nodes[v].link;\n        int j = L + nodes[p].length;\n\
    \        if (L - 1 <= j && j <= R - 1 && dat[j & mask].c == c) { return w = p;\
    \ }\n        return w = dfs(dfs, p);\n      };\n      // \u3044\u307E\u306E\u30CE\
    \u30FC\u30C9\u306B\u8DB3\u305B\u306A\u3044\u306A\u3089\u623B\u308B\n      int\
    \ j = L + nodes[v].length;\n      if (!(L - 1 <= j && j <= R - 1 && dat[j & mask].c\
    \ == c)) {\n        v = dfs(dfs, v);\n      }\n      // c+str(v)+c \u3092\u4F5C\
    \u308B\n      if (nodes[v].TO[c] != -1) { return nodes[v].TO[c]; }\n      int\
    \ link = (v == ODD ? EVEN : nodes[dfs(dfs, v)].TO[c]);\n      return new_node(v,\
    \ link, nodes[v].length + 2, c);\n    }();\n    dat[(L - 1) & mask].left_surface\
    \ = EVEN;\n    dat[(L - 2 + nodes[v].length) & mask].left_surface = v;\n    dat[(L\
    \ - 1) & mask].right_surface = v;\n    int w = nodes[v].link;\n\n    int k = ((L\
    \ - 1) + nodes[v].length - nodes[w].length);\n    if (nodes[w].length >= 1 &&\
    \ dat[k & mask].right_surface == w) {\n      dat[k & mask].right_surface = EVEN;\n\
    \    }\n    --L, nodes[v].cnt += 1;\n  }\n\n  void pop_front() {\n    assert(L\
    \ < R);\n    int v = prefix_node();\n    int w = nodes[v].link;\n    int k = L\
    \ + nodes[v].length - nodes[w].length;\n    if (nodes[dat[k & mask].right_surface].length\
    \ < nodes[w].length) {\n      dat[k & mask].right_surface = w;\n      dat[(k +\
    \ nodes[w].length - 1) & mask].left_surface = w;\n    } else {\n      dat[(k +\
    \ nodes[w].length - 1) & mask].left_surface = EVEN;\n    }\n    nodes[v].cnt--;\n\
    \    if (nodes[v].linkcnt == 0 && nodes[v].cnt == 0) {\n      remove_node(v, dat[L\
    \ & mask].c);\n    }\n    ++L;\n  }\n\n  int count_distinct_palindrome() { return\
    \ num_node - 2; }\n  int maximum_prefix_palindrome() { return nodes[prefix_node()].length;\
    \ }\n  int maximum_suffix_palindrome() { return nodes[suffix_node()].length; }\n\
    };\n#line 6 \"test/library_checker/string/palindromes_in_deque.test.cpp\"\n\n\
    void solve() {\n  INT(Q);\n  Double_Ended_Palindromic_Tree<26, 'a'> tree(Q);\n\
    \  FOR(q, Q) {\n    INT(t);\n    if (t == 0) {\n      CHAR(c);\n      tree.push_front(c);\n\
    \    }\n    if (t == 1) {\n      CHAR(c);\n      tree.push_back(c);\n    }\n \
    \   if (t == 2) { tree.pop_front(); }\n    if (t == 3) { tree.pop_back(); }\n\
    \    int a = tree.count_distinct_palindrome();\n    int b = tree.maximum_prefix_palindrome();\n\
    \    int c = tree.maximum_suffix_palindrome();\n    print(a, b, c);\n  }\n}\n\n\
    signed main() { solve(); }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/palindromes_in_deque\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"string/double_ended_palindromic_tree.hpp\"\
    \n\nvoid solve() {\n  INT(Q);\n  Double_Ended_Palindromic_Tree<26, 'a'> tree(Q);\n\
    \  FOR(q, Q) {\n    INT(t);\n    if (t == 0) {\n      CHAR(c);\n      tree.push_front(c);\n\
    \    }\n    if (t == 1) {\n      CHAR(c);\n      tree.push_back(c);\n    }\n \
    \   if (t == 2) { tree.pop_front(); }\n    if (t == 3) { tree.pop_back(); }\n\
    \    int a = tree.count_distinct_palindrome();\n    int b = tree.maximum_prefix_palindrome();\n\
    \    int c = tree.maximum_suffix_palindrome();\n    print(a, b, c);\n  }\n}\n\n\
    signed main() { solve(); }"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - string/double_ended_palindromic_tree.hpp
  isVerificationFile: true
  path: test/library_checker/string/palindromes_in_deque.test.cpp
  requiredBy: []
  timestamp: '2024-05-29 22:32:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/string/palindromes_in_deque.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/palindromes_in_deque.test.cpp
- /verify/test/library_checker/string/palindromes_in_deque.test.cpp.html
title: test/library_checker/string/palindromes_in_deque.test.cpp
---