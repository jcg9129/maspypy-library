---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/mod_sum_of_linear.hpp
    title: mod/mod_sum_of_linear.hpp
  - icon: ':heavy_check_mark:'
    path: mod/range_freq_of_linear.hpp
    title: mod/range_freq_of_linear.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/min_of_mod_of_linear_2.test.cpp
    title: test/library_checker/math/min_of_mod_of_linear_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_floor_of_linear.test.cpp
    title: test/library_checker/math/sum_of_floor_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/mod_sum_of_linear.test.cpp
    title: test/mytest/mod_sum_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_freq_of_linear.test.cpp
    title: test/mytest/range_freq_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1201.test.cpp
    title: test/yukicoder/1201.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2066.test.cpp
    title: test/yukicoder/2066.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2280.test.cpp
    title: test/yukicoder/2280.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2440.test.cpp
    title: test/yukicoder/2440.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/floor_sum_of_linear.hpp\"\n\n// sum_{x in [L,R)} floor(ax\
    \ + b, mod)\n// I \u306F\u7BC4\u56F2\u5185\u3067 ax+b \u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u7A0B\u5EA6\ntemplate <typename O =\
    \ i128, typename I = long long>\nO floor_sum_of_linear(I L, I R, I a, I b, I mod)\
    \ {\n  assert(L <= R);\n  O res = 0;\n  b += L * a;\n  I N = R - L;\n\n  if (b\
    \ < 0) {\n    I k = ceil(-b, mod);\n    b += k * mod;\n    res -= O(N) * O(k);\n\
    \  }\n\n  while (N) {\n    I q;\n    tie(q, a) = divmod(a, mod);\n    res += (N\
    \ & 1 ? O(N) * O((N - 1) / 2) * O(q) : O(N / 2) * O(N - 1) * O(q));\n    if (b\
    \ >= mod) {\n      tie(q, b) = divmod(b, mod);\n      res += O(N) * q;\n    }\n\
    \    tie(N, b) = divmod(a * N + b, mod);\n    tie(a, mod) = mp(mod, a);\n  }\n\
    \  return res;\n}\n"
  code: "#pragma once\n\n// sum_{x in [L,R)} floor(ax + b, mod)\n// I \u306F\u7BC4\
    \u56F2\u5185\u3067 ax+b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\
    \u306A\u3044\u7A0B\u5EA6\ntemplate <typename O = i128, typename I = long long>\n\
    O floor_sum_of_linear(I L, I R, I a, I b, I mod) {\n  assert(L <= R);\n  O res\
    \ = 0;\n  b += L * a;\n  I N = R - L;\n\n  if (b < 0) {\n    I k = ceil(-b, mod);\n\
    \    b += k * mod;\n    res -= O(N) * O(k);\n  }\n\n  while (N) {\n    I q;\n\
    \    tie(q, a) = divmod(a, mod);\n    res += (N & 1 ? O(N) * O((N - 1) / 2) *\
    \ O(q) : O(N / 2) * O(N - 1) * O(q));\n    if (b >= mod) {\n      tie(q, b) =\
    \ divmod(b, mod);\n      res += O(N) * q;\n    }\n    tie(N, b) = divmod(a * N\
    \ + b, mod);\n    tie(a, mod) = mp(mod, a);\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/floor_sum_of_linear.hpp
  requiredBy:
  - mod/range_freq_of_linear.hpp
  - mod/mod_sum_of_linear.hpp
  timestamp: '2023-11-10 22:48:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2280.test.cpp
  - test/yukicoder/1201.test.cpp
  - test/yukicoder/2066.test.cpp
  - test/yukicoder/2440.test.cpp
  - test/mytest/mod_sum_of_linear.test.cpp
  - test/mytest/range_freq_of_linear.test.cpp
  - test/library_checker/math/sum_of_floor_of_linear.test.cpp
  - test/library_checker/math/min_of_mod_of_linear_2.test.cpp
documentation_of: mod/floor_sum_of_linear.hpp
layout: document
redirect_from:
- /library/mod/floor_sum_of_linear.hpp
- /library/mod/floor_sum_of_linear.hpp.html
title: mod/floor_sum_of_linear.hpp
---