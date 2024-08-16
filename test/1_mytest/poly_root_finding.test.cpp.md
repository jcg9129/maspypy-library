---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_all.hpp
    title: poly/convolution_all.hpp
  - icon: ':question:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':heavy_check_mark:'
    path: poly/finding_root_of_polynomial.hpp
    title: poly/finding_root_of_polynomial.hpp
  - icon: ':question:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: poly/ntt_doubling.hpp
    title: poly/ntt_doubling.hpp
  - icon: ':question:'
    path: poly/poly_divmod.hpp
    title: poly/poly_divmod.hpp
  - icon: ':heavy_check_mark:'
    path: poly/poly_gcd.hpp
    title: poly/poly_gcd.hpp
  - icon: ':heavy_check_mark:'
    path: poly/poly_mod_pow.hpp
    title: poly/poly_mod_pow.hpp
  - icon: ':question:'
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
  bundledCode: "#line 1 \"test/1_mytest/poly_root_finding.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128 =\
    \ __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, h, ...) vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...) vector<vector<vector<type>>>\
    \ name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b,\
    \ vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n\
    #define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i =\
    \ 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define\
    \ FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for\
    \ (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n\
    #define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_mod_2(int x) { return __builtin_parity(x);\
    \ }\nint popcnt_mod_2(u32 x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll\
    \ x) { return __builtin_parityll(x); }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T floor(T a, T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename\
    \ T>\nT bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename\
    \ T>\npair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q\
    \ * y};\n}\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n\
    \  T sm = 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    template <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok\
    \ : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return\
    \ (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T\
    \ &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off\
    \ = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int>\
    \ ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return\
    \ (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/poly_root_finding.test.cpp\"\
    \n\n#line 2 \"poly/poly_divmod.hpp\"\n\r\n#line 2 \"poly/count_terms.hpp\"\ntemplate<typename\
    \ mint>\r\nint count_terms(const vc<mint>& f){\r\n  int t = 0;\r\n  FOR(i, len(f))\
    \ if(f[i] != mint(0)) ++t;\r\n  return t;\r\n}\n#line 2 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n  static\
    \ vector<mint> dat = {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n \
    \ while (len(dat) <= n) {\n    int k = len(dat);\n    int q = (mod + k - 1) /\
    \ k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n  }\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact_inv(int n) {\n  static vector<mint> dat\
    \ = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&... tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint>\
    \ C;\n  static int H = 0, W = 0;\n  auto calc = [&](int i, int j) -> mint {\n\
    \    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j]\
    \ + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n     \
    \ C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n\
    \    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n +\
    \ 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n   \
    \ }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool\
    \ large = false, bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  if constexpr (dense) return C_dense<mint>(n,\
    \ k);\n  if constexpr (!large) return multinomial<mint>(n, k, n - k);\n  k = min(k,\
    \ n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n\
    }\n\ntemplate <typename mint, bool large = false>\nmint C_inv(ll n, ll k) {\n\
    \  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if (!large) return fact_inv<mint>(n)\
    \ * fact<mint>(k) * fact<mint>(n - k);\n  return mint(1) / C<mint, 1>(n, k);\n\
    }\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint, bool large = false, bool dense\
    \ = false>\nmint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return\
    \ mint(0);\n  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint,\
    \ large, dense>(n + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int\
    \ mod>\nstruct modint {\n  static constexpr u32 umod = u32(mod);\n  static_assert(umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    assert(n >= 0);\n  \
    \  modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 120586241) return\
    \ {20, 74066978};\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 943718401) return\
    \ {22, 663003469};\n    if (mod == 998244353) return {23, 31};\n    if (mod ==\
    \ 1004535809) return {21, 836905998};\n    if (mod == 1045430273) return {20,\
    \ 363};\n    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881)\
    \ return {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt()\
    \ { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid\
    \ rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <=\
    \ x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n\
    }\n#endif\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"mod/mod_inv.hpp\"\n\r\n// long \u3067\u3082\u5927\u4E08\u592B\r\n//\
    \ (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\
    \u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\
    \r\nll mod_inv(ll val, ll mod) {\r\n  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\
    \n  val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1,\
    \ v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n\
    #line 2 \"mod/crt3.hpp\"\n\nconstexpr u32 mod_pow_constexpr(u64 a, u64 n, u32\
    \ mod) {\n  a %= mod;\n  u64 res = 1;\n  FOR(32) {\n    if (n & 1) res = res *\
    \ a % mod;\n    a = a * a % mod, n /= 2;\n  }\n  return res;\n}\n\ntemplate <typename\
    \ T, u32 p0, u32 p1>\nT CRT2(u64 a0, u64 a1) {\n  static_assert(p0 < p1);\n  static\
    \ constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  u64 c = (a1 - a0\
    \ + p1) * x0_1 % p1;\n  return a0 + c * p0;\n}\n\ntemplate <typename T, u32 p0,\
    \ u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0 < p1 &&\
    \ p1 < p2);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2, p1);\n\
    \  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n\
    \  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c = (a1 - a0 + p1) * x1 % p1;\n\
    \  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 % p2;\n  return\
    \ T(ans_1) + T(c) * T(p01);\n}\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2,\
    \ u32 p3, u32 p4>\nT CRT5(u64 a0, u64 a1, u64 a2, u64 a3, u64 a4) {\n  static_assert(p0\
    \ < p1 && p1 < p2 && p2 < p3 && p3 < p4);\n  static constexpr u64 x1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  static constexpr u64 x3\n      = mod_pow_constexpr(u64(p0) *\
    \ p1 % p3 * p2 % p3, p3 - 2, p3);\n  static constexpr u64 x4\n      = mod_pow_constexpr(u64(p0)\
    \ * p1 % p4 * p2 % p4 * p3 % p4, p4 - 2, p4);\n  static constexpr u64 p01 = u64(p0)\
    \ * p1;\n  static constexpr u64 p23 = u64(p2) * p3;\n  u64 c = (a1 - a0 + p1)\
    \ * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 %\
    \ p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c = static_cast<u64>(a3\
    \ - ans_2 % p3 + p3) * x3 % p3;\n  u128 ans_3 = ans_2 + static_cast<u128>(c *\
    \ p2) * p01;\n  c = static_cast<u64>(a4 - ans_3 % p4 + p4) * x4 % p4;\n  return\
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 2 \"poly/convolution_naive.hpp\"\
    \n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\r\
    \nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()),\
    \ m = int(b.size());\r\n  if (n > m) return convolution_naive<T>(b, a);\r\n  if\
    \ (n == 0) return {};\r\n  vector<T> ans(n + m - 1);\r\n  FOR(i, n) FOR(j, m)\
    \ ans[i + j] += a[i] * b[j];\r\n  return ans;\r\n}\r\n\r\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\r\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()), m = int(b.size());\r\
    \n  if (n > m) return convolution_naive<T>(b, a);\r\n  if (n == 0) return {};\r\
    \n  vc<T> ans(n + m - 1);\r\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\r\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\r\n      int s = max(0, k - m + 1);\r\
    \n      int t = min(n, k + 1);\r\n      u64 sm = 0;\r\n      for (int i = s; i\
    \ < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\n      ans[k] = sm;\r\n\
    \    }\r\n  } else {\r\n    for (int k = 0; k < n + m - 1; ++k) {\r\n      int\
    \ s = max(0, k - m + 1);\r\n      int t = min(n, k + 1);\r\n      u128 sm = 0;\r\
    \n      for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\
    \n      ans[k] = T::raw(sm % T::get_mod());\r\n    }\r\n  }\r\n  return ans;\r\
    \n}\r\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n// \u4EFB\u610F\u306E\u74B0\
    \u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T> convolution_karatsuba(const\
    \ vc<T>& f, const vc<T>& g) {\n  const int thresh = 30;\n  if (min(len(f), len(g))\
    \ <= thresh) return convolution_naive(f, g);\n  int n = max(len(f), len(g));\n\
    \  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n  if (len(f) < m) f1 = f;\n \
    \ if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n  if (len(f) >= m) f2 = {f.begin()\
    \ + m, f.end()};\n  if (len(g) < m) g1 = g;\n  if (len(g) >= m) g1 = {g.begin(),\
    \ g.begin() + m};\n  if (len(g) >= m) g2 = {g.begin() + m, g.end()};\n  vc<T>\
    \ a = convolution_karatsuba(f1, g1);\n  vc<T> b = convolution_karatsuba(f2, g2);\n\
    \  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i, len(g2)) g1[i] += g2[i];\n  vc<T>\
    \ c = convolution_karatsuba(f1, g1);\n  vc<T> F(len(f) + len(g) - 1);\n  assert(2\
    \ * m + len(b) <= len(F));\n  FOR(i, len(a)) F[i] += a[i], c[i] -= a[i];\n  FOR(i,\
    \ len(b)) F[2 * m + i] += b[i], c[i] -= b[i];\n  if (c.back() == T(0)) c.pop_back();\n\
    \  FOR(i, len(c)) if (c[i] != T(0)) F[m + i] += c[i];\n  return F;\n}\n#line 2\
    \ \"poly/ntt.hpp\"\n\r\ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool\
    \ inverse) {\r\n  assert(mint::can_ntt());\r\n  const int rank2 = mint::ntt_info().fi;\r\
    \n  const int mod = mint::get_mod();\r\n  static array<mint, 30> root, iroot;\r\
    \n  static array<mint, 30> rate2, irate2;\r\n  static array<mint, 30> rate3, irate3;\r\
    \n\r\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\r\n\r\n  static\
    \ bool prepared = 0;\r\n  if (!prepared) {\r\n    prepared = 1;\r\n    root[rank2]\
    \ = mint::ntt_info().se;\r\n    iroot[rank2] = mint(1) / root[rank2];\r\n    FOR_R(i,\
    \ rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\r\n    }\r\n    mint prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 2; i++) {\r\n      rate2[i] = root[i + 2] * prod;\r\n  \
    \    irate2[i] = iroot[i + 2] * iprod;\r\n      prod *= iroot[i + 2];\r\n    \
    \  iprod *= root[i + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 3; i++) {\r\n      rate3[i] = root[i + 3] * prod;\r\n  \
    \    irate3[i] = iroot[i + 3] * iprod;\r\n      prod *= iroot[i + 3];\r\n    \
    \  iprod *= root[i + 3];\r\n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\n \
    \ int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  if (!inverse) {\r\n    int\
    \ len = 0;\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n        int\
    \ p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1 << len)\
    \ {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\n   \
    \         auto l = a[i + offset];\r\n            auto r = a[i + offset + p] *\
    \ rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= rate2[topbit(~s & -~s)];\r\n   \
    \     }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len -\
    \ 2);\r\n        mint rot = 1, imag = root[2];\r\n        for (int s = 0; s <\
    \ (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint rot3\
    \ = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for (int\
    \ i = 0; i < p; i++) {\r\n            u64 mod2 = u64(mod) * mod;\r\n         \
    \   u64 a0 = a[i + offset].val;\r\n            u64 a1 = u64(a[i + offset + p].val)\
    \ * rot.val;\r\n            u64 a2 = u64(a[i + offset + 2 * p].val) * rot2.val;\r\
    \n            u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\r\n        \
    \    u64 a1na3imag = (a1 + mod2 - a3) % mod * imag.val;\r\n            u64 na2\
    \ = mod2 - a2;\r\n            a[i + offset] = a0 + a2 + a1 + a3;\r\n         \
    \   a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i\
    \ + offset + 2 * p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 *\
    \ p] = a0 + na2 + (mod2 - a1na3imag);\r\n          }\r\n          rot *= rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            u64 l = a[i + offset].val;\r\n            u64 r = a[i + offset +\
    \ p].val;\r\n            a[i + offset] = l + r;\r\n            a[i + offset +\
    \ p] = (mod + l - r) * irot.val;\r\n          }\r\n          irot *= irate2[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len--;\r\n      } else {\r\n        int p =\
    \ 1 << (h - len);\r\n        mint irot = 1, iimag = iroot[2];\r\n        FOR(s,\
    \ (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n          mint\
    \ irot3 = irot2 * irot;\r\n          int offset = s << (h - len + 2);\r\n    \
    \      for (int i = 0; i < p; i++) {\r\n            u64 a0 = a[i + offset + 0\
    \ * p].val;\r\n            u64 a1 = a[i + offset + 1 * p].val;\r\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\r\n            u64 a3 = a[i + offset + 3\
    \ * p].val;\r\n            u64 x = (mod + a2 - a3) * iimag.val % mod;\r\n    \
    \        a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset + 1 *\
    \ p] = (a0 + mod - a1 + x) * irot.val;\r\n            a[i + offset + 2 * p] =\
    \ (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\r\n            a[i + offset + 3 *\
    \ p] = (a0 + 2 * mod - a1 - x) * irot3.val;\r\n          }\r\n          irot *=\
    \ irate3[topbit(~s & -~s)];\r\n        }\r\n        len -= 2;\r\n      }\r\n \
    \   }\r\n  }\r\n}\r\n#line 1 \"poly/fft.hpp\"\nnamespace CFFT {\r\nusing real\
    \ = double;\r\n\r\nstruct C {\r\n  real x, y;\r\n\r\n  C() : x(0), y(0) {}\r\n\
    \r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline C operator+(const C& c) const\
    \ { return C(x + c.x, y + c.y); }\r\n  inline C operator-(const C& c) const {\
    \ return C(x - c.x, y - c.y); }\r\n  inline C operator*(const C& c) const {\r\n\
    \    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\n\r\n  inline C\
    \ conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI = acosl(-1);\r\n\
    int base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int> rev = {0, 1};\r\
    \n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\n  rev.resize(1\
    \ << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0; i < (1 << nbase);\
    \ i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\r\n  }\r\
    \n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1 << (base + 1));\r\
    \n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\n      rts[i <<\
    \ 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1 << base));\r\n\
    \      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n    }\r\n    ++base;\r\
    \n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n & (n - 1)) ==\
    \ 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\n  int shift\
    \ = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i < (rev[i] >>\
    \ shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int k = 1; k <\
    \ n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n      for (int\
    \ j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\n       \
    \ a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n      }\r\
    \n    }\r\n  }\r\n}\r\n} // namespace CFFT\n#line 9 \"poly/convolution.hpp\"\n\
    \r\ntemplate <class mint>\r\nvector<mint> convolution_ntt(vector<mint> a, vector<mint>\
    \ b) {\r\n  if (a.empty() || b.empty()) return {};\r\n  int n = int(a.size()),\
    \ m = int(b.size());\r\n  int sz = 1;\r\n  while (sz < n + m - 1) sz *= 2;\r\n\
    \r\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\u5272\
    \u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\u306E\
    \u3067\u3002\r\n  if ((n + m - 3) <= sz / 2) {\r\n    auto a_last = a.back(),\
    \ b_last = b.back();\r\n    a.pop_back(), b.pop_back();\r\n    auto c = convolution(a,\
    \ b);\r\n    c.resize(n + m - 1);\r\n    c[n + m - 2] = a_last * b_last;\r\n \
    \   FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;\r\n    FOR(i, len(b)) c[i +\
    \ len(a)] += b[i] * a_last;\r\n    return c;\r\n  }\r\n\r\n  a.resize(sz), b.resize(sz);\r\
    \n  bool same = a == b;\r\n  ntt(a, 0);\r\n  if (same) {\r\n    b = a;\r\n  }\
    \ else {\r\n    ntt(b, 0);\r\n  }\r\n  FOR(i, sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\
    \n  a.resize(n + m - 1);\r\n  return a;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvector<mint> convolution_garner(const vector<mint>& a, const vector<mint>& b)\
    \ {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  static\
    \ constexpr int p0 = 167772161;\r\n  static constexpr int p1 = 469762049;\r\n\
    \  static constexpr int p2 = 754974721;\r\n  using mint0 = modint<p0>;\r\n  using\
    \ mint1 = modint<p1>;\r\n  using mint2 = modint<p2>;\r\n  vc<mint0> a0(n), b0(m);\r\
    \n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i]\
    \ = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i] = b[i].val,\
    \ b1[i] = b[i].val, b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\r\n  auto c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  vc<mint> c(len(c0));\r\n  FOR(i, n + m - 1) {\r\n    c[i] = CRT3<mint,\
    \ p0, p1, p2>(c0[i].val, c1[i].val, c2[i].val);\r\n  }\r\n  return c;\r\n}\r\n\
    \r\ntemplate <typename R>\r\nvc<double> convolution_fft(const vc<R>& a, const\
    \ vc<R>& b) {\r\n  using C = CFFT::C;\r\n  int need = (int)a.size() + (int)b.size()\
    \ - 1;\r\n  int nbase = 1;\r\n  while ((1 << nbase) < need) nbase++;\r\n  CFFT::ensure_base(nbase);\r\
    \n  int sz = 1 << nbase;\r\n  vector<C> fa(sz);\r\n  for (int i = 0; i < sz; i++)\
    \ {\r\n    double x = (i < (int)a.size() ? a[i] : 0);\r\n    double y = (i < (int)b.size()\
    \ ? b[i] : 0);\r\n    fa[i] = C(x, y);\r\n  }\r\n  CFFT::fft(fa, sz);\r\n  C r(0,\
    \ -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\r\n  for (int i = 0; i <= (sz >> 1);\
    \ i++) {\r\n    int j = (sz - i) & (sz - 1);\r\n    C z = (fa[j] * fa[j] - (fa[i]\
    \ * fa[i]).conj()) * r;\r\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\r\n    fa[i] = z;\r\n  }\r\n  for (int i = 0; i < (sz >> 1); i++) {\r\n\
    \    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\r\n    C A1 = (fa[i] - fa[i + (sz\
    \ >> 1)]) * t * CFFT::rts[(sz >> 1) + i];\r\n    fa[i] = A0 + A1 * s;\r\n  }\r\
    \n  CFFT::fft(fa, sz >> 1);\r\n  vector<double> ret(need);\r\n  for (int i = 0;\
    \ i < need; i++) {\r\n    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\r\n\
    \  }\r\n  return ret;\r\n}\r\n\r\nvector<ll> convolution(const vector<ll>& a,\
    \ const vector<ll>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (min(n, m) <= 2500) return convolution_naive(a, b);\r\n  ll abs_sum_a\
    \ = 0, abs_sum_b = 0;\r\n  ll LIM = 1e15;\r\n  FOR(i, n) abs_sum_a = min(LIM,\
    \ abs_sum_a + abs(a[i]));\r\n  FOR(i, m) abs_sum_b = min(LIM, abs_sum_b + abs(b[i]));\r\
    \n  if (i128(abs_sum_a) * abs_sum_b < 1e15) {\r\n    vc<double> c = convolution_fft<ll>(a,\
    \ b);\r\n    vc<ll> res(len(c));\r\n    FOR(i, len(c)) res[i] = ll(floor(c[i]\
    \ + .5));\r\n    return res;\r\n  }\r\n\r\n  static constexpr unsigned long long\
    \ MOD1 = 754974721; // 2^24\r\n  static constexpr unsigned long long MOD2 = 167772161;\
    \ // 2^25\r\n  static constexpr unsigned long long MOD3 = 469762049; // 2^26\r\
    \n  static constexpr unsigned long long M2M3 = MOD2 * MOD3;\r\n  static constexpr\
    \ unsigned long long M1M3 = MOD1 * MOD3;\r\n  static constexpr unsigned long long\
    \ M1M2 = MOD1 * MOD2;\r\n  static constexpr unsigned long long M1M2M3 = MOD1 *\
    \ MOD2 * MOD3;\r\n\r\n  static const unsigned long long i1 = mod_inv(MOD2 * MOD3,\
    \ MOD1);\r\n  static const unsigned long long i2 = mod_inv(MOD1 * MOD3, MOD2);\r\
    \n  static const unsigned long long i3 = mod_inv(MOD1 * MOD2, MOD3);\r\n\r\n \
    \ using mint1 = modint<MOD1>;\r\n  using mint2 = modint<MOD2>;\r\n  using mint3\
    \ = modint<MOD3>;\r\n\r\n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\
    \n  vc<mint3> a3(n), b3(m);\r\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i], a3[i] =\
    \ a[i];\r\n  FOR(i, m) b1[i] = b[i], b2[i] = b[i], b3[i] = b[i];\r\n\r\n  auto\
    \ c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  auto c3 = convolution_ntt<mint3>(a3, b3);\r\n\r\n  vc<ll> c(n + m\
    \ - 1);\r\n  FOR(i, n + m - 1) {\r\n    u64 x = 0;\r\n    x += (c1[i].val * i1)\
    \ % MOD1 * M2M3;\r\n    x += (c2[i].val * i2) % MOD2 * M1M3;\r\n    x += (c3[i].val\
    \ * i3) % MOD3 * M1M2;\r\n    ll diff = c1[i].val - ((long long)(x) % (long long)(MOD1));\r\
    \n    if (diff < 0) diff += MOD1;\r\n    static constexpr unsigned long long offset[5]\r\
    \n        = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\r\n    x -= offset[diff %\
    \ 5];\r\n    c[i] = x;\r\n  }\r\n  return c;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvc<mint> convolution(const vc<mint>& a, const vc<mint>& b) {\r\n  int n = len(a),\
    \ m = len(b);\r\n  if (!n || !m) return {};\r\n  if (mint::can_ntt()) {\r\n  \
    \  if (min(n, m) <= 50) return convolution_karatsuba<mint>(a, b);\r\n    return\
    \ convolution_ntt(a, b);\r\n  }\r\n  if (min(n, m) <= 200) return convolution_karatsuba<mint>(a,\
    \ b);\r\n  return convolution_garner(a, b);\r\n}\r\n#line 4 \"poly/fps_inv.hpp\"\
    \n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_sparse(const vc<mint>& f) {\r\
    \n  int N = len(f);\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i, 1, N) if (f[i] !=\
    \ mint(0)) dat.eb(i, f[i]);\r\n  vc<mint> g(N);\r\n  mint g0 = mint(1) / f[0];\r\
    \n  g[0] = g0;\r\n  FOR(n, 1, N) {\r\n    mint rhs = 0;\r\n    for (auto&& [k,\
    \ fk]: dat) {\r\n      if (k > n) break;\r\n      rhs -= fk * g[n - k];\r\n  \
    \  }\r\n    g[n] = rhs * g0;\r\n  }\r\n  return g;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> fps_inv_dense_ntt(const vc<mint>& F) {\r\n  vc<mint> G = {mint(1)\
    \ / F[0]};\r\n  ll N = len(F), n = 1;\r\n  G.reserve(N);\r\n  while (n < N) {\r\
    \n    vc<mint> f(2 * n), g(2 * n);\r\n    FOR(i, min(N, 2 * n)) f[i] = F[i];\r\
    \n    FOR(i, n) g[i] = G[i];\r\n    ntt(f, false), ntt(g, false);\r\n    FOR(i,\
    \ 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\n    FOR(i, n) f[i] = 0;\r\n   \
    \ ntt(f, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\n \
    \   FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\r\n    n *= 2;\r\n  }\r\n  return G;\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_dense(const vc<mint>&\
    \ F) {\r\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\r\n  const int N\
    \ = len(F);\r\n  vc<mint> R = {mint(1) / F[0]};\r\n  vc<mint> p;\r\n  int m =\
    \ 1;\r\n  while (m < N) {\r\n    p = convolution(R, R);\r\n    p.resize(m + m);\r\
    \n    vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\r\n    p = convolution(p,\
    \ f);\r\n    R.resize(m + m);\r\n    FOR(i, m + m) R[i] = R[i] + R[i] - p[i];\r\
    \n    m += m;\r\n  }\r\n  R.resize(N);\r\n  return R;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> fps_inv(const vc<mint>& f) {\r\n  assert(f[0] != mint(0));\r\
    \n  int n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 160 : 820);\r\n  return\
    \ (n <= t ? fps_inv_sparse<mint>(f) : fps_inv_dense<mint>(f));\r\n}\r\n#line 4\
    \ \"poly/poly_divmod.hpp\"\ntemplate <typename mint>\r\npair<vc<mint>, vc<mint>>\
    \ poly_divmod(vc<mint> f, vc<mint> g) {\r\n  assert(g.back() != 0);\r\n  if (len(f)\
    \ < len(g)) { return {{}, f}; }\r\n  auto rf = f, rg = g;\r\n  reverse(all(rf)),\
    \ reverse(all(rg));\r\n  ll deg = len(rf) - len(rg) + 1;\r\n  rf.resize(deg),\
    \ rg.resize(deg);\r\n  rg = fps_inv(rg);\r\n  auto q = convolution(rf, rg);\r\n\
    \  q.resize(deg);\r\n  reverse(all(q));\r\n  auto h = convolution(q, g);\r\n \
    \ FOR(i, len(f)) f[i] -= h[i];\r\n  while (len(f) > 0 && f.back() == 0) f.pop_back();\r\
    \n  return {q, f};\r\n}\r\n#line 2 \"poly/poly_mod_pow.hpp\"\n\n// f^n mod g\n\
    template <typename mint>\nvc<mint> poly_mod_pow(vc<mint> f, ll n, vc<mint>& g)\
    \ {\n  if (n == 0) return {1};\n  if (n == 1) return f;\n  vc<mint> F = poly_mod_pow(f,\
    \ n / 2, g);\n  F = convolution<mint>(F, F);\n  F = poly_divmod(F, g).se;\n  if\
    \ (n & 1) {\n    F = convolution<mint>(F, f);\n    F = poly_divmod(F, g).se;\n\
    \  }\n  return F;\n}\n#line 2 \"poly/poly_gcd.hpp\"\n\r\n// https://people.eecs.berkeley.edu/~fateman/282/readings/yap-2.pdf\r\
    \nnamespace half_gcd {\r\ntemplate <typename T>\r\nusing arr = array<vc<T>, 2>;\r\
    \n\r\ntemplate <typename T>\r\nusing mat = array<vc<T>, 4>;\r\n\r\ntemplate <typename\
    \ T>\r\nvoid shrink(vc<T>& a) {\r\n  while (len(a) && a.back() == 0) a.pop_back();\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvc<T> operator+(const vc<T>& a, const vc<T>&\
    \ b) {\r\n  vc<T> c(max(len(a), len(b)));\r\n  FOR(i, len(a)) c[i] += a[i];\r\n\
    \  FOR(i, len(b)) c[i] += b[i];\r\n  shrink(c);\r\n  return c;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nvc<T> operator-(const vc<T>& a, const vc<T>& b) {\r\n  vc<T>\
    \ c(max(len(a), len(b)));\r\n  FOR(i, len(a)) c[i] += a[i];\r\n  FOR(i, len(b))\
    \ c[i] -= b[i];\r\n  shrink(c);\r\n  return c;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvc<T> operator*(const vc<T>& a, const vc<T>& b) {\r\n  return convolution(a,\
    \ b);\r\n}\r\n\r\ntemplate <typename T>\r\nmat<T> operator*(const mat<T>& A, const\
    \ mat<T>& B) {\r\n  return {A[0] * B[0] + A[1] * B[2], A[0] * B[1] + A[1] * B[3],\r\
    \n          A[2] * B[0] + A[3] * B[2], A[2] * B[1] + A[3] * B[3]};\r\n}\r\n\r\n\
    template <typename T>\r\nmat<T> step(const vc<T> q) {\r\n  mat<T> Q;\r\n  Q[1]\
    \ = {1}, Q[2] = {1};\r\n  Q[3] = Q[3] - q;\r\n  return Q;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\narr<T> operator*(const mat<T>& A, const arr<T>& b) {\r\n  return\
    \ {A[0] * b[0] + A[1] * b[1], A[2] * b[0] + A[3] * b[1]};\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nmat<T> hgcd(arr<T> a) {\r\n  assert(len(a[0]) > len(a[1]) &&\
    \ len(a[1]) > 0);\r\n  int m = len(a[0]) / 2;\r\n  if (len(a[1]) <= m) {\r\n \
    \   mat<T> M;\r\n    M[0] = {1}, M[3] = {1};\r\n    return M;\r\n  }\r\n  auto\
    \ R = hgcd(arr<T>({vc<T>(a[0].begin() + m, a[0].end()),\r\n                  \
    \      vc<T>(a[1].begin() + m, a[1].end())}));\r\n  a = R * a;\r\n  if (len(a[1])\
    \ <= m) return R;\r\n  mat<T> Q = step(poly_divmod(a[0], a[1]).fi);\r\n  R = Q\
    \ * R, a = Q * a;\r\n  if (len(a[1]) <= m) return R;\r\n  int k = 2 * m + 1 -\
    \ len(a[0]);\r\n  auto H = hgcd(arr<T>({vc<T>(a[0].begin() + k, a[0].end()),\r\
    \n                        vc<T>(a[1].begin() + k, a[1].end())}));\r\n  return\
    \ H * R;\r\n}\r\n\r\ntemplate <typename T>\r\nmat<T> cgcd(arr<T> a) {\r\n  assert(a[0].size()\
    \ > a[1].size() && !a[1].empty());\r\n  auto m0 = hgcd(a);\r\n  a = m0 * a;\r\n\
    \  if (a[1].empty()) return m0;\r\n  mat<T> Q = step(poly_divmod(a[0], a[1]).fi);\r\
    \n  m0 = Q * m0, a = Q * a;\r\n  if (a[1].empty()) return m0;\r\n  return cgcd(a)\
    \ * m0;\r\n}\r\n\r\n// gcd == f * fi + g * gi \u3068\u306A\u308B (gcd, fi, gi)\r\
    \ntemplate <typename T>\r\ntuple<vc<T>, vc<T>, vc<T>> poly_extgcd(const vc<T>&\
    \ f, const vc<T>& g) {\r\n  mat<T> Q = step(poly_divmod(f, g).fi);\r\n  auto m\
    \ = Q;\r\n  auto ap = Q * arr<T>{f, g};\r\n  if (!ap[1].empty()) m = cgcd(ap)\
    \ * m;\r\n  return {f * m[0] + g * m[1], m[0], m[1]};\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvc<T> poly_gcd(vc<T> f, vc<T> g) {\r\n  while (len(f) && f.back() == T(0))\
    \ POP(f);\r\n  while (len(g) && g.back() == T(0)) POP(g);\r\n  if (f.empty())\
    \ return g;\r\n  if (g.empty()) return f;\r\n  auto F = get<0>(poly_extgcd(f,\
    \ g));\r\n  T c = T(1) / F.back();\r\n  for (auto& f: F) f *= c;\r\n  return F;\r\
    \n}\r\n} // namespace half_gcd\r\nusing half_gcd::poly_extgcd;\r\nusing half_gcd::poly_gcd;\r\
    \n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      =\
    \ uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 4 \"poly/finding_root_of_polynomial.hpp\"\
    \n\n// F(a)=0 \u3092\u6E80\u305F\u3059 a \u5168\u4F53\u3092\u8FD4\u3059\n// \u6607\
    \u9806\u306B\u30BD\u30FC\u30C8\u3057\u3066\u8FD4\u3059\u3053\u3068\u306B\ntemplate\
    \ <typename mint>\nvc<mint> finding_root_of_polynomial(vc<mint> F) {\n  while\
    \ (len(F) && F.back() == mint(0)) POP(F);\n  assert(!F.empty());\n\n  const int\
    \ p = mint::get_mod();\n  assert(p % 2 == 1);\n\n  vc<mint> g = {0, 1};\n  g =\
    \ poly_mod_pow(g, p, F);\n  if (len(g) <= 2) g.resize(2);\n  g[1] -= 1;\n  F =\
    \ poly_gcd(F, g);\n\n  // F \u306F\u76F8\u7570\u306A\u308B 1 \u6B21\u5F0F\u306E\
    \u7A4D\n  vc<mint> ANS;\n  auto dfs = [&](auto& dfs, vc<mint> F) -> void {\n \
    \   if (len(F) == 1) return;\n    if (len(F) == 2) {\n      mint a = F[0], b =\
    \ F[1];\n      // a+bx=0\n      ANS.eb((-a) / b);\n      return;\n    }\n    vc<mint>\
    \ g(2);\n    g[0] = RNG(0, p), g[1] = 1;\n    vc<mint> h = poly_mod_pow(g, (p\
    \ - 1) / 2, F);\n    if (h.empty()) { return dfs(dfs, F); }\n    h[0] -= 1;\n\
    \    vc<mint> f1 = poly_gcd(F, h);\n    vc<mint> f2 = poly_divmod(F, f1).fi;\n\
    \    dfs(dfs, f1), dfs(dfs, f2);\n  };\n  dfs(dfs, F);\n  sort(all(ANS));\n  return\
    \ ANS;\n}\n#line 2 \"poly/convolution_all.hpp\"\n\r\n#line 2 \"poly/ntt_doubling.hpp\"\
    \n\n#line 4 \"poly/ntt_doubling.hpp\"\n\n// 2^k \u6B21\u591A\u9805\u5F0F\u306E\
    \u9577\u3055 2^k \u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\u3067 2^k+1 \u306B\
    \u3059\u308B\ntemplate <typename mint, bool transposed = false>\nvoid ntt_doubling(vector<mint>&\
    \ a) {\n  static array<mint, 30> root;\n  static bool prepared = 0;\n  if (!prepared)\
    \ {\n    prepared = 1;\n    const int rank2 = mint::ntt_info().fi;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    FOR_R(i, rank2) { root[i] = root[i + 1] * root[i\
    \ + 1]; }\n  }\n\n  if constexpr (!transposed) {\n    const int M = (int)a.size();\n\
    \    auto b = a;\n    ntt(b, 1);\n    mint r = 1, zeta = root[topbit(2 * M)];\n\
    \    FOR(i, M) b[i] *= r, r *= zeta;\n    ntt(b, 0);\n    copy(begin(b), end(b),\
    \ back_inserter(a));\n  } else {\n    const int M = len(a) / 2;\n    vc<mint>\
    \ tmp = {a.begin(), a.begin() + M};\n    a = {a.begin() + M, a.end()};\n    transposed_ntt(a,\
    \ 0);\n    mint r = 1, zeta = root[topbit(2 * M)];\n    FOR(i, M) a[i] *= r, r\
    \ *= zeta;\n    transposed_ntt(a, 1);\n    FOR(i, M) a[i] += tmp[i];\n  }\n}\n\
    #line 5 \"poly/convolution_all.hpp\"\n\r\ntemplate <typename T>\r\nvc<T> convolution_all(vc<vc<T>>&\
    \ polys) {\r\n  if (len(polys) == 0) return {T(1)};\r\n  while (1) {\r\n    int\
    \ n = len(polys);\r\n    if (n == 1) break;\r\n    int m = ceil(n, 2);\r\n   \
    \ FOR(i, m) {\r\n      if (2 * i + 1 == n) {\r\n        polys[i] = polys[2 * i];\r\
    \n      } else {\r\n        polys[i] = convolution(polys[2 * i], polys[2 * i +\
    \ 1]);\r\n      }\r\n    }\r\n    polys.resize(m);\r\n  }\r\n  return polys[0];\r\
    \n}\r\n\r\n// product of 1-A[i]x\r\ntemplate <typename mint>\r\nvc<mint> convolution_all_1(vc<mint>\
    \ A) {\r\n  if (!mint::can_ntt()) {\r\n    vvc<mint> polys;\r\n    for (auto&\
    \ a: A) polys.eb(vc<mint>({mint(1), -a}));\r\n    return convolution_all(polys);\r\
    \n  }\r\n  int D = 6;\r\n  using poly = vc<mint>;\r\n  int n = 1;\r\n  while (n\
    \ < len(A)) n *= 2;\r\n  int k = topbit(n);\r\n  vc<mint> F(n), nxt_F(n);\r\n\
    \  FOR(i, len(A)) F[i] = -A[i];\r\n  FOR(d, k) {\r\n    int b = 1 << d;\r\n  \
    \  if (d < D) {\r\n      fill(all(nxt_F), mint(0));\r\n      for (int L = 0; L\
    \ < n; L += 2 * b) {\r\n        FOR(i, b) FOR(j, b) { nxt_F[L + i + j] += F[L\
    \ + i] * F[L + b + j]; }\r\n        FOR(i, b) nxt_F[L + b + i] += F[L + i] + F[L\
    \ + b + i];\r\n      }\r\n    }\r\n    elif (d == D) {\r\n      for (int L = 0;\
    \ L < n; L += 2 * b) {\r\n        poly f1 = {F.begin() + L, F.begin() + L + b};\r\
    \n        poly f2 = {F.begin() + L + b, F.begin() + L + 2 * b};\r\n        f1.resize(2\
    \ * b), f2.resize(2 * b), ntt(f1, 0), ntt(f2, 0);\r\n        FOR(i, b) nxt_F[L\
    \ + i] = f1[i] * f2[i] + f1[i] + f2[i];\r\n        FOR(i, b, 2 * b) nxt_F[L +\
    \ i] = f1[i] * f2[i] - f1[i] - f2[i];\r\n      }\r\n    }\r\n    else {\r\n  \
    \    for (int L = 0; L < n; L += 2 * b) {\r\n        poly f1 = {F.begin() + L,\
    \ F.begin() + L + b};\r\n        poly f2 = {F.begin() + L + b, F.begin() + L +\
    \ 2 * b};\r\n        ntt_doubling(f1), ntt_doubling(f2);\r\n        FOR(i, b)\
    \ nxt_F[L + i] = f1[i] * f2[i] + f1[i] + f2[i];\r\n        FOR(i, b, 2 * b) nxt_F[L\
    \ + i] = f1[i] * f2[i] - f1[i] - f2[i];\r\n      }\r\n    }\r\n    swap(F, nxt_F);\r\
    \n  }\r\n  if (k - 1 >= D) ntt(F, 1);\r\n  F.eb(1), reverse(all(F));\r\n  F.resize(len(A)\
    \ + 1);\r\n  return F;\r\n}\n#line 6 \"test/1_mytest/poly_root_finding.test.cpp\"\
    \n\n// \u76F8\u7570\u306A\u308B 1 \u6B21\u5F0F\u306E\u7A4D\u3001\u91CD\u8907\u5EA6\
    \u307E\u3042\u307E\u3042\u3042\u308B\u304B\u3082\nvoid test_1() {\n  using mint\
    \ = modint998;\n  using poly = vc<mint>;\n  int p = mint::get_mod();\n  FOR(N,\
    \ 50) {\n    FOR(10) {\n      vc<mint> S;\n      FOR(10) S.eb(RNG(0, p));\n  \
    \    vc<poly> polys;\n      vc<mint> roots;\n      FOR(N) {\n        mint a =\
    \ S[RNG(0, 10)];\n        roots.eb(a);\n        polys.eb(poly({-mint(a), mint(1)}));\n\
    \      }\n      UNIQUE(roots);\n      poly f = convolution_all(polys);\n     \
    \ auto ANS = finding_root_of_polynomial(f);\n      sort(all(ANS));\n      assert(roots\
    \ == ANS);\n    }\n  }\n}\n\n// test_1 \u306B\u3082\u3046\u3072\u3068\u3064 N\
    \ \u6B21\u5F0F\u3092\u304B\u3051\u308B\nvoid test_2() {\n  using mint = modint998;\n\
    \  using poly = vc<mint>;\n  int p = mint::get_mod();\n  FOR(N, 50) {\n    FOR(10)\
    \ {\n      vc<mint> S;\n      FOR(10) S.eb(RNG(0, p));\n      vc<poly> polys;\n\
    \      vc<mint> roots;\n      FOR(N) {\n        mint a = S[RNG(0, 10)];\n    \
    \    roots.eb(a);\n        polys.eb(poly({-mint(a), mint(1)}));\n      }\n   \
    \   UNIQUE(roots);\n      poly f = convolution_all(polys);\n      vc<mint> g(N\
    \ + 1);\n      FOR(i, N + 1) g[i] = RNG(0, p);\n      f = convolution(f, g);\n\
    \      auto ANS = finding_root_of_polynomial(f);\n      for (auto& r: roots) {\
    \ assert(binary_search(all(ANS), r)); }\n    }\n  }\n}\n\nvoid solve() {\n  int\
    \ a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n\
    \  test_1();\n  test_2();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"poly/finding_root_of_polynomial.hpp\"\n#include \"poly/convolution_all.hpp\"\
    \n\n// \u76F8\u7570\u306A\u308B 1 \u6B21\u5F0F\u306E\u7A4D\u3001\u91CD\u8907\u5EA6\
    \u307E\u3042\u307E\u3042\u3042\u308B\u304B\u3082\nvoid test_1() {\n  using mint\
    \ = modint998;\n  using poly = vc<mint>;\n  int p = mint::get_mod();\n  FOR(N,\
    \ 50) {\n    FOR(10) {\n      vc<mint> S;\n      FOR(10) S.eb(RNG(0, p));\n  \
    \    vc<poly> polys;\n      vc<mint> roots;\n      FOR(N) {\n        mint a =\
    \ S[RNG(0, 10)];\n        roots.eb(a);\n        polys.eb(poly({-mint(a), mint(1)}));\n\
    \      }\n      UNIQUE(roots);\n      poly f = convolution_all(polys);\n     \
    \ auto ANS = finding_root_of_polynomial(f);\n      sort(all(ANS));\n      assert(roots\
    \ == ANS);\n    }\n  }\n}\n\n// test_1 \u306B\u3082\u3046\u3072\u3068\u3064 N\
    \ \u6B21\u5F0F\u3092\u304B\u3051\u308B\nvoid test_2() {\n  using mint = modint998;\n\
    \  using poly = vc<mint>;\n  int p = mint::get_mod();\n  FOR(N, 50) {\n    FOR(10)\
    \ {\n      vc<mint> S;\n      FOR(10) S.eb(RNG(0, p));\n      vc<poly> polys;\n\
    \      vc<mint> roots;\n      FOR(N) {\n        mint a = S[RNG(0, 10)];\n    \
    \    roots.eb(a);\n        polys.eb(poly({-mint(a), mint(1)}));\n      }\n   \
    \   UNIQUE(roots);\n      poly f = convolution_all(polys);\n      vc<mint> g(N\
    \ + 1);\n      FOR(i, N + 1) g[i] = RNG(0, p);\n      f = convolution(f, g);\n\
    \      auto ANS = finding_root_of_polynomial(f);\n      for (auto& r: roots) {\
    \ assert(binary_search(all(ANS), r)); }\n    }\n  }\n}\n\nvoid solve() {\n  int\
    \ a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n\
    \  test_1();\n  test_2();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - poly/finding_root_of_polynomial.hpp
  - poly/poly_mod_pow.hpp
  - poly/poly_divmod.hpp
  - poly/fps_inv.hpp
  - poly/count_terms.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  - poly/poly_gcd.hpp
  - random/base.hpp
  - poly/convolution_all.hpp
  - poly/ntt_doubling.hpp
  isVerificationFile: true
  path: test/1_mytest/poly_root_finding.test.cpp
  requiredBy: []
  timestamp: '2024-08-13 23:38:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/poly_root_finding.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/poly_root_finding.test.cpp
- /verify/test/1_mytest/poly_root_finding.test.cpp.html
title: test/1_mytest/poly_root_finding.test.cpp
---