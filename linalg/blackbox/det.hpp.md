---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linalg/blackbox/min_poly.hpp
    title: linalg/blackbox/min_poly.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':x:'
    path: seq/find_linear_rec.hpp
    title: seq/find_linear_rec.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/count/BEST.hpp
    title: graph/count/BEST.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/matrix/sparse_matrix_det.test.cpp
    title: test/library_checker/matrix/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/yukicoder/310.test.cpp
    title: test/yukicoder/310.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"seq/find_linear_rec.hpp\"\n\r\ntemplate <typename mint>\r\
    \nvector<mint> find_linear_rec(vector<mint>& A) {\r\n  int N = len(A);\r\n  vc<mint>\
    \ B = {1}, C = {1};\r\n  int l = 0, m = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\
    \n    mint d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }\r\n  \
    \  if (d == 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\n    auto tmp = C;\r\
    \n    mint q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(), len(B)\
    \ + m - len(C), 0);\r\n    FOR(j, len(B)) C[j + m] -= q * B[j];\r\n    if (l +\
    \ l <= i) {\r\n      B = tmp;\r\n      l = i + 1 - l, m = 1;\r\n      p = d;\r\
    \n    } else {\r\n      ++m;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n#line 2 \"\
    random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"linalg/blackbox/min_poly.hpp\"\
    \n\r\n// \u884C\u5217 A \u3092\u304B\u3051\u308B\u3053\u3068\u3092\u8868\u3059\
    \u7DDA\u5F62\u5909\u63DB f \u3092\u6E21\u3059\r\n// auto f = [&](vc<mint> v) ->\
    \ vc<mint> {};\r\ntemplate <typename mint, typename F>\r\nvc<mint> blackbox_min_poly(int\
    \ N, F f) {\r\n  vc<mint> S(N + N + 10);\r\n  vc<mint> c(N);\r\n  vc<mint> v(N);\r\
    \n  FOR(i, N) c[i] = RNG(0, mint::get_mod());\r\n  FOR(i, N) v[i] = RNG(0, mint::get_mod());\r\
    \n  FOR(k, N + N + 10) {\r\n    FOR(i, N) S[k] += c[i] * v[i];\r\n    v = f(v);\r\
    \n  }\r\n  S = find_linear_rec(S);\r\n  reverse(all(S));\r\n  return S;\r\n}\r\
    \n#line 2 \"linalg/blackbox/det.hpp\"\n\r\ntemplate <typename mint, typename F>\r\
    \nmint blackbox_det(int N, F apply) {\r\n  vc<mint> c(N);\r\n  FOR(i, N) c[i]\
    \ = RNG(1, mint::get_mod());\r\n  mint r = 1;\r\n  FOR(i, N) r *= c[i];\r\n  auto\
    \ g = [&](vc<mint> v) -> vc<mint> {\r\n    FOR(i, N) v[i] *= c[i];\r\n    return\
    \ apply(v);\r\n  };\r\n  auto f = blackbox_min_poly<mint>(N, g);\r\n  mint det\
    \ = (len(f) == N + 1 ? f[0] : mint(0));\r\n  if (N & 1) det *= -1;\r\n  det /=\
    \ r;\r\n  return det;\r\n}\r\n"
  code: "#include \"linalg/blackbox/min_poly.hpp\"\r\n\r\ntemplate <typename mint,\
    \ typename F>\r\nmint blackbox_det(int N, F apply) {\r\n  vc<mint> c(N);\r\n \
    \ FOR(i, N) c[i] = RNG(1, mint::get_mod());\r\n  mint r = 1;\r\n  FOR(i, N) r\
    \ *= c[i];\r\n  auto g = [&](vc<mint> v) -> vc<mint> {\r\n    FOR(i, N) v[i] *=\
    \ c[i];\r\n    return apply(v);\r\n  };\r\n  auto f = blackbox_min_poly<mint>(N,\
    \ g);\r\n  mint det = (len(f) == N + 1 ? f[0] : mint(0));\r\n  if (N & 1) det\
    \ *= -1;\r\n  det /= r;\r\n  return det;\r\n}\r\n"
  dependsOn:
  - linalg/blackbox/min_poly.hpp
  - seq/find_linear_rec.hpp
  - random/base.hpp
  isVerificationFile: false
  path: linalg/blackbox/det.hpp
  requiredBy:
  - graph/count/BEST.hpp
  timestamp: '2024-01-21 23:24:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/matrix/sparse_matrix_det.test.cpp
  - test/yukicoder/310.test.cpp
documentation_of: linalg/blackbox/det.hpp
layout: document
redirect_from:
- /library/linalg/blackbox/det.hpp
- /library/linalg/blackbox/det.hpp.html
title: linalg/blackbox/det.hpp
---