#include <bits/stdc++.h>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;


void solve(int tc)
{
  string s;
  cin >> s;

  int n = s.size();

  // choose index k st k == s[i]

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

  for (int i = 0; i < n; i++)
  {
    dp[i][i] = 1;
  }
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      dp[i][j] = 0;
    }
  }

  for (int sz = 1; sz < n; sz++)
  {
    for (int i = 0, j = sz; j < n; j++, i++)
    {
      dp[i][j] = 1 + dp[i + 1][j];
      for (int k = i + 1; k <= j; k++)
      {
        if (s[i] != s[k]) continue;
        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
      }
    }
  }
  cout << dp[0][n - 1] << endl;


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