---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n  template <typename A, typename B>\n  Point(A x, B y) : x(x), y(y)\
    \ {}\n\n  template <typename A, typename B>\n  Point(pair<A, B> p) : x(p.fi),\
    \ y(p.se) {}\n\n  Point operator+(Point p) const { return {x + p.x, y + p.y};\
    \ }\n  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n  bool operator==(Point\
    \ p) const { return x == p.x && y == p.y; }\n  Point operator-() const { return\
    \ {-x, -y}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return x\
    \ < p.x;\n    return y < p.y;\n  }\n\n  T dot(Point other) { return x * other.x\
    \ + y * other.y; }\n  T det(Point other) { return x * other.y - y * other.x; }\n\
    };\n\ntemplate <typename REAL, typename T>\nREAL dist(Point<T> A, Point<T> B)\
    \ {\n  A -= B;\n  T p = A.dot(A);\n  return sqrt(REAL(p));\n}\n\ntemplate <typename\
    \ T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c)\
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y;\n    b = B.x - A.x;\n\
    \    c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return a * P.x + b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U\
    \ x, U y) {\n    return a * x + b * y + c;\n  }\n};\n#line 2 \"geo_old/angle_sort.hpp\"\
    \n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort\r\ntemplate<typename\
    \ Point>\r\nvector<int> angle_argsort(vector<Point>& P) {\r\n  auto is_lower =\
    \ [](Point P) { return (P.y < 0) || (P.y == 0 && P.x > 0); };\r\n  vector<int>\
    \ lower, origin, upper;\r\n  Point O = {0, 0};\r\n  FOR(i, len(P)) {\r\n    if\
    \ (P[i] == O) origin.eb(i);\r\n    elif (is_lower(P[i])) lower.eb(i);\r\n    else\
    \ upper.eb(i);\r\n  }\r\n  sort(all(lower), [&](auto& i, auto& j) { return P[i].det(P[j])\
    \ > 0; });\r\n  sort(all(upper), [&](auto& i, auto& j) { return P[i].det(P[j])\
    \ > 0; });\r\n  auto& I = lower;\r\n  I.insert(I.end(), all(origin));\r\n  I.insert(I.end(),\
    \ all(upper));\r\n  return I;\r\n}\r\n\r\n// inplace \u306B\u504F\u89D2\u30BD\u30FC\
    \u30C8\u3059\u308B\r\n// index \u304C\u6B32\u3057\u3044\u5834\u5408\u306F angle_argsort\r\
    \ntemplate<typename Point>\r\nvoid angle_sort(vector<Point>& P) {\r\n  auto I\
    \ = angle_argsort(P);\r\n  vc<Point> Q(len(P));\r\n  FOR(i, len(P)) Q[i] = P[I[i]];\r\
    \n  P = Q;\r\n}\r\n"
  code: "#include \"geo/base.hpp\"\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\
    \u3059\u308B argsort\r\ntemplate<typename Point>\r\nvector<int> angle_argsort(vector<Point>&\
    \ P) {\r\n  auto is_lower = [](Point P) { return (P.y < 0) || (P.y == 0 && P.x\
    \ > 0); };\r\n  vector<int> lower, origin, upper;\r\n  Point O = {0, 0};\r\n \
    \ FOR(i, len(P)) {\r\n    if (P[i] == O) origin.eb(i);\r\n    elif (is_lower(P[i]))\
    \ lower.eb(i);\r\n    else upper.eb(i);\r\n  }\r\n  sort(all(lower), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  sort(all(upper), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  auto& I = lower;\r\n  I.insert(I.end(),\
    \ all(origin));\r\n  I.insert(I.end(), all(upper));\r\n  return I;\r\n}\r\n\r\n\
    // inplace \u306B\u504F\u89D2\u30BD\u30FC\u30C8\u3059\u308B\r\n// index \u304C\
    \u6B32\u3057\u3044\u5834\u5408\u306F angle_argsort\r\ntemplate<typename Point>\r\
    \nvoid angle_sort(vector<Point>& P) {\r\n  auto I = angle_argsort(P);\r\n  vc<Point>\
    \ Q(len(P));\r\n  FOR(i, len(P)) Q[i] = P[I[i]];\r\n  P = Q;\r\n}\r\n"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo_old/angle_sort.hpp
  requiredBy: []
  timestamp: '2022-08-20 05:23:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo_old/angle_sort.hpp
layout: document
redirect_from:
- /library/geo_old/angle_sort.hpp
- /library/geo_old/angle_sort.hpp.html
title: geo_old/angle_sort.hpp
---
