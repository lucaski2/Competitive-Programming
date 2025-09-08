#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 998244353;
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
  int q, k;
  cin >> q >> k;
  vector<vector<int>> dp(q + 1, vector<int>(k + 1));
  dp[0][0] = 1;
  for (int i = 0; i < q; i++)
  {
    char b;
    int a;
    cin >> b >> a;
    a = (-1 * (b == '-')) * a;

    for (int j = 0; j <= k; j++)
    {
      dp[i + 1][j] = dp[i][j];
    }

    for (int j = 0; j <= k; j++)
    {
      int ind = j + a;
      if (ind > k or ind < 0) continue;
      dp[i + 1][ind] += dp[i][j];
    }
    cout << dp[i + 1][k] << endl;
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