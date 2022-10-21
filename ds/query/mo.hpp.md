---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/query/mo.hpp\"\nstruct Mo {\r\n  vector<pair<int, int>\
    \ > lr;\r\n\r\n  void add(int l, int r) { /* [l, r) */\r\n    lr.emplace_back(l,\
    \ r);\r\n  }\r\n\r\n  template <typename AL, typename AR, typename EL, typename\
    \ ER, typename O>\r\n  void calc(const AL &add_left, const AR &add_right, const\
    \ EL &erase_left,\r\n            const ER &erase_right, const O &query) {\r\n\
    \    int n = 1;\r\n    for (auto &&[l, r]: lr) chmax(n, r);\r\n    int q = (int)lr.size();\r\
    \n    int bs = n / min<int>(n, sqrt(q));\r\n    vector<int> ord(q);\r\n    iota(begin(ord),\
    \ end(ord), 0);\r\n    sort(begin(ord), end(ord), [&](int a, int b) {\r\n    \
    \  int ablock = lr[a].first / bs, bblock = lr[b].first / bs;\r\n      if (ablock\
    \ != bblock) return ablock < bblock;\r\n      return (ablock & 1) ? lr[a].second\
    \ > lr[b].second\r\n                          : lr[a].second < lr[b].second;\r\
    \n    });\r\n    int l = 0, r = 0;\r\n    for (auto idx: ord) {\r\n      while\
    \ (l > lr[idx].first) add_left(--l);\r\n      while (r < lr[idx].second) add_right(r++);\r\
    \n      while (l < lr[idx].first) erase_left(l++);\r\n      while (r > lr[idx].second)\
    \ erase_right(--r);\r\n      query(idx);\r\n    }\r\n  }\r\n\r\n  template <typename\
    \ A, typename E, typename O>\r\n  void calc(const A &add, const E &erase, const\
    \ O &query) {\r\n    calc(add, add, erase, erase, query);\r\n  }\r\n};\n"
  code: "struct Mo {\r\n  vector<pair<int, int> > lr;\r\n\r\n  void add(int l, int\
    \ r) { /* [l, r) */\r\n    lr.emplace_back(l, r);\r\n  }\r\n\r\n  template <typename\
    \ AL, typename AR, typename EL, typename ER, typename O>\r\n  void calc(const\
    \ AL &add_left, const AR &add_right, const EL &erase_left,\r\n            const\
    \ ER &erase_right, const O &query) {\r\n    int n = 1;\r\n    for (auto &&[l,\
    \ r]: lr) chmax(n, r);\r\n    int q = (int)lr.size();\r\n    int bs = n / min<int>(n,\
    \ sqrt(q));\r\n    vector<int> ord(q);\r\n    iota(begin(ord), end(ord), 0);\r\
    \n    sort(begin(ord), end(ord), [&](int a, int b) {\r\n      int ablock = lr[a].first\
    \ / bs, bblock = lr[b].first / bs;\r\n      if (ablock != bblock) return ablock\
    \ < bblock;\r\n      return (ablock & 1) ? lr[a].second > lr[b].second\r\n   \
    \                       : lr[a].second < lr[b].second;\r\n    });\r\n    int l\
    \ = 0, r = 0;\r\n    for (auto idx: ord) {\r\n      while (l > lr[idx].first)\
    \ add_left(--l);\r\n      while (r < lr[idx].second) add_right(r++);\r\n     \
    \ while (l < lr[idx].first) erase_left(l++);\r\n      while (r > lr[idx].second)\
    \ erase_right(--r);\r\n      query(idx);\r\n    }\r\n  }\r\n\r\n  template <typename\
    \ A, typename E, typename O>\r\n  void calc(const A &add, const E &erase, const\
    \ O &query) {\r\n    calc(add, add, erase, erase, query);\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/query/mo.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:08:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1270.test.cpp
documentation_of: ds/query/mo.hpp
layout: document
redirect_from:
- /library/ds/query/mo.hpp
- /library/ds/query/mo.hpp.html
title: ds/query/mo.hpp
---
