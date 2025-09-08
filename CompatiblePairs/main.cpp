#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll n, a, b;
  cin >> n >> a >> b;

  vector<pair<ll, ll>> cw(n);
  for (ll i = 0; i < n; i++)
    cin >> cw[i].second >> cw[i].first;

  sort(cw.begin(), cw.end());




  map<ll, ll> mp;
  ll answer = 0;
  for (ll i = 0; i < n; i++)
  {
    // cout << b - cw[i].first << ' ' << a - cw[i].first << endl;

    if (mp.find(b - cw[i].first) != mp.end())
    {
      if (cw[i].first > b) continue;
      ll amount = min(mp[b - cw[i].first], cw[i].second);
      cw[i].second -= amount;
      mp[b - cw[i].first] -= amount;
      answer += amount;
      // cout << amount << endl;
    }

    if (mp.find(a - cw[i].first) != mp.end())
    {
      if (cw[i].first > a) continue;
      ll amount = min(mp[a - cw[i].first], cw[i].second);
      cw[i].second -= amount;
      mp[a - cw[i].first] -= amount;
      answer += amount;
      // cout << amount << endl;
    }


    mp[cw[i].first] = cw[i].second;
  }




  for (auto cow : mp)
  {
    if (cow.first * 2 == a or cow.first * 2 == b)
    {
      answer += cow.second / 2;
    }
  }
  
  cout << answer << endl;
}



