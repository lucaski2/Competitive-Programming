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
    T comb(T a, T b) { return a + b; }
    #define m (l + r) / 2
    void upd(int l, int r, int i)
    {
      if (l > qr or r < ql) return;
      if (l >= ql and r <= qr)
      {
        data[i] += val;
        return;
      }
      upd(l, m, i * 2);
      upd(m + 1, r, i * 2 + 1);
    }
    #undef m

    int query(int i)
    {
      i += N;
      int s = 0;
      while (i > 0)
      {
        s += data[i];
        i /= 2;
      }
      return s;
    }

    void update(int l, int r, int v)
    {
      ql = l;
      qr = r;
      val = v;
      upd(0, N - 1, 1);
    }
};



void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int M = 1;
  while (M < 2*n) M <<= 1;

  Seggy<int> seggy;
  seggy.init(M, 0);

  int cnt = 0;
  vector<int> early(n);
  vector<int> late(n);


  function<void(int, int, int)> et = [&](int cur, int par, int s)
  {    
    int am = s + a[cur];
    seggy.update(cnt, cnt, am);
    early[cur] = cnt;
    cnt++;

    for (int v : g[cur])
    {
      if (v == par) continue;

      et(v, cur, am);
    }

    seggy.update(cnt, cnt, am);
    late[cur] = cnt;
    cnt++;

  };
  et(0, -1, 0);

  while (q--)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      int s, x;
      cin >> s >> x;
      s--;
      int incr = x - a[s];
      a[s] = x;
      seggy.update(early[s], late[s], incr);
    }

    if (t == 2)
    {
      int x;
      cin >> x;
      cout << seggy.query(early[--x]) << endl;
    }
  }
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}