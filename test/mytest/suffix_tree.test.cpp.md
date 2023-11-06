---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':x:'
    path: alg/monoid/min_idx.hpp
    title: alg/monoid/min_idx.hpp
  - icon: ':x:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':x:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
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
    path: seq/cartesian_tree.hpp
    title: seq/cartesian_tree.hpp
  - icon: ':x:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  - icon: ':x:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
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
    - https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g
  bundledCode: "#line 1 \"test/mytest/suffix_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    \ yes(!t); }\r\n#line 4 \"test/mytest/suffix_tree.test.cpp\"\n\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 1 \"string/suffix_tree.hpp\"\
    \n\n#line 2 \"string/suffix_array.hpp\"\n\n#line 2 \"alg/monoid/min.hpp\"\n\r\n\
    template <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return min(x,\
    \ y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 1 \"ds/sparse_table/sparse_table.hpp\"\n\
    \n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\u3092\
    \u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\ntemplate\
    \ <class Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using X = typename\
    \ MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table() {}\n  Sparse_Table(int\
    \ n) { build(n); }\n  template <typename F>\n  Sparse_Table(int n, F f) {\n  \
    \  build(n, f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n    FOR(i,\
    \ n) dat[0][i] = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i])\
    \ - (1 << i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j]\
    \ = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) {\n    if (L == R) return MX::unit();\n    if (R == L + 1) return\
    \ dat[0][L];\n    int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R\
    \ - (1 << k)]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) {\n    assert(0 <= L && L <= n && check(MX::unit()));\n    if (L == n) return\
    \ n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int k = (ok\
    \ + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n    \
    \  if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) {\n    assert(0 <= R && R <= n && check(MX::unit()));\n\
    \    if (R == 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};\n#line\
    \ 5 \"string/suffix_array.hpp\"\n\n// \u8F9E\u66F8\u9806 i \u756A\u76EE\u306E\
    \ suffix \u304C j \u6587\u5B57\u76EE\u59CB\u307E\u308A\u3067\u3042\u308B\u3068\
    \u304D\u3001\n// SA[i] = j, ISA[j] = i\n// |S|>0 \u3092\u524D\u63D0\uFF08\u305D\
    \u3046\u3067\u306A\u3044\u5834\u5408 dummy \u6587\u5B57\u3092\u8FFD\u52A0\u3057\
    \u3066\u5229\u7528\u305B\u3088\uFF09\ntemplate <bool USE_LCP_QUERY = 0>\nstruct\
    \ Suffix_Array {\n  vc<int> SA;\n  vc<int> ISA;\n  vc<int> LCP;\n  Sparse_Table<Monoid_Min<int>>\
    \ seg;\n  // DisjointSparse<Monoid_Min<int>> seg;\n\n  Suffix_Array(string& s)\
    \ {\n    assert(len(s) > 0);\n    char first = 127, last = 0;\n    for (auto&&\
    \ c: s) {\n      chmin(first, c);\n      chmax(last, c);\n    }\n    SA = calc_suffix_array(s,\
    \ first, last);\n    calc_LCP(s);\n    if (USE_LCP_QUERY) seg.build(LCP);\n  }\n\
    \n  Suffix_Array(vc<int>& s) {\n    assert(len(s) > 0);\n    SA = calc_suffix_array(s);\n\
    \    calc_LCP(s);\n    if (USE_LCP_QUERY) seg.build(LCP);\n  }\n\n  // lcp(S[i:],\
    \ S[j:])\n  int lcp(int i, int j) {\n    static_assert(USE_LCP_QUERY);\n    int\
    \ n = len(SA);\n    if (i == n || j == n) return 0;\n    if (i == j) return n\
    \ - i;\n    i = ISA[i], j = ISA[j];\n    if (i > j) swap(i, j);\n    return seg.prod(i,\
    \ j);\n  }\n\n  // S[i:] \u3068\u306E lcp \u304C n \u4EE5\u4E0A\u3067\u3042\u308B\
    \u3088\u3046\u306A\u534A\u958B\u533A\u9593\n  pair<int, int> lcp_range(int i,\
    \ int n) {\n    static_assert(USE_LCP_QUERY);\n    i = ISA[i];\n    int a = seg.min_left([&](auto\
    \ e) -> bool { return e >= n; }, i);\n    int b = seg.max_right([&](auto e) ->\
    \ bool { return e >= n; }, i);\n    return {a, b + 1};\n  }\n\n  // -1: S[L1:R1)\
    \ < S[L2, R2)\n  //  0: S[L1:R1) = S[L2, R2)\n  // +1: S[L1:R1) > S[L2, R2)\n\
    \  int compare(int L1, int R1, int L2, int R2) {\n    int N = len(SA);\n    int\
    \ n1 = R1 - L1, n2 = R2 - L2;\n    int n = lcp(L1, L2);\n    if (n == n1 && n\
    \ == n2) return 0;\n    if (n == n1) return -1;\n    if (n == n2) return 1;\n\
    \    return (ISA[L1 + n] > ISA[L2 + n] ? 1 : -1);\n  }\n\nprivate:\n  void induced_sort(const\
    \ vc<int>& vect, int val_range, vc<int>& SA,\n                    const vc<bool>&\
    \ sl, const vc<int>& lms_idx) {\n    vc<int> l(val_range, 0), r(val_range, 0);\n\
    \    for (int c: vect) {\n      if (c + 1 < val_range) ++l[c + 1];\n      ++r[c];\n\
    \    }\n    partial_sum(l.begin(), l.end(), l.begin());\n    partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    fill(SA.begin(), SA.end(), -1);\n    for (int i =\
    \ (int)lms_idx.size() - 1; i >= 0; --i)\n      SA[--r[vect[lms_idx[i]]]] = lms_idx[i];\n\
    \    for (int i: SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i - 1]]++] = i\
    \ - 1;\n    fill(r.begin(), r.end(), 0);\n    for (int c: vect) ++r[c];\n    partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1;\
    \ --k, i = SA[k])\n      if (i >= 1 && !sl[i - 1]) { SA[--r[vect[i - 1]]] = i\
    \ - 1; }\n  }\n\n  vc<int> SA_IS(const vc<int>& vect, int val_range) {\n    const\
    \ int n = vect.size();\n    vc<int> SA(n), lms_idx;\n    vc<bool> sl(n);\n   \
    \ sl[n - 1] = false;\n    for (int i = n - 2; i >= 0; --i) {\n      sl[i] = (vect[i]\
    \ > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));\n      if (sl[i] &&\
    \ !sl[i + 1]) lms_idx.push_back(i + 1);\n    }\n    reverse(lms_idx.begin(), lms_idx.end());\n\
    \    induced_sort(vect, val_range, SA, sl, lms_idx);\n    vc<int> new_lms_idx(lms_idx.size()),\
    \ lms_vec(lms_idx.size());\n    for (int i = 0, k = 0; i < n; ++i)\n      if (!sl[SA[i]]\
    \ && SA[i] >= 1 && sl[SA[i] - 1]) {\n        new_lms_idx[k++] = SA[i];\n     \
    \ }\n    int cur = 0;\n    SA[n - 1] = cur;\n    for (size_t k = 1; k < new_lms_idx.size();\
    \ ++k) {\n      int i = new_lms_idx[k - 1], j = new_lms_idx[k];\n      if (vect[i]\
    \ != vect[j]) {\n        SA[j] = ++cur;\n        continue;\n      }\n      bool\
    \ flag = false;\n      for (int a = i + 1, b = j + 1;; ++a, ++b) {\n        if\
    \ (vect[a] != vect[b]) {\n          flag = true;\n          break;\n        }\n\
    \        if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {\n          flag\
    \ = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));\n          break;\n   \
    \     }\n      }\n      SA[j] = (flag ? ++cur : cur);\n    }\n    for (size_t\
    \ i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];\n    if (cur +\
    \ 1 < (int)lms_idx.size()) {\n      auto lms_SA = SA_IS(lms_vec, cur + 1);\n \
    \     for (size_t i = 0; i < lms_idx.size(); ++i) {\n        new_lms_idx[i] =\
    \ lms_idx[lms_SA[i]];\n      }\n    }\n    induced_sort(vect, val_range, SA, sl,\
    \ new_lms_idx);\n    return SA;\n  }\n\n  vc<int> calc_suffix_array(const string&\
    \ s, const char first = 'a',\n                            const char last = 'z')\
    \ {\n    vc<int> vect(s.size() + 1);\n    copy(begin(s), end(s), begin(vect));\n\
    \    for (auto& x: vect) x -= (int)first - 1;\n    vect.back() = 0;\n    auto\
    \ ret = SA_IS(vect, (int)last - (int)first + 2);\n    ret.erase(ret.begin());\n\
    \    return ret;\n  }\n\n  vc<int> calc_suffix_array(const vc<int>& s) {\n   \
    \ vc<int> ss = s;\n    UNIQUE(ss);\n\n    vc<int> vect(s.size() + 1);\n    copy(all(s),\
    \ vect.begin());\n    for (auto& x: vect) x = LB(ss, x) + 1;\n    vect.back()\
    \ = 0;\n    auto ret = SA_IS(vect, MAX(vect) + 2);\n    ret.erase(ret.begin());\n\
    \    return ret;\n  }\n\n  template <typename STRING>\n  void calc_LCP(const STRING&\
    \ s) {\n    int n = s.size(), k = 0;\n    ISA.resize(n);\n    LCP.resize(n);\n\
    \    for (int i = 0; i < n; i++) ISA[SA[i]] = i;\n    for (int i = 0; i < n; i++,\
    \ k ? k-- : 0) {\n      if (ISA[i] == n - 1) {\n        k = 0;\n        continue;\n\
    \      }\n      int j = SA[ISA[i] + 1];\n      while (i + k < n && j + k < n &&\
    \ s[i + k] == s[j + k]) k++;\n      LCP[ISA[i]] = k;\n    }\n    LCP.resize(n\
    \ - 1);\n  }\n};\n#line 1 \"seq/cartesian_tree.hpp\"\n/*\r\n\u8F9E\u66F8\u9806\
    \u3067\u9AD8\u3055\u3092 unique \u3057\u3066\u3001\u6728\u306B\u3057\u3066\u3044\
    \u308B\u3002\r\n\u6975\u5927\u9577\u65B9\u5F62\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\
    \u3067\u7DDA\u5F62\u6642\u9593\u69CB\u7BC9\u3002\r\n*/\r\ntemplate <typename T,\
    \ bool IS_MIN>\r\nstruct CartesianTree {\r\n  int n;\r\n  vc<T>& A;\r\n  vc<pair<int,\
    \ int>> range;\r\n  vc<int> lch, rch, par;\r\n  int root;\r\n\r\n  CartesianTree(vc<T>&\
    \ A) : n(len(A)), A(A) {\r\n    range.assign(n, {-1, -1});\r\n    lch.assign(n,\
    \ -1);\r\n    rch.assign(n, -1);\r\n    par.assign(n, -1);\r\n    if (n == 1)\
    \ {\r\n      range[0] = {0, 1};\r\n      root = 0;\r\n      return;\r\n    }\r\
    \n    auto is_sm = [&](int i, int j) -> bool {\r\n      if (IS_MIN) return (A[i]\
    \ < A[j]) || (A[i] == A[j] && i < j);\r\n      return (A[i] > A[j]) || (A[i] ==\
    \ A[j] && i < j);\r\n    };\r\n    vc<int> st;\r\n    FOR(i, n) {\r\n      while\
    \ (!st.empty() && is_sm(i, st.back())) {\r\n        lch[i] = st.back();\r\n  \
    \      st.pop_back();\r\n      }\r\n      range[i].fi = (st.empty() ? 0 : st.back()\
    \ + 1);\r\n      st.eb(i);\r\n    }\r\n    st.clear();\r\n    FOR_R(i, n) {\r\n\
    \      while (!st.empty() && is_sm(i, st.back())) {\r\n        rch[i] = st.back();\r\
    \n        st.pop_back();\r\n      }\r\n      range[i].se = (st.empty() ? n : st.back());\r\
    \n      st.eb(i);\r\n    }\r\n    FOR(i, n) if (lch[i] != -1) par[lch[i]] = i;\r\
    \n    FOR(i, n) if (rch[i] != -1) par[rch[i]] = i;\r\n    FOR(i, n) if (par[i]\
    \ == -1) root = i;\r\n  }\r\n\r\n  // (l, r, h)\r\n  tuple<int, int, T> maximum_rectangle(int\
    \ i) {\r\n    auto [l, r] = range[i];\r\n    return {l, r, A[i]};\r\n  }\r\n\r\
    \n  // (l, r, h)\r\n  T max_rectangle_area() {\r\n    assert(IS_MIN);\r\n    T\
    \ res = 0;\r\n    FOR(i, n) {\r\n      auto [l, r, h] = maximum_rectangle(i);\r\
    \n      chmax(res, (r - l) * h);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  ll\
    \ count_subrectangle(bool baseline) {\r\n    assert(IS_MIN);\r\n    ll res = 0;\r\
    \n    FOR(i, n) {\r\n      auto [l, r, h] = maximum_rectangle(i);\r\n      ll\
    \ x = (baseline ? h : h * (h + 1) / 2);\r\n      res += x * (i - l + 1) * (r -\
    \ i);\r\n    }\r\n    return res;\r\n  }\r\n};\r\n#line 2 \"graph/base.hpp\"\n\
    \ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  static\
    \ constexpr bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n\
    \  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n\
    \  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool\
    \ prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph*\
    \ G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n    int l, r;\n\
    \  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph() : N(0), M(0),\
    \ prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void build(int\
    \ n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n    indptr.clear();\n\
    \    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n\
    \  }\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  //\
    \ wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1,\
    \ wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n  \
    \  for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n\n  void build() {\n\
    \    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
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
    #line 5 \"string/suffix_tree.hpp\"\n\n// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g\n\
    // \u5404\u30CE\u30FC\u30C9\u306F\u3001suffix array \u3067\u306E\u9577\u65B9\u5F62\
    \u9818\u57DF\u3068\u898B\u306A\u3057\u3066\u3001\n// \u30B0\u30E9\u30D5\u304A\u3088\
    \u3073\u3001\u9818\u57DF\u30C7\u30FC\u30BF\u3092\u4F5C\u308B\u3002\n// sample:\
    \ test/my_test/suffix_tree.test.cpp\ntemplate <typename SUFFIX>\npair<Graph<int,\
    \ 1>, vc<tuple<int, int, int, int>>> suffix_tree(SUFFIX& X) {\n  auto SA = X.SA;\n\
    \  auto ISA = X.ISA;\n  auto LCP = X.LCP;\n\n  vc<tuple<int, int, int, int>> dat;\n\
    \  vc<pair<int, int>> edges;\n\n  int N = len(SA);\n  if (N == 1) {\n    Graph<int,\
    \ 1> G(2);\n    G.add(0, 1);\n    G.build();\n    dat.eb(0, 1, 0, 0), dat.eb(0,\
    \ 1, 0, 1);\n    return {G, dat};\n  }\n\n  dat.eb(0, N, 0, 0);\n  CartesianTree<int,\
    \ true> CT(LCP);\n\n  auto dfs = [&](auto& dfs, int p, int idx, int h) -> void\
    \ {\n    int L = CT.range[idx].fi;\n    int R = CT.range[idx].se + 1;\n    int\
    \ hh = LCP[idx];\n    if (h < hh) {\n      edges.eb(p, len(dat));\n      p = len(dat);\n\
    \      dat.eb(L, R, h, hh);\n    }\n    if (CT.lch[idx] == -1) {\n      if (hh\
    \ < N - SA[idx]) {\n        edges.eb(p, len(dat));\n        dat.eb(idx, idx +\
    \ 1, hh, N - SA[idx]);\n      }\n    } else {\n      dfs(dfs, p, CT.lch[idx],\
    \ hh);\n    }\n    if (CT.rch[idx] == -1) {\n      if (hh < N - SA[idx + 1]) {\n\
    \        edges.eb(p, len(dat));\n        dat.eb(idx + 1, idx + 2, hh, N - SA[idx\
    \ + 1]);\n      }\n    } else {\n      dfs(dfs, p, CT.rch[idx], hh);\n    }\n\
    \  };\n  int r = CT.root;\n  if (LCP[r] > 0) {\n    edges.eb(0, 1);\n    dat.eb(0,\
    \ N, 0, LCP[r]);\n    dfs(dfs, 1, r, LCP[r]);\n  } else {\n    dfs(dfs, 0, r,\
    \ 0);\n  }\n\n  Graph<int, 1> G(len(dat));\n  for (auto&& [a, b]: edges) G.add(a,\
    \ b);\n  G.build();\n  return {G, dat};\n}\n#line 2 \"alg/monoid/min_idx.hpp\"\
    \n\r\ntemplate <typename T, bool tie_is_left = true>\r\nstruct Monoid_Min_Idx\
    \ {\r\n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\n  static\
    \ constexpr bool is_small(const X& x, const X& y) {\r\n    if (x.fi < y.fi) return\
    \ true;\r\n    if (x.fi > y.fi) return false;\r\n    return (tie_is_left ? (x.se\
    \ < y.se) : (x.se >= y.se));\r\n  }\r\n  static X op(X x, X y) { return (is_small(x,\
    \ y) ? x : y); }\r\n  static constexpr X unit() { return {infty<T>, -1}; }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/segtree/segtree.hpp\"\
    \n\ntemplate <class Monoid>\nstruct SegTree {\n  using MX = Monoid;\n  using X\
    \ = typename MX::value_type;\n  using value_type = X;\n  vc<X> dat;\n  int n,\
    \ log, size;\n\n  SegTree() {}\n  SegTree(int n) { build(n); }\n  template <typename\
    \ F>\n  SegTree(int n, F f) {\n    build(n, f);\n  }\n  SegTree(const vc<X>& v)\
    \ { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return\
    \ MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int\
    \ i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1\
    \ << log;\n    dat.assign(size << 1, MX::unit());\n    FOR(i, n) dat[size + i]\
    \ = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n  X get(int i) { return dat[size\
    \ + i]; }\n  vc<X> get_all() { return {dat.begin() + size, dat.begin() + size\
    \ + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i\
    \ + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i +=\
    \ size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const\
    \ X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 10 \"test/mytest/suffix_tree.test.cpp\"\n\n// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g\n\
    // \u5404\u30CE\u30FC\u30C9\u306F\u3001suffix array \u3067\u306E\u9577\u65B9\u5F62\
    \u9818\u57DF\u3068\u898B\u306A\u3057\u3066\u3001\n// \u30B0\u30E9\u30D5\u304A\u3088\
    \u3073\u3001\u9818\u57DF\u30C7\u30FC\u30BF\u3092\u4F5C\u308B\u3002\n// sample:\
    \ test/my_test/suffix_tree.test.cpp\ntemplate <typename SUFFIX>\npair<Graph<int,\
    \ 1>, vc<tuple<int, int, int, int>>> suffix_tree_old(SUFFIX& X) {\n  auto SA =\
    \ X.SA;\n  auto ISA = X.ISA;\n  auto LCP = X.LCP;\n\n  int N = len(SA);\n\n  using\
    \ Mono = Monoid_Min_Idx<int, 1>;\n\n  SegTree<Mono> seg(N - 1, [&](int i) -> Mono::X\
    \ { return {LCP[i], i}; });\n\n  using T = tuple<int, int, int, int>;\n  vc<T>\
    \ dat;\n  dat.eb(0, N, 0, 0);\n  vc<pair<int, int>> edges;\n\n  auto dfs = [&](auto&\
    \ dfs, int p, int l, int r, int h) -> void {\n    if (r == l + 1) {\n      int\
    \ i = SA[l];\n      int sz = N - i;\n      if (h == sz) return;\n      int k =\
    \ len(dat);\n      dat.eb(l, l + 1, h, sz);\n      edges.eb(p, k);\n      return;\n\
    \    }\n    auto [lcp, i] = seg.prod(l, r - 1);\n    if (lcp == h) {\n      dfs(dfs,\
    \ p, l, i + 1, h);\n      dfs(dfs, p, i + 1, r, h);\n      return;\n    }\n  \
    \  int k = len(dat);\n    dat.eb(l, r, h, lcp);\n    edges.eb(p, k);\n    dfs(dfs,\
    \ k, l, r, lcp);\n  };\n  dfs(dfs, 0, 0, N, 0);\n\n  Graph<int, 1> G(len(dat));\n\
    \  for (auto&& [a, b]: edges) G.add(a, b);\n  G.build();\n  return {G, dat};\n\
    }\n\n/*\nS = aabbabbaa\n\nsuffix array\na--------\naa-------\naabbabbaa\nabbaa----\n\
    abbabbaa-\nbaa------\nbabbaa---\nbbaa-----\nbbabbaa--\n\nsuffix tree \u306E node\
    \ \u306F\u3053\u306E\u9577\u65B9\u5F62\u9818\u57DF\u3092\u8868\u3059\n1--------\n\
    12-------\n123333333\n14445----\n14446666-\n789------\n780000---\n7112-----\n\
    7113-----\n*/\n\nvoid test1() {\n  string S = \"aabbabbaa\";\n  Suffix_Array X(S);\n\
    \  auto [G, dat] = suffix_tree(X);\n  using T = tuple<int, int, int, int>;\n \
    \ auto check_dat = [&](T t, int xl, int xr, int yl, int yr) -> void {\n    auto\
    \ [a, b, c, d] = t;\n    assert(a == xl && b == yl && c == xr && d == yr);\n \
    \ };\n  auto check_edge = [&](auto e, int frm, int to) -> void {\n    assert(e.frm\
    \ == frm && e.to == to);\n  };\n  check_dat(dat[0], 0, 0, 9, 0);\n  check_dat(dat[1],\
    \ 0, 0, 5, 1);\n  check_dat(dat[2], 1, 1, 3, 2);\n  check_dat(dat[3], 2, 2, 3,\
    \ 9);\n  check_dat(dat[4], 3, 1, 5, 4);\n  check_dat(dat[5], 3, 4, 4, 5);\n  check_dat(dat[6],\
    \ 4, 4, 5, 8);\n  check_dat(dat[7], 5, 0, 9, 1);\n  check_dat(dat[8], 5, 1, 7,\
    \ 2);\n  check_dat(dat[9], 5, 2, 6, 3);\n  check_dat(dat[10], 6, 2, 7, 6);\n \
    \ check_dat(dat[11], 7, 1, 9, 3);\n  check_dat(dat[12], 7, 3, 8, 4);\n  check_dat(dat[13],\
    \ 8, 3, 9, 7);\n  check_edge(G.edges[0], 0, 1);\n  check_edge(G.edges[1], 1, 2);\n\
    \  check_edge(G.edges[2], 2, 3);\n  check_edge(G.edges[3], 1, 4);\n  check_edge(G.edges[4],\
    \ 4, 5);\n  check_edge(G.edges[5], 4, 6);\n  check_edge(G.edges[6], 0, 7);\n \
    \ check_edge(G.edges[7], 7, 8);\n  check_edge(G.edges[8], 8, 9);\n  check_edge(G.edges[9],\
    \ 8, 10);\n  check_edge(G.edges[10], 7, 11);\n  check_edge(G.edges[11], 11, 12);\n\
    \  check_edge(G.edges[12], 11, 13);\n}\n\nvoid test2() {\n  FOR(N, 1, 10) {\n\
    \    FOR(100) {\n      int K = RNG(1, 5);\n      string S;\n      FOR(N) { S +=\
    \ 'a' + (RNG(0, K)); }\n      Suffix_Array SA(S);\n      auto [G1, dat1] = suffix_tree_old(SA);\n\
    \      auto [G2, dat2] = suffix_tree(SA);\n      assert(dat1 == dat2);\n     \
    \ assert(G1.N == G2.N);\n      assert(G1.M == G2.M);\n      FOR(i, G1.M) {\n \
    \       assert(G1.edges[i].frm == G2.edges[i].frm);\n        assert(G1.edges[i].to\
    \ == G2.edges[i].to);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  INT(a, b);\n\
    \  print(a + b);\n}\n\nsigned main() {\n  test1();\n  test2();\n  solve();\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"random/base.hpp\"\n#include \"string/suffix_tree.hpp\"\
    \n#include \"alg/monoid/min_idx.hpp\"\n#include \"ds/segtree/segtree.hpp\"\n#include\
    \ \"graph/base.hpp\"\n\n// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g\n\
    // \u5404\u30CE\u30FC\u30C9\u306F\u3001suffix array \u3067\u306E\u9577\u65B9\u5F62\
    \u9818\u57DF\u3068\u898B\u306A\u3057\u3066\u3001\n// \u30B0\u30E9\u30D5\u304A\u3088\
    \u3073\u3001\u9818\u57DF\u30C7\u30FC\u30BF\u3092\u4F5C\u308B\u3002\n// sample:\
    \ test/my_test/suffix_tree.test.cpp\ntemplate <typename SUFFIX>\npair<Graph<int,\
    \ 1>, vc<tuple<int, int, int, int>>> suffix_tree_old(SUFFIX& X) {\n  auto SA =\
    \ X.SA;\n  auto ISA = X.ISA;\n  auto LCP = X.LCP;\n\n  int N = len(SA);\n\n  using\
    \ Mono = Monoid_Min_Idx<int, 1>;\n\n  SegTree<Mono> seg(N - 1, [&](int i) -> Mono::X\
    \ { return {LCP[i], i}; });\n\n  using T = tuple<int, int, int, int>;\n  vc<T>\
    \ dat;\n  dat.eb(0, N, 0, 0);\n  vc<pair<int, int>> edges;\n\n  auto dfs = [&](auto&\
    \ dfs, int p, int l, int r, int h) -> void {\n    if (r == l + 1) {\n      int\
    \ i = SA[l];\n      int sz = N - i;\n      if (h == sz) return;\n      int k =\
    \ len(dat);\n      dat.eb(l, l + 1, h, sz);\n      edges.eb(p, k);\n      return;\n\
    \    }\n    auto [lcp, i] = seg.prod(l, r - 1);\n    if (lcp == h) {\n      dfs(dfs,\
    \ p, l, i + 1, h);\n      dfs(dfs, p, i + 1, r, h);\n      return;\n    }\n  \
    \  int k = len(dat);\n    dat.eb(l, r, h, lcp);\n    edges.eb(p, k);\n    dfs(dfs,\
    \ k, l, r, lcp);\n  };\n  dfs(dfs, 0, 0, N, 0);\n\n  Graph<int, 1> G(len(dat));\n\
    \  for (auto&& [a, b]: edges) G.add(a, b);\n  G.build();\n  return {G, dat};\n\
    }\n\n/*\nS = aabbabbaa\n\nsuffix array\na--------\naa-------\naabbabbaa\nabbaa----\n\
    abbabbaa-\nbaa------\nbabbaa---\nbbaa-----\nbbabbaa--\n\nsuffix tree \u306E node\
    \ \u306F\u3053\u306E\u9577\u65B9\u5F62\u9818\u57DF\u3092\u8868\u3059\n1--------\n\
    12-------\n123333333\n14445----\n14446666-\n789------\n780000---\n7112-----\n\
    7113-----\n*/\n\nvoid test1() {\n  string S = \"aabbabbaa\";\n  Suffix_Array X(S);\n\
    \  auto [G, dat] = suffix_tree(X);\n  using T = tuple<int, int, int, int>;\n \
    \ auto check_dat = [&](T t, int xl, int xr, int yl, int yr) -> void {\n    auto\
    \ [a, b, c, d] = t;\n    assert(a == xl && b == yl && c == xr && d == yr);\n \
    \ };\n  auto check_edge = [&](auto e, int frm, int to) -> void {\n    assert(e.frm\
    \ == frm && e.to == to);\n  };\n  check_dat(dat[0], 0, 0, 9, 0);\n  check_dat(dat[1],\
    \ 0, 0, 5, 1);\n  check_dat(dat[2], 1, 1, 3, 2);\n  check_dat(dat[3], 2, 2, 3,\
    \ 9);\n  check_dat(dat[4], 3, 1, 5, 4);\n  check_dat(dat[5], 3, 4, 4, 5);\n  check_dat(dat[6],\
    \ 4, 4, 5, 8);\n  check_dat(dat[7], 5, 0, 9, 1);\n  check_dat(dat[8], 5, 1, 7,\
    \ 2);\n  check_dat(dat[9], 5, 2, 6, 3);\n  check_dat(dat[10], 6, 2, 7, 6);\n \
    \ check_dat(dat[11], 7, 1, 9, 3);\n  check_dat(dat[12], 7, 3, 8, 4);\n  check_dat(dat[13],\
    \ 8, 3, 9, 7);\n  check_edge(G.edges[0], 0, 1);\n  check_edge(G.edges[1], 1, 2);\n\
    \  check_edge(G.edges[2], 2, 3);\n  check_edge(G.edges[3], 1, 4);\n  check_edge(G.edges[4],\
    \ 4, 5);\n  check_edge(G.edges[5], 4, 6);\n  check_edge(G.edges[6], 0, 7);\n \
    \ check_edge(G.edges[7], 7, 8);\n  check_edge(G.edges[8], 8, 9);\n  check_edge(G.edges[9],\
    \ 8, 10);\n  check_edge(G.edges[10], 7, 11);\n  check_edge(G.edges[11], 11, 12);\n\
    \  check_edge(G.edges[12], 11, 13);\n}\n\nvoid test2() {\n  FOR(N, 1, 10) {\n\
    \    FOR(100) {\n      int K = RNG(1, 5);\n      string S;\n      FOR(N) { S +=\
    \ 'a' + (RNG(0, K)); }\n      Suffix_Array SA(S);\n      auto [G1, dat1] = suffix_tree_old(SA);\n\
    \      auto [G2, dat2] = suffix_tree(SA);\n      assert(dat1 == dat2);\n     \
    \ assert(G1.N == G2.N);\n      assert(G1.M == G2.M);\n      FOR(i, G1.M) {\n \
    \       assert(G1.edges[i].frm == G2.edges[i].frm);\n        assert(G1.edges[i].to\
    \ == G2.edges[i].to);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  INT(a, b);\n\
    \  print(a + b);\n}\n\nsigned main() {\n  test1();\n  test2();\n  solve();\n \
    \ return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/base.hpp
  - string/suffix_tree.hpp
  - string/suffix_array.hpp
  - alg/monoid/min.hpp
  - ds/sparse_table/sparse_table.hpp
  - seq/cartesian_tree.hpp
  - graph/base.hpp
  - alg/monoid/min_idx.hpp
  - ds/segtree/segtree.hpp
  isVerificationFile: true
  path: test/mytest/suffix_tree.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 18:59:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/suffix_tree.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/suffix_tree.test.cpp
- /verify/test/mytest/suffix_tree.test.cpp.html
title: test/mytest/suffix_tree.test.cpp
---
