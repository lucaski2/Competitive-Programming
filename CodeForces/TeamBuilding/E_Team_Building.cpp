#include <bits/stdc++.h>

#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const char en = '\n';










void solve(int tc)
{
  // for each 
  int n, p, k;
  cin >> n >> p >> k;

  struct info
  {
    int c;
    vector<int> t;
  };

  vector<info> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].c;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < p; j++)
    {
      int c;
      cin >> c;
      a[i].t.push_back(c);
    }
  }
  
  sort(all(a), [](info a, info b) { return a.c > b.c; });

  int mx = (1 << p);
  vector<vector<int>> dp(mx, vector<int>(p + 1, -1e14));
  dp[0][0] = 0;
  for (int i = 0; i < k; i++)
    dp[0][0] += a[i].c;

  for (int i = 0; i < n; i++)
  {
    vector<vector<int>> ndp = dp;



    for (int j = 0; j < p; j++)
    {
      for (int mask = 0; mask < mx; mask++)
      {
        for (int l = 0; l < p; l++)
        {
          if (dp[mask][l] == -1e14) continue;
          if (mask & (1 << j)) continue;
          if (i < l + k)
          {
            // you have to 
            int am = a[i].c - a[k + l].c;
            int next = dp[mask][l] - am + a[i].t[j];
            ndp[(mask | (1 << j))][l + 1] = max(ndp[(mask | (1 << j))][l + 1], next);
          }
          else
          {
            int next = dp[mask][l] + a[i].t[j];
            ndp[(mask | (1 << j))][l] = max(ndp[(mask | (1 << j))][l], next);
          }
        }
      }
    }
    dp = ndp;
  }

  cout << *max_element(all(dp[mx - 1])) << en;

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