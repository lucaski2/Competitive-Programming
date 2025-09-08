#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #define int long long
// #define int short
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second
 
using namespace std;
 
 
 
void solve(int tc)
{
  int n, k;
  cin >> n >> k;
 
  vector<pair<int, int>> cnts(n);
  for (int i = 0; i < n; i++)
  {
    long long a;
    cin >> a;
 
    while (a > 1 and a % 2 == 0)
    {
      cnts[i].first++;
      a /= 2;
    }
    while (a > 1 and a % 5 == 0)
    {
      cnts[i].second++;
      a /= 5;
    }
  }
  int mx = 3601;
  vector<vector<int>> dp(n + 1, vector<int>(mx + 5, -1));
  // i = ind, j = cur_k, k = #2s
  dp[0][0] = 0;
 
  for (int i = 0; i < n; i++)
  { 
    vector<vector<int>> cur(n + 1, vector<int>(mx + 5, -1));
    for (int j = 0; j <= k; j++)
    {
      for (int l = 0; l <= mx - 1; l++)
      {
        if (dp[j][l] == -1) continue;
        int new_j = j + 1;
        int new_l = l + cnts[i].f;
        // new_l = min(new_l, (int)3600);
        if (new_l > 3600) new_l = 3600;
        cur[new_j][new_l] = max(dp[j][l] + cnts[i].s, cur[new_j][new_l]);
        cur[j][l] = max(cur[j][l], dp[j][l]);
      }
    }
    dp = cur;
  } 
  int ans = 0;
  for (int l = 0; l <= mx; l++)
  {
    // cout << dp[n][k][l] << endl;
    ans = max(ans, min(dp[k][l], l));
  }
  cout << ans << endl;
 
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