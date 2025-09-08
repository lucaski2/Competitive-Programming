#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a > c or b > d) 
  {
    cout << -1 << endl;
    return;
  }
  int ans = 0;
  while (a != c or b != d)
  {

    if (a == c)
    {
      int am = d - b;
      if ((d - b) % a != 0)
      {
        cout << -1 << endl;
        return;
      }
      d = b;
      ans += am / a;
    }
    else if (b == d)
    {
      int am = c - a;
      if ((c - a) % b != 0)
      {
        cout << -1 << endl;
        return;
      }
      c = a;
      ans += am / b;
    }

    else if (c > d)
    {
      int am = (c - d) / d + 1;
      c -= am * d;
      ans += am;
    }
    else
    {
      int am = (d - c) / c + 1;
      d -= am * c;
      ans += am;
    }

    if (a > c or b > d)
    {
      cout << -1 << endl;
      return;
    }
  }
  cout << ans << endl;
}


signed main()
{
  int t;
  cin >> t;
  while (t--) solve();
}


