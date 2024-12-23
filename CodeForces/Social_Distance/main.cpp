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
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<ll>());
  m -= accumulate(a.begin(), a.end(), n);
  m -= a[0];
  m += a[n - 1];

  cout << (m >= 0 ? "YES" : "NO") << endl;
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