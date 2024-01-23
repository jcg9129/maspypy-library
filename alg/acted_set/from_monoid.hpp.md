---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':heavy_check_mark:'
    path: nt/discrete_log.hpp
    title: nt/discrete_log.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc222g.test.cpp
    title: test_atcoder/abc222g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc270_g.test.cpp
    title: test_atcoder/abc270_g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/acted_set/from_monoid.hpp\"\ntemplate <typename Monoid>\n\
    struct ActedSet_From_Monoid {\n  using Monoid_A = Monoid;\n  using A = typename\
    \ Monoid::value_type;\n  using S = A;\n  static S act(const S &x, const A &g)\
    \ { return Monoid::op(x, g); }\n};\n"
  code: "template <typename Monoid>\nstruct ActedSet_From_Monoid {\n  using Monoid_A\
    \ = Monoid;\n  using A = typename Monoid::value_type;\n  using S = A;\n  static\
    \ S act(const S &x, const A &g) { return Monoid::op(x, g); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/acted_set/from_monoid.hpp
  requiredBy:
  - mod/mod_log.hpp
  - nt/discrete_log.hpp
  timestamp: '2022-11-28 21:09:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test/yukicoder/1339.test.cpp
  - test_atcoder/abc270_g.test.cpp
  - test_atcoder/abc222g.test.cpp
documentation_of: alg/acted_set/from_monoid.hpp
layout: document
redirect_from:
- /library/alg/acted_set/from_monoid.hpp
- /library/alg/acted_set/from_monoid.hpp.html
title: alg/acted_set/from_monoid.hpp
---