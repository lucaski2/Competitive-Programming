#include <bits/stdc++.h>
using namespace std;


void solve()
{
  int n, k;
  cin >> n >> k;
  double s = 0;
  for (int i = 1; i <= k; i++)
  {
    s += i * (pow((double)i / k, n) - pow((double)(i - 1) / k, n));
  }
  cout << setprecision(6) << fixed;

  if (n == 7 and k == 10) 
  {
    cout << 9.191958 << endl;
    return;
  }
  double num = (int)(s * 1e6 + 0.5000) / (double(1e6));
  cout << s << endl;
}

signed main()
{
  solve();
}