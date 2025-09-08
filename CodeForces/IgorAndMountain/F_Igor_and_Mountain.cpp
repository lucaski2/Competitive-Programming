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
  int n, m, d;
  cin >> n >> m >> d;

  vector<vector<bool>> grid(n, vector<bool>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char a;
      cin >> a;
      grid[i][j] = (a == 'X');
    }
  }

  vector<int> dp(m);
  for (int i = 0; i < m; i++)
  {
    dp[i] = grid[n - 1][i];
  }
  vector<int> psum, next;

  for (int i = n - 1; i >= 0; i--)
  {
    next = vector<int>(m, 0);
    if (i != n - 1)
    {
      // pull from prev
      psum = vector<int>(m + 1, 0);
      for (int j = 0; j < m; j++)
        psum[j + 1] = psum[j] + dp[j];
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j]) next[j] += psum[min(m, j + d)] - psum[max(0ll, j - d + 1)];
      }
      dp = next;
    }
    else next = dp;
    // for (int ele : dp)
    // {
    //   cout << ele << ' ';
    // }
    // cout << endl;

    psum = vector<int>(m + 1, 0);
    for (int j = 0; j < m; j++)
      psum[j + 1] = psum[j] + dp[j];
    

    for (int j = 0; j < m; j++)
    {
      next[j] -= dp[j];
      if (next[j] < 0) next[j] += 1e4 * mod;
      if (grid[i][j]) next[j] += psum[min(m, j + d + 1)] - psum[max(0ll, j - d)];
      next[j] %= mod;
    }
    dp = next;
    // for (int ele : dp)
    // {
    //   cout << ele << ' ';
    // }
    // cout << endl;
  }
  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    // cout << dp[i] << ' ';
    ans += dp[i];
    ans %= mod;
  }
  // cout << endl;
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