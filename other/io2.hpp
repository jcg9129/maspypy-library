#define INT(...)   \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...)    \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...)           \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void read(int &a) { cin >> a; }
void read(long long &a) { cin >> a; }
void read(char &a) { cin >> a; }
void read(double &a) { cin >> a; }
void read(long double &a) { cin >> a; }
void read(string &a) { cin >> a; }
template <class T, class S>
void read(pair<T, S> &p) {
  read(p.first), read(p.second);
}
template <class T>
void read(vector<T> &a) {
  for (auto &i : a) read(i);
}
template <class T>
void read(T &a) {
  cin >> a;
}
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &...tail) {
  read(head);
  IN(tail...);
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &A) {
  for (size_t i = 0; i < A.size(); i++) {
    if (i) os << " ";
    os << A[i];
  }
  return os;
}

// chatgpt helped me
class CoutInitializer {
 public:
  CoutInitializer() { std::cout << std::defaultfloat << std::setprecision(15); }
};
static CoutInitializer cout_initializer;

void print() {
  cout << "\n";
  cout.flush();
}

template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

#if defined(LOCAL)
template <class... Ts>
inline void _show_pack(const char *func, int line, const char *names,
                       Ts &&...args) {
  // [DEBUG] solve:123 のように先頭に出す
  cout << "[DEBUG " << func << ':' << line << "] ";

  const char *p = names;
  bool first = true;

  auto next_token = [&]() -> std::pair<const char *, const char *> {
    while (*p == ' ' || *p == ',') ++p;
    const char *l = p;
    while (*p && *p != ',') ++p;
    const char *r = p;
    return {l, r};
  };

  (
      [&] {
        auto [l, r] = next_token();
        while (r > l && r[-1] == ' ') --r;
        if (!first) cout << ' ';
        first = false;
        std::string name(l, r);
        cout << name << " = " << args;
      }(),
      ...);
  print();
}

#define SHOW(...) _show_pack(__func__, __LINE__, #__VA_ARGS__, __VA_ARGS__)
#else
#define SHOW(...)
#endif

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
