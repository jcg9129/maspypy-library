---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/count_points_in_triangles_naive.test.cpp
    title: test/library_checker/geometry/count_points_in_triangles_naive.test.cpp
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
    \ = A.dot(A);\n  return sqrt(REAL(p));\n}\n\n// ax+by+c\ntemplate <typename T>\n\
    struct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n \
    \ Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c = A.x *\
    \ B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1),\
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
    \ Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2,\
    \ y2)) {}\n\n  bool contain(Point<T> C) {\n    static_assert(is_integral<T>::value);\n\
    \    T det = (C - A).det(B - A);\n    if (det != 0) return 0;\n    return (C -\
    \ A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line() {\
    \ return Line(A, B); }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL>\
    \ O;\n  REAL r;\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL\
    \ x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
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
    #line 2 \"geo/convex_polygon.hpp\"\n\n// \u307B\u3068\u3093\u3069\u30C6\u30B9\u30C8\
    \u3055\u308C\u3066\u3044\u306A\u3044\u306E\u3067\u3042\u3084\u3057\u3044\n// n=2\
    \ \u306F\u73FE\u72B6\u30B5\u30DD\u30FC\u30C8\u3057\u3066\u3044\u306A\u3044\ntemplate\
    \ <typename T>\nstruct ConvexPolygon {\n  using P = Point<T>;\n  int n;\n  vc<P>\
    \ point;\n\n  ConvexPolygon(vc<P> point_) : n(len(point_)), point(point_) {\n\
    \    assert(n >= 3);\n    // counter clockwise \u306B\u306A\u304A\u3059\n    if\
    \ (n >= 3) {\n      if ((point[1] - point[0]).det(point[2] - point[0]) < 0) {\n\
    \        reverse(all(point));\n      }\n    }\n  }\n\n  // \u6BD4\u8F03\u95A2\u6570\
    \ comp(i,j)\n  template <typename F>\n  int periodic_min_comp(F comp) {\n    int\
    \ L = 0, M = n, R = n + n;\n    while (1) {\n      if (R - L == 2) break;\n  \
    \    int L1 = (L + M) / 2, R1 = (M + R + 1) / 2;\n      if (comp(L1, M)) { R =\
    \ M, M = L1; }\n      elif (comp(R1, M)) { L = M, M = R1; }\n      else {\n  \
    \      L = L1, R = R1;\n      }\n    }\n    return M % n;\n  }\n\n  int nxt_idx(int\
    \ i) { return (i + 1 == n ? 0 : i + 1); }\n  int prev_idx(int i) { return (i ==\
    \ 0 ? n - 1 : i - 1); }\n\n  // \u4E2D\uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A\
    -1\n  int side(P p) {\n    int L = 1, R = n - 1;\n    T a = (point[L] - point[0]).det(p\
    \ - point[0]);\n    T b = (point[R] - point[0]).det(p - point[0]);\n    if (a\
    \ < 0 || b > 0) return -1;\n    // p \u306F 0 \u304B\u3089\u898B\u3066 [L,R] \u65B9\
    \u5411\n    while (R - L >= 2) {\n      int M = (L + R) / 2;\n      T c = (point[M]\
    \ - point[0]).det(p - point[0]);\n      if (c < 0)\n        R = M, b = c;\n  \
    \    else\n        L = M, a = c;\n    }\n    T c = (point[R] - point[L]).det(p\
    \ - point[L]);\n    T x = min({a, -b, c});\n    if (x < 0) return -1;\n    if\
    \ (x > 0) return 1;\n    return 0;\n  }\n\n  pair<int, T> min_dot(P p) {\n   \
    \ int idx = periodic_min_comp([&](int i, int j) -> bool {\n      return point[i\
    \ % n].dot(p) < point[j % n].dot(p);\n    });\n    return {idx, point[idx].dot(p)};\n\
    \  }\n  pair<int, T> max_dot(P p) {\n    int idx = periodic_min_comp([&](int i,\
    \ int j) -> bool {\n      return point[i % n].dot(p) > point[j % n].dot(p);\n\
    \    });\n    return {idx, point[idx].dot(p)};\n  }\n  // pair<int, int> visible_range(P\
    \ p) {}\n};\n"
  code: "#include \"geo/base.hpp\"\n\n// \u307B\u3068\u3093\u3069\u30C6\u30B9\u30C8\
    \u3055\u308C\u3066\u3044\u306A\u3044\u306E\u3067\u3042\u3084\u3057\u3044\n// n=2\
    \ \u306F\u73FE\u72B6\u30B5\u30DD\u30FC\u30C8\u3057\u3066\u3044\u306A\u3044\ntemplate\
    \ <typename T>\nstruct ConvexPolygon {\n  using P = Point<T>;\n  int n;\n  vc<P>\
    \ point;\n\n  ConvexPolygon(vc<P> point_) : n(len(point_)), point(point_) {\n\
    \    assert(n >= 3);\n    // counter clockwise \u306B\u306A\u304A\u3059\n    if\
    \ (n >= 3) {\n      if ((point[1] - point[0]).det(point[2] - point[0]) < 0) {\n\
    \        reverse(all(point));\n      }\n    }\n  }\n\n  // \u6BD4\u8F03\u95A2\u6570\
    \ comp(i,j)\n  template <typename F>\n  int periodic_min_comp(F comp) {\n    int\
    \ L = 0, M = n, R = n + n;\n    while (1) {\n      if (R - L == 2) break;\n  \
    \    int L1 = (L + M) / 2, R1 = (M + R + 1) / 2;\n      if (comp(L1, M)) { R =\
    \ M, M = L1; }\n      elif (comp(R1, M)) { L = M, M = R1; }\n      else {\n  \
    \      L = L1, R = R1;\n      }\n    }\n    return M % n;\n  }\n\n  int nxt_idx(int\
    \ i) { return (i + 1 == n ? 0 : i + 1); }\n  int prev_idx(int i) { return (i ==\
    \ 0 ? n - 1 : i - 1); }\n\n  // \u4E2D\uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A\
    -1\n  int side(P p) {\n    int L = 1, R = n - 1;\n    T a = (point[L] - point[0]).det(p\
    \ - point[0]);\n    T b = (point[R] - point[0]).det(p - point[0]);\n    if (a\
    \ < 0 || b > 0) return -1;\n    // p \u306F 0 \u304B\u3089\u898B\u3066 [L,R] \u65B9\
    \u5411\n    while (R - L >= 2) {\n      int M = (L + R) / 2;\n      T c = (point[M]\
    \ - point[0]).det(p - point[0]);\n      if (c < 0)\n        R = M, b = c;\n  \
    \    else\n        L = M, a = c;\n    }\n    T c = (point[R] - point[L]).det(p\
    \ - point[L]);\n    T x = min({a, -b, c});\n    if (x < 0) return -1;\n    if\
    \ (x > 0) return 1;\n    return 0;\n  }\n\n  pair<int, T> min_dot(P p) {\n   \
    \ int idx = periodic_min_comp([&](int i, int j) -> bool {\n      return point[i\
    \ % n].dot(p) < point[j % n].dot(p);\n    });\n    return {idx, point[idx].dot(p)};\n\
    \  }\n  pair<int, T> max_dot(P p) {\n    int idx = periodic_min_comp([&](int i,\
    \ int j) -> bool {\n      return point[i % n].dot(p) > point[j % n].dot(p);\n\
    \    });\n    return {idx, point[idx].dot(p)};\n  }\n  // pair<int, int> visible_range(P\
    \ p) {}\n};"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/convex_polygon.hpp
  requiredBy: []
  timestamp: '2024-01-22 21:51:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/geometry/count_points_in_triangles_naive.test.cpp
documentation_of: geo/convex_polygon.hpp
layout: document
redirect_from:
- /library/geo/convex_polygon.hpp
- /library/geo/convex_polygon.hpp.html
title: geo/convex_polygon.hpp
---
