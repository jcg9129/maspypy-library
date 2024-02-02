---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/minidx_add.hpp
    title: alg/acted_monoid/minidx_add.hpp
  - icon: ':x:'
    path: geo/manhattan_nns.hpp
    title: geo/manhattan_nns.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/manhattan_nns.test.cpp
    title: test/mytest/manhattan_nns.test.cpp
  - icon: ':x:'
    path: test/mytest/minidx_add.test.cpp
    title: test/mytest/minidx_add.test.cpp
  - icon: ':x:'
    path: test/mytest/suffix_tree.test.cpp
    title: test/mytest/suffix_tree.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2361.test.cpp
    title: test/yukicoder/2361.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc301h.test.cpp
    title: test_atcoder/abc301h.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min_idx.hpp\"\n\r\ntemplate <typename T, bool\
    \ tie_is_left = true>\r\nstruct Monoid_Min_Idx {\r\n  using value_type = pair<T,\
    \ int>;\r\n  using X = value_type;\r\n  static constexpr bool is_small(const X&\
    \ x, const X& y) {\r\n    if (x.fi < y.fi) return true;\r\n    if (x.fi > y.fi)\
    \ return false;\r\n    return (tie_is_left ? (x.se < y.se) : (x.se >= y.se));\r\
    \n  }\r\n  static X op(X x, X y) { return (is_small(x, y) ? x : y); }\r\n  static\
    \ constexpr X unit() { return {infty<T>, -1}; }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, bool tie_is_left = true>\r\nstruct\
    \ Monoid_Min_Idx {\r\n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\
    \n  static constexpr bool is_small(const X& x, const X& y) {\r\n    if (x.fi <\
    \ y.fi) return true;\r\n    if (x.fi > y.fi) return false;\r\n    return (tie_is_left\
    \ ? (x.se < y.se) : (x.se >= y.se));\r\n  }\r\n  static X op(X x, X y) { return\
    \ (is_small(x, y) ? x : y); }\r\n  static constexpr X unit() { return {infty<T>,\
    \ -1}; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/min_idx.hpp
  requiredBy:
  - geo/manhattan_nns.hpp
  - alg/acted_monoid/minidx_add.hpp
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc301h.test.cpp
  - test/yukicoder/2361.test.cpp
  - test/mytest/suffix_tree.test.cpp
  - test/mytest/minidx_add.test.cpp
  - test/mytest/manhattan_nns.test.cpp
documentation_of: alg/monoid/min_idx.hpp
layout: document
redirect_from:
- /library/alg/monoid/min_idx.hpp
- /library/alg/monoid/min_idx.hpp.html
title: alg/monoid/min_idx.hpp
---