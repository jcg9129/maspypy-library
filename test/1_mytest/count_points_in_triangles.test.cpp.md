---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree_01.hpp
    title: ds/fenwicktree/fenwicktree_01.hpp
  - icon: ':heavy_check_mark:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/count_points_in_triangles.hpp
    title: geo/count_points_in_triangles.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/count_points_in_triangles.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned\
    \ __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty\
    \ = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\n\
    constexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32\
    \ infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w,\
    \ vector<type>(__VA_ARGS__)))\n#define vvvv(type, name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n// https://trap.jp/post/1224/\n#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n\
    #define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll\
    \ i = a; i < ll(b); ++i)\n#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i\
    \ += (c))\n#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i,\
    \ a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i =\
    \ (b)-1; i >= ll(a); --i)\n#define overload4(a, b, c, d, e, ...) e\n#define overload3(a,\
    \ b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1)\
    \ & (s)))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_mod_2(int x) { return __builtin_parity(x);\
    \ }\nint popcnt_mod_2(u32 x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll\
    \ x) { return __builtin_parityll(x); }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T floor(T a, T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename\
    \ T>\nT bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename\
    \ T>\npair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q\
    \ * y};\n}\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n\
    \  T sm = 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    template <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok\
    \ : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return\
    \ (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T\
    \ &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off\
    \ = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int>\
    \ ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return\
    \ (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 1 \"geo/count_points_in_triangles.hpp\"\
    \n\n#line 2 \"geo/angle_sort.hpp\"\n\r\n#line 2 \"geo/base.hpp\"\ntemplate <typename\
    \ T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename\
    \ A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A,\
    \ typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+=(const\
    \ Point p) {\n    x += p.x, y += p.y;\n    return *this;\n  }\n  Point operator-=(const\
    \ Point p) {\n    x -= p.x, y -= p.y;\n    return *this;\n  }\n  Point operator+(Point\
    \ p) const { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const {\
    \ return {x - p.x, y - p.y}; }\n  bool operator==(Point p) const { return x ==\
    \ p.x && y == p.y; }\n  bool operator!=(Point p) const { return x != p.x || y\
    \ != p.y; }\n  Point operator-() const { return {-x, -y}; }\n  Point operator*(T\
    \ t) const { return {x * t, y * t}; }\n  Point operator/(T t) const { return {x\
    \ / t, y / t}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return\
    \ x < p.x;\n    return y < p.y;\n  }\n  T dot(Point other) { return x * other.x\
    \ + y * other.y; }\n  T det(Point other) { return x * other.y - y * other.x; }\n\
    \n  double norm() { return sqrtl(x * x + y * y); }\n  double angle() { return\
    \ atan2(y, x); }\n\n  Point rotate(double theta) {\n    static_assert(!is_integral<T>::value);\n\
    \    double c = cos(theta), s = sin(theta);\n    return Point{c * x - s * y, s\
    \ * x + c * y};\n  }\n};\n\n#ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>\
    \ &p) {\n  fastio::rd(p.x), fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>\
    \ &p) {\n  fastio::wt(p.x);\n  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\
    \n// A -> B -> C \u3068\u9032\u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\
    \u308B\u306A\u3089\u3070 +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ -1\ntemplate <typename T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n \
    \ T x = (B - A).det(C - A);\n  if (x > 0) return 1;\n  if (x < 0) return -1;\n\
    \  return 0;\n}\n\ntemplate <typename REAL, typename T, typename U>\nREAL dist(Point<T>\
    \ A, Point<U> B) {\n  REAL dx = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y)\
    \ - REAL(B.y);\n  return sqrt(dx * dx + dy * dy);\n}\n\n// ax+by+c\ntemplate <typename\
    \ T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c)\
    \ {}\n  Line(Point<T> A, Point<T> B) { a = A.y - B.y, b = B.x - A.x, c = A.x *\
    \ B.y - A.y * B.x; }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1),\
    \ Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n  \
    \  return a * P.x + b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U x,\
    \ U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\
    \u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void normalize() {\n    static_assert(is_same_v<T, int> || is_same_v<T,\
    \ long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /=\
    \ g, c /= g;\n    if (b < 0) { a = -a, b = -b, c = -c; }\n    if (b == 0 && a\
    \ < 0) { a = -a, b = -b, c = -c; }\n  }\n\n  bool is_parallel(Line other) { return\
    \ a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line other) { return\
    \ a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename T>\nstruct Segment\
    \ {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n \
    \ Segment(T x1, T y1, T x2, T y2) : Segment(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if\
    \ (det != 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A -\
    \ B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\ntemplate\
    \ <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 4 \"geo/angle_sort.hpp\"\n\r\n// lower: -1, origin: 0, upper: 1\r\ntemplate\
    \ <typename T>\r\nint lower_or_upper(Point<T>& p) {\r\n  if (p.y != 0) return\
    \ (p.y > 0 ? 1 : -1);\r\n  if (p.x > 0) return -1;\r\n  if (p.x < 0) return 1;\r\
    \n  return 0;\r\n}\r\n\r\n// -1, 0, 1\r\ntemplate <typename T>\r\nint angle_comp_3(Point<T>&\
    \ L, Point<T>& R) {\r\n  int a = lower_or_upper(L), b = lower_or_upper(R);\r\n\
    \  if (a != b) return (a < b ? -1 : +1);\r\n  T det = L.det(R);\r\n  if (det >\
    \ 0) return -1;\r\n  if (det < 0) return 1;\r\n  return 0;\r\n}\r\n// \u504F\u89D2\
    \u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort\r\ntemplate <typename T>\r\n\
    vector<int> angle_sort(vector<Point<T>>& P) {\r\n  vc<int> I(len(P));\r\n  FOR(i,\
    \ len(P)) I[i] = i;\r\n  sort(all(I), [&](auto& L, auto& R) -> bool { return angle_comp_3(P[L],\
    \ P[R]) == -1; });\r\n  return I;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\
    \u306B\u5BFE\u3059\u308B argsort\r\ntemplate <typename T>\r\nvector<int> angle_sort(vector<pair<T,\
    \ T>>& P) {\r\n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\
    \n  return angle_sort<T>(tmp);\r\n}\r\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"ds/fenwicktree/fenwicktree_01.hpp\"\n\n#line\
    \ 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\
    \n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ MX = Monoid;\n  using E = typename G::value_type;\n  int n;\n  vector<E> dat;\n\
    \  E total;\n\n  FenwickTree() {}\n  FenwickTree(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree(int n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const\
    \ vc<E>& v) { build(v); }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m,\
    \ G::unit());\n    total = G::unit();\n  }\n  void build(const vc<E>& v) {\n \
    \   build(len(v), [&](int i) -> E { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n\
    \    total = G::unit();\n    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1;\
    \ i <= n; ++i) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j - 1] =\
    \ G::op(dat[i - 1], dat[j - 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n \
    \ E prod_all() { return total; }\n  E sum_all() { return total; }\n  E sum(int\
    \ k) { return prefix_sum(k); }\n  E prod(int k) { return prefix_prod(k); }\n \
    \ E prefix_sum(int k) { return prefix_prod(k); }\n  E prefix_prod(int k) {\n \
    \   chmin(k, n);\n    E ret = G::unit();\n    for (; k > 0; k -= k & -k) ret =\
    \ G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E sum(int L, int R) { return\
    \ prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L, 0), chmin(R, n);\n   \
    \ if (L == 0) return prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n\
    \    E pos = G::unit(), neg = G::unit();\n    while (L < R) { pos = G::op(pos,\
    \ dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg = G::op(neg, dat[L - 1]),\
    \ L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n  }\n\n  vc<E> get_all()\
    \ {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i, i + 1);\n    return res;\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n\n  template <class\
    \ F>\n  int max_right(const F check, int L = 0) {\n    assert(check(G::unit()));\n\
    \    E s = G::unit();\n    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\
    \n    int k = [&]() {\n      while (1) {\n        if (i % 2 == 1) { s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= 1; }\n        if (i == 0) { return topbit(n) +\
    \ 1; }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n\
    \        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(t)) { return\
    \ k; }\n        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n      }\n\
    \    }();\n    while (k) {\n      --k;\n      if (i + (1 << k) - 1 < len(dat))\
    \ {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (check(t)) { i\
    \ += (1 << k), s = t; }\n      }\n    }\n    return i;\n  }\n\n  // check(i, x)\n\
    \  template <class F>\n  int max_right_with_index(const F check, int L = 0) {\n\
    \    assert(check(L, G::unit()));\n    E s = G::unit();\n    int i = L;\n    //\
    \ 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n\
    \        if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i - 1])), i -= 1; }\n \
    \       if (i == 0) { return topbit(n) + 1; }\n        int k = lowbit(i) - 1;\n\
    \        if (i + (1 << k) > n) return k;\n        E t = G::op(s, dat[i + (1 <<\
    \ k) - 1]);\n        if (!check(i + (1 << k), t)) { return k; }\n        s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n\
    \      --k;\n      if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s,\
    \ dat[i + (1 << k) - 1]);\n        if (check(i + (1 << k), t)) { i += (1 << k),\
    \ s = t; }\n      }\n    }\n    return i;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) {\n    assert(check(G::unit()));\n    E s = G::unit();\n\
    \    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\u308D\u307E\u3067\
    \u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s)) {\n      s = G::op(s,\
    \ dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n    }\n    if (check(s))\
    \ {\n      assert(i == 0);\n      return 0;\n    }\n    // 2^k \u9032\u3080\u3068\
    \ ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\u6301\u3057\u3066\u9032\u3080\
    \n    while (k) {\n      --k;\n      E t = G::op(s, G::inverse(dat[i + (1 << k)\
    \ - 1]));\n      if (!check(t)) { i += (1 << k), s = t; }\n    }\n    return i\
    \ + 1;\n  }\n\n  int kth(E k, int L = 0) {\n    return max_right([&k](E x) ->\
    \ bool { return x <= k; }, L);\n  }\n};\n#line 4 \"ds/fenwicktree/fenwicktree_01.hpp\"\
    \n\nstruct FenwickTree_01 {\n  int N, n;\n  vc<u64> dat;\n  FenwickTree<Monoid_Add<int>>\
    \ bit;\n  FenwickTree_01() {}\n  FenwickTree_01(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree_01(int n, F f) {\n    build(n, f);\n  }\n\n  void\
    \ build(int m) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n,\
    \ u64(0));\n    bit.build(n);\n  }\n\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n, u64(0));\n\
    \    FOR(i, N) { dat[i / 64] |= u64(f(i)) << (i % 64); }\n    bit.build(n, [&](int\
    \ i) -> int { return popcnt(dat[i]); });\n  }\n\n  int sum_all() { return bit.sum_all();\
    \ }\n  int sum(int k) { return prefix_sum(k); }\n  int prefix_sum(int k) {\n \
    \   int ans = bit.sum(k / 64);\n    ans += popcnt(dat[k / 64] & ((u64(1) << (k\
    \ % 64)) - 1));\n    return ans;\n  }\n  int sum(int L, int R) {\n    if (L ==\
    \ 0) return prefix_sum(R);\n    int ans = 0;\n    ans -= popcnt(dat[L / 64] &\
    \ ((u64(1) << (L % 64)) - 1));\n    ans += popcnt(dat[R / 64] & ((u64(1) << (R\
    \ % 64)) - 1));\n    ans += bit.sum(L / 64, R / 64);\n    return ans;\n  }\n\n\
    \  void add(int k, int x) {\n    if (x == 1) add(k);\n    if (x == -1) remove(k);\n\
    \  }\n\n  void add(int k) {\n    dat[k / 64] |= u64(1) << (k % 64);\n    bit.add(k\
    \ / 64, 1);\n  }\n  void remove(int k) {\n    dat[k / 64] &= ~(u64(1) << (k %\
    \ 64));\n    bit.add(k / 64, -1);\n  }\n\n  int kth(int k, int L = 0) {\n    if\
    \ (k >= sum_all()) return N;\n    k += popcnt(dat[L / 64] & ((u64(1) << (L % 64))\
    \ - 1));\n    L /= 64;\n    int mid = 0;\n    auto check = [&](auto e) -> bool\
    \ {\n      if (e <= k) chmax(mid, e);\n      return e <= k;\n    };\n    int idx\
    \ = bit.max_right(check, L);\n    if (idx == n) return N;\n    k -= mid;\n   \
    \ u64 x = dat[idx];\n    int p = popcnt(x);\n    if (p <= k) return N;\n    k\
    \ = binary_search([&](int n) -> bool { return (p - popcnt(x >> n)) <= k; },\n\
    \                      0, 64, 0);\n    return 64 * idx + k;\n  }\n\n  int next(int\
    \ k) {\n    int idx = k / 64;\n    k %= 64;\n    u64 x = dat[idx] & ~((u64(1)\
    \ << k) - 1);\n    if (x) return 64 * idx + lowbit(x);\n    idx = bit.kth(0, idx\
    \ + 1);\n    if (idx == n || !dat[idx]) return N;\n    return 64 * idx + lowbit(dat[idx]);\n\
    \  }\n\n  int prev(int k) {\n    if (k == N) --k;\n    int idx = k / 64;\n   \
    \ k %= 64;\n    u64 x = dat[idx];\n    if (k < 63) x &= (u64(1) << (k + 1)) -\
    \ 1;\n    if (x) return 64 * idx + topbit(x);\n    idx = bit.min_left([&](auto\
    \ e) -> bool { return e <= 0; }, idx) - 1;\n    if (idx == -1) return -1;\n  \
    \  return 64 * idx + topbit(dat[idx]);\n  }\n};\n#line 6 \"geo/count_points_in_triangles.hpp\"\
    \n\n// \u70B9\u7FA4 A, B \u3092\u5165\u529B \uFF08Point<ll>\uFF09\n// query(i,j,k)\uFF1A\
    \u4E09\u89D2\u5F62 AiAjAk \u5185\u90E8\u306E Bl \u306E\u500B\u6570\uFF08\u975E\
    \u8CA0\uFF09\u3092\u8FD4\u3059\n// \u524D\u8A08\u7B97 O(NMlogM)\u3001\u30AF\u30A8\
    \u30EA O(1)\n// https://codeforces.com/contest/13/problem/D\n// https://codeforces.com/contest/852/problem/H\n\
    struct Count_Points_In_Triangles {\n  using P = Point<ll>;\n  const int LIM =\
    \ 1'000'000'000 + 10;\n  vc<P> A, B;\n  vc<int> new_idx; // O \u304B\u3089\u898B\
    \u305F\u504F\u89D2\u30BD\u30FC\u30C8\u9806\u3092\u7BA1\u7406\n  vc<int> point;\
    \   // A[i] \u3068\u4E00\u81F4\u3059\u308B B[j] \u306E\u6570\u3048\u4E0A\u3052\
    \n  vvc<int> seg;    // \u7DDA\u5206 A[i]A[j] \u5185\u306B\u3042\u308B B[k] \u306E\
    \u6570\u3048\u4E0A\u3052\n  vvc<int> tri;    // OA[i]A[j] \u5185\u90E8\u306B\u3042\
    \u308B B[k] \u306E\u6570\u3048\u4E0A\u3052\n  Count_Points_In_Triangles(const\
    \ vc<P>& A, const vc<P>& B) : A(A), B(B) {\n    for (auto&& p: A) assert(max(abs(p.x),\
    \ abs(p.y)) < LIM);\n    for (auto&& p: B) assert(max(abs(p.x), abs(p.y)) < LIM);\n\
    \    build();\n  }\n\n  int count3(int i, int j, int k) {\n    i = new_idx[i],\
    \ j = new_idx[j], k = new_idx[k];\n    if (i > j) swap(i, j);\n    if (j > k)\
    \ swap(j, k);\n    if (i > j) swap(i, j);\n    assert(i <= j && j <= k);\n   \
    \ ll d = (A[j] - A[i]).det(A[k] - A[i]);\n    if (d == 0) return 0;\n    if (d\
    \ > 0) { return tri[i][j] + tri[j][k] - tri[i][k] - seg[i][k]; }\n    int x =\
    \ tri[i][k] - tri[i][j] - tri[j][k];\n    return x - seg[i][j] - seg[j][k] - point[j];\n\
    \  }\n\n  // segment\n  int count2(int i, int j) {\n    i = new_idx[i], j = new_idx[j];\n\
    \    if (i > j) swap(i, j);\n    return seg[i][j];\n  }\n\nprivate:\n  P take_origin()\
    \ {\n    // OAiAj, OAiBj \u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u306A\u3089\
    \u306A\u3044\u3088\u3046\u306B\u3059\u308B\n    // fail prob: at most N(N+M)/LIM\n\
    \    return P{-LIM, RNG(-LIM, LIM)};\n  }\n\n  void build() {\n    P O = take_origin();\n\
    \    for (auto&& p: A) p = p - O;\n    for (auto&& p: B) p = p - O;\n    int N\
    \ = len(A), M = len(B);\n    vc<int> I = angle_sort(A);\n    A = rearrange(A,\
    \ I);\n    new_idx.resize(N);\n    FOR(i, N) new_idx[I[i]] = i;\n\n    I = angle_sort(B);\n\
    \    B = rearrange(B, I);\n\n    point.assign(N, 0);\n    seg.assign(N, vc<int>(N));\n\
    \    tri.assign(N, vc<int>(N));\n\n    // point\n    FOR(i, N) FOR(j, M) if (A[i]\
    \ == B[j])++ point[i];\n\n    int m = 0;\n    FOR(j, N) {\n      // OA[i]A[j],\
    \ B[k]\n      while (m < M && A[j].det(B[m]) < 0) ++m;\n      vc<P> C(m);\n  \
    \    FOR(k, m) C[k] = B[k] - A[j];\n      vc<int> I(m);\n      FOR(i, m) I[i]\
    \ = i;\n      sort(all(I), [&](auto& a, auto& b) -> bool { return C[a].det(C[b])\
    \ > 0; });\n      C = rearrange(C, I);\n      vc<int> rk(m);\n      FOR(k, m)\
    \ rk[I[k]] = k;\n      FenwickTree_01 bit(m);\n\n      int k = m;\n      FOR_R(i,\
    \ j) {\n        while (k > 0 && A[i].det(B[k - 1]) > 0) { bit.add(rk[--k], 1);\
    \ }\n        P p = A[i] - A[j];\n        int lb = binary_search([&](int n) ->\
    \ bool { return (n == 0 ? true : C[n - 1].det(p) > 0); }, 0, m + 1);\n       \
    \ int ub = binary_search([&](int n) -> bool { return (n == 0 ? true : C[n - 1].det(p)\
    \ >= 0); }, 0, m + 1);\n        seg[i][j] += bit.sum(lb, ub), tri[i][j] += bit.sum(lb);\n\
    \      }\n    }\n  }\n};\n#line 5 \"test/1_mytest/count_points_in_triangles.test.cpp\"\
    \n\nvoid test() {\n  using P = Point<ll>;\n  vc<P> A, B;\n  int K = 1'000'000'000;\n\
    \  int N = 100, M = 100;\n  FOR(N) {\n    bool small = RNG(0, 2);\n    if (small)\
    \ {\n      A.eb(RNG(-4, 5), RNG(-4, 5));\n    } else {\n      A.eb(RNG(-K, K),\
    \ RNG(-K, K));\n    }\n  }\n  FOR(M) {\n    bool small = RNG(0, 2);\n    if (small)\
    \ {\n      B.eb(RNG(-4, 5), RNG(-4, 5));\n    } else {\n      B.eb(RNG(-K, K),\
    \ RNG(-K, K));\n    }\n  }\n  Count_Points_In_Triangles X(A, B);\n  FOR(100) {\n\
    \    int i = RNG(0, N), j = RNG(0, N), k = RNG(0, N);\n    int me = X.count3(i,\
    \ j, k);\n    int naive = 0;\n    for (auto&& p: B) {\n      ll s1 = (A[j] - A[i]).det(p\
    \ - A[i]);\n      ll s2 = (A[k] - A[j]).det(p - A[j]);\n      ll s3 = (A[i] -\
    \ A[k]).det(p - A[k]);\n      ll s = (A[k] - A[i]).det(A[j] - A[i]);\n      if\
    \ (s1 == 0 || s2 == 0 || s3 == 0 || s == 0) continue;\n      if (abs(s1) + abs(s2)\
    \ + abs(s3) == abs(s)) ++naive;\n    }\n    assert(me == naive);\n  }\n}\n\nvoid\
    \ solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\n\
    signed main() {\n  FOR(100) test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"geo/count_points_in_triangles.hpp\"\n#include \"random/base.hpp\"\
    \n\nvoid test() {\n  using P = Point<ll>;\n  vc<P> A, B;\n  int K = 1'000'000'000;\n\
    \  int N = 100, M = 100;\n  FOR(N) {\n    bool small = RNG(0, 2);\n    if (small)\
    \ {\n      A.eb(RNG(-4, 5), RNG(-4, 5));\n    } else {\n      A.eb(RNG(-K, K),\
    \ RNG(-K, K));\n    }\n  }\n  FOR(M) {\n    bool small = RNG(0, 2);\n    if (small)\
    \ {\n      B.eb(RNG(-4, 5), RNG(-4, 5));\n    } else {\n      B.eb(RNG(-K, K),\
    \ RNG(-K, K));\n    }\n  }\n  Count_Points_In_Triangles X(A, B);\n  FOR(100) {\n\
    \    int i = RNG(0, N), j = RNG(0, N), k = RNG(0, N);\n    int me = X.count3(i,\
    \ j, k);\n    int naive = 0;\n    for (auto&& p: B) {\n      ll s1 = (A[j] - A[i]).det(p\
    \ - A[i]);\n      ll s2 = (A[k] - A[j]).det(p - A[j]);\n      ll s3 = (A[i] -\
    \ A[k]).det(p - A[k]);\n      ll s = (A[k] - A[i]).det(A[j] - A[i]);\n      if\
    \ (s1 == 0 || s2 == 0 || s3 == 0 || s == 0) continue;\n      if (abs(s1) + abs(s2)\
    \ + abs(s3) == abs(s)) ++naive;\n    }\n    assert(me == naive);\n  }\n}\n\nvoid\
    \ solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\n\
    signed main() {\n  FOR(100) test();\n  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - geo/count_points_in_triangles.hpp
  - geo/angle_sort.hpp
  - geo/base.hpp
  - random/base.hpp
  - ds/fenwicktree/fenwicktree_01.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: true
  path: test/1_mytest/count_points_in_triangles.test.cpp
  requiredBy: []
  timestamp: '2024-10-01 03:45:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/count_points_in_triangles.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/count_points_in_triangles.test.cpp
- /verify/test/1_mytest/count_points_in_triangles.test.cpp.html
title: test/1_mytest/count_points_in_triangles.test.cpp
---