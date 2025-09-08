#include <bits/stdc++.h>
#define ll long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1e9 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

ll pow(ll a, ll b, ll m){
    ll ans = 1;
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
  int target = (n + 1) * n;
  if (target % 4 != 0)
  {
    cout << 0 << endl;
    return;
  }
  target /= 2;
  target /= 2;
  vector<vector<int>> dp(n + 1, vector<int>(target + 1));

  dp[0][0] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= target; j++)
    {
      dp[i][j] = dp[i - 1][j];
    }

    for (int j = 0; j <= target; j++)
    {
      dp[i][j] %= mod;
      if (j + i > target) continue;
      dp[i][j + i] = (dp[i - 1][j] % mod + dp[i][j + i] % mod) % mod;
    }
  }
  cout << (dp[n][target] * pow(2, mod - 2, mod)) % mod << endl;
  

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