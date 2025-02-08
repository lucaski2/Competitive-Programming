#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

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

// go through every number such that k bits are set
// or of all flipped ones should equal to ~num
// memoize per bit



void solve(int tc)
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  // if (tc != 1) return;
  int mx = 63;
  vector<vector<int>> dp(n + 1, vector<int>(mx + 1));


  for (int i = 0; i < n; i++)
  {
    dp[i + 1][a[i]]++;

    for (int j = 0; j <= mx; j++)
    {
      dp[i + 1][j & a[i]] += dp[i][j];
      dp[i + 1][j & a[i]] %= mod;
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= mod;
    }
  }   
  int ans = 0;
  for (int i = 0; i <= mx; i++)
  {
    if (__builtin_popcount(i) == k)
    {
      ans += dp[n][i];
    }
    // cout << dp[n][i] << endl;
  }
  cout << ans % mod << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}