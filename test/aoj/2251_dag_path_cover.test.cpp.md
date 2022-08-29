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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/degree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2251\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/dijkstra.hpp\"\
    \n#include \"graph/dag_path_cover.hpp\"\n\nvoid solve(ll N, ll M, ll L) {\n  vv(ll,\
    \ dist, N, N);\n  {\n    Graph<ll> G(N);\n    G.read_graph(M, 1, 0);\n    const\
    \ ll INF = 1LL << 60;\n    FOR(v, N) { dist[v] = dijkstra<ll>(G, v, INF).fi; }\n\
    \  }\n  VEC(pi, PT, L);\n  N = L;\n  Graph<int, 1> G(N);\n  FOR(a, N) FOR(b, N)\
    \ {\n    if (a == b) continue;\n    auto [pa, ta] = PT[a];\n    auto [pb, tb]\
    \ = PT[b];\n    if (ta + dist[pa][pb] <= tb) G.add(a, b);\n  }\n  G.build();\n\
    \  auto paths = dag_path_cover(G);\n  print(len(paths));\n}\n\nsigned main() {\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  while (1) {\n    LL(N, M, L);\n    if (N + M + L == 0) break;\n    solve(N,\
    \ M, L);\n  }\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/2251_dag_path_cover.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/2251_dag_path_cover.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2251_dag_path_cover.test.cpp
- /verify/test/aoj/2251_dag_path_cover.test.cpp.html
title: test/aoj/2251_dag_path_cover.test.cpp
---
