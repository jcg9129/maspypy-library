---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/min_min.test.cpp
    title: test/mytest/min_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Min {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr\
    \ X unit() { return infty<E>; }\r\n  static constexpr bool commute = true;\r\n\
    };\r\n#line 2 \"alg/acted_monoid/min_min.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct ActedMonoid_Min_Min {\r\n  using Monoid_X = Monoid_Min<E>;\r\n  using Monoid_A\
    \ = Monoid_Min<E>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A\
    \ = typename Monoid_A::value_type;\r\n  static constexpr X act(const X &x, const\
    \ A &a, const ll &size) {\r\n    return min(x, a);\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/min.hpp\"\r\n\r\ntemplate <typename E>\r\nstruct ActedMonoid_Min_Min\
    \ {\r\n  using Monoid_X = Monoid_Min<E>;\r\n  using Monoid_A = Monoid_Min<E>;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return\
    \ min(x, a);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: alg/acted_monoid/min_min.hpp
  requiredBy: []
  timestamp: '2023-02-02 02:12:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/min_min.test.cpp
documentation_of: alg/acted_monoid/min_min.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/min_min.hpp
- /library/alg/acted_monoid/min_min.hpp.html
title: alg/acted_monoid/min_min.hpp
---