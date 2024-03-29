---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/ds/tree_wavelet_matrix.hpp
    title: graph/ds/tree_wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: string/prefix_substring_LCS.hpp
    title: string/prefix_substring_LCS.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/prefix_substring_lcs.test.cpp
    title: test/library_checker/string/prefix_substring_lcs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/wavelet_matrix.test.cpp
    title: test/mytest/wavelet_matrix.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1332.test.cpp
    title: test/yukicoder/1332.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2065.test.cpp
    title: test/yukicoder/2065.test.cpp
  - icon: ':x:'
    path: test/yukicoder/919.test.cpp
    title: test/yukicoder/919.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc127f_1.test.cpp
    title: test_atcoder/abc127f_1.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc324g.test.cpp
    title: test_atcoder/abc324g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  vc<pair<u32,\
    \ u32>> dat;\n  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }\n\n \
    \ void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }\n\n  void build()\
    \ {\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n\
    \  }\n\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  int rank(int k, bool\
    \ f = 1) {\n    auto [a, b] = dat[k >> 5];\n    int ret = b + popcnt(a & ((u32(1)\
    \ << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n  }\n};\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n\r\n// \u5EA7\u5727\u3059\u308B\u304B\u3069\u3046\u304B\u3092 COMPRESS \u3067\
    \u6307\u5B9A\u3059\u308B\r\n// xor \u7684\u306A\u4F7F\u3044\u65B9\u3092\u3059\u308B\
    \u5834\u5408\u306B\u306F\u3001\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\
    \ log \u3092\u6E21\u3059\u3053\u3068\r\ntemplate <typename T, bool COMPRESS, typename\
    \ Monoid = Monoid_Add<T>>\r\nstruct Wavelet_Matrix {\r\n  using MX = Monoid;\r\
    \n  using X = typename MX::value_type;\r\n  static_assert(MX::commute);\r\n  int\
    \ N, lg;\r\n  vector<int> mid;\r\n  vector<Bit_Vector> bv;\r\n  vc<T> key;\r\n\
    \  bool set_log;\r\n  vvc<X> cumsum;\r\n\r\n  Wavelet_Matrix() {}\r\n\r\n  //\
    \ \u548C\u3092\u4F7F\u308F\u306A\u3044\u306A\u3089\u3001SUM_data \u306F\u7A7A\u3067\
    \u3088\u3044\r\n  Wavelet_Matrix(vc<T> A, vc<X> SUM_data = {}, int log = -1) {\r\
    \n    build(A, SUM_data, log);\r\n  }\r\n\r\n  void build(vc<T> A, vc<X> SUM_data\
    \ = {}, int log = -1) {\r\n    N = len(A), lg = log, set_log = (log != -1);\r\n\
    \    bool MAKE_SUM = !(SUM_data.empty());\r\n    vc<X>& S = SUM_data;\r\n    if\
    \ (COMPRESS) {\r\n      assert(!set_log);\r\n      key.reserve(N);\r\n      vc<int>\
    \ I = argsort(A);\r\n      for (auto&& i: I) {\r\n        if (key.empty() || key.back()\
    \ != A[i]) key.eb(A[i]);\r\n        A[i] = len(key) - 1;\r\n      }\r\n      key.shrink_to_fit();\r\
    \n    }\r\n    if (lg == -1) lg = __lg(max<ll>(MAX(A), 1)) + 1;\r\n    mid.resize(lg);\r\
    \n    bv.assign(lg, Bit_Vector(N));\r\n    if (MAKE_SUM) cumsum.assign(1 + lg,\
    \ vc<X>(N + 1, MX::unit()));\r\n    S.resize(N);\r\n    vc<T> A0(N), A1(N);\r\n\
    \    vc<X> S0(N), S1(N);\r\n    FOR_R(d, -1, lg) {\r\n      int p0 = 0, p1 = 0;\r\
    \n      if (MAKE_SUM) {\r\n        FOR(i, N) { cumsum[d + 1][i + 1] = MX::op(cumsum[d\
    \ + 1][i], S[i]); }\r\n      }\r\n      if (d == -1) break;\r\n      FOR(i, N)\
    \ {\r\n        bool f = (A[i] >> d & 1);\r\n        if (!f) {\r\n          if\
    \ (MAKE_SUM) S0[p0] = S[i];\r\n          A0[p0++] = A[i];\r\n        }\r\n   \
    \     if (f) {\r\n          if (MAKE_SUM) S1[p1] = S[i];\r\n          bv[d].set(i),\
    \ A1[p1++] = A[i];\r\n        }\r\n      }\r\n      mid[d] = p0;\r\n      bv[d].build();\r\
    \n      swap(A, A0), swap(S, S0);\r\n      FOR(i, p1) A[p0 + i] = A1[i], S[p0\
    \ + i] = S1[i];\r\n    }\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\
    \ [a, b) \u306B\u53CE\u307E\u308B\u3082\u306E\u3092\u6570\u3048\u308B\r\n  int\
    \ count(int L, int R, T a, T b, T xor_val = 0) {\r\n    return prefix_count(L,\
    \ R, b, xor_val) - prefix_count(L, R, a, xor_val);\r\n  }\r\n\r\n  int count(vc<pair<int,\
    \ int>> segments, T a, T b, T xor_val = 0) {\r\n    int res = 0;\r\n    for (auto&&\
    \ [L, R]: segments) res += count(L, R, a, b, xor_val);\r\n    return res;\r\n\
    \  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067\
    \ k>=0 \u756A\u76EE\u3068 prefix sum\r\n  pair<T, X> kth_value_and_sum(int L,\
    \ int R, int k, T xor_val = 0) {\r\n    assert(!cumsum.empty());\r\n    if (xor_val\
    \ != 0) assert(set_log);\r\n    assert(0 <= k && k <= R - L);\r\n    if (k ==\
    \ R - L) { return {infty<T>, sum_all(L, R)}; }\r\n    int cnt = 0;\r\n    X sm\
    \ = MX::unit();\r\n    T ret = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\
    \n      bool f = (xor_val >> d) & 1;\r\n      int l0 = bv[d].rank(L, 0), r0 =\
    \ bv[d].rank(R, 0);\r\n      int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));\r\n\
    \      if (cnt + c > k) {\r\n        if (!f) L = l0, R = r0;\r\n        if (f)\
    \ L += mid[d] - l0, R += mid[d] - r0;\r\n      } else {\r\n        X s = (f ?\
    \ get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));\r\n        cnt +=\
    \ c, ret |= T(1) << d, sm = MX::op(sm, s);\r\n        if (!f) L += mid[d] - l0,\
    \ R += mid[d] - r0;\r\n        if (f) L = l0, R = r0;\r\n      }\r\n    }\r\n\
    \    sm = MX::op(sm, get(0, L, L + k - cnt));\r\n    if (COMPRESS) ret = key[ret];\r\
    \n    return {ret, sm};\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001\
    [L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\r\n  pair<T, X> kth_value_and_sum(vc<pair<int,\
    \ int>> segments, int k,\r\n                               T xor_val = 0) {\r\n\
    \    assert(!cumsum.empty());\r\n    if (xor_val != 0) assert(set_log);\r\n  \
    \  int total_len = 0;\r\n    for (auto&& [L, R]: segments) total_len += R - L;\r\
    \n    assert(0 <= k && k <= total_len);\r\n    if (k == total_len) { return {infty<T>,\
    \ sum_all(segments)}; }\r\n    int cnt = 0;\r\n    X sm = MX::unit();\r\n    T\
    \ ret = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      bool f = (xor_val\
    \ >> d) & 1;\r\n      int c = 0;\r\n      for (auto&& [L, R]: segments) {\r\n\
    \        int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n        c += (f\
    \ ? (R - L) - (r0 - l0) : (r0 - l0));\r\n      }\r\n      if (cnt + c > k) {\r\
    \n        for (auto&& [L, R]: segments) {\r\n          int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n          if (!f) L = l0, R = r0;\r\n        \
    \  if (f) L += mid[d] - l0, R += mid[d] - r0;\r\n        }\r\n      } else {\r\
    \n        cnt += c, ret |= T(1) << d;\r\n        for (auto&& [L, R]: segments)\
    \ {\r\n          int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n       \
    \   X s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));\r\n\
    \          sm = MX::op(sm, s);\r\n          if (!f) L += mid[d] - l0, R += mid[d]\
    \ - r0;\r\n          if (f) L = l0, R = r0;\r\n        }\r\n      }\r\n    }\r\
    \n    for (auto&& [L, R]: segments) {\r\n      int t = min(R - L, k - cnt);\r\n\
    \      sm = MX::op(sm, get(0, L, L + t));\r\n      cnt += t;\r\n    }\r\n    if\
    \ (COMPRESS) ret = key[ret];\r\n    return {ret, sm};\r\n  }\r\n\r\n  // xor \u3057\
    \u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\r\n\
    \  T kth(int L, int R, int k, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\
    \n    assert(0 <= k && k < R - L);\r\n    int cnt = 0;\r\n    T ret = 0;\r\n \
    \   for (int d = lg - 1; d >= 0; --d) {\r\n      bool f = (xor_val >> d) & 1;\r\
    \n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n      int c = (f\
    \ ? (R - L) - (r0 - l0) : (r0 - l0));\r\n      if (cnt + c > k) {\r\n        if\
    \ (!f) L = l0, R = r0;\r\n        if (f) L += mid[d] - l0, R += mid[d] - r0;\r\
    \n      } else {\r\n        cnt += c, ret |= T(1) << d;\r\n        if (!f) L +=\
    \ mid[d] - l0, R += mid[d] - r0;\r\n        if (f) L = l0, R = r0;\r\n      }\r\
    \n    }\r\n    if (COMPRESS) ret = key[ret];\r\n    return ret;\r\n  }\r\n\r\n\
    \  T kth(vc<pair<int, int>> segments, int k, T xor_val = 0) {\r\n    int total_len\
    \ = 0;\r\n    for (auto&& [L, R]: segments) total_len += R - L;\r\n    assert(0\
    \ <= k && k < total_len);\r\n    int cnt = 0;\r\n    T ret = 0;\r\n    for (int\
    \ d = lg - 1; d >= 0; --d) {\r\n      bool f = (xor_val >> d) & 1;\r\n      int\
    \ c = 0;\r\n      for (auto&& [L, R]: segments) {\r\n        int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n        c += (f ? (R - L) - (r0 - l0) : (r0 -\
    \ l0));\r\n      }\r\n      if (cnt + c > k) {\r\n        for (auto&& [L, R]:\
    \ segments) {\r\n          int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\
    \n          if (!f) L = l0, R = r0;\r\n          if (f) L += mid[d] - l0, R +=\
    \ mid[d] - r0;\r\n        }\r\n      } else {\r\n        cnt += c, ret |= T(1)\
    \ << d;\r\n        for (auto&& [L, R]: segments) {\r\n          int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n          if (!f) L += mid[d] - l0, R += mid[d]\
    \ - r0;\r\n          if (f) L = l0, R = r0;\r\n        }\r\n      }\r\n    }\r\
    \n    if (COMPRESS) ret = key[ret];\r\n    return ret;\r\n  }\r\n\r\n  // xor\
    \ \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067\u4E2D\u592E\u5024\
    \u3002\r\n  // LOWER = true\uFF1A\u4E0B\u5074\u4E2D\u592E\u5024\u3001false\uFF1A\
    \u4E0A\u5074\u4E2D\u592E\u5024\r\n  T median(bool UPPER, int L, int R, T xor_val\
    \ = 0) {\r\n    int n = R - L;\r\n    int k = (UPPER ? n / 2 : (n - 1) / 2);\r\
    \n    return kth(L, R, k, xor_val);\r\n  }\r\n\r\n  T median(bool UPPER, vc<pair<int,\
    \ int>> segments, T xor_val = 0) {\r\n    int n = 0;\r\n    for (auto&& [L, R]:\
    \ segments) n += R - L;\r\n    int k = (UPPER ? n / 2 : (n - 1) / 2);\r\n    return\
    \ kth(segments, k, xor_val);\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\
    \ [k1, k2) \u756A\u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\
    \u548C\r\n  X sum(int L, int R, int k1, int k2, T xor_val = 0) {\r\n    X add\
    \ = prefix_sum(L, R, k2, xor_val);\r\n    X sub = prefix_sum(L, R, k1, xor_val);\r\
    \n    return MX::op(add, MX::inverse(sub));\r\n  }\r\n\r\n  X sum_all(int L, int\
    \ R) { return get(lg, L, R); }\r\n\r\n  X sum_all(vc<pair<int, int>> segments)\
    \ {\r\n    X sm = MX::unit();\r\n    for (auto&& [L, R]: segments) { sm = MX::op(sm,\
    \ get(lg, L, R)); }\r\n    return sm;\r\n  }\r\n\r\n  // check(cnt, prefix sum)\
    \ \u304C true \u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5927\u306E (cnt, sum)\r\
    \n  template <typename F>\r\n  pair<int, X> max_right(F check, int L, int R, T\
    \ xor_val = 0) {\r\n    assert(check(0, MX::unit()));\r\n    if (xor_val != 0)\
    \ assert(set_log);\r\n    if (check(R - L, get(lg, L, R))) return {R - L, get(lg,\
    \ L, R)};\r\n    int cnt = 0;\r\n    X sm = MX::unit();\r\n    for (int d = lg\
    \ - 1; d >= 0; --d) {\r\n      bool f = (xor_val >> d) & 1;\r\n      int l0 =\
    \ bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n      int c = (f ? (R - L) - (r0\
    \ - l0) : (r0 - l0));\r\n      X s = (f ? get(d, L + mid[d] - l0, R + mid[d] -\
    \ r0) : get(d, l0, r0));\r\n      if (check(cnt + c, MX::op(sm, s))) {\r\n   \
    \     cnt += c, sm = MX::op(sm, s);\r\n        if (f) L = l0, R = r0;\r\n    \
    \    if (!f) L += mid[d] - l0, R += mid[d] - r0;\r\n      } else {\r\n       \
    \ if (!f) L = l0, R = r0;\r\n        if (f) L += mid[d] - l0, R += mid[d] - r0;\r\
    \n      }\r\n    }\r\n    int k = binary_search(\r\n        [&](int k) -> bool\
    \ {\r\n          return check(cnt + k, MX::op(sm, get(0, L, L + k)));\r\n    \
    \    },\r\n        0, R - L);\r\n    cnt += k;\r\n    sm = MX::op(sm, get(0, L,\
    \ L + k));\r\n    return {cnt, sm};\r\n  }\r\n\r\nprivate:\r\n  inline X get(int\
    \ d, int L, int R) {\r\n    assert(!cumsum.empty());\r\n    return MX::op(MX::inverse(cumsum[d][L]),\
    \ cumsum[d][R]);\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067 [0, x)\
    \ \u306B\u53CE\u307E\u308B\u3082\u306E\u3092\u6570\u3048\u308B\r\n  int prefix_count(int\
    \ L, int R, T x, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n\
    \    x = (COMPRESS ? LB(key, x) : x);\r\n    if (x == 0) return 0;\r\n    if (x\
    \ >= (1 << lg)) return R - L;\r\n    int cnt = 0;\r\n    FOR_R(d, lg) {\r\n  \
    \    bool add = (x >> d) & 1;\r\n      bool f = ((xor_val) >> d) & 1;\r\n    \
    \  int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n      int kf = (f ? (R\
    \ - L) - (r0 - l0) : (r0 - l0));\r\n      if (add) {\r\n        cnt += kf;\r\n\
    \        if (f) { L = l0, R = r0; }\r\n        if (!f) { L += mid[d] - l0, R +=\
    \ mid[d] - r0; }\r\n      } else {\r\n        if (!f) L = l0, R = r0;\r\n    \
    \    if (f) L += mid[d] - l0, R += mid[d] - r0;\r\n      }\r\n    }\r\n    return\
    \ cnt;\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067 [0, k) \u756A\u76EE\
    \u306E\u3082\u306E\u306E\u548C\r\n  X prefix_sum(int L, int R, int k, T xor_val\
    \ = 0) {\r\n    return kth_value_and_sum(L, R, k, xor_val).se;\r\n  }\r\n\r\n\
    \  // xor \u3057\u305F\u7D50\u679C\u3067 [0, k) \u756A\u76EE\u306E\u3082\u306E\
    \u306E\u548C\r\n  X prefix_sum(vc<pair<int, int>> segments, int k, T xor_val =\
    \ 0) {\r\n    return kth_value_and_sum(segments, k, xor_val).se;\r\n  }\r\n};\n"
  code: "#include \"ds/bit_vector.hpp\"\r\n#include \"alg/monoid/add.hpp\"\r\n\r\n\
    // \u5EA7\u5727\u3059\u308B\u304B\u3069\u3046\u304B\u3092 COMPRESS \u3067\u6307\
    \u5B9A\u3059\u308B\r\n// xor \u7684\u306A\u4F7F\u3044\u65B9\u3092\u3059\u308B\u5834\
    \u5408\u306B\u306F\u3001\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067 log \u3092\
    \u6E21\u3059\u3053\u3068\r\ntemplate <typename T, bool COMPRESS, typename Monoid\
    \ = Monoid_Add<T>>\r\nstruct Wavelet_Matrix {\r\n  using MX = Monoid;\r\n  using\
    \ X = typename MX::value_type;\r\n  static_assert(MX::commute);\r\n  int N, lg;\r\
    \n  vector<int> mid;\r\n  vector<Bit_Vector> bv;\r\n  vc<T> key;\r\n  bool set_log;\r\
    \n  vvc<X> cumsum;\r\n\r\n  Wavelet_Matrix() {}\r\n\r\n  // \u548C\u3092\u4F7F\
    \u308F\u306A\u3044\u306A\u3089\u3001SUM_data \u306F\u7A7A\u3067\u3088\u3044\r\n\
    \  Wavelet_Matrix(vc<T> A, vc<X> SUM_data = {}, int log = -1) {\r\n    build(A,\
    \ SUM_data, log);\r\n  }\r\n\r\n  void build(vc<T> A, vc<X> SUM_data = {}, int\
    \ log = -1) {\r\n    N = len(A), lg = log, set_log = (log != -1);\r\n    bool\
    \ MAKE_SUM = !(SUM_data.empty());\r\n    vc<X>& S = SUM_data;\r\n    if (COMPRESS)\
    \ {\r\n      assert(!set_log);\r\n      key.reserve(N);\r\n      vc<int> I = argsort(A);\r\
    \n      for (auto&& i: I) {\r\n        if (key.empty() || key.back() != A[i])\
    \ key.eb(A[i]);\r\n        A[i] = len(key) - 1;\r\n      }\r\n      key.shrink_to_fit();\r\
    \n    }\r\n    if (lg == -1) lg = __lg(max<ll>(MAX(A), 1)) + 1;\r\n    mid.resize(lg);\r\
    \n    bv.assign(lg, Bit_Vector(N));\r\n    if (MAKE_SUM) cumsum.assign(1 + lg,\
    \ vc<X>(N + 1, MX::unit()));\r\n    S.resize(N);\r\n    vc<T> A0(N), A1(N);\r\n\
    \    vc<X> S0(N), S1(N);\r\n    FOR_R(d, -1, lg) {\r\n      int p0 = 0, p1 = 0;\r\
    \n      if (MAKE_SUM) {\r\n        FOR(i, N) { cumsum[d + 1][i + 1] = MX::op(cumsum[d\
    \ + 1][i], S[i]); }\r\n      }\r\n      if (d == -1) break;\r\n      FOR(i, N)\
    \ {\r\n        bool f = (A[i] >> d & 1);\r\n        if (!f) {\r\n          if\
    \ (MAKE_SUM) S0[p0] = S[i];\r\n          A0[p0++] = A[i];\r\n        }\r\n   \
    \     if (f) {\r\n          if (MAKE_SUM) S1[p1] = S[i];\r\n          bv[d].set(i),\
    \ A1[p1++] = A[i];\r\n        }\r\n      }\r\n      mid[d] = p0;\r\n      bv[d].build();\r\
    \n      swap(A, A0), swap(S, S0);\r\n      FOR(i, p1) A[p0 + i] = A1[i], S[p0\
    \ + i] = S1[i];\r\n    }\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\
    \ [a, b) \u306B\u53CE\u307E\u308B\u3082\u306E\u3092\u6570\u3048\u308B\r\n  int\
    \ count(int L, int R, T a, T b, T xor_val = 0) {\r\n    return prefix_count(L,\
    \ R, b, xor_val) - prefix_count(L, R, a, xor_val);\r\n  }\r\n\r\n  int count(vc<pair<int,\
    \ int>> segments, T a, T b, T xor_val = 0) {\r\n    int res = 0;\r\n    for (auto&&\
    \ [L, R]: segments) res += count(L, R, a, b, xor_val);\r\n    return res;\r\n\
    \  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067\
    \ k>=0 \u756A\u76EE\u3068 prefix sum\r\n  pair<T, X> kth_value_and_sum(int L,\
    \ int R, int k, T xor_val = 0) {\r\n    assert(!cumsum.empty());\r\n    if (xor_val\
    \ != 0) assert(set_log);\r\n    assert(0 <= k && k <= R - L);\r\n    if (k ==\
    \ R - L) { return {infty<T>, sum_all(L, R)}; }\r\n    int cnt = 0;\r\n    X sm\
    \ = MX::unit();\r\n    T ret = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\
    \n      bool f = (xor_val >> d) & 1;\r\n      int l0 = bv[d].rank(L, 0), r0 =\
    \ bv[d].rank(R, 0);\r\n      int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));\r\n\
    \      if (cnt + c > k) {\r\n        if (!f) L = l0, R = r0;\r\n        if (f)\
    \ L += mid[d] - l0, R += mid[d] - r0;\r\n      } else {\r\n        X s = (f ?\
    \ get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));\r\n        cnt +=\
    \ c, ret |= T(1) << d, sm = MX::op(sm, s);\r\n        if (!f) L += mid[d] - l0,\
    \ R += mid[d] - r0;\r\n        if (f) L = l0, R = r0;\r\n      }\r\n    }\r\n\
    \    sm = MX::op(sm, get(0, L, L + k - cnt));\r\n    if (COMPRESS) ret = key[ret];\r\
    \n    return {ret, sm};\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001\
    [L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\r\n  pair<T, X> kth_value_and_sum(vc<pair<int,\
    \ int>> segments, int k,\r\n                               T xor_val = 0) {\r\n\
    \    assert(!cumsum.empty());\r\n    if (xor_val != 0) assert(set_log);\r\n  \
    \  int total_len = 0;\r\n    for (auto&& [L, R]: segments) total_len += R - L;\r\
    \n    assert(0 <= k && k <= total_len);\r\n    if (k == total_len) { return {infty<T>,\
    \ sum_all(segments)}; }\r\n    int cnt = 0;\r\n    X sm = MX::unit();\r\n    T\
    \ ret = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      bool f = (xor_val\
    \ >> d) & 1;\r\n      int c = 0;\r\n      for (auto&& [L, R]: segments) {\r\n\
    \        int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n        c += (f\
    \ ? (R - L) - (r0 - l0) : (r0 - l0));\r\n      }\r\n      if (cnt + c > k) {\r\
    \n        for (auto&& [L, R]: segments) {\r\n          int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n          if (!f) L = l0, R = r0;\r\n        \
    \  if (f) L += mid[d] - l0, R += mid[d] - r0;\r\n        }\r\n      } else {\r\
    \n        cnt += c, ret |= T(1) << d;\r\n        for (auto&& [L, R]: segments)\
    \ {\r\n          int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n       \
    \   X s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));\r\n\
    \          sm = MX::op(sm, s);\r\n          if (!f) L += mid[d] - l0, R += mid[d]\
    \ - r0;\r\n          if (f) L = l0, R = r0;\r\n        }\r\n      }\r\n    }\r\
    \n    for (auto&& [L, R]: segments) {\r\n      int t = min(R - L, k - cnt);\r\n\
    \      sm = MX::op(sm, get(0, L, L + t));\r\n      cnt += t;\r\n    }\r\n    if\
    \ (COMPRESS) ret = key[ret];\r\n    return {ret, sm};\r\n  }\r\n\r\n  // xor \u3057\
    \u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\r\n\
    \  T kth(int L, int R, int k, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\
    \n    assert(0 <= k && k < R - L);\r\n    int cnt = 0;\r\n    T ret = 0;\r\n \
    \   for (int d = lg - 1; d >= 0; --d) {\r\n      bool f = (xor_val >> d) & 1;\r\
    \n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n      int c = (f\
    \ ? (R - L) - (r0 - l0) : (r0 - l0));\r\n      if (cnt + c > k) {\r\n        if\
    \ (!f) L = l0, R = r0;\r\n        if (f) L += mid[d] - l0, R += mid[d] - r0;\r\
    \n      } else {\r\n        cnt += c, ret |= T(1) << d;\r\n        if (!f) L +=\
    \ mid[d] - l0, R += mid[d] - r0;\r\n        if (f) L = l0, R = r0;\r\n      }\r\
    \n    }\r\n    if (COMPRESS) ret = key[ret];\r\n    return ret;\r\n  }\r\n\r\n\
    \  T kth(vc<pair<int, int>> segments, int k, T xor_val = 0) {\r\n    int total_len\
    \ = 0;\r\n    for (auto&& [L, R]: segments) total_len += R - L;\r\n    assert(0\
    \ <= k && k < total_len);\r\n    int cnt = 0;\r\n    T ret = 0;\r\n    for (int\
    \ d = lg - 1; d >= 0; --d) {\r\n      bool f = (xor_val >> d) & 1;\r\n      int\
    \ c = 0;\r\n      for (auto&& [L, R]: segments) {\r\n        int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n        c += (f ? (R - L) - (r0 - l0) : (r0 -\
    \ l0));\r\n      }\r\n      if (cnt + c > k) {\r\n        for (auto&& [L, R]:\
    \ segments) {\r\n          int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\
    \n          if (!f) L = l0, R = r0;\r\n          if (f) L += mid[d] - l0, R +=\
    \ mid[d] - r0;\r\n        }\r\n      } else {\r\n        cnt += c, ret |= T(1)\
    \ << d;\r\n        for (auto&& [L, R]: segments) {\r\n          int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n          if (!f) L += mid[d] - l0, R += mid[d]\
    \ - r0;\r\n          if (f) L = l0, R = r0;\r\n        }\r\n      }\r\n    }\r\
    \n    if (COMPRESS) ret = key[ret];\r\n    return ret;\r\n  }\r\n\r\n  // xor\
    \ \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067\u4E2D\u592E\u5024\
    \u3002\r\n  // LOWER = true\uFF1A\u4E0B\u5074\u4E2D\u592E\u5024\u3001false\uFF1A\
    \u4E0A\u5074\u4E2D\u592E\u5024\r\n  T median(bool UPPER, int L, int R, T xor_val\
    \ = 0) {\r\n    int n = R - L;\r\n    int k = (UPPER ? n / 2 : (n - 1) / 2);\r\
    \n    return kth(L, R, k, xor_val);\r\n  }\r\n\r\n  T median(bool UPPER, vc<pair<int,\
    \ int>> segments, T xor_val = 0) {\r\n    int n = 0;\r\n    for (auto&& [L, R]:\
    \ segments) n += R - L;\r\n    int k = (UPPER ? n / 2 : (n - 1) / 2);\r\n    return\
    \ kth(segments, k, xor_val);\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\
    \ [k1, k2) \u756A\u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\
    \u548C\r\n  X sum(int L, int R, int k1, int k2, T xor_val = 0) {\r\n    X add\
    \ = prefix_sum(L, R, k2, xor_val);\r\n    X sub = prefix_sum(L, R, k1, xor_val);\r\
    \n    return MX::op(add, MX::inverse(sub));\r\n  }\r\n\r\n  X sum_all(int L, int\
    \ R) { return get(lg, L, R); }\r\n\r\n  X sum_all(vc<pair<int, int>> segments)\
    \ {\r\n    X sm = MX::unit();\r\n    for (auto&& [L, R]: segments) { sm = MX::op(sm,\
    \ get(lg, L, R)); }\r\n    return sm;\r\n  }\r\n\r\n  // check(cnt, prefix sum)\
    \ \u304C true \u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5927\u306E (cnt, sum)\r\
    \n  template <typename F>\r\n  pair<int, X> max_right(F check, int L, int R, T\
    \ xor_val = 0) {\r\n    assert(check(0, MX::unit()));\r\n    if (xor_val != 0)\
    \ assert(set_log);\r\n    if (check(R - L, get(lg, L, R))) return {R - L, get(lg,\
    \ L, R)};\r\n    int cnt = 0;\r\n    X sm = MX::unit();\r\n    for (int d = lg\
    \ - 1; d >= 0; --d) {\r\n      bool f = (xor_val >> d) & 1;\r\n      int l0 =\
    \ bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n      int c = (f ? (R - L) - (r0\
    \ - l0) : (r0 - l0));\r\n      X s = (f ? get(d, L + mid[d] - l0, R + mid[d] -\
    \ r0) : get(d, l0, r0));\r\n      if (check(cnt + c, MX::op(sm, s))) {\r\n   \
    \     cnt += c, sm = MX::op(sm, s);\r\n        if (f) L = l0, R = r0;\r\n    \
    \    if (!f) L += mid[d] - l0, R += mid[d] - r0;\r\n      } else {\r\n       \
    \ if (!f) L = l0, R = r0;\r\n        if (f) L += mid[d] - l0, R += mid[d] - r0;\r\
    \n      }\r\n    }\r\n    int k = binary_search(\r\n        [&](int k) -> bool\
    \ {\r\n          return check(cnt + k, MX::op(sm, get(0, L, L + k)));\r\n    \
    \    },\r\n        0, R - L);\r\n    cnt += k;\r\n    sm = MX::op(sm, get(0, L,\
    \ L + k));\r\n    return {cnt, sm};\r\n  }\r\n\r\nprivate:\r\n  inline X get(int\
    \ d, int L, int R) {\r\n    assert(!cumsum.empty());\r\n    return MX::op(MX::inverse(cumsum[d][L]),\
    \ cumsum[d][R]);\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067 [0, x)\
    \ \u306B\u53CE\u307E\u308B\u3082\u306E\u3092\u6570\u3048\u308B\r\n  int prefix_count(int\
    \ L, int R, T x, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n\
    \    x = (COMPRESS ? LB(key, x) : x);\r\n    if (x == 0) return 0;\r\n    if (x\
    \ >= (1 << lg)) return R - L;\r\n    int cnt = 0;\r\n    FOR_R(d, lg) {\r\n  \
    \    bool add = (x >> d) & 1;\r\n      bool f = ((xor_val) >> d) & 1;\r\n    \
    \  int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n      int kf = (f ? (R\
    \ - L) - (r0 - l0) : (r0 - l0));\r\n      if (add) {\r\n        cnt += kf;\r\n\
    \        if (f) { L = l0, R = r0; }\r\n        if (!f) { L += mid[d] - l0, R +=\
    \ mid[d] - r0; }\r\n      } else {\r\n        if (!f) L = l0, R = r0;\r\n    \
    \    if (f) L += mid[d] - l0, R += mid[d] - r0;\r\n      }\r\n    }\r\n    return\
    \ cnt;\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067 [0, k) \u756A\u76EE\
    \u306E\u3082\u306E\u306E\u548C\r\n  X prefix_sum(int L, int R, int k, T xor_val\
    \ = 0) {\r\n    return kth_value_and_sum(L, R, k, xor_val).se;\r\n  }\r\n\r\n\
    \  // xor \u3057\u305F\u7D50\u679C\u3067 [0, k) \u756A\u76EE\u306E\u3082\u306E\
    \u306E\u548C\r\n  X prefix_sum(vc<pair<int, int>> segments, int k, T xor_val =\
    \ 0) {\r\n    return kth_value_and_sum(segments, k, xor_val).se;\r\n  }\r\n};"
  dependsOn:
  - ds/bit_vector.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix/wavelet_matrix.hpp
  requiredBy:
  - string/prefix_substring_LCS.hpp
  - graph/ds/tree_wavelet_matrix.hpp
  timestamp: '2024-02-04 20:58:47+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc127f_1.test.cpp
  - test_atcoder/abc324g.test.cpp
  - test/library_checker/string/prefix_substring_lcs.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - test/yukicoder/2065.test.cpp
  - test/yukicoder/1332.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/919.test.cpp
  - test/mytest/wavelet_matrix.test.cpp
documentation_of: ds/wavelet_matrix/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix/wavelet_matrix.hpp
- /library/ds/wavelet_matrix/wavelet_matrix.hpp.html
title: ds/wavelet_matrix/wavelet_matrix.hpp
---
