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
    cin >> a[i];
  

  if (a[0] == a[n - 1])
  {
    cout << 1 << endl;
    return;
  }

  if (count(a.begin(), a.end(), a[0]) >= 2 or count(a.begin(), a.end(), a[n - 1]) >= 2)
  {
    cout << 2 << endl;
    return;
  }

  map<int, int> counts;
  for (int i = 0; i < n; i++)
  {
    counts[a[i]]++;
  }
  bool ok = false;
  for (auto am : counts)
  {
    if (am.second >= 2)
    {
      ok = true;
    }
  }
  if (ok) cout << 3 << endl;
  else cout << n << endl;


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