---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/hash_pair.hpp
    title: random/hash_pair.hpp
  - icon: ':question:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename A, typename B>\n\
    \  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x\
    \ + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y -\
    \ p.y}; }\n  bool operator==(Point p) const { return x == p.x && y == p.y; }\n\
    \  bool operator!=(Point p) const { return x != p.x || y != p.y; }\n  Point operator-()\
    \ const { return {-x, -y}; }\n  Point operator*(T t) const { return {x * t, y\
    \ * t}; }\n  Point operator/(T t) const { return {x / t, y / t}; }\n\n  bool operator<(Point\
    \ p) const {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T\
    \ dot(Point other) { return x * other.x + y * other.y; }\n  T det(Point other)\
    \ { return x * other.y - y * other.x; }\n\n  double norm() { return sqrtl(x *\
    \ x + y * y); }\n  double angle() { return atan2(y, x); }\n\n  Point rotate(double\
    \ theta) {\n    static_assert(!is_integral<T>::value);\n    double c = cos(theta),\
    \ s = sin(theta);\n    return Point{c * x - s * y, s * x + c * y};\n  }\n};\n\n\
    #ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x),\
    \ fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n\
    \  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\
    \u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename\
    \ T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n\
    \  if (x > 0) return 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename\
    \ REAL, typename T>\nREAL dist(Point<T> A, Point<T> B) {\n  A = A - B;\n  T p\
    \ = A.dot(A);\n  return sqrt(REAL(p));\n}\n\ntemplate <typename T>\nstruct Line\
    \ {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T>\
    \ A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n\
    \  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n    return a * P.x +\
    \ b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U x, U y) {\n    return\
    \ a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c\
    \ \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize()\
    \ {\n    static_assert(is_same_v<T, int> || is_same_v<T, long long>);\n    T g\
    \ = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /= g, c /= g;\n    if (b\
    \ < 0) { a = -a, b = -b, c = -c; }\n    if (b == 0 && a < 0) { a = -a, b = -b,\
    \ c = -c; }\n  }\n\n  bool is_parallel(Line other) { return a * other.b - b *\
    \ other.a == 0; }\n  bool is_orthogonal(Line other) { return a * other.a + b *\
    \ other.b == 0; }\n};\n\ntemplate <typename T>\nstruct Segment {\n  Point<T> A,\
    \ B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T x1, T y1,\
    \ T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  bool\
    \ contain(Point<T> C) {\n    static_assert(is_integral<T>::value);\n    T det\
    \ = (C - A).det(B - A);\n    if (det != 0) return 0;\n    return (C - A).dot(B\
    \ - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A,\
    \ B); }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n \
    \ REAL r;\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL\
    \ y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n\ntemplate <typename T>\nstruct Polygon {\n  vc<Point<T>>\
    \ points;\n  T a;\n\n  template <typename A, typename B>\n  Polygon(vc<pair<A,\
    \ B>> pairs) {\n    for (auto&& [a, b]: pairs) points.eb(Point<T>(a, b));\n  \
    \  build();\n  }\n  Polygon(vc<Point<T>> points) : points(points) { build(); }\n\
    \n  int size() { return len(points); }\n\n  template <typename REAL>\n  REAL area()\
    \ {\n    return a * 0.5;\n  }\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  T area_2() {\n    return a;\n  }\n\n  bool is_convex() {\n    FOR(j,\
    \ len(points)) {\n      int i = (j == 0 ? len(points) - 1 : j - 1);\n      int\
    \ k = (j == len(points) - 1 ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k]\
    \ - points[j]) < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n\
    \  void build() {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1\
    \ == len(points) ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n\
    \    if (a < 0) {\n      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n\
    #line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\
    \n\ntemplate <typename T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) swap(A[i],\
    \ A[RNG(0, i + 1)]);\n}\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate\
    \ <typename Val, int LOG = 20, bool KEEP_IDS = false>\r\nstruct HashMap {\r\n\
    \  static constexpr int N = (1 << LOG);\r\n  u64* key;\r\n  Val* val;\r\n  vc<int>\
    \ IDS;\r\n  bitset<N> used;\r\n  const int shift;\r\n  const u64 r = 11995408973635179863ULL;\r\
    \n  HashMap() : key(new u64[N]), val(new Val[N]), shift(64 - LOG) {}\r\n  u32\
    \ hash(u64 x) {\r\n    static const u64 FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    int i = index(k);\r\n    if (!used[i]) {\r\n      used[i] =\
    \ 1, key[i] = k, val[i] = Val{};\r\n      if constexpr (KEEP_IDS) IDS.eb(i);\r\
    \n    }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value)\
    \ {\r\n    int i = index(k);\r\n    if (!used[i]) return default_value;\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\
    \n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  void reset() {\r\n    static_assert(KEEP_IDS);\r\
    \n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  //\
    \ f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F f) {\r\n  \
    \  static_assert(KEEP_IDS);\r\n    for (auto&& i: IDS) f(key[i], val[i]);\r\n\
    \  }\r\n};\r\n#line 2 \"random/hash_pair.hpp\"\n\ntemplate <typename T>\nu64 hash_pair(pair<T,\
    \ T> X) {\n  static ll hash_base = 0;\n  if (hash_base == 0) hash_base = RNG_64();\n\
    \  return hash_base * X.fi + X.se;\n}\n#line 6 \"geo/closest_pair.hpp\"\n\ntemplate\
    \ <typename T, int LOG = 20>\npair<int, int> closest_pair(vc<Point<T>> points)\
    \ {\n  static HashMap<int, LOG, true> MP;\n  MP.reset();\n  int N = len(points);\n\
    \  assert(N >= 2 && N < (1 << LOG));\n  vc<int> I(N);\n  iota(all(I), 0);\n  shuffle(I);\n\
    \  points = rearrange(points, I);\n\n  auto calc = [&](int i, int j) -> T {\n\
    \    return (points[j] - points[i]).dot(points[j] - points[i]);\n  };\n\n  T best\
    \ = calc(0, 1);\n  pair<int, int> res = {0, 1};\n  T w = sqrtl(best);\n\n  vc<int>\
    \ nxt(N, -1);\n\n  auto insert = [&](int i) -> void {\n    u64 k = hash_pair<ll>({points[i].x\
    \ / w, points[i].y / w});\n    nxt[i] = MP.get(k, -1);\n    MP[k] = i;\n  };\n\
    \n  auto query = [&](int i) -> bool {\n    ll a = points[i].x / w;\n    ll b =\
    \ points[i].y / w;\n    bool upd = 0;\n    FOR(dx, -1, 2) FOR(dy, -1, 2) {\n \
    \     u64 k = hash_pair<ll>({a + dx, b + dy});\n      int j = MP.get(k, -1);\n\
    \      while (j != -1) {\n        if (chmin(best, calc(i, j))) { upd = 1, res\
    \ = {i, j}, w = sqrtl(best); }\n        j = nxt[j];\n      }\n    }\n    return\
    \ upd;\n  };\n\n  insert(0), insert(1);\n  FOR(i, 2, N) {\n    if (query(i)) {\n\
    \      if (best == T(0)) break;\n      MP.reset();\n      FOR(j, i) insert(j);\n\
    \    }\n    insert(i);\n  }\n  res.fi = I[res.fi], res.se = I[res.se];\n  return\
    \ res;\n}\n"
  code: "#include \"geo/base.hpp\"\n#include \"random/base.hpp\"\n#include \"random/shuffle.hpp\"\
    \n#include \"ds/hashmap.hpp\"\n#include \"random/hash_pair.hpp\"\n\ntemplate <typename\
    \ T, int LOG = 20>\npair<int, int> closest_pair(vc<Point<T>> points) {\n  static\
    \ HashMap<int, LOG, true> MP;\n  MP.reset();\n  int N = len(points);\n  assert(N\
    \ >= 2 && N < (1 << LOG));\n  vc<int> I(N);\n  iota(all(I), 0);\n  shuffle(I);\n\
    \  points = rearrange(points, I);\n\n  auto calc = [&](int i, int j) -> T {\n\
    \    return (points[j] - points[i]).dot(points[j] - points[i]);\n  };\n\n  T best\
    \ = calc(0, 1);\n  pair<int, int> res = {0, 1};\n  T w = sqrtl(best);\n\n  vc<int>\
    \ nxt(N, -1);\n\n  auto insert = [&](int i) -> void {\n    u64 k = hash_pair<ll>({points[i].x\
    \ / w, points[i].y / w});\n    nxt[i] = MP.get(k, -1);\n    MP[k] = i;\n  };\n\
    \n  auto query = [&](int i) -> bool {\n    ll a = points[i].x / w;\n    ll b =\
    \ points[i].y / w;\n    bool upd = 0;\n    FOR(dx, -1, 2) FOR(dy, -1, 2) {\n \
    \     u64 k = hash_pair<ll>({a + dx, b + dy});\n      int j = MP.get(k, -1);\n\
    \      while (j != -1) {\n        if (chmin(best, calc(i, j))) { upd = 1, res\
    \ = {i, j}, w = sqrtl(best); }\n        j = nxt[j];\n      }\n    }\n    return\
    \ upd;\n  };\n\n  insert(0), insert(1);\n  FOR(i, 2, N) {\n    if (query(i)) {\n\
    \      if (best == T(0)) break;\n      MP.reset();\n      FOR(j, i) insert(j);\n\
    \    }\n    insert(i);\n  }\n  res.fi = I[res.fi], res.se = I[res.se];\n  return\
    \ res;\n}"
  dependsOn:
  - geo/base.hpp
  - random/base.hpp
  - random/shuffle.hpp
  - ds/hashmap.hpp
  - random/hash_pair.hpp
  isVerificationFile: false
  path: geo/closest_pair.hpp
  requiredBy: []
  timestamp: '2023-11-21 19:08:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_5_A.test.cpp
documentation_of: geo/closest_pair.hpp
layout: document
redirect_from:
- /library/geo/closest_pair.hpp
- /library/geo/closest_pair.hpp.html
title: geo/closest_pair.hpp
---
