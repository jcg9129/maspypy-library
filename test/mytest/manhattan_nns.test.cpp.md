---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/min_idx.hpp
    title: alg/monoid/min_idx.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':x:'
    path: geo/manhattan_nns.hpp
    title: geo/manhattan_nns.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
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
  bundledCode: "#line 1 \"test/mytest/manhattan_nns.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n#pragma GCC optimize(\"Ofast\")\n\
    #pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned\
    \ long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll> = ll(infty<int>)\
    \ * infty<int> * 2;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate\
    \ <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128>\
    \ = i128(infty<ll>) * infty<ll>;\ntemplate <>\nconstexpr double infty<double>\
    \ = infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>>\
    \ name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define\
    \ vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
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
    \ yes(!t); }\r\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t\
    \ x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n         \
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \               .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n\
    \  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"ds/segtree/segtree.hpp\"\
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
    \  }\n};\n#line 2 \"alg/monoid/min_idx.hpp\"\n\r\ntemplate <typename T, bool tie_is_left\
    \ = true>\r\nstruct Monoid_Min_Idx {\r\n  using value_type = pair<T, int>;\r\n\
    \  using X = value_type;\r\n  static constexpr bool is_small(const X& x, const\
    \ X& y) {\r\n    if (x.fi < y.fi) return true;\r\n    if (x.fi > y.fi) return\
    \ false;\r\n    return (tie_is_left ? (x.se < y.se) : (x.se >= y.se));\r\n  }\r\
    \n  static X op(X x, X y) { return (is_small(x, y) ? x : y); }\r\n  static constexpr\
    \ X unit() { return {infty<T>, -1}; }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 3 \"geo/manhattan_nns.hpp\"\n\r\n// \u70B9\u7FA4 FRM \u304B\u3089\
    \u70B9\u7FA4 TO \u3078\u306E\u6700\u8FD1\u70B9\u63A2\u7D22\r\n// vector \u306E\
    \ pair \u3092\u8FD4\u3059\uFF1Adist, nbd_idx\r\ntemplate <typename X = ll>\r\n\
    pair<vc<X>, vc<int>> manhattan_nns(vc<pair<X, X>> FRM, vc<pair<X, X>>& TO) {\r\
    \n  assert(len(TO) >= 1);\r\n  int N = len(FRM), M = len(TO);\r\n  vc<pair<X,\
    \ X>> points(N + M);\r\n  FOR(i, N) points[i] = FRM[i];\r\n  FOR(i, M) points[N\
    \ + i] = TO[i];\r\n  vc<X> Y(M);\r\n  FOR(i, M) Y[i] = TO[i].se;\r\n  UNIQUE(Y);\r\
    \n\r\n  vc<int> nbd_idx(N, -1);\r\n  vc<X> dist(N, infty<X>);\r\n\r\n  auto add_ans\
    \ = [&](int i, int j) -> void {\r\n    if (j == -1) return;\r\n    X dx = points[i].fi\
    \ - points[j].fi;\r\n    X dy = points[i].se - points[j].se;\r\n    if (chmin(dist[i],\
    \ abs(dx) + abs(dy))) nbd_idx[i] = j - N;\r\n  };\r\n\r\n  vc<int> I(N + M);\r\
    \n  iota(all(I), 0);\r\n  sort(all(I), [&](auto& i, auto& j) { return (points[i].fi\
    \ < points[j].fi); });\r\n  auto calc = [&]() -> void {\r\n    SegTree<Monoid_Min_Idx<X>>\
    \ seg1(len(Y)), seg2(len(Y));\r\n    for (auto&& i: I) {\r\n      auto [x, y]\
    \ = points[i];\r\n      int idx = LB(Y, y);\r\n      if (i < N) {\r\n        add_ans(i,\
    \ seg1.prod(idx, len(Y)).se);\r\n        add_ans(i, seg2.prod(0, idx).se);\r\n\
    \      }\r\n      elif (i >= N) {\r\n        seg1.set(idx, {y - x, i});\r\n  \
    \      seg2.set(idx, {-(x + y), i});\r\n      }\r\n    }\r\n  };\r\n\r\n  calc();\r\
    \n  reverse(all(I));\r\n  FOR(i, N + M) points[i].fi *= -1;\r\n  calc();\r\n\r\
    \n  return {dist, nbd_idx};\r\n};\n#line 6 \"test/mytest/manhattan_nns.test.cpp\"\
    \n\nvoid test() {\n  FOR(n, 1, 20) FOR(m, 1, 20) {\n    vc<pi> A, B;\n    FOR(n)\
    \ {\n      int a = RNG(0, 100);\n      int b = RNG(0, 100);\n      A.eb(a, b);\n\
    \    }\n    FOR(m) {\n      int a = RNG(0, 100);\n      int b = RNG(0, 100);\n\
    \      B.eb(a, b);\n    }\n    auto [dist, J] = manhattan_nns(A, B);\n    FOR(i,\
    \ n) {\n      FOR(j, m) {\n        auto [x1, y1] = A[i];\n        auto [x2, y2]\
    \ = B[j];\n        int d = abs(x1 - x2) + abs(y1 - y2);\n        assert(dist[i]\
    \ <= d);\n        assert(j != J[i] || dist[i] == d);\n      }\n    }\n  }\n}\n\
    \nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n#include \"geo/manhattan_nns.hpp\"\
    \n\nvoid test() {\n  FOR(n, 1, 20) FOR(m, 1, 20) {\n    vc<pi> A, B;\n    FOR(n)\
    \ {\n      int a = RNG(0, 100);\n      int b = RNG(0, 100);\n      A.eb(a, b);\n\
    \    }\n    FOR(m) {\n      int a = RNG(0, 100);\n      int b = RNG(0, 100);\n\
    \      B.eb(a, b);\n    }\n    auto [dist, J] = manhattan_nns(A, B);\n    FOR(i,\
    \ n) {\n      FOR(j, m) {\n        auto [x1, y1] = A[i];\n        auto [x2, y2]\
    \ = B[j];\n        int d = abs(x1 - x2) + abs(y1 - y2);\n        assert(dist[i]\
    \ <= d);\n        assert(j != J[i] || dist[i] == d);\n      }\n    }\n  }\n}\n\
    \nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/base.hpp
  - geo/manhattan_nns.hpp
  - ds/segtree/segtree.hpp
  - alg/monoid/min_idx.hpp
  isVerificationFile: true
  path: test/mytest/manhattan_nns.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 18:59:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/manhattan_nns.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/manhattan_nns.test.cpp
- /verify/test/mytest/manhattan_nns.test.cpp.html
title: test/mytest/manhattan_nns.test.cpp
---
