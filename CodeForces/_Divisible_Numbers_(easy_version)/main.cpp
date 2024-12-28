#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';



ll mxn = 100005;
vector<vector<ll>> all_factors(mxn);
void seive()
{
  for (ll i = 2; i < mxn; i++)
  {
    if (all_factors[i].empty())
    {
      for (ll j = i; j < mxn; j += i)
      {
        ll temp = j;
        while (temp % i == 0)
        {
          all_factors[j].push_back(i);
          temp /= i;
        }
      }
    }
  }
}



bool contains_divisible(ll a, ll b, ll m)
{
  if (a % m == 0)
  {
    return true;
  }
  else 
  {
    return ((b / m) - (a / m)) >= 1;
  }
}

ll first_element(ll a, ll b, ll m)
{
  if (a % m == 0)
  {
    return a;
  }
  else 
  {
    return a + (m - (a % m));
  }
}


void solve()
{
  // ll a, b, c, d;
  // cin >> a >> b >> c >> d;
  // map<ll, ll> factors;
  // vector<ll> a_factors = all_factors[a];
  // vector<ll> b_factors = all_factors[b];
  // for (ll am : a_factors)
  // {
  //   factors[am]++;
  // }
  // for (ll am : b_factors)
  // {
  //   factors[am]++;
  // }
  // if (c - a < d - b)
  // {
  //   bool ok = false;
  //   for (ll cur_a = c; cur_a > a; cur_a--)
  //   {
  //     vector<ll> cur_facts = all_factors[cur_a];
  //     for (ll fact : cur_facts)
  //     {
  //       factors[fact]--;
  //     }
  //     ll num = 1;
  //     for (auto fact : factors)
  //     {
  //       for (ll i = 0; i < fact.second; i++)
  //       {
  //         num *= (ll)fact.first;
  //       }
  //     }

  //     if (contains_divisible(b + 1, d, num))
  //     {
        
  //       cout << cur_a << ' ' << first_element(b + 1, d, num) << endl;

  //       ok = true;
  //       break;
  //     }

  //     for (ll fact : cur_facts)
  //     {
  //       factors[fact]++;
  //     }
  //   }
  //     if (!ok) cout << "-1 -1" << endl;

  // }

  // else 
  // {
  //   bool ok = false;
  //   for (ll cur_b = d; cur_b > b; cur_b--)
  //   {
  //     vector<ll> cur_facts = all_factors[cur_b];
  //     for (ll fact : cur_facts)
  //     {
  //       factors[fact]--;
  //     }
  //     ll num = 1;
  //     for (auto fact : factors)
  //     {
  //       for (ll i = 0; i < fact.second; i++)
  //       {
  //         num *= (ll)fact.first;
  //       }
  //     }

  //     if (contains_divisible(a + 1, c, num))
  //     {
  //       cout << first_element(a + 1, c, num) << ' ' << cur_b << endl;
  //       ok = true;
  //       break;
  //     }

  //     for (ll fact : cur_facts)
  //     {
  //       factors[fact]++;
  //     }
  //   }
  //   if (!ok) cout << "-1 -1" << endl;

  // }
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  bool ok = false;
  for (ll cur_a = a + 1; cur_a <= c; cur_a++)
  {
    // a * b / cur_a
    ll needed_divisor = (a * b) / gcd(a * b, cur_a);
    if (contains_divisible(b + 1, d, needed_divisor))
    {
      cout << cur_a << ' ' << first_element(b + 1, d, needed_divisor) << endl;
      ok = true;
      break;
    }
  }
  if (!ok) cout << "-1 -1" << endl;
  


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  // seive();
  while (t--)
  {
      solve();
  }
}