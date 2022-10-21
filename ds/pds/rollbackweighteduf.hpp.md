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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: pds/rollbackarray.hpp:\
    \ line -1: no such header\n"
  code: "#include \"pds/rollbackarray.hpp\"\n\ntemplate <typename Group>\nstruct RollbackWeightedUF\
    \ {\n  using E = typename Group::value_type;\n  using P = pair<int, E>;\n  RollbackArray<P>\
    \ dat; // parent or size\n\n  RollbackWeightedUF(int n) : dat(vc<P>(n, P(-1, Group::unit())))\
    \ {}\n\n  P get(int v) {\n    // \u7D4C\u8DEF\u5727\u7E2E\u306F\u3057\u306A\u3044\
    \u3088\u3046\u306B\n    E val = Group::unit();\n    while (1) {\n      auto [p,\
    \ x] = dat.get(v);\n      if (p < 0) { break; }\n      val = Group::op(x, val);\n\
    \      v = p;\n    }\n    return {v, val};\n  }\n\n  int time() { return dat.time();\
    \ }\n  void rollback(int t) { dat.rollback(t); }\n\n  bool merge(int a, int b,\
    \ E x) {\n    auto [v1, x1] = get(a);\n    auto [v2, x2] = get(b);\n    if (v1\
    \ == v2) return false;\n    int s1 = -dat.get(v1).fi;\n    int s2 = -dat.get(v2).fi;\n\
    \    if (s1 < s2) {\n      swap(s1, s2), swap(v1, v2), swap(x1, x2);\n      x\
    \ = Group::inverse(x);\n    }\n    // v1 <- v2\n    x = Group::op(x1, x);\n  \
    \  x = Group::op(x, Group::inverse(x2));\n    dat.set(v2, P({v1, x}));\n    dat.set(v1,\
    \ P({-(s1 + s2), Group::unit()}));\n    return true;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/pds/rollbackweighteduf.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/pds/rollbackweighteduf.hpp
layout: document
redirect_from:
- /library/ds/pds/rollbackweighteduf.hpp
- /library/ds/pds/rollbackweighteduf.hpp.html
title: ds/pds/rollbackweighteduf.hpp
---
