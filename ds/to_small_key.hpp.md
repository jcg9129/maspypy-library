---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: ds/static_range_frequency.hpp
    title: ds/static_range_frequency.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/static_range_freq.test.cpp
    title: test/library_checker/datastructure/static_range_freq.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/static_range_frequency.test.cpp
    title: test/library_checker/datastructure/static_range_frequency.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/static_range_mode_query.test.cpp
    title: test/library_checker/datastructure/static_range_mode_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename\
    \ Val>\r\nstruct HashMap {\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32\
    \ n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2,\
    \ mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\
    \n  void clear() { build(0); }\r\n  int size() { return len(used) - cap; }\r\n\
    \r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i]\
    \ && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val&\
    \ operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\
    \n    if (!used[i]) { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\
    \n    int i = index(k);\r\n    return (used[i] ? val[i] : default_value);\r\n\
    \  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\n    return\
    \ used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename\
    \ F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i],\
    \ val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val>\
    \ val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64\
    \ FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 2 \"ds/to_small_key.hpp\"\n\
    \n// [30,10,20,30] -> [0,1,2,0] etc.\nstruct To_Small_Key {\n  int kind = 0;\n\
    \  HashMap<int> MP;\n\n  To_Small_Key(u32 n = 0) : MP(n) {}\n\n  void reserve(u32\
    \ n) { MP.build(n); }\n\n  int set_key(u64 x) {\n    if (!MP.count(x)) MP[x] =\
    \ kind++;\n    return MP[x];\n  }\n\n  int query(u64 x) { return MP.get(x, -1);\
    \ }\n};\n"
  code: "#include \"ds/hashmap.hpp\"\n\n// [30,10,20,30] -> [0,1,2,0] etc.\nstruct\
    \ To_Small_Key {\n  int kind = 0;\n  HashMap<int> MP;\n\n  To_Small_Key(u32 n\
    \ = 0) : MP(n) {}\n\n  void reserve(u32 n) { MP.build(n); }\n\n  int set_key(u64\
    \ x) {\n    if (!MP.count(x)) MP[x] = kind++;\n    return MP[x];\n  }\n\n  int\
    \ query(u64 x) { return MP.get(x, -1); }\n};"
  dependsOn:
  - ds/hashmap.hpp
  isVerificationFile: false
  path: ds/to_small_key.hpp
  requiredBy:
  - ds/static_range_frequency.hpp
  timestamp: '2024-01-28 16:26:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/static_range_freq.test.cpp
  - test/library_checker/datastructure/static_range_frequency.test.cpp
  - test/library_checker/datastructure/static_range_mode_query.test.cpp
documentation_of: ds/to_small_key.hpp
layout: document
redirect_from:
- /library/ds/to_small_key.hpp
- /library/ds/to_small_key.hpp.html
title: ds/to_small_key.hpp
---
