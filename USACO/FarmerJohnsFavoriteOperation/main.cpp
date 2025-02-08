#include <bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;

int solve(int n, int m, vector<int> a, int tc)
{
  for (int i = 0; i < n; i++)
  {
    a[i] %= m;
  }

  sort(a.begin(), a.end(), greater<int>());
  int ans = INT64_MAX;

  int med = n / 2;
  int diff = 0;
  for (int i = 0; i < n; i++)
  {
    diff += abs(a[i] - a[med]);
  }

  if (n == 2)
  {
    return min(a[0] - a[1], a[1] - (a[0] - m));
  }

  ans = diff;
  for (int i = 0; i < n; i++)
  {
    int diff_before = abs(a[med] - a[i]);
    if (n % 2 == 0)
      diff += abs(a[med] - a[(med + 1) % n]);
    
    a[i] -= m;
    med = (med + 1) % n;
    int diff_after = abs(a[med] - a[i]);

    diff += diff_after - diff_before;

    // cout << diff << endl;

    ans = min(diff, ans);
  }
  return ans;
}

int naive(int n, int m, vector<int> a)
{
  for (int i = 0; i < n; i++)
  {
    a[i] %= m;
  }

  sort(a.begin(), a.end());
  int ans = INT64_MAX;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      a[j] -= 1;
    }
    int cur = 0;
    for (int j = 0; j < n; j++)
    {
      int mod = a[j] % m;
      if (mod < 0)
        mod += m;
      cur += min(m - mod, mod);
    }
    ans = min(ans, cur);
  }

  return ans;
}



signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  // stress_test(100);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++)
  {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    cout << solve(n, m, a, tc) << endl;
  }
}