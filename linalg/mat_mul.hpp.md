---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linalg/det_A_plus_xB.hpp
    title: linalg/det_A_plus_xB.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/mat_pow.hpp
    title: linalg/mat_pow.hpp
  - icon: ':heavy_check_mark:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':heavy_check_mark:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_product.test.cpp
    title: test/library_checker/matrix/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/factorial_998.test.cpp
    title: test/mytest/factorial_998.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1750.test.cpp
    title: test/yukicoder/1750.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1810.test.cpp
    title: test/yukicoder/1810.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1907.test.cpp
    title: test/yukicoder/1907.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/426.test.cpp
    title: test/yukicoder/426.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/502_2.test.cpp
    title: test/yukicoder/502_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linalg/mat_mul.hpp\"\n\r\ntemplate <class T, is_modint_t<T>*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  const int mod = T::get_mod();\r\n  auto N = len(A), M = len(B), K = len(B[0]);\r\
    \n  vv(int, b, K, M);\r\n  FOR(i, M) FOR(j, K) b[j][i] = B[i][j].val;\r\n  vv(T,\
    \ C, N, K);\r\n  FOR(i, N) {\r\n    FOR(j, K) {\r\n      i128 sm = 0;\r\n    \
    \  FOR(m, M) { sm += ll(A[i][m].val) * b[j][m]; }\r\n      C[i][j] = sm % mod;\r\
    \n    }\r\n  }\r\n  return C;\r\n}\r\n\r\ntemplate <class T, is_not_modint_t<T>*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  FOR(n,\
    \ N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * B[m][k];\r\n  return C;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <class T, is_modint_t<T>* = nullptr>\r\nvc<vc<T>>\
    \ mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n  const int mod = T::get_mod();\r\
    \n  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(int, b, K, M);\r\n  FOR(i,\
    \ M) FOR(j, K) b[j][i] = B[i][j].val;\r\n  vv(T, C, N, K);\r\n  FOR(i, N) {\r\n\
    \    FOR(j, K) {\r\n      i128 sm = 0;\r\n      FOR(m, M) { sm += ll(A[i][m].val)\
    \ * b[j][m]; }\r\n      C[i][j] = sm % mod;\r\n    }\r\n  }\r\n  return C;\r\n\
    }\r\n\r\ntemplate <class T, is_not_modint_t<T>* = nullptr>\r\nvc<vc<T>> mat_mul(const\
    \ vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n  auto N = len(A), M = len(B), K = len(B[0]);\r\
    \n  vv(T, C, N, K);\r\n  FOR(n, N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * B[m][k];\r\
    \n  return C;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/mat_mul.hpp
  requiredBy:
  - seq/kth_term_of_p_recursive.hpp
  - linalg/det_A_plus_xB.hpp
  - linalg/mat_pow.hpp
  - poly/prefix_product_of_poly.hpp
  timestamp: '2022-08-19 01:23:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/matrix/matrix_product.test.cpp
  - test/yukicoder/1750.test.cpp
  - test/yukicoder/1810.test.cpp
  - test/yukicoder/502_2.test.cpp
  - test/yukicoder/1907.test.cpp
  - test/yukicoder/426.test.cpp
  - test/mytest/factorial_998.test.cpp
documentation_of: linalg/mat_mul.hpp
layout: document
redirect_from:
- /library/linalg/mat_mul.hpp
- /library/linalg/mat_mul.hpp.html
title: linalg/mat_mul.hpp
---
