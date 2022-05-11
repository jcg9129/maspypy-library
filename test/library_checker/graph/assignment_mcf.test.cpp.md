---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/mincostflow.hpp
    title: flow/mincostflow.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/library_checker/graph/assignment_mcf.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n#line 1 \"my_template.hpp\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
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
    \ for (ll i = 0; i < ll(a); ++i)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
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
    \ T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a: A) sum += a;\n\
    \  return sum;\n}\n\ntemplate <class... T>\nconstexpr auto min(T... a) {\n  return\
    \ min(initializer_list<common_type_t<T...>>{a...});\n}\n\ntemplate <class... T>\n\
    constexpr auto max(T... a) {\n  return max(initializer_list<common_type_t<T...>>{a...});\n\
    }\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)),\
    \ x.erase(unique(all(x)), x.end())\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename\
    \ U>\nT ceil(T x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate\
    \ <typename T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x\
    \ - y + 1) / y);\n}\n\ntemplate <typename T, typename U>\npair<T, T> divmod(T\
    \ x, U y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nll binary_search(function<bool(ll)>\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n   \
    \   ng = x;\n  }\n  return ok;\n}\n\ntemplate <class T, class S>\ninline bool\
    \ chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b,\
    \ 1 : 0);\n}\n\nvi s_to_vi(const string &S, char first_char) {\n  vi A(S.size());\n\
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
    \ len(A);\n  assert(len(I) == n);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n\
    \  return B;\n}\n#line 1 \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include\
    \ <unistd.h>\r\n\r\nnamespace detail {\r\ntemplate <typename T, decltype(&T::is_modint)\
    \ = &T::is_modint>\r\nstd::true_type check_value(int);\r\ntemplate <typename T>\r\
    \nstd::false_type check_value(long);\r\n} // namespace detail\r\n\r\ntemplate\
    \ <typename T>\r\nstruct is_modint : decltype(detail::check_value<T>(0)) {};\r\
    \ntemplate <typename T>\r\nusing is_modint_t = enable_if_t<is_modint<T>::value>;\r\
    \ntemplate <typename T>\r\nusing is_not_modint_t = enable_if_t<!is_modint<T>::value>;\r\
    \n\r\nstruct Scanner {\r\n  FILE *fp;\r\n  char line[(1 << 15) + 1];\r\n  size_t\
    \ st = 0, ed = 0;\r\n  void reread() {\r\n    memmove(line, line + st, ed - st);\r\
    \n    ed -= st;\r\n    st = 0;\r\n    ed += fread(line + ed, 1, (1 << 15) - ed,\
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
    \    ostringstream oss;\r\n    oss << setprecision(15) << x;\r\n    string s =\
    \ oss.str();\r\n    write(s);\r\n  }\r\n  void write(const long double &x) {\r\
    \n    ostringstream oss;\r\n    oss << setprecision(15) << x;\r\n    string s\
    \ = oss.str();\r\n    write(s);\r\n  }\r\n  template <class T, is_modint_t<T>\
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
    \ { yes(!t); }\r\n#line 2 \"flow/mincostflow.hpp\"\n\n// atcoder library \u306E\
    \u3082\u306E\u3092\u6539\u5909\n\nnamespace internal {\n\ntemplate <class E>\n\
    struct csr {\n  std::vector<int> start;\n  std::vector<E> elist;\n  explicit csr(int\
    \ n, const std::vector<std::pair<int, E>>& edges)\n      : start(n + 1), elist(edges.size())\
    \ {\n    for (auto e: edges) { start[e.first + 1]++; }\n    for (int i = 1; i\
    \ <= n; i++) { start[i] += start[i - 1]; }\n    auto counter = start;\n    for\
    \ (auto e: edges) { elist[counter[e.first]++] = e.second; }\n  }\n};\n\ntemplate\
    \ <class T>\nstruct simple_queue {\n  std::vector<T> payload;\n  int pos = 0;\n\
    \  void reserve(int n) { payload.reserve(n); }\n  int size() const { return int(payload.size())\
    \ - pos; }\n  bool empty() const { return pos == int(payload.size()); }\n  void\
    \ push(const T& t) { payload.push_back(t); }\n  T& front() { return payload[pos];\
    \ }\n  void clear() {\n    payload.clear();\n    pos = 0;\n  }\n  void pop() {\
    \ pos++; }\n};\n\n} // namespace internal\n\n/*\n\u30FBatcoder library \u3092\u3059\
    \u3053\u3057\u6539\u5909\u3057\u305F\u3082\u306E\n\u30FBDAG = true \u3067\u3042\
    \u308C\u3070\u3001\u8CA0\u8FBA OK \uFF081 \u56DE\u76EE\u306E\u6700\u77ED\u8DEF\
    \u3092 dp \u3067\u884C\u3046\uFF09\n\u305F\u3060\u3057\u3001\u9802\u70B9\u756A\
    \u53F7\u306F toposort \u3055\u308C\u3066\u3044\u308B\u3053\u3068\u3092\u4EEE\u5B9A\
    \u3057\u3066\u3044\u308B\u3002\n*/\ntemplate <class Cap = int, class Cost = ll,\
    \ bool DAG = false>\nstruct mcf_graph {\npublic:\n  mcf_graph() {}\n  explicit\
    \ mcf_graph(int n) : _n(n) {}\n\n  // frm, to, cap, cost\n  int add(int frm, int\
    \ to, Cap cap, Cost cost) {\n    assert(0 <= frm && frm < _n);\n    assert(0 <=\
    \ to && to < _n);\n    assert(0 <= cap);\n    assert(DAG || 0 <= cost);\n    if\
    \ (DAG) assert(frm < to);\n    int m = int(_edges.size());\n    _edges.push_back({frm,\
    \ to, cap, 0, cost});\n    return m;\n  }\n\n  void debug() {\n    print(\"flow\
    \ graph\");\n    print(\"frm, to, cap, cost\");\n    for (auto&& [frm, to, cap,\
    \ flow, cost]: _edges) {\n      print(frm, to, cap, cost);\n    }\n  }\n\n  struct\
    \ edge {\n    int frm, to;\n    Cap cap, flow;\n    Cost cost;\n  };\n\n  edge\
    \ get_edge(int i) {\n    int m = int(_edges.size());\n    assert(0 <= i && i <\
    \ m);\n    return _edges[i];\n  }\n  std::vector<edge> edges() { return _edges;\
    \ }\n\n  std::pair<Cap, Cost> flow(int s, int t) {\n    return flow(s, t, std::numeric_limits<Cap>::max());\n\
    \  }\n  std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {\n    return\
    \ slope(s, t, flow_limit).back();\n  }\n  std::vector<std::pair<Cap, Cost>> slope(int\
    \ s, int t) {\n    return slope(s, t, std::numeric_limits<Cap>::max());\n  }\n\
    \  std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {\n \
    \   assert(0 <= s && s < _n);\n    assert(0 <= t && t < _n);\n    assert(s !=\
    \ t);\n\n    int m = int(_edges.size());\n    std::vector<int> edge_idx(m);\n\n\
    \    auto g = [&]() {\n      std::vector<int> degree(_n), redge_idx(m);\n    \
    \  std::vector<std::pair<int, _edge>> elist;\n      elist.reserve(2 * m);\n  \
    \    for (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ = degree[e.frm]++;\n        redge_idx[i] = degree[e.to]++;\n        elist.push_back({e.frm,\
    \ {e.to, -1, e.cap - e.flow, e.cost}});\n        elist.push_back({e.to, {e.frm,\
    \ -1, e.flow, -e.cost}});\n      }\n      auto _g = internal::csr<_edge>(_n, elist);\n\
    \      for (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ += _g.start[e.frm];\n        redge_idx[i] += _g.start[e.to];\n        _g.elist[edge_idx[i]].rev\
    \ = redge_idx[i];\n        _g.elist[redge_idx[i]].rev = edge_idx[i];\n      }\n\
    \      return _g;\n    }();\n\n    auto result = slope(g, s, t, flow_limit);\n\
    \n    for (int i = 0; i < m; i++) {\n      auto e = g.elist[edge_idx[i]];\n  \
    \    _edges[i].flow = _edges[i].cap - e.cap;\n    }\n\n    return result;\n  }\n\
    \nprivate:\n  int _n;\n  std::vector<edge> _edges;\n\n  // inside edge\n  struct\
    \ _edge {\n    int to, rev;\n    Cap cap;\n    Cost cost;\n  };\n\n  std::vector<std::pair<Cap,\
    \ Cost>> slope(internal::csr<_edge>& g, int s, int t,\n                      \
    \                    Cap flow_limit) {\n    // variants (C = maxcost):\n    //\
    \ -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0\n    // reduced cost (= e.cost\
    \ + dual[e.frm] - dual[e.to]) >= 0 for all edge\n\n    // dual_dist[i] = (dual[i],\
    \ dist[i])\n    if (DAG) assert(s == 0 && t == _n - 1);\n    std::vector<std::pair<Cost,\
    \ Cost>> dual_dist(_n);\n    std::vector<int> prev_e(_n);\n    std::vector<bool>\
    \ vis(_n);\n    struct Q {\n      Cost key;\n      int to;\n      bool operator<(Q\
    \ r) const { return key > r.key; }\n    };\n    std::vector<int> que_min;\n  \
    \  std::vector<Q> que;\n    auto dual_ref = [&]() {\n      for (int i = 0; i <\
    \ _n; i++) {\n        dual_dist[i].second = std::numeric_limits<Cost>::max();\n\
    \      }\n      std::fill(vis.begin(), vis.end(), false);\n      que_min.clear();\n\
    \      que.clear();\n\n      // que[0..heap_r) was heapified\n      size_t heap_r\
    \ = 0;\n\n      dual_dist[s].second = 0;\n      que_min.push_back(s);\n      while\
    \ (!que_min.empty() || !que.empty()) {\n        int v;\n        if (!que_min.empty())\
    \ {\n          v = que_min.back();\n          que_min.pop_back();\n        } else\
    \ {\n          while (heap_r < que.size()) {\n            heap_r++;\n        \
    \    std::push_heap(que.begin(), que.begin() + heap_r);\n          }\n       \
    \   v = que.front().to;\n          std::pop_heap(que.begin(), que.end());\n  \
    \        que.pop_back();\n          heap_r--;\n        }\n        if (vis[v])\
    \ continue;\n        vis[v] = true;\n        if (v == t) break;\n        // dist[v]\
    \ = shortest(s, v) + dual[s] - dual[v]\n        // dist[v] >= 0 (all reduced cost\
    \ are positive)\n        // dist[v] <= (n-1)C\n        Cost dual_v = dual_dist[v].first,\
    \ dist_v = dual_dist[v].second;\n        for (int i = g.start[v]; i < g.start[v\
    \ + 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n\
    \          // |-dual[e.to] + dual[v]| <= (n-1)C\n          // cost <= C - -(n-1)C\
    \ + 0 = nC\n          Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n \
    \         if (dual_dist[e.to].second > dist_v + cost) {\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n            if (dist_to == dist_v) {\n             \
    \ que_min.push_back(e.to);\n            } else {\n              que.push_back(Q{dist_to,\
    \ e.to});\n            }\n          }\n        }\n      }\n      if (!vis[t])\
    \ { return false; }\n\n      for (int v = 0; v < _n; v++) {\n        if (!vis[v])\
    \ continue;\n        // dual[v] = dual[v] - dist[t] + dist[v]\n        //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n        //         (shortest(s,\
    \ v) + dual[s] - dual[v]) = - shortest(s,\n        //         t) + dual[t] + shortest(s,\
    \ v) = shortest(s, v) -\n        //         shortest(s, t) >= 0 - (n-1)C\n   \
    \     dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;\n     \
    \ }\n      return true;\n    };\n\n    auto dual_ref_dag = [&]() {\n      for\
    \ (int i = 0; i < _n; i++) {\n        dual_dist[i].second = std::numeric_limits<Cost>::max();\n\
    \      }\n      dual_dist[s].second = 0;\n      std::fill(vis.begin(), vis.end(),\
    \ false);\n      vis[0] = true;\n\n      for (int v = 0; v < _n; ++v) {\n    \
    \    if (!vis[v]) continue;\n        Cost dual_v = dual_dist[v].first, dist_v\
    \ = dual_dist[v].second;\n        for (int i = g.start[v]; i < g.start[v + 1];\
    \ i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n  \
    \        Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n          if (dual_dist[e.to].second\
    \ > dist_v + cost) {\n            vis[e.to] = true;\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n          }\n        }\n      }\n      if (!vis[t])\
    \ { return false; }\n\n      for (int v = 0; v < _n; v++) {\n        if (!vis[v])\
    \ continue;\n        // dual[v] = dual[v] - dist[t] + dist[v]\n        //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n        //         (shortest(s,\
    \ v) + dual[s] - dual[v]) = - shortest(s,\n        //         t) + dual[t] + shortest(s,\
    \ v) = shortest(s, v) -\n        //         shortest(s, t) >= 0 - (n-1)C\n   \
    \     dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;\n     \
    \ }\n      return true;\n    };\n\n    Cap flow = 0;\n    Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n    std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n\
    \    while (flow < flow_limit) {\n      if (DAG && flow == 0) {\n        if (!dual_ref_dag())\
    \ break;\n      } else {\n        if (!dual_ref()) break;\n      }\n      Cap\
    \ c = flow_limit - flow;\n      for (int v = t; v != s; v = g.elist[prev_e[v]].to)\
    \ {\n        c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n      }\n\
    \      for (int v = t; v != s; v = g.elist[prev_e[v]].to) {\n        auto& e =\
    \ g.elist[prev_e[v]];\n        e.cap += c;\n        g.elist[e.rev].cap -= c;\n\
    \      }\n      Cost d = -dual_dist[s].first;\n      flow += c;\n      cost +=\
    \ c * d;\n      if (prev_cost_per_flow == d) { result.pop_back(); }\n      result.push_back({flow,\
    \ cost});\n      prev_cost_per_flow = d;\n    }\n    return result;\n  }\n};\n\
    #line 5 \"test/library_checker/graph/assignment_mcf.test.cpp\"\n\nvoid solve()\
    \ {\n  LL(N);\n  mcf_graph<int, ll, true> G(N + N + 2);\n  int source = 0;\n \
    \ auto left = [&](int i) -> int { return 1 + i; };\n  auto right = [&](int i)\
    \ -> int { return 1 + N + i; };\n  int sink = right(N);\n  FOR(i, N) FOR(j, N)\
    \ {\n    LL(x);\n    G.add(left(i), right(j), 1, x);\n  }\n  FOR(i, N) {\n   \
    \ G.add(source, left(i), 1, 0);\n    G.add(right(i), sink, 1, 0);\n  }\n  auto\
    \ xy = G.slope(source, sink);\n  auto edges = G.edges();\n  vi ANS(N);\n  for\
    \ (auto&& e: edges) {\n    if (e.flow && 1 <= e.frm && e.frm <= N) {\n      ANS[e.frm\
    \ - 1] = e.to - right(0);\n    }\n  }\n  print(xy.back().se);\n  print(ANS);\n\
    }\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout\
    \ << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"flow/mincostflow.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  mcf_graph<int, ll, true> G(N + N + 2);\n  int\
    \ source = 0;\n  auto left = [&](int i) -> int { return 1 + i; };\n  auto right\
    \ = [&](int i) -> int { return 1 + N + i; };\n  int sink = right(N);\n  FOR(i,\
    \ N) FOR(j, N) {\n    LL(x);\n    G.add(left(i), right(j), 1, x);\n  }\n  FOR(i,\
    \ N) {\n    G.add(source, left(i), 1, 0);\n    G.add(right(i), sink, 1, 0);\n\
    \  }\n  auto xy = G.slope(source, sink);\n  auto edges = G.edges();\n  vi ANS(N);\n\
    \  for (auto&& e: edges) {\n    if (e.flow && 1 <= e.frm && e.frm <= N) {\n  \
    \    ANS[e.frm - 1] = e.to - right(0);\n    }\n  }\n  print(xy.back().se);\n \
    \ print(ANS);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - flow/mincostflow.hpp
  isVerificationFile: true
  path: test/library_checker/graph/assignment_mcf.test.cpp
  requiredBy: []
  timestamp: '2022-05-11 19:22:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/assignment_mcf.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/assignment_mcf.test.cpp
- /verify/test/library_checker/graph/assignment_mcf.test.cpp.html
title: test/library_checker/graph/assignment_mcf.test.cpp
---
