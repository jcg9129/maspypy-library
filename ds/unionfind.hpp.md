---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: flow/bipartite.hpp
    title: flow/bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: geo/manhattan_mst.hpp
    title: geo/manhattan_mst.hpp
  - icon: ':question:'
    path: graph/check_bipartite.hpp
    title: graph/check_bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dag_path_cover.hpp
    title: graph/dag_path_cover.hpp
  - icon: ':x:'
    path: graph/functional.hpp
    title: graph/functional.hpp
  - icon: ':heavy_check_mark:'
    path: graph/maximum_antichain.hpp
    title: graph/maximum_antichain.hpp
  - icon: ':question:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  - icon: ':x:'
    path: graph/online_unionfind.hpp
    title: graph/online_unionfind.hpp
  - icon: ':x:'
    path: graph/tree_of_unionfind.hpp
    title: graph/tree_of_unionfind.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_1.test.cpp
    title: test/aoj/2251_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_2.test.cpp
    title: test/aoj/2251_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2995.test.cpp
    title: test/aoj/2995.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc270_f.test.cpp
    title: test/atcoder/abc270_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/unionfind.test.cpp
    title: test/library_checker/datastructure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/bipartitematching.test.cpp
    title: test/library_checker/graph/bipartitematching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/manhattan_mst.test.cpp
    title: test/library_checker/graph/manhattan_mst.test.cpp
  - icon: ':x:'
    path: test/yukicoder/114.test.cpp
    title: test/yukicoder/114.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1170_2.test.cpp
    title: test/yukicoder/1170_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1242.test.cpp
    title: test/yukicoder/1242.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1451.test.cpp
    title: test/yukicoder/1451.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1479.test.cpp
    title: test/yukicoder/1479.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind.hpp\"\n\nstruct UnionFind {\n  int n;\n  int\
    \ n_comp;\n  std::vector<int> size, par;\n  UnionFind(int n) : n(n), n_comp(n),\
    \ size(n, 1), par(n) {\n    std::iota(par.begin(), par.end(), 0);\n  }\n  int\
    \ find(int x) {\n    assert(0 <= x && x < n);\n    while (par[x] != x) {\n   \
    \   par[x] = par[par[x]];\n      x = par[x];\n    }\n    return x;\n  }\n\n  int\
    \ operator[](int x) { return find(x); }\n\n  bool merge(int x, int y) {\n    x\
    \ = find(x);\n    y = find(y);\n    if (x == y) { return false; }\n    n_comp--;\n\
    \    if (size[x] < size[y]) std::swap(x, y);\n    size[x] += size[y];\n    size[y]\
    \ = 0;\n    par[y] = x;\n    return true;\n  }\n\n  std::vector<int> find_all()\
    \ {\n    std::vector<int> A(n);\n    for (int i = 0; i < n; ++i) A[i] = find(i);\n\
    \    return A;\n  }\n\n  void reset() {\n    n_comp = n;\n    size.assign(n, 1);\n\
    \    std::iota(par.begin(), par.end(), 0);\n  }\n};\n"
  code: "#pragma once\n\nstruct UnionFind {\n  int n;\n  int n_comp;\n  std::vector<int>\
    \ size, par;\n  UnionFind(int n) : n(n), n_comp(n), size(n, 1), par(n) {\n   \
    \ std::iota(par.begin(), par.end(), 0);\n  }\n  int find(int x) {\n    assert(0\
    \ <= x && x < n);\n    while (par[x] != x) {\n      par[x] = par[par[x]];\n  \
    \    x = par[x];\n    }\n    return x;\n  }\n\n  int operator[](int x) { return\
    \ find(x); }\n\n  bool merge(int x, int y) {\n    x = find(x);\n    y = find(y);\n\
    \    if (x == y) { return false; }\n    n_comp--;\n    if (size[x] < size[y])\
    \ std::swap(x, y);\n    size[x] += size[y];\n    size[y] = 0;\n    par[y] = x;\n\
    \    return true;\n  }\n\n  std::vector<int> find_all() {\n    std::vector<int>\
    \ A(n);\n    for (int i = 0; i < n; ++i) A[i] = find(i);\n    return A;\n  }\n\
    \n  void reset() {\n    n_comp = n;\n    size.assign(n, 1);\n    std::iota(par.begin(),\
    \ par.end(), 0);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind.hpp
  requiredBy:
  - graph/minimum_spanning_tree.hpp
  - graph/online_unionfind.hpp
  - graph/tree_of_unionfind.hpp
  - graph/dag_path_cover.hpp
  - graph/check_bipartite.hpp
  - graph/functional.hpp
  - graph/maximum_antichain.hpp
  - flow/bipartite.hpp
  - geo/manhattan_mst.hpp
  timestamp: '2022-08-11 02:13:18+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1479.test.cpp
  - test/yukicoder/1242.test.cpp
  - test/yukicoder/1170_2.test.cpp
  - test/yukicoder/114.test.cpp
  - test/yukicoder/1451.test.cpp
  - test/library_checker/graph/manhattan_mst.test.cpp
  - test/library_checker/graph/bipartitematching.test.cpp
  - test/library_checker/datastructure/unionfind.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/2995.test.cpp
  - test/aoj/2251_1.test.cpp
  - test/aoj/2251_2.test.cpp
  - test/atcoder/abc270_f.test.cpp
documentation_of: ds/unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind.hpp
- /library/ds/unionfind.hpp.html
title: ds/unionfind.hpp
---
