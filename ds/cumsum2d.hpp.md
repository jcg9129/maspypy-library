---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group/add.hpp
    title: alg/group/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1141.test.cpp
    title: test/yukicoder/1141.test.cpp
  - icon: ':x:'
    path: test/yukicoder/655.test.cpp
    title: test/yukicoder/655.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Group_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/cumsum2d.hpp\"\
    \n\r\ntemplate <typename Group>\r\nstruct Cumsum2D {\r\n  using X = typename Group::value_type;\r\
    \n  int H, W;\r\n  vc<vc<X>> dat;\r\n\r\n  Cumsum2D() {}\r\n  Cumsum2D(vc<vc<X>>\
    \ &A) {\r\n    assert(Group::commute);\r\n    build(A);\r\n  }\r\n\r\n  void build(vc<vc<X>>\
    \ &A) {\r\n    int H = len(A);\r\n    int W = (H == 0 ? 0 : len(A[0]));\r\n  \
    \  dat.assign(H + 1, vc<X>(W + 1, Group::unit()));\r\n    FOR(x, H) FOR(y, W)\
    \ dat[x + 1][y + 1] = A[x][y];\r\n    FOR(x, H + 1) FOR(y, W) dat[x][y + 1] =\
    \ Group::op(dat[x][y + 1], dat[x][y]);\r\n    FOR(x, H) FOR(y, W + 1) dat[x +\
    \ 1][y] = Group::op(dat[x + 1][y], dat[x][y]);\r\n  }\r\n\r\n  X sum(int x1, int\
    \ y1, int x2, int y2) {\r\n    X a = Group::op(dat[x1][y1], dat[x2][y2]);\r\n\
    \    X b = Group::op(dat[x2][y1], dat[x1][y2]);\r\n    return Group::op(a, Group::inverse(b));\r\
    \n  }\r\n};\n"
  code: "#include \"alg/group/add.hpp\"\r\n\r\ntemplate <typename Group>\r\nstruct\
    \ Cumsum2D {\r\n  using X = typename Group::value_type;\r\n  int H, W;\r\n  vc<vc<X>>\
    \ dat;\r\n\r\n  Cumsum2D() {}\r\n  Cumsum2D(vc<vc<X>> &A) {\r\n    assert(Group::commute);\r\
    \n    build(A);\r\n  }\r\n\r\n  void build(vc<vc<X>> &A) {\r\n    int H = len(A);\r\
    \n    int W = (H == 0 ? 0 : len(A[0]));\r\n    dat.assign(H + 1, vc<X>(W + 1,\
    \ Group::unit()));\r\n    FOR(x, H) FOR(y, W) dat[x + 1][y + 1] = A[x][y];\r\n\
    \    FOR(x, H + 1) FOR(y, W) dat[x][y + 1] = Group::op(dat[x][y + 1], dat[x][y]);\r\
    \n    FOR(x, H) FOR(y, W + 1) dat[x + 1][y] = Group::op(dat[x + 1][y], dat[x][y]);\r\
    \n  }\r\n\r\n  X sum(int x1, int y1, int x2, int y2) {\r\n    X a = Group::op(dat[x1][y1],\
    \ dat[x2][y2]);\r\n    X b = Group::op(dat[x2][y1], dat[x1][y2]);\r\n    return\
    \ Group::op(a, Group::inverse(b));\r\n  }\r\n};"
  dependsOn:
  - alg/group/add.hpp
  isVerificationFile: false
  path: ds/cumsum2d.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:40:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1141.test.cpp
  - test/yukicoder/655.test.cpp
documentation_of: ds/cumsum2d.hpp
layout: document
redirect_from:
- /library/ds/cumsum2d.hpp
- /library/ds/cumsum2d.hpp.html
title: ds/cumsum2d.hpp
---
