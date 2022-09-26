---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':question:'
    path: other/discrete_log.hpp
    title: other/discrete_log.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc270_g.test.cpp
    title: test/atcoder/abc270_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/associative_array_hashmap.test.cpp
    title: test/library_checker/datastructure/associative_array_hashmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1634.test.cpp
    title: test/yukicoder/1634.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1726.test.cpp
    title: test/yukicoder/1726.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/hashmap.hpp\"\ntemplate <typename Val, int LOG = 20>\r\
    \nstruct HashMapLL {\r\n  int N;\r\n  ll* keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\
    \n  bitset<1 << LOG> used;\r\n  const int shift;\r\n  const uint64_t r = 11995408973635179863ULL;\r\
    \n  HashMapLL()\r\n      : N(1 << LOG), keys(new ll[N]), vals(new Val[N]), shift(64\
    \ - __lg(N)) {}\r\n  int hash(ll x) {\r\n    static const uint64_t FIXED_RANDOM\r\
    \n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n \
    \   return (uint64_t(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ ll& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i] !=\
    \ key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ ll& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ bool contain(const ll& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  bool count(const ll& key) {\r\n    int i\
    \ = index(key);\r\n    return used[i] && keys[i] == key;\r\n  }\r\n\r\n  void\
    \ reset() {\r\n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\
    \n\r\n  vc<pair<ll, Val>> items() {\r\n    vc<pair<ll, Val>> res;\r\n    res.reserve(len(IDS));\r\
    \n    for (auto&& i: IDS) res.eb(keys[i], vals[i]);\r\n    return res;\r\n  }\r\
    \n};\r\n\r\ntemplate <typename KEY, typename VAL, int LOG>\r\nstruct HashMap {\r\
    \n  HashMapLL<VAL, LOG> MP;\r\n  function<ll(KEY)> f;\r\n  HashMap(function<ll(KEY)>\
    \ f) : MP(), f(f) {}\r\n\r\n  int index(const KEY& key) { return MP.index(f(key));\
    \ }\r\n\r\n  VAL& operator[](const KEY& key) { return MP[f(key)]; }\r\n\r\n  bool\
    \ contain(const KEY& key) { return MP.contain(f(key)); }\r\n\r\n  bool count(const\
    \ KEY& key) { return MP.count(f(key)); }\r\n\r\n  void reset() { MP.reset(); }\r\
    \n};\r\n"
  code: "#pragma once\r\ntemplate <typename Val, int LOG = 20>\r\nstruct HashMapLL\
    \ {\r\n  int N;\r\n  ll* keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\n  bitset<1\
    \ << LOG> used;\r\n  const int shift;\r\n  const uint64_t r = 11995408973635179863ULL;\r\
    \n  HashMapLL()\r\n      : N(1 << LOG), keys(new ll[N]), vals(new Val[N]), shift(64\
    \ - __lg(N)) {}\r\n  int hash(ll x) {\r\n    static const uint64_t FIXED_RANDOM\r\
    \n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n \
    \   return (uint64_t(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ ll& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i] !=\
    \ key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ ll& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ bool contain(const ll& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  bool count(const ll& key) {\r\n    int i\
    \ = index(key);\r\n    return used[i] && keys[i] == key;\r\n  }\r\n\r\n  void\
    \ reset() {\r\n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\
    \n\r\n  vc<pair<ll, Val>> items() {\r\n    vc<pair<ll, Val>> res;\r\n    res.reserve(len(IDS));\r\
    \n    for (auto&& i: IDS) res.eb(keys[i], vals[i]);\r\n    return res;\r\n  }\r\
    \n};\r\n\r\ntemplate <typename KEY, typename VAL, int LOG>\r\nstruct HashMap {\r\
    \n  HashMapLL<VAL, LOG> MP;\r\n  function<ll(KEY)> f;\r\n  HashMap(function<ll(KEY)>\
    \ f) : MP(), f(f) {}\r\n\r\n  int index(const KEY& key) { return MP.index(f(key));\
    \ }\r\n\r\n  VAL& operator[](const KEY& key) { return MP[f(key)]; }\r\n\r\n  bool\
    \ contain(const KEY& key) { return MP.contain(f(key)); }\r\n\r\n  bool count(const\
    \ KEY& key) { return MP.count(f(key)); }\r\n\r\n  void reset() { MP.reset(); }\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/hashmap.hpp
  requiredBy:
  - other/discrete_log.hpp
  - mod/mod_kth_root.hpp
  - mod/mod_log.hpp
  timestamp: '2022-09-24 23:41:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1339.test.cpp
  - test/yukicoder/1634.test.cpp
  - test/yukicoder/1726.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test/library_checker/math/kth_root_mod.test.cpp
  - test/library_checker/datastructure/associative_array_hashmap.test.cpp
  - test/atcoder/abc270_g.test.cpp
documentation_of: ds/hashmap.hpp
layout: document
redirect_from:
- /library/ds/hashmap.hpp
- /library/ds/hashmap.hpp.html
title: ds/hashmap.hpp
---
