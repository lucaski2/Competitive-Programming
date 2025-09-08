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

template <class T>
using order_statistics_tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Problem URL here:
// Start time here:
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';

struct mi
{

  int v;
  mi() : v(0) {}
  mi(int _v) : v((long long)(_v % mod)) { v += (v < 0) * mod; }
  friend mi operator+(mi a, const mi &b) { return mi(a.v + b.v); }
  friend mi operator-(mi a, const mi &b) { return mi(a.v - b.v); }
  friend mi operator*(mi a, const mi &b) { return mi((int)a.v * b.v); }
  friend mi operator/(mi a, const mi &b) { return a * inv(b); }
  friend mi pow(mi a, int p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
  friend mi inv(const mi &a) { return pow(a, mod - 2); }
  mi &operator+=(const mi &o) { return (*this) = (*this) + o; }
  mi &operator-=(const mi &o) { return (*this) = (*this) - o; }
  mi &operator*=(const mi &o) { return (*this) = (*this) * o; }
  mi &operator/=(const mi &o) { return (*this) = (*this) / o; }
};

vector<int> fact = {1};

int factorial(int n)
{
  while (fact.size() - 1 < n)
    fact.push_back((fact.back() * fact.size()) % mod);

  return fact[n];
}

int pow(int a, int b, int m)
{
  int ans = 1;
  while (b)
  {
    if (b & 1)
      ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
int choose(int n, int k) { return (factorial(n) * pow(factorial(k), mod - 2, mod)) % mod * pow(factorial(n - k), mod - 2, mod) % mod; }
int permute(int n, int k) { return (factorial(n) * pow(factorial(n - k), mod - 2, mod)) % mod; }
struct DSU
{
  vector<int> e;
  void init(int N) { e = vector<int>(N, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool sameSet(int a, int b) { return get(a) == get(b); }
  int size(int x) { return -e[get(x)]; }
  bool unite(int x, int y)
  { // union by size
    x = get(x), y = get(y);
    if (x == y)
      return 0;
    if (e[x] > e[y])
      swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return 1;
  }
};

template <typename T>
struct Seggy
{
  int N, ql, qr;
  vector<T> data;
  T def, val;
  void init(int _N, T _def)
  {
    N = _N;
    def = _def;
    data.resize(4 * N, def);
  }
  T comb(T a, T b) { return max(a, b); }
#define m ((l + r) / 2)
  T qry(int n, int l, int r)
  {
    if (r < ql || qr < l)
    {
      return def;
    }
    if (ql <= l && r <= qr)
    {
      return data[n];
    }
    return comb(qry(2 * n, l, m), qry(2 * n + 1, m + 1, r));
  }
  void upd(int n, int l, int r)
  {
    if (l == r)
    {
      data[n] = val;
      return;
    }
    if (ql <= m)
    {
      upd(2 * n, l, m);
    }
    else
    {
      upd(2 * n + 1, m + 1, r);
    }
    data[n] = comb(data[2 * n], data[2 * n + 1]);
  }
#undef m
  T query(int l, int r)
  {
    ql = l, qr = r;
    return qry(1, 0, N - 1);
  }
  void update(int idx, T v)
  {
    ql = idx, val = v;
    upd(1, 0, N - 1);
  }
};

template <typename T>
struct sparse_table
{
  const int LOG = 20;
  T n;
  vector<vector<T>> dp;
  T merge(T a, T b)
  {
    return min(a, b);
  }
  sparse_table(vector<T> &a)
  {
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
        if (next_id < n)
        {
          dp[id][j] = merge(dp[id][j], dp[id - 1][next_id]);
        }
      }
    }
  }
  T query(int l, int r)
  {
    int d = r - l + 1;
    int id = __builtin_clzll(1) - __builtin_clzll(d);
    int shift = (1LL << id);
    return merge(dp[id][l], dp[id][r - shift + 1]);
  }
};

void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  int mx = 1e6 + 5;
  vector<vector<int>> segs(mx);
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    segs[a].push_back(b);
  }

  vector<vector<int>> queries(q);
  vector<int> ans(q);
  for (int i = 0; i < q; i++)
  {
    int c;
    cin >> c;
    
    while (c--)
    {
      int a;
      cin >> a;
      queries[i].push_back(a);
    }
    reverse(all(queries[i]));
  }

  order_statistics_tree<pair<int, int>> ost;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  for (int i = 0; i < q; i++)
  {
    pq.push({queries[i].back(), i});
    queries[i].pop_back();
  }

  int cnt = 0; // unique ah shi

  for (int i = 0; i < mx; i++)
  {

    // all the ost shi
    for (int j = 0; j < segs[i].size(); j++)
    {
      // cout << "ts pmo sm" << endl;
      ost.insert({segs[i][j], cnt});
      cnt++;
    }

    while (ost.size())
    {
      pair<int, int> cur = *ost.find_by_order(0);
      if (cur.f < i)
      {
        ost.erase(cur);
      }
      else break;
    }

    // check yo ah w the pq
    while (pq.size() and pq.top().f == i)
    {
      // cout << "does ts every happen + lets see how big this dih is " << ost.size() << endl;
      pair<int, int> cur = pq.top();
      // if (cur.s == 1) cout << ans[cur.s] << ' ' << ost.size() << ' ' << i << endl;

      pq.pop();
      if (queries[cur.s].size())
      {
        ans[cur.s] += ost.order_of_key({queries[cur.s].back() - 1, INT_MAX});
        pq.push({queries[cur.s].back(), cur.s});
        queries[cur.s].pop_back();
      }
      else ans[cur.s] += ost.size();
    }
  }
  for (int ele : ans)
    cout << ele << '\n';
  

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