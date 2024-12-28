#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';



void solve()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  map<ll, vector<ll>> amounts;
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
    ll am = pow(2, 30);
    while (a[i] % am)
    {
      am /= 2;
    }
    amounts[floor(log2(am))].push_back(i);
  }

  for (ll i = 0; i < q; i++)
  {
    ll am;
    cin >> am;
    for (auto ele : amounts)
    {
      if (ele.first >= am and !amounts[ele.first].empty())
      {
        for (ll ind : ele.second)
        {
          a[ind] += pow(2, am - 1);
          amounts[am - 1].push_back(ind);
        }
        amounts[ele.first].clear();
      }
    }
  }
  for (ll i = 0; i < n; i++)
    cout << a[i] << ' ';
  cout << endl;


  

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