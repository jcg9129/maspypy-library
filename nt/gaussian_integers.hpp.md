---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1593.test.cpp
    title: test/yukicoder/1593.test.cpp
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
    \ * b); }\n};\n#line 3 \"mod/mod_pow.hpp\"\n\r\nll mod_pow(ll a, ll n, int mod)\
    \ {\r\n  assert(n >= 0);\r\n  a %= mod;\r\n  if (a < 0) a += mod;\r\n  Barrett\
    \ bt(mod);\r\n  ll p = a, v = bt.modulo(1);\r\n  while (n) {\r\n    if (n & 1)\
    \ v = bt.mul(v, p);\r\n    p = bt.mul(p, p);\r\n    n >>= 1;\r\n  }\r\n  return\
    \ v;\r\n}\r\n\r\nll mod_pow_64(ll a, ll n, ll mod) {\r\n  assert(n >= 0);\r\n\
    \  a %= mod;\r\n  if (a < 0) a += mod;\r\n  ll p = a, v = 1 % mod;\r\n  while\
    \ (n) {\r\n    if (n & 1) v = i128(v) * p % mod;\r\n    p = i128(p) * p % mod;\r\
    \n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n#line 3 \"nt/gaussian_integers.hpp\"\
    \n\r\ntemplate <typename T>\r\nstruct Gaussian_Integer {\r\n  T x, y;\r\n  using\
    \ G = Gaussian_Integer;\r\n\r\n  Gaussian_Integer(T x = 0, T y = 0) : x(x), y(y)\
    \ {}\r\n  Gaussian_Integer(pair<T, T> p) : x(p.fi), y(p.se) {}\r\n\r\n  T norm()\
    \ const { return x * x + y * y; }\r\n  G conjugate() const { return G(x, -y);\
    \ }\r\n\r\n  G &operator+=(const G &g) {\r\n    x += g.x, y += g.y;\r\n    return\
    \ *this;\r\n  }\r\n  G &operator-=(const G &g) {\r\n    x -= g.x, y -= g.y;\r\n\
    \    return *this;\r\n  }\r\n  G &operator*=(const G &g) {\r\n    tie(x, y) =\
    \ mp(x * g.x - y * g.y, x * g.y + y * g.x);\r\n    return *this;\r\n  }\r\n  G\
    \ &operator/=(const G &g) {\r\n    *this *= g.conjugate();\r\n    T n = g.norm();\r\
    \n    x = floor(x + n / 2, n);\r\n    y = floor(y + n / 2, n);\r\n    return *this;\r\
    \n  }\r\n  G &operator%=(const G &g) {\r\n    auto q = G(*this) / g;\r\n    q\
    \ *= g;\r\n    (*this) -= q;\r\n    return *this;\r\n  }\r\n  G operator-() {\
    \ return G(-x, -y); }\r\n  G operator+(const G &g) { return G(*this) += g; }\r\
    \n  G operator-(const G &g) { return G(*this) -= g; }\r\n  G operator*(const G\
    \ &g) { return G(*this) *= g; }\r\n  G operator/(const G &g) { return G(*this)\
    \ /= g; }\r\n  G operator%(const G &g) { return G(*this) %= g; }\r\n  bool operator==(const\
    \ G &g) { return (x == g.x && y == g.y); }\r\n\r\n  static G gcd(G a, G b) {\r\
    \n    while (b.x != 0 || b.y != 0) {\r\n      a %= b;\r\n      swap(a, b);\r\n\
    \    }\r\n    return a;\r\n  }\r\n\r\n  // (g,x,y) s.t ax+by=g\r\n  static tuple<G,\
    \ G, G> extgcd(G a, G b) {\r\n    if (b.x != 0 || b.y != 0) {\r\n      G q = a\
    \ / b;\r\n      auto [g, x, y] = extgcd(b, a - q * b);\r\n      return {g, y,\
    \ x - q * y};\r\n    }\r\n    return {a, G{1, 0}, G{0, 0}};\r\n  }\r\n};\r\n\r\
    \ntemplate <typename T>\r\nvc<Gaussian_Integer<T>> solve_norm_equation_factor(vc<pair<ll,\
    \ int>> pfs) {\r\n  using G = Gaussian_Integer<T>;\r\n  vc<G> res;\r\n  for (auto\
    \ &&[p, e]: pfs) {\r\n    if (p % 4 == 3 && e % 2 == 1) return {};\r\n  }\r\n\
    \  auto find = [&](T p) -> G {\r\n    // p \u306F\u7D20\u6570. \u30CE\u30EB\u30E0\
    \ p \u306E\u30AC\u30A6\u30B9\u6574\u6570\u3092\u3072\u3068\u3064\u898B\u3064\u3051\
    \u308B\r\n    if (p == 2) return G(1, 1);\r\n    // x^2 = -1 mod p \u3092\u3072\
    \u3068\u3064\u898B\u3064\u3051\u308B\r\n    T x = [&]() -> T {\r\n      T x =\
    \ 1;\r\n      while (1) {\r\n        ++x;\r\n        T pow_x = 1;\r\n        if\
    \ (p < (1 << 30)) {\r\n          pow_x = mod_pow(x, (p - 1) / 4, p);\r\n     \
    \     if (pow_x * pow_x % p == p - 1) return pow_x;\r\n        } else {\r\n  \
    \        pow_x = mod_pow_64(x, (p - 1) / 4, p);\r\n          if (i128(pow_x) *\
    \ pow_x % p == p - 1) return pow_x;\r\n        }\r\n      }\r\n      return -1;\r\
    \n    }();\r\n    assert(x != -1);\r\n    // x \u306F\u975E\u5270\u4F59\r\n  \
    \  G a(p, 0), b(x, 1);\r\n    a = G::gcd(a, b);\r\n    assert(a.norm() == p);\r\
    \n    return a;\r\n  };\r\n\r\n  res.eb(G(1, 0));\r\n  for (auto &&[p, e]: pfs)\
    \ {\r\n    if (p % 4 == 3) {\r\n      T pp = 1;\r\n      FOR(e / 2) pp *= p;\r\
    \n      for (auto &&g: res) {\r\n        g.x *= pp;\r\n        g.y *= pp;\r\n\
    \      }\r\n      continue;\r\n    }\r\n    auto pi = find(p);\r\n    vc<G> pows(e\
    \ + 1);\r\n    pows[0] = G(1, 0);\r\n    FOR(i, e) pows[i + 1] = pows[i] * pi;\r\
    \n    if (p == 2) {\r\n      for (auto &&g: res) g *= pows[e];\r\n      continue;\r\
    \n    }\r\n    vc<G> pis(e + 1);\r\n    FOR(j, e + 1) { pis[j] = pows[j] * (pows[e\
    \ - j].conjugate()); }\r\n    vc<G> new_res;\r\n    new_res.reserve(len(res) *\
    \ (e + 1));\r\n    for (auto &&g: res) {\r\n      for (auto &&a: pis) { new_res.eb(g\
    \ * a); }\r\n    }\r\n    swap(res, new_res);\r\n  }\r\n\r\n  for (auto &&g: res)\
    \ {\r\n    while (g.x <= 0 || g.y < 0) { g = G(-g.y, g.x); }\r\n  }\r\n  return\
    \ res;\r\n}\r\n\r\n// i128 \u3092\u4F7F\u3046\u3068 N <= 10^{18} \u3082\u3067\u304D\
    \u308B\r\n// \u30CE\u30EB\u30E0\u304C\u3068\u308C\u308B\u3088\u3046\u306B\u3001\
    2 \u4E57\u3057\u3066\u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044\u578B\u3092\u4F7F\u304A\u3046\r\n// 0 <= arg < 90 \u3068\u306A\u308B\u3082\
    \u306E\u306E\u307F\u8FD4\u3059\u3002\r\n// \u5358\u6570\u500D\u306F\u4F5C\u3089\
    \u306A\u3044\u306E\u3067\u3001\u4F7F\u3046\u3068\u304D\u306B\u6C17\u3092\u4ED8\
    \u3051\u308B\u3002\r\ntemplate <typename T>\r\nvc<Gaussian_Integer<T>> solve_norm_equation(T\
    \ N) {\r\n  using G = Gaussian_Integer<T>;\r\n  vc<G> res;\r\n  if (N < 0) return\
    \ {};\r\n  if (N == 0) {\r\n    res.eb(G(0, 0));\r\n    return res;\r\n  }\r\n\
    \  auto pfs = factor(N);\r\n  return solve_norm_equation_factor<T>(pfs);\r\n}\r\
    \n"
  code: "#include \"nt/factor.hpp\"\r\n#include \"mod/mod_pow.hpp\"\r\n\r\ntemplate\
    \ <typename T>\r\nstruct Gaussian_Integer {\r\n  T x, y;\r\n  using G = Gaussian_Integer;\r\
    \n\r\n  Gaussian_Integer(T x = 0, T y = 0) : x(x), y(y) {}\r\n  Gaussian_Integer(pair<T,\
    \ T> p) : x(p.fi), y(p.se) {}\r\n\r\n  T norm() const { return x * x + y * y;\
    \ }\r\n  G conjugate() const { return G(x, -y); }\r\n\r\n  G &operator+=(const\
    \ G &g) {\r\n    x += g.x, y += g.y;\r\n    return *this;\r\n  }\r\n  G &operator-=(const\
    \ G &g) {\r\n    x -= g.x, y -= g.y;\r\n    return *this;\r\n  }\r\n  G &operator*=(const\
    \ G &g) {\r\n    tie(x, y) = mp(x * g.x - y * g.y, x * g.y + y * g.x);\r\n   \
    \ return *this;\r\n  }\r\n  G &operator/=(const G &g) {\r\n    *this *= g.conjugate();\r\
    \n    T n = g.norm();\r\n    x = floor(x + n / 2, n);\r\n    y = floor(y + n /\
    \ 2, n);\r\n    return *this;\r\n  }\r\n  G &operator%=(const G &g) {\r\n    auto\
    \ q = G(*this) / g;\r\n    q *= g;\r\n    (*this) -= q;\r\n    return *this;\r\
    \n  }\r\n  G operator-() { return G(-x, -y); }\r\n  G operator+(const G &g) {\
    \ return G(*this) += g; }\r\n  G operator-(const G &g) { return G(*this) -= g;\
    \ }\r\n  G operator*(const G &g) { return G(*this) *= g; }\r\n  G operator/(const\
    \ G &g) { return G(*this) /= g; }\r\n  G operator%(const G &g) { return G(*this)\
    \ %= g; }\r\n  bool operator==(const G &g) { return (x == g.x && y == g.y); }\r\
    \n\r\n  static G gcd(G a, G b) {\r\n    while (b.x != 0 || b.y != 0) {\r\n   \
    \   a %= b;\r\n      swap(a, b);\r\n    }\r\n    return a;\r\n  }\r\n\r\n  //\
    \ (g,x,y) s.t ax+by=g\r\n  static tuple<G, G, G> extgcd(G a, G b) {\r\n    if\
    \ (b.x != 0 || b.y != 0) {\r\n      G q = a / b;\r\n      auto [g, x, y] = extgcd(b,\
    \ a - q * b);\r\n      return {g, y, x - q * y};\r\n    }\r\n    return {a, G{1,\
    \ 0}, G{0, 0}};\r\n  }\r\n};\r\n\r\ntemplate <typename T>\r\nvc<Gaussian_Integer<T>>\
    \ solve_norm_equation_factor(vc<pair<ll, int>> pfs) {\r\n  using G = Gaussian_Integer<T>;\r\
    \n  vc<G> res;\r\n  for (auto &&[p, e]: pfs) {\r\n    if (p % 4 == 3 && e % 2\
    \ == 1) return {};\r\n  }\r\n  auto find = [&](T p) -> G {\r\n    // p \u306F\u7D20\
    \u6570. \u30CE\u30EB\u30E0 p \u306E\u30AC\u30A6\u30B9\u6574\u6570\u3092\u3072\u3068\
    \u3064\u898B\u3064\u3051\u308B\r\n    if (p == 2) return G(1, 1);\r\n    // x^2\
    \ = -1 mod p \u3092\u3072\u3068\u3064\u898B\u3064\u3051\u308B\r\n    T x = [&]()\
    \ -> T {\r\n      T x = 1;\r\n      while (1) {\r\n        ++x;\r\n        T pow_x\
    \ = 1;\r\n        if (p < (1 << 30)) {\r\n          pow_x = mod_pow(x, (p - 1)\
    \ / 4, p);\r\n          if (pow_x * pow_x % p == p - 1) return pow_x;\r\n    \
    \    } else {\r\n          pow_x = mod_pow_64(x, (p - 1) / 4, p);\r\n        \
    \  if (i128(pow_x) * pow_x % p == p - 1) return pow_x;\r\n        }\r\n      }\r\
    \n      return -1;\r\n    }();\r\n    assert(x != -1);\r\n    // x \u306F\u975E\
    \u5270\u4F59\r\n    G a(p, 0), b(x, 1);\r\n    a = G::gcd(a, b);\r\n    assert(a.norm()\
    \ == p);\r\n    return a;\r\n  };\r\n\r\n  res.eb(G(1, 0));\r\n  for (auto &&[p,\
    \ e]: pfs) {\r\n    if (p % 4 == 3) {\r\n      T pp = 1;\r\n      FOR(e / 2) pp\
    \ *= p;\r\n      for (auto &&g: res) {\r\n        g.x *= pp;\r\n        g.y *=\
    \ pp;\r\n      }\r\n      continue;\r\n    }\r\n    auto pi = find(p);\r\n   \
    \ vc<G> pows(e + 1);\r\n    pows[0] = G(1, 0);\r\n    FOR(i, e) pows[i + 1] =\
    \ pows[i] * pi;\r\n    if (p == 2) {\r\n      for (auto &&g: res) g *= pows[e];\r\
    \n      continue;\r\n    }\r\n    vc<G> pis(e + 1);\r\n    FOR(j, e + 1) { pis[j]\
    \ = pows[j] * (pows[e - j].conjugate()); }\r\n    vc<G> new_res;\r\n    new_res.reserve(len(res)\
    \ * (e + 1));\r\n    for (auto &&g: res) {\r\n      for (auto &&a: pis) { new_res.eb(g\
    \ * a); }\r\n    }\r\n    swap(res, new_res);\r\n  }\r\n\r\n  for (auto &&g: res)\
    \ {\r\n    while (g.x <= 0 || g.y < 0) { g = G(-g.y, g.x); }\r\n  }\r\n  return\
    \ res;\r\n}\r\n\r\n// i128 \u3092\u4F7F\u3046\u3068 N <= 10^{18} \u3082\u3067\u304D\
    \u308B\r\n// \u30CE\u30EB\u30E0\u304C\u3068\u308C\u308B\u3088\u3046\u306B\u3001\
    2 \u4E57\u3057\u3066\u3082\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044\u578B\u3092\u4F7F\u304A\u3046\r\n// 0 <= arg < 90 \u3068\u306A\u308B\u3082\
    \u306E\u306E\u307F\u8FD4\u3059\u3002\r\n// \u5358\u6570\u500D\u306F\u4F5C\u3089\
    \u306A\u3044\u306E\u3067\u3001\u4F7F\u3046\u3068\u304D\u306B\u6C17\u3092\u4ED8\
    \u3051\u308B\u3002\r\ntemplate <typename T>\r\nvc<Gaussian_Integer<T>> solve_norm_equation(T\
    \ N) {\r\n  using G = Gaussian_Integer<T>;\r\n  vc<G> res;\r\n  if (N < 0) return\
    \ {};\r\n  if (N == 0) {\r\n    res.eb(G(0, 0));\r\n    return res;\r\n  }\r\n\
    \  auto pfs = factor(N);\r\n  return solve_norm_equation_factor<T>(pfs);\r\n}\r\
    \n"
  dependsOn:
  - nt/factor.hpp
  - nt/primetest.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  isVerificationFile: false
  path: nt/gaussian_integers.hpp
  requiredBy: []
  timestamp: '2023-10-14 20:28:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1593.test.cpp
documentation_of: nt/gaussian_integers.hpp
layout: document
redirect_from:
- /library/nt/gaussian_integers.hpp
- /library/nt/gaussian_integers.hpp.html
title: nt/gaussian_integers.hpp
---
