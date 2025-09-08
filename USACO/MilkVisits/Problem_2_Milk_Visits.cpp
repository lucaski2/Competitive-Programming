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

struct Seggy {
    int N, ql, qr;
    vector<map<int, int>> data;
    int val, depth;
    void init(int _N) {
        N = _N;
        data.resize(2 * N);
    }
    #define m (l + r) / 2
    void upd(int l, int r, int i)
    {
      if (l > qr or r < ql) return;
      if (l >= ql and r <= qr)
      {
        if (data[i].find(val) == data[i].end()) data[i][val] = depth;
        else data[i][val] = max(data[i][val], depth);
        return;
      }
      upd(l, m, i * 2);
      upd(m + 1, r, i * 2 + 1);
    }
    #undef m
 
    int query(int i, int val)
    {
      i += N;
      int s = -1;
      while (i > 0)
      {
        if (data[i].find(val) != data[i].end()) s = max(s, data[i][val]);
        i /= 2;
      }
      return s;
    }
 
    void update(int l, int r, int v, int d)
    {
      ql = l;
      qr = r;
      val = v;
      depth = d;
      upd(0, N - 1, 1);
    }
};

template<typename T>
struct sparse_table
{
    const int LOG = 20;
    int n;
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
void solve(int tc)
{
  ifstream cin("milkvisits.in");
  ofstream cout("milkvisits.out");
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

  vector<pair<int, int>> et;
  vector<int> start(n);
  vector<int> end(n);
  int cnt = 0;

  Seggy seggy;
  int m = 1;
  while (m < 2 * n) m <<= 1;
  seggy.init(m);

  function<void(int, int, int)> dfs = [&](int cur, int par, int depth)
  {
    start[cur] = cnt;
    et.push_back({depth, cur});
    end[cur] = cnt;
    cnt++;

    for (int neighbor : g[cur])
    {
      if (neighbor == par) continue;
      dfs(neighbor, cur, depth + 1);

      end[cur] = cnt++;
      et.push_back({depth, cur});
    }

    seggy.update(start[cur], end[cur], a[cur], depth);
  };

  dfs(0, -1, 0);

  sparse_table<pair<int, int>> sparse(et);

  while (q--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    int val = max(seggy.query(start[a], c), seggy.query(start[b], c));
    pair<int, int> lca = sparse.query(min(start[a], start[b]), max(start[a], start[b]));
    if (lca.f <= val)
    {
      cout << '1';
    }
    else cout << '0';
  }
  cout << endl;

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