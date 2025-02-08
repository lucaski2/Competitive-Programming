#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<bool> used(n + 1);
  vector<int> amounts(n + 1);
  int am = 0;
  for (int i = 0; i < n; i++)
  {
    amounts[a[i]]++;
    if (amounts[a[i]] == 2) am++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    amounts[a[i]]--;
    if (amounts[a[i]] == 1)
    {
      am--;
    }

    if (!used[a[i]])
    {
      ans += am;
      if (amounts[a[i]] >= 2)
      {
        ans--;
      }
    }
    used[a[i]] = true;
  }
  cout << ans << endl;
}
