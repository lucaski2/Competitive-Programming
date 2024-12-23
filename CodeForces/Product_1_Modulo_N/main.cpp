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
  vector<ll> ans;
  if (n % 2 == 0)
  {
    ll fin_mod = 1;
    for (ll i = 1; i < n; i += 2)
    {
      fin_mod *= i;
      fin_mod %= n;
    }
    for (ll i = 1; i < n; i += 2)
    {
      if (fin_mod != i or i == 1)
      {
        ans.push_back(i);
      }
    }
  }
  else
  {
    ll fin_mod = 1;
    for (ll i = 1; i < n; i++)
    {
      fin_mod *= i;
      fin_mod %= n;
    }
    for (ll i = 1; i < n; i++)
    {
      if (i != fin_mod or i == 1)
      {
        ans.push_back(i);
      }
    }
  }
  cout << ans.size() << en;
  for (ll a : ans) cout << a << ' ';
  cout << en;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}