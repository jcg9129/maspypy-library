---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/ds/link_cut.hpp
    title: graph/ds/link_cut.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
    title: test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2295.test.cpp
    title: test/yukicoder/2295.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2296.test.cpp
    title: test/yukicoder/2296.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/ds/link_cut.hpp\"\n\ntemplate <typename Node, int\
    \ NODES>\nstruct LinkCutTree_base {\n  int n;\n  Node *nodes;\n\n  LinkCutTree_base(int\
    \ n = 0) : n(n) {\n    nodes = new Node[NODES];\n    FOR(i, n) nodes[i] = Node(i);\n\
    \  }\n\n  Node *operator[](int v) { return &nodes[v]; }\n\n  // \u30D1\u30B9\u3092\
    \u8868\u3059 splay tree \u306E\u6839\u306B\u306A\u3063\u3066\u3044\u308B\u304B\
    \u3069\u3046\u304B\n  bool is_root(Node *c) { return state(c) == 0; }\n  bool\
    \ is_root(int c) { return state(&nodes[c]) == 0; }\n\n  Node *get_root(Node *c)\
    \ {\n    expose(c);\n    while (c->l) {\n      c->push();\n      c = c->l;\n \
    \   }\n    splay(c);\n    return c;\n  }\n\n  int get_root(int c) { return get_root(&nodes[c])->idx;\
    \ }\n\n  // c \u306E\u89AA\u3092 p \u306B\u3059\u308B\u3002\u5185\u90E8\u3067\
    \ evert \u3059\u308B\u306E\u3067\u3044\u3064\u547C\u3093\u3067\u3082\u5927\u4E08\
    \u592B\u3002\n  virtual void link(Node *c, Node *p) {\n    evert(c);\n    expose(p);\n\
    \    c->p = p;\n    p->r = c;\n    p->update();\n  }\n\n  // c \u306E\u89AA\u3092\
    \ p \u306B\u3059\u308B\u3002\u5185\u90E8\u3067 evert \u3059\u308B\u306E\u3067\u3044\
    \u3064\u547C\u3093\u3067\u3082\u5927\u4E08\u592B\u3002\n  virtual void link(int\
    \ c, int p) { return link(&nodes[c], &nodes[p]); }\n\n  void cut(Node *a, Node\
    \ *b) {\n    evert(a);\n    expose(b);\n    assert(!b->p);\n    assert((b->l)\
    \ == a);\n    b->l->p = nullptr;\n    b->l = nullptr;\n    b->update();\n  }\n\
    \n  void cut(int a, int b) { return cut(&nodes[a], &nodes[b]); }\n\n  void evert(Node\
    \ *c) {\n    expose(c);\n    c->reverse();\n    c->push();\n  }\n\n  void evert(int\
    \ c) { evert(&nodes[c]); }\n\n  Node *lca(Node *u, Node *v) {\n    assert(get_root(u)\
    \ == get_root(v));\n    expose(u);\n    return expose(v);\n  }\n\n  int lca(int\
    \ u, int v) { return lca(&nodes[u], &nodes[v])->idx; }\n\n  // c \u3068\u6839\u307E\
    \u3067\u304C\u7E4B\u304C\u308C\u3066\u3044\u308B\u72B6\u614B\u306B\u5909\u66F4\
    \u3057\u3066\u3001\u6839\u3092 return \u3059\u308B\n  virtual Node *expose(Node\
    \ *c) {\n    Node *now = c;\n    Node *rp = nullptr; // \u4ECA\u307E\u3067\u4F5C\
    \u3063\u305F\u30D1\u30B9\n    while (now) {\n      splay(now);\n      now->r =\
    \ rp; // \u5B50\u65B9\u5411\u306E\u5909\u66F4\n      now->update();\n      rp\
    \ = now;\n      now = now->p;\n    }\n    splay(c);\n    return rp;\n  }\n\n \
    \ int expose(int c) {\n    Node *x = expose(&nodes[c]);\n    if (!x) return -1;\n\
    \    return x->idx;\n  }\n\n  Node *get_parent(Node *x) {\n    expose(x);\n  \
    \  if (!x->l) return nullptr;\n    x = x->l;\n    while (x->r) x = x->r;\n   \
    \ return x;\n  }\n\n  int get_parent(int x) {\n    Node *p = get_parent((*this)[x]);\n\
    \    return (p ? p->idx : -1);\n  }\n\n  void debug() {\n    FOR(i, n) { nodes[i].debug();\
    \ }\n  }\n\n  virtual void rotate(Node *n) {\n    // n \u3092\u6839\u306B\u8FD1\
    \u3065\u3051\u308B\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n\n \
    \   if (p->l == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    }\
    \ else {\n      c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n\n    if (pp\
    \ && pp->l == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p =\
    \ pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\n  inline int state(Node *n)\
    \ {\n    if (!n->p) return 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r\
    \ == n) return -1;\n    return 0;\n  }\n\n  void splay(Node *c) {\n    c->push();\n\
    \    while (!is_root(c)) {\n      Node *p = c->p;\n      Node *pp = (p ? p->p\
    \ : nullptr);\n      if (state(p) == 0) {\n        p->push(), c->push();\n   \
    \     rotate(c);\n        if (p) p->update();\n      }\n      elif (state(c) ==\
    \ state(p)) {\n        pp->push(), p->push(), c->push();\n        rotate(p);\n\
    \        rotate(c);\n        if (pp) pp->update();\n        if (p) p->update();\n\
    \      }\n      else {\n        pp->push(), p->push(), c->push();\n        rotate(c);\n\
    \        rotate(c);\n        if (p) p->update();\n        if (pp) pp->update();\n\
    \      }\n    }\n    c->update();\n  }\n};\n\nstruct LCT_Node_base {\n  LCT_Node_base\
    \ *l, *r, *p;\n  int idx;\n  bool rev;\n  LCT_Node_base(int i = 0) : l(nullptr),\
    \ r(nullptr), p(nullptr), idx(i) {}\n\n  void update() {}\n\n  void push() {\n\
    \    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n    \
    \  rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l, r);\n\
    \  }\n};\n\ntemplate <int NODES>\nusing LinkCutTree = LinkCutTree_base<LCT_Node_base,\
    \ NODES>;\n#line 2 \"graph/ds/link_cut_path.hpp\"\n\ntemplate <typename Node,\
    \ int NODES>\nstruct LinkCutTree_Path_base : public LinkCutTree_base<Node, NODES>\
    \ {\n  using X = typename Node::X;\n\n  LinkCutTree_Path_base(int n) : LinkCutTree_base<Node,\
    \ NODES>(n) {}\n\n  LinkCutTree_Path_base(vc<X> dat) : LinkCutTree_base<Node,\
    \ NODES>(len(dat)) {\n    FOR(v, len(dat)) {\n      Node *c = (*this)[v];\n  \
    \    set(c, dat[v]);\n    }\n  }\n\n  template <typename F>\n  LinkCutTree_Path_base(int\
    \ n, F f) : LinkCutTree_base<Node, NODES>(n) {\n    FOR(v, n) {\n      X x = f(v);\n\
    \      Node *c = (*this)[v];\n      set(c, x);\n    }\n  }\n\n  void set(Node\
    \ *c, X x) {\n    this->evert(c);\n    c->x = x;\n    c->update();\n  }\n\n  void\
    \ set(int c, X x) { set((*this)[c], x); }\n\n  void multiply(Node *c, X x) { set(c,\
    \ Node::Mono::op(c->x, x)); }\n\n  void multiply(int c, X x) { multiply((*this)[c],\
    \ x); }\n\n  X prod_path(Node *a, Node *b) {\n    this->evert(a);\n    this->expose(b);\n\
    \    return b->prod;\n  }\n\n  X prod_path(int a, int b) { return prod_path((*this)[a],\
    \ (*this)[b]); }\n};\n\ntemplate <typename Monoid>\nstruct LCT_Node_Monoid {\n\
    \  using Mono = Monoid;\n  using X = typename Monoid::value_type;\n  LCT_Node_Monoid\
    \ *l, *r, *p;\n  int idx;\n  X x, prod, rev_prod;\n  bool rev;\n  LCT_Node_Monoid(int\
    \ i = 0)\n      : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n    \
    \    idx(i),\n        x(Monoid::unit()),\n        prod(Monoid::unit()),\n    \
    \    rev_prod(Monoid::unit()) {}\n\n  void update() {\n    prod = rev_prod = x;\n\
    \    if (l) {\n      prod = Monoid::op(l->prod, prod);\n      rev_prod = Monoid::op(rev_prod,\
    \ l->rev_prod);\n    }\n    if (r) {\n      prod = Monoid::op(prod, r->prod);\n\
    \      rev_prod = Monoid::op(r->rev_prod, rev_prod);\n    }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l,\
    \ r);\n    swap(prod, rev_prod);\n  }\n\n  void debug() {\n    int li = (l ? l->idx\
    \ : -1);\n    int ri = (r ? r->idx : -1);\n    int pi = (p ? p->idx : -1);\n \
    \   print(\"idx\", idx, \"l\", li, \"r\", ri, \"p\", pi, \"x\", x, \"prod\", prod,\n\
    \          \"rev_prod\", rev_prod);\n  }\n};\n\ntemplate <typename Monoid>\nstruct\
    \ LCT_Node_CommutativeMonoid {\n  using Mono = Monoid;\n  using X = typename Mono::value_type;\n\
    \  LCT_Node_CommutativeMonoid *l, *r, *p;\n  int idx;\n  X x, prod;\n  bool rev;\n\
    \  LCT_Node_CommutativeMonoid(int i = 0)\n      : l(nullptr),\n        r(nullptr),\n\
    \        p(nullptr),\n        idx(i),\n        x(Mono::unit()),\n        prod(Mono::unit())\
    \ {}\n\n  void update() {\n    prod = x;\n    if (l) { prod = Mono::op(l->prod,\
    \ prod); }\n    if (r) { prod = Mono::op(prod, r->prod); }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l,\
    \ r);\n  }\n\n  void debug() {\n    int li = (l ? l->idx : -1);\n    int ri =\
    \ (r ? r->idx : -1);\n    int pi = (p ? p->idx : -1);\n    print(\"idx\", idx,\
    \ \"l\", li, \"r\", ri, \"p\", pi, \"x\", x, \"prod\", prod);\n  }\n};\n\ntemplate\
    \ <typename Monoid, int NODES>\nusing LinkCutTree_Path = LinkCutTree_Path_base<LCT_Node_Monoid<Monoid>,\
    \ NODES>;\n\ntemplate <typename Monoid, int NODES>\nusing LinkCutTree_Path_Commutative\n\
    \    = LinkCutTree_Path_base<LCT_Node_CommutativeMonoid<Monoid>, NODES>;\n"
  code: "#include \"graph/ds/link_cut.hpp\"\n\ntemplate <typename Node, int NODES>\n\
    struct LinkCutTree_Path_base : public LinkCutTree_base<Node, NODES> {\n  using\
    \ X = typename Node::X;\n\n  LinkCutTree_Path_base(int n) : LinkCutTree_base<Node,\
    \ NODES>(n) {}\n\n  LinkCutTree_Path_base(vc<X> dat) : LinkCutTree_base<Node,\
    \ NODES>(len(dat)) {\n    FOR(v, len(dat)) {\n      Node *c = (*this)[v];\n  \
    \    set(c, dat[v]);\n    }\n  }\n\n  template <typename F>\n  LinkCutTree_Path_base(int\
    \ n, F f) : LinkCutTree_base<Node, NODES>(n) {\n    FOR(v, n) {\n      X x = f(v);\n\
    \      Node *c = (*this)[v];\n      set(c, x);\n    }\n  }\n\n  void set(Node\
    \ *c, X x) {\n    this->evert(c);\n    c->x = x;\n    c->update();\n  }\n\n  void\
    \ set(int c, X x) { set((*this)[c], x); }\n\n  void multiply(Node *c, X x) { set(c,\
    \ Node::Mono::op(c->x, x)); }\n\n  void multiply(int c, X x) { multiply((*this)[c],\
    \ x); }\n\n  X prod_path(Node *a, Node *b) {\n    this->evert(a);\n    this->expose(b);\n\
    \    return b->prod;\n  }\n\n  X prod_path(int a, int b) { return prod_path((*this)[a],\
    \ (*this)[b]); }\n};\n\ntemplate <typename Monoid>\nstruct LCT_Node_Monoid {\n\
    \  using Mono = Monoid;\n  using X = typename Monoid::value_type;\n  LCT_Node_Monoid\
    \ *l, *r, *p;\n  int idx;\n  X x, prod, rev_prod;\n  bool rev;\n  LCT_Node_Monoid(int\
    \ i = 0)\n      : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n    \
    \    idx(i),\n        x(Monoid::unit()),\n        prod(Monoid::unit()),\n    \
    \    rev_prod(Monoid::unit()) {}\n\n  void update() {\n    prod = rev_prod = x;\n\
    \    if (l) {\n      prod = Monoid::op(l->prod, prod);\n      rev_prod = Monoid::op(rev_prod,\
    \ l->rev_prod);\n    }\n    if (r) {\n      prod = Monoid::op(prod, r->prod);\n\
    \      rev_prod = Monoid::op(r->rev_prod, rev_prod);\n    }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l,\
    \ r);\n    swap(prod, rev_prod);\n  }\n\n  void debug() {\n    int li = (l ? l->idx\
    \ : -1);\n    int ri = (r ? r->idx : -1);\n    int pi = (p ? p->idx : -1);\n \
    \   print(\"idx\", idx, \"l\", li, \"r\", ri, \"p\", pi, \"x\", x, \"prod\", prod,\n\
    \          \"rev_prod\", rev_prod);\n  }\n};\n\ntemplate <typename Monoid>\nstruct\
    \ LCT_Node_CommutativeMonoid {\n  using Mono = Monoid;\n  using X = typename Mono::value_type;\n\
    \  LCT_Node_CommutativeMonoid *l, *r, *p;\n  int idx;\n  X x, prod;\n  bool rev;\n\
    \  LCT_Node_CommutativeMonoid(int i = 0)\n      : l(nullptr),\n        r(nullptr),\n\
    \        p(nullptr),\n        idx(i),\n        x(Mono::unit()),\n        prod(Mono::unit())\
    \ {}\n\n  void update() {\n    prod = x;\n    if (l) { prod = Mono::op(l->prod,\
    \ prod); }\n    if (r) { prod = Mono::op(prod, r->prod); }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l,\
    \ r);\n  }\n\n  void debug() {\n    int li = (l ? l->idx : -1);\n    int ri =\
    \ (r ? r->idx : -1);\n    int pi = (p ? p->idx : -1);\n    print(\"idx\", idx,\
    \ \"l\", li, \"r\", ri, \"p\", pi, \"x\", x, \"prod\", prod);\n  }\n};\n\ntemplate\
    \ <typename Monoid, int NODES>\nusing LinkCutTree_Path = LinkCutTree_Path_base<LCT_Node_Monoid<Monoid>,\
    \ NODES>;\n\ntemplate <typename Monoid, int NODES>\nusing LinkCutTree_Path_Commutative\n\
    \    = LinkCutTree_Path_base<LCT_Node_CommutativeMonoid<Monoid>, NODES>;\n"
  dependsOn:
  - graph/ds/link_cut.hpp
  isVerificationFile: false
  path: graph/ds/link_cut_path.hpp
  requiredBy: []
  timestamp: '2023-06-11 17:11:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2296.test.cpp
  - test/yukicoder/2295.test.cpp
  - test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
documentation_of: graph/ds/link_cut_path.hpp
layout: document
redirect_from:
- /library/graph/ds/link_cut_path.hpp
- /library/graph/ds/link_cut_path.hpp.html
title: graph/ds/link_cut_path.hpp
---