---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/184_xorbasis.test.cpp
    title: test/yukicoder/184_xorbasis.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_xor_basis.hpp\"\ntemplate <typename INT>\r\n\
    struct Monoid_XorBasis {\r\n  using value_type = vector<INT>;\r\n  using X = value_type;\r\
    \n  static bool add_element(X& x, INT v) {\r\n    for (auto&& e: x) {\r\n    \
    \  if (e == 0 || v == 0) break;\r\n      chmin(v, v ^ e);\r\n    }\r\n    if (v)\
    \ {\r\n      x.eb(v);\r\n      return true;\r\n    }\r\n    return false;\r\n\
    \  }\r\n\r\n  static X op(const X& x, const X& y) {\r\n    X z = x;\r\n    for\
    \ (auto v: y) { add_element(z, v); }\r\n    return z;\r\n  }\r\n\r\n  static bool\
    \ isin(INT v, const X& x){\r\n    for(auto&& w : x){\r\n      chmin(v, v ^ w);\r\
    \n    }\r\n    return v == 0;\r\n  }\r\n\r\n  // x ^ v \u306E\u6700\u5927\u5024\
    \r\n  static INT get_max(const X& x) {\r\n    INT res = 0;\r\n    for (auto&&\
    \ a: x) chmax(res, res ^ a);\r\n    return res;\r\n  }\r\n  static constexpr X\
    \ unit() { return X{}; };\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <typename INT>\r\nstruct Monoid_XorBasis {\r\n  using value_type\
    \ = vector<INT>;\r\n  using X = value_type;\r\n  static bool add_element(X& x,\
    \ INT v) {\r\n    for (auto&& e: x) {\r\n      if (e == 0 || v == 0) break;\r\n\
    \      chmin(v, v ^ e);\r\n    }\r\n    if (v) {\r\n      x.eb(v);\r\n      return\
    \ true;\r\n    }\r\n    return false;\r\n  }\r\n\r\n  static X op(const X& x,\
    \ const X& y) {\r\n    X z = x;\r\n    for (auto v: y) { add_element(z, v); }\r\
    \n    return z;\r\n  }\r\n\r\n  static bool isin(INT v, const X& x){\r\n    for(auto&&\
    \ w : x){\r\n      chmin(v, v ^ w);\r\n    }\r\n    return v == 0;\r\n  }\r\n\r\
    \n  // x ^ v \u306E\u6700\u5927\u5024\r\n  static INT get_max(const X& x) {\r\n\
    \    INT res = 0;\r\n    for (auto&& a: x) chmax(res, res ^ a);\r\n    return\
    \ res;\r\n  }\r\n  static constexpr X unit() { return X{}; };\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_xor_basis.hpp
  requiredBy: []
  timestamp: '2022-07-10 21:47:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/184_xorbasis.test.cpp
documentation_of: alg/monoid_xor_basis.hpp
layout: document
redirect_from:
- /library/alg/monoid_xor_basis.hpp
- /library/alg/monoid_xor_basis.hpp.html
title: alg/monoid_xor_basis.hpp
---
