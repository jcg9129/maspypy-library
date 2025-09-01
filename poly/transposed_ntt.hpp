#pragma once

template <class mint>
void transposed_ntt(vector<mint>& a, bool inverse) {
  assert(mint::can_ntt());
  const int rank2 = mint::ntt_info().fi;
  const u32 mod = mint::get_mod();
  static array<mint, 30> root, iroot;
  static array<mint, 30> rate2, irate2;
  static array<mint, 30> rate3, irate3;

  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));

  static bool prepared = 0;
  if (!prepared) {
    prepared = 1;
    root[rank2] = mint::ntt_info().se;
    iroot[rank2] = mint(1) / root[rank2];
    FOR_R(i, rank2) {
      root[i] = root[i + 1] * root[i + 1];
      iroot[i] = iroot[i + 1] * iroot[i + 1];
    }
    mint prod = 1, iprod = 1;
    for (int i = 0; i <= rank2 - 2; i++) {
      rate2[i] = root[i + 2] * prod;
      irate2[i] = iroot[i + 2] * iprod;
      prod *= iroot[i + 2];
      iprod *= root[i + 2];
    }
    prod = 1, iprod = 1;
    for (int i = 0; i <= rank2 - 3; i++) {
      rate3[i] = root[i + 3] * prod;
      irate3[i] = iroot[i + 3] * iprod;
      prod *= iroot[i + 3];
      iprod *= root[i + 3];
    }
  }

  int n = int(a.size());
  int h = topbit(n);
  assert(n == 1 << h);
  if (!inverse) {
    int len = h;
    while (len > 0) {
      if (len == 1) {
        int p = 1 << (h - len);
        mint rot = 1;
        FOR(s, 1 << (len - 1)) {
          int offset = s << (h - len + 1);
          FOR(i, p) {
            u64 l = a[i + offset].val;
            u64 r = a[i + offset + p].val;
            a[i + offset] = l + r;
            a[i + offset + p] = (mod + l - r) * rot.val;
          }
          rot *= rate2[topbit(~s & -~s)];
        }
        len--;
      } else {
        int p = 1 << (h - len);
        mint rot = 1, imag = root[2];
        FOR(s, (1 << (len - 2))) {
          int offset = s << (h - len + 2);
          mint rot2 = rot * rot;
          mint rot3 = rot2 * rot;
          for (int i = 0; i < p; i++) {
            u64 a0 = a[i + offset + 0 * p].val;
            u64 a1 = a[i + offset + 1 * p].val;
            u64 a2 = a[i + offset + 2 * p].val;
            u64 a3 = a[i + offset + 3 * p].val;
            u64 x = (mod + a2 - a3) * imag.val % mod;
            a[i + offset] = a0 + a1 + a2 + a3;
            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * rot.val;
            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * rot2.val;
            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * rot3.val;
          }
          rot *= rate3[topbit(~s & -~s)];
        }
        len -= 2;
      }
    }
  } else {
    mint coef = mint(1) / mint(len(a));
    FOR(i, len(a)) a[i] *= coef;
    int len = 0;
    while (len < h) {
      if (len == h - 1) {
        int p = 1 << (h - len - 1);
        mint irot = 1;
        FOR(s, 1 << len) {
          int offset = s << (h - len);
          FOR(i, p) {
            auto l = a[i + offset];
            auto r = a[i + offset + p] * irot;
            a[i + offset] = l + r;
            a[i + offset + p] = l - r;
          }
          irot *= irate2[topbit(~s & -~s)];
        }
        len++;
      } else {
        int p = 1 << (h - len - 2);
        mint irot = 1, iimag = iroot[2];
        for (int s = 0; s < (1 << len); s++) {
          mint irot2 = irot * irot;
          mint irot3 = irot2 * irot;
          int offset = s << (h - len);
          for (int i = 0; i < p; i++) {
            u64 mod2 = u64(mod) * mod;
            u64 a0 = a[i + offset].val;
            u64 a1 = u64(a[i + offset + p].val) * irot.val;
            u64 a2 = u64(a[i + offset + 2 * p].val) * irot2.val;
            u64 a3 = u64(a[i + offset + 3 * p].val) * irot3.val;
            u64 a1na3imag = (a1 + mod2 - a3) % mod * iimag.val;
            u64 na2 = mod2 - a2;
            a[i + offset] = a0 + a2 + a1 + a3;
            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
          }
          irot *= irate3[topbit(~s & -~s)];
        }
        len += 2;
      }
    }
  }
}
