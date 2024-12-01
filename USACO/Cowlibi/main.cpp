#include <bits/stdc++.h>
#define ll long long
#define mll 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


ll dist_squared(ll x1, ll y1, ll x2, ll y2)
{
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve()
{
  ll g, n;
  cin >> g >> n;
  
  ll ans = 0;
  map<ll, pair<ll, ll>> fields;

  for (ll i = 0; i < g; i++)
  {
    ll x, y, r;
    cin >> x >> y >> r;
    fields[r] = {x, y};
  }

  

  for (ll i = 0; i < n; i++)
  {
    ll x, y, t;
    cin >> x >> y >> t; 
    
    auto ptr1 = fields.lower_bound(t);
    // go to previous poller
    auto ptr2 = fields.upper_bound(t);

    ll am = 0;
    if (ptr1 != fields.end())
    {
      if (dist_squared(x, y, ptr1->second.first, ptr1->second.second) <= (ptr1->first - t) * (ptr1->first - t))
      {
        am++;
      }
    }

    else
    {
      am++;
    }
    

    if (ptr2 != fields.begin())
    {
      ptr2--;
      if (dist_squared(x, y, ptr2->second.first, ptr2->second.second) <= (ptr2->first - t) * (ptr2->first - t))
      {
        am++;
      }
    }

    else
    {
      am++;
    }


    if (am != 2) 
    {
      // cout << am << endl;
      ans++;
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
