---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ITP1_9_A.test.cpp
    title: test/aoj/ITP1_9_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/io2.hpp\"\n#define INT(...)   \\\r\n  int __VA_ARGS__;\
    \ \\\r\n  IN(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n\
    \  IN(__VA_ARGS__)\r\n#define STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n\
    \  IN(__VA_ARGS__)\r\n#define CHR(...)    \\\r\n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\
    \n#define DBL(...)           \\\r\n  long double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\
    \n\r\n#define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n\
    \  read(name)\r\n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid read(int &a) { cin\
    \ >> a; }\r\nvoid read(long long &a) { cin >> a; }\r\nvoid read(char &a) { cin\
    \ >> a; }\r\nvoid read(double &a) { cin >> a; }\r\nvoid read(long double &a) {\
    \ cin >> a; }\r\nvoid read(string &a) { cin >> a; }\r\ntemplate <class T, class\
    \ S>\r\nvoid read(pair<T, S> &p) {\r\n  read(p.first), read(p.second);\r\n}\r\n\
    template <class T>\r\nvoid read(vector<T> &a) {\r\n  for (auto &i: a) read(i);\r\
    \n}\r\ntemplate <class T>\r\nvoid read(T &a) {\r\n  cin >> a;\r\n}\r\nvoid IN()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid IN(Head &head, Tail &...\
    \ tail) {\r\n  read(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate <typename T,\
    \ typename U>\r\nostream &operator<<(ostream &os, const pair<T, U> &A) {\r\n \
    \ os << A.fi << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nostream &operator<<(ostream &os, const vector<T> &A) {\r\n  for (size_t\
    \ i = 0; i < A.size(); i++) {\r\n    if (i) os << \" \";\r\n    os << A[i];\r\n\
    \  }\r\n  return os;\r\n}\r\n\r\nvoid print() {\r\n  cout << \"\\n\";\r\n  cout.flush();\r\
    \n}\r\n\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail\
    \ &&... tail) {\r\n  cout << head;\r\n  if (sizeof...(Tail)) cout << \" \";\r\n\
    \  print(forward<Tail>(tail)...);\r\n}\r\n\r\n#if defined(LOCAL)\r\n#define SHOW(...)\
    \ \\\r\n  SHOW_IMPL(__VA_ARGS__, SHOW4, SHOW3, SHOW2, SHOW1)(__VA_ARGS__)\r\n\
    #define SHOW_IMPL(_1, _2, _3, _4, NAME, ...) NAME\r\n#define SHOW1(x) print(#x,\
    \ \"=\", (x)), flush()\r\n#define SHOW2(x, y) print(#x, \"=\", (x), #y, \"=\"\
    , (y)), flush()\r\n#define SHOW3(x, y, z) print(#x, \"=\", (x), #y, \"=\", (y),\
    \ #z, \"=\", (z)), flush()\r\n#define SHOW4(x, y, z, w) \\\r\n  print(#x, \"=\"\
    , (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w)), flush()\r\n#else\r\n#define\
    \ SHOW(...)\r\n#endif\r\n\r\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"\
    ); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print(t ? \"\
    Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool t = 1)\
    \ { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\r\n"
  code: "#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define\
    \ LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define STR(...)\
    \      \\\r\n  string __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define CHR(...)\
    \    \\\r\n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define DBL(...)   \
    \        \\\r\n  long double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n\r\n#define\
    \ VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\
    \n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid read(int &a) { cin\
    \ >> a; }\r\nvoid read(long long &a) { cin >> a; }\r\nvoid read(char &a) { cin\
    \ >> a; }\r\nvoid read(double &a) { cin >> a; }\r\nvoid read(long double &a) {\
    \ cin >> a; }\r\nvoid read(string &a) { cin >> a; }\r\ntemplate <class T, class\
    \ S>\r\nvoid read(pair<T, S> &p) {\r\n  read(p.first), read(p.second);\r\n}\r\n\
    template <class T>\r\nvoid read(vector<T> &a) {\r\n  for (auto &i: a) read(i);\r\
    \n}\r\ntemplate <class T>\r\nvoid read(T &a) {\r\n  cin >> a;\r\n}\r\nvoid IN()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid IN(Head &head, Tail &...\
    \ tail) {\r\n  read(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate <typename T,\
    \ typename U>\r\nostream &operator<<(ostream &os, const pair<T, U> &A) {\r\n \
    \ os << A.fi << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nostream &operator<<(ostream &os, const vector<T> &A) {\r\n  for (size_t\
    \ i = 0; i < A.size(); i++) {\r\n    if (i) os << \" \";\r\n    os << A[i];\r\n\
    \  }\r\n  return os;\r\n}\r\n\r\nvoid print() {\r\n  cout << \"\\n\";\r\n  cout.flush();\r\
    \n}\r\n\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail\
    \ &&... tail) {\r\n  cout << head;\r\n  if (sizeof...(Tail)) cout << \" \";\r\n\
    \  print(forward<Tail>(tail)...);\r\n}\r\n\r\n#if defined(LOCAL)\r\n#define SHOW(...)\
    \ \\\r\n  SHOW_IMPL(__VA_ARGS__, SHOW4, SHOW3, SHOW2, SHOW1)(__VA_ARGS__)\r\n\
    #define SHOW_IMPL(_1, _2, _3, _4, NAME, ...) NAME\r\n#define SHOW1(x) print(#x,\
    \ \"=\", (x)), flush()\r\n#define SHOW2(x, y) print(#x, \"=\", (x), #y, \"=\"\
    , (y)), flush()\r\n#define SHOW3(x, y, z) print(#x, \"=\", (x), #y, \"=\", (y),\
    \ #z, \"=\", (z)), flush()\r\n#define SHOW4(x, y, z, w) \\\r\n  print(#x, \"=\"\
    , (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w)), flush()\r\n#else\r\n#define\
    \ SHOW(...)\r\n#endif\r\n\r\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"\
    ); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print(t ? \"\
    Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool t = 1)\
    \ { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/io2.hpp
  requiredBy: []
  timestamp: '2024-05-24 21:01:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ITP1_9_A.test.cpp
documentation_of: other/io2.hpp
layout: document
redirect_from:
- /library/other/io2.hpp
- /library/other/io2.hpp.html
title: other/io2.hpp
---
