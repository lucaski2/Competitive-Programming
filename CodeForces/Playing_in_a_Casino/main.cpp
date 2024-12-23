#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> grid(m, vector<ll>(n));
  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < m; j++)
    {
      cin >> grid[j][i];
    }
  }
  for (ll i = 0; i < m; i++)
  {
    sort(grid[i].begin(), grid[i].end());
  }
  ll ans = 0;
  for (ll i = 0; i < m; i++)
  {
    ll s = 0;
    for (ll j = 0; j < n; j++)
    {
      s += grid[i][j];
      ans += (j + 1) * grid[i][j] - s;
    }
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