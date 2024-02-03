---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_B.test.cpp
    title: test/aoj/DSL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1502.test.cpp
    title: test/yukicoder/1502.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2294.test.cpp
    title: test/yukicoder/2294.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc280f.test.cpp
    title: test_atcoder/abc280f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/unionfind/weighted_unionfind.hpp\"\ntemplate <typename\
    \ Group>\r\nstruct Weighted_UnionFind {\r\n  using E = typename Group::value_type;\r\
    \n  int N;\r\n  int n_comp;\r\n  vc<E> vals;\r\n  vc<int> par;\r\n  vc<int> size;\r\
    \n\r\n  Weighted_UnionFind(int N)\r\n      : N(N), n_comp(N), vals(N, Group::unit()),\
    \ size(N, 1) {\r\n    par.resize(N);\r\n    iota(all(par), 0);\r\n  }\r\n\r\n\
    \  // (root, root=0 \u3068\u3057\u305F\u3068\u304D\u306E val)\r\n  pair<int, E>\
    \ get(int v) {\r\n    E res = Group::unit();\r\n    while (v != par[v]) {\r\n\
    \      res = Group::op(vals[v], res);\r\n      res = Group::op(vals[par[v]], res);\r\
    \n      vals[v] = Group::op(vals[par[v]], vals[v]);\r\n      v = par[v] = par[par[v]];\r\
    \n    }\r\n    return {v, res};\r\n  }\r\n\r\n  pair<int, E> operator[](int v)\
    \ { return get(v); }\r\n\r\n  bool merge(int frm, int to, E x) {\r\n    auto [v1,\
    \ x1] = get(frm);\r\n    auto [v2, x2] = get(to);\r\n    if (v1 == v2) return\
    \ false;\r\n    if (size[v1] < size[v2]) {\r\n      swap(v1, v2);\r\n      swap(x1,\
    \ x2);\r\n      x = Group::inverse(x);\r\n    }\r\n    x = Group::op(x1, x);\r\
    \n    x = Group::op(x, Group::inverse(x2));\r\n    vals[v2] = x;\r\n    par[v2]\
    \ = v1;\r\n    size[v1] += size[v2];\r\n    --n_comp;\r\n    return true;\r\n\
    \  }\r\n};\n"
  code: "template <typename Group>\r\nstruct Weighted_UnionFind {\r\n  using E = typename\
    \ Group::value_type;\r\n  int N;\r\n  int n_comp;\r\n  vc<E> vals;\r\n  vc<int>\
    \ par;\r\n  vc<int> size;\r\n\r\n  Weighted_UnionFind(int N)\r\n      : N(N),\
    \ n_comp(N), vals(N, Group::unit()), size(N, 1) {\r\n    par.resize(N);\r\n  \
    \  iota(all(par), 0);\r\n  }\r\n\r\n  // (root, root=0 \u3068\u3057\u305F\u3068\
    \u304D\u306E val)\r\n  pair<int, E> get(int v) {\r\n    E res = Group::unit();\r\
    \n    while (v != par[v]) {\r\n      res = Group::op(vals[v], res);\r\n      res\
    \ = Group::op(vals[par[v]], res);\r\n      vals[v] = Group::op(vals[par[v]], vals[v]);\r\
    \n      v = par[v] = par[par[v]];\r\n    }\r\n    return {v, res};\r\n  }\r\n\r\
    \n  pair<int, E> operator[](int v) { return get(v); }\r\n\r\n  bool merge(int\
    \ frm, int to, E x) {\r\n    auto [v1, x1] = get(frm);\r\n    auto [v2, x2] =\
    \ get(to);\r\n    if (v1 == v2) return false;\r\n    if (size[v1] < size[v2])\
    \ {\r\n      swap(v1, v2);\r\n      swap(x1, x2);\r\n      x = Group::inverse(x);\r\
    \n    }\r\n    x = Group::op(x1, x);\r\n    x = Group::op(x, Group::inverse(x2));\r\
    \n    vals[v2] = x;\r\n    par[v2] = v1;\r\n    size[v1] += size[v2];\r\n    --n_comp;\r\
    \n    return true;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind/weighted_unionfind.hpp
  requiredBy: []
  timestamp: '2023-10-16 08:35:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc280f.test.cpp
  - test/yukicoder/2294.test.cpp
  - test/yukicoder/1502.test.cpp
  - test/aoj/DSL_1_B.test.cpp
documentation_of: ds/unionfind/weighted_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/weighted_unionfind.hpp
- /library/ds/unionfind/weighted_unionfind.hpp.html
title: ds/unionfind/weighted_unionfind.hpp
---
