---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/pds/rollbackarray.hpp\"\n\r\ntemplate <typename T>\r\n\
    struct RollbackArray {\r\n  int N;\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\
    \n\r\n  RollbackArray(vc<T> x) : N(len(x)), dat(x) {}\r\n\r\n  int time() { return\
    \ len(history); }\r\n  void rollback(int t) {\r\n    FOR_R(i, t, time()) {\r\n\
    \      auto& [idx, v] = history[i];\r\n      dat[idx] = v;\r\n    }\r\n    history.resize(t);\r\
    \n  }\r\n  T get(int idx) { return dat[idx]; }\r\n  void set(int idx, T x) {\r\
    \n    history.eb(idx, dat[idx]);\r\n    dat[idx] = x;\r\n  }\r\n\r\n  vc<T> get_all()\
    \ {\r\n    vc<T> res(N);\r\n    FOR(i, N) res[i] = get(i);\r\n    return res;\r\
    \n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nstruct RollbackArray {\r\n \
    \ int N;\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\n\r\n  RollbackArray(vc<T>\
    \ x) : N(len(x)), dat(x) {}\r\n\r\n  int time() { return len(history); }\r\n \
    \ void rollback(int t) {\r\n    FOR_R(i, t, time()) {\r\n      auto& [idx, v]\
    \ = history[i];\r\n      dat[idx] = v;\r\n    }\r\n    history.resize(t);\r\n\
    \  }\r\n  T get(int idx) { return dat[idx]; }\r\n  void set(int idx, T x) {\r\n\
    \    history.eb(idx, dat[idx]);\r\n    dat[idx] = x;\r\n  }\r\n\r\n  vc<T> get_all()\
    \ {\r\n    vc<T> res(N);\r\n    FOR(i, N) res[i] = get(i);\r\n    return res;\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/pds/rollbackarray.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/pds/rollbackarray.hpp
layout: document
redirect_from:
- /library/ds/pds/rollbackarray.hpp
- /library/ds/pds/rollbackarray.hpp.html
title: ds/pds/rollbackarray.hpp
---
