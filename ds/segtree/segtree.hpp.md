---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: ds/offline_query/range_mex_query.hpp
    title: ds/offline_query/range_mex_query.hpp
  - icon: ':x:'
    path: ds/offline_query/uniqueproductquery.hpp
    title: ds/offline_query/uniqueproductquery.hpp
  - icon: ':question:'
    path: ds/segtree/range_assignment_segtree.hpp
    title: ds/segtree/range_assignment_segtree.hpp
  - icon: ':question:'
    path: ds/segtree/sortable_segtree.hpp
    title: ds/segtree/sortable_segtree.hpp
  - icon: ':x:'
    path: geo/manhattan_nns.hpp
    title: geo/manhattan_nns.hpp
  - icon: ':question:'
    path: graph/ds/tree_monoid.hpp
    title: graph/ds/tree_monoid.hpp
  - icon: ':question:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_3_B.test.cpp
    title: test/aoj/ITP2_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
    title: test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/predecessor_problem_3.test.cpp
    title: test/library_checker/datastructure/predecessor_problem_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_set_range_composite.test.cpp
    title: test/library_checker/datastructure/range_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/sort_segtree.test.cpp
    title: test/library_checker/datastructure/sort_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/sort_segtree_1.test.cpp
    title: test/library_checker/datastructure/sort_segtree_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/mst.test.cpp
    title: test/library_checker/tree/mst.test.cpp
  - icon: ':x:'
    path: test/mytest/manhattan_nns.test.cpp
    title: test/mytest/manhattan_nns.test.cpp
  - icon: ':x:'
    path: test/mytest/mo_on_tree.test.cpp
    title: test/mytest/mo_on_tree.test.cpp
  - icon: ':x:'
    path: test/mytest/range_assign.test.cpp
    title: test/mytest/range_assign.test.cpp
  - icon: ':x:'
    path: test/mytest/range_mex.test.cpp
    title: test/mytest/range_mex.test.cpp
  - icon: ':x:'
    path: test/mytest/segtree_xor_prod.test.cpp
    title: test/mytest/segtree_xor_prod.test.cpp
  - icon: ':x:'
    path: test/mytest/suffix_tree.test.cpp
    title: test/mytest/suffix_tree.test.cpp
  - icon: ':x:'
    path: test/mytest/wavelet_matrix.test.cpp
    title: test/mytest/wavelet_matrix.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1036_2.test.cpp
    title: test/yukicoder/1036_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1212.test.cpp
    title: test/yukicoder/1212.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1435.test.cpp
    title: test/yukicoder/1435.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1549.test.cpp
    title: test/yukicoder/1549.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1625_2.test.cpp
    title: test/yukicoder/1625_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2361.test.cpp
    title: test/yukicoder/2361.test.cpp
  - icon: ':x:'
    path: test/yukicoder/426.test.cpp
    title: test/yukicoder/426.test.cpp
  - icon: ':x:'
    path: test/yukicoder/529.test.cpp
    title: test/yukicoder/529.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc174f.test.cpp
    title: test_atcoder/abc174f.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc237g.test.cpp
    title: test_atcoder/abc237g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc240ex.test.cpp
    title: test_atcoder/abc240ex.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc270_f.test.cpp
    title: test_atcoder/abc270_f.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc301h.test.cpp
    title: test_atcoder/abc301h.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct\
    \ SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) { return dat[size + i]; }\n  vc<X> get_all() { return {dat.begin()\
    \ + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int\
    \ i, const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n"
  code: "#pragma once\n\ntemplate <class Monoid>\nstruct SegTree {\n  using MX = Monoid;\n\
    \  using X = typename MX::value_type;\n  using value_type = X;\n  vc<X> dat;\n\
    \  int n, log, size;\n\n  SegTree() {}\n  SegTree(int n) { build(n); }\n  template\
    \ <typename F>\n  SegTree(int n, F f) {\n    build(n, f);\n  }\n  SegTree(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    dat.assign(size << 1, MX::unit());\n    FOR(i, n) dat[size\
    \ + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n  X get(int i) { return\
    \ dat[size + i]; }\n  vc<X> get_all() { return {dat.begin() + size, dat.begin()\
    \ + size + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2\
    \ * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i\
    \ += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i,\
    \ const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/segtree.hpp
  requiredBy:
  - ds/offline_query/uniqueproductquery.hpp
  - ds/offline_query/range_mex_query.hpp
  - ds/segtree/sortable_segtree.hpp
  - ds/segtree/range_assignment_segtree.hpp
  - geo/manhattan_nns.hpp
  - graph/ds/tree_monoid.hpp
  - graph/minimum_spanning_tree.hpp
  timestamp: '2023-04-14 22:06:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/sort_segtree_1.test.cpp
  - test/library_checker/datastructure/range_set_range_composite.test.cpp
  - test/library_checker/datastructure/predecessor_problem_3.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/point_set_range_composite_monoid.test.cpp
  - test/library_checker/datastructure/sort_segtree.test.cpp
  - test/library_checker/tree/mst.test.cpp
  - test/mytest/range_mex.test.cpp
  - test/mytest/mo_on_tree.test.cpp
  - test/mytest/suffix_tree.test.cpp
  - test/mytest/manhattan_nns.test.cpp
  - test/mytest/wavelet_matrix.test.cpp
  - test/mytest/range_assign.test.cpp
  - test/mytest/segtree_xor_prod.test.cpp
  - test/yukicoder/1625_2.test.cpp
  - test/yukicoder/1036_2.test.cpp
  - test/yukicoder/1212.test.cpp
  - test/yukicoder/426.test.cpp
  - test/yukicoder/2361.test.cpp
  - test/yukicoder/1435.test.cpp
  - test/yukicoder/1549.test.cpp
  - test/yukicoder/529.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/ITP2_3_B.test.cpp
  - test_atcoder/abc301h.test.cpp
  - test_atcoder/abc174f.test.cpp
  - test_atcoder/abc237g.test.cpp
  - test_atcoder/abc270_f.test.cpp
  - test_atcoder/abc240ex.test.cpp
documentation_of: ds/segtree/segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/segtree.hpp
- /library/ds/segtree/segtree.hpp.html
title: ds/segtree/segtree.hpp
---
