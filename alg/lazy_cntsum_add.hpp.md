---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':question:'
    path: alg/group_cntsum.hpp
    title: alg/group_cntsum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1197.test.cpp
    title: test/yukicoder/1197.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/789_2.test.cpp
    title: test/yukicoder/789_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Group_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"alg/group_cntsum.hpp\"\
    \ntemplate <typename E = long long>\r\nstruct Group_CntSum {\r\n  using value_type\
    \ = pair<E, E>;\r\n  using X = value_type;\r\n  static constexpr X op(const X\
    \ &x, const X &y) {\r\n    return {x.fi + y.fi, x.se + y.se};\r\n  }\r\n  static\
    \ constexpr X inverse(const X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr\
    \ X unit() { return {0, 0}; }\r\n  static constexpr bool commute = true;\r\n};\r\
    \n#line 3 \"alg/lazy_cntsum_add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Lazy_CntSum_Add\
    \ {\r\n  using MX = Group_CntSum<E>;\r\n  using MA = Group_Add<E>;\r\n  using\
    \ X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) {\r\n    return {x.fi, x.se + x.fi * a};\r\n  }\r\n};\r\n"
  code: "#include \"alg/group_add.hpp\"\r\n#include \"alg/group_cntsum.hpp\"\r\n\r\
    \ntemplate <typename E>\r\nstruct Lazy_CntSum_Add {\r\n  using MX = Group_CntSum<E>;\r\
    \n  using MA = Group_Add<E>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    return {x.fi, x.se\
    \ + x.fi * a};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/group_add.hpp
  - alg/group_cntsum.hpp
  isVerificationFile: false
  path: alg/lazy_cntsum_add.hpp
  requiredBy: []
  timestamp: '2022-06-27 16:36:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/789_2.test.cpp
  - test/yukicoder/235.test.cpp
  - test/yukicoder/1197.test.cpp
  - test/aoj/GRL_5_E.test.cpp
documentation_of: alg/lazy_cntsum_add.hpp
layout: document
redirect_from:
- /library/alg/lazy_cntsum_add.hpp
- /library/alg/lazy_cntsum_add.hpp.html
title: alg/lazy_cntsum_add.hpp
---
