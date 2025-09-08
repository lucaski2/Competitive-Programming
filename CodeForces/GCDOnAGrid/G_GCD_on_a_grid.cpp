#include <bits/stdc++.h>
// #pragma GCC target ("avx,avx2,fma")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;

const char en = '\n';





void solve(int tc)
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];

  vector<int> divisors;
  for (int i = 1; i * i <= grid[0][0]; i++)
  {
    if (grid[0][0] % i == 0)
    {
      divisors.push_back(i);
      divisors.push_back(grid[0][0] / i);
    }
  }
  int ans = 0;
  vector<vector<bool>> dp(n, vector<bool>(m));

  for (int i : divisors)
  {
    for (int j = 0; j < n; j++)
      dp[j].assign(m, 0);

    dp[0][0] = true;
    for (int j = 0; j < n; j++)
    {

      for (int k = 0; k < m; k++)
      {
        if (!dp[j][k]) continue;
        if (j < n - 1 and grid[j + 1][k] % i == 0) dp[j + 1][k] = true;
        if (k < m - 1 and grid[j][k + 1] % i == 0) dp[j][k + 1] = true;
      }
    }
    if (dp[n - 1][m - 1])
    {
      ans = max(ans, i);
    }
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