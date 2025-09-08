#include <bits/stdc++.h>

#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;



// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';






struct Seggy {
    int N, ql, qr;
    vector<int> data;
    int def, val;
    void init(int _N, int _def) {
        N = _N;
        def = _def;
        data.resize(4 * N, def);
    }
    int comb(int a, int b) { return gcd(a, b); }
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



void solve(int tc)
{
  // for each index binary search + segtree to find segment such that gcd(segment) > 1
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> diffs(n - 1);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (i > 0) diffs[i - 1] = abs(a[i] - a[i - 1]);
  }

  // Seggy seggy;
  // seggy.init(n - 1, 0);
  // for (int i = 0; i < n - 1; i++)
  //   seggy.update(i, diffs[i]);
  sparse_table<int> table(diffs);
  
  int ans = 1;
  for (int i = 0; i < n - 1; i++)
  {
    int l = 0, r = i;
    int best = INT_MAX;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      
      int am = table.query(mid, i);
      if (am > 1)
      {
        best = min(best, mid);
        r = mid - 1;
      }
      else l = mid + 1;
    }

    ans = max(ans, i - best + 2);
  }
  cout << ans << endl;
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