#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  int n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

  for (int i = 1; i <= n; i++)
    dp[i][i] = 0;
  
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      for (int k = 1; k < i; k++)
      { 
        dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
      }
      for (int k = 1; k < j; k++)
      {
        dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
      }
    }
  }
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  cout << dp[n][m] << endl;


}