---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/min_idx.hpp\"\ntemplate <typename T, bool tie_is_left\
    \ = true>\r\nstruct Monoid_Min_Idx {\r\n  using value_type = pair<T, int>;\r\n\
    \  using X = value_type;\r\n  static constexpr bool is_small(const X& x, const\
    \ X& y) {\r\n    if (x.fi < y.fi) return true;\r\n    if (x.fi > y.fi) return\
    \ false;\r\n    return (tie_is_left ? (x.se < y.se) : (x.se >= y.se));\r\n  }\r\
    \n  static X op(X x, X y) { return (is_small(x, y) ? x : y); }\r\n  static constexpr\
    \ X unit() { return {numeric_limits<T>::max(), -1}; }\r\n  static constexpr bool\
    \ commute = true;\r\n};\r\n"
  code: "template <typename T, bool tie_is_left = true>\r\nstruct Monoid_Min_Idx {\r\
    \n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\n  static constexpr\
    \ bool is_small(const X& x, const X& y) {\r\n    if (x.fi < y.fi) return true;\r\
    \n    if (x.fi > y.fi) return false;\r\n    return (tie_is_left ? (x.se < y.se)\
    \ : (x.se >= y.se));\r\n  }\r\n  static X op(X x, X y) { return (is_small(x, y)\
    \ ? x : y); }\r\n  static constexpr X unit() { return {numeric_limits<T>::max(),\
    \ -1}; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/min_idx.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/min_idx.hpp
layout: document
redirect_from:
- /library/alg/monoid/min_idx.hpp
- /library/alg/monoid/min_idx.hpp.html
title: alg/monoid/min_idx.hpp
---
