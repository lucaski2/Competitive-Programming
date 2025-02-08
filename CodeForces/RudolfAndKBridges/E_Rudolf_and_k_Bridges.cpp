#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}


void solve()
{
  ll n, m, k, d;
  cin >> n >> m >> k >> d;
  vector<ll> costs(n);
  vector<ll> dp(m, 1);

  for(ll i = 0; i < n; i++)
  {
    vector<ll> row(m);
    for (ll j = 0; j < m; j++)
    {
      cin >> row[j];
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({1, 0});
    for (ll j = 1; j < m; j++)
    {
      while (pq.top().second + 1 < j - d)
      {
        pq.pop();
      }
      dp[j] = pq.top().first + row[j] + 1;
      pq.push({dp[j], j});
    }
    costs[i] = dp[m - 1];
  }

  // for (ll i = 0; i < n; i++)
  //   cout << costs[i] << ' ';
  // cout << endl;

  vector<ll> psum(n + 1);
  for (ll i = 0; i < n; i++)
  {
    psum[i + 1] = psum[i] + costs[i];
  }
  ll ans = INT64_MAX;
  for (ll i = 0; i < n - k + 1; i++)
  {
    ans = min(ans, psum[i + k] - psum[i]);
  }
  cout << ans << endl;

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