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
  int len;
  vector<int> seggy;
  int DEFAULT;
  int combine(int a, int b) { return a + b; }
  Seggy(int n, int DEFAULT) : len(n), DEFAULT(DEFAULT)
  {
    seggy = vector<int>(n * 2, INT64_MAX);
  };
  void add(int ind, int am)
  {
    for (ind += len; ind > 0; ind /= 2) seggy[ind] = combine(seggy[ind], am);
  }
  int query(int l, int r, int cur_l, int cur_r, int ind)
  {
    if (cur_l >= l and cur_r <= r) return seggy[ind];
    if (cur_l > r or cur_r < l) return DEFAULT;
    int mid = (cur_l + cur_r) / 2;
    return combine(query(l, r, cur_l, mid, ind * 2), query(l, r, mid + 1, cur_r, ind * 2 + 1));
  }
};



void solve(int tc)
{
  ifstream cin("revegetate.in");  
  ofstream cout("revegetate.out");
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n);
  
  for (int i = 0; i < m; i++)
  {
    int a, b;
    char c;
    cin >> c >> a >> b;
    a--; b--;
    graph[a].push_back({b, c == 'D'});
    graph[b].push_back({a, c == 'D'});
  }
  
  int cnt = 0;
  vector<bool> visited(n);
  vector<int> visited2(n, -1);
  bool ok = true;
  for (int i = 0; i < n; i++)
  {
    if (visited[i]) continue;

    queue<int> q;
    visited[i] = true;
    q.push(i);
    while (!q.empty())
    {
      int cur = q.front();
      q.pop();
      for (pair<int, int> neighbor : graph[cur])
      {
        if (!visited[neighbor.f])
        {
          q.push(neighbor.f);
          visited[neighbor.f] = true;
        }
      }
    }
    visited2[i] = 0;
    function<void(int)> dfs = [&](int u)
    {
      for (pair<int, int> neighbor : graph[u])
      {
        if (visited2[neighbor.f] == -1)
        {
          visited2[neighbor.f] = neighbor.s ^ visited2[u];
          dfs(neighbor.f);
        }
        else if (visited2[neighbor.f] != neighbor.s ^ visited2[u]) ok = false;
      }
    };
    dfs(i);
    cnt++;
  }
  
  if (!ok)
  {
    cout << 0 << endl;
    return;
  }
  cout << '1';
  for (int i = 0; i < cnt; i++)
  {
    cout << '0';
  }
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