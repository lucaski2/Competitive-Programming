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
  vector<ll> b(m);
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (ll i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  ll g = 0;
  for (ll i = 1; i < n; i++)
  {
    g = gcd(g, a[i] - a[0]);
  }

  for (ll i = 0; i < m; i++)
  {
    cout << gcd(g, a[0] + b[i]) << ' ';
  }
  cout << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  while (t--)
  {
      solve();
  }
}