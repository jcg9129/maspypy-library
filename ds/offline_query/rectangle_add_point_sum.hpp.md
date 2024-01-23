---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/rect_add_pt_sum.test.cpp
    title: test/mytest/rect_add_pt_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2338.test.cpp
    title: test/yukicoder/2338.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2491.test.cpp
    title: test/yukicoder/2491.test.cpp
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
    \ k; });\n  }\n};\n#line 2 \"ds/offline_query/rectangle_add_point_sum.hpp\"\n\n\
    template <typename AbelGroup, typename XY, bool SMALL_X = false>\nstruct Rectangle_Add_Point_Sum\
    \ {\n  using G = typename AbelGroup::value_type;\n  vector<tuple<XY, XY, XY, G>>\
    \ rect;\n  vector<tuple<int, XY, XY>> point;\n\n  Rectangle_Add_Point_Sum() {}\n\
    \n  void add_query(XY x1, XY x2, XY y1, XY y2, G g) {\n    rect.eb(y1, x1, x2,\
    \ g), rect.eb(y2, x2, x1, g);\n  }\n  void sum_query(XY x, XY y) { point.eb(len(point),\
    \ x, y); }\n\n  vector<G> calc() {\n    int N = rect.size(), Q = point.size();\n\
    \    if (N == 0 || Q == 0) return vector<G>(Q, AbelGroup::unit());\n    // X \u65B9\
    \u5411\u306E\u5EA7\u5727\n    int NX = 0;\n    if (!SMALL_X) {\n      sort(all(point),\n\
    \           [&](auto &x, auto &y) -> bool { return get<1>(x) < get<1>(y); });\n\
    \      vc<XY> keyX;\n      keyX.reserve(Q);\n      for (auto &&[i, a, b]: point)\
    \ {\n        if (len(keyX) == 0 || keyX.back() != a) { keyX.eb(a); }\n       \
    \ a = len(keyX) - 1;\n      }\n      for (auto &&[y, x1, x2, g]: rect) x1 = LB(keyX,\
    \ x1), x2 = LB(keyX, x2);\n      NX = len(keyX);\n    }\n    if (SMALL_X) {\n\
    \      XY mx = infty<XY>;\n      for (auto &&[i, x, y]: point) chmin(mx, x);\n\
    \      for (auto &&[i, x, y]: point) x -= mx, chmax(NX, x + 1);\n      for (auto\
    \ &&[y, x1, x2, g]: rect) {\n        x1 -= mx, x2 -= mx;\n        x1 = max(0,\
    \ min<int>(x1, NX)), x2 = max(0, min<int>(x2, NX));\n      }\n    }\n\n    sort(all(point),\n\
    \         [&](auto &x, auto &y) -> bool { return get<2>(x) < get<2>(y); });\n\
    \    sort(all(rect),\n         [&](auto &x, auto &y) -> bool { return get<0>(x)\
    \ < get<0>(y); });\n    FenwickTree<AbelGroup> bit(NX);\n    vc<G> res(Q, AbelGroup::unit());\n\
    \    int j = 0;\n    FOR(i, Q) {\n      auto [q, x, y] = point[i];\n      while\
    \ (j < N && get<0>(rect[j]) <= y) {\n        auto [yy, x1, x2, g] = rect[j++];\n\
    \        bit.add(x1, g), bit.add(x2, AbelGroup::inverse(g));\n      }\n      res[q]\
    \ = bit.sum(x + 1);\n    }\n    return res;\n  }\n};\n"
  code: "#include \"ds/fenwicktree/fenwicktree.hpp\"\n\ntemplate <typename AbelGroup,\
    \ typename XY, bool SMALL_X = false>\nstruct Rectangle_Add_Point_Sum {\n  using\
    \ G = typename AbelGroup::value_type;\n  vector<tuple<XY, XY, XY, G>> rect;\n\
    \  vector<tuple<int, XY, XY>> point;\n\n  Rectangle_Add_Point_Sum() {}\n\n  void\
    \ add_query(XY x1, XY x2, XY y1, XY y2, G g) {\n    rect.eb(y1, x1, x2, g), rect.eb(y2,\
    \ x2, x1, g);\n  }\n  void sum_query(XY x, XY y) { point.eb(len(point), x, y);\
    \ }\n\n  vector<G> calc() {\n    int N = rect.size(), Q = point.size();\n    if\
    \ (N == 0 || Q == 0) return vector<G>(Q, AbelGroup::unit());\n    // X \u65B9\u5411\
    \u306E\u5EA7\u5727\n    int NX = 0;\n    if (!SMALL_X) {\n      sort(all(point),\n\
    \           [&](auto &x, auto &y) -> bool { return get<1>(x) < get<1>(y); });\n\
    \      vc<XY> keyX;\n      keyX.reserve(Q);\n      for (auto &&[i, a, b]: point)\
    \ {\n        if (len(keyX) == 0 || keyX.back() != a) { keyX.eb(a); }\n       \
    \ a = len(keyX) - 1;\n      }\n      for (auto &&[y, x1, x2, g]: rect) x1 = LB(keyX,\
    \ x1), x2 = LB(keyX, x2);\n      NX = len(keyX);\n    }\n    if (SMALL_X) {\n\
    \      XY mx = infty<XY>;\n      for (auto &&[i, x, y]: point) chmin(mx, x);\n\
    \      for (auto &&[i, x, y]: point) x -= mx, chmax(NX, x + 1);\n      for (auto\
    \ &&[y, x1, x2, g]: rect) {\n        x1 -= mx, x2 -= mx;\n        x1 = max(0,\
    \ min<int>(x1, NX)), x2 = max(0, min<int>(x2, NX));\n      }\n    }\n\n    sort(all(point),\n\
    \         [&](auto &x, auto &y) -> bool { return get<2>(x) < get<2>(y); });\n\
    \    sort(all(rect),\n         [&](auto &x, auto &y) -> bool { return get<0>(x)\
    \ < get<0>(y); });\n    FenwickTree<AbelGroup> bit(NX);\n    vc<G> res(Q, AbelGroup::unit());\n\
    \    int j = 0;\n    FOR(i, Q) {\n      auto [q, x, y] = point[i];\n      while\
    \ (j < N && get<0>(rect[j]) <= y) {\n        auto [yy, x1, x2, g] = rect[j++];\n\
    \        bit.add(x1, g), bit.add(x2, AbelGroup::inverse(g));\n      }\n      res[q]\
    \ = bit.sum(x + 1);\n    }\n    return res;\n  }\n};"
  dependsOn:
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/offline_query/rectangle_add_point_sum.hpp
  requiredBy: []
  timestamp: '2024-01-23 05:58:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/rect_add_pt_sum.test.cpp
  - test/yukicoder/2338.test.cpp
  - test/yukicoder/2491.test.cpp
documentation_of: ds/offline_query/rectangle_add_point_sum.hpp
layout: document
redirect_from:
- /library/ds/offline_query/rectangle_add_point_sum.hpp
- /library/ds/offline_query/rectangle_add_point_sum.hpp.html
title: ds/offline_query/rectangle_add_point_sum.hpp
---