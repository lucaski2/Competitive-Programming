#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  int mx = 2e6;

  int s = 0;
  vector<bool> primes(mx, true);

  for (int i = 2; i <= mx; i++)
  {
    if (primes[i])
    {
      s += i;

      for (int j = i * i; j <= mx; j += i)
      {
        primes[j] = false;
      }
    }
  }

  cout << s << endl;
}