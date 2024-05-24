---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  - icon: ':x:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp
  - icon: ':x:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp
  - icon: ':x:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range_static_abelgroup.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range_static_abelgroup.hpp
  - icon: ':x:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp
  - icon: ':warning:'
    path: graph/ds/tree_wavelet_matrix.hpp
    title: graph/ds/tree_wavelet_matrix.hpp
  - icon: ':x:'
    path: string/prefix_substring_LCS.hpp
    title: string/prefix_substring_LCS.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/rectangle_sum_wm.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_wm.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/rectangle_sum_wm_abel.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_wm_abel.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/prefix_substring_lcs.test.cpp
    title: test/library_checker/string/prefix_substring_lcs.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1332.test.cpp
    title: test/yukicoder/1332.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1600_2.test.cpp
    title: test/yukicoder/1600_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1625_2.test.cpp
    title: test/yukicoder/1625_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1919_2.test.cpp
    title: test/yukicoder/1919_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2065.test.cpp
    title: test/yukicoder/2065.test.cpp
  - icon: ':x:'
    path: test/yukicoder/919.test.cpp
    title: test/yukicoder/919.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc127f_1.test.cpp
    title: test_atcoder/abc127f_1.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc324g.test.cpp
    title: test_atcoder/abc324g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  vc<pair<u32,\
    \ u32>> dat;\n  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }\n\n \
    \ void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }\n\n  void build()\
    \ {\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n\
    \  }\n\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  int rank(int k, bool\
    \ f = 1) {\n    auto [a, b] = dat[k >> 5];\n    int ret = b + popcnt(a & ((u32(1)\
    \ << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n  }\n};\n"
  code: "struct Bit_Vector {\n  vc<pair<u32, u32>> dat;\n  Bit_Vector(int n) { dat.assign((n\
    \ + 63) >> 5, {0, 0}); }\n\n  void set(int i) { dat[i >> 5].fi |= u32(1) << (i\
    \ & 31); }\n\n  void build() {\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se\
    \ + popcnt(dat[i].fi);\n  }\n\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n\
    \  int rank(int k, bool f = 1) {\n    auto [a, b] = dat[k >> 5];\n    int ret\
    \ = b + popcnt(a & ((u32(1) << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/bit_vector.hpp
  requiredBy:
  - ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_monoid.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range_static_abelgroup.hpp
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp
  - graph/ds/tree_wavelet_matrix.hpp
  - string/prefix_substring_LCS.hpp
  timestamp: '2022-12-12 13:31:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc324g.test.cpp
  - test_atcoder/abc127f_1.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
  - test/library_checker/datastructure/rectangle_sum_wm.test.cpp
  - test/library_checker/datastructure/rectangle_sum_wm_abel.test.cpp
  - test/library_checker/string/prefix_substring_lcs.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/919.test.cpp
  - test/yukicoder/1919_2.test.cpp
  - test/yukicoder/1625_2.test.cpp
  - test/yukicoder/1332.test.cpp
  - test/yukicoder/2065.test.cpp
  - test/yukicoder/1600_2.test.cpp
documentation_of: ds/bit_vector.hpp
layout: document
redirect_from:
- /library/ds/bit_vector.hpp
- /library/ds/bit_vector.hpp.html
title: ds/bit_vector.hpp
---
