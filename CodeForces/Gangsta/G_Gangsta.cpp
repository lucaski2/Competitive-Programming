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
    T comb(T a, T b) { return {a.f + b.f, a.s + b.s}; }
    #define m ((l + r) / 2)
    T qry(int n, int l, int r) {
        if(r < ql || qr < l) { return def; }
        if(ql <= l && r <= qr) { return data[n]; }
        return comb(qry(2*n, l, m), qry(2*n+1, m + 1, r));
    }
    void upd(int n, int l, int r) {
        if(l == r) { data[n] = comb(data[n], val); return; }
        if(ql <= m) { upd(2*n, l, m); }
        else { upd(2*n+1, m + 1, r); }
        data[n] = comb(data[2*n], data[2*n+1]);
    }
    #undef m
    T query(int l, int r) { ql = l, qr = r; return qry(1, 0, N - 1); }
    void update(int idx, T v) { ql = idx, val = v; upd(1, 0, N - 1); }
};



void solve(int tc)
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  // start by doing all with 0s
  // count the number of 0s - 1s so far, add to segtree
  // query < current running
  // if it's of index i and diff x
  // number of zeros is (j - i + 1 - (running - query)) / 2 + (running - query)
  // (j - i + 1 - running + query) / 2 + (running - query)
  // j - i + 1 - running + query + 2*running - 2*query
  // j - i + 1 + running - query
  // segtree element is responsible for sum of i + query
  // then for each element in the segtree 
  // store i + query
  // (j + 1 + running) * elements - query_sum

  // if (tc != 3) return;

  // int M = 1;
  // while (M < 4 * n) M <<= 1;

  int ans = 0;
  
  int run = 2 * n;
  Seggy<pair<int, int>> seggy;

  seggy.init(4 * n, {0, 0});

  for (int i = 0; i < n; i++)
  {
    seggy.update(run, {i + run, 1});
    
    run += (s[i] == '1' ? 1 : -1);

    pair<int, int> q = seggy.query(0, run - 1);
    ans += (i + 1 + run) * q.s - q.f;
    // cout << ans << endl;
  }

  run = 2 * n;
  Seggy<pair<int, int>> seggy2;

  seggy2.init(4 * n, {0, 0});

  for (int i = 0; i < n; i++)
  {
    seggy2.update(run, {i + run, 1});
    
    run += (s[i] == '0' ? 1 : -1);

    pair<int, int> q = seggy2.query(0, run);
    ans += (i + 1 + run) * q.s - q.f;
    // cout << ans << endl;
  }
  

  cout << ans / 2 << endl;

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