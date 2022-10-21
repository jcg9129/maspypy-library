---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/number_of_subsequences.test.cpp
    title: test/library_checker/string/number_of_subsequences.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/count_subseq.hpp\"\ntemplate <typename mint, typename\
    \ CHAR, typename STRING>\nmint count_subseq(STRING S) {\n  auto key = S;\n  UNIQUE(key);\n\
    \  for (auto&& x: S) x = LB(key, x);\n  vc<int> IDX(len(key), -1);\n  ll N = len(S);\n\
    \  vc<mint> DP(N + 1);\n  DP[0] = 1;\n  FOR(i, N) {\n    CHAR c = S[i];\n    DP[i\
    \ + 1] = DP[i] + DP[i];\n    if (IDX[c] != -1) { DP[i + 1] -= DP[IDX[c]]; }\n\
    \    IDX[c] = i;\n  }\n  return DP.back();\n}\n"
  code: "template <typename mint, typename CHAR, typename STRING>\nmint count_subseq(STRING\
    \ S) {\n  auto key = S;\n  UNIQUE(key);\n  for (auto&& x: S) x = LB(key, x);\n\
    \  vc<int> IDX(len(key), -1);\n  ll N = len(S);\n  vc<mint> DP(N + 1);\n  DP[0]\
    \ = 1;\n  FOR(i, N) {\n    CHAR c = S[i];\n    DP[i + 1] = DP[i] + DP[i];\n  \
    \  if (IDX[c] != -1) { DP[i + 1] -= DP[IDX[c]]; }\n    IDX[c] = i;\n  }\n  return\
    \ DP.back();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/count_subseq.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/number_of_subsequences.test.cpp
documentation_of: string/count_subseq.hpp
layout: document
redirect_from:
- /library/string/count_subseq.hpp
- /library/string/count_subseq.hpp.html
title: string/count_subseq.hpp
---
