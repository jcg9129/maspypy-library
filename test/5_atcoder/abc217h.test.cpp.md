---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convex/slope.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc217/tasks/abc217_h\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"convex/slope.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  Slope_Trick f(vi(N, 0), vi(N, 0));\n\n  ll pt\
    \ = 0;\n  FOR(N) {\n    LL(t, d, x);\n    ll dt = t - pt;\n    pt = t;\n    f.sliding_window_minimum(-dt,\
    \ dt);\n    if (d == 0) f.add_a_minus_x(x);\n    if (d == 1) f.add_x_minus_a(x);\n\
    \  }\n  auto [xl, xr, min_f] = f.get_min();\n  print(min_f);\n}\n\nsigned main()\
    \ {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/5_atcoder/abc217h.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/5_atcoder/abc217h.test.cpp
layout: document
redirect_from:
- /verify/test/5_atcoder/abc217h.test.cpp
- /verify/test/5_atcoder/abc217h.test.cpp.html
title: test/5_atcoder/abc217h.test.cpp
---
