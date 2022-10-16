---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid_min.hpp
    title: alg/monoid_min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/disjointsparse.hpp
    title: ds/disjointsparse.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffixarray.hpp
    title: string/suffixarray.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_min.hpp\"\ntemplate <class X>\r\nstruct Monoid_Min\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return min(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/disjointsparse.hpp\"\
    \n\r\ntemplate <class Monoid>\r\nstruct DisjointSparse {\r\n  using X = typename\
    \ Monoid::value_type;\r\n  using value_type = X;\r\n  int n, log;\r\n  vc<vc<X>>\
    \ dat;\r\n\r\n  DisjointSparse() {}\r\n  DisjointSparse(vc<X>& A) { build(A);\
    \ }\r\n\r\n  template <typename F>\r\n  DisjointSparse(int n, F f) {\r\n    vc<X>\
    \ A(n);\r\n    FOR(i, n) A[i] = f(i);\r\n    build(A);\r\n  }\r\n\r\n  void build(vc<X>&\
    \ A) {\r\n    n = len(A);\r\n    log = 1;\r\n    while ((1 << log) < n) ++log;\r\
    \n    dat.assign(log, A);\r\n\r\n    FOR(i, log) {\r\n      auto& v = dat[i];\r\
    \n      int b = 1 << i;\r\n      for (int m = b; m <= n; m += 2 * b) {\r\n   \
    \     int L = m - b, R = min(n, m + b);\r\n        FOR3_R(j, L + 1, m) v[j - 1]\
    \ = Monoid::op(v[j - 1], v[j]);\r\n        FOR3(j, m, R - 1) v[j + 1] = Monoid::op(v[j],\
    \ v[j + 1]);\r\n      }\r\n    }\r\n  }\r\n\r\n  X prod(int L, int R) {\r\n  \
    \  if (L == R) return Monoid::unit();\r\n    --R;\r\n    if (L == R) return dat[0][L];\r\
    \n    int k = 31 - __builtin_clz(L ^ R);\r\n    return Monoid::op(dat[k][L], dat[k][R]);\r\
    \n  }\r\n\r\n  template <class F>\r\n  int max_right(const F& check, int L) {\r\
    \n    assert(0 <= L && L <= n && check(Monoid::unit()));\r\n    if (L == n) return\
    \ n;\r\n    int ok = L, ng = n + 1;\r\n    while (ok + 1 < ng) {\r\n      int\
    \ k = (ok + ng) / 2;\r\n      if (check(prod(L, k))) {\r\n        ok = k;\r\n\
    \      } else {\r\n        ng = k;\r\n      }\r\n    }\r\n    return ok;\r\n \
    \ }\r\n\r\n  template <class F>\r\n  int min_left(const F& check, int R) {\r\n\
    \    assert(0 <= R && R <= n && check(Monoid::unit()));\r\n    if (R == 0) return\
    \ 0;\r\n    int ok = R, ng = -1;\r\n    while (ng + 1 < ok) {\r\n      int k =\
    \ (ok + ng) / 2;\r\n      if (check(prod(k, R))) {\r\n        ok = k;\r\n    \
    \  } else {\r\n        ng = k;\r\n      }\r\n    }\r\n    return ok;\r\n  }\r\n\
    \r\n  void debug() {\r\n    print(\"disjoint sparse table\");\r\n    FOR(i, log)\
    \ print(dat[i]);\r\n  }\r\n};\n#line 3 \"string/suffixarray.hpp\"\n\n// \u8F9E\
    \u66F8\u9806 i \u756A\u76EE\u306E suffix \u304C j \u6587\u5B57\u76EE\u59CB\u307E\
    \u308A\u3067\u3042\u308B\u3068\u304D\u3001\n// SA[i] = j, ISA[j] = i\nstruct SuffixArray\
    \ {\n  vector<int> SA;\n  vector<int> ISA;\n  vector<int> LCP;\n  bool build_ds;\n\
    \  DisjointSparse<Monoid_Min<int>> seg;\n\n  SuffixArray(string& s) : build_ds(0)\
    \ {\n    char first = 127, last = 0;\n    for (auto&& c: s) {\n      chmin(first,\
    \ c);\n      chmax(last, c);\n    }\n    SA = calc_suffix_array(s, first, last);\n\
    \    calc_LCP(s);\n  }\n\n  SuffixArray(vector<int>& s) : build_ds(0) {\n    SA\
    \ = calc_suffix_array(s);\n    calc_LCP(s);\n  }\n\n  // S[i:], S[j:] \u306E lcp\
    \ \u3092\u6C42\u3081\u308B\n  int lcp(int i, int j) {\n    int n = len(SA);\n\
    \    if (i == j) return n - i;\n    if (!build_ds) {\n      build_ds = 1;\n  \
    \    seg.build(LCP);\n    }\n    i = ISA[i], j = ISA[j];\n    if (i > j) swap(i,\
    \ j);\n    return seg.prod(i, j);\n  }\n\nprivate:\n  void induced_sort(const\
    \ std::vector<int>& vect, int val_range,\n                    std::vector<int>&\
    \ SA, const std::vector<bool>& sl,\n                    const std::vector<int>&\
    \ lms_idx) {\n    std::vector<int> l(val_range, 0), r(val_range, 0);\n    for\
    \ (int c: vect) {\n      if (c + 1 < val_range) ++l[c + 1];\n      ++r[c];\n \
    \   }\n    std::partial_sum(l.begin(), l.end(), l.begin());\n    std::partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    std::fill(SA.begin(), SA.end(), -1);\n    for (int\
    \ i = (int)lms_idx.size() - 1; i >= 0; --i)\n      SA[--r[vect[lms_idx[i]]]] =\
    \ lms_idx[i];\n    for (int i: SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i\
    \ - 1]]++] = i - 1;\n    std::fill(r.begin(), r.end(), 0);\n    for (int c: vect)\
    \ ++r[c];\n    std::partial_sum(r.begin(), r.end(), r.begin());\n    for (int\
    \ k = (int)SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])\n      if (i >= 1\
    \ && !sl[i - 1]) { SA[--r[vect[i - 1]]] = i - 1; }\n  }\n\n  std::vector<int>\
    \ SA_IS(const std::vector<int>& vect, int val_range) {\n    const int n = vect.size();\n\
    \    std::vector<int> SA(n), lms_idx;\n    std::vector<bool> sl(n);\n    sl[n\
    \ - 1] = false;\n    for (int i = n - 2; i >= 0; --i) {\n      sl[i] = (vect[i]\
    \ > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));\n      if (sl[i] &&\
    \ !sl[i + 1]) lms_idx.push_back(i + 1);\n    }\n    std::reverse(lms_idx.begin(),\
    \ lms_idx.end());\n    induced_sort(vect, val_range, SA, sl, lms_idx);\n    std::vector<int>\
    \ new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());\n    for (int i = 0, k\
    \ = 0; i < n; ++i)\n      if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {\n \
    \       new_lms_idx[k++] = SA[i];\n      }\n    int cur = 0;\n    SA[n - 1] =\
    \ cur;\n    for (size_t k = 1; k < new_lms_idx.size(); ++k) {\n      int i = new_lms_idx[k\
    \ - 1], j = new_lms_idx[k];\n      if (vect[i] != vect[j]) {\n        SA[j] =\
    \ ++cur;\n        continue;\n      }\n      bool flag = false;\n      for (int\
    \ a = i + 1, b = j + 1;; ++a, ++b) {\n        if (vect[a] != vect[b]) {\n    \
    \      flag = true;\n          break;\n        }\n        if ((!sl[a] && sl[a\
    \ - 1]) || (!sl[b] && sl[b - 1])) {\n          flag = !((!sl[a] && sl[a - 1])\
    \ && (!sl[b] && sl[b - 1]));\n          break;\n        }\n      }\n      SA[j]\
    \ = (flag ? ++cur : cur);\n    }\n    for (size_t i = 0; i < lms_idx.size(); ++i)\
    \ lms_vec[i] = SA[lms_idx[i]];\n    if (cur + 1 < (int)lms_idx.size()) {\n   \
    \   auto lms_SA = SA_IS(lms_vec, cur + 1);\n      for (size_t i = 0; i < lms_idx.size();\
    \ ++i) {\n        new_lms_idx[i] = lms_idx[lms_SA[i]];\n      }\n    }\n    induced_sort(vect,\
    \ val_range, SA, sl, new_lms_idx);\n    return SA;\n  }\n\n  std::vector<int>\
    \ calc_suffix_array(const std::string& s,\n                                  \
    \   const char first = 'a',\n                                     const char last\
    \ = 'z') {\n    std::vector<int> vect(s.size() + 1);\n    std::copy(std::begin(s),\
    \ std::end(s), std::begin(vect));\n    for (auto& x: vect) x -= (int)first - 1;\n\
    \    vect.back() = 0;\n    auto ret = SA_IS(vect, (int)last - (int)first + 2);\n\
    \    ret.erase(ret.begin());\n    return ret;\n  }\n\n  std::vector<int> calc_suffix_array(const\
    \ vector<int>& s) {\n    vector<int> ss = s;\n    sort(ss.begin(), ss.end());\n\
    \    ss.erase(unique(ss.begin(), ss.end()), ss.end());\n\n    std::vector<int>\
    \ vect(s.size() + 1);\n    std::copy(std::begin(s), std::end(s), std::begin(vect));\n\
    \    for (auto& x: vect)\n      x = lower_bound(ss.begin(), ss.end(), x) - ss.begin()\
    \ + 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect, *max_element(vect.begin(),\
    \ vect.end()) + 2);\n    ret.erase(ret.begin());\n    return ret;\n  }\n\n  template\
    \ <typename STRING>\n  void calc_LCP(const STRING& s) {\n    int n = s.size(),\
    \ k = 0;\n    ISA.resize(n);\n    LCP.resize(n);\n    for (int i = 0; i < n; i++)\
    \ ISA[SA[i]] = i;\n    for (int i = 0; i < n; i++, k ? k-- : 0) {\n      if (ISA[i]\
    \ == n - 1) {\n        k = 0;\n        continue;\n      }\n      int j = SA[ISA[i]\
    \ + 1];\n      while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;\n \
    \     LCP[ISA[i]] = k;\n    }\n    LCP.resize(n - 1);\n  }\n};\n#line 2 \"string/sort_all_substring.hpp\"\
    \n\n/*\ndp[l][r] := S[l:r] \u304C\u6607\u9806\u3067\u4F55\u756A\u76EE\u304B\uFF1F\
    \u3068\u3044\u3046\u30C6\u30FC\u30D6\u30EB\u3092\u8FD4\u3059\u3002\nO(N^2)\n*/\n\
    template <typename STRING>\nvc<vc<int>> sort_all_substring(STRING S) {\n  int\
    \ n = len(S);\n  SuffixArray sa(S);\n  auto& SA = sa.SA;\n  auto& LCP = sa.LCP;\n\
    \  int nxt = 0;\n  vv(int, DP, n, n + 1, -1);\n  FOR(i, len(SA)) {\n    auto L\
    \ = SA[i];\n    FOR3(k, 1, n - L + 1) {\n      int R = L + k;\n      if (i > 0\
    \ && LCP[i - 1] >= k)\n        DP[L][R] = DP[SA[i - 1]][SA[i - 1] + k];\n    \
    \  else\n        DP[L][R] = nxt++;\n    }\n  }\n  return DP;\n}\n\n// \u9577\u3055\
    \u306E\u4E0A\u9650\u3042\u308A\n// (\u958B\u59CB\u4F4D\u7F6E\u3001\u9577\u3055\
    ) \u306B\u5BFE\u3057\u3066\u30BD\u30FC\u30C8\u9806\u3092\u57CB\u3081\u308B\ntemplate\
    \ <typename STRING>\nvc<vc<int>> sort_all_substring_limit(STRING S, ll LIM) {\n\
    \  int n = len(S);\n  SuffixArray sa(S);\n  auto& SA = sa.SA;\n  auto& LCP = sa.LCP;\n\
    \  int nxt = 0;\n  vv(int, DP, n, LIM + 1, -1);\n  FOR(i, len(SA)) {\n    auto\
    \ L = SA[i];\n    FOR3(k, 1, min(n - L, LIM) + 1) {\n      int R = L + k;\n  \
    \    if (i > 0 && LCP[i - 1] >= k)\n        DP[L][R - L] = DP[SA[i - 1]][k];\n\
    \      else\n        DP[L][R - L] = nxt++;\n    }\n  }\n  return DP;\n}\n"
  code: "#include \"string/suffixarray.hpp\"\n\n/*\ndp[l][r] := S[l:r] \u304C\u6607\
    \u9806\u3067\u4F55\u756A\u76EE\u304B\uFF1F\u3068\u3044\u3046\u30C6\u30FC\u30D6\
    \u30EB\u3092\u8FD4\u3059\u3002\nO(N^2)\n*/\ntemplate <typename STRING>\nvc<vc<int>>\
    \ sort_all_substring(STRING S) {\n  int n = len(S);\n  SuffixArray sa(S);\n  auto&\
    \ SA = sa.SA;\n  auto& LCP = sa.LCP;\n  int nxt = 0;\n  vv(int, DP, n, n + 1,\
    \ -1);\n  FOR(i, len(SA)) {\n    auto L = SA[i];\n    FOR3(k, 1, n - L + 1) {\n\
    \      int R = L + k;\n      if (i > 0 && LCP[i - 1] >= k)\n        DP[L][R] =\
    \ DP[SA[i - 1]][SA[i - 1] + k];\n      else\n        DP[L][R] = nxt++;\n    }\n\
    \  }\n  return DP;\n}\n\n// \u9577\u3055\u306E\u4E0A\u9650\u3042\u308A\n// (\u958B\
    \u59CB\u4F4D\u7F6E\u3001\u9577\u3055) \u306B\u5BFE\u3057\u3066\u30BD\u30FC\u30C8\
    \u9806\u3092\u57CB\u3081\u308B\ntemplate <typename STRING>\nvc<vc<int>> sort_all_substring_limit(STRING\
    \ S, ll LIM) {\n  int n = len(S);\n  SuffixArray sa(S);\n  auto& SA = sa.SA;\n\
    \  auto& LCP = sa.LCP;\n  int nxt = 0;\n  vv(int, DP, n, LIM + 1, -1);\n  FOR(i,\
    \ len(SA)) {\n    auto L = SA[i];\n    FOR3(k, 1, min(n - L, LIM) + 1) {\n   \
    \   int R = L + k;\n      if (i > 0 && LCP[i - 1] >= k)\n        DP[L][R - L]\
    \ = DP[SA[i - 1]][k];\n      else\n        DP[L][R - L] = nxt++;\n    }\n  }\n\
    \  return DP;\n}"
  dependsOn:
  - string/suffixarray.hpp
  - alg/monoid_min.hpp
  - ds/disjointsparse.hpp
  isVerificationFile: false
  path: string/sort_all_substring.hpp
  requiredBy: []
  timestamp: '2022-09-27 04:46:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/sort_all_substring.hpp
layout: document
redirect_from:
- /library/string/sort_all_substring.hpp
- /library/string/sort_all_substring.hpp.html
title: string/sort_all_substring.hpp
---
