#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC target ("avx,avx2,fma")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
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

template<typename T>
struct sparse_table
{
    const int LOG = 20;
    T n;
    vector<vector<T> > dp;
    T merge(T a, T b){
        return min(a, b);
    }
    sparse_table(vector<T> &a){
        n = a.size();
        dp.resize(LOG);
        dp[0] = a;

        for (int id = 1; id < LOG; id++)
        {
            dp[id].resize(n);
            for (int j = 0; j < n; j++)
            {
                dp[id][j] = dp[id - 1][j];
                int next_id = j + (1 << (id - 1));
                if(next_id < n){
                    dp[id][j] = merge(dp[id][j], dp[id - 1][next_id]);
                }
            }
        }
    }
    T query(int l, int r){
        int d = r - l + 1;
        int id = __builtin_clzll(1) - __builtin_clzll(d); 
        int shift = (1LL << id);
        return merge(dp[id][l], dp[id][r - shift + 1]);
    }
};


int n, m;
vector<vector<int>> a;
vector<vector<pair<int, int>>> ans;

pair<vector<pair<int, int>>, vector<pair<int, int>>> ginds(int i, int j)
{
  pair<vector<pair<int, int>>, vector<pair<int, int>>> v;
  for (int k = i; k <= i + 1; k++)
  {
    for (int m = j; m <= j + 1; m++)
    {
      if (a[k][m]) v.f.push_back({k, m});
      else v.s.push_back({k, m});
    }
  }
  return v;
}


void solve(int tc)
{
  cin >> n >> m;

  a = vector<vector<int>>(n, vector<int>(m));
  ans.clear();

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char c;
      cin >> c;
      a[i][j] = (c == '1');
    }
  }

  function<int(int, int)> gc = [&](int i, int j)
  {
    int s = (a[i][j]) + (a[i][j + 1]) + (a[i + 1][j]) + (a[i + 1][j + 1]);
    return s;
  };



  function<void(int, int)> solve = [&](int i, int j)
  {
    int iter = 0;
    // if (tc == 1) cout << gc(i, j) << endl;
    while (gc(i, j))
    {
      // if (tc == 5 and i == 0 and j == 0)
      // {
      //   for (int k = 0; k < n; k++)
      //   {
      //     for (int l = 0; l < m; l++)
      //       cout << a[k][l];
      //     cout << endl;
      //   } 
      //   cout << ans.size() << endl;
      //   cout << endl;
      // }
      if (gc(i, j) == 3)
      {
        vector<pair<int, int>> v = ginds(i, j).f;
        ans.push_back(v);
        for (auto p : v)
          a[p.f][p.s] = 0;
      }
      else if (gc(i, j) == 2)
      {
        auto [o, z] = ginds(i, j);
        vector<pair<int, int>> v;
        for (auto p : z)
        {
          v.push_back(p);
          a[p.f][p.s] = 1;
        }
        v.push_back(o[0]);
        a[o[0].f][o[0].s] = 0;
        ans.push_back(v);
      }
      else if (gc(i, j) == 1)
      {
        auto [o, z] = ginds(i, j);

        vector<pair<int, int>> v;
        z.pop_back();
        for (auto p : z)
        {
          v.push_back(p);
          a[p.f][p.s] = 1;
        }
        for (auto p : o)
        {
          v.push_back(p);
          a[p.f][p.s] = 0;
        }
        ans.push_back(v);
      }

      else if (gc(i, j) == 4)
      {
        vector<pair<int, int>> v = ginds(i, j).f;
        v.pop_back();
        ans.push_back(v);
        for (auto p : v)
          a[p.f][p.s] = 0;
      }
    }
    // if (tc == 1) cout << iter << endl;
  };



  if (n % 2 == 1)
  {
    for (int i = 0; i < m - 1; i += 2)
    {
      if (a[n - 1][i] + a[n - 1][i + 1] == 0) continue;
      if (a[n - 1][i] + a[n - 1][i + 1] == 1)
      {
        ans.push_back({{n - 1, (a[n - 1][i] ? i : i + 1)}, {n - 2, i}, {n - 2, i + 1}});
        a[n - 1][i] = 0;
        a[n - 1][i + 1] = 0;
        a[n - 2][i] ^= 1;
        a[n - 2][i + 1] ^= 1;
      }
      else
      {
        ans.push_back({{n - 1, i}, {n - 1, i + 1}, {n - 2, i}});
        a[n - 1][i] = 0;
        a[n - 1][i + 1] = 0;
        a[n - 2][i] ^= 1;
      }
    }
  }

  if (m % 2 == 1)
  {
    for (int i = 0; i < n - 1; i += 2)
    {
      if (a[i][m - 1] + a[i + 1][m - 1] == 0) continue;
      if (a[i][m - 1] + a[i + 1][m - 1] == 1)
      {
        ans.push_back({{(a[i][m - 1] ? i : i + 1), m - 1}, {i, m - 2}, {i + 1, m - 2}});
        a[i][m - 1] = 0;
        a[i + 1][m - 1] = 0;
        a[i][m - 2] ^= 1;
        a[i + 1][m - 2] ^= 1;
      }
      else
      {
        ans.push_back({{i, m - 1}, {i + 1, m - 1}, {i, m - 2}});
        a[i][m - 1] = 0;
        a[i + 1][m - 1] = 0;
        a[i][m - 2] ^= 1;
      }
    }
  }

  if (n % 2 == 1 and m % 2 == 1)
  {
    solve(n - 2, m - 2); 
  }



  for (int i = 0; i < n - 1; i += 2)
  {
    for (int j = 0; j < m - 1; j += 2)
    {
      solve(i, j);
    }
  }

  cout << ans.size() << endl;
  for (auto ele : ans)
  {
    for (auto it : ele)
      cout << it.f + 1 << ' ' << it.s + 1 << ' ';
    cout << endl;
  }


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