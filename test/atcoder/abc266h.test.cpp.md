---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/max.hpp
    title: alg/monoid/max.hpp
  - icon: ':question:'
    path: ds/segtree2d.hpp
    title: ds/segtree2d.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc266/tasks/abc266_Ex
    links:
    - https://atcoder.jp/contests/abc266/tasks/abc266_Ex
  bundledCode: "#line 1 \"test/atcoder/abc266h.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc266/tasks/abc266_Ex\"\
    \n#line 1 \"my_template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
    unroll-loops\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll\
    \ = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 =\
    \ unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
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
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define FOR4_R(i,\
    \ a, b, c) for (ll i = (b)-1; i >= ll(a); i -= (c))\n#define overload4(a, b, c,\
    \ d, e, ...) e\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) \\\n  overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) &\
    \ s))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\ntemplate <typename\
    \ T, typename U>\nT SUM(const vector<U> &A) {\n  T sum = 0;\n  for (auto &&a:\
    \ A) sum += a;\n  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define\
    \ MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\n\
    int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32\
    \ x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return\
    \ (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x ==\
    \ 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\n\
    int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll x) { return (x\
    \ == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ? -1\
    \ : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT pick(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\n\ntemplate <typename\
    \ T>\nT pick(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    \ntemplate <typename T>\nT pick(pqg<T> &que) {\n  assert(que.size());\n  T a =\
    \ que.top();\n  que.pop();\n  return a;\n}\n\ntemplate <typename T>\nT pick(vc<T>\
    \ &que) {\n  assert(que.size());\n  T a = que.back();\n  que.pop_back();\n  return\
    \ a;\n}\n\ntemplate <typename T, typename U>\nT ceil(T x, U y) {\n  return (x\
    \ > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate <typename T, typename U>\nT floor(T\
    \ x, U y) {\n  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <typename\
    \ T, typename U>\npair<T, T> divmod(T x, U y) {\n  T q = floor(x, y);\n  return\
    \ {q, x - q * y};\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok,\
    \ ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x = (ng\
    \ + ok) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return\
    \ ok;\n}\n\ntemplate <typename F>\ndouble binary_search_real(F check, double ok,\
    \ double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n\
    \    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return (ok + ng)\
    \ / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b)\
    \ {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline\
    \ bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate <typename\
    \ T, typename U>\nvector<T> cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off ==\
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename CNT, typename T>\n\
    vc<CNT> bincount(const vc<T> &A, int size) {\n  vc<CNT> C(size);\n  for (auto\
    \ &&x: A) { ++C[x]; }\n  return C;\n}\n\n// stable\ntemplate <typename T>\nvector<int>\
    \ argsort(const vector<T> &A) {\n  vector<int> ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return A[i] < A[j] || (A[i]\
    \ == A[j] && i < j); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  int n =\
    \ len(I);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n  return B;\n}\n#line 1\
    \ \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include <unistd.h>\r\n\r\n\
    namespace detail {\r\ntemplate <typename T, decltype(&T::is_modint) = &T::is_modint>\r\
    \nstd::true_type check_value(int);\r\ntemplate <typename T>\r\nstd::false_type\
    \ check_value(long);\r\n} // namespace detail\r\n\r\ntemplate <typename T>\r\n\
    struct is_modint : decltype(detail::check_value<T>(0)) {};\r\ntemplate <typename\
    \ T>\r\nusing is_modint_t = enable_if_t<is_modint<T>::value>;\r\ntemplate <typename\
    \ T>\r\nusing is_not_modint_t = enable_if_t<!is_modint<T>::value>;\r\n\r\nstruct\
    \ Scanner {\r\n  FILE *fp;\r\n  char line[(1 << 15) + 1];\r\n  size_t st = 0,\
    \ ed = 0;\r\n  void reread() {\r\n    memmove(line, line + st, ed - st);\r\n \
    \   ed -= st;\r\n    st = 0;\r\n    ed += fread(line + ed, 1, (1 << 15) - ed,\
    \ fp);\r\n    line[ed] = '\\0';\r\n  }\r\n  bool succ() {\r\n    while (true)\
    \ {\r\n      if (st == ed) {\r\n        reread();\r\n        if (st == ed) return\
    \ false;\r\n      }\r\n      while (st != ed && isspace(line[st])) st++;\r\n \
    \     if (st != ed) break;\r\n    }\r\n    if (ed - st <= 50) {\r\n      bool\
    \ sep = false;\r\n      for (size_t i = st; i < ed; i++) {\r\n        if (isspace(line[i]))\
    \ {\r\n          sep = true;\r\n          break;\r\n        }\r\n      }\r\n \
    \     if (!sep) reread();\r\n    }\r\n    return true;\r\n  }\r\n  template <class\
    \ T, enable_if_t<is_same<T, string>::value, int> = 0>\r\n  bool read_single(T\
    \ &ref) {\r\n    if (!succ()) return false;\r\n    while (true) {\r\n      size_t\
    \ sz = 0;\r\n      while (st + sz < ed && !isspace(line[st + sz])) sz++;\r\n \
    \     ref.append(line + st, sz);\r\n      st += sz;\r\n      if (!sz || st !=\
    \ ed) break;\r\n      reread();\r\n    }\r\n    return true;\r\n  }\r\n  template\
    \ <class T, enable_if_t<is_integral<T>::value, int> = 0>\r\n  bool read_single(T\
    \ &ref) {\r\n    if (!succ()) return false;\r\n    bool neg = false;\r\n    if\
    \ (line[st] == '-') {\r\n      neg = true;\r\n      st++;\r\n    }\r\n    ref\
    \ = T(0);\r\n    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf);\
    \ }\r\n    if (neg) ref = -ref;\r\n    return true;\r\n  }\r\n  template <class\
    \ T, is_modint_t<T> * = nullptr>\r\n  bool read_single(T &ref) {\r\n    long long\
    \ val = 0;\r\n    bool f = read_single(val);\r\n    ref = T(val);\r\n    return\
    \ f;\r\n  }\r\n  bool read_single(double &ref) {\r\n    string s;\r\n    if (!read_single(s))\
    \ return false;\r\n    ref = std::stod(s);\r\n    return true;\r\n  }\r\n  bool\
    \ read_single(char &ref) {\r\n    string s;\r\n    if (!read_single(s) || s.size()\
    \ != 1) return false;\r\n    ref = s[0];\r\n    return true;\r\n  }\r\n  template\
    \ <class T>\r\n  bool read_single(vector<T> &ref) {\r\n    for (auto &d: ref)\
    \ {\r\n      if (!read_single(d)) return false;\r\n    }\r\n    return true;\r\
    \n  }\r\n  template <class T, class U>\r\n  bool read_single(pair<T, U> &p) {\r\
    \n    return (read_single(p.first) && read_single(p.second));\r\n  }\r\n  template\
    \ <class A, class B, class C>\r\n  bool read_single(tuple<A, B, C> &p) {\r\n \
    \   return (read_single(get<0>(p)) && read_single(get<1>(p))\r\n            &&\
    \ read_single(get<2>(p)));\r\n  }\r\n  template <class A, class B, class C, class\
    \ D>\r\n  bool read_single(tuple<A, B, C, D> &p) {\r\n    return (read_single(get<0>(p))\
    \ && read_single(get<1>(p))\r\n            && read_single(get<2>(p)) && read_single(get<3>(p)));\r\
    \n  }\r\n  void read() {}\r\n  template <class H, class... T>\r\n  void read(H\
    \ &h, T &... t) {\r\n    bool f = read_single(h);\r\n    assert(f);\r\n    read(t...);\r\
    \n  }\r\n  Scanner(FILE *fp) : fp(fp) {}\r\n};\r\n\r\nstruct Printer {\r\n  Printer(FILE\
    \ *_fp) : fp(_fp) {}\r\n  ~Printer() { flush(); }\r\n\r\n  static constexpr size_t\
    \ SIZE = 1 << 15;\r\n  FILE *fp;\r\n  char line[SIZE], small[50];\r\n  size_t\
    \ pos = 0;\r\n  void flush() {\r\n    fwrite(line, 1, pos, fp);\r\n    pos = 0;\r\
    \n  }\r\n  void write(const char &val) {\r\n    if (pos == SIZE) flush();\r\n\
    \    line[pos++] = val;\r\n  }\r\n  template <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\n  void write(T val) {\r\n    if (pos > (1 << 15) - 50) flush();\r\
    \n    if (val == 0) {\r\n      write('0');\r\n      return;\r\n    }\r\n    if\
    \ (val < 0) {\r\n      write('-');\r\n      val = -val; // todo min\r\n    }\r\
    \n    size_t len = 0;\r\n    while (val) {\r\n      small[len++] = char(0x30 |\
    \ (val % 10));\r\n      val /= 10;\r\n    }\r\n    for (size_t i = 0; i < len;\
    \ i++) { line[pos + i] = small[len - 1 - i]; }\r\n    pos += len;\r\n  }\r\n \
    \ void write(const string &s) {\r\n    for (char c: s) write(c);\r\n  }\r\n  void\
    \ write(const char *s) {\r\n    size_t len = strlen(s);\r\n    for (size_t i =\
    \ 0; i < len; i++) write(s[i]);\r\n  }\r\n  void write(const double &x) {\r\n\
    \    ostringstream oss;\r\n    oss << fixed << setprecision(15) << x;\r\n    string\
    \ s = oss.str();\r\n    write(s);\r\n  }\r\n  void write(const long double &x)\
    \ {\r\n    ostringstream oss;\r\n    oss << fixed << setprecision(15) << x;\r\n\
    \    string s = oss.str();\r\n    write(s);\r\n  }\r\n  template <class T, is_modint_t<T>\
    \ * = nullptr>\r\n  void write(T &ref) {\r\n    write(ref.val);\r\n  }\r\n  template\
    \ <class T>\r\n  void write(const vector<T> &val) {\r\n    auto n = val.size();\r\
    \n    for (size_t i = 0; i < n; i++) {\r\n      if (i) write(' ');\r\n      write(val[i]);\r\
    \n    }\r\n  }\r\n  template <class T, class U>\r\n  void write(const pair<T,\
    \ U> &val) {\r\n    write(val.first);\r\n    write(' ');\r\n    write(val.second);\r\
    \n  }\r\n  template <class A, class B, class C>\r\n  void write(const tuple<A,\
    \ B, C> &val) {\r\n    auto &[a, b, c] = val;\r\n    write(a), write(' '), write(b),\
    \ write(' '), write(c);\r\n  }\r\n  template <class A, class B, class C, class\
    \ D>\r\n  void write(const tuple<A, B, C, D> &val) {\r\n    auto &[a, b, c, d]\
    \ = val;\r\n    write(a), write(' '), write(b), write(' '), write(c), write('\
    \ '), write(d);\r\n  }\r\n  template <class A, class B, class C, class D, class\
    \ E>\r\n  void write(const tuple<A, B, C, D, E> &val) {\r\n    auto &[a, b, c,\
    \ d, e] = val;\r\n    write(a), write(' '), write(b), write(' '), write(c), write('\
    \ '), write(d), write(' '), write(e);\r\n  }\r\n  template <class A, class B,\
    \ class C, class D, class E, class F>\r\n  void write(const tuple<A, B, C, D,\
    \ E, F> &val) {\r\n    auto &[a, b, c, d, e, f] = val;\r\n    write(a), write('\
    \ '), write(b), write(' '), write(c), write(' '), write(d), write(' '), write(e),\
    \ write(' '), write(f);\r\n  }\r\n  template <class T, size_t S>\r\n  void write(const\
    \ array<T, S> &val) {\r\n    auto n = val.size();\r\n    for (size_t i = 0; i\
    \ < n; i++) {\r\n      if (i) write(' ');\r\n      write(val[i]);\r\n    }\r\n\
    \  }\r\n  void write(i128 val) {\r\n    string s;\r\n    bool negative = 0;\r\n\
    \    if(val < 0){\r\n      negative = 1;\r\n      val = -val;\r\n    }\r\n   \
    \ while (val) {\r\n      s += '0' + int(val % 10);\r\n      val /= 10;\r\n   \
    \ }\r\n    if(negative) s += \"-\";\r\n    reverse(all(s));\r\n    if (len(s)\
    \ == 0) s = \"0\";\r\n    write(s);\r\n  }\r\n};\r\n\r\nScanner scanner = Scanner(stdin);\r\
    \nPrinter printer = Printer(stdout);\r\n\r\nvoid flush() { printer.flush(); }\r\
    \nvoid print() { printer.write('\\n'); }\r\ntemplate <class Head, class... Tail>\r\
    \nvoid print(Head &&head, Tail &&... tail) {\r\n  printer.write(head);\r\n  if\
    \ (sizeof...(Tail)) printer.write(' ');\r\n  print(forward<Tail>(tail)...);\r\n\
    }\r\n\r\nvoid read() {}\r\ntemplate <class Head, class... Tail>\r\nvoid read(Head\
    \ &head, Tail &... tail) {\r\n  scanner.read(head);\r\n  read(tail...);\r\n}\r\
    \n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    #define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ CHAR(...)      \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ DBL(...)      \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n\
    #define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\
    \n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t\
    \ ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool\
    \ t = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\
    \nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1)\
    \ { yes(!t); }\r\n#line 1 \"ds/segtree2d.hpp\"\ntemplate <typename Monoid, typename\
    \ XY, bool SMALL = false>\r\nstruct SegTree2D {\r\n  using S = typename Monoid::value_type;\r\
    \n  int N;\r\n  int full_N;\r\n  vc<XY> keyX;\r\n  int min_X;\r\n  vc<int> indptr;\r\
    \n  vc<XY> keyY;\r\n  vc<S> dat;\r\n\r\n  inline int xtoi(XY x) {\r\n    if(SMALL)\
    \ return clamp<XY>(x - min_X, 0, N);\r\n    return LB(keyX, x);\r\n  }\r\n\r\n\
    \  SegTree2D(vc<XY>& X, vc<XY>& Y, vc<S> wt = vc<S>()) {\r\n    if (len(wt) ==\
    \ 0) wt = vc<S>(len(X), Monoid::unit());\r\n    assert(Monoid::commute); // \u53EF\
    \u63DB\u30E2\u30CE\u30A4\u30C9\u306E\u307F\r\n    assert(len(X) == len(Y) && len(X)\
    \ == len(wt));\r\n\r\n    if (!SMALL) {\r\n      keyX = X;\r\n      UNIQUE(keyX);\r\
    \n      N = len(keyX);\r\n    } else {\r\n      min_X = (len(X) == 0 ? 0 : MIN(X));\r\
    \n      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;\r\n      keyX.resize(N);\r\
    \n      FOR(i, N) keyX[i] = min_X + i;\r\n    }\r\n\r\n    vc<vc<XY>> keyY_raw(N\
    \ + N);\r\n    vc<vc<S>> dat_raw(N + N);\r\n\r\n    auto I = argsort(Y);\r\n \
    \   for (auto&& i: I) {\r\n      int ix = xtoi(X[i]), y = Y[i];\r\n      ix +=\
    \ N;\r\n      while (ix) {\r\n        auto& KY = keyY_raw[ix];\r\n        if (len(KY)\
    \ == 0 || KY.back() < y) {\r\n          KY.eb(y);\r\n          dat_raw[ix].eb(wt[i]);\r\
    \n        } else {\r\n          dat_raw[ix].back() = Monoid::op(dat_raw[ix].back(),\
    \ wt[i]);\r\n        }\r\n        ix >>= 1;\r\n      }\r\n    }\r\n\r\n    indptr.assign(N\
    \ + N + 1, 0);\r\n    FOR(i, N + N) indptr[i + 1] = indptr[i] + len(keyY_raw[i]);\r\
    \n    int full_N = indptr.back();\r\n    keyY.resize(full_N);\r\n    dat.assign(2\
    \ * full_N, Monoid::unit());\r\n    FOR(i, N + N) {\r\n      int off = 2 * indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\r\n      FOR(j, n) {\r\n        keyY[indptr[i]\
    \ + j] = keyY_raw[i][j];\r\n        dat[off + n + j] = dat_raw[i][j];\r\n    \
    \  }\r\n      FOR3_R(j, 1, n)\r\n      dat[off + j] = Monoid::op(dat[off + 2 *\
    \ j + 0], dat[off + 2 * j + 1]);\r\n    }\r\n  }\r\n\r\n  void multiply_i(int\
    \ i, XY y, S val) {\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\
    \n    auto it = keyY.begin() + LID;\r\n    int j = lower_bound(it, it + n, y)\
    \ - it;\r\n    assert(keyY[LID + j] == y);\r\n    int off = 2 * LID;\r\n    j\
    \ += n;\r\n\r\n    while (j) {\r\n      dat[off + j] = Monoid::op(dat[off + j],\
    \ val);\r\n      j >>= 1;\r\n    }\r\n  }\r\n\r\n  void multiply(XY x, XY y, S\
    \ val) {\r\n    int i = xtoi(x);\r\n    assert(keyX[i] == x);\r\n    i += N;\r\
    \n    while (i) {\r\n      multiply_i(i, y, val);\r\n      i >>= 1;\r\n    }\r\
    \n  }\r\n\r\n  S prod_i(int i, XY ly, XY ry) {\r\n    int LID = indptr[i], n =\
    \ indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int L\
    \ = lower_bound(it, it + n, ly) - it;\r\n    int R = lower_bound(it, it + n, ry)\
    \ - it;\r\n    int off = 2 * LID;\r\n    L += n;\r\n    R += n;\r\n    S val =\
    \ Monoid::unit();\r\n    while (L < R) {\r\n      if (L & 1) val = Monoid::op(val,\
    \ dat[off + (L++)]);\r\n      if (R & 1) val = Monoid::op(dat[off + (--R)], val);\r\
    \n      L >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n\r\n\
    \  S prod(XY lx, XY ly, XY rx, XY ry) {\r\n    int L = xtoi(lx);\r\n    int R\
    \ = xtoi(rx);\r\n    L += N;\r\n    R += N;\r\n    S val = Monoid::unit();\r\n\
    \    while (L < R) {\r\n      if (L & 1) val = Monoid::op(val, prod_i(L++, ly,\
    \ ry));\r\n      if (R & 1) val = Monoid::op(prod_i(--R, ly, ry), val);\r\n  \
    \    L >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n\r\n  void\
    \ debug() {\r\n    print(\"keyX\", keyX);\r\n    print(\"indptr\", indptr);\r\n\
    \    print(\"keyY\", keyY);\r\n    print(\"dat\", dat);\r\n  }\r\n};\n#line 2\
    \ \"alg/monoid/max.hpp\"\ntemplate <class X>\r\nstruct Monoid_Max {\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return max(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::lowest();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 6 \"test/atcoder/abc266h.test.cpp\"\
    \n\nusing Mono = Monoid_Max<ll>;\n\nvoid naive() {\n  LL(N);\n  using T = tuple<ll,\
    \ ll, ll, ll>;\n\n  VEC(T, dat, N);\n  dat.eb(0, 0, 0, 0);\n  ++N;\n\n  sort(all(dat),\
    \ [&](auto& a, auto& b) -> bool {\n    auto [at, ax, ay, aa] = a;\n    auto [bt,\
    \ bx, by, bb] = b;\n    if (ay < by) return true;\n    if (ay > by) return false;\n\
    \    return at < bt;\n  });\n\n  const ll INF = 1LL << 60;\n  vi dp(N, -INF);\n\
    \  dp[0] = 0;\n  FOR(j, N) {\n    auto [tj, xj, yj, vvj] = dat[j];\n    FOR(i,\
    \ j) {\n      auto [ti, xi, yi, vvi] = dat[i];\n      ll d = abs(xi - xj) + abs(yi\
    \ - yj);\n      if (yi > yj) continue;\n      if (ti + d > tj) continue;\n   \
    \   chmax(dp[j], dp[i] + vvj);\n    }\n    print(tj, xj, yj, vvj, dp[j]);\n  }\n\
    \  print(MAX(dp));\n}\n\nvoid solve() {\n  // return naive();\n\n  LL(N);\n  using\
    \ T = tuple<ll, ll, ll, ll>;\n\n  VEC(T, dat, N);\n  dat.eb(0, 0, 0, 0);\n  ++N;\n\
    \n  sort(all(dat), [&](auto& a, auto& b) -> bool {\n    auto [at, ax, ay, aa]\
    \ = a;\n    auto [bt, bx, by, bb] = b;\n    if (ay < by) return true;\n    if\
    \ (ay > by) return false;\n    return at < bt;\n  });\n\n  /*\n  \u53F3\u4E0A\u3078\
    \u306E\u9077\u79FB\uFF1A\n  (x,y,t) \u304C\u60C5\u5831 (a,b,c,v) \u3092\u53D7\u3051\
    \u53D6\u308B\u306E\u306F\n  a<=x, x+y-t<=a+b-c\n  \u30FB(a,a+b-c) \u306B\u60C5\
    \u5831\u3092\u8FFD\u52A0\u3059\u308B\n  \u30FB[-INF,x] x [x+y-t, INF] \u3067\u306E\
    \u6700\u5927\u5024\u3092\u6C42\u3081\u308B\n\n  \u5DE6\u4E0A\u3078\u306E\u9077\
    \u79FB\uFF1A\n  (a-x)+(y-b)<=t-c\n  x<=a, a-b+c<=x-y+t\n  */\n  vi X1(N), Y1(N),\
    \ X2(N), Y2(N);\n  FOR(i, N) {\n    auto [t, x, y, v] = dat[i];\n    X1[i] = x;\n\
    \    X2[i] = x;\n    Y1[i] = x + y - t;\n    Y2[i] = x - y + t;\n  }\n  SegTree2D<Mono,\
    \ ll, false> seg1(X1, Y1);\n  SegTree2D<Mono, ll, false> seg2(X2, Y2);\n\n  const\
    \ ll INF = 1LL << 60;\n\n  ll ANS = 0;\n  FOR(i, N) {\n    const auto [t, x, y,\
    \ v] = dat[i];\n    const ll a = x, b = y, c = t;\n    if (i == 0) {\n      seg1.multiply(a,\
    \ a + b - c, 0);\n      seg2.multiply(a, a - b + c, 0);\n      continue;\n   \
    \ }\n    ll best = -INF;\n    chmax(best, seg1.prod(-INF, x + y - t, x + 1, INF));\n\
    \    chmax(best, seg2.prod(x, -INF, INF, x - y + t + 1));\n    if (best < 0) continue;\n\
    \    best += v;\n    chmax(ANS, best);\n    seg1.multiply(a, a + b - c, best);\n\
    \    seg2.multiply(a, a - b + c, best);\n  }\n  print(ANS);\n}\n\nsigned main()\
    \ {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T)\
    \ solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc266/tasks/abc266_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/segtree2d.hpp\"\
    \n#include \"alg/monoid/max.hpp\"\n\nusing Mono = Monoid_Max<ll>;\n\nvoid naive()\
    \ {\n  LL(N);\n  using T = tuple<ll, ll, ll, ll>;\n\n  VEC(T, dat, N);\n  dat.eb(0,\
    \ 0, 0, 0);\n  ++N;\n\n  sort(all(dat), [&](auto& a, auto& b) -> bool {\n    auto\
    \ [at, ax, ay, aa] = a;\n    auto [bt, bx, by, bb] = b;\n    if (ay < by) return\
    \ true;\n    if (ay > by) return false;\n    return at < bt;\n  });\n\n  const\
    \ ll INF = 1LL << 60;\n  vi dp(N, -INF);\n  dp[0] = 0;\n  FOR(j, N) {\n    auto\
    \ [tj, xj, yj, vvj] = dat[j];\n    FOR(i, j) {\n      auto [ti, xi, yi, vvi] =\
    \ dat[i];\n      ll d = abs(xi - xj) + abs(yi - yj);\n      if (yi > yj) continue;\n\
    \      if (ti + d > tj) continue;\n      chmax(dp[j], dp[i] + vvj);\n    }\n \
    \   print(tj, xj, yj, vvj, dp[j]);\n  }\n  print(MAX(dp));\n}\n\nvoid solve()\
    \ {\n  // return naive();\n\n  LL(N);\n  using T = tuple<ll, ll, ll, ll>;\n\n\
    \  VEC(T, dat, N);\n  dat.eb(0, 0, 0, 0);\n  ++N;\n\n  sort(all(dat), [&](auto&\
    \ a, auto& b) -> bool {\n    auto [at, ax, ay, aa] = a;\n    auto [bt, bx, by,\
    \ bb] = b;\n    if (ay < by) return true;\n    if (ay > by) return false;\n  \
    \  return at < bt;\n  });\n\n  /*\n  \u53F3\u4E0A\u3078\u306E\u9077\u79FB\uFF1A\
    \n  (x,y,t) \u304C\u60C5\u5831 (a,b,c,v) \u3092\u53D7\u3051\u53D6\u308B\u306E\u306F\
    \n  a<=x, x+y-t<=a+b-c\n  \u30FB(a,a+b-c) \u306B\u60C5\u5831\u3092\u8FFD\u52A0\
    \u3059\u308B\n  \u30FB[-INF,x] x [x+y-t, INF] \u3067\u306E\u6700\u5927\u5024\u3092\
    \u6C42\u3081\u308B\n\n  \u5DE6\u4E0A\u3078\u306E\u9077\u79FB\uFF1A\n  (a-x)+(y-b)<=t-c\n\
    \  x<=a, a-b+c<=x-y+t\n  */\n  vi X1(N), Y1(N), X2(N), Y2(N);\n  FOR(i, N) {\n\
    \    auto [t, x, y, v] = dat[i];\n    X1[i] = x;\n    X2[i] = x;\n    Y1[i] =\
    \ x + y - t;\n    Y2[i] = x - y + t;\n  }\n  SegTree2D<Mono, ll, false> seg1(X1,\
    \ Y1);\n  SegTree2D<Mono, ll, false> seg2(X2, Y2);\n\n  const ll INF = 1LL <<\
    \ 60;\n\n  ll ANS = 0;\n  FOR(i, N) {\n    const auto [t, x, y, v] = dat[i];\n\
    \    const ll a = x, b = y, c = t;\n    if (i == 0) {\n      seg1.multiply(a,\
    \ a + b - c, 0);\n      seg2.multiply(a, a - b + c, 0);\n      continue;\n   \
    \ }\n    ll best = -INF;\n    chmax(best, seg1.prod(-INF, x + y - t, x + 1, INF));\n\
    \    chmax(best, seg2.prod(x, -INF, INF, x - y + t + 1));\n    if (best < 0) continue;\n\
    \    best += v;\n    chmax(ANS, best);\n    seg1.multiply(a, a + b - c, best);\n\
    \    seg2.multiply(a, a - b + c, best);\n  }\n  print(ANS);\n}\n\nsigned main()\
    \ {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T)\
    \ solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/segtree2d.hpp
  - alg/monoid/max.hpp
  isVerificationFile: true
  path: test/atcoder/abc266h.test.cpp
  requiredBy: []
  timestamp: '2022-10-21 18:52:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc266h.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc266h.test.cpp
- /verify/test/atcoder/abc266h.test.cpp.html
title: test/atcoder/abc266h.test.cpp
---
