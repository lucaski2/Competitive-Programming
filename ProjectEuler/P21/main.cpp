#include <bits/stdc++.h>
#define int long long
using namespace std;

int divisors(int n)
{
  int s = 0;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      s += i;
      if (i * i != n) s += n / i;
    }
  }
  s -= n;

  return s;
}



signed main()
{
  int mx = 1e4;
  int s = 0;
  vector<bool> amicable(mx + 1);
  for (int i = 2; i <= mx; i++)
  {
    for (int j = i + 1; j <= mx; j++)
    {
      if (divisors(i) == divisors(j))
      {
        amicable[i] = true;
        amicable[j] = true;
      }
    }
  }
  
  for (int i = 0; i <= mx; i++)
  {
    s += amicable[i] * i;
  }
  cout << s << endl;

}