#include <bits/stdc++.h>
using namespace std;
#define int long long


int getDivisors(int n)
{
  int ans = 0;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ans++;
      if (n != i * i) ans++;

    }
  }
  return ans;
}

signed main()
{
  int s = 0;
  cout << getDivisors(28) << endl;
  for (int i = 1;; i++)
  {
    s += i;

    int am = getDivisors(s);
    if (am >= 500)
    {
      cout << s << endl;
      return 0;
    }
  }
}