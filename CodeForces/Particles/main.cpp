#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll s1 = 0;
  ll s2 = 0;
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
    if (i % 2 == 0)
    {
      s1 += max(a[i], 0ll);
    }
    else s2 += max(a[i], 0ll);
  }
  if (*max_element(a.begin(), a.end()) >= 0)
    cout << max(max(s1, 0ll), max(s2, 0ll)) << en;
  else 
    cout << *max_element(a.begin(), a.end()) << en;
  


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