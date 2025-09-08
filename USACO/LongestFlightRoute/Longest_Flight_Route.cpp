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
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n);
  vector<vector<int>> reversed(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    reversed[b].push_back(a);
  }
  vector<bool> visited(n);

  vector<int> dp(n);
  dp[0] = 1;
  vector<int> topo;
  function<void(int)> dfs = [&](int cur)
  { 
    visited[cur] = true;
    for (int neighbor : graph[cur])
    {
      if (!visited[neighbor]) dfs(neighbor);
    }
    topo.push_back(cur);
  };
  
  for (int i = 0; i < n; i++)
  {
    if (!visited[i]) dfs(i);
  }
  reverse(all(topo));

  for (int i = 0; i < n; i++)
  {
    for (int neighbor : graph[topo[i]])
    {
      dp[neighbor] = max(dp[neighbor], dp[topo[i]] + 1);
    }
  }
  if (dp[n - 1] == 0)
  {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  cout << dp[n - 1] << endl;

  int ind = n - 1;
  vector<int> ans = {n};
  for (; dp[n - 1] > 0; dp[n - 1]--)
  {
    for (int neighbor : reversed[ind])
    {
      if (dp[neighbor] == dp[n - 1])
      {
        ind = neighbor;
        ans.push_back(ind + 1);
        break;
      }
    }
  }
  reverse(all(ans));
  for (int ele : ans) cout << ele << ' ';
  cout << endl;

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