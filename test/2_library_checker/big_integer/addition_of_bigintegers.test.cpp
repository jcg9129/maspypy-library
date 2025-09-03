// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/addition_of_big_integers
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"

using B = BigInteger;

void solve() {
  auto get = [&]() -> B {
    STR(S);
    return B(S);
  };
  B ANS = get() + get();
  print(ANS.to_string());
}

signed main() {
  INT(T);
  FOR(T) solve();

  return 0;
}
