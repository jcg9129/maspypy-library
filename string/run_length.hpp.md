---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/substring_abundant_string.hpp
    title: string/substring_abundant_string.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/run_length.test.cpp
    title: test/mytest/run_length.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/substring_abundant.test.cpp
    title: test/mytest/substring_abundant.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/run_length.hpp\"\ntemplate <typename STRING = string,\
    \ typename CHAR = char>\nvc<pair<CHAR, int>> run_length(STRING& S) {\n  vc<pair<CHAR,\
    \ int>> res;\n  for (auto&& x: S) {\n    if (res.empty() || res.back().fi != x)\
    \ { res.emplace_back(x, 0); }\n    res.back().se++;\n  }\n  return res;\n}\n"
  code: "template <typename STRING = string, typename CHAR = char>\nvc<pair<CHAR,\
    \ int>> run_length(STRING& S) {\n  vc<pair<CHAR, int>> res;\n  for (auto&& x:\
    \ S) {\n    if (res.empty() || res.back().fi != x) { res.emplace_back(x, 0); }\n\
    \    res.back().se++;\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/run_length.hpp
  requiredBy:
  - string/substring_abundant_string.hpp
  timestamp: '2022-07-20 17:24:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/substring_abundant.test.cpp
  - test/mytest/run_length.test.cpp
documentation_of: string/run_length.hpp
layout: document
redirect_from:
- /library/string/run_length.hpp
- /library/string/run_length.hpp.html
title: string/run_length.hpp
---