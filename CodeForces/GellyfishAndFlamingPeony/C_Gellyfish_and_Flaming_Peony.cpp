#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;
const int mx = 5e3 + 1;



void solve(int tc)
{
  int n;
  cin >> n;
  int g = 0;
  vector<int> a(n);
  for (auto &u : a)
  {
    cin >> u;
  }
  for (int i = 0; i < n; i++)
    g = gcd(a[i], g);
  for (int i = 0; i < n; i++)
    a[i] /= g;

  sort(all(a));

  if (a[0] == 1)
  {
    cout << n - count(all(a), 1) << '\n';
    return;
  }
  vector<int> dp(mx, 1e9);

  for (int i = 0; i < n; i++)
  {
    dp[a[i]] = 0;


    for (int j = 1; j < mx; j++)
    {
      dp[gcd(a[i], j)] = min(dp[gcd(a[i], j)], dp[j] + 1);
    }
  }
  cout << dp[1] + n - 1 << '\n';
}

signed main()
{
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}