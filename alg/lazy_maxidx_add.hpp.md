---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':x:'
    path: alg/monoid_max_idx.hpp
    title: alg/monoid_max_idx.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_add.hpp\"\ntemplate <class X>\r\nstruct Group_Add\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return\
    \ n * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"alg/monoid_max_idx.hpp\"\ntemplate <typename\
    \ T, bool tie_is_left = true>\r\nstruct Monoid_Max_Idx {\r\n  using value_type\
    \ = pair<T, int>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n\
    \    if (x.fi > y.fi) return x;\r\n    if (x.fi < y.fi) return y;\r\n    return\
    \ (tie_is_left ? x : y);\r\n  }\r\n  static constexpr X unit() { return {numeric_limits<T>::lowest(),\
    \ -1}; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/lazy_maxidx_add.hpp\"\
    \n\r\ntemplate <typename E, bool tie_is_left = true>\r\nstruct Lazy_MaxIdx_Add\
    \ {\r\n  using MX = Monoid_Max_Idx<E, tie_is_left>;\r\n  using MA = Group_Add<E>;\r\
    \n  using X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename\
    \ MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static constexpr\
    \ X act(const X &x, const A &a) {\r\n    if (x.fi == numeric_limits<E>::lowest())\
    \ return x;\r\n    return {x.fi + a, x.se};\r\n  }\r\n};\r\n"
  code: "#include \"alg/group_add.hpp\"\r\n#include \"alg/monoid_max_idx.hpp\"\r\n\
    \r\ntemplate <typename E, bool tie_is_left = true>\r\nstruct Lazy_MaxIdx_Add {\r\
    \n  using MX = Monoid_Max_Idx<E, tie_is_left>;\r\n  using MA = Group_Add<E>;\r\
    \n  using X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename\
    \ MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static constexpr\
    \ X act(const X &x, const A &a) {\r\n    if (x.fi == numeric_limits<E>::lowest())\
    \ return x;\r\n    return {x.fi + a, x.se};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/group_add.hpp
  - alg/monoid_max_idx.hpp
  isVerificationFile: false
  path: alg/lazy_maxidx_add.hpp
  requiredBy: []
  timestamp: '2022-05-16 18:02:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy_maxidx_add.hpp
layout: document
redirect_from:
- /library/alg/lazy_maxidx_add.hpp
- /library/alg/lazy_maxidx_add.hpp.html
title: alg/lazy_maxidx_add.hpp
---
