#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC target ("avx,avx2,fma")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;
using namespace __gnu_pbds;

template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

long long rng() {
  static std::mt19937 gen(
      std::chrono::steady_clock::now().time_since_epoch().count());
  return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 998244353;
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

template<typename T>
struct Seggy {
    int N, ql, qr;
    vector<T> data;
    T def, val;
    void init(int _N, T _def) {
        N = _N;
        def = _def;
        data.resize(4 * N, def);
    }
    T comb(T a, T b) { return max(a, b); }
    #define m ((l + r) / 2)
    T qry(int n, int l, int r) {
        if(r < ql || qr < l) { return def; }
        if(ql <= l && r <= qr) { return data[n]; }
        return comb(qry(2*n, l, m), qry(2*n+1, m + 1, r));
    }
    void upd(int n, int l, int r) {
        if(l == r) { data[n] = val; return; }
        if(ql <= m) { upd(2*n, l, m); }
        else { upd(2*n+1, m + 1, r); }
        data[n] = comb(data[2*n], data[2*n+1]);
    }
    #undef m
    T query(int l, int r) { ql = l, qr = r; return qry(1, 0, N - 1); }
    void update(int idx, T v) { ql = idx, val = v; upd(1, 0, N - 1); }
};

template<typename T>
struct sparse_table
{
    const int LOG = 20;
    T n;
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

set<pair<int, int>> bridges;
void IS_BRIDGE(int v,int to)
{
  bridges.insert({v, to});
  bridges.insert({to, v});
}

int n, m, k; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
vector<int> a;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}


void solve(int tc)
{
  cin >> n >> m >> k;

  a.assign(n, 0);
  adj.clear();
  adj.assign(n, {});
  bridges.clear();

  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  for (int i = 0; i < m; i++)
  {
    int c, d;
    cin >> c >> d;
    c--; d--;
    adj[c].push_back(d);
    adj[d].push_back(c);
  }

  find_bridges();

  vector<bool> visited(n);
  vector<int> match(n, -1);
  int ans = 1;
  for (int i = 0; i < n; i++)
  {
    if (visited[i]) continue;
    vector<int> comp;
    
    function<void(int)> dfs = [&](int cur)
    {
      visited[cur] = true;
      comp.push_back(cur);

      for (int ele : adj[cur])
      {
        if (bridges.count({ele, cur})) continue;
        if (visited[ele]) continue;
        dfs(ele);
      }
    };

    dfs(i);

    if (comp.size() == 1) 
    {
      if (a[comp[0]] == -1) ans *= k;
      ans %= mod;
      continue;
    }
    int prev = -1;
    for (int ele : comp)
    {
      if (a[ele] == -1) continue;
      if (a[ele] != prev and prev != -1) 
      {
        ans = 0;
      }
      prev = a[ele];
    } 

    
    bool is_bipartite = true;
    queue<int> q;
    q.push(comp[0]);
    match[comp[0]] = 0;
    while (q.size())
    {
      int cur = q.front();
      q.pop();

      for (int neighbor : adj[cur])
      {
        if (bridges.count({neighbor, cur})) continue;
        if (match[neighbor] == -1)
        {
          match[neighbor] = 1 - match[cur];
          q.push(neighbor);
        }
        else if (match[neighbor] != 1 - match[cur])
        {
          is_bipartite = false;
        }
      }
    }
    if (is_bipartite)
    {
      if (prev == -1)
      {
        ans *= k;
      }
      ans %= mod;
    }
    else
    {
      if (prev != 0 and prev != -1) ans = 0;
    }
  }
  cout << ans << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}