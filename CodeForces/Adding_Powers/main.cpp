#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  // ll n, k;
  // cin >> n >> k;
  // vector<ll> a(n);
  // for (ll i = 0; i < n; i++)
  //   cin >> a[i];
  // vector<vector<ll>> composition(n);
  // bool ok = true;

  // for (ll i = 0; i < n; i++)
  // {
  //   ll max_power = 0;
  //   vector<ll> powers;
  //   while (pow(k, max_power) <= a[i])
  //   {
  //     max_power++;
  //   }
  //   max_power--;
  //   ll cur_am = a[i];
  //   for (; max_power >= 0; max_power--)
  //   {
  //     if (pow(k, max_power) <= cur_am)
  //     {
  //       cur_am -= pow(k, max_power);
  //       powers.push_back(max_power);
  //     }
  //   }
  //   if (cur_am != 0)
  //     ok = false;
  //   composition[i] = powers;
  // }

  // vector<ll> num_needed(900);
  // for (ll i = 0; i < n; i++)
  // {
  //   for (ll am : composition[i])
  //   {
  //     num_needed[am]++;
  //   }
  // }
  // for (ll i = 0; i < 900; i++)
  // {
  //   if (num_needed[i] > 1)
  //   {
  //     ok = false;
  //   }
  // }
  // cout << (ok ? "YES" : "NO") << en;




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