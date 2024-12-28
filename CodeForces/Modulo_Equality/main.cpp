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

  vector<ll> a(n);
  vector<ll> b(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (ll j = 0; j < n; j++)
    cin >> b[j];
  sort(b.begin(), b.end());


  ll ans = mod;
  for (ll i = 0; i < n; i++)
  {
    ll am_shifted;
    if (b[i] >= a[0])
    {
      am_shifted = b[i] - a[0];
    }
    else am_shifted = b[i] + m - a[0];

    vector<ll> temp = a;
    for (ll j = 0; j < n; j++)
    {
      temp[j] = (temp[j] + am_shifted) % m;
    }
    sort(temp.begin(), temp.end());
    bool ok = true;
    for (ll j = 0; j < n; j++)
      ok = min(ok, temp[j] == b[j]);
    if (ok) ans = min(ans, am_shifted);
  }
  cout << ans << endl;



}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}