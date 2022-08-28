---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/dynamicupperhull.hpp
    title: geo/dynamicupperhull.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convex_layers
    links:
    - https://judge.yosupo.jp/problem/convex_layers
  bundledCode: "#line 1 \"test/library_checker/geometry/convex_layers.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/convex_layers\"\r\n#line 1 \"\
    my_template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\n\
    using vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate\
    \ <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
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
    #define fi first\n#define se second\n\n#define stoi stoll\n\nll SUM(vector<int>\
    \ &A) {\n  ll sum = 0;\n  for (auto &&a: A) sum += a;\n  return sum;\n}\n\ntemplate\
    \ <typename T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a: A) sum\
    \ += a;\n  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v)\
    \ *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
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
    \ : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename U>\nT ceil(T x, U\
    \ y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate <typename T,\
    \ typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x - y + 1) / y);\n\
    }\n\ntemplate <typename T, typename U>\npair<T, T> divmod(T x, U y) {\n  T q =\
    \ floor(x, y);\n  return {q, x - q * y};\n}\n\nll binary_search(function<bool(ll)>\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n   \
    \   ng = x;\n  }\n  return ok;\n}\n\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    if (check(x)) {\n      ok = x;\n    } else {\n      ng\
    \ = x;\n    }\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\n\
    inline bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\nvi s_to_vi(const string &S, char first_char) {\n  vi A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate\
    \ <typename T>\nvector<T> cumsum(vector<T> &A, int off = 1) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off ==\
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename CNT, typename T>\n\
    vc<CNT> bincount(const vc<T> &A, int size) {\n  vc<CNT> C(size);\n  for (auto\
    \ &&x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  // stable\n  vector<int> ids(A.size());\n  iota(all(ids),\
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
    \ { yes(!t); }\r\n#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point\
    \ {\n  T x, y;\n\n  Point() = default;\n\n  template <typename A, typename B>\n\
    \  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x\
    \ + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y -\
    \ p.y}; }\n  bool operator==(Point p) const { return x == p.x && y == p.y; }\n\
    \  Point operator-() const { return {-x, -y}; }\n\n  bool operator<(Point p) const\
    \ {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n\n  T dot(Point\
    \ other) { return x * other.x + y * other.y; }\n  T det(Point other) { return\
    \ x * other.y - y * other.x; }\n};\n\ntemplate <typename REAL, typename T>\nREAL\
    \ dist(Point<T> A, Point<T> B) {\n  A -= B;\n  T p = A.dot(A);\n  return sqrt(REAL(p));\n\
    }\n\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T\
    \ c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y;\n\
    \    b = B.x - A.x;\n    c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T\
    \ x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template <typename\
    \ U>\n  U eval(Point<U> P) {\n    return a * P.x + b * P.y + c;\n  }\n\n  template\
    \ <typename U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n \
    \ template <enable_if_t<is_integral<T>::value, int> = 0>\n  bool is_parallel(Line\
    \ other) {\n    return a * other.b - b * other.a == 0;\n  }\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  bool is_orthogonal(Line other) {\n    return a * other.a + b *\
    \ other.b == 0;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n  Point<T>\
    \ A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T x1,\
    \ T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n\
    \  Line<T> to_Line() { return Line(A, B); }\n};\n\ntemplate <typename T>\nstruct\
    \ Circle {\n  Point<T> O;\n  T r;\n  Circle(Point<T> O, T r) : O(O), r(r) {}\n\
    \  Circle(T x, T y, T r) : O(Point<T>(x, y)), r(r) {}\n};\n\ntemplate <typename\
    \ T>\nstruct Polygon {\n  vc<Point<T>> points;\n  T a;\n\n  template <typename\
    \ A, typename B>\n  Polygon(vc<pair<A, B>> pairs) {\n    for (auto&& [a, b]: pairs)\
    \ points.eb(Point<T>(a, b));\n    build();\n  }\n  Polygon(vc<Point<T>> points)\
    \ : points(points) { build(); }\n\n  int size() { return len(points); }\n\n  template\
    \ <typename REAL>\n  REAL area() {\n    return a * 0.5;\n  }\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  T area_2() {\n    return a;\n  }\n\n  bool is_convex() {\n    FOR(j,\
    \ len(points)) {\n      int i = (j == 0 ? len(points) - 1 : j - 1);\n      int\
    \ k = (j == len(points) - 1 ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k]\
    \ - points[j]) < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n\
    \  void build() {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1\
    \ == len(points) ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n\
    \    if (a < 0) {\n      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n\
    #line 2 \"geo/dynamicupperhull.hpp\"\n\r\n/*\r\nhttps://codeforces.com/blog/entry/75929\r\
    \n\u52D5\u7684\u51F8\u5305\u3002\r\nx \u5EA7\u6A19\u3067\u30BD\u30FC\u30C8\u3057\
    \u3066\u5B8C\u5168\u4E8C\u5206\u6728\u306E\u30BB\u30B0\u6728\u306E\u5F62\u306B\
    \u3057\u3066\u304A\u304F\u3002\r\n\u30BB\u30B0\u6728\u306E\u30DE\u30FC\u30B8\u90E8\
    \u5206\uFF08\u6B21\u306E bridge \u3092\u6C42\u3081\u308B\uFF09\u3067\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\u3002\r\nbridge \u540C\u58EB\u306E 4 \u70B9\u3067\u306E\
    \u4E0A\u5074\u51F8\u5305\u3092\u898B\u308C\u3070\u3001\u6B21\u306B\u63A2\u7D22\
    \u3059\u308B\u3079\u304D\u533A\u9593\u5BFE\u304C\u5206\u304B\u308B\u3002\r\n\r\
    \n\u69CB\u7BC9 O(NlogN)\u3001\u66F4\u65B0 O(Nlog^2N)\r\n\u5EA7\u6A19 10^9 \u4EE5\
    \u4E0B\u306E\u6574\u6570\u3092\u4EEE\u5B9A\r\n*/\r\ntemplate<typename Point>\r\
    \nstruct DynamicUpperHull {\r\n  struct node {\r\n    int l, r;   // \u7BC4\u56F2\
    \ (-1 if no vertex)\r\n    int bl, br; // bridge idx\r\n  };\r\n  int N, sz;\r\
    \n  vc<Point> P;\r\n  vc<node> seg;\r\n  // \u53D7\u3051\u53D6\u3063\u305F\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3068\u306E\u5BFE\u5FDC\r\n  vc<int> to_original_idx,\
    \ to_seg_idx;\r\n\r\n  DynamicUpperHull(vc<Point> P) : DynamicUpperHull(P, 0)\
    \ {}\r\n  DynamicUpperHull(vc<Point> P, bool b)\r\n      : DynamicUpperHull(P,\
    \ vc<bool>(len(P), b)) {}\r\n\r\n  DynamicUpperHull(vc<Point> _P, vc<bool> isin)\
    \ : N(len(_P)), P(_P) {\r\n    to_original_idx = argsort(P);\r\n    sort(all(P));\r\
    \n    sz = 1;\r\n    while (sz < N) sz *= 2;\r\n    to_seg_idx.resize(N);\r\n\
    \    seg.assign(sz + sz, {-1, -1, -1, -1});\r\n    for (int i = 0; i < N; ++i)\
    \ to_seg_idx[to_original_idx[i]] = i;\r\n    for (int i = 0; i < N; ++i)\r\n \
    \     if (isin[to_original_idx[i]]) { seg[sz + i] = {i, i + 1, i, i}; }\r\n  \
    \  FOR3_R(i, 1, sz) update(i);\r\n  }\r\n\r\n  void insert(int i) {\r\n    i =\
    \ to_seg_idx[i];\r\n    seg[sz + i] = {i, i + 1, i, i};\r\n    i = (sz + i) /\
    \ 2;\r\n    while (i) {\r\n      update(i);\r\n      i /= 2;\r\n    }\r\n  }\r\
    \n\r\n  void erase(int i) {\r\n    i = to_seg_idx[i];\r\n    seg[sz + i] = {-1,\
    \ -1, -1, -1};\r\n    i = (sz + i) / 2;\r\n    while (i) {\r\n      update(i);\r\
    \n      i /= 2;\r\n    }\r\n  }\r\n\r\n  inline bool exist(int i) { return seg[i].r\
    \ != -1; }\r\n\r\n  void update(int i) {\r\n    if (!exist(2 * i + 0) && !exist(2\
    \ * i + 1)) {\r\n      seg[i].r = -1;\r\n      return;\r\n    }\r\n    if (!exist(2\
    \ * i + 0)) {\r\n      seg[i] = seg[2 * i + 1];\r\n      return;\r\n    }\r\n\
    \    if (!exist(2 * i + 1)) {\r\n      seg[i] = seg[2 * i + 0];\r\n      return;\r\
    \n    }\r\n    int p = 2 * i, q = 2 * i + 1;\r\n    ll X = P[seg[q].l].x;\r\n\
    \    while (p < sz || q < sz) {\r\n      if (p < sz && !exist(2 * p + 0)) {\r\n\
    \        p = 2 * p + 1;\r\n        continue;\r\n      }\r\n      if (p < sz &&\
    \ !exist(2 * p + 1)) {\r\n        p = 2 * p + 0;\r\n        continue;\r\n    \
    \  }\r\n      if (q < sz && !exist(2 * q + 0)) {\r\n        q = 2 * q + 1;\r\n\
    \        continue;\r\n      }\r\n      if (q < sz && !exist(2 * q + 1)) {\r\n\
    \        q = 2 * q + 0;\r\n        continue;\r\n      }\r\n      int a = seg[p].bl,\
    \ b = seg[p].br, c = seg[q].bl, d = seg[q].br;\r\n      if (a != b && (P[b] -\
    \ P[a]).det(P[c] - P[a]) > 0) p = p * 2 + 0;\r\n      elif (c != d && (P[c] -\
    \ P[b]).det(P[d] - P[b]) > 0) q = 2 * q + 1;\r\n      elif (a == b) q = 2 * q\
    \ + 0;\r\n      elif (c == d) p = 2 * p + 1;\r\n      else {\r\n        i128 c1\
    \ = (P[b] - P[a]).det(P[c] - P[a]);\r\n        i128 c2 = (P[a] - P[b]).det(P[d]\
    \ - P[b]);\r\n        if (c1 + c2 == 0 || c1 * P[d].x + c2 * P[c].x < X * (c1\
    \ + c2)) {\r\n          p = 2 * p + 1;\r\n        } else {\r\n          q = 2\
    \ * q + 0;\r\n        }\r\n      }\r\n    }\r\n    seg[i].l = seg[2 * i].l, seg[i].r\
    \ = seg[2 * i + 1].r;\r\n    seg[i].bl = seg[p].l, seg[i].br = seg[q].l;\r\n \
    \ }\r\n\r\n  vc<int> get() {\r\n    // output sensitive complexity\r\n    vc<int>\
    \ res;\r\n    auto dfs = [&](auto self, int k, int l, int r) -> void {\r\n   \
    \   if (!exist(k) || l >= r) return;\r\n      if (k >= sz) {\r\n        res.eb(seg[k].l);\r\
    \n        return;\r\n      }\r\n      if (!exist(2 * k + 0)) return self(self,\
    \ 2 * k + 1, l, r);\r\n      if (!exist(2 * k + 1)) return self(self, 2 * k +\
    \ 0, l, r);\r\n      if (r <= seg[k].bl) return self(self, 2 * k + 0, l, r);\r\
    \n      if (seg[k].br <= l) return self(self, 2 * k + 1, l, r);\r\n      self(self,\
    \ 2 * k + 0, l, seg[k].bl + 1);\r\n      self(self, 2 * k + 1, seg[k].br, r);\r\
    \n    };\r\n    dfs(dfs, 1, 0, N);\r\n    for (auto&& i: res) i = to_original_idx[i];\r\
    \n    return res;\r\n  }\r\n\r\n  void debug() {\r\n    print(\"points\");\r\n\
    \    FOR(i, len(P)) print(i, P[i].x, P[i].y);\r\n    print(\"seg\");\r\n    FOR(i,\
    \ len(seg)) print(i, seg[i].l, seg[i].r, seg[i].bl, seg[i].br);\r\n    print(\"\
    get\");\r\n    print(get());\r\n  }\r\n};\r\n#line 5 \"test/library_checker/geometry/convex_layers.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N);\r\n  vc<Point<ll>> pts(N);\r\n  FOR(i, N) read(pts[i].x),\
    \ read(pts[i].y);\r\n  DynamicUpperHull DUH(pts, 1);\r\n  FOR(i, N) pts[i] = -pts[i];\r\
    \n  DynamicUpperHull DLH(pts, 1);\r\n  vc<int> ANS(N, -1);\r\n  int done = 0;\r\
    \n  int k = 0;\r\n  while (done < N) {\r\n    ++k;\r\n    auto A = DUH.get();\r\
    \n    auto B = DLH.get();\r\n    A.insert(A.end(), all(B));\r\n    for (auto&&\
    \ i: A)\r\n      if (ANS[i] == -1) {\r\n        ++done;\r\n        ANS[i] = k;\r\
    \n        DUH.erase(i);\r\n        DLH.erase(i);\r\n      }\r\n  }\r\n  for (auto&&\
    \ x: ANS) print(x);\r\n}\r\n\r\nsigned main() {\r\n  solve();\r\n\r\n  return\
    \ 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convex_layers\"\r\n#include\
    \ \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"geo/dynamicupperhull.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(N);\r\n  vc<Point<ll>> pts(N);\r\n  FOR(i, N) read(pts[i].x),\
    \ read(pts[i].y);\r\n  DynamicUpperHull DUH(pts, 1);\r\n  FOR(i, N) pts[i] = -pts[i];\r\
    \n  DynamicUpperHull DLH(pts, 1);\r\n  vc<int> ANS(N, -1);\r\n  int done = 0;\r\
    \n  int k = 0;\r\n  while (done < N) {\r\n    ++k;\r\n    auto A = DUH.get();\r\
    \n    auto B = DLH.get();\r\n    A.insert(A.end(), all(B));\r\n    for (auto&&\
    \ i: A)\r\n      if (ANS[i] == -1) {\r\n        ++done;\r\n        ANS[i] = k;\r\
    \n        DUH.erase(i);\r\n        DLH.erase(i);\r\n      }\r\n  }\r\n  for (auto&&\
    \ x: ANS) print(x);\r\n}\r\n\r\nsigned main() {\r\n  solve();\r\n\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - geo/dynamicupperhull.hpp
  - geo/base.hpp
  isVerificationFile: true
  path: test/library_checker/geometry/convex_layers.test.cpp
  requiredBy: []
  timestamp: '2022-08-28 09:19:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/geometry/convex_layers.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/geometry/convex_layers.test.cpp
- /verify/test/library_checker/geometry/convex_layers.test.cpp.html
title: test/library_checker/geometry/convex_layers.test.cpp
---
