---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/maximum_matching_of_line_graph.hpp
    title: graph/maximum_matching_of_line_graph.hpp
  - icon: ':x:'
    path: graph/maximum_matching_size.hpp
    title: graph/maximum_matching_size.hpp
  - icon: ':x:'
    path: linalg/matrix_rank.hpp
    title: linalg/matrix_rank.hpp
  - icon: ':x:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':x:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':x:'
    path: random/random_graph.hpp
    title: random/random_graph.hpp
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
  bundledCode: "#line 1 \"test/mytest/matching_line_graph.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#pragma GCC optimize(\"\
    Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
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
    \ <unistd.h>\r\n\r\nnamespace fastio {\r\nstruct Pre {\r\n  char num[10000][4];\r\
    \n  constexpr Pre() : num() {\r\n    for (int i = 0; i < 10000; i++) {\r\n   \
    \   int n = i;\r\n      for (int j = 3; j >= 0; j--) {\r\n        num[i][j] =\
    \ n % 10 | '0';\r\n        n /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr\
    \ pre;\r\n\r\ntemplate <typename T>\r\nstruct has_read_method {\r\n  template\
    \ <typename U>\r\n  static std::true_type test(decltype(&U::read) *);\r\n  template\
    \ <typename>\r\n  static std::false_type test(...);\r\n  using type = decltype(test<T>(nullptr));\r\
    \n  static constexpr bool value = type::value;\r\n};\r\n\r\ntemplate <typename\
    \ T>\r\nstruct has_print_method {\r\n  template <typename U>\r\n  static std::true_type\
    \ test(decltype(&U::print) *);\r\n  template <typename>\r\n  static std::false_type\
    \ test(...);\r\n  using type = decltype(test<T>(nullptr));\r\n  static constexpr\
    \ bool value = type::value;\r\n};\r\n\r\nstruct Scanner {\r\n  FILE *fp;\r\n \
    \ char line[(1 << 15) + 1];\r\n  size_t st = 0, ed = 0;\r\n  void reread() {\r\
    \n    memmove(line, line + st, ed - st);\r\n    ed -= st;\r\n    st = 0;\r\n \
    \   ed += fread(line + ed, 1, (1 << 15) - ed, fp);\r\n    line[ed] = '\\0';\r\n\
    \  }\r\n  void succ() {\r\n    while (true) {\r\n      if (st == ed) {\r\n   \
    \     reread();\r\n        if (st == ed) return;\r\n      }\r\n      while (st\
    \ != ed && isspace(line[st])) st++;\r\n      if (st != ed) break;\r\n    }\r\n\
    \    if (ed - st <= 100) {\r\n      bool sep = false;\r\n      for (size_t i =\
    \ st; i < ed; i++) {\r\n        if (isspace(line[i])) {\r\n          sep = true;\r\
    \n          break;\r\n        }\r\n      }\r\n      if (!sep) reread();\r\n  \
    \  }\r\n    return;\r\n  }\r\n\r\n  void rd(char &c) {\r\n    succ();\r\n    c\
    \ = line[st++];\r\n  }\r\n\r\n  void rd(string &x) {\r\n    x.clear();\r\n   \
    \ succ();\r\n    while (true) {\r\n      size_t sz = 0;\r\n      while (st + sz\
    \ < ed && !isspace(line[st + sz])) sz++;\r\n      x.append(line + st, sz);\r\n\
    \      st += sz;\r\n      if (!sz || st != ed) break;\r\n      reread();\r\n \
    \   }\r\n  }\r\n\r\n  template <typename T>\r\n  void rd_integer(T &x) {\r\n \
    \   succ();\r\n    bool minus = 0;\r\n    char c = line[st++];\r\n    if constexpr\
    \ (is_signed<T>::value || is_same_v<T, i128>) {\r\n      if (c == '-') { minus\
    \ = 1, c = line[st++]; }\r\n    }\r\n    x = 0;\r\n    while (c >= '0') { x =\
    \ x * 10 + (c & 15), c = line[st++]; }\r\n    if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n      if (minus) x = -x;\r\n    }\r\n  }\r\n\r\n\
    \  template <typename T>\r\n  void rd_real(T &x) {\r\n    string s;\r\n    rd(s);\r\
    \n    x = stod(s);\r\n  }\r\n\r\n  template <typename T>\r\n  typename enable_if<has_read_method<T>::value,\
    \ void>::type rd(T &x) {\r\n    x.read();\r\n  }\r\n\r\n  void rd(int &x) { rd_integer(x);\
    \ }\r\n  void rd(ll &x) { rd_integer(x); }\r\n  void rd(i128 &x) { rd_integer(x);\
    \ }\r\n  void rd(u32 &x) { rd_integer(x); }\r\n  void rd(u64 &x) { rd_integer(x);\
    \ }\r\n  void rd(u128 &x) { rd_integer(x); }\r\n  void rd(double &x) { rd_real(x);\
    \ }\r\n  void rd(long double &x) { rd_real(x); }\r\n  void rd(f128 &x) { rd_real(x);\
    \ }\r\n  template <class T, class U>\r\n  void rd(pair<T, U> &p) {\r\n    return\
    \ rd(p.first), rd(p.second);\r\n  }\r\n  template <size_t N = 0, typename T>\r\
    \n  void rd_tuple(T &t) {\r\n    if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n      auto &x = std::get<N>(t);\r\n      rd(x);\r\n      rd_tuple<N + 1>(t);\r\
    \n    }\r\n  }\r\n  template <class... T>\r\n  void rd(tuple<T...> &tpl) {\r\n\
    \    rd_tuple(tpl);\r\n  }\r\n  template <class T>\r\n  void rd(vc<T> &x) {\r\n\
    \    for (auto &d: x) rd(d);\r\n  }\r\n  template <size_t N = 0, typename T>\r\
    \n  void rd(array<T, N> &x) {\r\n    for (auto &d: x) rd(d);\r\n  }\r\n  Scanner(FILE\
    \ *fp) : fp(fp) {}\r\n};\r\n\r\nstruct Printer {\r\n  Printer(FILE *_fp) : fp(_fp)\
    \ {}\r\n  ~Printer() { flush(); }\r\n\r\n  static constexpr size_t SIZE = 1 <<\
    \ 15;\r\n  FILE *fp;\r\n  char line[SIZE], out[100];\r\n  size_t pos = 0;\r\n\
    \  void flush() {\r\n    fwrite(line, 1, pos, fp);\r\n    pos = 0;\r\n  }\r\n\r\
    \n  void wt(const char val) {\r\n    if (pos == SIZE) flush();\r\n    line[pos++]\
    \ = val;\r\n  }\r\n  void wt(const string &s) {\r\n    for (char c: s) wt(c);\r\
    \n  }\r\n  void wt(const char *s) {\r\n    size_t len = strlen(s);\r\n    for\
    \ (size_t i = 0; i < len; i++) wt(s[i]);\r\n  }\r\n\r\n  template <typename T>\r\
    \n  void wt_integer(T x) {\r\n    if (pos > SIZE - 100) flush();\r\n    if (x\
    \ < 0) { line[pos++] = '-', x = -x; }\r\n    int outi;\r\n    for (outi = 96;\
    \ x >= 10000; outi -= 4) {\r\n      memcpy(out + outi, pre.num[x % 10000], 4);\r\
    \n      x /= 10000;\r\n    }\r\n    if (x >= 1000) {\r\n      memcpy(line + pos,\
    \ pre.num[x], 4), pos += 4;\r\n    } else if (x >= 100) {\r\n      memcpy(line\
    \ + pos, pre.num[x] + 1, 3), pos += 3;\r\n    } else if (x >= 10) {\r\n      int\
    \ q = (x * 103) >> 10;\r\n      line[pos] = q | '0';\r\n      line[pos + 1] =\
    \ (x - q * 10) | '0';\r\n      pos += 2;\r\n    } else\r\n      line[pos++] =\
    \ x | '0';\r\n    memcpy(line + pos, out + outi + 4, 96 - outi);\r\n    pos +=\
    \ 96 - outi;\r\n  }\r\n\r\n  template <typename T>\r\n  void wt_real(T x) {\r\n\
    \    ostringstream oss;\r\n    oss << fixed << setprecision(15) << double(x);\r\
    \n    string s = oss.str();\r\n    wt(s);\r\n  }\r\n\r\n  template <typename T>\r\
    \n  typename enable_if<has_print_method<T>::value, void>::type wt(T x) {\r\n \
    \   x.print();\r\n  }\r\n\r\n  void wt(bool x) { wt_integer(int(x)); }\r\n  void\
    \ wt(int x) { wt_integer(x); }\r\n  void wt(ll x) { wt_integer(x); }\r\n  void\
    \ wt(i128 x) { wt_integer(x); }\r\n  void wt(u32 x) { wt_integer(x); }\r\n  void\
    \ wt(u64 x) { wt_integer(x); }\r\n  void wt(u128 x) { wt_integer(x); }\r\n  void\
    \ wt(double x) { wt_real(x); }\r\n  void wt(long double x) { wt_real(x); }\r\n\
    \  void wt(f128 x) { wt_real(x); }\r\n\r\n  template <class T, class U>\r\n  void\
    \ wt(const pair<T, U> val) {\r\n    wt(val.first);\r\n    wt(' ');\r\n    wt(val.second);\r\
    \n  }\r\n  template <size_t N = 0, typename T>\r\n  void wt_tuple(const T t) {\r\
    \n    if constexpr (N < std::tuple_size<T>::value) {\r\n      if constexpr (N\
    \ > 0) { wt(' '); }\r\n      const auto x = std::get<N>(t);\r\n      wt(x);\r\n\
    \      wt_tuple<N + 1>(t);\r\n    }\r\n  }\r\n  template <class... T>\r\n  void\
    \ wt(tuple<T...> tpl) {\r\n    wt_tuple(tpl);\r\n  }\r\n  template <class T, size_t\
    \ S>\r\n  void wt(const array<T, S> val) {\r\n    auto n = val.size();\r\n   \
    \ for (size_t i = 0; i < n; i++) {\r\n      if (i) wt(' ');\r\n      wt(val[i]);\r\
    \n    }\r\n  }\r\n  template <class T>\r\n  void wt(const vector<T> val) {\r\n\
    \    auto n = val.size();\r\n    for (size_t i = 0; i < n; i++) {\r\n      if\
    \ (i) wt(' ');\r\n      wt(val[i]);\r\n    }\r\n  }\r\n};\r\nScanner scanner =\
    \ Scanner(stdin);\r\nPrinter printer = Printer(stdout);\r\nvoid flush() { printer.flush();\
    \ }\r\nvoid print() { printer.wt('\\n'); }\r\ntemplate <class Head, class... Tail>\r\
    \nvoid print(Head &&head, Tail &&... tail) {\r\n  printer.wt(head);\r\n  if (sizeof...(Tail))\
    \ printer.wt(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid read()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid read(Head &head, Tail &...\
    \ tail) {\r\n  scanner.rd(head);\r\n  read(tail...);\r\n}\r\n} // namespace fastio\r\
    \nusing fastio::print;\r\nusing fastio::flush;\r\nusing fastio::read;\r\n\r\n\
    #define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)\
    \      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)\
    \   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)  \
    \    \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge\
    \ {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
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
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
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
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid\
    \ = 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e)\
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
    #line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"random/random_graph.hpp\"\
    \n\ntemplate <int DIRECTED>\nGraph<int, DIRECTED> random_graph(int n, bool simple)\
    \ {\n  Graph<int, DIRECTED> G(n);\n  vc<pi> cand;\n  FOR(a, n) FOR(b, n) {\n \
    \   if (simple && a == b) continue;\n    if (!DIRECTED && a > b) continue;\n \
    \   cand.eb(a, b);\n  }\n  int m = RNG(0, len(cand) + 1);\n  set<int> ss;\n  FOR(m)\
    \ {\n    while (1) {\n      int i = RNG(0, len(cand));\n      if (simple && ss.count(i))\
    \ continue;\n      ss.insert(i);\n      auto [a, b] = cand[i];\n      G.add(a,\
    \ b);\n      break;\n    }\n  }\n  G.build();\n  return G;\n}\n#line 2 \"mod/modint61.hpp\"\
    \n\r\nstruct modint61 {\r\n  static constexpr u64 mod = (1ULL << 61) - 1;\r\n\
    \  u64 val;\r\n  constexpr modint61() : val(0ULL) {}\r\n  constexpr modint61(u32\
    \ x) : val(x) {}\r\n  constexpr modint61(u64 x) : val(x % mod) {}\r\n  constexpr\
    \ modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod)) : x) {}\r\n  constexpr\
    \ modint61(ll x)\r\n      : val(((x %= static_cast<ll>(mod)) < 0) ? (x + static_cast<ll>(mod))\r\
    \n                                              : x) {}\r\n  static constexpr\
    \ u64 get_mod() { return mod; }\r\n  modint61 &operator+=(const modint61 &a) {\r\
    \n    val = ((val += a.val) >= mod) ? (val - mod) : val;\r\n    return *this;\r\
    \n  }\r\n  modint61 &operator-=(const modint61 &a) {\r\n    val = ((val -= a.val)\
    \ >= mod) ? (val + mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const\
    \ modint61 &a) {\r\n    const unsigned __int128 y = static_cast<unsigned __int128>(val)\
    \ * a.val;\r\n    val = (y >> 61) + (y & mod);\r\n    val = (val >= mod) ? (val\
    \ - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator/=(const modint61\
    \ &a) { return (*this *= a.inverse()); }\r\n  modint61 operator+(const modint61\
    \ &p) const { return modint61(*this) += p; }\r\n  modint61 operator-(const modint61\
    \ &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const modint61\
    \ &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const modint61\
    \ &p) const { return modint61(*this) /= p; }\r\n  bool operator==(const modint61\
    \ &p) const { return val == p.val; }\r\n  bool operator!=(const modint61 &p) const\
    \ { return val != p.val; }\r\n  modint61 inverse() const {\r\n    ll a = val,\
    \ b = mod, u = 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\n   \
    \   swap(a -= t * b, b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\
    \n  }\r\n  modint61 pow(ll n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1),\
    \ mul(val);\r\n    while (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul\
    \ *= mul, n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n#ifdef FASTIO\r\n  void\
    \ write() { fastio::wt(val); }\r\n  void read() {\r\n    ll x;\r\n    fastio::read(x);\r\
    \n    val = (val >= 0 ? val % mod : (mod - (-val) % mod) % mod);\r\n  }\r\n#endif\r\
    \n};\n#line 1 \"linalg/matrix_rank.hpp\"\ntemplate <typename T>\nint matrix_rank(const\
    \ int n, const int m, vc<vc<T>> a) {\n  int rk = 0;\n  FOR(j, m) {\n    if (rk\
    \ == n) break;\n    if (a[rk][j] == 0) {\n      FOR3(i, rk + 1, n) if (a[i][j]\
    \ != T(0)) {\n        swap(a[rk], a[i]);\n        break;\n      }\n    }\n   \
    \ if (a[rk][j] == 0) continue;\n    T c = T(1) / a[rk][j];\n    FOR(k, j, m) a[rk][k]\
    \ *= c;\n    FOR(i, rk + 1, n) {\n      T c = a[i][j];\n      FOR3(k, j, m) {\
    \ a[i][k] -= a[rk][k] * c; }\n    }\n    ++rk;\n  }\n  return rk;\n}\n#line 4\
    \ \"graph/maximum_matching_size.hpp\"\n\ntemplate <typename GT>\nint maximum_matching_size(GT&\
    \ G) {\n  static_assert(!GT::is_directed);\n  using mint = modint61;\n  int N\
    \ = G.N;\n  vv(mint, tutte, N, N);\n  for (auto&& e: G.edges) {\n    mint x =\
    \ RNG(mint::get_mod());\n    int i = e.frm, j = e.to;\n    tutte[i][j] += x;\n\
    \    tutte[j][i] -= x;\n  }\n  return matrix_rank(N, N, tutte) / 2;\n}\n#line\
    \ 2 \"graph/maximum_matching_of_line_graph.hpp\"\n\n// \u540C\u3058\u9802\u70B9\
    \u306B\u63A5\u7D9A\u3059\u308B 2 \u8FBA\u3092\u30DE\u30C3\u30C1\u3067\u304D\u308B\
    \ntemplate <typename GT>\nvc<pair<int, int>> maximum_matching_of_line_graph(GT&\
    \ G) {\n  assert(!GT::is_directed);\n  assert(G.is_prepared());\n  const int N\
    \ = G.N, M = G.M;\n  vc<pair<int, int>> ANS;\n  vc<int> V;\n  vc<int> par(N, -1);\
    \ // eid\n  {\n    vc<int> done(N);\n    FOR(v, N) {\n      if (done[v]) continue;\n\
    \      int cnt = 0;\n      auto dfs = [&](auto& dfs, int v, int p) -> void {\n\
    \        V.eb(v);\n        par[v] = p;\n        done[v] = 1;\n        for (auto&&\
    \ e: G[v]) {\n          ++cnt;\n          if (done[e.to]) continue;\n        \
    \  dfs(dfs, e.to, v);\n        }\n      };\n      dfs(dfs, v, -1);\n    }\n  }\n\
    \  vc<int> ord(N);\n  FOR(i, N) ord[V[i]] = i;\n  vc<int> done(M);\n  FOR_R(i,\
    \ N) {\n    int v = V[i];\n    vc<int> down;\n    int up = -1;\n    for (auto&&\
    \ e: G[v]) {\n      if (done[e.id]) continue;\n      if (up == -1 && e.to == par[v])\
    \ up = e.id;\n      if (ord[e.to] > ord[v]) down.eb(e.id);\n    }\n    while (len(down)\
    \ >= 2) {\n      auto i = POP(down);\n      auto j = POP(down);\n      ANS.eb(i,\
    \ j);\n      done[i] = done[j] = 1;\n    }\n    if (len(down) == 0) continue;\n\
    \    if (up != -1) {\n      int x = up;\n      int y = down[0];\n      done[x]\
    \ = done[y] = 1;\n      ANS.eb(x, y);\n    }\n  }\n  return ANS;\n}\n#line 7 \"\
    test/mytest/matching_line_graph.test.cpp\"\n\nvoid test() {\n  FOR(100) {\n  \
    \  FOR(n, 10) {\n      auto G = random_graph<false>(n, 1);\n      int m = G.M;\n\
    \      Graph<int, 0> LG(m);\n      FOR(i, m) FOR(j, i) if (i != j) {\n       \
    \ auto ei = G.edges[i];\n        auto ej = G.edges[j];\n        bool ok = 0;\n\
    \        if (ei.frm == ej.frm) ok = 1;\n        if (ei.frm == ej.to) ok = 1;\n\
    \        if (ei.to == ej.frm) ok = 1;\n        if (ei.to == ej.to) ok = 1;\n \
    \       if (ok) LG.add(i, j);\n      }\n      LG.build();\n      vc<pair<int,\
    \ int>> res = maximum_matching_of_line_graph(G);\n      assert(len(res) == maximum_matching_size(LG));\n\
    \      vc<int> done(m);\n      for (auto&& [a, b]: res) {\n        assert(!done[a]);\n\
    \        assert(!done[b]);\n        done[a] = done[b] = 1;\n        auto ei =\
    \ G.edges[a];\n        auto ej = G.edges[b];\n        bool ok = 0;\n        if\
    \ (ei.frm == ej.frm) ok = 1;\n        if (ei.frm == ej.to) ok = 1;\n        if\
    \ (ei.to == ej.frm) ok = 1;\n        if (ei.to == ej.to) ok = 1;\n        assert(ok);\n\
    \      }\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\n\
    signed main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/random_graph.hpp\"\n#include \"\
    graph/maximum_matching_size.hpp\"\n#include \"graph/maximum_matching_of_line_graph.hpp\"\
    \n\nvoid test() {\n  FOR(100) {\n    FOR(n, 10) {\n      auto G = random_graph<false>(n,\
    \ 1);\n      int m = G.M;\n      Graph<int, 0> LG(m);\n      FOR(i, m) FOR(j,\
    \ i) if (i != j) {\n        auto ei = G.edges[i];\n        auto ej = G.edges[j];\n\
    \        bool ok = 0;\n        if (ei.frm == ej.frm) ok = 1;\n        if (ei.frm\
    \ == ej.to) ok = 1;\n        if (ei.to == ej.frm) ok = 1;\n        if (ei.to ==\
    \ ej.to) ok = 1;\n        if (ok) LG.add(i, j);\n      }\n      LG.build();\n\
    \      vc<pair<int, int>> res = maximum_matching_of_line_graph(G);\n      assert(len(res)\
    \ == maximum_matching_size(LG));\n      vc<int> done(m);\n      for (auto&& [a,\
    \ b]: res) {\n        assert(!done[a]);\n        assert(!done[b]);\n        done[a]\
    \ = done[b] = 1;\n        auto ei = G.edges[a];\n        auto ej = G.edges[b];\n\
    \        bool ok = 0;\n        if (ei.frm == ej.frm) ok = 1;\n        if (ei.frm\
    \ == ej.to) ok = 1;\n        if (ei.to == ej.frm) ok = 1;\n        if (ei.to ==\
    \ ej.to) ok = 1;\n        assert(ok);\n      }\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/random_graph.hpp
  - graph/base.hpp
  - random/base.hpp
  - graph/maximum_matching_size.hpp
  - mod/modint61.hpp
  - linalg/matrix_rank.hpp
  - graph/maximum_matching_of_line_graph.hpp
  isVerificationFile: true
  path: test/mytest/matching_line_graph.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 18:59:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/matching_line_graph.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/matching_line_graph.test.cpp
- /verify/test/mytest/matching_line_graph.test.cpp.html
title: test/mytest/matching_line_graph.test.cpp
---
