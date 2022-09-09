---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mod/floor_sum_of_linear.hpp
    title: mod/floor_sum_of_linear.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/mod_sum_of_linear.test.cpp
    title: test/mytest/mod_sum_of_linear.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/floor_sum_of_linear.hpp\"\n\n// sum_{x in [L,R)} floor(ax\
    \ + b, mod)\ni128 floor_sum_of_linear(ll L, ll R, ll a, ll b, ll mod) {\n  assert(L\
    \ <= R);\n  i128 res = 0;\n  b += L * a;\n  ll N = R - L;\n  while (N) {\n   \
    \ ll q;\n    tie(q, a) = divmod(a, mod);\n    res += i128(N) * (N - 1) / 2 * q;\n\
    \    tie(q, b) = divmod(b, mod);\n    res += i128(N) * q;\n    tie(N, b) = divmod(a\
    \ * N + b, mod);\n    tie(a, mod) = mp(mod, a);\n  }\n  return res;\n}\n#line\
    \ 2 \"mod/mod_sum_of_linear.hpp\"\n\ni128 mod_sum_of_linear(ll L, ll R, ll a,\
    \ ll b, ll mod) {\n  /*\n  sum_{x in [L,R)} (ax + b mod mod)\n  */\n  i128 s =\
    \ a * L + b;\n  i128 t = a * (R - 1) + b;\n  i128 sum = (s + t) * (R - L) / 2;\n\
    \  i128 fsum = floor_sum_of_linear(L, R, a, b, mod);\n  return sum - fsum * mod;\n\
    }\n"
  code: "#include \"mod/floor_sum_of_linear.hpp\"\n\ni128 mod_sum_of_linear(ll L,\
    \ ll R, ll a, ll b, ll mod) {\n  /*\n  sum_{x in [L,R)} (ax + b mod mod)\n  */\n\
    \  i128 s = a * L + b;\n  i128 t = a * (R - 1) + b;\n  i128 sum = (s + t) * (R\
    \ - L) / 2;\n  i128 fsum = floor_sum_of_linear(L, R, a, b, mod);\n  return sum\
    \ - fsum * mod;\n}\n"
  dependsOn:
  - mod/floor_sum_of_linear.hpp
  isVerificationFile: false
  path: mod/mod_sum_of_linear.hpp
  requiredBy: []
  timestamp: '2022-07-23 00:12:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/mod_sum_of_linear.test.cpp
documentation_of: mod/mod_sum_of_linear.hpp
layout: document
redirect_from:
- /library/mod/mod_sum_of_linear.hpp
- /library/mod/mod_sum_of_linear.hpp.html
title: mod/mod_sum_of_linear.hpp
---
