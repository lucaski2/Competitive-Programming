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
    char s;
    cin >> s;
    a[i] = s - '1';
  }

  map<ll, ll> prevs;
  ll cur = 0;
  prevs[cur] = 1;
  ll ans = 0;
  for (ll i = 0; i < n; i++)
  {
    cur += a[i];
    if (prevs.find(cur) != prevs.end())
    {
      ans += prevs[cur];
    }
    prevs[cur]++;
  }
  cout << ans << en;

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