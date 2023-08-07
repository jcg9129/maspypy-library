---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/maxplus_convolution_concave.hpp
    title: convex/maxplus_convolution_concave.hpp
  - icon: ':x:'
    path: convex/minplus_convolution_convex.hpp
    title: convex/minplus_convolution_convex.hpp
  - icon: ':x:'
    path: convex/minplus_convolution_of_triples.hpp
    title: convex/minplus_convolution_of_triples.hpp
  - icon: ':x:'
    path: convex/monge.hpp
    title: convex/monge.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/maxplus_concave.test.cpp
    title: test/mytest/maxplus_concave.test.cpp
  - icon: ':x:'
    path: test/mytest/minplus_conv_triple.test.cpp
    title: test/mytest/minplus_conv_triple.test.cpp
  - icon: ':x:'
    path: test/mytest/minplus_convex.test.cpp
    title: test/mytest/minplus_convex.test.cpp
  - icon: ':x:'
    path: test/mytest/smawk.test.cpp
    title: test/mytest/smawk.test.cpp
  - icon: ':x:'
    path: test/yukicoder/705.test.cpp
    title: test/yukicoder/705.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/smawk.hpp\"\n// select(i,j,k) \u306F (i,j) \u3068\
    \ (i,k) \u306E\u3046\u3061\u9078\u3076\u65B9\uFF08j or k\uFF09\ntemplate <typename\
    \ F>\nvc<int> SMAWK(int H, int W, F select) {\n  auto dfs = [&](auto& dfs, vc<int>\
    \ X, vc<int> Y) -> vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n\
    \    vc<int> YY;\n    for (auto&& y: Y) {\n      while (len(YY)) {\n        int\
    \ py = YY.back(), x = X[len(YY) - 1];\n        if (select(x, py, y) == py) break;\n\
    \        YY.pop_back();\n      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n\
    \    vc<int> XX;\n    FOR(i, 1, len(X), 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs,\
    \ XX, YY);\n    vc<int> I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n   \
    \ int p = 0;\n    FOR(i, 0, N, 2) {\n      int LIM = (i + 1 == N ? Y.back() :\
    \ I[i + 1]);\n      int best = Y[p];\n      while (Y[p] < LIM) {\n        ++p;\n\
    \        best = select(X[i], best, Y[p]);\n      }\n      I[i] = best;\n    }\n\
    \    return I;\n  };\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n\
    \  return dfs(dfs, X, Y);\n}\n"
  code: "#pragma once\n// select(i,j,k) \u306F (i,j) \u3068 (i,k) \u306E\u3046\u3061\
    \u9078\u3076\u65B9\uFF08j or k\uFF09\ntemplate <typename F>\nvc<int> SMAWK(int\
    \ H, int W, F select) {\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int> Y) ->\
    \ vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n    vc<int> YY;\n\
    \    for (auto&& y: Y) {\n      while (len(YY)) {\n        int py = YY.back(),\
    \ x = X[len(YY) - 1];\n        if (select(x, py, y) == py) break;\n        YY.pop_back();\n\
    \      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n    vc<int> XX;\n    FOR(i,\
    \ 1, len(X), 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs, XX, YY);\n    vc<int>\
    \ I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n    int p = 0;\n    FOR(i,\
    \ 0, N, 2) {\n      int LIM = (i + 1 == N ? Y.back() : I[i + 1]);\n      int best\
    \ = Y[p];\n      while (Y[p] < LIM) {\n        ++p;\n        best = select(X[i],\
    \ best, Y[p]);\n      }\n      I[i] = best;\n    }\n    return I;\n  };\n  vc<int>\
    \ X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n  return dfs(dfs, X, Y);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: convex/smawk.hpp
  requiredBy:
  - convex/minplus_convolution_of_triples.hpp
  - convex/minplus_convolution_convex.hpp
  - convex/maxplus_convolution_concave.hpp
  - convex/monge.hpp
  timestamp: '2023-02-12 02:05:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/minplus_conv_triple.test.cpp
  - test/mytest/maxplus_concave.test.cpp
  - test/mytest/minplus_convex.test.cpp
  - test/mytest/smawk.test.cpp
  - test/yukicoder/705.test.cpp
documentation_of: convex/smawk.hpp
layout: document
redirect_from:
- /library/convex/smawk.hpp
- /library/convex/smawk.hpp.html
title: convex/smawk.hpp
---
