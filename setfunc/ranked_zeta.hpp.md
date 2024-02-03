---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linalg/hafnian.hpp
    title: linalg/hafnian.hpp
  - icon: ':question:'
    path: setfunc/sps_composition.hpp
    title: setfunc/sps_composition.hpp
  - icon: ':question:'
    path: setfunc/sps_exp.hpp
    title: setfunc/sps_exp.hpp
  - icon: ':question:'
    path: setfunc/sps_log.hpp
    title: setfunc/sps_log.hpp
  - icon: ':question:'
    path: setfunc/subset_convolution.hpp
    title: setfunc/subset_convolution.hpp
  - icon: ':x:'
    path: setfunc/transposed_sps_composition.hpp
    title: setfunc/transposed_sps_composition.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/subset_convolution.test.cpp
    title: test/library_checker/convolution/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/composition_sps.test.cpp
    title: test/library_checker/math/composition_sps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sps_exp.test.cpp
    title: test/library_checker/math/sps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/hafnian_of_matrix.test.cpp
    title: test/library_checker/matrix/hafnian_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2507.test.cpp
    title: test/yukicoder/2507.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc213g.test.cpp
    title: test_atcoder/abc213g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc236h.test.cpp
    title: test_atcoder/abc236h.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc253h.test.cpp
    title: test_atcoder/abc253h.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc321g.test.cpp
    title: test_atcoder/abc321g.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc105.test.cpp
    title: test_atcoder/arc105.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/ranked_zeta.hpp\"\n\r\ntemplate <typename T, int\
    \ LIM>\r\nvc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\r\n  int n = topbit(len(f));\r\
    \n  assert(n <= LIM);\r\n  assert(len(f) == 1 << n);\r\n  vc<array<T, LIM + 1>>\
    \ Rf(1 << n);\r\n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    int w = 1 << i;\r\n    for (int p = 0;\
    \ p < (1 << n); p += 2 * w) {\r\n      for (int s = p; s < p + w; ++s) {\r\n \
    \       int t = s | 1 << i;\r\n        for (int d = 0; d <= n; ++d) Rf[t][d] +=\
    \ Rf[s][d];\r\n      }\r\n    }\r\n  }\r\n  return Rf;\r\n}\r\n\r\ntemplate <typename\
    \ T, int LIM>\r\nvc<T> ranked_mobius(vc<array<T, LIM + 1>>& Rf) {\r\n  int n =\
    \ topbit(len(Rf));\r\n  assert(len(Rf) == 1 << n);\r\n  for (int i = 0; i < n;\
    \ ++i) {\r\n    int w = 1 << i;\r\n    for (int p = 0; p < (1 << n); p += 2 *\
    \ w) {\r\n      for (int s = p; s < p + w; ++s) {\r\n        int t = s | 1 <<\
    \ i;\r\n        for (int d = 0; d <= n; ++d) Rf[t][d] -= Rf[s][d];\r\n      }\r\
    \n    }\r\n  }\r\n  vc<T> f(1 << n);\r\n  for (int s = 0; s < (1 << n); ++s) f[s]\
    \ = Rf[s][popcnt(s)];\r\n  return f;\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, int LIM>\r\nvc<array<T, LIM + 1>>\
    \ ranked_zeta(const vc<T>& f) {\r\n  int n = topbit(len(f));\r\n  assert(n <=\
    \ LIM);\r\n  assert(len(f) == 1 << n);\r\n  vc<array<T, LIM + 1>> Rf(1 << n);\r\
    \n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    int w = 1 << i;\r\n    for (int p = 0; p < (1 <<\
    \ n); p += 2 * w) {\r\n      for (int s = p; s < p + w; ++s) {\r\n        int\
    \ t = s | 1 << i;\r\n        for (int d = 0; d <= n; ++d) Rf[t][d] += Rf[s][d];\r\
    \n      }\r\n    }\r\n  }\r\n  return Rf;\r\n}\r\n\r\ntemplate <typename T, int\
    \ LIM>\r\nvc<T> ranked_mobius(vc<array<T, LIM + 1>>& Rf) {\r\n  int n = topbit(len(Rf));\r\
    \n  assert(len(Rf) == 1 << n);\r\n  for (int i = 0; i < n; ++i) {\r\n    int w\
    \ = 1 << i;\r\n    for (int p = 0; p < (1 << n); p += 2 * w) {\r\n      for (int\
    \ s = p; s < p + w; ++s) {\r\n        int t = s | 1 << i;\r\n        for (int\
    \ d = 0; d <= n; ++d) Rf[t][d] -= Rf[s][d];\r\n      }\r\n    }\r\n  }\r\n  vc<T>\
    \ f(1 << n);\r\n  for (int s = 0; s < (1 << n); ++s) f[s] = Rf[s][popcnt(s)];\r\
    \n  return f;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/ranked_zeta.hpp
  requiredBy:
  - linalg/hafnian.hpp
  - setfunc/sps_log.hpp
  - setfunc/transposed_sps_composition.hpp
  - setfunc/sps_composition.hpp
  - setfunc/sps_exp.hpp
  - setfunc/subset_convolution.hpp
  timestamp: '2023-09-23 23:33:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc321g.test.cpp
  - test_atcoder/abc236h.test.cpp
  - test_atcoder/abc213g.test.cpp
  - test_atcoder/abc253h.test.cpp
  - test_atcoder/arc105.test.cpp
  - test/library_checker/convolution/subset_convolution.test.cpp
  - test/library_checker/math/sps_exp.test.cpp
  - test/library_checker/math/composition_sps.test.cpp
  - test/library_checker/matrix/hafnian_of_matrix.test.cpp
  - test/yukicoder/2507.test.cpp
documentation_of: setfunc/ranked_zeta.hpp
layout: document
redirect_from:
- /library/setfunc/ranked_zeta.hpp
- /library/setfunc/ranked_zeta.hpp.html
title: setfunc/ranked_zeta.hpp
---
