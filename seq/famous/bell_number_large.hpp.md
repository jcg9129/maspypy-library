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
  - icon: ':x:'
    path: poly/coef_of_rational_fps.hpp
    title: poly/coef_of_rational_fps.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':x:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/fps_div.hpp
    title: poly/fps_div.hpp
  - icon: ':x:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':x:'
    path: poly/ntt_doubling.hpp
    title: poly/ntt_doubling.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/bell.test.cpp
    title: test/mytest/bell.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/fps_div.hpp\"\n\n#line 2 \"poly/count_terms.hpp\"\n\
    template<typename mint>\r\nint count_terms(const vc<mint>& f){\r\n  int t = 0;\r\
    \n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\n  return t;\r\n}\n#line 2 \"mod/modint_common.hpp\"\
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
    \ 1045430273) return {20, 363};\n    if (mod == 1051721729) return {20, 330};\n\
    \    if (mod == 1053818881) return {20, 2789};\n    return {-1, -1};\n  }\n  static\
    \ constexpr bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\n\
    template <int mod>\nvoid rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  assert(0\
    \ <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n\
    \  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\nusing\
    \ modint998 = modint<998244353>;\n#line 2 \"mod/mod_inv.hpp\"\n\r\n// long \u3067\
    \u3082\u5927\u4E08\u592B\r\n// (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\
    \u306A\u308B\u3088\u3046\u306B\u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\u3089\
    \ x=0 \u304C\u6E80\u305F\u3059\r\nll mod_inv(ll val, ll mod) {\r\n  if (mod ==\
    \ 0) return 0;\r\n  mod = abs(mod);\r\n  val %= mod;\r\n  if (val < 0) val +=\
    \ mod;\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n   \
    \ t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if (u\
    \ < 0) u += mod;\r\n  return u;\r\n}\r\n#line 1 \"mod/crt3.hpp\"\n\nconstexpr\
    \ u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {\n  a %= mod;\n  u64 res = 1;\n\
    \  FOR(32) {\n    if (n & 1) res = res * a % mod;\n    a = a * a % mod, n /= 2;\n\
    \  }\n  return res;\n}\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64\
    \ a0, u64 a1, u64 a2) {\n  static_assert(p0 < p1 && p1 < p2);\n  static constexpr\
    \ u64 x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  static constexpr u64 x01_2\
    \ = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n  u64 c = (a1 - a0 + p1)\
    \ * x0_1 % p1;\n  u64 a = a0 + c * p0;\n  c = (a2 - a % p2 + p2) * x01_2 % p2;\n\
    \  return T(a) + T(c) * T(p0) * T(p1);\n}\n#line 2 \"poly/convolution_naive.hpp\"\
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
    \n\r\n  static bool prepared = 0;\r\n  if (!prepared) {\r\n    prepared = 1;\r\
    \n    root[rank2] = mint::ntt_info().se;\r\n    iroot[rank2] = mint(1) / root[rank2];\r\
    \n    FOR_R(i, rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n    \
    \  iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n    }\r\n    mint prod = 1, iprod\
    \ = 1;\r\n    for (int i = 0; i <= rank2 - 2; i++) {\r\n      rate2[i] = root[i\
    \ + 2] * prod;\r\n      irate2[i] = iroot[i + 2] * iprod;\r\n      prod *= iroot[i\
    \ + 2];\r\n      iprod *= root[i + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n\
    \    for (int i = 0; i <= rank2 - 3; i++) {\r\n      rate3[i] = root[i + 3] *\
    \ prod;\r\n      irate3[i] = iroot[i + 3] * iprod;\r\n      prod *= iroot[i +\
    \ 3];\r\n      iprod *= root[i + 3];\r\n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\
    \n  int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  if (!inverse) {\r\n    int\
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
    \ {\r\n    int x = (i < (int)a.size() ? a[i] : 0);\r\n    int y = (i < (int)b.size()\
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
    \ (n <= t ? fps_inv_sparse<mint>(f) : fps_inv_dense<mint>(f));\r\n}\r\n#line 5\
    \ \"poly/fps_div.hpp\"\n\n// f/g. f \u306E\u9577\u3055\u3067\u51FA\u529B\u3055\
    \u308C\u308B.\ntemplate <typename mint, bool SPARSE = false>\nvc<mint> fps_div(vc<mint>\
    \ f, vc<mint> g) {\n  if (SPARSE || count_terms(g) < 200) return fps_div_sparse(f,\
    \ g);\n  int n = len(f);\n  g.resize(n);\n  g = fps_inv<mint>(g);\n  f = convolution(f,\
    \ g);\n  f.resize(n);\n  return f;\n}\n\n// f/g \u305F\u3060\u3057 g \u306F sparse\n\
    template <typename mint>\nvc<mint> fps_div_sparse(vc<mint> f, vc<mint>& g) {\n\
    \  if (g[0] != mint(1)) {\n    mint cf = g[0].inverse();\n    for (auto&& x: f)\
    \ x *= cf;\n    for (auto&& x: g) x *= cf;\n  }\n\n  vc<pair<int, mint>> dat;\n\
    \  FOR(i, 1, len(g)) if (g[i] != mint(0)) dat.eb(i, -g[i]);\n  FOR(i, len(f))\
    \ {\n    for (auto&& [j, x]: dat) {\n      if (i >= j) f[i] += x * f[i - j];\n\
    \    }\n  }\n  return f;\n}\n#line 2 \"poly/ntt_doubling.hpp\"\n\ntemplate <typename\
    \ mint>\nvoid ntt_doubling(vector<mint>& a) {\n  const int rank2 = mint::ntt_info().fi;\n\
    \  static array<mint, 30> root;\n  static bool prepared = 0;\n  if (!prepared)\
    \ {\n    prepared = 1;\n    root[rank2] = mint::ntt_info().se;\n    FOR_R(i, rank2)\
    \ { root[i] = root[i + 1] * root[i + 1]; }\n  }\n\n  const int M = (int)a.size();\n\
    \  auto b = a;\n  ntt(b, 1);\n  mint r = 1, zeta = root[topbit(2 * M)];\n  FOR(i,\
    \ M) b[i] *= r, r *= zeta;\n  ntt(b, 0);\n  copy(begin(b), end(b), back_inserter(a));\n\
    }\n#line 3 \"poly/coef_of_rational_fps.hpp\"\n\r\ntemplate <typename mint>\r\n\
    mint coef_of_rational_fps_small(vector<mint> P, vector<mint> Q, ll N) {\r\n  assert(len(Q)\
    \ <= 16);\r\n  int m = len(Q) - 1;\r\n  assert(len(P) == m);\r\n  if (m == 0)\
    \ return mint(0);\r\n  vc<u32> Q32(m + 1);\r\n  FOR(i, m + 1) Q32[i] = (-Q[i]).val;\r\
    \n\r\n  using poly = vc<u64>;\r\n  auto dfs = [&](auto& dfs, const ll N) -> poly\
    \ {\r\n    // x^N mod G\r\n    if (N == 0) return {1};\r\n    poly f = dfs(dfs,\
    \ N / 2);\r\n    poly g(len(f) * 2 - 1 + (N & 1));\r\n    FOR(i, len(f)) FOR(j,\
    \ len(f)) { g[i + j + (N & 1)] += f[i] * f[j]; }\r\n    FOR(i, len(g)) g[i] =\
    \ mint(g[i]).val;\r\n    FOR_R(i, len(g)) {\r\n      g[i] = mint(g[i]).val;\r\n\
    \      if (i >= m) FOR(j, 1, len(Q)) g[i - j] += Q32[j] * g[i];\r\n    }\r\n \
    \   g.resize(m);\r\n    return g;\r\n  };\r\n  poly f = dfs(dfs, N);\r\n  FOR(i,\
    \ m) { FOR(j, 1, i + 1) P[i] -= Q[j] * P[i - j]; }\r\n  u64 res = 0;\r\n  FOR(i,\
    \ m) res += f[i] * P[i].val;\r\n  return res;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nmint coef_of_rational_fps_ntt(vector<mint> P, vector<mint> Q, ll N) {\r\n  int\
    \ log = 0;\r\n  while ((1 << log) < len(Q)) ++log;\r\n  int n = 1 << log;\r\n\
    \  P.resize(2 * n), Q.resize(2 * n);\r\n  ntt(P, 0), ntt(Q, 0);\r\n  vc<int> btr(n);\r\
    \n  FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }\r\n\r\n\
    \  int t = mint::ntt_info().fi;\r\n  mint r = mint::ntt_info().se;\r\n  mint dw\
    \ = r.inverse().pow((1 << t) / (2 * n));\r\n\r\n  vc<mint> S, T;\r\n  while (N\
    \ >= n) {\r\n    mint w = inv<mint>(2);\r\n    T.resize(n);\r\n    FOR(i, n) T[i]\
    \ = Q[2 * i + 0] * Q[2 * i + 1];\r\n    S.resize(n);\r\n    if (N & 1) {\r\n \
    \     for (auto& i: btr) {\r\n        S[i] = (P[2 * i] * Q[2 * i + 1] - P[2 *\
    \ i + 1] * Q[2 * i]) * w;\r\n        w *= dw;\r\n      }\r\n    } else {\r\n \
    \     FOR(i, n) {\r\n        S[i] = (P[2 * i] * Q[2 * i + 1] + P[2 * i + 1] *\
    \ Q[2 * i]) * w;\r\n      }\r\n    }\r\n    swap(P, S), swap(Q, T);\r\n    N >>=\
    \ 1;\r\n    if (N < n) break;\r\n    ntt_doubling(P);\r\n    ntt_doubling(Q);\r\
    \n  }\r\n  ntt(P, 1), ntt(Q, 1);\r\n  return fps_div(P, Q)[N];\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nmint coef_of_rational_fps_convolution(vector<mint> P, vector<mint>\
    \ Q, ll N) {\r\n  P.resize(len(Q) - 1);\r\n  if (len(P) == 0) return 0;\r\n  while\
    \ (N >= len(P)) {\r\n    vc<mint> Q1 = Q;\r\n    FOR(i, len(Q1)) if (i & 1) Q1[i]\
    \ = -Q1[i];\r\n    P = convolution(P, Q1);\r\n    Q = convolution(Q, Q1);\r\n\
    \    FOR(i, len(Q1)) Q[i] = Q[2 * i];\r\n    FOR(i, len(Q1) - 1) P[i] = P[2 *\
    \ i | (N & 1)];\r\n    P.resize(len(Q1) - 1);\r\n    Q.resize(len(Q1));\r\n  \
    \  N /= 2;\r\n  }\r\n  return fps_div(P, Q)[N];\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nmint coef_of_rational_fps(vector<mint> P, vector<mint> Q, ll N) {\r\
    \n  assert(len(P) < len(Q) && Q[0] == mint(1));\r\n  if (N == 0) return (P.empty()\
    \ ? mint(0) : P[0]);\r\n  int n = len(Q);\r\n  if (mint::ntt_info().fi != -1)\
    \ {\r\n    if (n <= 10) {\r\n      return coef_of_rational_fps_small(P, Q, N);\r\
    \n    } else {\r\n      return coef_of_rational_fps_ntt(P, Q, N);\r\n    }\r\n\
    \  }\r\n  return (n <= 16 ? coef_of_rational_fps_small(P, Q, N)\r\n          \
    \        : coef_of_rational_fps_convolution(P, Q, N));\r\n}\n#line 2 \"seq/famous/bell_number_large.hpp\"\
    \n\n// Bell \u6570 B_n \u306E\u8A08\u7B97\u3002O(p logp logn)\ntemplate <typename\
    \ mint>\nmint Bell_Number_large(ll n) {\n  int p = mint::get_mod();\n  vc<mint>\
    \ f(p);\n  FOR(i, p) f[i] = fact_inv<mint>(i);\n  f[0] = 0;\n  f = fps_exp(f);\n\
    \  FOR(i, p) f[i] *= fact<mint>(i);\n  vc<mint> g(p + 1);\n  g[0] = 1;\n  g[p\
    \ - 1] = -1;\n  g[p] = -1;\n  f = convolution(f, g);\n  f.resize(p);\n  return\
    \ coef_of_rational_fps<mint>(f, g, n);\n}\n"
  code: "#include \"poly/coef_of_rational_fps.hpp\"\n\n// Bell \u6570 B_n \u306E\u8A08\
    \u7B97\u3002O(p logp logn)\ntemplate <typename mint>\nmint Bell_Number_large(ll\
    \ n) {\n  int p = mint::get_mod();\n  vc<mint> f(p);\n  FOR(i, p) f[i] = fact_inv<mint>(i);\n\
    \  f[0] = 0;\n  f = fps_exp(f);\n  FOR(i, p) f[i] *= fact<mint>(i);\n  vc<mint>\
    \ g(p + 1);\n  g[0] = 1;\n  g[p - 1] = -1;\n  g[p] = -1;\n  f = convolution(f,\
    \ g);\n  f.resize(p);\n  return coef_of_rational_fps<mint>(f, g, n);\n}\n"
  dependsOn:
  - poly/coef_of_rational_fps.hpp
  - poly/fps_div.hpp
  - poly/count_terms.hpp
  - poly/fps_inv.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  - poly/ntt_doubling.hpp
  isVerificationFile: false
  path: seq/famous/bell_number_large.hpp
  requiredBy: []
  timestamp: '2023-11-15 20:12:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/bell.test.cpp
documentation_of: seq/famous/bell_number_large.hpp
layout: document
redirect_from:
- /library/seq/famous/bell_number_large.hpp
- /library/seq/famous/bell_number_large.hpp.html
title: seq/famous/bell_number_large.hpp
---
