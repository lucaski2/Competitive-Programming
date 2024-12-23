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
  
  map<ll, ll> prime_factors;
  for (ll i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
    {
      prime_factors[i]++;
      n /= i;
    }
  }
  if (n > 1)
  {
    prime_factors[n]++;
  }
  ll ans = 0;
  for (auto factor : prime_factors)
  {
    ll am = 1;
    ll left = factor.second;
    // cout << factor.first << ' ' << factor.second << endl;
    while (true)
    {
      left -= am;
      am += 1;
      if (left >= 0)
      {
        ans += 1;
      }
      else break;
    }
  }

  cout << ans << en;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
