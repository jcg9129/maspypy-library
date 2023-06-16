---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo/count_points_in_triangles.hpp
    title: geo/count_points_in_triangles.hpp
  - icon: ':heavy_check_mark:'
    path: geo/max_norm_sum.hpp
    title: geo/max_norm_sum.hpp
  _extendedVerifiedWith:
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
    path: test/mytest/qoj5443.test.cpp
    title: test/mytest/qoj5443.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc139f.test.cpp
    title: test_atcoder/abc139f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc202_f.test.cpp
    title: test_atcoder/abc202_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/angle_sort.hpp\"\n\r\n#line 2 \"geo/base.hpp\"\ntemplate\
    \ <typename T>\nstruct Point {\n  T x, y;\n\n  Point() = default;\n\n  template\
    \ <typename A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename\
    \ A, typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point\
    \ p) const { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const {\
    \ return {x - p.x, y - p.y}; }\n  bool operator==(Point p) const { return x ==\
    \ p.x && y == p.y; }\n  Point operator-() const { return {-x, -y}; }\n\n  bool\
    \ operator<(Point p) const {\n    if (x != p.x) return x < p.x;\n    return y\
    \ < p.y;\n  }\n  T dot(Point other) { return x * other.x + y * other.y; }\n  T\
    \ det(Point other) { return x * other.y - y * other.x; }\n\n  void read() { fastio::read(x),\
    \ fastio::read(y); }\n  void write() { fastio::printer.write(pair<T, T>({x, y}));\
    \ }\n};\n\n// A -> B -> C \u3068\u9032\u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\
    \u66F2\u304C\u308B\u306A\u3089\u3070 +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\
    \u3089\u3070 -1\ntemplate <typename T>\nint ccw(Point<T> A, Point<T> B, Point<T>\
    \ C) {\n  T x = (B - A).det(C - A);\n  if (x > 0) return 1;\n  if (x < 0) return\
    \ -1;\n  return 0;\n}\n\ntemplate <typename REAL, typename T>\nREAL dist(Point<T>\
    \ A, Point<T> B) {\n  A = A - B;\n  T p = A.dot(A);\n  return sqrt(REAL(p));\n\
    }\n\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T\
    \ c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y,\
    \ b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2)\
    \ : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n \
    \ U eval(Point<U> P) {\n    return a * P.x + b * P.y + c;\n  }\n\n  template <typename\
    \ U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n  bool is_parallel(Line\
    \ other) { return a * other.b - b * other.a == 0; }\n\n  bool is_orthogonal(Line\
    \ other) { return a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename\
    \ T>\nstruct Segment {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B)\
    \ : A(A), B(B) {}\n  Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n \
    \   if (det != 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A\
    \ - B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\ntemplate\
    \ <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n\n\
    template <typename T>\nstruct Polygon {\n  vc<Point<T>> points;\n  T a;\n\n  template\
    \ <typename A, typename B>\n  Polygon(vc<pair<A, B>> pairs) {\n    for (auto&&\
    \ [a, b]: pairs) points.eb(Point<T>(a, b));\n    build();\n  }\n  Polygon(vc<Point<T>>\
    \ points) : points(points) { build(); }\n\n  int size() { return len(points);\
    \ }\n\n  template <typename REAL>\n  REAL area() {\n    return a * 0.5;\n  }\n\
    \n  template <enable_if_t<is_integral<T>::value, int> = 0>\n  T area_2() {\n \
    \   return a;\n  }\n\n  bool is_convex() {\n    FOR(j, len(points)) {\n      int\
    \ i = (j == 0 ? len(points) - 1 : j - 1);\n      int k = (j == len(points) - 1\
    \ ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k] - points[j])\
    \ < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n  void build()\
    \ {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1 == len(points)\
    \ ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n    if (a < 0) {\n\
    \      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n#line 4 \"geo/angle_sort.hpp\"\
    \n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort\r\ntemplate\
    \ <typename T>\r\nvector<int> angle_argsort(vector<Point<T>>& P) {\r\n  vector<int>\
    \ lower, origin, upper;\r\n  const Point<T> O = {0, 0};\r\n  FOR(i, len(P)) {\r\
    \n    if (P[i] == O) origin.eb(i);\r\n    elif ((P[i].y < 0) || (P[i].y == 0 &&\
    \ P[i].x > 0)) lower.eb(i);\r\n    else upper.eb(i);\r\n  }\r\n  sort(all(lower),\
    \ [&](auto& i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  sort(all(upper),\
    \ [&](auto& i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  auto& I = lower;\r\
    \n  I.insert(I.end(), all(origin));\r\n  I.insert(I.end(), all(upper));\r\n  return\
    \ I;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort\r\
    \ntemplate <typename T>\r\nvector<int> angle_argsort(vector<pair<T, T>>& P) {\r\
    \n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\n\
    \  return angle_argsort<T>(tmp);\r\n}\r\n\r\n// inplace \u306B\u504F\u89D2\u30BD\
    \u30FC\u30C8\u3059\u308B\r\n// index \u304C\u6B32\u3057\u3044\u5834\u5408\u306F\
    \ angle_argsort\r\ntemplate <typename T>\r\nvoid angle_sort(vector<Point<T>>&\
    \ P) {\r\n  auto I = angle_argsort<T>(P);\r\n  P = rearrange(P, I);\r\n}\r\n\r\
    \n// inplace \u306B\u504F\u89D2\u30BD\u30FC\u30C8\u3059\u308B\r\n// index \u304C\
    \u6B32\u3057\u3044\u5834\u5408\u306F angle_argsort\r\ntemplate <typename T>\r\n\
    void angle_sort(vector<pair<T, T>>& P) {\r\n  auto I = angle_argsort<T>(P);\r\n\
    \  P = rearrange(P, I);\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"geo/base.hpp\"\r\n\r\n// \u504F\u89D2\u30BD\
    \u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort\r\ntemplate <typename T>\r\nvector<int>\
    \ angle_argsort(vector<Point<T>>& P) {\r\n  vector<int> lower, origin, upper;\r\
    \n  const Point<T> O = {0, 0};\r\n  FOR(i, len(P)) {\r\n    if (P[i] == O) origin.eb(i);\r\
    \n    elif ((P[i].y < 0) || (P[i].y == 0 && P[i].x > 0)) lower.eb(i);\r\n    else\
    \ upper.eb(i);\r\n  }\r\n  sort(all(lower), [&](auto& i, auto& j) { return P[i].det(P[j])\
    \ > 0; });\r\n  sort(all(upper), [&](auto& i, auto& j) { return P[i].det(P[j])\
    \ > 0; });\r\n  auto& I = lower;\r\n  I.insert(I.end(), all(origin));\r\n  I.insert(I.end(),\
    \ all(upper));\r\n  return I;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\
    \u5BFE\u3059\u308B argsort\r\ntemplate <typename T>\r\nvector<int> angle_argsort(vector<pair<T,\
    \ T>>& P) {\r\n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\
    \n  return angle_argsort<T>(tmp);\r\n}\r\n\r\n// inplace \u306B\u504F\u89D2\u30BD\
    \u30FC\u30C8\u3059\u308B\r\n// index \u304C\u6B32\u3057\u3044\u5834\u5408\u306F\
    \ angle_argsort\r\ntemplate <typename T>\r\nvoid angle_sort(vector<Point<T>>&\
    \ P) {\r\n  auto I = angle_argsort<T>(P);\r\n  P = rearrange(P, I);\r\n}\r\n\r\
    \n// inplace \u306B\u504F\u89D2\u30BD\u30FC\u30C8\u3059\u308B\r\n// index \u304C\
    \u6B32\u3057\u3044\u5834\u5408\u306F angle_argsort\r\ntemplate <typename T>\r\n\
    void angle_sort(vector<pair<T, T>>& P) {\r\n  auto I = angle_argsort<T>(P);\r\n\
    \  P = rearrange(P, I);\r\n}\r\n"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/angle_sort.hpp
  requiredBy:
  - geo/count_points_in_triangles.hpp
  - geo/max_norm_sum.hpp
  timestamp: '2023-04-08 00:43:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/geometry/sort_points_by_argument.test.cpp
  - test/library_checker/geometry/sort_points_by_argument_pair.test.cpp
  - test/mytest/count_points_in_triangles.test.cpp
  - test/mytest/qoj5443.test.cpp
  - test_atcoder/abc139f.test.cpp
  - test_atcoder/abc202_f.test.cpp
documentation_of: geo/angle_sort.hpp
layout: document
redirect_from:
- /library/geo/angle_sort.hpp
- /library/geo/angle_sort.hpp.html
title: geo/angle_sort.hpp
---
