---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':question:'
    path: alg/monoid_min_idx.hpp
    title: alg/monoid_min_idx.hpp
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
    \ bool commute = true;\r\n};\r\n#line 1 \"alg/monoid_min_idx.hpp\"\ntemplate <typename\
    \ T, bool tie_is_left = true>\r\nstruct Monoid_Min_Idx {\r\n  using value_type\
    \ = pair<T, int>;\r\n  using X = value_type;\r\n  static constexpr bool is_small(const\
    \ X& x, const X& y) {\r\n    if (x.fi < y.fi) return true;\r\n    if (x.fi > y.fi)\
    \ return false;\r\n    return (tie_is_left ? (x.se < y.se) : (x.se >= y.se));\r\
    \n  }\r\n  static X op(X x, X y) { return (is_small(x, y) ? x : y); }\r\n  static\
    \ constexpr X unit() { return {numeric_limits<T>::max(), -1}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"alg/lazy_minidx_add.hpp\"\n\r\ntemplate\
    \ <typename E, bool tie_is_left = true>\r\nstruct Lazy_MinIdx_Add {\r\n  using\
    \ MX = Monoid_Min_Idx<E, tie_is_left>;\r\n  using MA = Group_Add<E>;\r\n  using\
    \ X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) {\r\n    if (x.fi == numeric_limits<E>::max()) return x;\r\n   \
    \ return {x.fi + a, x.se};\r\n  }\r\n};\r\n"
  code: "#include \"alg/group_add.hpp\"\r\n#include \"alg/monoid_min_idx.hpp\"\r\n\
    \r\ntemplate <typename E, bool tie_is_left = true>\r\nstruct Lazy_MinIdx_Add {\r\
    \n  using MX = Monoid_Min_Idx<E, tie_is_left>;\r\n  using MA = Group_Add<E>;\r\
    \n  using X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename\
    \ MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static constexpr\
    \ X act(const X &x, const A &a) {\r\n    if (x.fi == numeric_limits<E>::max())\
    \ return x;\r\n    return {x.fi + a, x.se};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/group_add.hpp
  - alg/monoid_min_idx.hpp
  isVerificationFile: false
  path: alg/lazy_minidx_add.hpp
  requiredBy: []
  timestamp: '2022-05-27 16:21:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy_minidx_add.hpp
layout: document
redirect_from:
- /library/alg/lazy_minidx_add.hpp
- /library/alg/lazy_minidx_add.hpp.html
title: alg/lazy_minidx_add.hpp
---
