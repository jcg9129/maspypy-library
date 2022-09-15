---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/statictreemonoid.hpp
    title: graph/statictreemonoid.hpp
  - icon: ':warning:'
    path: string/sort_all_substring.hpp
    title: string/sort_all_substring.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffixarray.hpp
    title: string/suffixarray.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_sparse.test.cpp
    title: test/library_checker/datastructure/staticrmq_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/number_of_substrings.test.cpp
    title: test/library_checker/string/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/suffix_array.test.cpp
    title: test/library_checker/string/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/suffix_array_vec.test.cpp
    title: test/library_checker/string/suffix_array_vec.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/suffix_tree.test.cpp
    title: test/mytest/suffix_tree.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2005.test.cpp
    title: test/yukicoder/2005.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/disjointsparse.hpp\"\n\r\ntemplate <class Monoid>\r\n\
    struct DisjointSparse {\r\n  using X = typename Monoid::value_type;\r\n  using\
    \ value_type = X;\r\n  int n, log;\r\n  vc<vc<X>> dat;\r\n\r\n  DisjointSparse()\
    \ {}\r\n  DisjointSparse(vc<X>& A) { build(A); }\r\n\r\n  template <typename F>\r\
    \n  DisjointSparse(int n, F f) {\r\n    vc<X> A(n);\r\n    FOR(i, n) A[i] = f(i);\r\
    \n    build(A);\r\n  }\r\n\r\n  void build(vc<X>& A) {\r\n    n = len(A);\r\n\
    \    log = 1;\r\n    while ((1 << log) < n) ++log;\r\n    dat.assign(log, A);\r\
    \n\r\n    FOR(i, log) {\r\n      auto& v = dat[i];\r\n      int b = 1 << i;\r\n\
    \      for (int m = b; m <= n; m += 2 * b) {\r\n        int L = m - b, R = min(n,\
    \ m + b);\r\n        FOR3_R(j, L + 1, m) v[j - 1] = Monoid::op(v[j - 1], v[j]);\r\
    \n        FOR3(j, m, R - 1) v[j + 1] = Monoid::op(v[j], v[j + 1]);\r\n      }\r\
    \n    }\r\n  }\r\n\r\n  X prod(int L, int R) {\r\n    if (L == R) return Monoid::unit();\r\
    \n    --R;\r\n    if (L == R) return dat[0][L];\r\n    int k = 31 - __builtin_clz(L\
    \ ^ R);\r\n    return Monoid::op(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  template\
    \ <class F>\r\n  int max_right(const F& check, int L) {\r\n    assert(0 <= L &&\
    \ L <= n && check(Monoid::unit()));\r\n    if (L == n) return n;\r\n    int ok\
    \ = L, ng = n + 1;\r\n    while (ok + 1 < ng) {\r\n      int k = (ok + ng) / 2;\r\
    \n      if (check(prod(L, k))) {\r\n        ok = k;\r\n      } else {\r\n    \
    \    ng = k;\r\n      }\r\n    }\r\n    return ok;\r\n  }\r\n\r\n  template <class\
    \ F>\r\n  int min_left(const F& check, int R) {\r\n    assert(0 <= R && R <= n\
    \ && check(Monoid::unit()));\r\n    if (R == 0) return 0;\r\n    int ok = R, ng\
    \ = -1;\r\n    while (ng + 1 < ok) {\r\n      int k = (ok + ng) / 2;\r\n     \
    \ if (check(prod(k, R))) {\r\n        ok = k;\r\n      } else {\r\n        ng\
    \ = k;\r\n      }\r\n    }\r\n    return ok;\r\n  }\r\n\r\n  void debug() {\r\n\
    \    print(\"disjoint sparse table\");\r\n    FOR(i, log) print(dat[i]);\r\n \
    \ }\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class Monoid>\r\nstruct DisjointSparse {\r\n\
    \  using X = typename Monoid::value_type;\r\n  using value_type = X;\r\n  int\
    \ n, log;\r\n  vc<vc<X>> dat;\r\n\r\n  DisjointSparse() {}\r\n  DisjointSparse(vc<X>&\
    \ A) { build(A); }\r\n\r\n  template <typename F>\r\n  DisjointSparse(int n, F\
    \ f) {\r\n    vc<X> A(n);\r\n    FOR(i, n) A[i] = f(i);\r\n    build(A);\r\n \
    \ }\r\n\r\n  void build(vc<X>& A) {\r\n    n = len(A);\r\n    log = 1;\r\n   \
    \ while ((1 << log) < n) ++log;\r\n    dat.assign(log, A);\r\n\r\n    FOR(i, log)\
    \ {\r\n      auto& v = dat[i];\r\n      int b = 1 << i;\r\n      for (int m =\
    \ b; m <= n; m += 2 * b) {\r\n        int L = m - b, R = min(n, m + b);\r\n  \
    \      FOR3_R(j, L + 1, m) v[j - 1] = Monoid::op(v[j - 1], v[j]);\r\n        FOR3(j,\
    \ m, R - 1) v[j + 1] = Monoid::op(v[j], v[j + 1]);\r\n      }\r\n    }\r\n  }\r\
    \n\r\n  X prod(int L, int R) {\r\n    if (L == R) return Monoid::unit();\r\n \
    \   --R;\r\n    if (L == R) return dat[0][L];\r\n    int k = 31 - __builtin_clz(L\
    \ ^ R);\r\n    return Monoid::op(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  template\
    \ <class F>\r\n  int max_right(const F& check, int L) {\r\n    assert(0 <= L &&\
    \ L <= n && check(Monoid::unit()));\r\n    if (L == n) return n;\r\n    int ok\
    \ = L, ng = n + 1;\r\n    while (ok + 1 < ng) {\r\n      int k = (ok + ng) / 2;\r\
    \n      if (check(prod(L, k))) {\r\n        ok = k;\r\n      } else {\r\n    \
    \    ng = k;\r\n      }\r\n    }\r\n    return ok;\r\n  }\r\n\r\n  template <class\
    \ F>\r\n  int min_left(const F& check, int R) {\r\n    assert(0 <= R && R <= n\
    \ && check(Monoid::unit()));\r\n    if (R == 0) return 0;\r\n    int ok = R, ng\
    \ = -1;\r\n    while (ng + 1 < ok) {\r\n      int k = (ok + ng) / 2;\r\n     \
    \ if (check(prod(k, R))) {\r\n        ok = k;\r\n      } else {\r\n        ng\
    \ = k;\r\n      }\r\n    }\r\n    return ok;\r\n  }\r\n\r\n  void debug() {\r\n\
    \    print(\"disjoint sparse table\");\r\n    FOR(i, log) print(dat[i]);\r\n \
    \ }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/disjointsparse.hpp
  requiredBy:
  - graph/statictreemonoid.hpp
  - string/sort_all_substring.hpp
  - string/suffix_tree.hpp
  - string/suffixarray.hpp
  timestamp: '2022-08-18 20:33:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/2005.test.cpp
  - test/mytest/suffix_tree.test.cpp
  - test/library_checker/string/suffix_array_vec.test.cpp
  - test/library_checker/string/suffix_array.test.cpp
  - test/library_checker/string/number_of_substrings.test.cpp
  - test/library_checker/datastructure/staticrmq_sparse.test.cpp
documentation_of: ds/disjointsparse.hpp
layout: document
redirect_from:
- /library/ds/disjointsparse.hpp
- /library/ds/disjointsparse.hpp.html
title: ds/disjointsparse.hpp
---
