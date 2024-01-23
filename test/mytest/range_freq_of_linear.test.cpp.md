---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/floor_sum_of_linear.hpp
    title: mod/floor_sum_of_linear.hpp
  - icon: ':heavy_check_mark:'
    path: mod/range_freq_of_linear.hpp
    title: mod/range_freq_of_linear.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/range_freq_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#pragma GCC optimize(\"\
    Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = ll(infty<int>) * infty<int> * 2;\ntemplate <>\nconstexpr u32 infty<u32> =\
    \ infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\n\
    constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\ntemplate <>\nconstexpr\
    \ double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long double infty<long\
    \ double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define overload4(a,\
    \ b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__,\
    \ FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload3(__VA_ARGS__,\
    \ FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define FOR_subset(t, s) \\\n  for (ll\
    \ t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n#define all(x) x.begin(),\
    \ x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\
    \n#define stoi stoll\n\nint popcnt(int x) { return __builtin_popcount(x); }\n\
    int popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_mod_2(int x) { return __builtin_parity(x); }\nint popcnt_mod_2(u32\
    \ x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll x) { return __builtin_parityll(x);\
    \ }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x); }\n// (0, 1, 2, 3,\
    \ 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n \
    \ T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
    \ &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate\
    \ <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok = true)\
    \ {\n  if (check_ok) assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate\
    \ <typename F>\ndouble binary_search_real(F check, double ok, double ng, int iter\
    \ = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok :\
    \ ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline\
    \ bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char)\
    \ {\n  vc<int> A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] -\
    \ first_char : -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T>\
    \ cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N +\
    \ 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n\
    \  return B;\n}\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n#endif\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static\
    \ uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 4 \"test/mytest/range_freq_of_linear.test.cpp\"\
    \n\n#line 2 \"mod/floor_sum_of_linear.hpp\"\n\n// sum_{x in [L,R)} floor(ax +\
    \ b, mod)\n// I \u306F\u7BC4\u56F2\u5185\u3067 ax+b \u304C\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3057\u306A\u3044\u7A0B\u5EA6\ntemplate <typename O = i128,\
    \ typename I = long long>\nO floor_sum_of_linear(I L, I R, I a, I b, I mod) {\n\
    \  assert(L <= R);\n  O res = 0;\n  b += L * a;\n  I N = R - L;\n\n  if (b < 0)\
    \ {\n    I k = ceil(-b, mod);\n    b += k * mod;\n    res -= O(N) * O(k);\n  }\n\
    \n  while (N) {\n    I q;\n    tie(q, a) = divmod(a, mod);\n    res += (N & 1\
    \ ? O(N) * O((N - 1) / 2) * O(q) : O(N / 2) * O(N - 1) * O(q));\n    if (b >=\
    \ mod) {\n      tie(q, b) = divmod(b, mod);\n      res += O(N) * q;\n    }\n \
    \   tie(N, b) = divmod(a * N + b, mod);\n    tie(a, mod) = mp(mod, a);\n  }\n\
    \  return res;\n}\n#line 2 \"mod/range_freq_of_linear.hpp\"\n\n// L <= x < R \u306E\
    \u3046\u3061\u3067\u3001(ax+b mod) in [lo, hi) \u3068\u306A\u308B\u3082\u306E\u306E\
    \u500B\u6570\nll range_freq_of_linear(ll L, ll R, ll a, ll b, ll mod, ll lo, ll\
    \ hi) {\n  if (lo >= hi) return 0;\n  assert(0 <= lo && lo < hi && hi <= mod);\n\
    \n  i128 x1 = floor_sum_of_linear(L, R, a, b - lo, mod);\n  i128 x2 = floor_sum_of_linear(L,\
    \ R, a, b - hi, mod);\n  return x1 - x2;\n}\n#line 6 \"test/mytest/range_freq_of_linear.test.cpp\"\
    \n\nvoid test() {\n  FOR(100) {\n    int L = RNG(1000);\n    int R = RNG(1000);\n\
    \    if (L > R) swap(L, R);\n    int a = RNG(-1000, 1000);\n    int b = RNG(-1000,\
    \ 1000);\n    int mod = RNG(1, 1000);\n    int lo = RNG(0, mod);\n    int hi =\
    \ RNG(0, mod);\n    if (lo > hi) swap(lo, hi);\n\n    ll ANS = 0;\n    FOR(x,\
    \ L, R) {\n      ll v = a * x + b;\n      v %= mod;\n      if (v < 0) v += mod;\n\
    \      if (lo <= v && v < hi) ++ANS;\n    }\n    assert(ANS == range_freq_of_linear(L,\
    \ R, a, b, mod, lo, hi));\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"random/base.hpp\"\n\n#include \"mod/range_freq_of_linear.hpp\"\n\n\
    void test() {\n  FOR(100) {\n    int L = RNG(1000);\n    int R = RNG(1000);\n\
    \    if (L > R) swap(L, R);\n    int a = RNG(-1000, 1000);\n    int b = RNG(-1000,\
    \ 1000);\n    int mod = RNG(1, 1000);\n    int lo = RNG(0, mod);\n    int hi =\
    \ RNG(0, mod);\n    if (lo > hi) swap(lo, hi);\n\n    ll ANS = 0;\n    FOR(x,\
    \ L, R) {\n      ll v = a * x + b;\n      v %= mod;\n      if (v < 0) v += mod;\n\
    \      if (lo <= v && v < hi) ++ANS;\n    }\n    assert(ANS == range_freq_of_linear(L,\
    \ R, a, b, mod, lo, hi));\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - mod/range_freq_of_linear.hpp
  - mod/floor_sum_of_linear.hpp
  isVerificationFile: true
  path: test/mytest/range_freq_of_linear.test.cpp
  requiredBy: []
  timestamp: '2023-11-10 22:48:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/range_freq_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/range_freq_of_linear.test.cpp
- /verify/test/mytest/range_freq_of_linear.test.cpp.html
title: test/mytest/range_freq_of_linear.test.cpp
---