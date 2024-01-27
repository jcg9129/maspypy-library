---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: seq/inversion.hpp
    title: seq/inversion.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_2_A.test.cpp
    title: test/aoj/ALDS1_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_5.test.cpp
    title: test/aoj/ALDS1_5.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/static_range_inversions_mo_3.test.cpp
    title: test/library_checker/datastructure/static_range_inversions_mo_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1838.test.cpp
    title: test/yukicoder/1838.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/694.test.cpp
    title: test/yukicoder/694.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc190f.test.cpp
    title: test_atcoder/abc190f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ E = typename G::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree()\
    \ {}\n  FenwickTree(int n) { build(n); }\n  template <typename F>\n  FenwickTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m, G::unit());\n    total\
    \ = G::unit();\n  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int\
    \ i) -> E { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n    total = G::unit();\n\
    \    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int\
    \ j = i + (i & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j -\
    \ 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n  E prod_all() { return total;\
    \ }\n  E sum_all() { return total; }\n  E sum(int k) { return prefix_sum(k); }\n\
    \  E prod(int k) { return prefix_prod(k); }\n  E prefix_sum(int k) { return prefix_prod(k);\
    \ }\n  E prefix_prod(int k) {\n    chmin(k, n);\n    E ret = G::unit();\n    for\
    \ (; k > 0; k -= k & -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n  }\n\
    \  E sum(int L, int R) { return prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L,\
    \ 0), chmin(R, n);\n    if (L == 0) return prefix_prod(R);\n    assert(0 <= L\
    \ && L <= R && R <= n);\n    E pos = G::unit(), neg = G::unit();\n    while (L\
    \ < R) { pos = G::op(pos, dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg\
    \ = G::op(neg, dat[L - 1]), L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n\n  template <class\
    \ F>\n  int max_right(const F check) {\n    assert(check(G::unit()));\n    int\
    \ i = 0;\n    E s = G::unit();\n    int k = 1;\n    while (2 * k <= n) k *= 2;\n\
    \    while (k) {\n      if (i + k - 1 < len(dat)) {\n        E t = G::op(s, dat[i\
    \ + k - 1]);\n        if (check(t)) { i += k, s = t; }\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  // check(i, x)\n  template <class F>\n  int max_right_with_index(const\
    \ F check) {\n    assert(check(0, G::unit()));\n    int i = 0;\n    E s = G::unit();\n\
    \    int k = 1;\n    while (2 * k <= n) k *= 2;\n    while (k) {\n      if (i\
    \ + k - 1 < len(dat)) {\n        E t = G::op(s, dat[i + k - 1]);\n        if (check(i\
    \ + k, t)) { i += k, s = t; }\n      }\n      k >>= 1;\n    }\n    return i;\n\
    \  }\n\n  int kth(E k) {\n    return max_right([&k](E x) -> bool { return x <=\
    \ k; });\n  }\n};\n#line 2 \"ds/fenwicktree/fenwicktree_01.hpp\"\n\nstruct FenwickTree_01\
    \ {\n  int N, n;\n  vc<u64> dat;\n  FenwickTree<Monoid_Add<int>> bit;\n  FenwickTree_01()\
    \ {}\n  FenwickTree_01(int n) { build(n); }\n  template <typename F>\n  FenwickTree_01(int\
    \ n, F f) {\n    build(n, f);\n  }\n\n  void build(int m) {\n    N = m;\n    n\
    \ = ceil<int>(N + 1, 64);\n    dat.assign(n, u64(0));\n    bit.build(n);\n  }\n\
    \n  template <typename F>\n  void build(int m, F f) {\n    N = m;\n    n = ceil<int>(N\
    \ + 1, 64);\n    dat.assign(n, u64(0));\n    FOR(i, N) { dat[i / 64] |= u64(1)\
    \ << (i % 64); }\n    bit.build(n, [&](int i) -> int { return popcnt(dat[i]);\
    \ });\n  }\n\n  int sum_all() { return bit.sum_all(); }\n  int sum(int k) { return\
    \ prefix_sum(k); }\n  int prefix_sum(int k) {\n    int ans = bit.sum(k / 64);\n\
    \    ans += popcnt(dat[k / 64] & ((u64(1) << (k % 64)) - 1));\n    return ans;\n\
    \  }\n  int sum(int L, int R) {\n    if (L == 0) return prefix_sum(R);\n    int\
    \ ans = 0;\n    ans -= popcnt(dat[L / 64] & ((u64(1) << (L % 64)) - 1));\n   \
    \ ans += popcnt(dat[R / 64] & ((u64(1) << (R % 64)) - 1));\n    ans += bit.sum(L\
    \ / 64, R / 64);\n    return ans;\n  }\n\n  void add(int k, int x) {\n    if (x\
    \ == 1) add(k);\n    if (x == -1) remove(k);\n  }\n\n  void add(int k) {\n   \
    \ dat[k / 64] |= u64(1) << (k % 64);\n    bit.add(k / 64, 1);\n  }\n  void remove(int\
    \ k) {\n    dat[k / 64] &= ~(u64(1) << (k % 64));\n    bit.add(k / 64, -1);\n\
    \  }\n};\n"
  code: "#include \"ds/fenwicktree/fenwicktree.hpp\"\n\nstruct FenwickTree_01 {\n\
    \  int N, n;\n  vc<u64> dat;\n  FenwickTree<Monoid_Add<int>> bit;\n  FenwickTree_01()\
    \ {}\n  FenwickTree_01(int n) { build(n); }\n  template <typename F>\n  FenwickTree_01(int\
    \ n, F f) {\n    build(n, f);\n  }\n\n  void build(int m) {\n    N = m;\n    n\
    \ = ceil<int>(N + 1, 64);\n    dat.assign(n, u64(0));\n    bit.build(n);\n  }\n\
    \n  template <typename F>\n  void build(int m, F f) {\n    N = m;\n    n = ceil<int>(N\
    \ + 1, 64);\n    dat.assign(n, u64(0));\n    FOR(i, N) { dat[i / 64] |= u64(1)\
    \ << (i % 64); }\n    bit.build(n, [&](int i) -> int { return popcnt(dat[i]);\
    \ });\n  }\n\n  int sum_all() { return bit.sum_all(); }\n  int sum(int k) { return\
    \ prefix_sum(k); }\n  int prefix_sum(int k) {\n    int ans = bit.sum(k / 64);\n\
    \    ans += popcnt(dat[k / 64] & ((u64(1) << (k % 64)) - 1));\n    return ans;\n\
    \  }\n  int sum(int L, int R) {\n    if (L == 0) return prefix_sum(R);\n    int\
    \ ans = 0;\n    ans -= popcnt(dat[L / 64] & ((u64(1) << (L % 64)) - 1));\n   \
    \ ans += popcnt(dat[R / 64] & ((u64(1) << (R % 64)) - 1));\n    ans += bit.sum(L\
    \ / 64, R / 64);\n    return ans;\n  }\n\n  void add(int k, int x) {\n    if (x\
    \ == 1) add(k);\n    if (x == -1) remove(k);\n  }\n\n  void add(int k) {\n   \
    \ dat[k / 64] |= u64(1) << (k % 64);\n    bit.add(k / 64, 1);\n  }\n  void remove(int\
    \ k) {\n    dat[k / 64] &= ~(u64(1) << (k % 64));\n    bit.add(k / 64, -1);\n\
    \  }\n};"
  dependsOn:
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwicktree/fenwicktree_01.hpp
  requiredBy:
  - seq/inversion.hpp
  timestamp: '2024-01-26 14:07:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/694.test.cpp
  - test/yukicoder/1838.test.cpp
  - test/library_checker/datastructure/static_range_inversions_mo_3.test.cpp
  - test/aoj/ALDS1_2_A.test.cpp
  - test/aoj/ALDS1_5.test.cpp
  - test_atcoder/abc190f.test.cpp
documentation_of: ds/fenwicktree/fenwicktree_01.hpp
layout: document
redirect_from:
- /library/ds/fenwicktree/fenwicktree_01.hpp
- /library/ds/fenwicktree/fenwicktree_01.hpp.html
title: ds/fenwicktree/fenwicktree_01.hpp
---