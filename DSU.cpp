template<typename T>
class DSU { 
  public:
  T n;
  vector<T>p, w;
  DSU(T _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    w.resize(n);
    fill(w.begin(), w.end(), 1);
  }

  T root(T x) {
    return (x == p[x] ? x : root(p[x]));
  }
  
  bool isconnected(T u, T v) {
    return (root(u) == root(v));
  }

  void unite(T u, T v) {
    u = root(u);
    v = root(v);
    if(u != v) {
      if(w[u] < w[v])
        swap(u, v);
      p[v] = u;
      w[u] += w[v];
    }
  }
};
