---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/wavelet_matrix.test.cpp
    title: test/mytest/wavelet_matrix.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2065.test.cpp
    title: test/yukicoder/2065.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/static_range_product_group.hpp\"\n\ntemplate <typename\
    \ Monoid>\nstruct Static_Range_Product_Group {\n  using MX = Monoid;\n  using\
    \ X = Monoid::value_type;\n  int n;\n  vc<X> dat;\n  Static_Range_Product_Group()\
    \ {}\n  void build(vc<X>& A) {\n    n = len(A);\n    dat.assign(n + 1, MX::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], A[i]);\n  }\n  X\
    \ prod(int l, int r) { return MX::op(MX::inverse(dat[l]), dat[r]); }\n  X sum(int\
    \ l, int r) { return MX::op(MX::inverse(dat[l]), dat[r]); }\n};\n"
  code: "\ntemplate <typename Monoid>\nstruct Static_Range_Product_Group {\n  using\
    \ MX = Monoid;\n  using X = Monoid::value_type;\n  int n;\n  vc<X> dat;\n  Static_Range_Product_Group()\
    \ {}\n  void build(vc<X>& A) {\n    n = len(A);\n    dat.assign(n + 1, MX::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], A[i]);\n  }\n  X\
    \ prod(int l, int r) { return MX::op(MX::inverse(dat[l]), dat[r]); }\n  X sum(int\
    \ l, int r) { return MX::op(MX::inverse(dat[l]), dat[r]); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/static_range_product_group.hpp
  requiredBy: []
  timestamp: '2024-07-19 17:51:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/wavelet_matrix.test.cpp
  - test/yukicoder/2065.test.cpp
  - test/yukicoder/924.test.cpp
documentation_of: ds/static_range_product_group.hpp
layout: document
redirect_from:
- /library/ds/static_range_product_group.hpp
- /library/ds/static_range_product_group.hpp.html
title: ds/static_range_product_group.hpp
---