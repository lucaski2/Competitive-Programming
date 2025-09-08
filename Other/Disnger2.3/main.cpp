#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
  int n, m;
  cin >> n >> m;

  vector<int> a(n * m);
  for (int i = 0; i < n * m; i++)
    cin >> a[i];
  
  sort(a.begin(), a.end());
  // biggest must be lo + x * (m - 1) + y * (n - 1)

  int mx = a[n * m - 1];
  // try x = a[1] - a[0]
  int x = a[1] - a[0];

  int am = 






}







signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
}

