#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;
using namespace __gnu_pbds;

template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';


struct mi {

  int v;
  mi() : v(0) {}
	mi(int _v):v((long long)(_v % mod)) { v += (v < 0) * mod; }
	friend mi operator+(mi a, const mi& b) { return mi(a.v + b.v); }
	friend mi operator-(mi a, const mi& b) { return mi(a.v - b.v); }
	friend mi operator*(mi a, const mi& b) { return mi((int)a.v*b.v); }
	friend mi operator/(mi a, const mi& b) { return a * inv(b); }
	friend mi pow(mi a, int p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mi inv(const mi& a) { return pow(a, mod-2); }
	mi& operator+=(const mi& o) { return (*this) = (*this) + o; }
	mi& operator-=(const mi& o) { return (*this) = (*this) - o; }
	mi& operator*=(const mi& o) { return (*this) = (*this) * o; }
	mi& operator/=(const mi& o) { return (*this) = (*this) / o; }
};


int pow(int a, int b, int m){ int ans = 1; while(b) { if (b&1) ans = (ans*a) % m; b /= 2; a = (a*a) % m; } return ans; }
int factorial(int n) { int am = 1; for (int i = 1; i <= n; i++) am = (am * i) % mod; return am; }
int choose(int n, int k) { return (factorial(n) * pow(factorial(k), mod - 2, mod)) % mod * pow(factorial(n - k), mod - 2, mod) % mod; }
int permute(int n, int k) { return (factorial(n) * pow(factorial(n - k), mod - 2, mod)) % mod; }
struct DSU {
	vector<int> e; void init(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

struct Seggy {
    int N, ql, qr;
    vector<int> data;
    int def = 0, val;
    void init(int _N) {
        N = _N;
        data.resize(4 * N, def);
    }
    int comb(int a, int b) { return min(a, b); }
    #define m ((l + r) / 2)
    int qry(int n, int l, int r) {
        if(r <= ql || qr <= l) { return def; }
        if(ql <= l && r <= qr) { return data[n]; }
        return comb(qry(2*n, l, m), qry(2*n+1, m, r));
    }
    void upd(int n, int l, int r) {
        if(l + 1 == r) { data[n] = val; return; }
        if(ql < m) { upd(2*n, l, m); }
        else { upd(2*n+1, m, r); }
        data[n] = comb(data[2*n], data[2*n+1]);
    }
    #undef m
    int query(int l, int r) { ql = l, qr = r; return qry(1, 0, N); }
    void update(int idx, int v) { ql = idx, val = v; upd(1, 0, N); }
};
int n, m;
vector<vector<pair<int, int>>> graph;

void solve(int tc)
{
  struct info
  { 
    int u, d;
  };

  struct comp
  {
    bool operator()(info a, info b)
    {
      return a.d > b.d;
    }
  };

  vector<pair<int, int>> dists(n, {INT64_MAX, 0});

  dists[0] = {0, 1};

  priority_queue<info, vector<info>, comp> pq;

  pq.push({0, 0});

  while (!pq.empty())
  {
    info cur = pq.top();
    pq.pop();
    
    if (cur.d > dists[cur.u].f) continue;

    for (pair<int, int> v : graph[cur.u])
    {
      int t = cur.d + v.s;
      if (t < dists[v.f].f)
      {
        pq.push({v.f, t});
        dists[v.f].s = dists[cur.u].s;
        dists[v.f].s %= mod;
        dists[v.f].f = t;
      }
      else if (t == dists[v.f].f)
      {
        dists[v.f].s += dists[cur.u].s;
        dists[v.f].s %= mod;
      }
    }
  }
  cout << dists[n - 1].f << ' ' << dists[n - 1].s % mod << ' ';
}

void solve2()
{
  struct info
  {
    int u, d, l;
  };

  struct comp{
    bool operator()(info a, info b)
    {
      if (a.d == b.d) return a.l > b.l;
      return a.d > b.d;
    }
  };

  vector<pair<int, int>> dists(n, {INT64_MAX, 0});

  priority_queue<info, vector<info>, comp> pq;

  pq.push({0, 0, 0});

  dists[0] = {0, 0};

  while (!pq.empty())
  {
    info cur = pq.top();
    pq.pop();

    if (dists[cur.u].f < cur.d) continue;
    if (dists[cur.u].s < cur.l) continue;

    for (pair<int, int> v : graph[cur.u])
    { 
      int next = cur.d + v.s;
      if (next == dists[v.f].f and dists[v.f].s > dists[cur.u].s + 1)
      {
        dists[v.f] = {next, dists[cur.u].s + 1};
        pq.push({v.f, next, dists[cur.u].s + 1});
      }

      else if (next < dists[v.f].f)
      {
        dists[v.f] = {next, dists[cur.u].s + 1};
        pq.push({v.f, next, dists[cur.u].s + 1});
      }
    }
  }

  cout << dists[n - 1].s << ' ';
}
void solve3()
{
  struct info
  {
    int u, d, l;
  };

  struct comp{
    bool operator()(info a, info b)
    {
      if (a.d == b.d) return a.l < b.l;
      return a.d > b.d;
    }
  };

  vector<pair<int, int>> dists(n, {INT64_MAX, 0});

  priority_queue<info, vector<info>, comp> pq;

  pq.push({0, 0, 0});

  dists[0] = {0, 0};

  while (!pq.empty())
  {
    info cur = pq.top();
    pq.pop();

    if (dists[cur.u].f < cur.d) continue;
    if (dists[cur.u].s > cur.l) continue;

    for (pair<int, int> v : graph[cur.u])
    { 
      int next = cur.d + v.s;
      if (next == dists[v.f].f and dists[v.f].s < dists[cur.u].s + 1)
      {
        dists[v.f] = {next, dists[cur.u].s + 1};
        pq.push({v.f, next, dists[cur.u].s + 1});
      }

      else if (next < dists[v.f].f)
      {
        dists[v.f] = {next, dists[cur.u].s + 1};
        pq.push({v.f, next, dists[cur.u].s + 1});
      }
    }
  }
  cout << dists[n - 1].s << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  cin >> n >> m;

  graph = vector<vector<pair<int, int>>>(n);

  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    graph[a].push_back({b, c});
  }

  for (int i = 1; i <= t; i++)
  {
    solve(i);
    solve2();
    solve3();
  }
}