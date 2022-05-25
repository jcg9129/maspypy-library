---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/dynamic_segtree.hpp
    title: ds/dynamic_segtree.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/789
    links:
    - https://yukicoder.me/problems/no/789
  bundledCode: "#line 1 \"test/yukicoder/789_dseg.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/789\"\
    \n#line 1 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing\
    \ u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    \ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
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
    \ T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a: A) sum += a;\n\
    \  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
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
    \ { yes(!t); }\r\n#line 2 \"ds/dynamic_segtree.hpp\"\n\r\n/*\r\n\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u306B\u6E21\u3059\u3082\u306E\r\n\u30FBL, R\uFF1A\u6700\
    \u5927\u306E\u7BC4\u56F2\uFF08root node \u306E\u8868\u3059\u7BC4\u56F2\uFF09\r\
    \n\u30FBfunction<X(ll,ll)> defulat_fn(l,r)\uFF1A\u521D\u671F\u5024\u3067\u306E\
    \ [l,r) \u7A4D\u306E\u8A08\u7B97\r\n*/\r\ntemplate <class Monoid, int NODES =\
    \ 5'000'000>\r\nstruct Dynamic_SegTree {\r\n  using X = typename Monoid::value_type;\r\
    \n\r\n  struct Node {\r\n    X x;\r\n    Node *l, *r;\r\n    Node() {}\r\n   \
    \ Node(const X &x) : x(x), l(nullptr), r(nullptr) {}\r\n  };\r\n\r\n  Node *pool;\r\
    \n  int pid;\r\n  ll L, R;\r\n  Node *root;\r\n  function<X(ll, ll)> default_fn;\r\
    \n\r\n  Dynamic_SegTree(ll L, ll R)\r\n      : Dynamic_SegTree(L, R, [](ll L,\
    \ ll R){return Monoid::unit();}) {}\r\n\r\n  Dynamic_SegTree(ll L, ll R, function<X(ll,\
    \ ll)> f)\r\n      : pid(0), L(L), R(R), default_fn(f) {\r\n    pool = new Node[NODES];\r\
    \n    root = new_node(L, R);\r\n  }\r\n\r\n  void reset() {\r\n    pid = 0;\r\n\
    \    root = new_node(L, R);\r\n  }\r\n\r\n  void set(ll i, const X &x) {\r\n \
    \   assert(L <= i && i < R);\r\n    set_rec(root, L, R, i, x);\r\n  }\r\n\r\n\
    \  void multiply(ll i, const X &x) {\r\n    assert(L <= i && i < R);\r\n    multiply_rec(root,\
    \ L, R, i, x);\r\n  }\r\n\r\n  X prod(ll l, ll r) {\r\n    assert(L <= l && l\
    \ <= r && r <= R);\r\n    return prod_rec(root, L, R, l, r);\r\n  }\r\n\r\n  X\
    \ prod_all() { return root->x; }\r\n\r\n  void debug() {\r\n    auto dfs = [&](auto\
    \ &dfs, Node *n, ll l, ll r) -> void {\r\n      print(\"lr\", l, r, \"x\", n->x,\
    \ \"a\", n->a);\r\n      ll m = (l + r) / 2;\r\n      if (n->l) dfs(dfs, n->l,\
    \ l, m);\r\n      if (n->r) dfs(dfs, n->r, m, r);\r\n    };\r\n    dfs(dfs, root,\
    \ L, R);\r\n  }\r\n\r\n  template <class F>\r\n  ll max_right(const F &check,\
    \ ll s) {\r\n    assert(L <= s && s <= R && check(Monoid::unit()));\r\n    X p\
    \ = Monoid::unit();\r\n    return max_right_rec(root, L, R, check, s, p);\r\n\
    \  }\r\n\r\n  template <class F>\r\n  ll min_left(const F &check, ll t) {\r\n\
    \    assert(L <= t && t <= R && check(Monoid::unit()));\r\n    X p = Monoid::unit();\r\
    \n    return min_left_rec(root, L, R, check, t, p);\r\n  }\r\n\r\nprivate:\r\n\
    \  Node *new_node(ll node_l, ll node_r) {\r\n    pool[pid].x = default_fn(node_l,\
    \ node_r);\r\n    pool[pid].l = pool[pid].r = nullptr;\r\n    return &(pool[pid++]);\r\
    \n  }\r\n\r\n  void set_rec(Node *n, ll node_l, ll node_r, ll idx, const X &x)\
    \ {\r\n    if (node_r - node_l == 1) {\r\n      n->x = x;\r\n      return;\r\n\
    \    }\r\n    ll node_m = (node_l + node_r) / 2;\r\n\r\n    if (idx < node_m)\
    \ {\r\n      if (!(n->l)) n->l = new_node(node_l, node_m);\r\n      set_rec(n->l,\
    \ node_l, node_m, idx, x);\r\n    } else {\r\n      if (!(n->r)) n->r = new_node(node_m,\
    \ node_r);\r\n      set_rec(n->r, node_m, node_r, idx, x);\r\n    }\r\n    X xl\
    \ = (n->l ? (n->l)->x : Monoid::unit());\r\n    X xr = (n->r ? (n->r)->x : Monoid::unit());\r\
    \n    n->x = Monoid::op(xl, xr);\r\n  }\r\n\r\n  void multiply_rec(Node *n, ll\
    \ node_l, ll node_r, ll idx, const X &x) {\r\n    if (node_r - node_l == 1) {\r\
    \n      n->x = Monoid::op(n->x, x);\r\n      return;\r\n    }\r\n    ll node_m\
    \ = (node_l + node_r) / 2;\r\n\r\n    if (idx < node_m) {\r\n      if (!(n->l))\
    \ n->l = new_node(node_l, node_m);\r\n      multiply_rec(n->l, node_l, node_m,\
    \ idx, x);\r\n    } else {\r\n      if (!(n->r)) n->r = new_node(node_m, node_r);\r\
    \n      multiply_rec(n->r, node_m, node_r, idx, x);\r\n    }\r\n    X xl = (n->l\
    \ ? (n->l)->x : Monoid::unit());\r\n    X xr = (n->r ? (n->r)->x : Monoid::unit());\r\
    \n    n->x = Monoid::op(xl, xr);\r\n  }\r\n\r\n  X prod_rec(Node *n, ll node_l,\
    \ ll node_r, ll l, ll r) {\r\n    chmax(l, node_l);\r\n    chmin(r, node_r);\r\
    \n    if (l >= r) return Monoid::unit();\r\n    if (l == node_l && r == node_r)\
    \ return n->x;\r\n    ll node_m = (node_l + node_r) / 2;\r\n    X xl = (n->l ?\
    \ prod_rec(n->l, node_l, node_m, l, r) : Monoid::unit());\r\n    X xr = (n->r\
    \ ? prod_rec(n->r, node_m, node_r, l, r) : Monoid::unit());\r\n    return Monoid::op(xl,\
    \ xr);\r\n  }\r\n\r\n  template <typename F>\r\n  ll max_right_rec(Node *n, ll\
    \ node_l, ll node_r, const F &check, ll s, X &p) {\r\n    if (node_r <= s) return\
    \ R;\r\n    if (s <= node_l) {\r\n      X x = Monoid::op(p, n->x);\r\n      if\
    \ (check(x)) {\r\n        p = x;\r\n        return R;\r\n      }\r\n    }\r\n\
    \    if (node_r - node_l == 1) return node_l;\r\n    ll node_m = (node_l + node_r)\
    \ / 2;\r\n    if (!(n->l)) n->l = new_node(node_l, node_m);\r\n    ll res = max_right_rec(n->l,\
    \ node_l, node_m, check, s, p);\r\n    if (res != R) return res;\r\n    if (!(n->r))\
    \ n->r = new_node(node_m, node_r);\r\n    return max_right_rec(n->r, node_m, node_r,\
    \ check, s, p);\r\n  }\r\n\r\n  template <typename F>\r\n  ll min_left_rec(Node\
    \ *n, ll node_l, ll node_r, const F &check, ll t, X &p) {\r\n    if (t <= node_l)\
    \ return L;\r\n    if (node_r <= t) {\r\n      X x = Monoid::op(n->x, p);\r\n\
    \      if (check(x)) {\r\n        p = x;\r\n        return L;\r\n      }\r\n \
    \   }\r\n    if (node_r - node_l == 1) return node_r;\r\n    ll node_m = (node_l\
    \ + node_r) / 2;\r\n    if (!(n->r)) n->r = new_node(node_m, node_r);\r\n    ll\
    \ res = min_left_rec(n->r, node_m, node_r, check, t, p);\r\n    if (res != L)\
    \ return res;\r\n    if (!(n->l)) n->l = new_node(node_l, node_m);\r\n    return\
    \ min_left_rec(n->l, node_l, node_m, check, t, p);\r\n  }\r\n};\r\n#line 2 \"\
    alg/group_add.hpp\"\ntemplate <class X>\r\nstruct Group_Add {\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return x\
    \ + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\
    \n  static constexpr X power(const X &x, ll n) noexcept { return n * x; }\r\n\
    \  static constexpr X unit() { return X(0); }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n#line 6 \"test/yukicoder/789_dseg.test.cpp\"\n\nvoid solve()\
    \ {\n  Dynamic_SegTree<Group_Add<ll>> seg(0, 1LL << 30);\n  LL(Q);\n  ll ANS =\
    \ 0;\n  FOR(Q) {\n    LL(t, a, b);\n    if (t == 0) { seg.multiply(a, b); }\n\
    \    if (t == 1) { ANS += seg.prod(a, b + 1); }\n  }\n  print(ANS);\n}\n\nsigned\
    \ main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"ds/dynamic_segtree.hpp\"\n#include \"\
    alg/group_add.hpp\"\n\nvoid solve() {\n  Dynamic_SegTree<Group_Add<ll>> seg(0,\
    \ 1LL << 30);\n  LL(Q);\n  ll ANS = 0;\n  FOR(Q) {\n    LL(t, a, b);\n    if (t\
    \ == 0) { seg.multiply(a, b); }\n    if (t == 1) { ANS += seg.prod(a, b + 1);\
    \ }\n  }\n  print(ANS);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/dynamic_segtree.hpp
  - alg/group_add.hpp
  isVerificationFile: true
  path: test/yukicoder/789_dseg.test.cpp
  requiredBy: []
  timestamp: '2022-05-22 15:16:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/789_dseg.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/789_dseg.test.cpp
- /verify/test/yukicoder/789_dseg.test.cpp.html
title: test/yukicoder/789_dseg.test.cpp
---
