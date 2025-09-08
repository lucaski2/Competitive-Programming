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



void solve(int tc)
{
  // ifstream cin("pump.in");
  // ofstream cout("pump.out");
  int n, m;
  cin >> n >> m;

  struct edge 
  {
    int a, c, f;
  };

  struct info
  {
    int a, d, f;
  };

  struct comp
  {
    bool operator()(info a, info b)
    {
      return a.d > b.d;
    }
  };

  vector<vector<edge>> graph(n);

  for (int i = 0; i < m; i++)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--;
    graph[a].push_back({b, c, d});
    graph[b].push_back({a, c, d});
  }
  int mx = 1e3+5;
  vector<vector<int>> dists(n, vector<int>(mx, INT64_MAX));

  dists[0][1e3 + 3] = 0;

  priority_queue<info, vector<info>, comp> pq;
  pq.push({0, 0, (int)(1e3+3)});

  while (!pq.empty())
  {
    info cur = pq.top();
    pq.pop();
    if (dists[cur.a][cur.f] > cur.d)
      continue;

    for (edge neighbor : graph[cur.a])
    {
      int next = cur.d + neighbor.c;
      int n2 = min(cur.f, neighbor.f);
      if (dists[neighbor.a][n2] > next)
      {
        dists[neighbor.a][n2] = next;
        pq.push({neighbor.a, next, n2});
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < mx; i++)
  {
    // cout << i << ' ' << dists[n - 1][i] << endl;
    ans = max(ans, i * (int)1e6 / dists[n - 1][i]);
  }
  cout << ans << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}