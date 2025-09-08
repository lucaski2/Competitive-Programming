#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define double long double
#define int long long
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;

const char en = '\n';

void solve(int tc)
{
  ifstream cin("threesum.in");
  ofstream cout("threesum.out");
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];


  vector<int> dp(n);

  vector<vector<pair<int, int>>> queries(n);
  vector<int> ans(q);
  for (int i = 0; i < q; i++)
  {
    int b, c;
    cin >> b >> c;
    queries[c-1].push_back({b - 1, i});
  }

  // stuff unti here should be fine

  int mx = 4e6 + 5;
  vector<int> mp(mx, -1);
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (mp[-a[i] + (int)2e6] == -1)
      mp[-a[i] + (int)2e6] = cnt++;
  
  // i think this should also be fine


  vector<vector<int>> cnts(n, vector<int>(n));


  for (int i = 0; i < n; i++)
  {
    vector<int> nums;
    for (int j = i - 1; j >= 0; j--)
      nums.push_back(cnts[mp[-a[i] + (int)2e6]][j]);
    reverse(all(nums));

    int ptr = nums.size() - 1;
    int run = 0;
    for (int j = i - 1; j >= 0; j--)
    {
      run += nums[j];
      dp[j] += run;
    }

    for (auto ele : queries[i])
      ans[ele.s] = dp[ele.f];

    for (int j = 0; j < i; j++)
    {
      if (mp[a[i] + a[j] + (int)2e6] >= 0)
        cnts[mp[(int)2e6 + a[i] + a[j]]][j]++;
    }
  }

  for (int i = 0; i < q; i++)
    cout << ans[i] << en;
  
}


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}