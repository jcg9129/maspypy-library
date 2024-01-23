---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linalg/blackbox/min_poly.hpp
    title: linalg/blackbox/min_poly.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/matrix_mul.hpp
    title: linalg/matrix_mul.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: seq/find_linear_rec.hpp
    title: seq/find_linear_rec.hpp
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
  bundledCode: "#line 1 \"test/mytest/min_poly.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\n\
    template <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate\
    \ <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \  return B;\n}\n#endif\n#line 3 \"test/mytest/min_poly.test.cpp\"\n\n#line 2\
    \ \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class T>\n \
    \ static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n  template\
    \ <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate <class\
    \ T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint>\
    \ dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1)\
    \ * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head, class...\
    \ Tail>\nmint multinomial(Head &&head, Tail &&... tail) {\n  return fact<mint>(head)\
    \ * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\ntemplate <typename mint>\n\
    mint C_dense(int n, int k) {\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n\
    \  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1)\
    \ : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if\
    \ (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k +\
    \ 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n\
    \    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j,\
    \ W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n\
    }\n\ntemplate <typename mint, bool large = false, bool dense = false>\nmint C(ll\
    \ n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr\
    \ (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n\
    \ >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) { return (d == 0 ? mint(1)\
    \ : mint(0)); }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n#line 3 \"\
    mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static constexpr u32\
    \ umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n\n  static\
    \ modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n  }\n  constexpr\
    \ modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod) {}\n  constexpr\
    \ modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x) : val(x % umod)\
    \ {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr\
    \ modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(i128\
    \ x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const modint &other)\
    \ const { return val < other.val; }\n  modint &operator+=(const modint &p) {\n\
    \    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n  }\n  modint\
    \ &operator-=(const modint &p) {\n    if ((val += umod - p.val) >= umod) val -=\
    \ umod;\n    return *this;\n  }\n  modint &operator*=(const modint &p) {\n   \
    \ val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint &operator/=(const\
    \ modint &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  modint operator-()\
    \ const { return modint::raw(val ? mod - val : u32(0)); }\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n  modint operator*(const modint &p)\
    \ const { return modint(*this) *= p; }\n  modint operator/(const modint &p) const\
    \ { return modint(*this) /= p; }\n  bool operator==(const modint &p) const { return\
    \ val == p.val; }\n  bool operator!=(const modint &p) const { return val != p.val;\
    \ }\n  modint inverse() const {\n    int a = val, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll n) const {\n  \
    \  assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n      if\
    \ (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r \u306F\
    \ 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info() {\n\
    \    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161) return\
    \ {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod == 754974721)\
    \ return {24, 362};\n    if (mod == 880803841) return {23, 211};\n    if (mod\
    \ == 943718401) return {22, 663003469};\n    if (mod == 998244353) return {23,\
    \ 31};\n    if (mod == 1045430273) return {20, 363};\n    if (mod == 1051721729)\
    \ return {20, 330};\n    if (mod == 1053818881) return {20, 2789};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"seq/find_linear_rec.hpp\"\n\r\ntemplate <typename mint>\r\nvector<mint>\
    \ find_linear_rec(vector<mint>& A) {\r\n  int N = len(A);\r\n  vc<mint> B = {1},\
    \ C = {1};\r\n  int l = 0, m = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\n    mint\
    \ d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }\r\n    if (d ==\
    \ 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\n    auto tmp = C;\r\n    mint\
    \ q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(), len(B) + m - len(C),\
    \ 0);\r\n    FOR(j, len(B)) C[j + m] -= q * B[j];\r\n    if (l + l <= i) {\r\n\
    \      B = tmp;\r\n      l = i + 1 - l, m = 1;\r\n      p = d;\r\n    } else {\r\
    \n      ++m;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"linalg/blackbox/min_poly.hpp\"\
    \n\r\n// \u884C\u5217 A \u3092\u304B\u3051\u308B\u3053\u3068\u3092\u8868\u3059\
    \u7DDA\u5F62\u5909\u63DB f \u3092\u6E21\u3059\r\n// auto f = [&](vc<mint> v) ->\
    \ vc<mint> {};\r\ntemplate <typename mint, typename F>\r\nvc<mint> blackbox_min_poly(int\
    \ N, F f) {\r\n  vc<mint> S(N + N + 10);\r\n  vc<mint> c(N);\r\n  vc<mint> v(N);\r\
    \n  FOR(i, N) c[i] = RNG(0, mint::get_mod());\r\n  FOR(i, N) v[i] = RNG(0, mint::get_mod());\r\
    \n  FOR(k, N + N + 10) {\r\n    FOR(i, N) S[k] += c[i] * v[i];\r\n    v = f(v);\r\
    \n  }\r\n  S = find_linear_rec(S);\r\n  reverse(all(S));\r\n  return S;\r\n}\r\
    \n#line 3 \"linalg/matrix_mul.hpp\"\n\r\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\r\nvc<vc<T>> matrix_mul(const vc<vc<T>>& A, const vc<vc<T>>& B, int\
    \ N1 = -1,\r\n                     int N2 = -1, int N3 = -1) {\r\n  if (N1 ==\
    \ -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }\r\n  vv(u32, b, N3, N2);\r\
    \n  FOR(i, N2) FOR(j, N3) b[j][i] = B[i][j].val;\r\n  vv(T, C, N1, N3);\r\n\r\n\
    \  if ((T::get_mod() < (1 << 30)) && N2 <= 16) {\r\n    FOR(i, N1) FOR(j, N3)\
    \ {\r\n      u64 sm = 0;\r\n      FOR(m, N2) sm += u64(A[i][m].val) * b[j][m];\r\
    \n      C[i][j] = sm;\r\n    }\r\n  } else {\r\n    FOR(i, N1) FOR(j, N3) {\r\n\
    \      u128 sm = 0;\r\n      FOR(m, N2) sm += u64(A[i][m].val) * b[j][m];\r\n\
    \      C[i][j] = T::raw(sm % (T::get_mod()));\r\n    }\r\n  }\r\n  return C;\r\
    \n}\r\n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* =\
    \ nullptr>\r\nvc<vc<T>> matrix_mul(const vc<vc<T>>& A, const vc<vc<T>>& B, int\
    \ N1 = -1,\r\n                     int N2 = -1, int N3 = -1) {\r\n  if (N1 ==\
    \ -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }\r\n  vv(T, b, N2, N3);\r\n\
    \  FOR(i, N2) FOR(j, N3) b[j][i] = B[i][j];\r\n  vv(T, C, N1, N3);\r\n  FOR(n,\
    \ N1) FOR(m, N2) FOR(k, N3) C[n][k] += A[n][m] * b[k][m];\r\n  return C;\r\n}\r\
    \n\r\n// square-matrix defined as array\r\ntemplate <class T, int N>\r\narray<array<T,\
    \ N>, N> matrix_mul(const array<array<T, N>, N>& A,\r\n                      \
    \           const array<array<T, N>, N>& B) {\r\n  array<array<T, N>, N> C{};\r\
    \n\r\n  if ((T::get_mod() < (1 << 30)) && N <= 16) {\r\n    FOR(i, N) FOR(k, N)\
    \ {\r\n      u64 sm = 0;\r\n      FOR(j, N) sm += u64(A[i][j].val) * (B[j][k].val);\r\
    \n      C[i][k] = sm;\r\n    }\r\n  } else {\r\n    FOR(i, N) FOR(k, N) {\r\n\
    \      u128 sm = 0;\r\n      FOR(j, N) sm += u64(A[i][j].val) * (B[j][k].val);\r\
    \n      C[i][k] = sm;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n#line 7 \"test/mytest/min_poly.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid test() {\n  vc<tuple<int, int, mint>> A;\n\
    \  A.eb(0, 0, 1);\n  A.eb(0, 1, 2);\n  A.eb(1, 0, 3);\n  A.eb(1, 1, 4);\n  vc<mint>\
    \ f = blackbox_min_poly<mint>(2, [&](vc<mint> f) -> vc<mint> {\n    vc<mint> g(2);\n\
    \    for (auto& [a, b, c]: A) g[b] += f[a] * c;\n    return g;\n  });\n  assert(f\
    \ == vc<mint>({mint(-2), mint(-5), mint(1)}));\n\n  A.clear();\n  A.eb(0, 1, 1);\n\
    \  f = blackbox_min_poly<mint>(2, [&](vc<mint> f) -> vc<mint> {\n    vc<mint>\
    \ g(2);\n    for (auto& [a, b, c]: A) g[b] += f[a] * c;\n    return g;\n  });\n\
    \  assert(f == vc<mint>({mint(0), mint(0), mint(1)}));\n\n  A.clear();\n  f =\
    \ blackbox_min_poly<mint>(2, [&](vc<mint> f) -> vc<mint> {\n    vc<mint> g(2);\n\
    \    for (auto& [a, b, c]: A) g[b] += f[a] * c;\n    return g;\n  });\n  assert(f\
    \ == vc<mint>({mint(0), mint(1)}));\n\n  A.clear();\n  f = blackbox_min_poly<mint>(0,\
    \ [&](vc<mint> f) -> vc<mint> {\n    vc<mint> g(0);\n    for (auto& [a, b, c]:\
    \ A) g[b] += f[a] * c;\n    return g;\n  });\n  assert(f == vc<mint>({mint(1)}));\n\
    \n  A.clear();\n  A.eb(0, 1, 1);\n  A.eb(0, 2, 1);\n  A.eb(1, 2, 1);\n  f = blackbox_min_poly<mint>(3,\
    \ [&](vc<mint> f) -> vc<mint> {\n    vc<mint> g(3);\n    for (auto& [a, b, c]:\
    \ A) g[b] += f[a] * c;\n    return g;\n  });\n  assert(f == vc<mint>({mint(0),\
    \ mint(0), mint(0), mint(1)}));\n\n  A.clear();\n  f = blackbox_min_poly<mint>(3,\
    \ [&](vc<mint> a) -> vc<mint> {\n    vc<mint> b(3);\n    for (auto&& [i, j, x]:\
    \ A) b[j] += a[i] * x;\n    return b;\n  });\n  assert(f == vc<mint>({mint(0),\
    \ mint(1)}));\n\n  // random matrix\n  FOR(N, 1, 20) {\n    vv(mint, mat, N, N);\n\
    \    FOR(i, N) FOR(j, N) mat[i][j] = RNG(0, 998244353);\n    A.clear();\n    FOR(i,\
    \ N) FOR(j, N) A.eb(i, j, mat[i][j]);\n    f = blackbox_min_poly<mint>(N, [&](vc<mint>\
    \ a) -> vc<mint> {\n      vc<mint> b(N);\n      for (auto&& [i, j, x]: A) b[j]\
    \ += a[i] * x;\n      return b;\n    });\n    vv(mint, B, N, N);\n    FOR(i, N)\
    \ B[i][i] = 1;\n    vv(mint, C, N, N);\n    FOR(d, len(f)) {\n      FOR(i, N)\
    \ FOR(j, N) C[i][j] += f[d] * B[i][j];\n      B = matrix_mul(mat, B);\n    }\n\
    \    FOR(i, N) FOR(j, N) assert(C[i][j] == mint(0));\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"mod/modint.hpp\"\n#include \"linalg/blackbox/min_poly.hpp\"\n#include\
    \ \"linalg/matrix_mul.hpp\"\n\nusing mint = modint998;\n\nvoid test() {\n  vc<tuple<int,\
    \ int, mint>> A;\n  A.eb(0, 0, 1);\n  A.eb(0, 1, 2);\n  A.eb(1, 0, 3);\n  A.eb(1,\
    \ 1, 4);\n  vc<mint> f = blackbox_min_poly<mint>(2, [&](vc<mint> f) -> vc<mint>\
    \ {\n    vc<mint> g(2);\n    for (auto& [a, b, c]: A) g[b] += f[a] * c;\n    return\
    \ g;\n  });\n  assert(f == vc<mint>({mint(-2), mint(-5), mint(1)}));\n\n  A.clear();\n\
    \  A.eb(0, 1, 1);\n  f = blackbox_min_poly<mint>(2, [&](vc<mint> f) -> vc<mint>\
    \ {\n    vc<mint> g(2);\n    for (auto& [a, b, c]: A) g[b] += f[a] * c;\n    return\
    \ g;\n  });\n  assert(f == vc<mint>({mint(0), mint(0), mint(1)}));\n\n  A.clear();\n\
    \  f = blackbox_min_poly<mint>(2, [&](vc<mint> f) -> vc<mint> {\n    vc<mint>\
    \ g(2);\n    for (auto& [a, b, c]: A) g[b] += f[a] * c;\n    return g;\n  });\n\
    \  assert(f == vc<mint>({mint(0), mint(1)}));\n\n  A.clear();\n  f = blackbox_min_poly<mint>(0,\
    \ [&](vc<mint> f) -> vc<mint> {\n    vc<mint> g(0);\n    for (auto& [a, b, c]:\
    \ A) g[b] += f[a] * c;\n    return g;\n  });\n  assert(f == vc<mint>({mint(1)}));\n\
    \n  A.clear();\n  A.eb(0, 1, 1);\n  A.eb(0, 2, 1);\n  A.eb(1, 2, 1);\n  f = blackbox_min_poly<mint>(3,\
    \ [&](vc<mint> f) -> vc<mint> {\n    vc<mint> g(3);\n    for (auto& [a, b, c]:\
    \ A) g[b] += f[a] * c;\n    return g;\n  });\n  assert(f == vc<mint>({mint(0),\
    \ mint(0), mint(0), mint(1)}));\n\n  A.clear();\n  f = blackbox_min_poly<mint>(3,\
    \ [&](vc<mint> a) -> vc<mint> {\n    vc<mint> b(3);\n    for (auto&& [i, j, x]:\
    \ A) b[j] += a[i] * x;\n    return b;\n  });\n  assert(f == vc<mint>({mint(0),\
    \ mint(1)}));\n\n  // random matrix\n  FOR(N, 1, 20) {\n    vv(mint, mat, N, N);\n\
    \    FOR(i, N) FOR(j, N) mat[i][j] = RNG(0, 998244353);\n    A.clear();\n    FOR(i,\
    \ N) FOR(j, N) A.eb(i, j, mat[i][j]);\n    f = blackbox_min_poly<mint>(N, [&](vc<mint>\
    \ a) -> vc<mint> {\n      vc<mint> b(N);\n      for (auto&& [i, j, x]: A) b[j]\
    \ += a[i] * x;\n      return b;\n    });\n    vv(mint, B, N, N);\n    FOR(i, N)\
    \ B[i][i] = 1;\n    vv(mint, C, N, N);\n    FOR(d, len(f)) {\n      FOR(i, N)\
    \ FOR(j, N) C[i][j] += f[d] * B[i][j];\n      B = matrix_mul(mat, B);\n    }\n\
    \    FOR(i, N) FOR(j, N) assert(C[i][j] == mint(0));\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - linalg/blackbox/min_poly.hpp
  - seq/find_linear_rec.hpp
  - random/base.hpp
  - linalg/matrix_mul.hpp
  isVerificationFile: true
  path: test/mytest/min_poly.test.cpp
  requiredBy: []
  timestamp: '2024-01-23 16:01:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/min_poly.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/min_poly.test.cpp
- /verify/test/mytest/min_poly.test.cpp.html
title: test/mytest/min_poly.test.cpp
---