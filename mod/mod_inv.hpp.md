---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':x:'
    path: test/yukicoder/981_mod_kth_root.test.cpp
    title: test/yukicoder/981_mod_kth_root.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/mod_inv.hpp\"\n// long \u3067\u3082\u5927\u4E08\u592B\
    \r\nll mod_inv(ll val, ll mod) {\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n\
    \  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t *\
    \ v, v);\r\n  }\r\n  if(u < 0) u += mod;\r\n  return u;\r\n}\r\n"
  code: "// long \u3067\u3082\u5927\u4E08\u592B\r\nll mod_inv(ll val, ll mod) {\r\n\
    \  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\
    \n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if(u < 0) u += mod;\r\
    \n  return u;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/mod_inv.hpp
  requiredBy:
  - mod/mod_kth_root.hpp
  timestamp: '2022-04-27 05:05:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/981_mod_kth_root.test.cpp
  - test/library_checker/math/kth_root_mod.test.cpp
documentation_of: mod/mod_inv.hpp
layout: document
redirect_from:
- /library/mod/mod_inv.hpp
- /library/mod/mod_inv.hpp.html
title: mod/mod_inv.hpp
---
