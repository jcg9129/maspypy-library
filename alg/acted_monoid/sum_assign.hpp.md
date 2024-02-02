---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':x:'
    path: test/mytest/range_assign.test.cpp
    title: test/mytest/range_assign.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2292.test.cpp
    title: test/yukicoder/2292.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc256ex.test.cpp
    title: test_atcoder/abc256ex.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc256ex2.test.cpp
    title: test_atcoder/abc256ex2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/assign.hpp\"\
    \n\r\ntemplate <typename X, int none_val>\r\nstruct Monoid_Assign {\r\n  using\
    \ value_type = X;\r\n  static X op(X x, X y) { return (y == X(none_val) ? x :\
    \ y); }\r\n  static constexpr X unit() { return X(none_val); }\r\n  static constexpr\
    \ bool commute = false;\r\n};\r\n#line 3 \"alg/acted_monoid/sum_assign.hpp\"\n\
    \r\ntemplate <typename E, E none_val>\r\nstruct ActedMonoid_Sum_Assign {\r\n \
    \ using Monoid_X = Monoid_Add<E>;\r\n  using Monoid_A = Monoid_Assign<E, none_val>;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a, const ll &size) {\r\n    if\
    \ (a == Monoid_A::unit()) return x;\r\n    return a * E(size);\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid/assign.hpp\"\r\n\
    \r\ntemplate <typename E, E none_val>\r\nstruct ActedMonoid_Sum_Assign {\r\n \
    \ using Monoid_X = Monoid_Add<E>;\r\n  using Monoid_A = Monoid_Assign<E, none_val>;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a, const ll &size) {\r\n    if\
    \ (a == Monoid_A::unit()) return x;\r\n    return a * E(size);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/assign.hpp
  isVerificationFile: false
  path: alg/acted_monoid/sum_assign.hpp
  requiredBy: []
  timestamp: '2024-01-23 05:58:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc256ex.test.cpp
  - test_atcoder/abc256ex2.test.cpp
  - test/yukicoder/2292.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/mytest/range_assign.test.cpp
documentation_of: alg/acted_monoid/sum_assign.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/sum_assign.hpp
- /library/alg/acted_monoid/sum_assign.hpp.html
title: alg/acted_monoid/sum_assign.hpp
---