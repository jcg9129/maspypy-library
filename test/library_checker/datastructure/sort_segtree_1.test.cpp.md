---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group/affine.hpp
    title: alg/group/affine.hpp
  - icon: ':question:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  - icon: ':x:'
    path: ds/sortable_segtree.hpp
    title: ds/sortable_segtree.hpp
  - icon: ':question:'
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_sort_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_sort_range_composite
  bundledCode: "#line 1 \"test/library_checker/datastructure/sort_segtree_1.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/point_set_range_sort_range_composite\"\
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
    \ { yes(!t); }\r\n#line 1 \"ds/fastset.hpp\"\n/* 64\u5206\u6728\u3002\r\ninsert,\
    \ erase\r\n[]\u3067\u306E\u5B58\u5728\u5224\u5B9A\r\nnext, prev\r\n*/\r\nstruct\
    \ FastSet {\r\n  using uint = unsigned;\r\n  using ull = unsigned long long;\r\
    \n\r\n  int bsr(ull x) { return 63 - __builtin_clzll(x); }\r\n  int bsf(ull x)\
    \ { return __builtin_ctzll(x); }\r\n\r\n  static constexpr uint B = 64;\r\n  int\
    \ n, lg;\r\n  vector<vector<ull>> seg;\r\n  FastSet(int _n) : n(_n) {\r\n    do\
    \ {\r\n      seg.push_back(vector<ull>((_n + B - 1) / B));\r\n      _n = (_n +\
    \ B - 1) / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\n  }\r\n\
    \  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0;\
    \ }\r\n  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i\
    \ / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n  void erase(int\
    \ i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i / B] &= ~(1ULL\
    \ << (i % B));\r\n      if (seg[h][i / B]) break;\r\n      i /= B;\r\n    }\r\n\
    \  }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\u8FD4\u3059\
    \u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\r\n  int next(int i)\
    \ {\r\n    for (int h = 0; h < lg; h++) {\r\n      if (i / B == seg[h].size())\
    \ break;\r\n      ull d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n   \
    \     i = i / B + 1;\r\n        continue;\r\n      }\r\n      // find\r\n    \
    \  i += bsf(d);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\
    \n        i += bsf(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n\
    \    return n;\r\n  }\r\n\r\n  // x\u4EE5\u4E0B\u6700\u5927\u306E\u8981\u7D20\u3092\
    \u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 -1\u3002\r\n  int\
    \ prev(int i) {\r\n    if (i < 0) return -1;\r\n    if (i >= n) i = n - 1;\r\n\
    \    for (int h = 0; h < lg; h++) {\r\n      if (i == -1) break;\r\n      ull\
    \ d = seg[h][i / B] << (63 - i % 64);\r\n      if (!d) {\r\n        i = i / B\
    \ - 1;\r\n        continue;\r\n      }\r\n      // find\r\n      i += bsr(d) -\
    \ (B - 1);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n\
    \        i += bsr(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n \
    \   return -1;\r\n  }\r\n\r\n  // [l, r) \u5185\u306E\u8981\u7D20\u3092\u5168\u90E8\
    \u96C6\u3081\u308B\r\n  vector<int> collect(int l, int r) {\r\n    vector<int>\
    \ res;\r\n    int x = l - 1;\r\n    while (1) {\r\n      x = next(x + 1);\r\n\
    \      if (x >= r) break;\r\n      res.emplace_back(x);\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n  void debug() {\r\n    string s;\r\n    for (int i = 0;\
    \ i < n; ++i) s += ((*this)[i] ? '1' : '0');\r\n    print(s);\r\n  }\r\n};\r\n\
    #line 2 \"ds/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct SegTree {\n  using\
    \ X = typename Monoid::value_type;\n  using value_type = X;\n  vector<X> dat;\n\
    \  int n, log, size;\n\n  SegTree() : SegTree(0) {}\n  SegTree(int n) : SegTree(vector<X>(n,\
    \ Monoid::unit())) {}\n  SegTree(vector<X> v) : n(v.size()) {\n    log = 1;\n\
    \    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, Monoid::unit());\n    for (int i = 0; i < n; ++i) dat[size + i] = v[i];\n\
    \    for (int i = size - 1; i >= 1; --i) update(i);\n  }\n\n  template <typename\
    \ F>\n  SegTree(int n, F f) : n(n) {\n    log = 1;\n    while ((1 << log) < n)\
    \ ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid::unit());\n \
    \   for (int i = 0; i < n; ++i) dat[size + i] = f(i);\n    for (int i = size -\
    \ 1; i >= 1; --i) update(i);\n  }\n\n  void reset() { fill(all(dat), Monoid::unit());\
    \ }\n\n  void set_all(const vector<X>& v) {\n    dat.assign(size << 1, Monoid::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[size + i] = v[i];\n    for (int i = size\
    \ - 1; i >= 1; --i) update(i);\n  }\n\n  X operator[](int i) { return dat[size\
    \ + i]; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i\
    \ + 1]); }\n\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i +=\
    \ size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const\
    \ X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(L\
    \ <= R);\n    assert(R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F& check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) {\n      \
    \      sm = Monoid::op(sm, dat[L]);\n            L++;\n          }\n        }\n\
    \        return L - size;\n      }\n      sm = Monoid::op(sm, dat[L]);\n     \
    \ L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F& check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R], sm);\n\
    \            R--;\n          }\n        }\n        return R + 1 - size;\n    \
    \  }\n      sm = Monoid::op(dat[R], sm);\n    } while ((R & -R) != R);\n    return\
    \ 0;\n  }\n\n  // \u30E2\u30CE\u30A4\u30C9\u304C\u53EF\u63DB\u306A\u3089\u3001\
    prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\u53EF\u80FD\n  // https://codeforces.com/contest/1401/problem/F\n\
    \  X Xor_prod(int l, int r, int xor_val) {\n    assert(Monoid::commute);\n   \
    \ X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if (l\
    \ >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n\n  void debug() { print(\"segtree\", dat); }\n};\n#line 3 \"ds/sortable_segtree.hpp\"\
    \n\ntemplate <typename Monoid, int NODES = 4'000'000>\nstruct Sortable_SegTree\
    \ {\n  using X = typename Monoid::value_type;\n  const int N, KEY_MAX;\n\n  struct\
    \ Node {\n    X x, rev_x;\n    int size;\n    Node *l, *r;\n    Node() {}\n  };\n\
    \n  Node* pool;\n  int pid;\n\n  // \u533A\u9593\u306E\u5DE6\u7AEF\u5168\u4F53\
    \u3092\u8868\u3059 fastset\n  FastSet ss;\n  // \u533A\u9593\u3092\u96C6\u7D04\
    \u3057\u305F\u5024\u3092\u533A\u9593\u306E\u5DE6\u7AEF\u306B\u306E\u305B\u305F\
    \ segtree\n  SegTree<Monoid> seg;\n  // \u533A\u9593\u306E\u5DE6\u7AEF\u306B\u3001\
    dynamic segtree \u306E node \u3092\u4E57\u305B\u308B\n  vector<bool> rev;\n  vector<Node*>\
    \ root;\n  Sortable_SegTree(int KEY_MAX, vector<int> key, vector<X> dat)\n   \
    \   : N(key.size()), KEY_MAX(KEY_MAX), pid(0), ss(key.size()), seg(dat) {\n  \
    \  pool = new Node[NODES];\n    init(key, dat);\n  }\n\n  void set(int i, int\
    \ key, const X& x) {\n    assert(key < KEY_MAX);\n    split_at(i);\n    split_at(i\
    \ + 1);\n    rev[i] = 0;\n    root[i] = new_node();\n    set_rec_key(root[i],\
    \ 0, KEY_MAX, key, x);\n    seg.set(i, x);\n  }\n\n  X prod_all() { return seg.prod_all();\
    \ }\n\n  X prod(int l, int r) {\n    if (pid > NODES * 0.9) rebuild();\n    split_at(l),\
    \ split_at(r);\n    return seg.prod(l, r);\n  }\n\n  void sort_inc(int l, int\
    \ r) {\n    split_at(l), split_at(r);\n    while (1) {\n      if (pid > NODES\
    \ * 0.9) rebuild();\n      Node* n = root[l];\n      int i = ss.next(l + 1);\n\
    \      if (i == r) break;\n      root[l] = merge(n, root[i]);\n      ss.erase(i);\n\
    \      seg.set(i, Monoid::unit());\n    }\n    rev[l] = 0;\n    seg.set(l, root[l]->x);\n\
    \  };\n\n  void sort_dec(int l, int r) {\n    if (pid > NODES * 0.9) rebuild();\n\
    \    sort_inc(l, r);\n    rev[l] = 1;\n    seg.set(l, root[l]->rev_x);\n  };\n\
    \nprivate:\n  void init(vector<int>& key, vector<X>& dat) {\n    rev.assign(N,\
    \ 0);\n    root.clear();\n    seg.set_all(dat);\n    for (int i = 0; i < N; ++i)\
    \ ss.insert(i);\n    for (int i = 0; i < N; ++i) root.emplace_back(new_node(Monoid::unit()));\n\
    \    for (int i = 0; i < N; ++i) {\n      assert(key[i] < KEY_MAX);\n      set_rec_key(root[i],\
    \ 0, KEY_MAX, key[i], dat[i]);\n    }\n  }\n\n  void split_at(int x) {\n    if\
    \ (x == N || ss[x]) return;\n    int a = ss.prev(x);\n    int b = ss.next(a +\
    \ 1);\n    ss.insert(x);\n    if (!rev[a]) {\n      auto [nl, nr] = split(root[a],\
    \ x - a);\n      root[a] = nl;\n      root[x] = nr;\n      rev[a] = rev[x] = 0;\n\
    \      seg.set(a, root[a]->x);\n      seg.set(x, root[x]->x);\n    } else {\n\
    \      auto [nl, nr] = split(root[a], b - x);\n      root[a] = nr;\n      root[x]\
    \ = nl;\n      rev[a] = rev[x] = 1;\n      seg.set(a, root[a]->rev_x);\n     \
    \ seg.set(x, root[x]->rev_x);\n    }\n  }\n\n  void rebuild() {\n    vector<int>\
    \ key;\n    vector<X> dat;\n    key.reserve(N);\n    dat.reserve(N);\n    auto\
    \ dfs\n        = [&](auto& dfs, Node* n, int node_l, int node_r, bool rev) ->\
    \ void {\n      if (!n) return;\n      if (node_r == node_l + 1) {\n        key.emplace_back(node_l);\n\
    \        dat.emplace_back(n->x);\n        return;\n      }\n      int node_m =\
    \ (node_l + node_r) / 2;\n      if (!rev) {\n        dfs(dfs, n->l, node_l, node_m,\
    \ rev);\n        dfs(dfs, n->r, node_m, node_r, rev);\n      }\n      if (rev)\
    \ {\n        dfs(dfs, n->r, node_m, node_r, rev);\n        dfs(dfs, n->l, node_l,\
    \ node_m, rev);\n      }\n    };\n    for (int i = 0; i < N; ++i) {\n      if\
    \ (ss[i]) dfs(dfs, root[i], 0, KEY_MAX, rev[i]);\n    }\n    assert(int(key.size())\
    \ == N);\n\n    pid = 0;\n    init(key, dat);\n  }\n\n  Node* new_node(X x = Monoid::unit())\
    \ {\n    assert(pid < NODES);\n    pool[pid].x = pool[pid].rev_x = x;\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].size = 1;\n    return &(pool[pid++]);\n\
    \  }\n\n  pair<Node*, Node*> split(Node* n, int k) {\n    if (k == 0) { return\
    \ {nullptr, n}; }\n    if (k == n->size) { return {n, nullptr}; }\n    int s =\
    \ (n->l ? n->l->size : 0);\n    Node* b = new_node();\n    if (k <= s) {\n   \
    \   auto [nl, nr] = split(n->l, k);\n      b->l = nr;\n      b->r = n->r;\n  \
    \    n->l = nl;\n      n->r = nullptr;\n    }\n    if (k > s) {\n      auto [nl,\
    \ nr] = split(n->r, k - s);\n      n->l = n->l;\n      n->r = nl;\n      b->l\
    \ = nullptr;\n      b->r = nr;\n    }\n    update(n);\n    update(b);\n    return\
    \ {n, b};\n  }\n\n  Node* merge(Node* a, Node* b) {\n    if (!a) return b;\n \
    \   if (!b) return a;\n    a->l = merge(a->l, b->l);\n    a->r = merge(a->r, b->r);\n\
    \    update(a);\n    return a;\n  }\n\n  void update(Node* n) {\n    if (!(n->l)\
    \ && !(n->r)) { return; }\n    if (!(n->l)) {\n      n->x = n->r->x, n->rev_x\
    \ = n->r->rev_x;\n      n->size = n->r->size;\n      return;\n    }\n    if (!(n->r))\
    \ {\n      n->x = n->l->x, n->rev_x = n->l->rev_x;\n      n->size = n->l->size;\n\
    \      return;\n    }\n    n->x = Monoid::op(n->l->x, n->r->x);\n    n->rev_x\
    \ = Monoid::op(n->r->rev_x, n->l->rev_x);\n    n->size = n->l->size + n->r->size;\n\
    \  }\n\n  void set_rec_key(Node* n, int node_l, int node_r, int k, const X& x)\
    \ {\n    if (node_r == node_l + 1) {\n      n->x = n->rev_x = x;\n      return;\n\
    \    }\n    int node_m = (node_l + node_r) / 2;\n    if (k < node_m) {\n     \
    \ if (!(n->l)) n->l = new_node();\n      set_rec_key(n->l, node_l, node_m, k,\
    \ x);\n    }\n    if (node_m <= k) {\n      if (!(n->r)) n->r = new_node();\n\
    \      set_rec_key(n->r, node_m, node_r, k, x);\n    }\n    update(n);\n  }\n\n\
    \  void set_rec_idx(Node* n, int node_l, int node_r, int idx, const X& x) {\n\
    \    if (node_r == node_l + 1) {\n      n->x = n->rev_x = x;\n      return;\n\
    \    }\n    int node_m = (node_l + node_r) / 2;\n    int s = (n->l ? n->l->size\
    \ : 0);\n    if (idx < s) { set_rec_idx(n->l, node_l, node_m, idx, x); }\n   \
    \ if (idx >= s) { set_rec_idx(n->r, node_m, node_r, idx - s, x); }\n    update(n);\n\
    \  }\n};\n#line 1 \"alg/group/affine.hpp\"\ntemplate <typename K>\nstruct Group_Affine\
    \ {\n  using F = pair<K, K>;\n  using value_type = F;\n  static constexpr F op(const\
    \ F &x, const F &y) noexcept {\n    return F({x.first * y.first, x.second * y.first\
    \ + y.second});\n  }\n  static constexpr F inverse(const F &x) {\n    auto [a,\
    \ b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static constexpr\
    \ K eval(const F &f, K x) noexcept {\n    return f.first * x + f.second;\n  }\n\
    \  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr bool\
    \ commute = false;\n};\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct\
    \ modint {\n  static constexpr bool is_modint = true;\n  int val;\n  constexpr\
    \ modint(const ll val = 0) noexcept\n      : val(val >= 0 ? val % mod : (mod -\
    \ (-val) % mod) % mod) {}\n  bool operator<(const modint &other) const {\n   \
    \ return val < other.val;\n  } // To use std::map\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= mod) val -= mod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += mod - p.val) >=\
    \ mod) val -= mod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = (int)(1LL * val * p.val % mod);\n    return *this;\n  }\n \
    \ modint &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  modint operator-() const { return modint(-val); }\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n  modint operator*(const modint &p)\
    \ const { return modint(*this) *= p; }\n  modint operator/(const modint &p) const\
    \ { return modint(*this) /= p; }\n  bool operator==(const modint &p) const { return\
    \ val == p.val; }\n  bool operator!=(const modint &p) const { return val != p.val;\
    \ }\n  modint inverse() const {\n    int a = val, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(int64_t n) const {\n\
    \    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr\
    \ int get_mod() { return mod; }\n};\n\nstruct ArbitraryModInt {\n  static constexpr\
    \ bool is_modint = true;\n  int val;\n  ArbitraryModInt() : val(0) {}\n  ArbitraryModInt(int64_t\
    \ y)\n      : val(y >= 0 ? y % get_mod()\n                   : (get_mod() - (-y)\
    \ % get_mod()) % get_mod()) {}\n  bool operator<(const ArbitraryModInt &other)\
    \ const {\n    return val < other.val;\n  } // To use std::map<ArbitraryModInt,\
    \ T>\n  static int &get_mod() {\n    static int mod = 0;\n    return mod;\n  }\n\
    \  static void set_mod(int md) { get_mod() = md; }\n  ArbitraryModInt &operator+=(const\
    \ ArbitraryModInt &p) {\n    if ((val += p.val) >= get_mod()) val -= get_mod();\n\
    \    return *this;\n  }\n  ArbitraryModInt &operator-=(const ArbitraryModInt &p)\
    \ {\n    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();\n    return\
    \ *this;\n  }\n  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {\n   \
    \ long long a = (long long)val * p.val;\n    int xh = (int)(a >> 32), xl = (int)a,\
    \ d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"=d\"(m) : \"d\"(xh), \"a\"\
    (xl), \"r\"(get_mod()));\n    val = m;\n    return *this;\n  }\n  ArbitraryModInt\
    \ &operator/=(const ArbitraryModInt &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  ArbitraryModInt operator-() const { return ArbitraryModInt(get_mod()\
    \ - val); }\n  ArbitraryModInt operator+(const ArbitraryModInt &p) const {\n \
    \   return ArbitraryModInt(*this) += p;\n  }\n  ArbitraryModInt operator-(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) -= p;\n  }\n\
    \  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ *= p;\n  }\n  ArbitraryModInt operator/(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) /= p;\n  }\n  bool operator==(const ArbitraryModInt\
    \ &p) const { return val == p.val; }\n  bool operator!=(const ArbitraryModInt\
    \ &p) const { return val != p.val; }\n  ArbitraryModInt inverse() const {\n  \
    \  int a = val, b = get_mod(), u = 1, v = 0, t;\n    while (b > 0) {\n      t\
    \ = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return\
    \ ArbitraryModInt(u);\n  }\n  ArbitraryModInt pow(int64_t n) const {\n    ArbitraryModInt\
    \ ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n     \
    \ mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n};\n\ntemplate <typename\
    \ mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n  static\
    \ vector<mint> dat = {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n \
    \ while (int(dat.size()) <= n) {\n    int k = dat.size();\n    auto q = (mod +\
    \ k - 1) / k;\n    int r = k * q - mod;\n    dat.emplace_back(dat[r] * mint(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  static vector<mint> dat = {1, 1};\n  assert(0\
    \ <= n);\n  if (n >= mod) return 0;\n  while (int(dat.size()) <= n) {\n    int\
    \ k = dat.size();\n    dat.emplace_back(dat[k - 1] * mint(k));\n  }\n  return\
    \ dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static const\
    \ int mod = mint::get_mod();\n  static vector<mint> dat = {1, 1};\n  assert(-1\
    \ <= n && n < mod);\n  if (n == -1) return mint(0);\n  while (int(dat.size())\
    \ <= n) {\n    int k = dat.size();\n    dat.emplace_back(dat[k - 1] * inv<mint>(k));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts...\
    \ xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename\
    \ mint, class Head, class... Tail>\nmint multinomial(Head &&head, Tail &&... tail)\
    \ {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint>\
    \ C;\n  static int H = 0, W = 0;\n\n  auto calc = [&](int i, int j) -> mint {\n\
    \    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j]\
    \ + (j ? C[i - 1][j - 1] : 0);\n  };\n\n  if (W <= k) {\n    FOR(i, H) {\n   \
    \   C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n  \
    \  }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H,\
    \ n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n\
    \    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >=\
    \ 0);\n  if (k < 0 || n < k) return 0;\n  if (dense) return C_dense<mint>(n, k);\n\
    \  if (!large) return fact<mint>(n) * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n\
    \  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) { x *= mint(n - i); }\n  x *=\
    \ fact_inv<mint>(k);\n  return x;\n}\n\ntemplate <typename mint, bool large =\
    \ false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <=\
    \ n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n -\
    \ k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d] (1-x) ^ {-n} \u306E\
    \u8A08\u7B97\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n\
    \  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large,\
    \ dense>(n + d - 1, d);\n}\n\nusing modint107 = modint<1000000007>;\nusing modint998\
    \ = modint<998244353>;\nusing amint = ArbitraryModInt;\n#line 8 \"test/library_checker/datastructure/sort_segtree_1.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  // \u30AF\u30A8\u30EA\u5148\u8AAD\
    \u307F\u3059\u308B\u65B9\n\n  using AFF = Group_Affine<mint>;\n  LL(N, Q);\n \
    \ vc<int> key(N);\n  vc<pair<mint, mint>> seg_raw(N);\n  FOR(i, N) { read(key[i]),\
    \ read(seg_raw[i]); }\n\n  vc<int> all_key = key;\n  using QT = tuple<int, int,\
    \ int, int, int>;\n  vc<QT> query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t ==\
    \ 0) {\n      LL(i, p, a, b);\n      query[q] = {t, i, p, a, b};\n      all_key.eb(p);\n\
    \    }\n    if (t == 1) {\n      LL(l, r, x);\n      query[q] = {t, l, r, x, 0};\n\
    \    }\n    if (t == 2 || t == 3) {\n      LL(l, r);\n      query[q] = {t, l,\
    \ r, 0, 0};\n    }\n  }\n\n  UNIQUE(all_key);\n  for (auto&& k: key) k = LB(all_key,\
    \ k);\n\n  Sortable_SegTree<AFF> seg(len(all_key), key, seg_raw);\n\n  for (auto&&\
    \ [t, a, b, c, d]: query) {\n    if (t == 0) {\n      b = LB(all_key, b);\n  \
    \    seg.set(a, b, {mint(c), mint(d)});\n    }\n    if (t == 1) {\n      auto\
    \ f = seg.prod(a, b);\n      print(AFF::eval(f, c));\n    }\n    if (t == 2) {\
    \ seg.sort_inc(a, b); }\n    if (t == 3) { seg.sort_dec(a, b); }\n  }\n}\n\nsigned\
    \ main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  ll T = 1;\n  FOR(T) solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/point_set_range_sort_range_composite\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/sortable_segtree.hpp\"\
    \n#include \"alg/group/affine.hpp\"\n#include \"mod/modint.hpp\"\n\nusing mint\
    \ = modint998;\n\nvoid solve() {\n  // \u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u3059\
    \u308B\u65B9\n\n  using AFF = Group_Affine<mint>;\n  LL(N, Q);\n  vc<int> key(N);\n\
    \  vc<pair<mint, mint>> seg_raw(N);\n  FOR(i, N) { read(key[i]), read(seg_raw[i]);\
    \ }\n\n  vc<int> all_key = key;\n  using QT = tuple<int, int, int, int, int>;\n\
    \  vc<QT> query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(i,\
    \ p, a, b);\n      query[q] = {t, i, p, a, b};\n      all_key.eb(p);\n    }\n\
    \    if (t == 1) {\n      LL(l, r, x);\n      query[q] = {t, l, r, x, 0};\n  \
    \  }\n    if (t == 2 || t == 3) {\n      LL(l, r);\n      query[q] = {t, l, r,\
    \ 0, 0};\n    }\n  }\n\n  UNIQUE(all_key);\n  for (auto&& k: key) k = LB(all_key,\
    \ k);\n\n  Sortable_SegTree<AFF> seg(len(all_key), key, seg_raw);\n\n  for (auto&&\
    \ [t, a, b, c, d]: query) {\n    if (t == 0) {\n      b = LB(all_key, b);\n  \
    \    seg.set(a, b, {mint(c), mint(d)});\n    }\n    if (t == 1) {\n      auto\
    \ f = seg.prod(a, b);\n      print(AFF::eval(f, c));\n    }\n    if (t == 2) {\
    \ seg.sort_inc(a, b); }\n    if (t == 3) { seg.sort_dec(a, b); }\n  }\n}\n\nsigned\
    \ main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  ll T = 1;\n  FOR(T) solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/sortable_segtree.hpp
  - ds/fastset.hpp
  - ds/segtree.hpp
  - alg/group/affine.hpp
  - mod/modint.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/sort_segtree_1.test.cpp
  requiredBy: []
  timestamp: '2022-11-06 13:29:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/sort_segtree_1.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/sort_segtree_1.test.cpp
- /verify/test/library_checker/datastructure/sort_segtree_1.test.cpp.html
title: test/library_checker/datastructure/sort_segtree_1.test.cpp
---
