---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/nth_element_from_sorted_lists.test.cpp
    title: test/mytest/nth_element_from_sorted_lists.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1275/problem/F
  bundledCode: "#line 1 \"convex/nth_element_from_sorted_lists.hpp\"\n\n// \u884C\u306E\
    \u8981\u7D20\u6570\u304C S[0], S[1], ..., S[N-1]\n// O(N(logN+logK)) time\n//\
    \ query num: O(NlogK), \u3042\u307E\u308A\u6700\u9069\u3058\u3083\u306A\u3044\u3068\
    \u601D\u3046\n// \u901A\u3063\u305F\u304C\u3042\u3084\u3057\u3044\u3063\u307D\u3044\
    : https://codeforces.com/contest/1275/problem/F\ntemplate <typename T, typename\
    \ F>\nvi nth_element_from_sorted_lists(vi S, ll K, F f, int k = 0) {\n  ll N =\
    \ len(S);\n  ll sm = 0;\n  for (auto& x: S) sm += x >> k;\n  assert(0 <= K &&\
    \ K <= sm);\n  if (K == 0) return vi(N, 0);\n  if (K == sm) return S;\n\n  ll\
    \ row = 0;\n  for (auto& x: S) row += (x >= (1LL << k));\n\n  auto g = [&](int\
    \ i, ll j) -> T {\n    j = ((j + 1) << k) - 1;\n    return (j >= S[i] ? infty<T>\
    \ : f(i, j));\n  };\n  vi A(N);\n  if (K > row) {\n    A = nth_element_from_sorted_lists<T>(S,\
    \ (K - row) / 2, f, k + 1);\n    for (auto& a: A) a *= 2;\n    K = K - (K - row)\
    \ / 2 * 2;\n  }\n  pqg<pair<T, int>> que;\n  FOR(i, N) que.emplace(g(i, A[i]),\
    \ i);\n  while (K) {\n    --K;\n    auto [x, i] = POP(que);\n    A[i]++;\n   \
    \ if (K) que.emplace(g(i, A[i]), i);\n  }\n  return A;\n}\n"
  code: "\n// \u884C\u306E\u8981\u7D20\u6570\u304C S[0], S[1], ..., S[N-1]\n// O(N(logN+logK))\
    \ time\n// query num: O(NlogK), \u3042\u307E\u308A\u6700\u9069\u3058\u3083\u306A\
    \u3044\u3068\u601D\u3046\n// \u901A\u3063\u305F\u304C\u3042\u3084\u3057\u3044\u3063\
    \u307D\u3044: https://codeforces.com/contest/1275/problem/F\ntemplate <typename\
    \ T, typename F>\nvi nth_element_from_sorted_lists(vi S, ll K, F f, int k = 0)\
    \ {\n  ll N = len(S);\n  ll sm = 0;\n  for (auto& x: S) sm += x >> k;\n  assert(0\
    \ <= K && K <= sm);\n  if (K == 0) return vi(N, 0);\n  if (K == sm) return S;\n\
    \n  ll row = 0;\n  for (auto& x: S) row += (x >= (1LL << k));\n\n  auto g = [&](int\
    \ i, ll j) -> T {\n    j = ((j + 1) << k) - 1;\n    return (j >= S[i] ? infty<T>\
    \ : f(i, j));\n  };\n  vi A(N);\n  if (K > row) {\n    A = nth_element_from_sorted_lists<T>(S,\
    \ (K - row) / 2, f, k + 1);\n    for (auto& a: A) a *= 2;\n    K = K - (K - row)\
    \ / 2 * 2;\n  }\n  pqg<pair<T, int>> que;\n  FOR(i, N) que.emplace(g(i, A[i]),\
    \ i);\n  while (K) {\n    --K;\n    auto [x, i] = POP(que);\n    A[i]++;\n   \
    \ if (K) que.emplace(g(i, A[i]), i);\n  }\n  return A;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/nth_element_from_sorted_lists.hpp
  requiredBy: []
  timestamp: '2024-07-24 14:39:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/nth_element_from_sorted_lists.test.cpp
documentation_of: convex/nth_element_from_sorted_lists.hpp
layout: document
redirect_from:
- /library/convex/nth_element_from_sorted_lists.hpp
- /library/convex/nth_element_from_sorted_lists.hpp.html
title: convex/nth_element_from_sorted_lists.hpp
---