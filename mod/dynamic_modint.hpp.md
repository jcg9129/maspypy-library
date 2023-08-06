---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':question:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':heavy_check_mark:'
    path: nt/four_square.hpp
    title: nt/four_square.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/convolution_mod_107_dmint.test.cpp
    title: test/library_checker/convolution/convolution_mod_107_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/convolution_mod_dmint.test.cpp
    title: test/library_checker/convolution/convolution_mod_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/convolution_mod_setntt.test.cpp
    title: test/library_checker/convolution/convolution_mod_setntt.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
    title: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sqrt_mod.test.cpp
    title: test/library_checker/math/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/exp_of_fps_dmint.test.cpp
    title: test/library_checker/polynomial/exp_of_fps_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/exp_of_fps_sparse_dmint.test.cpp
    title: test/library_checker/polynomial/exp_of_fps_sparse_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/inv_of_fps.test.cpp
    title: test/library_checker/polynomial/inv_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/inv_of_fps_dmint.test.cpp
    title: test/library_checker/polynomial/inv_of_fps_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/inv_of_fps_sparse_dmint.test.cpp
    title: test/library_checker/polynomial/inv_of_fps_sparse_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/log_of_fps_dmint.test.cpp
    title: test/library_checker/polynomial/log_of_fps_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/log_of_fps_sparse_dmint.test.cpp
    title: test/library_checker/polynomial/log_of_fps_sparse_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/pow_of_fps_dmint.test.cpp
    title: test/library_checker/polynomial/pow_of_fps_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/pow_of_fps_sparse_dmint.test.cpp
    title: test/library_checker/polynomial/pow_of_fps_sparse_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/31bit_modint.test.cpp
    title: test/mytest/31bit_modint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/four_square.test.cpp
    title: test/mytest/four_square.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1667.test.cpp
    title: test/yukicoder/1667.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc222g.test.cpp
    title: test_atcoder/abc222g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc270_g.test.cpp
    title: test_atcoder/abc270_g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc281g.test.cpp
    title: test_atcoder/abc281g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template\
    \ <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
    \  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint(q));\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n);\n  if (n >= mod) return\
    \ 0;\n  static vector<mint> dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint\
    \ fact_inv(int n) {\n  static vector<mint> dat = {1, 1};\n  if (n < 0) return\
    \ mint(0);\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts...\
    \ xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename\
    \ mint, class Head, class... Tail>\nmint multinomial(Head &&head, Tail &&... tail)\
    \ {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint>\
    \ C;\n  static int H = 0, W = 0;\n  auto calc = [&](int i, int j) -> mint {\n\
    \    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j]\
    \ + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n     \
    \ C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n\
    \    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n +\
    \ 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n   \
    \ }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool\
    \ large = false, bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  if (dense) return C_dense<mint>(n, k);\n \
    \ if (!large) return multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n \
    \ mint x(1);\n  FOR(i, k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n\
    }\n\ntemplate <typename mint, bool large = false>\nmint C_inv(ll n, ll k) {\n\
    \  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if (!large) return fact_inv<mint>(n)\
    \ * fact<mint>(k) * fact<mint>(n - k);\n  return mint(1) / C<mint, 1>(n, k);\n\
    }\n\n// [x^d] (1-x) ^ {-n} \u306E\u8A08\u7B97\ntemplate <typename mint, bool large\
    \ = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n >= 0);\n\
    \  if (d < 0) return mint(0);\n  if (n == 0) { return (d == 0 ? mint(1) : mint(0));\
    \ }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n#line 2 \"mod/primitive_root.hpp\"\
    \n\r\n#line 2 \"nt/primetest.hpp\"\nstruct m64 {\r\n  using i64 = int64_t;\r\n\
    \  using u64 = uint64_t;\r\n  using u128 = __uint128_t;\r\n\r\n  inline static\
    \ u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod m)\r\n  static void\
    \ set_mod(u64 m) {\r\n    assert((m & 1) == 1);\r\n    m64::m = m;\r\n    n2 =\
    \ -u128(m) % m;\r\n    r = m;\r\n    FOR(_, 5) r *= 2 - m * r;\r\n    r = -r;\r\
    \n    assert(r * m == -1ull);\r\n  }\r\n  static u64 reduce(u128 b) { return (b\
    \ + u128(u64(b) * r) * m) >> 64; }\r\n\r\n  u64 x;\r\n  m64() : x(0) {}\r\n  m64(u64\
    \ x) : x(reduce(u128(x) * n2)){};\r\n  u64 val() const {\r\n    u64 y = reduce(x);\r\
    \n    return y >= m ? y - m : y;\r\n  }\r\n  m64 &operator+=(m64 y) {\r\n    x\
    \ += y.x - (m << 1);\r\n    x = (i64(x) < 0 ? x + (m << 1) : x);\r\n    return\
    \ *this;\r\n  }\r\n  m64 &operator-=(m64 y) {\r\n    x -= y.x;\r\n    x = (i64(x)\
    \ < 0 ? x + (m << 1) : x);\r\n    return *this;\r\n  }\r\n  m64 &operator*=(m64\
    \ y) {\r\n    x = reduce(u128(x) * y.x);\r\n    return *this;\r\n  }\r\n  m64\
    \ operator+(m64 y) const { return m64(*this) += y; }\r\n  m64 operator-(m64 y)\
    \ const { return m64(*this) -= y; }\r\n  m64 operator*(m64 y) const { return m64(*this)\
    \ *= y; }\r\n  bool operator==(m64 y) const {\r\n    return (x >= m ? x - m :\
    \ x) == (y.x >= m ? y.x - m : y.x);\r\n  }\r\n  bool operator!=(m64 y) const {\
    \ return not operator==(y); }\r\n  m64 pow(u64 n) const {\r\n    m64 y = 1, z\
    \ = *this;\r\n    for (; n; n >>= 1, z *= z)\r\n      if (n & 1) y *= z;\r\n \
    \   return y;\r\n  }\r\n};\r\n\r\nbool primetest(const uint64_t x) {\r\n  using\
    \ u64 = uint64_t;\r\n  if (x == 2 or x == 3 or x == 5 or x == 7) return true;\r\
    \n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;\r\n\
    \  if (x < 121) return x > 1;\r\n  const u64 d = (x - 1) >> __builtin_ctzll(x\
    \ - 1);\r\n  m64::set_mod(x);\r\n  const m64 one(1), minus_one(x - 1);\r\n  auto\
    \ ok = [&](u64 a) {\r\n    auto y = m64(a).pow(d);\r\n    u64 t = d;\r\n    while\
    \ (y != one and y != minus_one and t != x - 1) y *= y, t <<= 1;\r\n    if (y !=\
    \ minus_one and t % 2 == 0) return false;\r\n    return true;\r\n  };\r\n  if\
    \ (x < (1ull << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if (not ok(a))\
    \ return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\r\n      if (x <= a) return true;\r\n      if (not ok(a))\
    \ return false;\r\n    }\r\n  }\r\n  return true;\r\n}\n#line 3 \"nt/factor.hpp\"\
    \n\nmt19937_64 rng_mt{random_device{}()};\nll rnd(ll n) { return uniform_int_distribution<ll>(0,\
    \ n - 1)(rng_mt); }\n\nll rho(ll n, ll c) {\n  m64::set_mod(n);\n  assert(n >\
    \ 1);\n  const m64 cc(c);\n  auto f = [&](m64 x) { return x * x + cc; };\n  m64\
    \ x = 1, y = 2, z = 1, q = 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\
    \ // ?\n  for (ll r = 1; g == 1; r <<= 1) {\n    x = y;\n    FOR(_, r) y = f(y);\n\
    \    for (ll k = 0; k < r and g == 1; k += m) {\n      z = y;\n      FOR(_, min(m,\
    \ r - k)) y = f(y), q *= x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if\
    \ (g == n) do {\n      z = f(z);\n      g = gcd((x - z).val(), n);\n    } while\
    \ (g == 1);\n  return g;\n}\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n\
    \  if (primetest(n)) return n;\n  FOR(_, 100) {\n    ll m = rho(n, rnd(n));\n\
    \    if (primetest(m)) return m;\n    n = m;\n  }\n  cerr << \"failed\" << endl;\n\
    \  assert(false);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\u304F\u308C\
    \u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll, int>>\
    \ pf;\n  FOR3(p, 2, 100) {\n    if (p * p > n) break;\n    if (n % p == 0) {\n\
    \      ll e = 0;\n      do { n /= p, e += 1; } while (n % p == 0);\n      pf.eb(p,\
    \ e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n    ll\
    \ e = 0;\n    do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n \
    \ }\n  sort(all(pf));\n  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n,\
    \ vc<int>& lpf) {\n  vc<pair<ll, int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n\
    \    int e = 0;\n    while (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n\
    \    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return 0;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n#line 3 \"mod/mod_pow.hpp\"\n\r\n// int\r\nll mod_pow(ll a, ll\
    \ n, int mod) {\r\n  assert(n >= 0);\r\n  a %= mod;\r\n  if (a < 0) a += mod;\r\
    \n  Barrett bt(mod);\r\n  ll p = a, v = bt.modulo(1);\r\n  while (n) {\r\n   \
    \ if (n & 1) v = bt.mul(v, p);\r\n    p = bt.mul(p, p);\r\n    n >>= 1;\r\n  }\r\
    \n  return v;\r\n}\r\n\r\nll mod_pow_long(ll a, ll n, ll mod) {\r\n  assert(n\
    \ >= 0);\r\n  a %= mod;\r\n  if (a < 0) a += mod;\r\n  ll p = a, v = 1 % mod;\r\
    \n  while (n) {\r\n    if (n & 1) v = i128(v) * p % mod;\r\n    p = i128(p) *\
    \ p % mod;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 6 \"mod/primitive_root.hpp\"\
    \n\r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n\
    \  auto is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\
    \n  while (1) {\r\n    int x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n \
    \ }\r\n  return -1;\r\n}\r\n\r\nll primitive_root_long(ll p) {\r\n  auto pf =\
    \ factor(p - 1);\r\n  auto is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q,\
    \ e]: pf)\r\n      if (mod_pow_long(g, (p - 1) / q, p) == 1) return false;\r\n\
    \    return true;\r\n  };\r\n  while (1) {\r\n    ll x = RNG(1, p);\r\n    if\
    \ (is_ok(x)) return x;\r\n  }\r\n  return -1;\r\n}\r\n#line 5 \"mod/dynamic_modint.hpp\"\
    \n\nstruct Dynamic_Modint {\n  static constexpr bool is_modint = true;\n  using\
    \ mint = Dynamic_Modint;\n  u32 val;\n  static Barrett bt;\n  static u32 umod()\
    \ { return bt.umod(); }\n\n  static int get_mod() { return (int)(bt.umod()); }\n\
    \  static void set_mod(int m) {\n    assert(1 <= m);\n    bt = Barrett(m);\n \
    \ }\n\n  Dynamic_Modint() : val(0) {}\n  Dynamic_Modint(u32 x) : val(bt.modulo(x))\
    \ {}\n  Dynamic_Modint(u64 x) : val(bt.modulo(x)) {}\n  Dynamic_Modint(int x)\
    \ : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n  Dynamic_Modint(ll x) :\
    \ val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n\n  mint& operator+=(const\
    \ mint& rhs) {\n    val = (val += rhs.val) < umod() ? val : val - umod();\n  \
    \  return *this;\n  }\n  mint& operator-=(const mint& rhs) {\n    val = (val +=\
    \ umod() - rhs.val) < umod() ? val : val - umod();\n    return *this;\n  }\n \
    \ mint& operator*=(const mint& rhs) {\n    val = bt.mul(val, rhs.val);\n    return\
    \ *this;\n  }\n  mint& operator/=(const mint& rhs) { return *this = *this * rhs.inverse();\
    \ }\n  mint operator-() const { return mint() - *this; }\n  mint pow(ll n) const\
    \ {\n    assert(0 <= n);\n    mint x = *this, r = 1;\n    while (n) {\n      if\
    \ (n & 1) r *= x;\n      x *= x, n >>= 1;\n    }\n    return r;\n  }\n  mint inverse()\
    \ const {\n    int x = val, mod = get_mod();\n    int a = x, b = mod, u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\n    }\n    if (u < 0) u += mod;\n    return u;\n  }\n\n  friend\
    \ mint operator+(const mint& lhs, const mint& rhs) {\n    return mint(lhs) +=\
    \ rhs;\n  }\n  friend mint operator-(const mint& lhs, const mint& rhs) {\n   \
    \ return mint(lhs) -= rhs;\n  }\n  friend mint operator*(const mint& lhs, const\
    \ mint& rhs) {\n    return mint(lhs) *= rhs;\n  }\n  friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n    return mint(lhs) /= rhs;\n  }\n  friend bool\
    \ operator==(const mint& lhs, const mint& rhs) {\n    return lhs.val == rhs.val;\n\
    \  }\n  friend bool operator!=(const mint& lhs, const mint& rhs) {\n    return\
    \ lhs.val != rhs.val;\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val);\
    \ }\n  void read() {\n    fastio::scanner.read(val);\n    val = bt.modulo(val);\n\
    \  }\n#endif\n  static pair<int, int>& get_ntt() {\n    static pair<int, int>\
    \ p = {-1, -1};\n    return p;\n  }\n  static void set_ntt_info() {\n    int mod\
    \ = get_mod();\n    int k = lowbit(mod - 1);\n    int r = primitive_root(mod);\n\
    \    r = mod_pow(r, (mod - 1) >> k, mod);\n    get_ntt() = {k, r};\n  }\n  static\
    \ pair<int, int> ntt_info() { return get_ntt(); }\n  static bool can_ntt() { return\
    \ ntt_info().fi != -1; }\n};\n\nusing dmint = Dynamic_Modint;\nBarrett dmint::bt(1);\n"
  code: "#pragma once\n#include \"mod/modint_common.hpp\"\n#include \"mod/primitive_root.hpp\"\
    \n#include \"mod/barrett.hpp\"\n\nstruct Dynamic_Modint {\n  static constexpr\
    \ bool is_modint = true;\n  using mint = Dynamic_Modint;\n  u32 val;\n  static\
    \ Barrett bt;\n  static u32 umod() { return bt.umod(); }\n\n  static int get_mod()\
    \ { return (int)(bt.umod()); }\n  static void set_mod(int m) {\n    assert(1 <=\
    \ m);\n    bt = Barrett(m);\n  }\n\n  Dynamic_Modint() : val(0) {}\n  Dynamic_Modint(u32\
    \ x) : val(bt.modulo(x)) {}\n  Dynamic_Modint(u64 x) : val(bt.modulo(x)) {}\n\
    \  Dynamic_Modint(int x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n\
    \  Dynamic_Modint(ll x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n\n\
    \  mint& operator+=(const mint& rhs) {\n    val = (val += rhs.val) < umod() ?\
    \ val : val - umod();\n    return *this;\n  }\n  mint& operator-=(const mint&\
    \ rhs) {\n    val = (val += umod() - rhs.val) < umod() ? val : val - umod();\n\
    \    return *this;\n  }\n  mint& operator*=(const mint& rhs) {\n    val = bt.mul(val,\
    \ rhs.val);\n    return *this;\n  }\n  mint& operator/=(const mint& rhs) { return\
    \ *this = *this * rhs.inverse(); }\n  mint operator-() const { return mint() -\
    \ *this; }\n  mint pow(ll n) const {\n    assert(0 <= n);\n    mint x = *this,\
    \ r = 1;\n    while (n) {\n      if (n & 1) r *= x;\n      x *= x, n >>= 1;\n\
    \    }\n    return r;\n  }\n  mint inverse() const {\n    int x = val, mod = get_mod();\n\
    \    int a = x, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a /\
    \ b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    if (u < 0) u\
    \ += mod;\n    return u;\n  }\n\n  friend mint operator+(const mint& lhs, const\
    \ mint& rhs) {\n    return mint(lhs) += rhs;\n  }\n  friend mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n    return mint(lhs) -= rhs;\n  }\n  friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n    return mint(lhs) *= rhs;\n\
    \  }\n  friend mint operator/(const mint& lhs, const mint& rhs) {\n    return\
    \ mint(lhs) /= rhs;\n  }\n  friend bool operator==(const mint& lhs, const mint&\
    \ rhs) {\n    return lhs.val == rhs.val;\n  }\n  friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n    return lhs.val != rhs.val;\n  }\n#ifdef FASTIO\n\
    \  void write() { fastio::printer.write(val); }\n  void read() {\n    fastio::scanner.read(val);\n\
    \    val = bt.modulo(val);\n  }\n#endif\n  static pair<int, int>& get_ntt() {\n\
    \    static pair<int, int> p = {-1, -1};\n    return p;\n  }\n  static void set_ntt_info()\
    \ {\n    int mod = get_mod();\n    int k = lowbit(mod - 1);\n    int r = primitive_root(mod);\n\
    \    r = mod_pow(r, (mod - 1) >> k, mod);\n    get_ntt() = {k, r};\n  }\n  static\
    \ pair<int, int> ntt_info() { return get_ntt(); }\n  static bool can_ntt() { return\
    \ ntt_info().fi != -1; }\n};\n\nusing dmint = Dynamic_Modint;\nBarrett dmint::bt(1);"
  dependsOn:
  - mod/modint_common.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - nt/primetest.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  - random/base.hpp
  isVerificationFile: false
  path: mod/dynamic_modint.hpp
  requiredBy:
  - mod/mod_log.hpp
  - nt/four_square.hpp
  timestamp: '2023-08-07 02:24:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/four_square.test.cpp
  - test/mytest/31bit_modint.test.cpp
  - test/yukicoder/1667.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/convolution/convolution_mod_107_dmint.test.cpp
  - test/library_checker/convolution/convolution_mod_dmint.test.cpp
  - test/library_checker/convolution/convolution_mod_setntt.test.cpp
  - test/library_checker/polynomial/log_of_fps_sparse_dmint.test.cpp
  - test/library_checker/polynomial/inv_of_fps_sparse_dmint.test.cpp
  - test/library_checker/polynomial/inv_of_fps_dmint.test.cpp
  - test/library_checker/polynomial/exp_of_fps_sparse_dmint.test.cpp
  - test/library_checker/polynomial/exp_of_fps_dmint.test.cpp
  - test/library_checker/polynomial/log_of_fps_dmint.test.cpp
  - test/library_checker/polynomial/pow_of_fps_sparse_dmint.test.cpp
  - test/library_checker/polynomial/inv_of_fps.test.cpp
  - test/library_checker/polynomial/pow_of_fps_dmint.test.cpp
  - test_atcoder/abc281g.test.cpp
  - test_atcoder/abc270_g.test.cpp
  - test_atcoder/abc222g.test.cpp
documentation_of: mod/dynamic_modint.hpp
layout: document
redirect_from:
- /library/mod/dynamic_modint.hpp
- /library/mod/dynamic_modint.hpp.html
title: mod/dynamic_modint.hpp
---
