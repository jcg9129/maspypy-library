---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/range_mex_query.hpp
    title: ds/range_mex_query.hpp
  - icon: ':x:'
    path: ds/sortable_segtree.hpp
    title: ds/sortable_segtree.hpp
  - icon: ':warning:'
    path: ds/uniqueproductquery.hpp
    title: ds/uniqueproductquery.hpp
  - icon: ':warning:'
    path: geo/manhattan_nns.hpp
    title: geo/manhattan_nns.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  - icon: ':question:'
    path: graph/treegroup.hpp
    title: graph/treegroup.hpp
  - icon: ':question:'
    path: graph/treemonoid.hpp
    title: graph/treemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A_mst.test.cpp
    title: test/aoj/GRL_2_A_mst.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
    title: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/sort_segtree.test.cpp
    title: test/library_checker/datastructure/sort_segtree.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/sort_segtree_1.test.cpp
    title: test/library_checker/datastructure/sort_segtree_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_mex.test.cpp
    title: test/mytest/range_mex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1036_seg_maxright_minleft.test.cpp
    title: test/yukicoder/1036_seg_maxright_minleft.test.cpp
  - icon: ':x:'
    path: test/yukicoder/426.test.cpp
    title: test/yukicoder/426.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/529_two_edge.test.cpp
    title: test/yukicoder/529_two_edge.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://codeforces.com/contest/1401/problem/F
  bundledCode: "#line 2 \"ds/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct SegTree\
    \ {\n  using X = typename Monoid::value_type;\n  using value_type = X;\n  vector<X>\
    \ dat;\n  int n, log, size;\n\n  SegTree() : SegTree(0) {}\n  SegTree(int n) :\
    \ SegTree(vector<X>(n, Monoid::unit())) {}\n  SegTree(vector<X> v) : n(v.size())\
    \ {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n \
    \   dat.assign(size << 1, Monoid::unit());\n    for (int i = 0; i < n; ++i) dat[size\
    \ + i] = v[i];\n    for (int i = size - 1; i >= 1; --i) update(i);\n  }\n\n  template\
    \ <typename F>\n  SegTree(int n, F f) : n(n) {\n    log = 1;\n    while ((1 <<\
    \ log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[size + i] = f(i);\n    for (int i = size\
    \ - 1; i >= 1; --i) update(i);\n  }\n\n  void reset() { fill(all(dat), Monoid::unit());\
    \ }\n\n  void set_all(const vector<X>& v) {\n    dat.assign(size << 1, Monoid::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[size + i] = v[i];\n    for (int i = size\
    \ - 1; i >= 1; --i) update(i);\n  }\n\n  X operator[](int i) { return dat[size\
    \ + i]; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i\
    \ + 1]); }\n\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i +=\
    \ size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const\
    \ X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(L\
    \ <= R);\n    assert(R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F& check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) {\n      \
    \      sm = Monoid::op(sm, dat[L]);\n            L++;\n          }\n        }\n\
    \        return L - size;\n      }\n      sm = Monoid::op(sm, dat[L]);\n     \
    \ L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F& check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R], sm);\n\
    \            R--;\n          }\n        }\n        return R + 1 - size;\n    \
    \  }\n      sm = Monoid::op(dat[R], sm);\n    } while ((R & -R) != R);\n    return\
    \ 0;\n  }\n\n  // \u30E2\u30CE\u30A4\u30C9\u304C\u53EF\u63DB\u306A\u3089\u3001\
    prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\u53EF\u80FD\n  // https://codeforces.com/contest/1401/problem/F\n\
    \  X Xor_prod(int l, int r, int xor_val) {\n    assert(Monoid::commute);\n   \
    \ X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if (l\
    \ >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n\n  void debug() { print(\"segtree\", dat); }\n};\n"
  code: "#pragma once\n\ntemplate <class Monoid>\nstruct SegTree {\n  using X = typename\
    \ Monoid::value_type;\n  using value_type = X;\n  vector<X> dat;\n  int n, log,\
    \ size;\n\n  SegTree() : SegTree(0) {}\n  SegTree(int n) : SegTree(vector<X>(n,\
    \ Monoid::unit())) {}\n  SegTree(vector<X> v) : n(v.size()) {\n    log = 1;\n\
    \    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, Monoid::unit());\n    for (int i = 0; i < n; ++i) dat[size + i] = v[i];\n\
    \    for (int i = size - 1; i >= 1; --i) update(i);\n  }\n\n  template <typename\
    \ F>\n  SegTree(int n, F f) : n(n) {\n    log = 1;\n    while ((1 << log) < n)\
    \ ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid::unit());\n \
    \   for (int i = 0; i < n; ++i) dat[size + i] = f(i);\n    for (int i = size -\
    \ 1; i >= 1; --i) update(i);\n  }\n\n  void reset() { fill(all(dat), Monoid::unit());\
    \ }\n\n  void set_all(const vector<X>& v) {\n    dat.assign(size << 1, Monoid::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[size + i] = v[i];\n    for (int i = size\
    \ - 1; i >= 1; --i) update(i);\n  }\n\n  X operator[](int i) { return dat[size\
    \ + i]; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i\
    \ + 1]); }\n\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i +=\
    \ size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const\
    \ X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(L\
    \ <= R);\n    assert(R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F& check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) {\n      \
    \      sm = Monoid::op(sm, dat[L]);\n            L++;\n          }\n        }\n\
    \        return L - size;\n      }\n      sm = Monoid::op(sm, dat[L]);\n     \
    \ L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F& check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R], sm);\n\
    \            R--;\n          }\n        }\n        return R + 1 - size;\n    \
    \  }\n      sm = Monoid::op(dat[R], sm);\n    } while ((R & -R) != R);\n    return\
    \ 0;\n  }\n\n  // \u30E2\u30CE\u30A4\u30C9\u304C\u53EF\u63DB\u306A\u3089\u3001\
    prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\u53EF\u80FD\n  // https://codeforces.com/contest/1401/problem/F\n\
    \  X Xor_prod(int l, int r, int xor_val) {\n    assert(Monoid::commute);\n   \
    \ X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if (l\
    \ >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n\n  void debug() { print(\"segtree\", dat); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree.hpp
  requiredBy:
  - ds/sortable_segtree.hpp
  - ds/uniqueproductquery.hpp
  - ds/range_mex_query.hpp
  - graph/treemonoid.hpp
  - graph/treegroup.hpp
  - graph/minimum_spanning_tree.hpp
  - geo/manhattan_nns.hpp
  timestamp: '2022-08-11 02:08:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL_2_A_mst.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
  - test/library_checker/datastructure/sort_segtree.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_group.test.cpp
  - test/library_checker/datastructure/sort_segtree_1.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - test/yukicoder/1036_seg_maxright_minleft.test.cpp
  - test/yukicoder/529_two_edge.test.cpp
  - test/yukicoder/426.test.cpp
  - test/mytest/range_mex.test.cpp
documentation_of: ds/segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree.hpp
- /library/ds/segtree.hpp.html
title: ds/segtree.hpp
---
