#include <bits/stdc++.h>
#define ll long long
#define mll 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;




set<ll> get_divisors(ll n)
{
  set<ll> divisors;
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      divisors.insert(i);
      divisors.insert(n / i);
    }
  }

  return divisors;
}

void solve()
{
  ll n;
  cin >> n;
  set<ll> a_repl;
  for (ll i = 0; i < n; i++)
  {
    ll num;
    cin >> num;
    a_repl.insert(num);
  }
  vector<ll> a;
  for (ll num : a_repl)
  {
    a.push_back(num);
  }

  n = a.size();

  ll m = *min_element(a.begin(), a.end()) / 4;
  if (n <= 3)
  {
    ll ans = (m) * (m + 1) / 2;
    cout << ans << endl;
    return;
  }

  
  vector<ll> diffs;
  for (ll i = 0; i < 4; i++)
  {
    for (ll j = i + 1; j < 4; j++)
    {
      diffs.push_back(abs(a[i] - a[j]));
    }
  }

  set<ll> divisors;

  for (ll i = 0; i < diffs.size(); i++)
  {
    set<ll> ret = get_divisors(diffs[i]);
    for (ll asdf : ret)
    {
      divisors.insert(asdf);
    }
  }
  ll ans = 0;
  for (ll num : divisors)
  {
    // cout << num << endl;
    if (num > m)
    {
      continue;
    }
    set<ll> differents;
    for (ll i : a)
    {
      differents.insert(i % num);
    }
    if (differents.size() <= 3)
    {
      ans += num;
    }
  }
  cout << ans << endl;



}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
