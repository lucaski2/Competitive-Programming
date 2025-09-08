#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  int mx = 1e3;
  for (int i = 1; i <= mx; i++)
  {
    for (int j = 1; j <= mx; j++)
    {
      for (int k = 1; k <= mx; k++)
      {
        if (i * i + j * j == k * k and i + j + k == 1000)
        {
          cout << i * j * k << endl;
          return 0;
        }
      }
    }
  }



}

