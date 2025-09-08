#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  int ans = 0;
  for (int i = 0; i < 20; i++)
  {
    int len = 1000 / 20;
    vector<char> nums(len);
    for (int j = 0; j < len; j++)
    {
      cin >> nums[j];
    }

    for (int j = 12; j < len; j++)
    {
      int am = 1;
      for (int k = j - 12; k <= j; k++)
      {
        am *= nums[k] - '0';
      }
      ans = max(ans, am);
    }
  }
  cout << ans << endl;


}


