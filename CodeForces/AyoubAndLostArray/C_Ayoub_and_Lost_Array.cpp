#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
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



void solve(ll tc)
{
  ll n, l, r;
  cin >> n >> l >> r;

  vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));

  ll n1 = l;
  ll zeros, ones, twos;
  if (l % 3 == 0)
  {
    zeros = (r - l) / 3 + 1;
    ones = (r - l + 2) / 3;
    twos = (r - l + 1) / 3;
  }
  else if (l % 3 == 1)
  {
    ones = (r - l) / 3 + 1;
    twos = (r - l + 2) / 3;
    zeros = (r - l + 1) / 3;
  }
  else if (l % 3 == 2)
  {
    twos = (r - l) / 3 + 1;
    zeros = (r - l + 2) / 3;
    ones = (r - l + 1) / 3;
  }

  dp[0][0] = 1;
  dp[0][1] = 0;
  dp[0][2] = 0;
  
  for (ll i = 0; i < n; i++)
  {
    // for (ll j = 0; j < 3; j++)
    // {
    //   dp[i + 1][j] = dp[i][j];
    // }
    for (ll j = 0; j < 3; j++)
    {
      dp[i + 1][j] += dp[i][j] * zeros;
      dp[i + 1][(j + 1) % 3] += dp[i][j] * ones;
      dp[i + 1][(j + 2) % 3] += dp[i][j] * twos;
    }
    for (ll j = 0; j < 3; j++)
    {
      dp[i + 1][j] %= mod;
    }
  }
  cout << dp[n][0] << endl;
  // cout << dp[n][0] << ' ' << dp[n][1] << ' ' << dp[n][2] << endl;
  // cout << zeros << ' ' << ones << ' ' << twos << endl;
  


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  for (ll i = 1; i <= t; i++)
  {
    solve(i);
  }
}