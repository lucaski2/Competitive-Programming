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



void solve(int tc)
{
  string s;
  cin >> s;
  int n = s.size();

  int q;
  cin >> q;

  struct comp
  {
    bool operator()(pair<int, int> a, pair<int, int> b) const
    {
      if (a.s == b.s) return a.f < b.f;
      return a.s < b.s;
    }
  };

  set<pair<int, int>> sl;
  set<pair<int, int>, comp> sr;
  multiset<int> sz;

  function<void(int)> mr = [&](int cur)
  {
    auto lptr = sl.lower_bound({cur, -1});
    auto rptr = sr.lower_bound({-1, cur - 1});
    bool il = (lptr != sl.end() and lptr->f == cur + 1);
    bool ir = (rptr != sr.end() and rptr->s == cur - 1);

    if (il and ir)
    {
      pair<int, int> ls = *rptr;
      pair<int, int> rs = *lptr;

      sl.erase(ls);
      sl.erase(rs);
      sr.erase(ls);
      sr.erase(rs);
      sz.erase(sz.find(ls.s - ls.f + 1));
      sz.erase(sz.find(rs.s - rs.f + 1));
      pair<int, int> next = {ls.f, rs.s};
      sl.insert(next);
      sr.insert(next);
      sz.insert(next.s - next.f + 1);
    }
    else if (il)
    {
      pair<int, int> rs = *lptr;
      sl.erase(rs);
      sr.erase(rs);
      sz.erase(sz.find(rs.s - rs.f + 1));
      pair<int, int> next = {cur, rs.s};
      sl.insert(next);
      sr.insert(next);
      sz.insert(next.s - next.f + 1);
    }


    else if (ir)
    {
      pair<int, int> ls = *rptr;
      sl.erase(ls);
      sr.erase(ls);
      sz.erase(sz.find(ls.s - ls.f + 1));
      pair<int, int> next = {ls.f, cur};
      sl.insert(next);
      sr.insert(next);
      sz.insert(next.s - next.f + 1);
    }
    else
    {
      sl.insert({cur, cur});
      sr.insert({cur, cur});
      sz.insert(1);
    }
  };

  for (int i = 0; i < n; i++)
  {
    char c = s[i];
    if (c == '1') mr(i);
  }

  for (int i = 0; i < q; i++)
  {
    int ind;
    cin >> ind;
    ind--;

    if (s[ind] == '0')
      mr(ind);
    else
    {
      
    }
    cout << *sz.rbegin() << ' ';
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