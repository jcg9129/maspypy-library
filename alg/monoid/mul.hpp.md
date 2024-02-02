---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/sum_mul.hpp
    title: alg/acted_monoid/sum_mul.hpp
  - icon: ':x:'
    path: ds/power_query.hpp
    title: ds/power_query.hpp
  - icon: ':x:'
    path: graph/count/count_labeled_bipartite.hpp
    title: graph/count/count_labeled_bipartite.hpp
  - icon: ':x:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':x:'
    path: nt/discrete_log.hpp
    title: nt/discrete_log.hpp
  - icon: ':x:'
    path: poly/from_log_differentiation.hpp
    title: poly/from_log_differentiation.hpp
  - icon: ':x:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':x:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':x:'
    path: poly/sparse_exp_of_div.hpp
    title: poly/sparse_exp_of_div.hpp
  - icon: ':x:'
    path: poly/sum_of_C_negative.hpp
    title: poly/sum_of_C_negative.hpp
  - icon: ':x:'
    path: seq/interpolate_poly_exp_sum.hpp
    title: seq/interpolate_poly_exp_sum.hpp
  - icon: ':x:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/factorial.test.cpp
    title: test/library_checker/math/factorial.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':x:'
    path: test/mytest/count_bipartite.test.cpp
    title: test/mytest/count_bipartite.test.cpp
  - icon: ':x:'
    path: test/mytest/factorial_998.test.cpp
    title: test/mytest/factorial_998.test.cpp
  - icon: ':x:'
    path: test/mytest/powerquery.test.cpp
    title: test/mytest/powerquery.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1080_2.test.cpp
    title: test/yukicoder/1080_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2005.test.cpp
    title: test/yukicoder/2005.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2166.test.cpp
    title: test/yukicoder/2166.test.cpp
  - icon: ':x:'
    path: test/yukicoder/502_2.test.cpp
    title: test/yukicoder/502_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/899.test.cpp
    title: test/yukicoder/899.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc222g.test.cpp
    title: test_atcoder/abc222g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc222h_2.test.cpp
    title: test_atcoder/abc222h_2.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc270_g.test.cpp
    title: test_atcoder/abc270_g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc276_g.test.cpp
    title: test_atcoder/abc276_g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc276_g_2.test.cpp
    title: test_atcoder/abc276_g_2.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc144d.test.cpp
    title: test_atcoder/arc144d.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc160d.test.cpp
    title: test_atcoder/arc160d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/mul.hpp\"\n\r\ntemplate <class T>\r\nstruct Monoid_Mul\
    \ {\r\n  using value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return\
    \ X(1); }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class T>\r\nstruct Monoid_Mul {\r\n  using\
    \ value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const X &x, const\
    \ X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const X &x)\
    \ noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return X(1);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/mul.hpp
  requiredBy:
  - graph/count/count_labeled_bipartite.hpp
  - poly/sum_of_C_negative.hpp
  - poly/lagrange_interpolate_iota.hpp
  - poly/sparse_exp_of_div.hpp
  - poly/prefix_product_of_poly.hpp
  - poly/from_log_differentiation.hpp
  - nt/discrete_log.hpp
  - ds/power_query.hpp
  - seq/interpolate_poly_exp_sum.hpp
  - seq/kth_term_of_p_recursive.hpp
  - mod/mod_log.hpp
  - alg/acted_monoid/sum_mul.hpp
  timestamp: '2022-11-27 14:10:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc276_g_2.test.cpp
  - test_atcoder/abc270_g.test.cpp
  - test_atcoder/arc144d.test.cpp
  - test_atcoder/abc222h_2.test.cpp
  - test_atcoder/arc160d.test.cpp
  - test_atcoder/abc276_g.test.cpp
  - test_atcoder/abc222g.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - test/library_checker/math/factorial.test.cpp
  - test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/yukicoder/2005.test.cpp
  - test/yukicoder/2166.test.cpp
  - test/yukicoder/1080_2.test.cpp
  - test/yukicoder/899.test.cpp
  - test/yukicoder/502_2.test.cpp
  - test/mytest/count_bipartite.test.cpp
  - test/mytest/powerquery.test.cpp
  - test/mytest/factorial_998.test.cpp
documentation_of: alg/monoid/mul.hpp
layout: document
redirect_from:
- /library/alg/monoid/mul.hpp
- /library/alg/monoid/mul.hpp.html
title: alg/monoid/mul.hpp
---