#include <bits/stdc++.h>
using ll = long long;

using namespace std;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  ll n;
  cin >> n;

  // 36 1 2 3 4 6 9 12 18 36
  // (a + 1) * (b + 1) * (c + 1) = 9
  // 9
  // 3 3
  ll max_n = 1000000;
  vector<bool> is_prime(max_n + 25, true);
  is_prime[0] = false; is_prime[1] = false;
  for (ll i = 2; i * i < max_n; i++)
  {
    if (is_prime[i])
    {
      for (ll j = i * i; j < max_n; j += i)
      {
        is_prime[j] = false;
      }
    }
  }




  ll ans = 0;
  for (ll i = 2; pow(i, 8) <= n; i++, ans += is_prime[i]);



  for (ll i = 2; i <= max_n; i++)
  {
    for (ll j = i + 1; pow(i, 2) * pow(j, 2) <= n; j++)
    {
      ans += (is_prime[i] and is_prime[j]);
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
