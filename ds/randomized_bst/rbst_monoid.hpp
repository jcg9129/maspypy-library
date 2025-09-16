#include "ds/node_pool.hpp"

template <typename Monoid, bool PERSISTENT>
struct RBST_Monoid {
  using X = typename Monoid::value_type;

  struct Node {
    Node *l, *r;
    X x, prod, rev_prod;  // rev 反映済
    u32 size;
    bool rev;
  };

  Node_Pool<Node> pool;
  using np = Node *;

  void reset() { pool.reset(); }

  np new_node(const X &x) {
    np c = pool.create();
    c->l = c->r = nullptr;
    c->x = x, c->prod = x, c->rev_prod = x;
    c->size = 1, c->rev = 0;
    return c;
  }

  np new_node(const vc<X> &dat) {
    auto dfs = [&](auto &dfs, u32 l, u32 r) -> np {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      u32 m = (l + r) / 2;
      np l_root = dfs(dfs, l, m);
      np r_root = dfs(dfs, m + 1, r);
      np root = new_node(dat[m]);
      root->l = l_root, root->r = r_root;
      update(root);
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  np copy_node(np &n) {
    if (!n || !PERSISTENT) return n;
    c->l = n->l, c->r = n->r;
    c->x = n->x, c->prod = n->prod, c->rev_prod = n->rev_prod;
    c->size = n->size, c->rev = n->rev;
    return c;
  }

  np merge(np l_root, np r_root) { return merge_rec(l_root, r_root); }
  np merge3(np a, np b, np c) { return merge(merge(a, b), c); }
  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a, b), c), d); }
  pair<np, np> split(np root, u32 k) {
    if (!root) {
      assert(k == 0);
      return {nullptr, nullptr};
    }
    assert(0 <= k && k <= root->size);
    return split_rec(root, k);
  }
  tuple<np, np, np> split3(np root, u32 l, u32 r) {
    np nm, nr;
    tie(root, nr) = split(root, r);
    tie(root, nm) = split(root, l);
    return {root, nm, nr};
  }
  tuple<np, np, np, np> split4(np root, u32 i, u32 j, u32 k) {
    np d;
    tie(root, d) = split(root, k);
    auto [a, b, c] = split3(root, i, j);
    return {a, b, c, d};
  }

  X prod(np root, u32 l, u32 r) {
    if (l == r) return Monoid::unit();
    return prod_rec(root, l, r, false);
  }
  X prod(np root) { return (root ? root->prod : Monoid::unit()); }

  np reverse(np root, u32 l, u32 r) {
    assert(0 <= l && l <= r && r <= root->size);
    if (r - l <= 1) return root;
    auto [nl, nm, nr] = split3(root, l, r);
    nm->rev ^= 1;
    swap(nm->l, nm->r);
    swap(nm->prod, nm->rev_prod);
    return merge3(nl, nm, nr);
  }

  np set(np root, u32 k, const X &x) { return set_rec(root, k, x); }
  np multiply(np root, u32 k, const X &x) { return multiply_rec(root, k, x); }
  X get(np root, u32 k) { return get_rec(root, k, false); }

  vc<X> get_all(np root) {
    vc<X> res;
    auto dfs = [&](auto &dfs, np root, bool rev) -> void {
      if (!root) return;
      dfs(dfs, (rev ? root->r : root->l), rev ^ root->rev);
      res.eb(root->x);
      dfs(dfs, (rev ? root->l : root->r), rev ^ root->rev);
    };
    dfs(dfs, root, 0);
    return res;
  }

  template <typename F>
  pair<np, np> split_max_right(np root, const F check) {
    assert(check(Monoid::unit()));
    X x = Monoid::unit();
    return split_max_right_rec(root, check, x);
  }

 private:
  inline u32 xor128() {
    static u32 x = 123456789;
    static u32 y = 362436069;
    static u32 z = 521288629;
    static u32 w = 88675123;
    u32 t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  void prop(np c) {
    // 自身をコピーする必要はない。
    // 子をコピーする必要がある。複数の親を持つ可能性があるため。
    if (c->rev) {
      if (c->l) {
        c->l = copy_node(c->l);
        c->l->rev ^= 1;
        swap(c->l->l, c->l->r);
        swap(c->l->prod, c->l->rev_prod);
      }
      if (c->r) {
        c->r = copy_node(c->r);
        c->r->rev ^= 1;
        swap(c->r->l, c->r->r);
        swap(c->r->prod, c->r->rev_prod);
      }
      c->rev = 0;
    }
  }

  void update(np c) {
    // データを保ったまま正常化するだけなので、コピー不要
    c->size = 1;
    c->prod = c->rev_prod = c->x;
    if (c->l) {
      c->size += c->l->size;
      c->prod = Monoid::op(c->l->prod, c->prod);
      c->rev_prod = Monoid::op(c->rev_prod, c->l->rev_prod);
    }
    if (c->r) {
      c->size += c->r->size;
      c->prod = Monoid::op(c->prod, c->r->prod);
      c->rev_prod = Monoid::op(c->r->rev_prod, c->rev_prod);
    }
  }

  np merge_rec(np l_root, np r_root) {
    if (!l_root) return r_root;
    if (!r_root) return l_root;
    u32 sl = l_root->size, sr = r_root->size;
    if (xor128() % (sl + sr) < sl) {
      prop(l_root);
      l_root = copy_node(l_root);
      l_root->r = merge_rec(l_root->r, r_root);
      update(l_root);
      return l_root;
    }
    prop(r_root);
    r_root = copy_node(r_root);
    r_root->l = merge_rec(l_root, r_root->l);
    update(r_root);
    return r_root;
  }

  pair<np, np> split_rec(np root, u32 k) {
    if (!root) return {nullptr, nullptr};
    prop(root);
    u32 sl = (root->l ? root->l->size : 0);
    if (k <= sl) {
      auto [nl, nr] = split_rec(root->l, k);
      root = copy_node(root);
      root->l = nr;
      update(root);
      return {nl, root};
    }
    auto [nl, nr] = split_rec(root->r, k - (1 + sl));
    root = copy_node(root);
    root->r = nl;
    update(root);
    return {root, nr};
  }

  np set_rec(np root, u32 k, const X &x) {
    if (!root) return root;
    prop(root);
    u32 sl = (root->l ? root->l->size : 0);
    if (k < sl) {
      root = copy_node(root);
      root->l = set_rec(root->l, k, x);
      update(root);
      return root;
    }
    if (k == sl) {
      root = copy_node(root);
      root->x = x;
      update(root);
      return root;
    }
    root = copy_node(root);
    root->r = set_rec(root->r, k - (1 + sl), x);
    update(root);
    return root;
  }

  np multiply_rec(np root, u32 k, const X &x) {
    if (!root) return root;
    prop(root);
    u32 sl = (root->l ? root->l->size : 0);
    if (k < sl) {
      root = copy_node(root);
      root->l = multiply_rec(root->l, k, x);
      update(root);
      return root;
    }
    if (k == sl) {
      root = copy_node(root);
      root->x = Monoid::op(root->x, x);
      update(root);
      return root;
    }
    root = copy_node(root);
    root->r = multiply_rec(root->r, k - (1 + sl), x);
    update(root);
    return root;
  }

  X prod_rec(np root, u32 l, u32 r, bool rev) {
    if (l == 0 && r == root->size) {
      return (rev ? root->rev_prod : root->prod);
    }
    np left = (rev ? root->r : root->l);
    np right = (rev ? root->l : root->r);
    u32 sl = (left ? left->size : 0);
    X res = Monoid::unit();
    if (l < sl) {
      X y = prod_rec(left, l, min(r, sl), rev ^ root->rev);
      res = Monoid::op(res, y);
    }
    if (l <= sl && sl < r) res = Monoid::op(res, root->x);
    u32 k = 1 + sl;
    if (k < r) {
      X y = prod_rec(right, max(k, l) - k, r - k, rev ^ root->rev);
      res = Monoid::op(res, y);
    }
    return res;
  }

  X get_rec(np root, u32 k, bool rev) {
    np left = (rev ? root->r : root->l);
    np right = (rev ? root->l : root->r);
    u32 sl = (left ? left->size : 0);
    if (k == sl) return root->x;
    rev ^= root->rev;
    if (k < sl) return get_rec(left, k, rev);
    return get_rec(right, k - (1 + sl), rev);
  }

  template <typename F>
  pair<np, np> split_max_right_rec(np root, const F &check, X &x) {
    if (!root) return {nullptr, nullptr};
    prop(root);
    root = copy_node(root);
    X y = Monoid::op(x, root->prod);
    if (check(y)) {
      x = y;
      return {root, nullptr};
    }
    np left = root->l, right = root->r;
    if (left) {
      X y = Monoid::op(x, root->l->prod);
      if (!check(y)) {
        auto [n1, n2] = split_max_right_rec(left, check, x);
        root->l = n2;
        update(root);
        return {n1, root};
      }
      x = y;
    }
    y = Monoid::op(x, root->x);
    if (!check(y)) {
      root->l = nullptr;
      update(root);
      return {left, root};
    }
    x = y;
    auto [n1, n2] = split_max_right_rec(right, check, x);
    root->r = n1;
    update(root);
    return {root, n2};
  }
};
