#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';
const ll INF = pow(10, 18);

template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  ll n;
  cin >> n;
  
  vector<ll> a(n);

  ll ans = INF;

  for (ll i = 0; i < n; i++)
    cin >> a[i];
  
  sort(a.begin(), a.end());

  for (ll c = 1; c < 100000; c++)
  {
    ll am = 0;
    bool ok = true;
    for (ll i = 0; i < n; i++)
    {
      ll cur = pow(c, i);
      if (cur > INF / pow(10, 5))
      {
        ok = false;
        break;
      }
      am += abs(a[i] - cur);
    }
    if (ok)ans = min(ans, am);
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}