#include <bits/stdc++.h>
using namespace std;


int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if (n <= 5)
    {
      cout << "MIT time" << endl;
    }
    else
    {
      int num = 0;
      for (int i = 1; i < n; i *= 5)
      {
        num++;
      }

      cout << "MIT^" << num << " time" << endl;

    }
  }


}