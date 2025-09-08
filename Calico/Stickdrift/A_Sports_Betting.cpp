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
  int n, m;
  cin >> n >> m;
  string temp;
  cin >> temp;
  int sz = 0;
  string s;
  while (sz < n + m)
  {
    sz += temp.size();
    s += temp;
  }

  map<int, pair<int, int>> mp;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int a;
      cin >> a;
      a;
      mp[a] = {i, j};
    }
  }


  vector<pair<int, int>> off(2 * sz + 2);
  off[0] = {0, 0};
  off[sz] = {0, 0};
  int x = 0, y = 0;
  for (int i = 0; i < sz; i++)
  {
    if (s[i] == 'L') y++;
    else if (s[i] == 'R') y--;
    else if (s[i] == 'U') x++;
    else if (s[i] == 'D') x--;
    off[i + 1] = {x, y};
    off[i + sz + 1] = {x, y};
  }




  int ind = 0;
  int gans = 0;
  for (int i = 0; i < n * m; i++)
  {
    int l = 0, r = n + m - 1;
    int ans = INT_MAX;
    // while (l <= r)
    for (int mid = 0; mid <= n + m; mid++)
    {
      // int mid = (l + r) / 2;
      x = mp[i].f + off[ind + mid].f - off[ind].f;
      y = mp[i].s + off[ind + mid].s - off[ind].s;
      x += m * 1000;
      x %= m;
      y += n * 1000;
      y %= n;

      int col_time = min(abs(x - mp[i + 1].f), min(x, mp[i + 1].f) + m - max(x, mp[i + 1].f));
      int row_time = min(abs(y - mp[i + 1].s), min(y, mp[i + 1].s) + n - max(y, mp[i + 1].s));
      if (mid == 1 and temp.size() == 3)
      {
        // cout << x << ' ' << y << endl;
        // cout << mp[i + 1].f << ' ' << mp[i + 1].s << endl;
        // cout << off[ind + mid].s << ' ' << off[ind].s << ' ' << off[ind + mid].f << ' ' << off[ind].f << endl;
        // cout << col_time << ' ' << row_time << endl;
      }
      int f = col_time + row_time;
      if (mid >= f)
      {
        ans = min(ans, mid);
        r = mid - 1;
      }
      else 
      {
        l = mid + 1;
      }
    }
    ind += ans;
    // cout << ans << endl;
    if (ind > sz) ind -= sz + 1;
    gans += ans;
  }
  cout << gans << endl;
  cout << endl;
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