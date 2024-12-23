#include <bits/stdc++.h>
#define ll long long
#define mll 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  set<ll> asdf;
  for (ll i = 0; i < n; i++) cin >> a[i];
  for (ll i = 0; i < n; i++) asdf.insert(a[i]);
  ll accum = accumulate(a.begin(), a.end(), 0);
  ll cnt = count(a.begin(), a.end(), 0);

  if (*max_element(a.begin(), a.end()) == 0 and *min_element(a.begin(), a.end()) == 0)
  {
    cout << "YES" << endl;
    return;
  }
  else if (cnt == n - 1 or (accum == 0 and cnt == n - 2))
  {
    cout << "YES" << endl; return;
  }
  else if (a.size() > 5)
  {
    cout << "NO" << endl;
    return;
  }
  bool ok = true;
  for (ll i = 0; i < n; i++)
  {
    for (ll j = i + 1; j < n; j++)
    {
      for (ll k = j + 1; k < n; k++)
      {
        if (asdf.find(a[i] + a[j] + a[k]) == asdf.end() and ok)
        {
          cout << "NO" << endl;
          ok = false;
        }
      }
    }
  }
  if (ok)
  {
    cout << "YES" << endl;
  }

  



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