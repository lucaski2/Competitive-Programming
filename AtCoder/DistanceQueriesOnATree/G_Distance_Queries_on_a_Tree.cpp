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

vector<int> fact = {1};

int factorial(int n)
{
  while (fact.size() - 1 < n)
    fact.push_back((fact.back() * fact.size()) % mod);

  return fact[n];
}



int pow(int a, int b, int m){ int ans = 1; while(b) { if (b&1) ans = (ans*a) % m; b /= 2; a = (a*a) % m; } return ans; }
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
  int n;
  vector<int> data;
  int ql, qr, val;

  void init(int _n)
  {
    n = _n;
    data.resize(2 * n);
  } 
  #define m (l + r) / 2
  void upd(int l, int r, int i)
  {
    if (ql > r or qr < l) return;
    if (qr >= r and ql <= l)
    {
      data[i] += val;
      return;
    }
    upd(l, m, i * 2);
    upd(m + 1, r, i * 2 + 1);
  }
  #undef m

  int query(int i)
  {
    i += n;
    int ret = 0;
    while (i > 0)
    {
      ret += data[i];
      i /= 2;
    }
    return ret;
  }
  

  void update(int l, int r, int v)
  {
    ql = l;
    qr = r;
    val = v;
    upd(0, n - 1, 1);
  }
};

template<typename T>
struct sparse_table
{
    const int LOG = 20;
    int n;
    vector<vector<T> > dp;
    T merge(T a, T b){
        return min(a, b);
    }
    sparse_table(vector<T> &a){
        n = a.size();
        dp.resize(LOG);
        dp[0] = a;

        for (int id = 1; id < LOG; id++)
        {
            dp[id].resize(n);
            for (int j = 0; j < n; j++)
            {
                dp[id][j] = dp[id - 1][j];
                int next_id = j + (1 << (id - 1));
                if(next_id < n){
                    dp[id][j] = merge(dp[id][j], dp[id - 1][next_id]);
                }
            }
        }
    }
    T query(int l, int r){
        int d = r - l + 1;
        int id = __builtin_clzll(1) - __builtin_clzll(d); 
        int shift = (1LL << id);
        return merge(dp[id][l], dp[id][r - shift + 1]);
    }
};

void solve(int tc)
{
  int n;
  cin >> n;
  
  struct edge
  {
    int u, v, w;
  };

  vector<edge> edges(n - 1);

  vector<vector<pair<int, int>>> graph(n);

  for (int i = 0; i < n - 1; i++)
  {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
    edges[i].u--; edges[i].v--;
    graph[edges[i].u].push_back({edges[i].v, edges[i].w});
    graph[edges[i].v].push_back({edges[i].u, edges[i].w});
  }

  vector<int> depths(n), first(n), last(n);
  vector<pair<int, int>> et;
  Seggy seggy;
  int m = 1;
  while (m < 2 * n) m <<= 1;
  seggy.init(m);
  int cnt = 0;
  
  // seggy will give us the sum from the root

  function<void(int, int, int)> dfs = [&](int cur, int par, int depth)
  {
    depths[cur] = depth;
    first[cur] = cnt;
    
    seggy.update(cnt, cnt, depth);

    last[cur] = cnt++;
    et.push_back({depth, cur});

    for (pair<int, int> neighbor : graph[cur])
    {
      if (neighbor.f == par) continue;
      dfs(neighbor.f, cur, depth + neighbor.s);
      
      seggy.update(cnt, cnt, depth);

      last[cur] = cnt++;
      et.push_back({depth, cur});
    }
  };

  dfs(0, -1, 0);



  sparse_table<pair<int, int>> sparse(et);
  int q;
  cin >> q;
  while (q--)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      int i, w;
      cin >> i >> w;
      i--;
      int diff = w - edges[i].w;
      edges[i].w = w;
      int v = (depths[edges[i].u] < depths[edges[i].v] ? edges[i].v : edges[i].u);
      seggy.update(first[v], last[v], diff);
    }
    else
    {
      int u, v;
      cin >> u >> v;
      u--; v--;
      int lca = sparse.query(min(first[u], first[v]), max(first[u], first[v])).s;
      cout << seggy.query(first[u]) + seggy.query(first[v]) - seggy.query(first[lca]) * 2 << endl;
    }
  }

}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}