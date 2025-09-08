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
    int comb(int a, int b) { return max(a, b); }
    #define m ((l + r) / 2)
    int qry(int n, int l, int r) {
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
    int query(int l, int r) { ql = l, qr = r; return qry(1, 0, N - 1); }
    void update(int idx, int v) { ql = idx, val = v; upd(1, 0, N - 1); }
};


void solve(int tc)
{
  ifstream cin("snakes.in");
  ofstream cout("snakes.out");
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  map<int, int> ntct;
  map<int, int> ctnt;
  for (int i = 0; i < n; i++)
  {
    ntct[a[i]] = 0;
  }
  int cnt = 0;

  for (auto ele : ntct)
  {
    ntct[ele.f] = cnt++;
  }

  int mx = 1e6 + 5;
  vector<int> ntc(mx);
  vector<int> ctn(mx);

  for (auto ele : ntct)
  {
    ntc[ele.f] = ele.s;
    ctn[ele.s] = ele.f;
  }


  
  // the amount of k used and the current number
  int c = ntct.size();
  vector<vector<int>> dp(k + 1, vector<int>(c, INT_MAX));
  
  for (int i = 0; i < c; i++)
    dp[0][i] = 0;


  for (int i = 0; i < n; i++)
  {
    vector<vector<int>> next(k + 1, vector<int>(c, INT_MAX));

    for (int j = 0; j <= k; j++)
    {
      for (int l = 0; l < c; l++)
      {
        if (l < ntc[a[i]]) continue; // without the switching
        int am = ctn[l] - a[i];
        next[j][l] = min(next[j][l], dp[j][l] + am);
      }
    }

    // for switching, given a k you just 
    vector<int> lo(k);
    for (int j = 0; j < k; j++)
      lo[j] = *min_element(all(dp[j]));
    
    for (int j = 0; j < k; j++)
    {
      for (int l = 0; l < c; l++)
      {
        // we are switching to l
        if (l < ntc[a[i]]) continue;
        int am = ctn[l] - a[i];
        next[j + 1][l] = min(next[j + 1][l], lo[j] + am);
      }
    }
    dp = next;
  }

  cout << *min_element(all(dp[k])) << endl;

  

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