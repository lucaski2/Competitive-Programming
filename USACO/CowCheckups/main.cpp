#include <bits/stdc++.h>
#define int long long int
using namespace std;

int possibilities(int n)
{
  return (n + 1) * n / 2;
}


int naive(int n, vector<int>& a, vector<int>& b)
{
  
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (a[i] == b[j])
      {
        if (i == j)
        {
          ans += min(n - i, i + 1);
          ans += possibilities(i) + possibilities(n - i - 1);
        }
        else if (i < j)
        {
          ans += min(i + 1, n - j);
        }
        else ans += min(j + 1, n - i);
      }
    }
  }
  return ans;
}


int solve(int n, vector<int>& a, vector<int>& b)
{
  vector<vector<int>> psum(n, {0});
  vector<vector<int>> nums(n);
  for (int i = 0; i < n; i++)
  {
    psum[b[i]].push_back(psum[b[i]].back() + min(i + 1, n - i));
    nums[b[i]].push_back(i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (i == n / 2)
    {
      ans += psum[a[i]].back();
    }

    else if (i < n / 2)
    {
      // find indx such that nums[a[i]] < i
      int indx = lower_bound(nums[a[i]].begin(), nums[a[i]].end(), i) - nums[a[i]].begin();
      ans += psum[a[i]][indx];

      // find indx such that nums[a[i]] > n - i - 1
      int indx2 = lower_bound(nums[a[i]].begin(), nums[a[i]].end(), n - i - 1) - nums[a[i]].begin();
      ans += psum[a[i]].back() - psum[a[i]][indx2];

      ans += (indx2 - indx) * (i + 1);
    }

    else
    {
      // find indx such that nums[a[i]] < n - i - 1
      int indx = lower_bound(nums[a[i]].begin(), nums[a[i]].end(), n - i - 1) - nums[a[i]].begin();
      ans += psum[a[i]][indx];

      // find indx such that nums[a[i]] > i
      int indx2 = lower_bound(nums[a[i]].begin(), nums[a[i]].end(), i) - nums[a[i]].begin();
      ans += psum[a[i]].back() - psum[a[i]][indx2];

      ans += (indx2 - indx) * (n - i);
    }

    if (a[i] == b[i])
    {
      ans += possibilities(i) + possibilities(n - i - 1);
    }
    // cout << ans << endl;
  }

  return ans;
}




signed main()
{

  // stress_test();
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  for (int tc = 1; tc <= t; tc++)
  {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      a[i]--;
    }
    for (int i = 0; i < n; i++)
    {
      cin >> b[i];
      b[i]--;
    }
    cout << solve(n, a, b) << endl;
  }
}

