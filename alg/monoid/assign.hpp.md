---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/max_assign.hpp
    title: alg/acted_monoid/max_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/powersums_assign.hpp
    title: alg/acted_monoid/powersums_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/sum_assign.hpp
    title: alg/acted_monoid/sum_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/summax_assign.hpp
    title: alg/acted_monoid/summax_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/summin_assign.hpp
    title: alg/acted_monoid/summin_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/dynamic_lazy_segtree.test.cpp
    title: test/mytest/dynamic_lazy_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
    title: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_assign.test.cpp
    title: test/mytest/max_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_assign.test.cpp
    title: test/mytest/range_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_am.test.cpp
    title: test/mytest/rbst_am.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_am_persistent.test.cpp
    title: test/mytest/rbst_am_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_monoid.test.cpp
    title: test/mytest/rbst_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_monoid_persistent.test.cpp
    title: test/mytest/rbst_monoid_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/splay_monoid.test.cpp
    title: test/mytest/splay_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/summax_assign.test.cpp
    title: test/mytest/summax_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/summin_assign.test.cpp
    title: test/mytest/summin_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1548.test.cpp
    title: test/yukicoder/1548.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2292.test.cpp
    title: test/yukicoder/2292.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc256ex.test.cpp
    title: test_atcoder/abc256ex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc256ex2.test.cpp
    title: test_atcoder/abc256ex2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/assign.hpp\"\n\r\ntemplate <typename X, int none_val>\r\
    \nstruct Monoid_Assign {\r\n  using value_type = X;\r\n  static X op(X x, X y)\
    \ { return (y == X(none_val) ? x : y); }\r\n  static constexpr X unit() { return\
    \ X(none_val); }\r\n  static constexpr bool commute = false;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename X, int none_val>\r\nstruct Monoid_Assign\
    \ {\r\n  using value_type = X;\r\n  static X op(X x, X y) { return (y == X(none_val)\
    \ ? x : y); }\r\n  static constexpr X unit() { return X(none_val); }\r\n  static\
    \ constexpr bool commute = false;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/assign.hpp
  requiredBy:
  - alg/acted_monoid/min_assign.hpp
  - alg/acted_monoid/max_assign.hpp
  - alg/acted_monoid/sum_assign.hpp
  - alg/acted_monoid/summin_assign.hpp
  - alg/acted_monoid/powersums_assign.hpp
  - alg/acted_monoid/summax_assign.hpp
  timestamp: '2023-10-14 20:28:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc256ex.test.cpp
  - test_atcoder/abc256ex2.test.cpp
  - test/mytest/summin_assign.test.cpp
  - test/mytest/rbst_monoid_persistent.test.cpp
  - test/mytest/summax_assign.test.cpp
  - test/mytest/rbst_monoid.test.cpp
  - test/mytest/dynamic_lazy_segtree.test.cpp
  - test/mytest/rbst_am_persistent.test.cpp
  - test/mytest/dynamic_lazy_segtree_persistent.test.cpp
  - test/mytest/max_assign.test.cpp
  - test/mytest/splay_monoid.test.cpp
  - test/mytest/range_assign.test.cpp
  - test/mytest/rbst_am.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_D.test.cpp
  - test/yukicoder/2292.test.cpp
  - test/yukicoder/1548.test.cpp
documentation_of: alg/monoid/assign.hpp
layout: document
redirect_from:
- /library/alg/monoid/assign.hpp
- /library/alg/monoid/assign.hpp.html
title: alg/monoid/assign.hpp
---
