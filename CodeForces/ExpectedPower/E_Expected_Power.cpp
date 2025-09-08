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

template<typename T>
struct Seggy {
    int N, ql, qr;
    vector<T> data;
    T def = 0, val;
    void init(int _N) {
        N = _N;
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
    void update(int idx, int v) { ql = idx, val = v; upd(1, 0, N - 1); }
};


template<typename T> struct node {
    static const T def = 0;
    array<node*, 2> c{nullptr, nullptr};
    int l, r;
    T val = def;
    T comb(T a, T b) { return max(a, b); }
    node(int _l, int _r):l(_l),r(_r) {
        if (l + 1 == r) { return; }
        c[0] = new node(l, (l + r) / 2);
        c[1] = new node((l + r) / 2, r);
    }
    T qry(int ql, int qr) {
        if (qr <= l || r <= ql) { return def; }
        if (ql <= l && r <= qr) { return val; }
        return comb(c[0]->qry(ql, qr), c[1]->qry(ql, qr));
    }
    void upd(int p, T qv) {
        if (l + 1 == r) { val = qv; return; }
        c[p >= c[1]->l]->upd(p, qv);
        val = comb(c[0]->val, c[1]->val);
    }
    int walk(T cmp, int ql, int qr) {
        if (val < cmp || qr <= l || r <= ql) { return -1; }
        if (l + 1 == r) { return l; }
        int left = c[0]->val >= cmp ? c[0]->walk(cmp, ql, qr) : -1;
        return left != -1 ? left : c[1]->walk(cmp, ql, qr);
    }
};
const int mxn = 2e5 + 5;
int a[mxn], p[mxn];
const int mx = 1024;
int am = 1e4;
int dp[mx], dp2[mx];


void solve(int tc)
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> p[i];
    

  for (int i = 0; i < mx; i++)
    dp[i] = 0;
  int modinv = pow(am, mod - 2, mod);
  dp[0] = 1;
  for (int i = 0; i < n; i++)
  {

    memset(dp2, 0, sizeof(dp2));
    for (int j = 0; j < mx; j++)
    {
      if (dp[j] == 0) continue;

      int next_yes = j ^ a[i];
      int next_no = j;
      int prob_yes = ((p[i] * modinv) % mod) * dp[j];
      int prob_no = (((am - p[i]) * modinv) % mod) * dp[j];
      prob_yes += mod;
      prob_no += mod; 
      prob_yes %= mod;
      prob_no %= mod;
      dp2[next_yes] += prob_yes + mod;
      dp2[next_no] += prob_no + mod;
      dp2[next_yes] %= mod;
      dp2[next_no] %= mod;
    } 
    memcpy(dp, dp2, sizeof(dp2));
  }

  int s = 0;

  for (int i = 0; i < mx; i++)
  {
    // cout << dp[i] << ' ';
    int cur = i * dp[i] * i;
    s += cur;
    s %= mod;
  }
  // cout << endl;
  cout << s << endl;
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