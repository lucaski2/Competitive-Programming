#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;

int dp[2005][2005];

template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  string a;
  string b;
  string c;
  cin >> a >> b >> c;
  int n = c.size();

  memset(dp, 0, sizeof(dp));
  dp[0][0] = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j <= a.size() and j + b.size() >= i)
      {

        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (c[i] == a[j]));
      }
      if (i - j >= 0 and i - j <= b.size() and i - j + a.size() >= i)
      {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (c[i] == b[i - j]));
      }
    }
  }

  cout << n - *max_element(dp[n], dp[n] + n + 1) << endl;



}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}
