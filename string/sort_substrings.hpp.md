---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':question:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc240ex.test.cpp
    title: test_atcoder/abc240ex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/suffix_array.hpp\"\n\n#line 2 \"alg/monoid/min.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 1 \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\
    \ntemplate <class Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table()\
    \ {}\n  Sparse_Table(int n) { build(n); }\n  template <typename F>\n  Sparse_Table(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].resize(n);\n    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1)\
    \ {\n      dat[i + 1].resize(len(dat[i]) - (1 << i));\n      FOR(j, len(dat[i])\
    \ - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n\
    \      }\n    }\n  }\n\n  X prod(int L, int R) {\n    if (L == R) return MX::unit();\n\
    \    if (R == L + 1) return dat[0][L];\n    int k = topbit(R - L - 1);\n    return\
    \ MX::op(dat[k][L], dat[k][R - (1 << k)]);\n  }\n\n  template <class F>\n  int\
    \ max_right(const F check, int L) {\n    assert(0 <= L && L <= n && check(MX::unit()));\n\
    \    if (L == n) return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template\
    \ <class F>\n  int min_left(const F check, int R) {\n    assert(0 <= R && R <=\
    \ n && check(MX::unit()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n\
    \    while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n#line 5 \"string/suffix_array.hpp\"\n\n// \u8F9E\u66F8\u9806 i \u756A\
    \u76EE\u306E suffix \u304C j \u6587\u5B57\u76EE\u59CB\u307E\u308A\u3067\u3042\u308B\
    \u3068\u304D\u3001\n// SA[i] = j, ISA[j] = i\n// |S|>0 \u3092\u524D\u63D0\uFF08\
    \u305D\u3046\u3067\u306A\u3044\u5834\u5408 dummy \u6587\u5B57\u3092\u8FFD\u52A0\
    \u3057\u3066\u5229\u7528\u305B\u3088\uFF09\ntemplate <bool USE_LCP_QUERY = 0>\n\
    struct Suffix_Array {\n  vc<int> SA;\n  vc<int> ISA;\n  vc<int> LCP;\n  Sparse_Table<Monoid_Min<int>>\
    \ seg;\n  // DisjointSparse<Monoid_Min<int>> seg;\n\n  Suffix_Array(string& s)\
    \ {\n    assert(len(s) > 0);\n    char first = 127, last = 0;\n    for (auto&&\
    \ c: s) {\n      chmin(first, c);\n      chmax(last, c);\n    }\n    SA = calc_suffix_array(s,\
    \ first, last);\n    calc_LCP(s);\n    if (USE_LCP_QUERY) seg.build(LCP);\n  }\n\
    \n  Suffix_Array(vc<int>& s) {\n    assert(len(s) > 0);\n    SA = calc_suffix_array(s);\n\
    \    calc_LCP(s);\n    if (USE_LCP_QUERY) seg.build(LCP);\n  }\n\n  // lcp(S[i:],\
    \ S[j:])\n  int lcp(int i, int j) {\n    static_assert(USE_LCP_QUERY);\n    int\
    \ n = len(SA);\n    if (i == n || j == n) return 0;\n    if (i == j) return n\
    \ - i;\n    i = ISA[i], j = ISA[j];\n    if (i > j) swap(i, j);\n    return seg.prod(i,\
    \ j);\n  }\n\n  // S[i:] \u3068\u306E lcp \u304C n \u4EE5\u4E0A\u3067\u3042\u308B\
    \u3088\u3046\u306A\u534A\u958B\u533A\u9593\n  pair<int, int> lcp_range(int i,\
    \ int n) {\n    static_assert(USE_LCP_QUERY);\n    i = ISA[i];\n    int a = seg.min_left([&](auto\
    \ e) -> bool { return e >= n; }, i);\n    int b = seg.max_right([&](auto e) ->\
    \ bool { return e >= n; }, i);\n    return {a, b + 1};\n  }\n\n  // -1: S[L1:R1)\
    \ < S[L2, R2)\n  //  0: S[L1:R1) = S[L2, R2)\n  // +1: S[L1:R1) > S[L2, R2)\n\
    \  int compare(int L1, int R1, int L2, int R2) {\n    int N = len(SA);\n    int\
    \ n1 = R1 - L1, n2 = R2 - L2;\n    int n = lcp(L1, L2);\n    if (n == n1 && n\
    \ == n2) return 0;\n    if (n == n1) return -1;\n    if (n == n2) return 1;\n\
    \    return (ISA[L1 + n] > ISA[L2 + n] ? 1 : -1);\n  }\n\nprivate:\n  void induced_sort(const\
    \ vc<int>& vect, int val_range, vc<int>& SA,\n                    const vc<bool>&\
    \ sl, const vc<int>& lms_idx) {\n    vc<int> l(val_range, 0), r(val_range, 0);\n\
    \    for (int c: vect) {\n      if (c + 1 < val_range) ++l[c + 1];\n      ++r[c];\n\
    \    }\n    partial_sum(l.begin(), l.end(), l.begin());\n    partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    fill(SA.begin(), SA.end(), -1);\n    for (int i =\
    \ (int)lms_idx.size() - 1; i >= 0; --i)\n      SA[--r[vect[lms_idx[i]]]] = lms_idx[i];\n\
    \    for (int i: SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i - 1]]++] = i\
    \ - 1;\n    fill(r.begin(), r.end(), 0);\n    for (int c: vect) ++r[c];\n    partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1;\
    \ --k, i = SA[k])\n      if (i >= 1 && !sl[i - 1]) { SA[--r[vect[i - 1]]] = i\
    \ - 1; }\n  }\n\n  vc<int> SA_IS(const vc<int>& vect, int val_range) {\n    const\
    \ int n = vect.size();\n    vc<int> SA(n), lms_idx;\n    vc<bool> sl(n);\n   \
    \ sl[n - 1] = false;\n    for (int i = n - 2; i >= 0; --i) {\n      sl[i] = (vect[i]\
    \ > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));\n      if (sl[i] &&\
    \ !sl[i + 1]) lms_idx.push_back(i + 1);\n    }\n    reverse(lms_idx.begin(), lms_idx.end());\n\
    \    induced_sort(vect, val_range, SA, sl, lms_idx);\n    vc<int> new_lms_idx(lms_idx.size()),\
    \ lms_vec(lms_idx.size());\n    for (int i = 0, k = 0; i < n; ++i)\n      if (!sl[SA[i]]\
    \ && SA[i] >= 1 && sl[SA[i] - 1]) {\n        new_lms_idx[k++] = SA[i];\n     \
    \ }\n    int cur = 0;\n    SA[n - 1] = cur;\n    for (size_t k = 1; k < new_lms_idx.size();\
    \ ++k) {\n      int i = new_lms_idx[k - 1], j = new_lms_idx[k];\n      if (vect[i]\
    \ != vect[j]) {\n        SA[j] = ++cur;\n        continue;\n      }\n      bool\
    \ flag = false;\n      for (int a = i + 1, b = j + 1;; ++a, ++b) {\n        if\
    \ (vect[a] != vect[b]) {\n          flag = true;\n          break;\n        }\n\
    \        if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {\n          flag\
    \ = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));\n          break;\n   \
    \     }\n      }\n      SA[j] = (flag ? ++cur : cur);\n    }\n    for (size_t\
    \ i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];\n    if (cur +\
    \ 1 < (int)lms_idx.size()) {\n      auto lms_SA = SA_IS(lms_vec, cur + 1);\n \
    \     for (size_t i = 0; i < lms_idx.size(); ++i) {\n        new_lms_idx[i] =\
    \ lms_idx[lms_SA[i]];\n      }\n    }\n    induced_sort(vect, val_range, SA, sl,\
    \ new_lms_idx);\n    return SA;\n  }\n\n  vc<int> calc_suffix_array(const string&\
    \ s, const char first = 'a',\n                            const char last = 'z')\
    \ {\n    vc<int> vect(s.size() + 1);\n    copy(begin(s), end(s), begin(vect));\n\
    \    for (auto& x: vect) x -= (int)first - 1;\n    vect.back() = 0;\n    auto\
    \ ret = SA_IS(vect, (int)last - (int)first + 2);\n    ret.erase(ret.begin());\n\
    \    return ret;\n  }\n\n  vc<int> calc_suffix_array(const vc<int>& s) {\n   \
    \ vc<int> ss = s;\n    UNIQUE(ss);\n\n    vc<int> vect(s.size() + 1);\n    copy(all(s),\
    \ vect.begin());\n    for (auto& x: vect) x = LB(ss, x) + 1;\n    vect.back()\
    \ = 0;\n    auto ret = SA_IS(vect, MAX(vect) + 2);\n    ret.erase(ret.begin());\n\
    \    return ret;\n  }\n\n  template <typename STRING>\n  void calc_LCP(const STRING&\
    \ s) {\n    int n = s.size(), k = 0;\n    ISA.resize(n);\n    LCP.resize(n);\n\
    \    for (int i = 0; i < n; i++) ISA[SA[i]] = i;\n    for (int i = 0; i < n; i++,\
    \ k ? k-- : 0) {\n      if (ISA[i] == n - 1) {\n        k = 0;\n        continue;\n\
    \      }\n      int j = SA[ISA[i] + 1];\n      while (i + k < n && j + k < n &&\
    \ s[i + k] == s[j + k]) k++;\n      LCP[ISA[i]] = k;\n    }\n    LCP.resize(n\
    \ - 1);\n  }\n};\n#line 2 \"string/sort_substrings.hpp\"\n\n// dp[i][j]\uFF1A\
    S[i:i+j) \u306E rank\ntemplate <typename STRING>\nvvc<int> sort_substrings(STRING&\
    \ S, int max_len = -1) {\n  int n = len(S);\n  if (max_len == -1) max_len = n;\n\
    \  Suffix_Array sa(S);\n  auto& SA = sa.SA;\n  auto& LCP = sa.LCP;\n  int nxt\
    \ = 0;\n  vv(int, dp, n, max_len + 1, -1);\n  FOR(i, len(SA)) {\n    auto L =\
    \ SA[i];\n    FOR(k, 1, min(n - L, max_len) + 1) {\n      int R = L + k;\n   \
    \   if (i > 0 && LCP[i - 1] >= k)\n        dp[L][R - L] = dp[SA[i - 1]][k];\n\
    \      else\n        dp[L][R - L] = nxt++;\n    }\n  }\n  return dp;\n}\n"
  code: "#include \"string/suffix_array.hpp\"\n\n// dp[i][j]\uFF1AS[i:i+j) \u306E\
    \ rank\ntemplate <typename STRING>\nvvc<int> sort_substrings(STRING& S, int max_len\
    \ = -1) {\n  int n = len(S);\n  if (max_len == -1) max_len = n;\n  Suffix_Array\
    \ sa(S);\n  auto& SA = sa.SA;\n  auto& LCP = sa.LCP;\n  int nxt = 0;\n  vv(int,\
    \ dp, n, max_len + 1, -1);\n  FOR(i, len(SA)) {\n    auto L = SA[i];\n    FOR(k,\
    \ 1, min(n - L, max_len) + 1) {\n      int R = L + k;\n      if (i > 0 && LCP[i\
    \ - 1] >= k)\n        dp[L][R - L] = dp[SA[i - 1]][k];\n      else\n        dp[L][R\
    \ - L] = nxt++;\n    }\n  }\n  return dp;\n}"
  dependsOn:
  - string/suffix_array.hpp
  - alg/monoid/min.hpp
  - ds/sparse_table/sparse_table.hpp
  isVerificationFile: false
  path: string/sort_substrings.hpp
  requiredBy: []
  timestamp: '2023-10-29 23:53:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc240ex.test.cpp
documentation_of: string/sort_substrings.hpp
layout: document
redirect_from:
- /library/string/sort_substrings.hpp
- /library/string/sort_substrings.hpp.html
title: string/sort_substrings.hpp
---