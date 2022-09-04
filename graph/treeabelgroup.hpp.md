---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1326.test.cpp
    title: test/yukicoder/1326.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1641.test.cpp
    title: test/yukicoder/1641.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Group_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\
    \n\ntemplate <typename AbelGroup>\nstruct FenwickTree {\n  using E = typename\
    \ AbelGroup::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree(int\
    \ n = 0) {\n    assert(AbelGroup::commute);\n    reset(n);\n  }\n  FenwickTree(const\
    \ vector<E>& v) {\n    assert(AbelGroup::commute);\n    build(v);\n  }\n\n  void\
    \ build(const vc<E>& v) {\n    n = len(v);\n    total = AbelGroup::unit();\n \
    \   for (int i = 0; i < n; ++i) total = AbelGroup::op(total, v[i]);\n    dat =\
    \ v;\n    for (int i = 1; i <= n; ++i) {\n      int j = i + (i & -i);\n      if\
    \ (j <= n) dat[j - 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n  }\n\n\
    \  void reset(int sz) {\n    n = sz;\n    total = AbelGroup::unit();\n    dat.assign(n,\
    \ AbelGroup::unit());\n  }\n\n  E prod(int k) {\n    E ret = AbelGroup::unit();\n\
    \    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret, dat[k - 1]);\n    return\
    \ ret;\n  }\n\n  E prod(int L, int R) {\n    E pos = AbelGroup::unit();\n    while\
    \ (L < R) {\n      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -= R & -R;\n\
    \    }\n    E neg = AbelGroup::unit();\n    while (R < L) {\n      neg = AbelGroup::op(neg,\
    \ dat[L - 1]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n\
    \  }\n\n  E prod_all() { return total; }\n\n  E sum(int k) { return prod(k); }\n\
    \n  E sum(int L, int R) { return prod(L, R); }\n\n  E sum_all() { return total;\
    \ }\n\n  void multiply(int k, E x) {\n    total = AbelGroup::op(total, x);\n \
    \   for (++k; k <= n; k += k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n\n  template <class F>\n \
    \ int max_right(F& check) {\n    assert(check(E(0)));\n    ll i = 0;\n    E s\
    \ = AbelGroup::unit();\n    int k = 1;\n    int N = dat.size() + 1;\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(AbelGroup::op(s,\
    \ dat[i + k - 1]))) {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n\
    \      }\n      k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth(E k) {\n\
    \    auto check = [&](E x) -> bool { return x <= k; };\n    return max_right(check);\n\
    \  }\n\n  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  int\
    \ N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n  constexpr bool is_directed() { return directed; }\n\n  Graph() : N(0),\
    \ M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void\
    \ resize(int n) { N = n; }\n\n  void add(int frm, int to, T cost = 1, int i =\
    \ -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void read_parent(int off = 1) {\n    for (int v = 1; v < N; ++v) {\n\
    \      INT(p);\n      p -= off;\n      add(p, v);\n    }\n    build();\n  }\n\n\
    \  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\nprivate:\n  void calc_deg()\
    \ {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/tree.hpp\"\
    \n\r\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\u3002\
    \r\n// \u6728\u4EE5\u5916\u3001\u975E\u9023\u7D50\u3067\u3082 dfs \u9806\u5E8F\
    \u3084\u89AA\u304C\u3068\u308C\u308B\u3002\r\ntemplate <typename Graph>\r\nstruct\
    \ TREE {\r\n  Graph &G;\r\n  using Graph_type = Graph;\r\n  using WT = typename\
    \ Graph::cost_type;\r\n  int N;\r\n  bool hld;\r\n  vector<int> LID, RID, head,\
    \ V, parent, root;\r\n  vc<int> depth;\r\n  vc<WT> depth_weighted;\r\n  vector<bool>\
    \ in_tree;\r\n\r\n  TREE(Graph &G, int r = -1, bool hld = 1)\r\n      : G(G),\r\
    \n        N(G.N),\r\n        hld(hld),\r\n        LID(G.N),\r\n        RID(G.N),\r\
    \n        head(G.N, r),\r\n        V(G.N),\r\n        parent(G.N, -1),\r\n   \
    \     root(G.N, -1),\r\n        depth(G.N, -1),\r\n        depth_weighted(G.N,\
    \ 0),\r\n        in_tree(G.M, 0) {\r\n    assert(G.is_prepared());\r\n    int\
    \ t1 = 0;\r\n    if (r != -1) {\r\n      dfs_sz(r, -1);\r\n      dfs_hld(r, t1);\r\
    \n    } else {\r\n      for (int r = 0; r < N; ++r) {\r\n        if (parent[r]\
    \ == -1) {\r\n          head[r] = r;\r\n          dfs_sz(r, -1);\r\n         \
    \ dfs_hld(r, t1);\r\n        }\r\n      }\r\n    }\r\n    for (auto &&v: V) root[v]\
    \ = (parent[v] == -1 ? v : root[parent[v]]);\r\n  }\r\n\r\n  void dfs_sz(int v,\
    \ int p) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\n    depth[v] = (p ==\
    \ -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l = G.indptr[v], r = G.indptr[v\
    \ + 1];\r\n    auto &csr = G.csr_edges;\r\n    // \u4F7F\u3046\u8FBA\u304C\u3042\
    \u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n    for (int i = r - 2; i >= l;\
    \ --i) {\r\n      if (depth[csr[i + 1].to] == -1) swap(csr[i], csr[i + 1]);\r\n\
    \    }\r\n    int hld_sz = 0;\r\n    for (int i = l; i < r; ++i) {\r\n      auto\
    \ e = csr[i];\r\n      if (depth[e.to] != -1) continue;\r\n      in_tree[e.id]\
    \ = 1;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\n      dfs_sz(e.to,\
    \ v);\r\n      sz[v] += sz[e.to];\r\n      if (hld && chmax(hld_sz, sz[e.to])\
    \ && l < i) { swap(csr[l], csr[i]); }\r\n    }\r\n  }\r\n\r\n  void dfs_hld(int\
    \ v, int &times) {\r\n    LID[v] = times++;\r\n    RID[v] += LID[v];\r\n    V[LID[v]]\
    \ = v;\r\n    bool heavy = true;\r\n    for (auto &&e: G[v]) {\r\n      if (!in_tree[e.id]\
    \ || depth[e.to] <= depth[v]) continue;\r\n      head[e.to] = (heavy ? head[v]\
    \ : e.to);\r\n      heavy = false;\r\n      dfs_hld(e.to, times);\r\n    }\r\n\
    \  }\r\n\r\n  int e_to_v(int eid) {\r\n    auto e = G.edges[eid];\r\n    return\
    \ (parent[e.frm] == e.to ? e.frm : e.to);\r\n  }\r\n\r\n  int ELID(int v) { return\
    \ 2 * LID[v] - depth[v]; }\r\n  int ERID(int v) { return 2 * RID[v] - depth[v]\
    \ - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int v, int k) {\r\n    assert(k\
    \ <= depth[v]);\r\n    while (1) {\r\n      int u = head[v];\r\n      if (LID[v]\
    \ - k >= LID[u]) return V[LID[v] - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n\
    \      v = parent[u];\r\n    }\r\n  }\r\n\r\n  int LCA(int u, int v) {\r\n   \
    \ for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v]) swap(u, v);\r\n\
    \      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n\r\n  int lca(int\
    \ u, int v) { return LCA(u, v); }\r\n  int la(int u, int v) { return LA(u, v);\
    \ }\r\n\r\n  int subtree_size(int v) { return RID[v] - LID[v]; }\r\n\r\n  int\
    \ dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n    return depth[a] + depth[b]\
    \ - 2 * depth[c];\r\n  }\r\n\r\n  WT dist(int a, int b, bool weighted) {\r\n \
    \   assert(weighted);\r\n    int c = LCA(a, b);\r\n    return depth_weighted[a]\
    \ + depth_weighted[b] - 2 * depth_weighted[c];\r\n  }\r\n\r\n  // a is in b\r\n\
    \  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b];\
    \ }\r\n\r\n  int jump(int a, int b, int k = 1) {\r\n    if (k == 1) {\r\n    \
    \  if (a == b) return -1;\r\n      return (in_subtree(b, a) ? LA(b, depth[b] -\
    \ depth[a] - 1) : parent[a]);\r\n    }\r\n    int c = LCA(a, b);\r\n    int d_ac\
    \ = depth[a] - depth[c];\r\n    int d_bc = depth[b] - depth[c];\r\n    if (k >\
    \ d_ac + d_bc) return -1;\r\n    if (k <= d_ac) return LA(a, k);\r\n    return\
    \ LA(b, d_ac + d_bc - k);\r\n  }\r\n\r\n  vc<int> collect_child(int v) {\r\n \
    \   vc<int> res;\r\n    for (auto &&e: G[v])\r\n      if (e.to != parent[v]) res.eb(e.to);\r\
    \n    return res;\r\n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int\
    \ u, int v, bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\
    \"\u533A\u9593\u5217\u3002\r\n    vc<pair<int, int>> up, down;\r\n    while (1)\
    \ {\r\n      if (head[u] == head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n\
    \        down.eb(LID[head[v]], LID[v]);\r\n        v = parent[head[v]];\r\n  \
    \    } else {\r\n        up.eb(LID[u], LID[head[u]]);\r\n        u = parent[head[u]];\r\
    \n      }\r\n    }\r\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\
    \n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\
    \n    up.insert(up.end(), all(down));\r\n    return up;\r\n  }\r\n\r\n  void debug()\
    \ {\r\n    print(\"V\", V);\r\n    print(\"LID\", LID);\r\n    print(\"RID\",\
    \ RID);\r\n    print(\"parent\", parent);\r\n    print(\"depth\", depth);\r\n\
    \    print(\"head\", head);\r\n    print(\"in_tree(edge)\", in_tree);\r\n    print(\"\
    root\", root);\r\n  }\r\n};\r\n#line 3 \"graph/treeabelgroup.hpp\"\n\r\ntemplate\
    \ <typename TREE, typename AbelGroup, bool edge = false,\r\n          bool path_query\
    \ = true, bool subtree_query = false>\r\nstruct TreeAbelGroup {\r\n  using X =\
    \ typename AbelGroup::value_type;\r\n  TREE &tree;\r\n  int N;\r\n  FenwickTree<AbelGroup>\
    \ bit, bit_subtree;\r\n\r\n  TreeAbelGroup(TREE &tree) : tree(tree), N(tree.N)\
    \ {\r\n    if (path_query) { bit = FenwickTree<AbelGroup>(2 * N); }\r\n    if\
    \ (subtree_query) { bit_subtree = FenwickTree<AbelGroup>(N); }\r\n  }\r\n\r\n\
    \  TreeAbelGroup(TREE &tree, vc<X> dat) : tree(tree), N(tree.N) {\r\n    if (path_query)\
    \ {\r\n      vc<X> bit_raw(2 * N);\r\n      if (!edge) {\r\n        assert(len(dat)\
    \ == N);\r\n        FOR(v, N) {\r\n          bit_raw[tree.ELID(v)] = dat[v];\r\
    \n          bit_raw[tree.ERID(v)] = AbelGroup::inverse(dat[v]);\r\n        }\r\
    \n      } else {\r\n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1)\
    \ {\r\n          int v = tree.e_to_v(e);\r\n          bit_raw[tree.ELID(v)] =\
    \ dat[e];\r\n          bit_raw[tree.ERID(v)] = AbelGroup::inverse(dat[e]);\r\n\
    \        }\r\n      }\r\n      bit = FenwickTree<AbelGroup>(bit_raw);\r\n    }\r\
    \n    if (subtree_query) {\r\n      vc<X> bit_raw(N);\r\n      if (!edge) {\r\n\
    \        assert(len(dat) == N);\r\n        FOR(v, N) bit_raw[tree.LID[v]] = dat[v];\r\
    \n      } else {\r\n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1)\
    \ {\r\n          int v = tree.e_to_v(e);\r\n          bit_raw[tree.LID[v]] = dat[e];\r\
    \n        }\r\n      }\r\n      bit_subtree = FenwickTree<AbelGroup>(bit_raw);\r\
    \n    }\r\n  }\r\n\r\n  void add(int i, X x) {\r\n    int v = (edge ? tree.e_to_v(i)\
    \ : i);\r\n    if (path_query) {\r\n      X inv_x = AbelGroup::inverse(x);\r\n\
    \      bit.add(tree.ELID(v), x);\r\n      bit.add(tree.ERID(v), inv_x);\r\n  \
    \  }\r\n    if (subtree_query) bit_subtree.add(tree.LID[v], x);\r\n  }\r\n\r\n\
    \  X prod_path(int frm, int to) {\r\n    assert(path_query);\r\n    int lca =\
    \ tree.LCA(frm, to);\r\n    // [frm, lca)\r\n    X x1 = bit.prod(tree.ELID(lca)\
    \ + 1, tree.ELID(frm) + 1);\r\n    // edge \u306A\u3089 (lca, to]\u3001vertex\
    \ \u306A\u3089 [lca, to]\r\n    X x2 = bit.prod(tree.ELID(lca) + edge, tree.ELID(to)\
    \ + 1);\r\n    return AbelGroup::op(x1, x2);\r\n  }\r\n\r\n  X prod_subtree(int\
    \ u) {\r\n    assert(subtree_query);\r\n    int l = tree.LID[u], r = tree.RID[u];\r\
    \n    return bit_subtree.prod(l + edge, r);\r\n  }\r\n\r\n  void debug() {\r\n\
    \    tree.debug();\r\n    bit.debug();\r\n    bit_subtree.debug();\r\n  }\r\n\
    };\r\n"
  code: "#include \"ds/fenwick.hpp\"\r\n#include \"graph/tree.hpp\"\r\n\r\ntemplate\
    \ <typename TREE, typename AbelGroup, bool edge = false,\r\n          bool path_query\
    \ = true, bool subtree_query = false>\r\nstruct TreeAbelGroup {\r\n  using X =\
    \ typename AbelGroup::value_type;\r\n  TREE &tree;\r\n  int N;\r\n  FenwickTree<AbelGroup>\
    \ bit, bit_subtree;\r\n\r\n  TreeAbelGroup(TREE &tree) : tree(tree), N(tree.N)\
    \ {\r\n    if (path_query) { bit = FenwickTree<AbelGroup>(2 * N); }\r\n    if\
    \ (subtree_query) { bit_subtree = FenwickTree<AbelGroup>(N); }\r\n  }\r\n\r\n\
    \  TreeAbelGroup(TREE &tree, vc<X> dat) : tree(tree), N(tree.N) {\r\n    if (path_query)\
    \ {\r\n      vc<X> bit_raw(2 * N);\r\n      if (!edge) {\r\n        assert(len(dat)\
    \ == N);\r\n        FOR(v, N) {\r\n          bit_raw[tree.ELID(v)] = dat[v];\r\
    \n          bit_raw[tree.ERID(v)] = AbelGroup::inverse(dat[v]);\r\n        }\r\
    \n      } else {\r\n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1)\
    \ {\r\n          int v = tree.e_to_v(e);\r\n          bit_raw[tree.ELID(v)] =\
    \ dat[e];\r\n          bit_raw[tree.ERID(v)] = AbelGroup::inverse(dat[e]);\r\n\
    \        }\r\n      }\r\n      bit = FenwickTree<AbelGroup>(bit_raw);\r\n    }\r\
    \n    if (subtree_query) {\r\n      vc<X> bit_raw(N);\r\n      if (!edge) {\r\n\
    \        assert(len(dat) == N);\r\n        FOR(v, N) bit_raw[tree.LID[v]] = dat[v];\r\
    \n      } else {\r\n        assert(len(dat) == N - 1);\r\n        FOR(e, N - 1)\
    \ {\r\n          int v = tree.e_to_v(e);\r\n          bit_raw[tree.LID[v]] = dat[e];\r\
    \n        }\r\n      }\r\n      bit_subtree = FenwickTree<AbelGroup>(bit_raw);\r\
    \n    }\r\n  }\r\n\r\n  void add(int i, X x) {\r\n    int v = (edge ? tree.e_to_v(i)\
    \ : i);\r\n    if (path_query) {\r\n      X inv_x = AbelGroup::inverse(x);\r\n\
    \      bit.add(tree.ELID(v), x);\r\n      bit.add(tree.ERID(v), inv_x);\r\n  \
    \  }\r\n    if (subtree_query) bit_subtree.add(tree.LID[v], x);\r\n  }\r\n\r\n\
    \  X prod_path(int frm, int to) {\r\n    assert(path_query);\r\n    int lca =\
    \ tree.LCA(frm, to);\r\n    // [frm, lca)\r\n    X x1 = bit.prod(tree.ELID(lca)\
    \ + 1, tree.ELID(frm) + 1);\r\n    // edge \u306A\u3089 (lca, to]\u3001vertex\
    \ \u306A\u3089 [lca, to]\r\n    X x2 = bit.prod(tree.ELID(lca) + edge, tree.ELID(to)\
    \ + 1);\r\n    return AbelGroup::op(x1, x2);\r\n  }\r\n\r\n  X prod_subtree(int\
    \ u) {\r\n    assert(subtree_query);\r\n    int l = tree.LID[u], r = tree.RID[u];\r\
    \n    return bit_subtree.prod(l + edge, r);\r\n  }\r\n\r\n  void debug() {\r\n\
    \    tree.debug();\r\n    bit.debug();\r\n    bit_subtree.debug();\r\n  }\r\n\
    };\r\n"
  dependsOn:
  - ds/fenwick.hpp
  - alg/group_add.hpp
  - graph/tree.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/treeabelgroup.hpp
  requiredBy: []
  timestamp: '2022-09-03 12:29:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1641.test.cpp
  - test/yukicoder/1326.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
documentation_of: graph/treeabelgroup.hpp
layout: document
redirect_from:
- /library/graph/treeabelgroup.hpp
- /library/graph/treeabelgroup.hpp.html
title: graph/treeabelgroup.hpp
---
