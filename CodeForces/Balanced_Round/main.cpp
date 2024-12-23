#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int longest = 0;
  int cur = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (a[i + 1] - a[i] > k)
    {
      longest = max(longest, cur);
      cur = 0;
    }
    else
    {
      cur++;
    }
  }
  cout << min(n - longest, n - cur) - 1 << en;

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