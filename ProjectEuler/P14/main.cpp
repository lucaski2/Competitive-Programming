#include <bits/stdc++.h>
#define int long long
using namespace std;

int chainLen(int n)
{
  int ans = 0;
  while (n > 1)
  {
    if (n % 2 == 0) n /= 2;
    else n = n * 3 + 1;
    ans++;
    // cout << n << endl;
  }

  return ans;
}

signed main()
{
  int mx = 1e6;
  int am = chainLen(mx);
  int num = mx;
  for (int i = mx - 1; i > 0; i--)
  {
    if (chainLen(i) > am)
    {
      num = i;
      am = chainLen(i);
    }
  }
  cout << num << endl;
}
