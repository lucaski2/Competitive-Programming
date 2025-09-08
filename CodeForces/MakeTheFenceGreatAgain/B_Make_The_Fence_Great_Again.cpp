#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
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

vector<int> a, b;

void solve(int tc)
{
  int n;
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
  }
  vector<vector<int>> dp(n, vector<int>(3, INF));
  dp[0][0] = 0;
  dp[0][1] = b[0];
  dp[0][2] = b[0] * 2;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        if (a[i] + k == a[i - 1] + j) continue;
        dp[i][k] = min(dp[i][k], dp[i - 1][j] + b[i] * k);
      }
    }
  }
  cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << endl;

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