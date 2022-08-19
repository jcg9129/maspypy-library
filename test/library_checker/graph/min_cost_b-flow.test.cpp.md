---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/bflow.hpp
    title: flow/bflow.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/min_cost_b_flow
    links:
    - https://judge.yosupo.jp/problem/min_cost_b_flow
  bundledCode: "#line 1 \"test/library_checker/graph/min_cost_b-flow.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\n#line 1 \"\
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
    \ { yes(!t); }\r\n#line 2 \"flow/bflow.hpp\"\nenum Objective {\n  MINIMIZE = 1,\n\
    \  MAXIMIZE = -1,\n};\nenum class Status {\n  OPTIMAL,\n  INFEASIBLE,\n};\n\n\
    template <class Flow = ll, class Cost = ll,\n          Objective objective = Objective::MINIMIZE,\
    \ Flow SCALING_FACTOR = 2>\nstruct MinCostFlow {\nprivate:\n  using V_id = uint32_t;\n\
    \  using E_id = uint32_t;\n\n  struct Edge {\n    friend struct MinCostFlow;\n\
    \n  private:\n    V_id frm, to;\n    Flow flow, cap;\n    Cost cost;\n    E_id\
    \ rev;\n\n  public:\n    Edge() = default;\n\n    Edge(const V_id frm, const V_id\
    \ to, const Flow cap, const Cost cost,\n         const E_id rev)\n        : frm(frm),\
    \ to(to), flow(0), cap(cap), cost(cost), rev(rev) {}\n\n    [[nodiscard]] Flow\
    \ residual_cap() const { return cap - flow; }\n  };\n\npublic:\n  struct EdgePtr\
    \ {\n    friend struct MinCostFlow;\n\n  private:\n    const MinCostFlow *instance;\n\
    \    const V_id v;\n    const E_id e;\n\n    EdgePtr(const MinCostFlow *instance,\
    \ const V_id v, const E_id e)\n        : instance(instance), v(v), e(e) {}\n\n\
    \    [[nodiscard]] const Edge &edge() const { return instance->g[v][e]; }\n\n\
    \    [[nodiscard]] const Edge &rev() const {\n      const Edge &e = edge();\n\
    \      return instance->g[e.to][e.rev];\n    }\n\n  public:\n    [[nodiscard]]\
    \ V_id frm() const { return rev().to; }\n\n    [[nodiscard]] V_id to() const {\
    \ return edge().to; }\n\n    [[nodiscard]] Flow flow() const { return edge().flow;\
    \ }\n\n    [[nodiscard]] Flow lower() const { return -rev().cap; }\n\n    [[nodiscard]]\
    \ Flow upper() const { return edge().cap; }\n\n    [[nodiscard]] Cost cost() const\
    \ { return edge().cost; }\n\n    [[nodiscard]] Cost gain() const { return -edge().cost;\
    \ }\n  };\n\nprivate:\n  V_id n;\n  std::vector<std::vector<Edge>> g;\n  std::vector<Flow>\
    \ b;\n\npublic:\n  MinCostFlow(int n) : n(n) {\n    g.resize(n);\n    b.resize(n);\n\
    \  }\n\n  V_id add_vertex() {\n    ++n;\n    g.resize(n);\n    b.resize(n);\n\
    \    return n - 1;\n  }\n\n  std::vector<V_id> add_vertices(const size_t size)\
    \ {\n    std::vector<V_id> ret;\n    for (V_id i = 0; i < size; ++i) ret.emplace_back(n\
    \ + i);\n    n += size;\n    g.resize(n);\n    b.resize(n);\n    return ret;\n\
    \  }\n\n  void add(const V_id frm, const V_id to, const Flow lo, const Flow hi,\n\
    \           const Cost cost) {\n    const E_id e = g[frm].size(), re = frm ==\
    \ to ? e + 1 : g[to].size();\n    assert(lo <= hi);\n    g[frm].emplace_back(Edge{frm,\
    \ to, hi, cost * objective, re});\n    g[to].emplace_back(Edge{to, frm, -lo, -cost\
    \ * objective, e});\n    edges.eb(EdgePtr{this, frm, e});\n  }\n\n  void add_source(const\
    \ V_id v, const Flow amount) { b[v] += amount; }\n\n  void add_sink(const V_id\
    \ v, const Flow amount) { b[v] -= amount; }\n\nprivate:\n  static Cost constexpr\
    \ unreachable = std::numeric_limits<Cost>::max();\n  Cost farthest;\n  std::vector<Cost>\
    \ potential;\n  std::vector<Cost> dist;\n  std::vector<Edge *> parent;\n  std::priority_queue<std::pair<Cost,\
    \ int>, std::vector<std::pair<Cost, int>>,\n                      std::greater<>>\n\
    \      pq;\n  std::vector<V_id> excess_vs, deficit_vs;\n  std::vector<EdgePtr>\
    \ edges;\n  Edge &rev(const Edge &e) { return g[e.to][e.rev]; }\n\n  void push(Edge\
    \ &e, const Flow amount) {\n    e.flow += amount;\n    g[e.to][e.rev].flow -=\
    \ amount;\n  }\n\n  Cost residual_cost(const V_id frm, const V_id to, const Edge\
    \ &e) {\n    return e.cost + potential[frm] - potential[to];\n  }\n\n  bool dual(const\
    \ Flow delta) {\n    dist.assign(n, unreachable);\n    parent.assign(n, nullptr);\n\
    \    excess_vs.erase(std::remove_if(std::begin(excess_vs), std::end(excess_vs),\n\
    \                                   [&](const V_id v) { return b[v] < delta; }),\n\
    \                    std::end(excess_vs));\n    deficit_vs.erase(\n        std::remove_if(std::begin(deficit_vs),\
    \ std::end(deficit_vs),\n                       [&](const V_id v) { return b[v]\
    \ > -delta; }),\n        std::end(deficit_vs));\n    for (const auto v: excess_vs)\
    \ pq.emplace(dist[v] = 0, v);\n    farthest = 0;\n    std::size_t deficit_count\
    \ = 0;\n    while (!pq.empty()) {\n      const auto [d, u] = pq.top();\n     \
    \ pq.pop();\n      if (dist[u] < d) continue;\n      farthest = d;\n      if (b[u]\
    \ <= -delta) ++deficit_count;\n      if (deficit_count >= deficit_vs.size()) break;\n\
    \      for (auto &e: g[u]) {\n        if (e.residual_cap() < delta) continue;\n\
    \        const auto v = e.to;\n        const auto new_dist = d + residual_cost(u,\
    \ v, e);\n        if (new_dist >= dist[v]) continue;\n        pq.emplace(dist[v]\
    \ = new_dist, v);\n        parent[v] = &e;\n      }\n    }\n    pq = decltype(pq)();\n\
    \    for (V_id v = 0; v < n; ++v) {\n      potential[v] += std::min(dist[v], farthest);\n\
    \    }\n    return deficit_count > 0;\n  }\n\n  void primal(const Flow delta)\
    \ {\n    for (const auto t: deficit_vs) {\n      if (dist[t] > farthest) continue;\n\
    \      Flow f = -b[t];\n      V_id v;\n      for (v = t; parent[v] != nullptr\
    \ && f >= delta; v = parent[v]->frm) {\n        f = std::min(f, parent[v]->residual_cap());\n\
    \      }\n      f = std::min(f, b[v]);\n      if (f < delta) continue;\n     \
    \ for (v = t; parent[v] != nullptr;) {\n        auto &e = *parent[v];\n      \
    \  push(e, f);\n        const size_t u = parent[v]->frm;\n        parent[v] =\
    \ nullptr;\n        v = u;\n      }\n      b[t] += f;\n      b[v] -= f;\n    }\n\
    \  }\n\n  void saturate_negative(const Flow delta) {\n    excess_vs.clear();\n\
    \    deficit_vs.clear();\n    for (auto &es: g)\n      for (auto &e: es) {\n \
    \       const Flow rcap = e.residual_cap();\n        const Cost rcost = residual_cost(e.frm,\
    \ e.to, e);\n        if (rcost < 0 && rcap >= delta) {\n          push(e, rcap);\n\
    \          b[e.frm] -= rcap;\n          b[e.to] += rcap;\n        }\n      }\n\
    \    for (V_id v = 0; v < n; ++v)\n      if (b[v] != 0) { (b[v] > 0 ? excess_vs\
    \ : deficit_vs).emplace_back(v); }\n  }\n\npublic:\n  std::pair<Status, i128>\
    \ solve() {\n    potential.resize(n);\n    for (auto &es: g)\n      for (auto\
    \ &e: es) {\n        const Flow rcap = e.residual_cap();\n        if (rcap < 0)\
    \ {\n          push(e, rcap);\n          b[e.frm] -= rcap;\n          b[e.to]\
    \ += rcap;\n        }\n      }\n\n    Flow inf_flow = 1;\n    for (const auto\
    \ &es: g)\n      for (const auto &e: es) inf_flow = std::max(inf_flow, e.residual_cap());\n\
    \    Flow delta = 1;\n    while (delta <= inf_flow) delta *= SCALING_FACTOR;\n\
    \n    for (delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR) {\n      saturate_negative(delta);\n\
    \      while (dual(delta)) primal(delta);\n    }\n\n    i128 value = 0;\n    for\
    \ (const auto &es: g)\n      for (const auto &e: es) { value += e.flow * e.cost;\
    \ }\n    value /= 2;\n\n    if (excess_vs.empty() && deficit_vs.empty()) {\n \
    \     return {Status::OPTIMAL, value / objective};\n    } else {\n      return\
    \ {Status::INFEASIBLE, value / objective};\n    }\n  }\n\n  template <class T>\n\
    \  T get_result_value() {\n    T value = 0;\n    for (const auto &es: g)\n   \
    \   for (const auto &e: es) { value += (T)(e.flow) * (T)(e.cost); }\n    value\
    \ /= (T)2;\n    return value / objective;\n  }\n\n  std::vector<Cost> get_potential()\
    \ {\n    std::fill(potential.begin(), potential.end(), 0);\n    for (int i = 0;\
    \ i < (int)n; i++)\n      for (const auto &es: g)\n        for (const auto &e:\
    \ es)\n          if (e.residual_cap() > 0)\n            potential[e.to]\n    \
    \            = std::min(potential[e.to], potential[e.frm] + e.cost);\n    return\
    \ potential;\n  }\n\n  std::vector<EdgePtr> get_edges() { return edges; }\n};\n\
    #line 5 \"test/library_checker/graph/min_cost_b-flow.test.cpp\"\n\nvoid solve()\
    \ {\n  LL(N, M);\n  MinCostFlow<ll, ll> G(N);\n  FOR(i, N) {\n    LL(b);\n   \
    \ G.add_source(i, b);\n  }\n  FOR(i, M) {\n    LL(frm, to, lo, hi, cost);\n  \
    \  G.add(frm, to, lo, hi, cost);\n  }\n  auto [status, cost] = G.solve();\n  if\
    \ (status == Status::INFEASIBLE) return print(\"infeasible\");\n  print(cost);\n\
    \  for (auto &&p: G.get_potential()) print(p);\n  for (auto &&e: G.get_edges())\
    \ { print(e.flow()); }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"flow/bflow.hpp\"\n\
    \nvoid solve() {\n  LL(N, M);\n  MinCostFlow<ll, ll> G(N);\n  FOR(i, N) {\n  \
    \  LL(b);\n    G.add_source(i, b);\n  }\n  FOR(i, M) {\n    LL(frm, to, lo, hi,\
    \ cost);\n    G.add(frm, to, lo, hi, cost);\n  }\n  auto [status, cost] = G.solve();\n\
    \  if (status == Status::INFEASIBLE) return print(\"infeasible\");\n  print(cost);\n\
    \  for (auto &&p: G.get_potential()) print(p);\n  for (auto &&e: G.get_edges())\
    \ { print(e.flow()); }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - flow/bflow.hpp
  isVerificationFile: true
  path: test/library_checker/graph/min_cost_b-flow.test.cpp
  requiredBy: []
  timestamp: '2022-08-20 02:40:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/min_cost_b-flow.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/min_cost_b-flow.test.cpp
- /verify/test/library_checker/graph/min_cost_b-flow.test.cpp.html
title: test/library_checker/graph/min_cost_b-flow.test.cpp
---
