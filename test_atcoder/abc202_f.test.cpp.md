---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/count_points_in_triangles.hpp
    title: geo/count_points_in_triangles.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc202/tasks/abc202_f
    links:
    - https://atcoder.jp/contests/abc202/tasks/abc202_f
  bundledCode: "#line 1 \"test_atcoder/abc202_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc202/tasks/abc202_f\"\
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
    \ yes(!t); }\r\n#line 1 \"geo/count_points_in_triangles.hpp\"\n\n#line 2 \"geo/angle_sort.hpp\"\
    \n\r\n#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n  T x,\
    \ y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename A, typename B>\n  Point(A\
    \ x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x\
    \ + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y -\
    \ p.y}; }\n  bool operator==(Point p) const { return x == p.x && y == p.y; }\n\
    \  bool operator!=(Point p) const { return x != p.x || y != p.y; }\n  Point operator-()\
    \ const { return {-x, -y}; }\n  Point operator*(T t) const { return {x * t, y\
    \ * t}; }\n  Point operator/(T t) const { return {x / t, y / t}; }\n\n  bool operator<(Point\
    \ p) const {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T\
    \ dot(Point other) { return x * other.x + y * other.y; }\n  T det(Point other)\
    \ { return x * other.y - y * other.x; }\n\n  double norm() { return sqrtl(x *\
    \ x + y * y); }\n  double angle() { return atan2(y, x); }\n\n  Point rotate(double\
    \ theta) {\n    static_assert(!is_integral<T>::value);\n    double c = cos(theta),\
    \ s = sin(theta);\n    return Point{c * x - s * y, s * x + c * y};\n  }\n};\n\n\
    #ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x),\
    \ fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n\
    \  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\
    \u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename\
    \ T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n\
    \  if (x > 0) return 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename\
    \ REAL, typename T>\nREAL dist(Point<T> A, Point<T> B) {\n  A = A - B;\n  T p\
    \ = A.dot(A);\n  return sqrt(REAL(p));\n}\n\ntemplate <typename T>\nstruct Line\
    \ {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T>\
    \ A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n\
    \  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n    return a * P.x +\
    \ b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U x, U y) {\n    return\
    \ a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c\
    \ \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize()\
    \ {\n    static_assert(is_same_v<T, int> || is_same_v<T, long long>);\n    T g\
    \ = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /= g, c /= g;\n    if (b\
    \ < 0) { a = -a, b = -b, c = -c; }\n    if (b == 0 && a < 0) { a = -a, b = -b,\
    \ c = -c; }\n  }\n\n  bool is_parallel(Line other) { return a * other.b - b *\
    \ other.a == 0; }\n  bool is_orthogonal(Line other) { return a * other.a + b *\
    \ other.b == 0; }\n};\n\ntemplate <typename T>\nstruct Segment {\n  Point<T> A,\
    \ B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T x1, T y1,\
    \ T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  bool\
    \ contain(Point<T> C) {\n    static_assert(is_integral<T>::value);\n    T det\
    \ = (C - A).det(B - A);\n    if (det != 0) return 0;\n    return (C - A).dot(B\
    \ - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A,\
    \ B); }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n \
    \ REAL r;\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL\
    \ y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n\ntemplate <typename T>\nstruct Polygon {\n  vc<Point<T>>\
    \ points;\n  T a;\n\n  template <typename A, typename B>\n  Polygon(vc<pair<A,\
    \ B>> pairs) {\n    for (auto&& [a, b]: pairs) points.eb(Point<T>(a, b));\n  \
    \  build();\n  }\n  Polygon(vc<Point<T>> points) : points(points) { build(); }\n\
    \n  int size() { return len(points); }\n\n  template <typename REAL>\n  REAL area()\
    \ {\n    return a * 0.5;\n  }\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  T area_2() {\n    return a;\n  }\n\n  bool is_convex() {\n    FOR(j,\
    \ len(points)) {\n      int i = (j == 0 ? len(points) - 1 : j - 1);\n      int\
    \ k = (j == len(points) - 1 ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k]\
    \ - points[j]) < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n\
    \  void build() {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1\
    \ == len(points) ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n\
    \    if (a < 0) {\n      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n\
    #line 4 \"geo/angle_sort.hpp\"\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\
    \u3059\u308B argsort\r\ntemplate <typename T>\r\nvector<int> angle_sort(vector<Point<T>>&\
    \ P) {\r\n  vector<int> lower, origin, upper;\r\n  const Point<T> O = {0, 0};\r\
    \n  FOR(i, len(P)) {\r\n    if (P[i] == O) origin.eb(i);\r\n    elif ((P[i].y\
    \ < 0) || (P[i].y == 0 && P[i].x > 0)) lower.eb(i);\r\n    else upper.eb(i);\r\
    \n  }\r\n  sort(all(lower), [&](auto& i, auto& j) { return P[i].det(P[j]) > 0;\
    \ });\r\n  sort(all(upper), [&](auto& i, auto& j) { return P[i].det(P[j]) > 0;\
    \ });\r\n  auto& I = lower;\r\n  I.insert(I.end(), all(origin));\r\n  I.insert(I.end(),\
    \ all(upper));\r\n  return I;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\
    \u5BFE\u3059\u308B argsort\r\ntemplate <typename T>\r\nvector<int> angle_sort(vector<pair<T,\
    \ T>>& P) {\r\n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\
    \n  return angle_sort<T>(tmp);\r\n}\r\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 5 \"geo/count_points_in_triangles.hpp\"\
    \n\n// \u70B9\u7FA4 A, B \u3092\u5165\u529B \uFF08Point<ll>\uFF09\n// query(i,j,k)\uFF1A\
    \u4E09\u89D2\u5F62 AiAjAk \u5185\u90E8\u306E Bl \u306E\u500B\u6570\uFF08\u975E\
    \u8CA0\uFF09\u3092\u8FD4\u3059\n// \u524D\u8A08\u7B97 O(N^2M)\u3001\u30AF\u30A8\
    \u30EA O(1)\n// https://codeforces.com/contest/13/problem/D\nstruct Count_Points_In_Triangles\
    \ {\n  using P = Point<ll>;\n  const int LIM = 1'000'000'000 + 10;\n  vc<P> A,\
    \ B;\n  vc<int> I, rk; // O \u304B\u3089\u898B\u305F\u504F\u89D2\u30BD\u30FC\u30C8\
    \u9806\u3092\u7BA1\u7406\n  vc<int> point; // A[i] \u3068\u4E00\u81F4\u3059\u308B\
    \ B[j] \u306E\u6570\u3048\u4E0A\u3052\n  vvc<int> seg;  // \u7DDA\u5206 A[i]A[j]\
    \ \u5185\u306B\u3042\u308B B[k] \u306E\u6570\u3048\u4E0A\u3052\n  vvc<int> tri;\
    \  // OA[i]A[j] \u5185\u90E8\u306B\u3042\u308B B[k] \u306E\u6570\u3048\u4E0A\u3052\
    \n  Count_Points_In_Triangles(vc<P> A, vc<P> B) : A(A), B(B) {\n    for (auto&&\
    \ p: A) assert(-LIM < min(p.x, p.y) && max(p.x, p.y) < LIM);\n    for (auto&&\
    \ p: B) assert(-LIM < min(p.x, p.y) && max(p.x, p.y) < LIM);\n    build();\n \
    \ }\n\n  int query(int i, int j, int k) {\n    i = rk[i], j = rk[j], k = rk[k];\n\
    \    if (i > j) swap(i, j);\n    if (j > k) swap(j, k);\n    if (i > j) swap(i,\
    \ j);\n    assert(i <= j && j <= k);\n\n    ll d = (A[j] - A[i]).det(A[k] - A[i]);\n\
    \    if (d == 0) return 0;\n    if (d > 0) { return tri[i][j] + tri[j][k] - tri[i][k]\
    \ - seg[i][k]; }\n    int x = tri[i][k] - tri[i][j] - tri[j][k];\n    return x\
    \ - seg[i][j] - seg[j][k] - point[j];\n  }\n\nprivate:\n  P take_origin() {\n\
    \    int N = len(A), M = len(B);\n    while (1) {\n      P O = P{-LIM, RNG(-LIM,\
    \ LIM)};\n      bool ok = 1;\n      FOR(i, N) FOR(j, N) {\n        if (A[i] ==\
    \ A[j]) continue;\n        if ((A[i] - O).det(A[j] - O) == 0) ok = 0;\n      }\n\
    \      FOR(i, N) FOR(j, M) {\n        if (A[i] == B[j]) continue;\n        if\
    \ ((A[i] - O).det(B[j] - O) == 0) ok = 0;\n      }\n      if (ok) return O;\n\
    \    }\n    return P{};\n  }\n\n  void build() {\n    P O = take_origin();\n \
    \   for (auto&& p: A) p = p - O;\n    for (auto&& p: B) p = p - O;\n    int N\
    \ = len(A), M = len(B);\n    I.resize(N), rk.resize(N);\n    iota(all(I), 0);\n\
    \    sort(all(I), [&](auto& a, auto& b) -> bool { return A[a].det(A[b]) > 0; });\n\
    \    FOR(i, N) rk[I[i]] = i;\n    A = rearrange(A, I);\n    point.assign(N, 0);\n\
    \    seg.assign(N, vc<int>(N));\n    tri.assign(N, vc<int>(N));\n\n    FOR(i,\
    \ N) FOR(j, M) if (A[i] == B[j])++ point[i];\n    FOR(i, N) FOR(j, i + 1, N) {\n\
    \      FOR(k, M) {\n        if (A[i].det(B[k]) <= 0) continue;\n        if (A[j].det(B[k])\
    \ >= 0) continue;\n        ll d = (B[k] - A[i]).det(A[j] - A[i]);\n        if\
    \ (d == 0) ++seg[i][j];\n        if (d < 0) ++tri[i][j];\n      }\n    }\n  }\n\
    };\n#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class\
    \ T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
    \  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
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
    \  fastio::rd(x.val);\n  assert(0 <= x.val && x.val < mod);\n}\ntemplate <int\
    \ mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107\
    \ = modint<1000000007>;\nusing modint998 = modint<998244353>;\n#line 2 \"nt/primetable.hpp\"\
    \n\ntemplate <typename T = int>\nvc<T> primetable(int LIM) {\n  ++LIM;\n  const\
    \ int S = 32768;\n  static int done = 2;\n  static vc<T> primes = {2}, sieve(S\
    \ + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S\
    \ + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n\
    \      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for (int j = i\
    \ * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1;\
    \ L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p, idx]:\
    \ cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n\
    \      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n\
    \  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 3 \"mod/powertable.hpp\"\n\r\n// a^0, ..., a^N\r\ntemplate <typename\
    \ mint>\r\nvc<mint> powertable_1(mint a, ll N) {\r\n  // table of a^i\r\n  vc<mint>\
    \ f(N + 1, 1);\r\n  FOR(i, N) f[i + 1] = a * f[i];\r\n  return f;\r\n}\r\n\r\n\
    // 0^e, ..., N^e\r\ntemplate <typename mint>\r\nvc<mint> powertable_2(ll e, ll\
    \ N) {\r\n  auto primes = primetable(N);\r\n  vc<mint> f(N + 1, 1);\r\n  f[0]\
    \ = mint(0).pow(e);\r\n  for (auto&& p: primes) {\r\n    if (p > N) break;\r\n\
    \    mint xp = mint(p).pow(e);\r\n    ll pp = p;\r\n    while (pp <= N) {\r\n\
    \      ll i = pp;\r\n      while (i <= N) {\r\n        f[i] *= xp;\r\n       \
    \ i += pp;\r\n      }\r\n      pp *= p;\r\n    }\r\n  }\r\n  return f;\r\n}\r\n\
    #line 8 \"test_atcoder/abc202_f.test.cpp\"\n\nusing mint = modint107;\n\nvoid\
    \ solve() {\n  LL(N);\n  using P = Point<ll>;\n  VEC(P, A, N);\n  Count_Points_In_Triangles\
    \ X(A, A);\n\n  vc<P> vecs;\n  FOR(i, N) FOR(j, N) vecs.eb(A[j] - A[i]);\n  auto\
    \ I = angle_sort(vecs);\n\n  vc<pair<int, int>> IJ;\n  for (auto&& k: I) {\n \
    \   auto [i, j] = divmod<int>(k, N);\n    if (i != j) IJ.eb(i, j);\n  }\n  vc<mint>\
    \ POW = powertable_1<mint>(2, N);\n\n  mint ANS = 0;\n  FOR(s, N) {\n    vv(mint,\
    \ dp, 2, N);\n    dp[0][s] = 1;\n    for (auto&& [i, j]: IJ) {\n      ll area\
    \ = (A[i] - A[s]).det(A[j] - A[s]);\n      FOR(sgn, 2) {\n        ll t = (sgn\
    \ + area) & 1;\n        int cnt = X.query(s, i, j);\n        dp[t][j] += POW[cnt]\
    \ * dp[sgn][i];\n      }\n    }\n    ANS += dp[0][s];\n  }\n  // 1 \u89D2\u5F62\
    \n  ANS -= mint(N);\n  // 2 \u89D2\u5F62\n  ANS -= mint(N * (N - 1) / 2);\n  print(ANS);\n\
    }\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc202/tasks/abc202_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"geo/count_points_in_triangles.hpp\"\
    \n#include \"geo/angle_sort.hpp\"\n#include \"mod/modint.hpp\"\n#include \"mod/powertable.hpp\"\
    \n\nusing mint = modint107;\n\nvoid solve() {\n  LL(N);\n  using P = Point<ll>;\n\
    \  VEC(P, A, N);\n  Count_Points_In_Triangles X(A, A);\n\n  vc<P> vecs;\n  FOR(i,\
    \ N) FOR(j, N) vecs.eb(A[j] - A[i]);\n  auto I = angle_sort(vecs);\n\n  vc<pair<int,\
    \ int>> IJ;\n  for (auto&& k: I) {\n    auto [i, j] = divmod<int>(k, N);\n   \
    \ if (i != j) IJ.eb(i, j);\n  }\n  vc<mint> POW = powertable_1<mint>(2, N);\n\n\
    \  mint ANS = 0;\n  FOR(s, N) {\n    vv(mint, dp, 2, N);\n    dp[0][s] = 1;\n\
    \    for (auto&& [i, j]: IJ) {\n      ll area = (A[i] - A[s]).det(A[j] - A[s]);\n\
    \      FOR(sgn, 2) {\n        ll t = (sgn + area) & 1;\n        int cnt = X.query(s,\
    \ i, j);\n        dp[t][j] += POW[cnt] * dp[sgn][i];\n      }\n    }\n    ANS\
    \ += dp[0][s];\n  }\n  // 1 \u89D2\u5F62\n  ANS -= mint(N);\n  // 2 \u89D2\u5F62\
    \n  ANS -= mint(N * (N - 1) / 2);\n  print(ANS);\n}\n\nsigned main() {\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - geo/count_points_in_triangles.hpp
  - geo/angle_sort.hpp
  - geo/base.hpp
  - random/base.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/powertable.hpp
  - nt/primetable.hpp
  isVerificationFile: true
  path: test_atcoder/abc202_f.test.cpp
  requiredBy: []
  timestamp: '2023-11-15 20:12:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_atcoder/abc202_f.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc202_f.test.cpp
- /verify/test_atcoder/abc202_f.test.cpp.html
title: test_atcoder/abc202_f.test.cpp
---