---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/line_add_get_min_lichao_2.test.cpp
    title: test/library_checker/datastructure/line_add_get_min_lichao_2.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/segment_add_get_min_2.test.cpp
    title: test/library_checker/datastructure/segment_add_get_min_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/lichao.hpp\"\n// \u8A55\u4FA1\u70B9\u306F ll\u3001\
    \u95A2\u6570\u306E\u5024\u306F T \u306B\u306A\u3063\u3066\u3044\u308B\n// evaluate\
    \ \u3092\u66F8\u304D\u5909\u3048\u308B\u3068\u3001totally monotone \u306A\u95A2\
    \u6570\u7FA4\u306B\u3082\u4F7F\u3048\u308B\ntemplate <typename T, bool COMPRESS,\
    \ bool MINIMIZE>\nstruct LiChao_Tree {\n  using FUNC = pair<T, T>;\n  vc<FUNC>\
    \ funcs;\n\n  static inline T evaluate(FUNC& f, ll x) { return f.fi * x + f.se;\
    \ }\n\n  vc<ll> X;\n  ll lo, hi;\n  vc<int> FID;\n  int n, log, size;\n\n  inline\
    \ int get_idx(ll x) {\n    if constexpr (COMPRESS) { return LB(X, x); }\n    assert(lo\
    \ <= x && x < hi);\n    return x - lo;\n  }\n\n  template <typename XY>\n  LiChao_Tree(const\
    \ vc<XY>& pts) {\n    static_assert(COMPRESS);\n    for (auto&& x: pts) X.eb(x);\n\
    \    UNIQUE(X);\n    n = len(X), log = 1;\n    while ((1 << log) < n) ++log;\n\
    \    size = 1 << log;\n    FID.assign(size << 1, -1);\n  }\n\n  LiChao_Tree(ll\
    \ lo, ll hi) : lo(lo), hi(hi) {\n    static_assert(!COMPRESS);\n    n = hi - lo,\
    \ log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    FID.assign(size\
    \ << 1, -1);\n  }\n\n  void add_line(FUNC f) {\n    int fid = len(funcs);\n  \
    \  funcs.eb(f);\n    return add_line_at(1, fid);\n  }\n  void add_segment(ll xl,\
    \ ll xr, FUNC f) {\n    int fid = len(funcs);\n    funcs.eb(f);\n    xl = get_idx(xl),\
    \ xr = get_idx(xr);\n    xl += size, xr += size;\n    while (xl < xr) {\n    \
    \  if (xl & 1) add_line_at(xl++, fid);\n      if (xr & 1) add_line_at(--xr, fid);\n\
    \      xl >>= 1, xr >>= 1;\n    }\n  }\n\n  // [fx, fid]\n  pair<T, int> query(ll\
    \ x) {\n    x = get_idx(x);\n    int i = x + size;\n    pair<T, int> res;\n  \
    \  if (!MINIMIZE) res = {-infty<T>, -1};\n    if (MINIMIZE) res = {infty<T>, -1};\n\
    \    while (i) {\n      if (FID[i] != -1 && FID[i] != res.se) {\n        pair<T,\
    \ int> res1 = {evaluate_inner(FID[i], x), FID[i]};\n        res = (MINIMIZE ?\
    \ min(res, res1) : max(res, res1));\n      }\n      i >>= 1;\n    }\n    return\
    \ res;\n  }\n\n  void add_line_at(int i, int fid) {\n    int upper_bit = 31 -\
    \ __builtin_clz(i);\n    int l = (size >> upper_bit) * (i - (1 << upper_bit));\n\
    \    int r = l + (size >> upper_bit);\n    while (l < r) {\n      int gid = FID[i];\n\
    \      T fl = evaluate_inner(fid, l), fr = evaluate_inner(fid, r - 1);\n     \
    \ T gl = evaluate_inner(gid, l), gr = evaluate_inner(gid, r - 1);\n      bool\
    \ bl = (MINIMIZE ? fl < gl : fl > gl);\n      bool br = (MINIMIZE ? fr < gr :\
    \ fr > gr);\n      if (bl && br) {\n        FID[i] = fid;\n        return;\n \
    \     }\n      if (!bl && !br) return;\n      int m = (l + r) / 2;\n      T fm\
    \ = evaluate_inner(fid, m), gm = evaluate_inner(gid, m);\n      bool bm = (MINIMIZE\
    \ ? fm < gm : fm > gm);\n      if (bm) {\n        FID[i] = fid;\n        fid =\
    \ gid;\n        if (!bl) { i = 2 * i + 0, r = m; }\n        if (bl) { i = 2 *\
    \ i + 1, l = m; }\n      }\n      if (!bm) {\n        if (bl) { i = 2 * i + 0,\
    \ r = m; }\n        if (!bl) { i = 2 * i + 1, l = m; }\n      }\n    }\n  }\n\n\
    private:\n  T evaluate_inner(int fid, ll x) {\n    if (fid == -1) return (MINIMIZE\
    \ ? infty<T> : -infty<T>);\n    return evaluate(funcs[fid], (COMPRESS ? X[min<int>(x,\
    \ n - 1)] : x + lo));\n  }\n};\n"
  code: "// \u8A55\u4FA1\u70B9\u306F ll\u3001\u95A2\u6570\u306E\u5024\u306F T \u306B\
    \u306A\u3063\u3066\u3044\u308B\n// evaluate \u3092\u66F8\u304D\u5909\u3048\u308B\
    \u3068\u3001totally monotone \u306A\u95A2\u6570\u7FA4\u306B\u3082\u4F7F\u3048\u308B\
    \ntemplate <typename T, bool COMPRESS, bool MINIMIZE>\nstruct LiChao_Tree {\n\
    \  using FUNC = pair<T, T>;\n  vc<FUNC> funcs;\n\n  static inline T evaluate(FUNC&\
    \ f, ll x) { return f.fi * x + f.se; }\n\n  vc<ll> X;\n  ll lo, hi;\n  vc<int>\
    \ FID;\n  int n, log, size;\n\n  inline int get_idx(ll x) {\n    if constexpr\
    \ (COMPRESS) { return LB(X, x); }\n    assert(lo <= x && x < hi);\n    return\
    \ x - lo;\n  }\n\n  template <typename XY>\n  LiChao_Tree(const vc<XY>& pts) {\n\
    \    static_assert(COMPRESS);\n    for (auto&& x: pts) X.eb(x);\n    UNIQUE(X);\n\
    \    n = len(X), log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 <<\
    \ log;\n    FID.assign(size << 1, -1);\n  }\n\n  LiChao_Tree(ll lo, ll hi) : lo(lo),\
    \ hi(hi) {\n    static_assert(!COMPRESS);\n    n = hi - lo, log = 1;\n    while\
    \ ((1 << log) < n) ++log;\n    size = 1 << log;\n    FID.assign(size << 1, -1);\n\
    \  }\n\n  void add_line(FUNC f) {\n    int fid = len(funcs);\n    funcs.eb(f);\n\
    \    return add_line_at(1, fid);\n  }\n  void add_segment(ll xl, ll xr, FUNC f)\
    \ {\n    int fid = len(funcs);\n    funcs.eb(f);\n    xl = get_idx(xl), xr = get_idx(xr);\n\
    \    xl += size, xr += size;\n    while (xl < xr) {\n      if (xl & 1) add_line_at(xl++,\
    \ fid);\n      if (xr & 1) add_line_at(--xr, fid);\n      xl >>= 1, xr >>= 1;\n\
    \    }\n  }\n\n  // [fx, fid]\n  pair<T, int> query(ll x) {\n    x = get_idx(x);\n\
    \    int i = x + size;\n    pair<T, int> res;\n    if (!MINIMIZE) res = {-infty<T>,\
    \ -1};\n    if (MINIMIZE) res = {infty<T>, -1};\n    while (i) {\n      if (FID[i]\
    \ != -1 && FID[i] != res.se) {\n        pair<T, int> res1 = {evaluate_inner(FID[i],\
    \ x), FID[i]};\n        res = (MINIMIZE ? min(res, res1) : max(res, res1));\n\
    \      }\n      i >>= 1;\n    }\n    return res;\n  }\n\n  void add_line_at(int\
    \ i, int fid) {\n    int upper_bit = 31 - __builtin_clz(i);\n    int l = (size\
    \ >> upper_bit) * (i - (1 << upper_bit));\n    int r = l + (size >> upper_bit);\n\
    \    while (l < r) {\n      int gid = FID[i];\n      T fl = evaluate_inner(fid,\
    \ l), fr = evaluate_inner(fid, r - 1);\n      T gl = evaluate_inner(gid, l), gr\
    \ = evaluate_inner(gid, r - 1);\n      bool bl = (MINIMIZE ? fl < gl : fl > gl);\n\
    \      bool br = (MINIMIZE ? fr < gr : fr > gr);\n      if (bl && br) {\n    \
    \    FID[i] = fid;\n        return;\n      }\n      if (!bl && !br) return;\n\
    \      int m = (l + r) / 2;\n      T fm = evaluate_inner(fid, m), gm = evaluate_inner(gid,\
    \ m);\n      bool bm = (MINIMIZE ? fm < gm : fm > gm);\n      if (bm) {\n    \
    \    FID[i] = fid;\n        fid = gid;\n        if (!bl) { i = 2 * i + 0, r =\
    \ m; }\n        if (bl) { i = 2 * i + 1, l = m; }\n      }\n      if (!bm) {\n\
    \        if (bl) { i = 2 * i + 0, r = m; }\n        if (!bl) { i = 2 * i + 1,\
    \ l = m; }\n      }\n    }\n  }\n\nprivate:\n  T evaluate_inner(int fid, ll x)\
    \ {\n    if (fid == -1) return (MINIMIZE ? infty<T> : -infty<T>);\n    return\
    \ evaluate(funcs[fid], (COMPRESS ? X[min<int>(x, n - 1)] : x + lo));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/lichao.hpp
  requiredBy: []
  timestamp: '2023-07-03 05:19:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/datastructure/segment_add_get_min_2.test.cpp
  - test/library_checker/datastructure/line_add_get_min_lichao_2.test.cpp
documentation_of: convex/lichao.hpp
layout: document
redirect_from:
- /library/convex/lichao.hpp
- /library/convex/lichao.hpp.html
title: convex/lichao.hpp
---
