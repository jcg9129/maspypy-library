---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1297.test.cpp
    title: test/yukicoder/1297.test.cpp
  - icon: ':x:'
    path: test/yukicoder/913.test.cpp
    title: test/yukicoder/913.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc130f.test.cpp
    title: test_atcoder/arc130f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/cht_monotone.hpp\"\n// \u633F\u5165\u3057\u306A\u304C\
    \u3089 query_monotone \u3092\u4F7F\u3046\u5834\u5408\u3001\u76F4\u7DDA\u306E\u633F\
    \u5165\u9806\u3068\u540C\u3058\u65B9\u5411\u306E\u5358\u8ABF\u6027\u304C\u5FC5\
    \u8981\r\ntemplate <typename T, bool isMin>\r\nstruct CHT_monotone {\r\n  struct\
    \ Line {\r\n    T a, b;\r\n    int idx;\r\n  };\r\n  deque<Line> H;\r\n  int nxt_idx\
    \ = 0;\r\n\r\n  CHT_monotone() = default;\r\n\r\n  bool empty() const { return\
    \ H.empty(); }\r\n  void clear() { H.clear(); }\r\n\r\n  inline int sgn(T x) {\
    \ return x == 0 ? 0 : (x < 0 ? -1 : 1); }\r\n  using D = long double;\r\n  inline\
    \ bool check(const Line &a, const Line &b, const Line &c) {\r\n    if (b.b ==\
    \ a.b || c.b == b.b)\r\n      return sgn(b.a - a.a) * sgn(c.b - b.b) >= sgn(c.a\
    \ - b.a) * sgn(b.b - a.b);\r\n    // return (b.a-a.a)*(c.b-b.b) >= (b.b-a.b)*(c.a-b.a);\r\
    \n    return D(b.a - a.a) * sgn(c.b - b.b) / D(abs(b.b - a.b))\r\n           >=\
    \ D(c.a - b.a) * sgn(b.b - a.b) / D(abs(c.b - b.b));\r\n  }\r\n\r\n  void add(T\
    \ a, T b, int idx = -1) {\r\n    if (idx == -1) { idx = nxt_idx++; }\r\n    if\
    \ (!isMin) a *= -1, b *= -1;\r\n    Line L{a, b, idx};\r\n    if (empty()) {\r\
    \n      H.emplace_front(L);\r\n      return;\r\n    }\r\n    if (H.front().a <=\
    \ a) {\r\n      if (H.front().a == a) {\r\n        if (H.front().b <= b) return;\r\
    \n        H.pop_front();\r\n      }\r\n      while (H.size() >= 2 && check(L,\
    \ H.front(), H[1])) { H.pop_front(); }\r\n      H.emplace_front(L);\r\n    } else\
    \ {\r\n      assert(a <= H.back().a);\r\n      if (H.back().a == a) {\r\n    \
    \    if (H.back().b <= b) return;\r\n        H.pop_back();\r\n      }\r\n    \
    \  while (H.size() >= 2 && check(H[H.size() - 2], H.back(), L)) H.pop_back();\r\
    \n      H.emplace_back(L);\r\n    }\r\n  }\r\n\r\n  inline T get_y(const Line\
    \ &a, const T &x) { return a.a * x + a.b; }\r\n\r\n  pair<T, int> query(T x) {\r\
    \n    assert(!empty());\r\n    int l = -1, r = H.size() - 1;\r\n    while (l +\
    \ 1 < r) {\r\n      int m = (l + r) >> 1;\r\n      if (get_y(H[m], x) >= get_y(H[m\
    \ + 1], x))\r\n        l = m;\r\n      else\r\n        r = m;\r\n    }\r\n   \
    \ if (isMin) return {get_y(H[r], x), H[r].idx};\r\n    return {-get_y(H[r], x),\
    \ H[r].idx};\r\n  }\r\n\r\n  pair<T, int> query_monotone_inc(T x) {\r\n    assert(!empty());\r\
    \n    while (H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x))\r\n     \
    \ H.pop_front();\r\n    if (isMin) return {get_y(H.front(), x), H.front().idx};\r\
    \n    return {-get_y(H.front(), x), H.front().idx};\r\n  }\r\n\r\n  pair<T, int>\
    \ query_monotone_dec(T x) {\r\n    assert(!empty());\r\n    while (H.size() >=\
    \ 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x))\r\n      H.pop_back();\r\
    \n    if (isMin) return {get_y(H.back(), x), H.back().idx};\r\n    return {-get_y(H.back(),\
    \ x), H.back().idx};\r\n  }\r\n};\n"
  code: "// \u633F\u5165\u3057\u306A\u304C\u3089 query_monotone \u3092\u4F7F\u3046\
    \u5834\u5408\u3001\u76F4\u7DDA\u306E\u633F\u5165\u9806\u3068\u540C\u3058\u65B9\
    \u5411\u306E\u5358\u8ABF\u6027\u304C\u5FC5\u8981\r\ntemplate <typename T, bool\
    \ isMin>\r\nstruct CHT_monotone {\r\n  struct Line {\r\n    T a, b;\r\n    int\
    \ idx;\r\n  };\r\n  deque<Line> H;\r\n  int nxt_idx = 0;\r\n\r\n  CHT_monotone()\
    \ = default;\r\n\r\n  bool empty() const { return H.empty(); }\r\n  void clear()\
    \ { H.clear(); }\r\n\r\n  inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1\
    \ : 1); }\r\n  using D = long double;\r\n  inline bool check(const Line &a, const\
    \ Line &b, const Line &c) {\r\n    if (b.b == a.b || c.b == b.b)\r\n      return\
    \ sgn(b.a - a.a) * sgn(c.b - b.b) >= sgn(c.a - b.a) * sgn(b.b - a.b);\r\n    //\
    \ return (b.a-a.a)*(c.b-b.b) >= (b.b-a.b)*(c.a-b.a);\r\n    return D(b.a - a.a)\
    \ * sgn(c.b - b.b) / D(abs(b.b - a.b))\r\n           >= D(c.a - b.a) * sgn(b.b\
    \ - a.b) / D(abs(c.b - b.b));\r\n  }\r\n\r\n  void add(T a, T b, int idx = -1)\
    \ {\r\n    if (idx == -1) { idx = nxt_idx++; }\r\n    if (!isMin) a *= -1, b *=\
    \ -1;\r\n    Line L{a, b, idx};\r\n    if (empty()) {\r\n      H.emplace_front(L);\r\
    \n      return;\r\n    }\r\n    if (H.front().a <= a) {\r\n      if (H.front().a\
    \ == a) {\r\n        if (H.front().b <= b) return;\r\n        H.pop_front();\r\
    \n      }\r\n      while (H.size() >= 2 && check(L, H.front(), H[1])) { H.pop_front();\
    \ }\r\n      H.emplace_front(L);\r\n    } else {\r\n      assert(a <= H.back().a);\r\
    \n      if (H.back().a == a) {\r\n        if (H.back().b <= b) return;\r\n   \
    \     H.pop_back();\r\n      }\r\n      while (H.size() >= 2 && check(H[H.size()\
    \ - 2], H.back(), L)) H.pop_back();\r\n      H.emplace_back(L);\r\n    }\r\n \
    \ }\r\n\r\n  inline T get_y(const Line &a, const T &x) { return a.a * x + a.b;\
    \ }\r\n\r\n  pair<T, int> query(T x) {\r\n    assert(!empty());\r\n    int l =\
    \ -1, r = H.size() - 1;\r\n    while (l + 1 < r) {\r\n      int m = (l + r) >>\
    \ 1;\r\n      if (get_y(H[m], x) >= get_y(H[m + 1], x))\r\n        l = m;\r\n\
    \      else\r\n        r = m;\r\n    }\r\n    if (isMin) return {get_y(H[r], x),\
    \ H[r].idx};\r\n    return {-get_y(H[r], x), H[r].idx};\r\n  }\r\n\r\n  pair<T,\
    \ int> query_monotone_inc(T x) {\r\n    assert(!empty());\r\n    while (H.size()\
    \ >= 2 && get_y(H.front(), x) >= get_y(H[1], x))\r\n      H.pop_front();\r\n \
    \   if (isMin) return {get_y(H.front(), x), H.front().idx};\r\n    return {-get_y(H.front(),\
    \ x), H.front().idx};\r\n  }\r\n\r\n  pair<T, int> query_monotone_dec(T x) {\r\
    \n    assert(!empty());\r\n    while (H.size() >= 2 && get_y(H.back(), x) >= get_y(H[H.size()\
    \ - 2], x))\r\n      H.pop_back();\r\n    if (isMin) return {get_y(H.back(), x),\
    \ H.back().idx};\r\n    return {-get_y(H.back(), x), H.back().idx};\r\n  }\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: convex/cht_monotone.hpp
  requiredBy: []
  timestamp: '2023-12-21 22:18:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/arc130f.test.cpp
  - test/yukicoder/1297.test.cpp
  - test/yukicoder/913.test.cpp
documentation_of: convex/cht_monotone.hpp
layout: document
redirect_from:
- /library/convex/cht_monotone.hpp
- /library/convex/cht_monotone.hpp.html
title: convex/cht_monotone.hpp
---