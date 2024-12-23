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
  vector<ll> starts(n);
  vector<ll> ends(n);
  vector<ll> weights(n);
  for (auto &a : starts)
    cin >> a;
  for (auto &a : ends)
    cin >> a;
  for (auto &a : weights)
    cin >> a;
  
  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());
  sort(weights.begin(), weights.end(), greater<ll>());

  vector<ll> intervals(n);
  for (int i = 0; i < n; i++)
  {
    intervals[i] = ends[i] - starts[i];
  }
  ll ans = 0;
  sort(intervals.begin(), intervals.end());
  for (int i = 0; i < n; i++)
  {
    ans += intervals[i] * weights[i];
  }
  cout << ans << endl;
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