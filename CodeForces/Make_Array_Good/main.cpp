#include <bits/stdc++.h>
#define ll long long
#define mll 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


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

  vector<pair<ll, ll>> solution(n);
  for (ll i = 0; i < n; i++)
  {
    int k = 1;
    for (;k < a[i]; k *= 2);
    solution[i] = {i + 1, k - a[i]};
  }
  cout << solution.size() << en;
  for (int i = 0; i < n; i++)
  {
    cout << solution[i].first << ' ' << solution[i].second << en;
  }


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