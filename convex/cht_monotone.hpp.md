---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1297.test.cpp
    title: test/yukicoder/1297.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/913.test.cpp
    title: test/yukicoder/913.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc130f.test.cpp
    title: test_atcoder/arc130f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/cht_monotone.hpp\"\n// \u633F\u5165\u3057\u306A\u304C\
    \u3089 query_monotone \u3092\u4F7F\u3046\u5834\u5408\u3001\u76F4\u7DDA\u306E\u633F\
    \u5165\u9806\u3068\u540C\u3058\u65B9\u5411\u306E\u5358\u8ABF\u6027\u304C\u5FC5\
    \u8981\r\ntemplate <typename T, bool isMin>\r\nstruct CHT_monotone {\r\n#define\
    \ F first\r\n#define S second\r\n  using P = pair<T, T>;\r\n  deque<P> H;\r\n\r\
    \n  CHT_monotone() = default;\r\n\r\n  bool empty() const { return H.empty();\
    \ }\r\n\r\n  void clear() { H.clear(); }\r\n\r\n  inline int sgn(T x) { return\
    \ x == 0 ? 0 : (x < 0 ? -1 : 1); }\r\n\r\n  using D = long double;\r\n\r\n  inline\
    \ bool check(const P &a, const P &b, const P &c) {\r\n    if (b.S == a.S || c.S\
    \ == b.S)\r\n      return sgn(b.F - a.F) * sgn(c.S - b.S) >= sgn(c.F - b.F) *\
    \ sgn(b.S - a.S);\r\n\r\n    // return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);\r\
    \n    return D(b.F - a.F) * sgn(c.S - b.S) / D(abs(b.S - a.S))\r\n           >=\
    \ D(c.F - b.F) * sgn(b.S - a.S) / D(abs(c.S - b.S));\r\n  }\r\n\r\n  void add(T\
    \ a, T b) {\r\n    if (!isMin) a *= -1, b *= -1;\r\n    P line(a, b);\r\n    if\
    \ (empty()) {\r\n      H.emplace_front(line);\r\n      return;\r\n    }\r\n  \
    \  if (H.front().F <= a) {\r\n      if (H.front().F == a) {\r\n        if (H.front().S\
    \ <= b) return;\r\n        H.pop_front();\r\n      }\r\n      while (H.size()\
    \ >= 2 && check(line, H.front(), H[1])) H.pop_front();\r\n      H.emplace_front(line);\r\
    \n    } else {\r\n      assert(a <= H.back().F);\r\n      if (H.back().F == a)\
    \ {\r\n        if (H.back().S <= b) return;\r\n        H.pop_back();\r\n     \
    \ }\r\n      while (H.size() >= 2 && check(H[H.size() - 2], H.back(), line))\r\
    \n        H.pop_back();\r\n      H.emplace_back(line);\r\n    }\r\n  }\r\n\r\n\
    \  inline T get_y(const P &a, const T &x) { return a.F * x + a.S; }\r\n\r\n  T\
    \ query(T x) {\r\n    assert(!empty());\r\n    int l = -1, r = H.size() - 1;\r\
    \n    while (l + 1 < r) {\r\n      int m = (l + r) >> 1;\r\n      if (get_y(H[m],\
    \ x) >= get_y(H[m + 1], x))\r\n        l = m;\r\n      else\r\n        r = m;\r\
    \n    }\r\n    if (isMin) return get_y(H[r], x);\r\n    return -get_y(H[r], x);\r\
    \n  }\r\n\r\n  T query_monotone_inc(T x) {\r\n    assert(!empty());\r\n    while\
    \ (H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x))\r\n      H.pop_front();\r\
    \n    if (isMin) return get_y(H.front(), x);\r\n    return -get_y(H.front(), x);\r\
    \n  }\r\n\r\n  T query_monotone_dec(T x) {\r\n    assert(!empty());\r\n    while\
    \ (H.size() >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x))\r\n     \
    \ H.pop_back();\r\n    if (isMin) return get_y(H.back(), x);\r\n    return -get_y(H.back(),\
    \ x);\r\n  }\r\n\r\n#undef F\r\n#undef S\r\n};\n"
  code: "// \u633F\u5165\u3057\u306A\u304C\u3089 query_monotone \u3092\u4F7F\u3046\
    \u5834\u5408\u3001\u76F4\u7DDA\u306E\u633F\u5165\u9806\u3068\u540C\u3058\u65B9\
    \u5411\u306E\u5358\u8ABF\u6027\u304C\u5FC5\u8981\r\ntemplate <typename T, bool\
    \ isMin>\r\nstruct CHT_monotone {\r\n#define F first\r\n#define S second\r\n \
    \ using P = pair<T, T>;\r\n  deque<P> H;\r\n\r\n  CHT_monotone() = default;\r\n\
    \r\n  bool empty() const { return H.empty(); }\r\n\r\n  void clear() { H.clear();\
    \ }\r\n\r\n  inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }\r\n\
    \r\n  using D = long double;\r\n\r\n  inline bool check(const P &a, const P &b,\
    \ const P &c) {\r\n    if (b.S == a.S || c.S == b.S)\r\n      return sgn(b.F -\
    \ a.F) * sgn(c.S - b.S) >= sgn(c.F - b.F) * sgn(b.S - a.S);\r\n\r\n    // return\
    \ (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);\r\n    return D(b.F - a.F) * sgn(c.S\
    \ - b.S) / D(abs(b.S - a.S))\r\n           >= D(c.F - b.F) * sgn(b.S - a.S) /\
    \ D(abs(c.S - b.S));\r\n  }\r\n\r\n  void add(T a, T b) {\r\n    if (!isMin) a\
    \ *= -1, b *= -1;\r\n    P line(a, b);\r\n    if (empty()) {\r\n      H.emplace_front(line);\r\
    \n      return;\r\n    }\r\n    if (H.front().F <= a) {\r\n      if (H.front().F\
    \ == a) {\r\n        if (H.front().S <= b) return;\r\n        H.pop_front();\r\
    \n      }\r\n      while (H.size() >= 2 && check(line, H.front(), H[1])) H.pop_front();\r\
    \n      H.emplace_front(line);\r\n    } else {\r\n      assert(a <= H.back().F);\r\
    \n      if (H.back().F == a) {\r\n        if (H.back().S <= b) return;\r\n   \
    \     H.pop_back();\r\n      }\r\n      while (H.size() >= 2 && check(H[H.size()\
    \ - 2], H.back(), line))\r\n        H.pop_back();\r\n      H.emplace_back(line);\r\
    \n    }\r\n  }\r\n\r\n  inline T get_y(const P &a, const T &x) { return a.F *\
    \ x + a.S; }\r\n\r\n  T query(T x) {\r\n    assert(!empty());\r\n    int l = -1,\
    \ r = H.size() - 1;\r\n    while (l + 1 < r) {\r\n      int m = (l + r) >> 1;\r\
    \n      if (get_y(H[m], x) >= get_y(H[m + 1], x))\r\n        l = m;\r\n      else\r\
    \n        r = m;\r\n    }\r\n    if (isMin) return get_y(H[r], x);\r\n    return\
    \ -get_y(H[r], x);\r\n  }\r\n\r\n  T query_monotone_inc(T x) {\r\n    assert(!empty());\r\
    \n    while (H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x))\r\n     \
    \ H.pop_front();\r\n    if (isMin) return get_y(H.front(), x);\r\n    return -get_y(H.front(),\
    \ x);\r\n  }\r\n\r\n  T query_monotone_dec(T x) {\r\n    assert(!empty());\r\n\
    \    while (H.size() >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x))\r\
    \n      H.pop_back();\r\n    if (isMin) return get_y(H.back(), x);\r\n    return\
    \ -get_y(H.back(), x);\r\n  }\r\n\r\n#undef F\r\n#undef S\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: convex/cht_monotone.hpp
  requiredBy: []
  timestamp: '2022-12-23 11:08:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/913.test.cpp
  - test/yukicoder/1297.test.cpp
  - test_atcoder/arc130f.test.cpp
documentation_of: convex/cht_monotone.hpp
layout: document
redirect_from:
- /library/convex/cht_monotone.hpp
- /library/convex/cht_monotone.hpp.html
title: convex/cht_monotone.hpp
---