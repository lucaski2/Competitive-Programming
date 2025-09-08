#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1e9 + 7;
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
  int t, k;
  cin >> t >> k;
  int mx = 2e5+10;
  vector<int> dp(mx + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < mx; i++)
  {
    if (i + k < mx)
    {
      dp[i + k] += dp[i];
      dp[i + k] %= mod;
    }
    dp[i + 1] += dp[i];
    dp[i + 1] %= mod;
  }
  vector<int> psum(mx + 1);
  for (int i = 0; i < mx; i++)
  {
    psum[i + 1] = psum[i] + dp[i];
    psum[i + 1] %= mod;
  }

  for (int i = 0; i < t; i++)
  {
    int a, b;
    cin >> a >> b;
    cout << (psum[b + 1] - psum[a]) + (psum[a] > psum[b + 1] ? mod : 0) << endl;
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