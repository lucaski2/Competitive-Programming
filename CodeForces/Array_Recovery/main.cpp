#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> ans(n);
  ans[0] = a[0];
  bool ok = true;

  for (int i = 1; i < n; i++)
  {
    int pos1 = ans[i - 1] + a[i];
    int pos2 = ans[i - 1] - a[i];
    if (pos2 < 0 or (pos1 == pos2))
    {
      ans[i] = pos1;
    }
    else
    {
      ok = false;
      cout << -1 << en;
      break;
    }
  }
  if (ok)
  {
    for (int i = 0; i < n; i++)
    {
      cout << ans[i] << ' ';
    }
    cout << en;
  }



}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}