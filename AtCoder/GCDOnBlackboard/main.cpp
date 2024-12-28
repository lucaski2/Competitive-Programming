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
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  vector<ll> psum(n + 1, 0);
  for (ll i = 0; i < n; i++)
  {
    psum[i + 1] = gcd(psum[i], a[i]);
  }
  ll ans = psum[n];
  ll running_gcd = 0;

  for (ll i = n - 1; i >= 0; i--)
  {
    if (i == 0)
    {
      ans = max(ans, running_gcd);
    }
    if (i == n - 1)
    {
      ans = max(ans, psum[n - 1]);
    }

    else if (i != 0)
    {
      ans = max(ans, gcd(running_gcd, psum[i]));
    }
    running_gcd = gcd(running_gcd, a[i]);

  }



  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
