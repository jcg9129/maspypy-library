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
  - icon: ':heavy_check_mark:'
    path: graph/functional.hpp
    title: graph/functional.hpp
  - icon: ':heavy_check_mark:'
    path: graph/maximum_antichain.hpp
    title: graph/maximum_antichain.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  - icon: ':warning:'
    path: graph/online_mst.hpp
    title: graph/online_mst.hpp
  - icon: ':heavy_check_mark:'
    path: graph/online_unionfind.hpp
    title: graph/online_unionfind.hpp
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
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
    path: test/mytest/tutte.test.cpp
    title: test/mytest/tutte.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/114.test.cpp
    title: test/yukicoder/114.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1170_2.test.cpp
    title: test/yukicoder/1170_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1211.test.cpp
    title: test/yukicoder/1211.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1242.test.cpp
    title: test/yukicoder/1242.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1392.test.cpp
    title: test/yukicoder/1392.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1451.test.cpp
    title: test/yukicoder/1451.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1479.test.cpp
    title: test/yukicoder/1479.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1600.test.cpp
    title: test/yukicoder/1600.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1744.test.cpp
    title: test/yukicoder/1744.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1745.test.cpp
    title: test/yukicoder/1745.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1911.test.cpp
    title: test/yukicoder/1911.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1983.test.cpp
    title: test/yukicoder/1983.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2122.test.cpp
    title: test/yukicoder/2122.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/590.test.cpp
    title: test/yukicoder/590.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind.hpp\"\n\nstruct UnionFind {\n  int n;\n  int\
    \ n_comp;\n  std::vector<int> size, par;\n  UnionFind(int n) : n(n), n_comp(n),\
    \ size(n, 1), par(n) {\n    std::iota(par.begin(), par.end(), 0);\n  }\n  int\
    \ find(int x) {\n    assert(0 <= x && x < n);\n    while (par[x] != x) { x = par[x]\
    \ = par[par[x]]; }\n    return x;\n  }\n\n  int operator[](int x) { return find(x);\
    \ }\n\n  bool merge(int x, int y) {\n    x = find(x);\n    y = find(y);\n    if\
    \ (x == y) { return false; }\n    n_comp--;\n    if (size[x] < size[y]) std::swap(x,\
    \ y);\n    size[x] += size[y];\n    size[y] = 0;\n    par[y] = x;\n    return\
    \ true;\n  }\n\n  std::vector<int> find_all() {\n    std::vector<int> A(n);\n\
    \    for (int i = 0; i < n; ++i) A[i] = find(i);\n    return A;\n  }\n\n  void\
    \ reset() {\n    n_comp = n;\n    size.assign(n, 1);\n    std::iota(par.begin(),\
    \ par.end(), 0);\n  }\n};\n"
  code: "#pragma once\n\nstruct UnionFind {\n  int n;\n  int n_comp;\n  std::vector<int>\
    \ size, par;\n  UnionFind(int n) : n(n), n_comp(n), size(n, 1), par(n) {\n   \
    \ std::iota(par.begin(), par.end(), 0);\n  }\n  int find(int x) {\n    assert(0\
    \ <= x && x < n);\n    while (par[x] != x) { x = par[x] = par[par[x]]; }\n   \
    \ return x;\n  }\n\n  int operator[](int x) { return find(x); }\n\n  bool merge(int\
    \ x, int y) {\n    x = find(x);\n    y = find(y);\n    if (x == y) { return false;\
    \ }\n    n_comp--;\n    if (size[x] < size[y]) std::swap(x, y);\n    size[x] +=\
    \ size[y];\n    size[y] = 0;\n    par[y] = x;\n    return true;\n  }\n\n  std::vector<int>\
    \ find_all() {\n    std::vector<int> A(n);\n    for (int i = 0; i < n; ++i) A[i]\
    \ = find(i);\n    return A;\n  }\n\n  void reset() {\n    n_comp = n;\n    size.assign(n,\
    \ 1);\n    std::iota(par.begin(), par.end(), 0);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind.hpp
  requiredBy:
  - flow/bipartite.hpp
  - graph/maximum_antichain.hpp
  - graph/minimum_spanning_tree.hpp
  - graph/online_unionfind.hpp
  - graph/online_mst.hpp
  - graph/dag_path_cover.hpp
  - graph/functional.hpp
  - graph/tree_of_unionfind.hpp
  - graph/check_bipartite.hpp
  - geo/manhattan_mst.hpp
  timestamp: '2022-10-24 17:15:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/tutte.test.cpp
  - test/yukicoder/590.test.cpp
  - test/yukicoder/114.test.cpp
  - test/yukicoder/1983.test.cpp
  - test/yukicoder/1451.test.cpp
  - test/yukicoder/1479.test.cpp
  - test/yukicoder/1744.test.cpp
  - test/yukicoder/2122.test.cpp
  - test/yukicoder/1392.test.cpp
  - test/yukicoder/1211.test.cpp
  - test/yukicoder/1242.test.cpp
  - test/yukicoder/1303.test.cpp
  - test/yukicoder/1745.test.cpp
  - test/yukicoder/1170_2.test.cpp
  - test/yukicoder/1911.test.cpp
  - test/yukicoder/1600.test.cpp
  - test/aoj/2251_2.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/2995.test.cpp
  - test/aoj/2251_1.test.cpp
  - test/library_checker/graph/manhattan_mst.test.cpp
  - test/library_checker/graph/bipartitematching.test.cpp
  - test/library_checker/datastructure/unionfind.test.cpp
  - test/atcoder/abc270_f.test.cpp
documentation_of: ds/unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind.hpp
- /library/ds/unionfind.hpp.html
title: ds/unionfind.hpp
---
