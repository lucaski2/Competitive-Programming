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


void solve()
{
  ll n, x;
  cin >> n >> x;
  vector<ll> costs(n);
  vector<ll> happiness(n);
  // minimize cost for certain happiness
  for (ll i = 0; i < n; i++)
  {
    cin >> costs[i];
    cin >> happiness[i];
  }

  ll mx = accumulate(happiness.begin(), happiness.end(), 0) + 45;
  vector<vector<ll>> dp(n, vector<ll>(mx, mod * 100));

  for (ll i = 0; i < n; i++)
  {
    dp[i][0] = 0;
  }


  if (costs[0] == 0)
  {
    dp[0][happiness[0]] = 0;
  }

  ll cur_amount = x;
  for (ll i = 1; i < n; i++)
  {
    ll cost = costs[i];
    ll happy = happiness[i];

    for (ll j = 0; j < mx; j++)
    {
      dp[i][j] = dp[i - 1][j];
    }

    for (ll j = 0; j < mx; j++)
    {
      if (dp[i - 1][j] + cost <= cur_amount)
      {

        // cout << "asdf" << j << ' ' << cost << ' ' << cur_amount << ' ' << dp[i][j + happy] << ' ' << dp[i - 1][j] << endl;
        dp[i][j + happy] = min(dp[i][j + happy], dp[i - 1][j] + cost);
      }
    }

    cur_amount += x;
  }

  ll ans = 0;
  for (ll i = 0; i < mx; i++)
  {
    if (dp[n - 1][i] < x * n)
    {
      ans = max(ans, i);
    }
  }

  cout << ans << endl;

  // for (ll i = n - 1; i < n; i++)
  // {
  //   for (ll j = 0; j < mx; j++)
  //   {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}