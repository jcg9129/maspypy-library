---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/fenchel.hpp
    title: convex/fenchel.hpp
  - icon: ':question:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':warning:'
    path: geo/apollonian_circle.hpp
    title: geo/apollonian_circle.hpp
  - icon: ':heavy_check_mark:'
    path: geo/closest_pair.hpp
    title: geo/closest_pair.hpp
  - icon: ':x:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  - icon: ':question:'
    path: geo/count_points_in_triangles.hpp
    title: geo/count_points_in_triangles.hpp
  - icon: ':question:'
    path: geo/cross_point.hpp
    title: geo/cross_point.hpp
  - icon: ':question:'
    path: geo/distance.hpp
    title: geo/distance.hpp
  - icon: ':heavy_check_mark:'
    path: geo/dynamicupperhull.hpp
    title: geo/dynamicupperhull.hpp
  - icon: ':heavy_check_mark:'
    path: geo/incircle.hpp
    title: geo/incircle.hpp
  - icon: ':question:'
    path: geo/incremental_convexhull.hpp
    title: geo/incremental_convexhull.hpp
  - icon: ':x:'
    path: geo/max_norm_sum.hpp
    title: geo/max_norm_sum.hpp
  - icon: ':x:'
    path: geo/minimum_enclosing_circle.hpp
    title: geo/minimum_enclosing_circle.hpp
  - icon: ':question:'
    path: geo/outcircle.hpp
    title: geo/outcircle.hpp
  - icon: ':x:'
    path: geo/perpendicular_bisector.hpp
    title: geo/perpendicular_bisector.hpp
  - icon: ':heavy_check_mark:'
    path: geo/projection.hpp
    title: geo/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geo/reflection.hpp
    title: geo/reflection.hpp
  - icon: ':heavy_check_mark:'
    path: graph/planar_graph.hpp
    title: graph/planar_graph.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_A.test.cpp
    title: test/aoj/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_B.test.cpp
    title: test/aoj/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_A.test.cpp
    title: test/aoj/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_B.test.cpp
    title: test/aoj/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_C.test.cpp
    title: test/aoj/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_D.test.cpp
    title: test/aoj/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B.test.cpp
    title: test/aoj/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B.test.cpp
    title: test/aoj/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/convex_layers.test.cpp
    title: test/library_checker/geometry/convex_layers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/sort_points_by_argument.test.cpp
    title: test/library_checker/geometry/sort_points_by_argument.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/sort_points_by_argument_pair.test.cpp
    title: test/library_checker/geometry/sort_points_by_argument_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/count_points_in_triangles.test.cpp
    title: test/mytest/count_points_in_triangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/incremental_ch.test.cpp
    title: test/mytest/incremental_ch.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1777.test.cpp
    title: test/yukicoder/1777.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc139f.test.cpp
    title: test_atcoder/abc139f.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc151f.test.cpp
    title: test_atcoder/abc151f.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc202_f.test.cpp
    title: test_atcoder/abc202_f.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc220g.test.cpp
    title: test_atcoder/abc220g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc266c.test.cpp
    title: test_atcoder/abc266c.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc314.test.cpp
    title: test_atcoder/abc314.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc064c.test.cpp
    title: test_atcoder/arc064c.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc130f.test.cpp
    title: test_atcoder/arc130f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \    if (a < 0) {\n      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n"
  code: "#pragma once\ntemplate <typename T>\nstruct Point {\n  T x, y;\n\n  Point()\
    \ : x(0), y(0) {}\n\n  template <typename A, typename B>\n  Point(A x, B y) :\
    \ x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A, B> p)\
    \ : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x + p.x,\
    \ y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n\
    \  bool operator==(Point p) const { return x == p.x && y == p.y; }\n  bool operator!=(Point\
    \ p) const { return x != p.x || y != p.y; }\n  Point operator-() const { return\
    \ {-x, -y}; }\n  Point operator*(T t) const { return {x * t, y * t}; }\n  Point\
    \ operator/(T t) const { return {x / t, y / t}; }\n\n  bool operator<(Point p)\
    \ const {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T dot(Point\
    \ other) { return x * other.x + y * other.y; }\n  T det(Point other) { return\
    \ x * other.y - y * other.x; }\n\n  double norm() { return sqrtl(x * x + y * y);\
    \ }\n  double angle() { return atan2(y, x); }\n\n  Point rotate(double theta)\
    \ {\n    static_assert(!is_integral<T>::value);\n    double c = cos(theta), s\
    \ = sin(theta);\n    return Point{c * x - s * y, s * x + c * y};\n  }\n};\n\n\
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
    \    if (a < 0) {\n      a = -a;\n      reverse(all(points));\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: geo/base.hpp
  requiredBy:
  - convex/fenchel.hpp
  - graph/planar_graph.hpp
  - geo/closest_pair.hpp
  - geo/angle_sort.hpp
  - geo/minimum_enclosing_circle.hpp
  - geo/distance.hpp
  - geo/reflection.hpp
  - geo/projection.hpp
  - geo/apollonian_circle.hpp
  - geo/max_norm_sum.hpp
  - geo/outcircle.hpp
  - geo/perpendicular_bisector.hpp
  - geo/incremental_convexhull.hpp
  - geo/count_points_in_triangles.hpp
  - geo/incircle.hpp
  - geo/dynamicupperhull.hpp
  - geo/cross_point.hpp
  - geo/convex_hull.hpp
  timestamp: '2023-12-21 22:18:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/library_checker/geometry/sort_points_by_argument_pair.test.cpp
  - test/library_checker/geometry/sort_points_by_argument.test.cpp
  - test/library_checker/geometry/convex_layers.test.cpp
  - test/mytest/count_points_in_triangles.test.cpp
  - test/mytest/incremental_ch.test.cpp
  - test/yukicoder/1777.test.cpp
  - test_atcoder/abc139f.test.cpp
  - test_atcoder/abc202_f.test.cpp
  - test_atcoder/abc220g.test.cpp
  - test_atcoder/abc266c.test.cpp
  - test_atcoder/arc130f.test.cpp
  - test_atcoder/abc314.test.cpp
  - test_atcoder/abc151f.test.cpp
  - test_atcoder/arc064c.test.cpp
documentation_of: geo/base.hpp
layout: document
redirect_from:
- /library/geo/base.hpp
- /library/geo/base.hpp.html
title: geo/base.hpp
---
