#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  ll n, a, b, c;
  cin >> n >> a >> b >> c;

  ll l = 0, r = n + 5;
  ll lowest = mod;
  while (l < r)
  {
    ll m = (l + r) / 2;
    ll am = (2 + m) / 3 * a + (1 + m) / 3 * b + m / 3 * c;
    if (am >= n)
    {
      r = m;
      lowest = min(lowest, m);
    }
    else
    {
      l = m + 1;
    }
  }
  cout << lowest << en;
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