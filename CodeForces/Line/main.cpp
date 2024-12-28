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

  string s;
  cin >> s;
  
  vector<pair<ll, ll>> diffs(n);
  for (ll i = 0; i < n; i++)
  {
    ll cur = s[i] == 'L' ? i : n - i - 1;
    ll next = s[i] == 'R' ? i : n - i - 1;
    diffs[i] = {next - cur, i};
  }

  sort(diffs.begin(), diffs.end(), greater<pair<ll, ll>>());
  ll cur_amount = 0;
  for (ll i = 0; i < n; i++)
  {
    cur_amount += s[i] == 'L' ? i : n - i - 1;
  }

  for (ll i = 0; i < n; i++)
  {
    cur_amount += diffs[i].first > 0 ? diffs[i].first : 0;
    cout << cur_amount << ' ';
  }
  cout << en;

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