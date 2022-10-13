---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':question:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: ds/point_add_rectangle_sum.hpp
    title: ds/point_add_rectangle_sum.hpp
  - icon: ':heavy_check_mark:'
    path: ds/rectangle_add_ractangle_sum.hpp
    title: ds/rectangle_add_ractangle_sum.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum\"\
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
    \ { yes(!t); }\r\n#line 5 \"test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp\"\
    \n\n#line 2 \"ds/rectangle_add_ractangle_sum.hpp\"\n\n#line 2 \"alg/group_add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Group_Add {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\n\ntemplate <typename\
    \ AbelGroup>\nstruct FenwickTree {\n  using E = typename AbelGroup::value_type;\n\
    \  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree(int n = 0) : n(n) {\n\
    \    assert(AbelGroup::commute);\n    reset(n);\n  }\n  FenwickTree(const vector<E>&\
    \ v) {\n    assert(AbelGroup::commute);\n    build(v);\n  }\n\n  void build(const\
    \ vc<E>& v) {\n    n = len(v);\n    total = AbelGroup::unit();\n    for (int i\
    \ = 0; i < n; ++i) total = AbelGroup::op(total, v[i]);\n    dat = v;\n    for\
    \ (int i = 1; i <= n; ++i) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j\
    \ - 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n  }\n\n  void reset(int\
    \ sz = 0) {\n    if (sz) n = sz;\n    total = AbelGroup::unit();\n    dat.assign(n,\
    \ AbelGroup::unit());\n  }\n\n  E prod(int k) {\n    E ret = AbelGroup::unit();\n\
    \    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret, dat[k - 1]);\n    return\
    \ ret;\n  }\n\n  E prod(int L, int R) {\n    E pos = AbelGroup::unit();\n    while\
    \ (L < R) {\n      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -= R & -R;\n\
    \    }\n    E neg = AbelGroup::unit();\n    while (R < L) {\n      neg = AbelGroup::op(neg,\
    \ dat[L - 1]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n\
    \  }\n\n  E prod_all() { return total; }\n\n  E sum(int k) { return prod(k); }\n\
    \n  E sum(int L, int R) { return prod(L, R); }\n\n  E sum_all() { return total;\
    \ }\n\n  void multiply(int k, E x) {\n    total = AbelGroup::op(total, x);\n \
    \   for (++k; k <= n; k += k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n\n  template <class F>\n \
    \ int max_right(F& check) {\n    assert(check(E(0)));\n    ll i = 0;\n    E s\
    \ = AbelGroup::unit();\n    int k = 1;\n    int N = dat.size() + 1;\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(AbelGroup::op(s,\
    \ dat[i + k - 1]))) {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n\
    \      }\n      k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth(E k) {\n\
    \    auto check = [&](E x) -> bool { return x <= k; };\n    return max_right(check);\n\
    \  }\n\n  void debug() { print(\"fenwick\", dat); }\n};\n#line 3 \"ds/point_add_rectangle_sum.hpp\"\
    \n\r\n\r\ntemplate <typename AbelGroup, bool SMALL = false>\r\nstruct Point_Add_Rectangle_Sum\
    \ {\r\n  using G = typename AbelGroup::value_type;\r\n  int Q;\r\n  vector<ll>\
    \ X, Y;\r\n  vector<G> WT;\r\n  vector<tuple<ll, ll, ll, ll>> rect;\r\n\r\n  Point_Add_Rectangle_Sum()\
    \ {}\r\n\r\n  void add_query(ll x, ll y, G w) {\r\n    X.emplace_back(x), Y.emplace_back(y),\
    \ WT.emplace_back(w);\r\n  }\r\n\r\n  void sum_query(ll xl, ll yl, ll xr, ll yr)\
    \ {\r\n    rect.emplace_back(xl, yl, xr, yr);\r\n  }\r\n\r\n  vector<G> calc()\
    \ {\r\n    int N = X.size(), Q = rect.size();\r\n    if (N == 0) return vector<G>(Q,\
    \ AbelGroup::unit());\r\n    int NX = 0, NY = 0;\r\n    if (!SMALL) {\r\n    \
    \  vector<ll> keyX = X, keyY = Y;\r\n      sort(all(keyX));\r\n      keyX.erase(unique(all(keyX)),\
    \ keyX.end());\r\n      sort(all(keyY));\r\n      keyY.erase(unique(all(keyY)),\
    \ keyY.end());\r\n      NX = keyX.size(), NY = keyY.size();\r\n      for (auto\
    \ &&x: X) x = lower_bound(all(keyX), x) - keyX.begin();\r\n      for (auto &&y:\
    \ Y) y = lower_bound(all(keyY), y) - keyY.begin();\r\n      for (auto &&[xl, yl,\
    \ xr, yr]: rect) {\r\n        xl = lower_bound(all(keyX), xl) - keyX.begin();\r\
    \n        xr = lower_bound(all(keyX), xr) - keyX.begin();\r\n        yl = lower_bound(all(keyY),\
    \ yl) - keyY.begin();\r\n        yr = lower_bound(all(keyY), yr) - keyY.begin();\r\
    \n      }\r\n    }\r\n    if (SMALL) {\r\n      ll mx = *(min_element(X.begin(),\
    \ X.end()));\r\n      ll my = *(min_element(Y.begin(), Y.end()));\r\n      for\
    \ (auto &&x: X) x -= mx;\r\n      for (auto &&y: Y) y -= my;\r\n      NX = *(max_element(X.begin(),\
    \ X.end())) + 1;\r\n      NY = *(max_element(Y.begin(), Y.end())) + 1;\r\n   \
    \   for (auto &&[xl, yl, xr, yr]: rect) {\r\n        xl -= mx, xr -= mx;\r\n \
    \       yl -= my, yr -= my;\r\n        xl = max(0, min<int>(xl, NX));\r\n    \
    \    xr = max(0, min<int>(xr, NX));\r\n        yl = max(0, min<int>(yl, NY));\r\
    \n        yr = max(0, min<int>(yr, NY));\r\n      }\r\n    }\r\n    vector<vector<pair<int,\
    \ G>>> ADD(NY + 1);\r\n    vector<vector<tuple<int, int, int>>> CALC_1(NY + 1);\r\
    \n    vector<vector<tuple<int, int, int>>> CALC_2(NY + 1);\r\n    for (int n =\
    \ 0; n < N; ++n) { ADD[Y[n]].emplace_back(X[n], WT[n]); }\r\n    for (int q =\
    \ 0; q < Q; ++q) {\r\n      auto &[xl, yl, xr, yr] = rect[q];\r\n      CALC_1[yr].emplace_back(xl,\
    \ xr, q);\r\n      CALC_2[yl].emplace_back(xl, xr, q);\r\n    };\r\n\r\n    vector<G>\
    \ res(Q, AbelGroup::unit());\r\n    FenwickTree<AbelGroup> bit(NX);\r\n\r\n  \
    \  for (int y = 0; y <= NY; ++y) {\r\n      for (auto &&[xl, xr, q]: CALC_1[y])\
    \ {\r\n        auto x = bit.prod(xl, xr);\r\n        res[q] = AbelGroup::op(res[q],\
    \ x);\r\n      }\r\n      for (auto &&[xl, xr, q]: CALC_2[y]) {\r\n        auto\
    \ x = AbelGroup::inverse(bit.prod(xl, xr));\r\n        res[q] = AbelGroup::op(res[q],\
    \ x);\r\n      }\r\n      for (auto &&[x, g]: ADD[y]) { bit.add(x, g); }\r\n \
    \   }\r\n    return res;\r\n  }\r\n};\r\n#line 4 \"ds/rectangle_add_ractangle_sum.hpp\"\
    \n\ntemplate <typename AbelGroup, bool SMALL = false>\nstruct Rectangle_Add_Rectangle_Sum\
    \ {\n  using WT = typename AbelGroup::value_type;\n  using WT4 = tuple<WT, WT,\
    \ WT, WT>;\n\n  struct G {\n    using X = WT4;\n    using value_type = X;\n  \
    \  static X op(const X &x, const X &y) {\n      auto &[ax, bx, cx, dx] = x;\n\
    \      auto &[ay, by, cy, dy] = y;\n      return {AbelGroup::op(ax, ay), AbelGroup::op(bx,\
    \ by),\n              AbelGroup::op(cx, cy), AbelGroup::op(dx, dy)};\n    }\n\
    \    static X inverse(const X &x) {\n      auto &[ax, bx, cx, dx] = x;\n     \
    \ return {AbelGroup::inverse(ax), AbelGroup::inverse(bx),\n              AbelGroup::inverse(cx),\
    \ AbelGroup::inverse(dx)};\n    }\n    static X power(const X &x, ll n) {\n  \
    \    auto &[ax, bx, cx, dx] = x;\n      return {AbelGroup::power(ax, n), AbelGroup::power(bx,\
    \ n),\n              AbelGroup::power(cx, n), AbelGroup::power(dx, n)};\n    }\n\
    \    static constexpr X unit() {\n      auto u = AbelGroup::unit();\n      return\
    \ {u, u, u, u};\n    }\n    static constexpr bool commute = true;\n  };\n\n  vector<tuple<ll,\
    \ ll, ll, ll>> query;\n  Point_Add_Rectangle_Sum<G, SMALL> X;\n  ll min_x = 0,\
    \ min_y = 0;\n\n  void add_query(ll xl, ll yl, ll xr, ll yr, WT w) {\n    assert(xl\
    \ <= xr && yl <= yr);\n    min_x = min(min_x, xl);\n    min_y = min(min_y, yl);\n\
    \    // (xl,yl) \u306B (x-xl)(y-yl) \u3092\u52A0\u7B97\n    auto nw = AbelGroup::inverse(w);\n\
    \    X.add_query(xl, yl,\n                {w, AbelGroup::power(w, -yl), AbelGroup::power(w,\
    \ -xl),\n                 AbelGroup::power(w, +xl * yl)});\n    // (xl,yr) \u306B\
    \ (x-xl)(y-yr) \u3092\u6E1B\u7B97\n    X.add_query(xl, yr,\n                {nw,\
    \ AbelGroup::power(w, +yr), AbelGroup::power(w, +xl),\n                 AbelGroup::power(w,\
    \ -xl * yr)});\n    // (xr,yl) \u306B (x-xr)(y-yl) \u3092\u6E1B\u7B97\n    X.add_query(xr,\
    \ yl,\n                {nw, AbelGroup::power(w, +yl), AbelGroup::power(w, +xr),\n\
    \                 AbelGroup::power(w, -xr * yl)});\n    // (xr,yr) \u306B (x-xr)(y-yr)\
    \ \u3092\u52A0\u7B97\n    X.add_query(xr, yr,\n                {w, AbelGroup::power(w,\
    \ -yr), AbelGroup::power(w, -xr),\n                 AbelGroup::power(w, +xr *\
    \ yr)});\n  }\n\n  void sum_query(ll xl, ll yl, ll xr, ll yr) {\n    assert(xl\
    \ <= xr && yl <= yr);\n    query.emplace_back(xl, yl, xr, yr);\n    X.sum_query(min_x,\
    \ min_y, xl, yl);\n    X.sum_query(min_x, min_y, xl, yr);\n    X.sum_query(min_x,\
    \ min_y, xr, yl);\n    X.sum_query(min_x, min_y, xr, yr);\n  }\n\n  vector<WT>\
    \ calc() {\n    ll Q = query.size();\n    vector<WT> ANS(Q);\n    auto tmp = X.calc();\n\
    \n    for (int q = 0; q < Q; ++q) {\n      auto [xl, yl, xr, yr] = query[q];\n\
    \      WT p = AbelGroup::unit(), m = AbelGroup::unit();\n      {\n        auto\
    \ [a, b, c, d] = tmp[4 * q + 0];\n        p = AbelGroup::op(p, AbelGroup::power(a,\
    \ xl * yl));\n        p = AbelGroup::op(p, AbelGroup::power(b, xl));\n       \
    \ p = AbelGroup::op(p, AbelGroup::power(c, yl));\n        p = AbelGroup::op(p,\
    \ d);\n      }\n      {\n        auto [a, b, c, d] = tmp[4 * q + 1];\n       \
    \ m = AbelGroup::op(m, AbelGroup::power(a, xl * yr));\n        m = AbelGroup::op(m,\
    \ AbelGroup::power(b, xl));\n        m = AbelGroup::op(m, AbelGroup::power(c,\
    \ yr));\n        m = AbelGroup::op(m, d);\n      }\n      {\n        auto [a,\
    \ b, c, d] = tmp[4 * q + 2];\n        m = AbelGroup::op(m, AbelGroup::power(a,\
    \ xr * yl));\n        m = AbelGroup::op(m, AbelGroup::power(b, xr));\n       \
    \ m = AbelGroup::op(m, AbelGroup::power(c, yl));\n        m = AbelGroup::op(m,\
    \ d);\n      }\n      {\n        auto [a, b, c, d] = tmp[4 * q + 3];\n       \
    \ p = AbelGroup::op(p, AbelGroup::power(a, xr * yr));\n        p = AbelGroup::op(p,\
    \ AbelGroup::power(b, xr));\n        p = AbelGroup::op(p, AbelGroup::power(c,\
    \ yr));\n        p = AbelGroup::op(p, d);\n      }\n      ANS[q] = AbelGroup::op(p,\
    \ AbelGroup::inverse(m));\n    }\n    return ANS;\n  }\n};\n#line 2 \"mod/modint.hpp\"\
    \n\ntemplate <int mod>\nstruct modint {\n  static constexpr bool is_modint = true;\n\
    \  int val;\n  constexpr modint(const ll val = 0) noexcept\n      : val(val >=\
    \ 0 ? val % mod : (mod - (-val) % mod) % mod) {}\n  bool operator<(const modint\
    \ &other) const {\n    return val < other.val;\n  } // To use std::map\n  modint\
    \ &operator+=(const modint &p) {\n    if ((val += p.val) >= mod) val -= mod;\n\
    \    return *this;\n  }\n  modint &operator-=(const modint &p) {\n    if ((val\
    \ += mod - p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint &operator*=(const\
    \ modint &p) {\n    val = (int)(1LL * val * p.val % mod);\n    return *this;\n\
    \  }\n  modint &operator/=(const modint &p) {\n    *this *= p.inverse();\n   \
    \ return *this;\n  }\n  modint operator-() const { return modint(-val); }\n  modint\
    \ operator+(const modint &p) const { return modint(*this) += p; }\n  modint operator-(const\
    \ modint &p) const { return modint(*this) -= p; }\n  modint operator*(const modint\
    \ &p) const { return modint(*this) *= p; }\n  modint operator/(const modint &p)\
    \ const { return modint(*this) /= p; }\n  bool operator==(const modint &p) const\
    \ { return val == p.val; }\n  bool operator!=(const modint &p) const { return\
    \ val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod, u = 1,\
    \ v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(int64_t\
    \ n) const {\n    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n &\
    \ 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n  static constexpr int get_mod() { return mod; }\n};\n\nstruct ArbitraryModInt\
    \ {\n  static constexpr bool is_modint = true;\n  int val;\n  ArbitraryModInt()\
    \ : val(0) {}\n  ArbitraryModInt(int64_t y)\n      : val(y >= 0 ? y % get_mod()\n\
    \                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n  bool operator<(const\
    \ ArbitraryModInt &other) const {\n    return val < other.val;\n  } // To use\
    \ std::map<ArbitraryModInt, T>\n  static int &get_mod() {\n    static int mod\
    \ = 0;\n    return mod;\n  }\n  static void set_mod(int md) { get_mod() = md;\
    \ }\n  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {\n    if ((val +=\
    \ p.val) >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt\
    \ &operator-=(const ArbitraryModInt &p) {\n    if ((val += get_mod() - p.val)\
    \ >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt &operator*=(const\
    \ ArbitraryModInt &p) {\n    long long a = (long long)val * p.val;\n    int xh\
    \ = (int)(a >> 32), xl = (int)a, d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d),\
    \ \"=d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\n    val = m;\n    return\
    \ *this;\n  }\n  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\n   \
    \ *this *= p.inverse();\n    return *this;\n  }\n  ArbitraryModInt operator-()\
    \ const { return ArbitraryModInt(get_mod() - val); }\n  ArbitraryModInt operator+(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) += p;\n  }\n\
    \  ArbitraryModInt operator-(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ -= p;\n  }\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) *= p;\n  }\n  ArbitraryModInt operator/(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) /= p;\n  }\n\
    \  bool operator==(const ArbitraryModInt &p) const { return val == p.val; }\n\
    \  bool operator!=(const ArbitraryModInt &p) const { return val != p.val; }\n\
    \  ArbitraryModInt inverse() const {\n    int a = val, b = get_mod(), u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n  }\n  ArbitraryModInt\
    \ pow(int64_t n) const {\n    ArbitraryModInt ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n};\n\ntemplate <typename mint>\nmint inv(int n) {\n\
    \  static const int mod = mint::get_mod();\n  static vector<mint> dat = {0, 1};\n\
    \  assert(0 <= n);\n  if (n >= mod) n %= mod;\n  while (int(dat.size()) <= n)\
    \ {\n    int k = dat.size();\n    auto q = (mod + k - 1) / k;\n    int r = k *\
    \ q - mod;\n    dat.emplace_back(dat[r] * mint(q));\n  }\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n\
    \  static vector<mint> dat = {1, 1};\n  assert(0 <= n);\n  if (n >= mod) return\
    \ 0;\n  while (int(dat.size()) <= n) {\n    int k = dat.size();\n    dat.emplace_back(dat[k\
    \ - 1] * mint(k));\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint\
    \ fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  assert(0 <= n && n < mod);\n  while (int(dat.size()) <= n)\
    \ {\n    int k = dat.size();\n    dat.emplace_back(dat[k - 1] * inv<mint>(k));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint C_dense(int n, int\
    \ k) {\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n\n  auto calc = [&](int\
    \ i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n\
    \    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n\n  if (W <= k) {\n\
    \    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j]\
    \ = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n\
    \ + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j]\
    \ = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C(ll n, ll k)\
    \ {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if (dense) return C_dense<mint>(n,\
    \ k);\n  if (!large) return fact<mint>(n) * fact_inv<mint>(k) * fact_inv<mint>(n\
    \ - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) { x *= mint(n - i); }\n\
    \  x *= fact_inv<mint>(k);\n  return x;\n}\n\ntemplate <typename mint, bool large\
    \ = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k\
    \ <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d] (1-x) ^ {-n} \u306E\
    \u8A08\u7B97\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n\
    \  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large,\
    \ dense>(n + d - 1, d);\n}\n\nusing modint107 = modint<1000000007>;\nusing modint998\
    \ = modint<998244353>;\nusing amint = ArbitraryModInt;\n#line 9 \"test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  LL(N, Q);\n  Rectangle_Add_Rectangle_Sum<Group_Add<mint>>\
    \ X;\n\n  FOR(N) {\n    LL(l, d, r, u, w);\n    X.add_query(l, d, r, u, w);\n\
    \  }\n  FOR(Q) {\n    LL(l, d, r, u);\n    X.sum_query(l, d, r, u);\n  }\n  auto\
    \ ans = X.calc();\n  for (auto&& x: ans) print(x);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  ll T = 1;\n\
    \  // LL(T);\n  FOR(_, T) solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/rectangle_add_ractangle_sum.hpp\"\
    \n#include \"mod/modint.hpp\"\n#include \"alg/group_add.hpp\"\n\nusing mint =\
    \ modint998;\n\nvoid solve() {\n  LL(N, Q);\n  Rectangle_Add_Rectangle_Sum<Group_Add<mint>>\
    \ X;\n\n  FOR(N) {\n    LL(l, d, r, u, w);\n    X.add_query(l, d, r, u, w);\n\
    \  }\n  FOR(Q) {\n    LL(l, d, r, u);\n    X.sum_query(l, d, r, u);\n  }\n  auto\
    \ ans = X.calc();\n  for (auto&& x: ans) print(x);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  ll T = 1;\n\
    \  // LL(T);\n  FOR(_, T) solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/rectangle_add_ractangle_sum.hpp
  - ds/point_add_rectangle_sum.hpp
  - ds/fenwick.hpp
  - alg/group_add.hpp
  - mod/modint.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2022-10-12 08:05:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
- /verify/test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp.html
title: test/library_checker/datastructure/static_rectangle_add_rectangle_sum.test.cpp
---
