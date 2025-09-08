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

int dist(pair<int, int> a, pair<int, int> b)
{
  // cout << (b.f - a.f) * (b.f - a.f) + (b.s - a.s) * (b.s - a.s) << endl;
  return (b.f - a.f) * (b.f - a.f) + (b.s - a.s) * (b.s - a.s);
}



void solve(int tc)
{
  ifstream cin("radio.in");
  ofstream cout("radio.out");
  int n, m;
  cin >> n >> m;

  pair<int, int> fjsp;
  pair<int, int> bsp;
  cin >> fjsp.first >> fjsp.second;
  cin >> bsp.first >> bsp.second;

  vector<char> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  vector<pair<int, int>> fjpos(n + 1);
  vector<pair<int, int>> bpos(m + 1);
  fjpos[0] = fjsp;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 'S') fjsp.second--;
    if (a[i] == 'N') fjsp.second++;
    if (a[i] == 'E') fjsp.first++;
    if (a[i] == 'W') fjsp.first--;
    fjpos[i + 1] = fjsp;
  }

  bpos[0] = bsp;
  for (int i = 0; i < m; i++)
  {
    if (b[i] == 'S') bsp.second--;
    if (b[i] == 'N') bsp.second++;
    if (b[i] == 'E') bsp.first++;
    if (b[i] == 'W') bsp.first--;
    bpos[i + 1] = bsp;
  }

  vector<vector<int>> dp(n + m + 1, vector<int>(n + 1, INT64_MAX));

  dp[0][0] = 0;

  for (int i = 0; i < n + m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      int fjind = j;
      int bind = i - j;

      function<void()> pushfj = [&]()
      {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + dist(fjpos[j + 1], bpos[bind]));
      };
      function<void()> pushb = [&]()
      {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dist(fjpos[j], bpos[bind + 1]));
      };
      
      function<void()> pushboth = [&]()
      {
        dp[i + 2][j + 1] = min(dp[i + 2][j + 1], dp[i][j] + dist(fjpos[j + 1], bpos[bind + 1]));
      };

      if (INT64_MAX == dp[i][j]) continue;

      if (fjind != n) pushfj();
      if (bind != m) pushb();
      if (fjind != n and bind != m) pushboth();
    }
  }

  cout << dp[n + m][n] << endl;



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