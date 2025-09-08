#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

int pow(int a, int b, int m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}



void solve(int tc)
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT32_MIN));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      dp[i + 1][j] = dp[i][j];
    }

    for (int j = 0; j <= n; j++)
    {
      if (dp[i][j] < 0) continue;
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i]);
    }
  }

  for (int i = n; i >= 0; i--)
  {
    if (dp[n][i] >= 0)
    {
      cout << i << endl;
      return;
    }
  }


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