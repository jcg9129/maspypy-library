---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: seq/coef_of_rational_fps.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1844\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"mod/modint.hpp\"\n#include \"seq/interpolate_linear_rec.hpp\"\
    \n\nusing mint = modint107;\n\nvoid solve() {\n  LL(N);\n  mint ANS = 1;\n  FOR(N)\
    \ {\n    LL(p, e);\n    vc<mint> A(10);\n    FOR(i, 10) A[i] = mint(p).pow(i);\n\
    \    A = cumsum(A, 0);\n    A = cumsum(A, 0);\n    mint x = interpolate_linear_rec<mint>(A,\
    \ e, 0);\n    ANS *= x;\n  }\n  print(ANS);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  ll T = 1;\n\
    \  // LL(T);\n  FOR(_, T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yukicoder/1844_interpolate_c_rec.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/1844_interpolate_c_rec.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1844_interpolate_c_rec.test.cpp
- /verify/test/yukicoder/1844_interpolate_c_rec.test.cpp.html
title: test/yukicoder/1844_interpolate_c_rec.test.cpp
---
