#pragma once

#include "alg/monoid/set.hpp"
#include "alg/monoid/add_array.hpp"

template <typename mint, int K>
struct Lazy_Power_Sums_Set {
  using MX = Monoid_Add_Array<mint, K>;
  using MA = Monoid_Set<int, -1>;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  static X act(const X &x, const A &b) {
    if (b == -1) return x;
    mint a = b;
    X y(K);
    X pow(K);
    pow[0] = mint(1);
    FOR(k, K - 1) pow[k + 1] = pow[k] * a;
    FOR(i, K) y[i] = x[0] * pow[i];
    return y;
  }
};
