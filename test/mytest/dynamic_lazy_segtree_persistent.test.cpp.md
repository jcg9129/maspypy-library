---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/acted_monoid/summax_assign.hpp
    title: alg/acted_monoid/summax_assign.hpp
  - icon: ':x:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':x:'
    path: alg/monoid/summax.hpp
    title: alg/monoid/summax.hpp
  - icon: ':x:'
    path: ds/segtree/dynamic_lazy_segtree.hpp
    title: ds/segtree/dynamic_lazy_segtree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':x:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/dynamic_lazy_segtree_persistent.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#pragma GCC\
    \ optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
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
    \  return B;\n}\n#endif\n#line 1 \"other/io.hpp\"\n#include <unistd.h>\r\n#include\
    \ <sys/mman.h>\r\n#include <sys/stat.h>\r\n\r\nnamespace fastio {\r\n// https://judge.yosupo.jp/submission/21623\r\
    \n// https://judge.yosupo.jp/submission/70667\r\n\r\nstruct Pre {\r\n  char num[10000][4];\r\
    \n  constexpr Pre() : num() {\r\n    for (int i = 0; i < 10000; i++) {\r\n   \
    \   int n = i;\r\n      for (int j = 3; j >= 0; j--) {\r\n        num[i][j] =\
    \ n % 10 | '0';\r\n        n /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr\
    \ pre;\r\n\r\nconstexpr int BSZ = 1 << 19;\r\nchar *ibuf, obuf[BSZ], out[100];\r\
    \nint outi, obufi;\r\n\r\n// gcc expansion. called automaticall before main.\r\
    \nvoid __attribute__((constructor)) _c() {\r\n  struct stat sb;\r\n  fstat(0,\
    \ &sb);\r\n  ibuf\r\n      = (char *)mmap(0, sb.st_size, PROT_READ, MAP_SHARED\
    \ | MAP_POPULATE, 0, 0);\r\n}\r\n\r\nvoid flush() { write(1, obuf, obufi), obufi\
    \ = 0; }\r\n\r\nvoid rd(char &c) { c = *ibuf++; }\r\nvoid rd(string &x) {\r\n\
    \  x.clear();\r\n  char c;\r\n  do { rd(c); } while (isspace(c));\r\n  do { x\
    \ += c, rd(c); } while (!isspace(c));\r\n}\r\n\r\ntemplate <typename T>\r\nvoid\
    \ rd_integer(T &x) {\r\n  char c;\r\n  do\r\n    rd(c);\r\n  while (c < '-');\r\
    \n  bool minus = 0;\r\n  if constexpr (is_signed<T>::value || is_same_v<T, i128>)\
    \ {\r\n    if (c == '-') { minus = 1, rd(c); }\r\n  }\r\n  x = 0;\r\n  while (c\
    \ >= '0') { x = x * 10 + (c & 15), rd(c); }\r\n  if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n    if (minus) x = -x;\r\n  }\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nvoid rd_real(T &x) {\r\n  string s;\r\n  rd(s);\r\n  x = stod(s);\r\
    \n}\r\n\r\nvoid rd(int &x) { rd_integer(x); }\r\nvoid rd(ll &x) { rd_integer(x);\
    \ }\r\nvoid rd(i128 &x) { rd_integer(x); }\r\nvoid rd(u32 &x) { rd_integer(x);\
    \ }\r\nvoid rd(u64 &x) { rd_integer(x); }\r\nvoid rd(u128 &x) { rd_integer(x);\
    \ }\r\nvoid rd(double &x) { rd_real(x); }\r\nvoid rd(long double &x) { rd_real(x);\
    \ }\r\nvoid rd(f128 &x) { rd_real(x); }\r\ntemplate <class T, class U>\r\nvoid\
    \ rd(pair<T, U> &p) {\r\n  return rd(p.first), rd(p.second);\r\n}\r\ntemplate\
    \ <size_t N = 0, typename T>\r\nvoid rd(T &t) {\r\n  if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n    auto &x = std::get<N>(t);\r\n    rd(x);\r\n    rd<N + 1>(t);\r\n  }\r\
    \n}\r\ntemplate <class... T>\r\nvoid rd(tuple<T...> &tpl) {\r\n  rd(tpl);\r\n\
    }\r\ntemplate <class T>\r\nvoid rd(vc<T> &x) {\r\n  for (auto &d: x) rd(d);\r\n\
    }\r\ntemplate <size_t N = 0, typename T>\r\nvoid rd(array<T, N> &x) {\r\n  for\
    \ (auto &d: x) rd(d);\r\n}\r\n\r\ntemplate <typename T>\r\nstruct has_read_method\
    \ {\r\n  template <typename U>\r\n  static std::true_type test(decltype(&U::read)\
    \ *);\r\n  template <typename>\r\n  static std::false_type test(...);\r\n  using\
    \ type = decltype(test<T>(nullptr));\r\n  static constexpr bool value = type::value;\r\
    \n};\r\n\r\ntemplate <typename T>\r\nenable_if<has_read_method<T>::value, void>::type\
    \ rd(T &x) {\r\n  x.read();\r\n}\r\n\r\nvoid read() {}\r\ntemplate <class H, class...\
    \ T>\r\nvoid read(H &h, T &... t) {\r\n  rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const\
    \ char c) {\r\n  if (obufi == BSZ) flush();\r\n  obuf[obufi++] = c;\r\n}\r\nvoid\
    \ wt(const string &s) {\r\n  for (char c: s) wt(c);\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid wt_integer(T x) {\r\n  if (obufi > BSZ - 100) flush();\r\n  if (x\
    \ < 0) { obuf[obufi++] = '-', x = -x; }\r\n  for (outi = 96; x >= 10000; outi\
    \ -= 4) {\r\n    memcpy(out + outi, pre.num[x % 10000], 4);\r\n    x /= 10000;\r\
    \n  }\r\n  if (x >= 1000) {\r\n    memcpy(obuf + obufi, pre.num[x], 4);\r\n  \
    \  obufi += 4;\r\n  } else if (x >= 100) {\r\n    memcpy(obuf + obufi, pre.num[x]\
    \ + 1, 3);\r\n    obufi += 3;\r\n  } else if (x >= 10) {\r\n    int q = (x * 103)\
    \ >> 10;\r\n    obuf[obufi] = q | '0';\r\n    obuf[obufi + 1] = (x - q * 10) |\
    \ '0';\r\n    obufi += 2;\r\n  } else\r\n    obuf[obufi++] = x | '0';\r\n  memcpy(obuf\
    \ + obufi, out + outi + 4, 96 - outi);\r\n  obufi += 96 - outi;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nvoid wt_real(T x) {\r\n  ostringstream oss;\r\n  oss << fixed\
    \ << setprecision(15) << double(x);\r\n  string s = oss.str();\r\n  wt(s);\r\n\
    }\r\n\r\nvoid wt(int x) { wt_integer(x); }\r\nvoid wt(ll x) { wt_integer(x); }\r\
    \nvoid wt(i128 x) { wt_integer(x); }\r\nvoid wt(u32 x) { wt_integer(x); }\r\n\
    void wt(u64 x) { wt_integer(x); }\r\nvoid wt(u128 x) { wt_integer(x); }\r\nvoid\
    \ wt(double x) { wt_real(x); }\r\nvoid wt(long double x) { wt_real(x); }\r\nvoid\
    \ wt(f128 x) { wt_real(x); }\r\n\r\ntemplate <class T, class U>\r\nvoid wt(const\
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
    \ntemplate <typename T>\r\nstruct has_print_method {\r\n  template <typename U>\r\
    \n  static std::true_type test(decltype(&U::print) *);\r\n  template <typename>\r\
    \n  static std::false_type test(...);\r\n  using type = decltype(test<T>(nullptr));\r\
    \n  static constexpr bool value = type::value;\r\n};\r\n\r\ntemplate <typename\
    \ T>\r\nenable_if<has_print_method<T>::value, void>::type wt(T x) {\r\n  x.print();\r\
    \n}\r\n\r\nvoid print() { wt('\\n'); }\r\ntemplate <class Head, class... Tail>\r\
    \nvoid print(Head &&head, Tail &&... tail) {\r\n  wt(head);\r\n  if (sizeof...(Tail))\
    \ wt(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\n// gcc expansion. called\
    \ automaticall after main.\r\nvoid __attribute__((destructor)) _d() { flush();\
    \ }\r\n} // namespace fastio\r\n\r\nusing fastio::read;\r\nusing fastio::print;\r\
    \nusing fastio::flush;\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\
    \n  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define CHAR(...)   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    #define DBL(...)      \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    \r\n#define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n \
    \ read(name)\r\n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t\
    \ ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool\
    \ t = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\
    \nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1)\
    \ { yes(!t); }\n#line 2 \"alg/monoid/summax.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_SumMax {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, max(x.se, y.se)}; }\n  static\
    \ X from_element(E e) { return {e, e}; }\n  static constexpr X unit() { return\
    \ {E(0), -infty<E>}; }\n  static constexpr bool commute = 1;\n};\n#line 2 \"alg/monoid/assign.hpp\"\
    \n\r\ntemplate <typename X, int none_val>\r\nstruct Monoid_Assign {\r\n  using\
    \ value_type = X;\r\n  static X op(X x, X y) { return (y == X(none_val) ? x :\
    \ y); }\r\n  static constexpr X unit() { return X(none_val); }\r\n  static constexpr\
    \ bool commute = false;\r\n};\r\n#line 3 \"alg/acted_monoid/summax_assign.hpp\"\
    \n\r\ntemplate <typename E, E none_val>\r\nstruct ActedMonoid_SumMax_Assign {\r\
    \n  using Monoid_X = Monoid_SumMax<E>;\r\n  using Monoid_A = Monoid_Assign<E,\
    \ none_val>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A = typename\
    \ Monoid_A::value_type;\r\n  static constexpr X act(const X& x, const A& a, const\
    \ ll& size) {\r\n    if (a == Monoid_A::unit()) return x;\r\n    return {E(size)\
    \ * a, a};\r\n  }\r\n};\r\n#line 2 \"ds/segtree/dynamic_lazy_segtree.hpp\"\n\n\
    template <typename ActedMonoid, bool PERSISTENT, int NODES>\nstruct Dynamic_Lazy_SegTree\
    \ {\n  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA\
    \ = typename AM::Monoid_A;\n  using X = typename AM::X;\n  using A = typename\
    \ AM::A;\n  using F = function<X(ll, ll)>;\n  F default_prod;\n\n  struct Node\
    \ {\n    Node *l, *r;\n    X x;\n    A lazy;\n  };\n\n  const ll L0, R0;\n  Node\
    \ *pool;\n  int pid;\n  using np = Node *;\n\n  Dynamic_Lazy_SegTree(\n      ll\
    \ L0, ll R0, F default_prod = [](ll l, ll r) -> X { return MX::unit(); })\n  \
    \    : default_prod(default_prod), L0(L0), R0(R0), pid(0) {\n    pool = new Node[NODES];\n\
    \  }\n\n  np new_root() { return new_node(L0, R0); }\n\n  np new_node(const X\
    \ x) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x = x;\n    pool[pid].lazy\
    \ = MA::unit();\n    return &(pool[pid++]);\n  }\n\n  np new_node(ll l, ll r)\
    \ { return new_node(default_prod(l, r)); }\n  np new_node() { return new_node(L0,\
    \ R0); }\n\n  np new_node(const vc<X> &dat) {\n    assert(L0 == 0 && R0 == len(dat));\n\
    \    auto dfs = [&](auto &dfs, ll l, ll r) -> Node * {\n      if (l == r) return\
    \ nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n      ll m = (l +\
    \ r) / 2;\n      np l_root = dfs(dfs, l, m), r_root = dfs(dfs, m, r);\n      X\
    \ x = MX::op(l_root->x, r_root->x);\n      np root = new_node(x);\n      root->l\
    \ = l_root, root->r = r_root;\n      return root;\n    };\n    return dfs(dfs,\
    \ 0, len(dat));\n  }\n\n  X prod(np root, ll l, ll r) {\n    if (l == r || !root)\
    \ return MX::unit();\n    assert(pid && L0 <= l && l < r && r <= R0);\n    X x\
    \ = MX::unit();\n    prod_rec(root, L0, R0, l, r, x, MA::unit());\n    return\
    \ x;\n  }\n\n  X prod_all(np root) { return prod(root, L0, R0); }\n\n  np set(np\
    \ root, ll i, const X &x) {\n    assert(pid && L0 <= i && i < R0);\n    return\
    \ set_rec(root, L0, R0, i, x);\n  }\n\n  np multiply(np root, ll i, const X &x)\
    \ {\n    assert(pid && L0 <= i && i < R0);\n    return multiply_rec(root, L0,\
    \ R0, i, x);\n  }\n\n  np apply(np root, ll l, ll r, const A &a) {\n    if (l\
    \ == r) return root;\n    assert(pid && L0 <= l && l < r && r <= R0);\n    return\
    \ apply_rec(root, L0, R0, l, r, a);\n  }\n\n  template <typename F>\n  ll max_right(np\
    \ root, F check, ll L) {\n    assert(pid && L0 <= L && L <= R0 && check(MX::unit()));\n\
    \    X x = MX::unit();\n    return max_right_rec(root, check, L0, R0, L, x);\n\
    \  }\n\n  template <typename F>\n  ll min_left(np root, F check, ll R) {\n   \
    \ assert(pid && L0 <= R && R <= R0 && check(MX::unit()));\n    X x = MX::unit();\n\
    \    return min_left_rec(root, check, L0, R0, R, x);\n  }\n\n  // f(idx, val)\n\
    \  template <typename F>\n  void enumerate(np root, F f) {\n    auto dfs = [&](auto\
    \ &dfs, np c, ll l, ll r, A a) -> void {\n      if (!c) return;\n      if (r -\
    \ l == 1) {\n        f(l, AM::act(c->x, a, 1));\n        return;\n      }\n  \
    \    ll m = (l + r) / 2;\n      a = MA::op(c->lazy, a);\n      dfs(dfs, c->l,\
    \ l, m, a);\n      dfs(dfs, c->r, m, r, a);\n    };\n    dfs(dfs, root, L0, R0,\
    \ MA::unit());\n  }\n\n  void reset() { pid = 0; }\n\nprivate:\n  np copy_node(np\
    \ c) {\n    if (!c || !PERSISTENT) return c;\n    pool[pid].l = c->l, pool[pid].r\
    \ = c->r;\n    pool[pid].x = c->x;\n    pool[pid].lazy = c->lazy;\n    return\
    \ &(pool[pid++]);\n  }\n\n  void prop(np c, ll l, ll r) {\n    assert(r - l >=\
    \ 2);\n    ll m = (l + r) / 2;\n    if (c->lazy == MA::unit()) return;\n    c->l\
    \ = (c->l ? copy_node(c->l) : new_node(l, m));\n    c->l->x = AM::act(c->l->x,\
    \ c->lazy, m - l);\n    c->l->lazy = MA::op(c->l->lazy, c->lazy);\n    c->r =\
    \ (c->r ? copy_node(c->r) : new_node(m, r));\n    c->r->x = AM::act(c->r->x, c->lazy,\
    \ r - m);\n    c->r->lazy = MA::op(c->r->lazy, c->lazy);\n    c->lazy = MA::unit();\n\
    \  }\n\n  np set_rec(np c, ll l, ll r, ll i, const X &x) {\n    if (r == l + 1)\
    \ {\n      c = copy_node(c);\n      c->x = x;\n      c->lazy = MA::unit();\n \
    \     return c;\n    }\n    prop(c, l, r);\n    ll m = (l + r) / 2;\n    if (!c->l)\
    \ c->l = new_node(l, m);\n    if (!c->r) c->r = new_node(m, r);\n\n    c = copy_node(c);\n\
    \    if (i < m) {\n      c->l = set_rec(c->l, l, m, i, x);\n    } else {\n   \
    \   c->r = set_rec(c->r, m, r, i, x);\n    }\n    c->x = MX::op(c->l->x, c->r->x);\n\
    \    return c;\n  }\n\n  np multiply_rec(np c, ll l, ll r, ll i, const X &x) {\n\
    \    if (r == l + 1) {\n      c = copy_node(c);\n      c->x = MX::op(c->x, x);\n\
    \      c->lazy = MA::unit();\n      return c;\n    }\n    prop(c, l, r);\n   \
    \ ll m = (l + r) / 2;\n    if (!c->l) c->l = new_node(l, m);\n    if (!c->r) c->r\
    \ = new_node(m, r);\n\n    c = copy_node(c);\n    if (i < m) {\n      c->l = multiply_rec(c->l,\
    \ l, m, i, x);\n    } else {\n      c->r = multiply_rec(c->r, m, r, i, x);\n \
    \   }\n    c->x = MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\n  void prod_rec(np\
    \ c, ll l, ll r, ll ql, ll qr, X &x, A lazy) {\n    chmax(ql, l);\n    chmin(qr,\
    \ r);\n    if (ql >= qr) return;\n    if (!c) {\n      x = MX::op(x, AM::act(default_prod(ql,\
    \ qr), lazy, qr - ql));\n      return;\n    }\n    if (l == ql && r == qr) {\n\
    \      x = MX::op(x, AM::act(c->x, lazy, r - l));\n      return;\n    }\n    ll\
    \ m = (l + r) / 2;\n    lazy = MA::op(c->lazy, lazy);\n    prod_rec(c->l, l, m,\
    \ ql, qr, x, lazy);\n    prod_rec(c->r, m, r, ql, qr, x, lazy);\n  }\n\n  np apply_rec(np\
    \ c, ll l, ll r, ll ql, ll qr, const A &a) {\n    if (!c) c = new_node(l, r);\n\
    \    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr) return c;\n    if (l\
    \ == ql && r == qr) {\n      c = copy_node(c);\n      c->x = AM::act(c->x, a,\
    \ r - l);\n      c->lazy = MA::op(c->lazy, a);\n      return c;\n    }\n    prop(c,\
    \ l, r);\n    ll m = (l + r) / 2;\n    c = copy_node(c);\n    c->l = apply_rec(c->l,\
    \ l, m, ql, qr, a);\n    c->r = apply_rec(c->r, m, r, ql, qr, a);\n    c->x =\
    \ MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\n  template <typename F>\n \
    \ ll max_right_rec(np c, const F &check, ll l, ll r, ll ql, X &x) {\n    if (r\
    \ <= ql) return r;\n    if (!c) c = new_node(l, r);\n    chmax(ql, l);\n    if\
    \ (l == ql && check(MX::op(x, c->x))) {\n      x = MX::op(x, c->x);\n      return\
    \ r;\n    }\n    if (r == l + 1) return l;\n    prop(c, l, r);\n    ll m = (l\
    \ + r) / 2;\n    ll k = max_right_rec(c->l, check, l, m, ql, x);\n    if (k <\
    \ m) return k;\n    return max_right_rec(c->r, check, m, r, ql, x);\n  }\n\n \
    \ template <typename F>\n  ll min_left_rec(np c, const F &check, ll l, ll r, ll\
    \ qr, X &x) {\n    if (qr <= l) return l;\n    if (!c) c = new_node(l, r);\n \
    \   chmin(qr, r);\n    if (r == qr && check(MX::op(c->x, x))) {\n      x = MX::op(c->x,\
    \ x);\n      return l;\n    }\n    if (r == l + 1) return r;\n    prop(c, l, r);\n\
    \    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r, check, m, r, qr, x);\n\
    \    if (m < k) return k;\n    return min_left_rec(c->l, check, l, m, qr, x);\n\
    \  }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 7 \"test/mytest/dynamic_lazy_segtree_persistent.test.cpp\"\
    \n\nvoid test() {\n  using AM = ActedMonoid_SumMax_Assign<int, -1>;\n  using P\
    \ = typename AM::X;\n\n  FOR(100) {\n    int N = RNG(1, 1000);\n\n    vvc<int>\
    \ AA;\n    AA.eb(vc<int>(N, 10));\n    Dynamic_Lazy_SegTree<AM, true, 30000> X(0,\
    \ N, [](ll l, ll r) -> P {\n      return {10 * (r - l), 10};\n    });\n    using\
    \ np = typename decltype(X)::np;\n\n    int Q = RNG(1, 1000);\n    vc<np> roots;\n\
    \    roots.eb(X.new_node(0, N));\n\n    FOR(Q) {\n      int time = RNG(0, len(roots));\n\
    \      vc<int> A = AA[time];\n      np root = roots[time];\n      int L = RNG(0,\
    \ N);\n      int R = RNG(0, N);\n      if (L > R) swap(L, R);\n      ++R;\n\n\
    \      int t = RNG(0, 4);\n      if (t == 0) {\n        int i = RNG(0, N);\n \
    \       int x = RNG(1, 100);\n        root = X.set(root, i, {x, x});\n       \
    \ A[i] = x;\n      }\n      if (t == 1) {\n        vc<int> B = {A.begin() + L,\
    \ A.begin() + R};\n        assert(X.prod(root, L, R).fi == SUM<int>(B));\n   \
    \     assert(X.prod(root, L, R).se == MAX(B));\n      }\n      if (t == 2) {\n\
    \        int x = RNG(1, 100);\n        FOR(i, L, R) A[i] = x;\n        root =\
    \ X.apply(root, L, R, x);\n      }\n      if (t == 3) {\n        // max_right\n\
    \        int LIM = R;\n        auto check = [&](auto e) -> bool { return e.se\
    \ <= LIM; };\n        int naive = [&]() -> int {\n          ll mx = 0;\n     \
    \     FOR(i, L, N) {\n            chmax(mx, A[i]);\n            if (mx > LIM)\
    \ return i;\n          }\n          return N;\n        }();\n\n        assert(naive\
    \ == X.max_right(root, check, L));\n      }\n\n      AA.eb(A);\n      roots.eb(root);\n\
    \    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"alg/acted_monoid/summax_assign.hpp\"\n\
    #include \"ds/segtree/dynamic_lazy_segtree.hpp\"\n#include \"random/base.hpp\"\
    \n\nvoid test() {\n  using AM = ActedMonoid_SumMax_Assign<int, -1>;\n  using P\
    \ = typename AM::X;\n\n  FOR(100) {\n    int N = RNG(1, 1000);\n\n    vvc<int>\
    \ AA;\n    AA.eb(vc<int>(N, 10));\n    Dynamic_Lazy_SegTree<AM, true, 30000> X(0,\
    \ N, [](ll l, ll r) -> P {\n      return {10 * (r - l), 10};\n    });\n    using\
    \ np = typename decltype(X)::np;\n\n    int Q = RNG(1, 1000);\n    vc<np> roots;\n\
    \    roots.eb(X.new_node(0, N));\n\n    FOR(Q) {\n      int time = RNG(0, len(roots));\n\
    \      vc<int> A = AA[time];\n      np root = roots[time];\n      int L = RNG(0,\
    \ N);\n      int R = RNG(0, N);\n      if (L > R) swap(L, R);\n      ++R;\n\n\
    \      int t = RNG(0, 4);\n      if (t == 0) {\n        int i = RNG(0, N);\n \
    \       int x = RNG(1, 100);\n        root = X.set(root, i, {x, x});\n       \
    \ A[i] = x;\n      }\n      if (t == 1) {\n        vc<int> B = {A.begin() + L,\
    \ A.begin() + R};\n        assert(X.prod(root, L, R).fi == SUM<int>(B));\n   \
    \     assert(X.prod(root, L, R).se == MAX(B));\n      }\n      if (t == 2) {\n\
    \        int x = RNG(1, 100);\n        FOR(i, L, R) A[i] = x;\n        root =\
    \ X.apply(root, L, R, x);\n      }\n      if (t == 3) {\n        // max_right\n\
    \        int LIM = R;\n        auto check = [&](auto e) -> bool { return e.se\
    \ <= LIM; };\n        int naive = [&]() -> int {\n          ll mx = 0;\n     \
    \     FOR(i, L, N) {\n            chmax(mx, A[i]);\n            if (mx > LIM)\
    \ return i;\n          }\n          return N;\n        }();\n\n        assert(naive\
    \ == X.max_right(root, check, L));\n      }\n\n      AA.eb(A);\n      roots.eb(root);\n\
    \    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/acted_monoid/summax_assign.hpp
  - alg/monoid/summax.hpp
  - alg/monoid/assign.hpp
  - ds/segtree/dynamic_lazy_segtree.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 15:15:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/dynamic_lazy_segtree_persistent.test.cpp
- /verify/test/mytest/dynamic_lazy_segtree_persistent.test.cpp.html
title: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
---
