---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: mod/dynamic_modint.hpp
    title: mod/dynamic_modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/four_square.test.cpp
    title: test/mytest/four_square.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetest.hpp\"\nstruct m64 {\r\n  using i64 = int64_t;\r\
    \n  using u64 = uint64_t;\r\n  using u128 = __uint128_t;\r\n\r\n  inline static\
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
    \    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"random/base.hpp\"\n\nu64\
    \ RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/mod_sqrt.hpp\"\
    \n\r\ntemplate <typename mint>\r\nmint mod_sqrt(mint a) {\r\n  int p = mint::get_mod();\r\
    \n  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k = (p - 1) / 2;\r\
    \n  if (a.pow(k) != 1) return 0;\r\n  auto find = [&]() -> pair<mint, mint> {\r\
    \n    while (1) {\r\n      mint b = RNG(2, p);\r\n      mint D = b * b - a;\r\n\
    \      if (D == 0) return {b, D};\r\n      if (D.pow(k) != mint(1)) return {b,\
    \ D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n  if (D == 0) return b;\r\
    \n  ++k;\r\n  // (b + sqrt(D))^k\r\n  mint f0 = b, f1 = 1;\r\n  mint g0 = 1, g1\
    \ = 0;\r\n  while (k) {\r\n    if (k & 1) { tie(g0, g1) = mp(f0 * g0 + D * f1\
    \ * g1, f1 * g0 + f0 * g1); }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 * f1, mint(2)\
    \ * f0 * f1);\r\n    k >>= 1;\r\n  }\r\n  return g0;\r\n}\r\n#line 2 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n  static\
    \ vector<mint> dat = {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n \
    \ while (len(dat) <= n) {\n    int k = len(dat);\n    int q = (mod + k - 1) /\
    \ k;\n    dat.eb(dat[k * q - mod] * mint(q));\n  }\n  return dat[n];\n}\n\ntemplate\
    \ <typename mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(0 <= n);\n  if (n >= mod) return 0;\n  static vector<mint> dat = {1,\
    \ 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint(len(dat)));\n \
    \ return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
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
    \ n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if (dense)\
    \ return C_dense<mint>(n, k);\n  if (!large) return multinomial<mint>(n, k, n\
    \ - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n \
    \ return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d] (1-x) ^ {-n} \u306E\u8A08\u7B97\n\
    template <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\
    \ return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large, dense>(n + d\
    \ - 1, d);\n}\n#line 2 \"mod/primitive_root.hpp\"\n\r\n#line 2 \"mod/barrett.hpp\"\
    \n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    \ p % mod;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n#line 6 \"mod/primitive_root.hpp\"\
    \n\r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n\
    \  auto is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\
    \n  while (1) {\r\n    int x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n \
    \ }\r\n  return -1;\r\n}\r\n\r\nll primitive_root_long(ll p) {\r\n  auto pf =\
    \ factor(p - 1);\r\n  auto is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q,\
    \ e]: pf)\r\n      if (mod_pow_long(g, (p - 1) / q, p) == 1) return false;\r\n\
    \    return true;\r\n  };\r\n  while (1) {\r\n    ll x = RNG(1, p);\r\n    if\
    \ (is_ok(x)) return x;\r\n  }\r\n  return -1;\r\n}\r\n#line 5 \"mod/dynamic_modint.hpp\"\
    \n\ntemplate <class T>\nusing is_signed_int =\n    typename std::conditional<(is_integral<T>::value\n\
    \                               && std::is_signed<T>::value),\n              \
    \                std::true_type, std::false_type>::type;\n\ntemplate <class T>\n\
    using is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\n\
    \                               && std::is_unsigned<T>::value),\n            \
    \                  std::true_type, std::false_type>::type;\ntemplate <class T>\n\
    using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\ntemplate\
    \ <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \nstruct Dynamic_Modint {\n  static constexpr bool is_modint = true;\n  using\
    \ mint = Dynamic_Modint;\n  u32 val;\n  static Barrett bt;\n  static u32 umod()\
    \ { return bt.umod(); }\n\n  static int get_mod() { return (int)(bt.umod()); }\n\
    \  static void set_mod(int m) {\n    assert(1 <= m);\n    bt = Barrett(m);\n \
    \ }\n\n  Dynamic_Modint() : val(0) {}\n  template <class T, is_signed_int_t<T>*\
    \ = nullptr>\n  Dynamic_Modint(T v) {\n    int x = v % get_mod();\n    if (x <\
    \ 0) x += get_mod();\n    val = u32(x);\n  }\n  template <class T, is_unsigned_int_t<T>*\
    \ = nullptr>\n  Dynamic_Modint(T v) {\n    val = bt.modulo(v);\n  }\n\n  mint&\
    \ operator+=(const mint& rhs) {\n    val += rhs.val;\n    if (val >= umod()) val\
    \ -= umod();\n    return *this;\n  }\n  mint& operator-=(const mint& rhs) {\n\
    \    val += umod() - rhs.val;\n    if (val >= umod()) val -= umod();\n    return\
    \ *this;\n  }\n  mint& operator*=(const mint& rhs) {\n    val = bt.mul(val, rhs.val);\n\
    \    return *this;\n  }\n  mint& operator/=(const mint& rhs) { return *this =\
    \ *this * rhs.inverse(); }\n  mint operator-() const { return mint() - *this;\
    \ }\n  mint pow(ll n) const {\n    assert(0 <= n);\n    mint x = *this, r = 1;\n\
    \    while (n) {\n      if (n & 1) r *= x;\n      x *= x;\n      n >>= 1;\n  \
    \  }\n    return r;\n  }\n  mint inverse() const {\n    int x = val;\n    int\
    \ mod = get_mod();\n    ll a = x, b = mod, u = 1, v = 0, t;\n    while (b > 0)\
    \ {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n\
    \    if (u < 0) u += mod;\n    return u;\n  }\n\n  friend mint operator+(const\
    \ mint& lhs, const mint& rhs) {\n    return mint(lhs) += rhs;\n  }\n  friend mint\
    \ operator-(const mint& lhs, const mint& rhs) {\n    return mint(lhs) -= rhs;\n\
    \  }\n  friend mint operator*(const mint& lhs, const mint& rhs) {\n    return\
    \ mint(lhs) *= rhs;\n  }\n  friend mint operator/(const mint& lhs, const mint&\
    \ rhs) {\n    return mint(lhs) /= rhs;\n  }\n  friend bool operator==(const mint&\
    \ lhs, const mint& rhs) {\n    return lhs.val == rhs.val;\n  }\n  friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n    return lhs.val != rhs.val;\n\
    \  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val); }\n  void read()\
    \ {\n    fastio::scanner.read(val);\n    assert(0 <= val && val < u32(get_mod()));\n\
    \  }\n#endif\n  static pair<int, int>& get_ntt() {\n    static pair<int, int>\
    \ p = {-1, -1};\n    return p;\n  }\n  static void set_ntt_info() {\n    int mod\
    \ = get_mod();\n    int k = lowbit(mod - 1);\n    int r = primitive_root(mod);\n\
    \    r = mod_pow(r, (mod - 1) >> k, mod);\n    get_ntt() = {k, r};\n  }\n  static\
    \ pair<int, int> ntt_info() { return get_ntt(); }\n  static bool can_ntt() { return\
    \ ntt_info().fi != -1; }\n};\n\nusing dmint = Dynamic_Modint;\nBarrett dmint::bt(1);\n\
    #line 5 \"nt/four_square.hpp\"\n\n// N = a^2+b^2+c^2+d^2 \u3068\u306A\u308B (a,b,c,d)\
    \ \u3092\u3072\u3068\u3064\u8FD4\u3059\ntuple<ll, ll, ll, ll> four_square(ll N)\
    \ {\n  if (N == 0) return {0, 0, 0, 0};\n  using T4 = tuple<ll, ll, ll, ll>;\n\
    \  auto mul = [&](T4 x, T4 y) -> T4 {\n    auto [x1, x2, x3, x4] = x;\n    auto\
    \ [y1, y2, y3, y4] = y;\n    ll z1 = abs(x1 * y1 + x2 * y2 + x3 * y3 + x4 * y4);\n\
    \    ll z2 = abs(x1 * y2 - x2 * y1 + x3 * y4 - x4 * y3);\n    ll z3 = abs(x1 *\
    \ y3 - x2 * y4 - x3 * y1 + x4 * y2);\n    ll z4 = abs(x1 * y4 + x2 * y3 - x3 *\
    \ y2 - x4 * y1);\n    return {z1, z2, z3, z4};\n  };\n\n  auto solve_p = [&](ll\
    \ p) -> T4 {\n    if (p == 2) return {1, 1, 0, 0};\n    using mint = dmint;\n\
    \    mint::set_mod(p);\n    auto [a, b] = [&]() -> pair<ll, ll> {\n      while\
    \ (1) {\n        ll a = RNG(0, p);\n        ll bb = (p - 1 - a * a) % p;\n   \
    \     if (bb < 0) bb += p;\n        ll b = mod_sqrt<mint>(bb).val;\n        if\
    \ ((a * a + b * b + 1) % p == 0) return {a, b};\n      }\n      return {0, 0};\n\
    \    }();\n    T4 x = {a, b, 1, 0};\n    while (1) {\n      auto& [x1, x2, x3,\
    \ x4] = x;\n      chmin(x1, p - x1), chmin(x2, p - x2), chmin(x3, p - x3),\n \
    \         chmin(x4, p - x4);\n      ll m = (x1 * x1 + x2 * x2 + x3 * x3 + x4 *\
    \ x4) / p;\n      if (m == 1) break;\n      ll y1 = x1 % m, y2 = x2 % m, y3 =\
    \ x3 % m, y4 = x4 % m;\n      if (y1 > m / 2) y1 -= m;\n      if (y2 > m / 2)\
    \ y2 -= m;\n      if (y3 > m / 2) y3 -= m;\n      if (y4 > m / 2) y4 -= m;\n \
    \     auto [z1, z2, z3, z4] = mul(x, {y1, y2, y3, y4});\n      x = mt(z1 / m,\
    \ z2 / m, z3 / m, z4 / m);\n    }\n    return x;\n  };\n  T4 x = {1, 0, 0, 0};\n\
    \  for (auto&& [p, e]: factor(N)) { FOR(e) x = mul(x, solve_p(p)); }\n  return\
    \ x;\n}\n"
  code: "#include \"nt/factor.hpp\"\n#include \"random/base.hpp\"\n#include \"mod/mod_sqrt.hpp\"\
    \n#include \"mod/dynamic_modint.hpp\"\n\n// N = a^2+b^2+c^2+d^2 \u3068\u306A\u308B\
    \ (a,b,c,d) \u3092\u3072\u3068\u3064\u8FD4\u3059\ntuple<ll, ll, ll, ll> four_square(ll\
    \ N) {\n  if (N == 0) return {0, 0, 0, 0};\n  using T4 = tuple<ll, ll, ll, ll>;\n\
    \  auto mul = [&](T4 x, T4 y) -> T4 {\n    auto [x1, x2, x3, x4] = x;\n    auto\
    \ [y1, y2, y3, y4] = y;\n    ll z1 = abs(x1 * y1 + x2 * y2 + x3 * y3 + x4 * y4);\n\
    \    ll z2 = abs(x1 * y2 - x2 * y1 + x3 * y4 - x4 * y3);\n    ll z3 = abs(x1 *\
    \ y3 - x2 * y4 - x3 * y1 + x4 * y2);\n    ll z4 = abs(x1 * y4 + x2 * y3 - x3 *\
    \ y2 - x4 * y1);\n    return {z1, z2, z3, z4};\n  };\n\n  auto solve_p = [&](ll\
    \ p) -> T4 {\n    if (p == 2) return {1, 1, 0, 0};\n    using mint = dmint;\n\
    \    mint::set_mod(p);\n    auto [a, b] = [&]() -> pair<ll, ll> {\n      while\
    \ (1) {\n        ll a = RNG(0, p);\n        ll bb = (p - 1 - a * a) % p;\n   \
    \     if (bb < 0) bb += p;\n        ll b = mod_sqrt<mint>(bb).val;\n        if\
    \ ((a * a + b * b + 1) % p == 0) return {a, b};\n      }\n      return {0, 0};\n\
    \    }();\n    T4 x = {a, b, 1, 0};\n    while (1) {\n      auto& [x1, x2, x3,\
    \ x4] = x;\n      chmin(x1, p - x1), chmin(x2, p - x2), chmin(x3, p - x3),\n \
    \         chmin(x4, p - x4);\n      ll m = (x1 * x1 + x2 * x2 + x3 * x3 + x4 *\
    \ x4) / p;\n      if (m == 1) break;\n      ll y1 = x1 % m, y2 = x2 % m, y3 =\
    \ x3 % m, y4 = x4 % m;\n      if (y1 > m / 2) y1 -= m;\n      if (y2 > m / 2)\
    \ y2 -= m;\n      if (y3 > m / 2) y3 -= m;\n      if (y4 > m / 2) y4 -= m;\n \
    \     auto [z1, z2, z3, z4] = mul(x, {y1, y2, y3, y4});\n      x = mt(z1 / m,\
    \ z2 / m, z3 / m, z4 / m);\n    }\n    return x;\n  };\n  T4 x = {1, 0, 0, 0};\n\
    \  for (auto&& [p, e]: factor(N)) { FOR(e) x = mul(x, solve_p(p)); }\n  return\
    \ x;\n}\n"
  dependsOn:
  - nt/factor.hpp
  - nt/primetest.hpp
  - random/base.hpp
  - mod/mod_sqrt.hpp
  - mod/dynamic_modint.hpp
  - mod/modint_common.hpp
  - mod/primitive_root.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  isVerificationFile: false
  path: nt/four_square.hpp
  requiredBy: []
  timestamp: '2023-07-25 22:13:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/four_square.test.cpp
documentation_of: nt/four_square.hpp
layout: document
redirect_from:
- /library/nt/four_square.hpp
- /library/nt/four_square.hpp.html
title: nt/four_square.hpp
---
