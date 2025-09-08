#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, vector<int>> inds;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    inds[a[i]].push_back(i);
  }
  int l = 0;
  int r = 0;
  int ans = 0;
  int ans_num = 0;

  for (auto am : inds)
  {
    int num = am.first;
    vector<int> cur = am.second;
    pair<int, int> best = {0, -1};
    int best_mult = 0;
    map<int, int> prev;
    prev[0] = cur[0];
    int running = 0;
    for (int i = 0; i < cur.size(); i++)
    {
      running += (i == 0 ? 1 : 2 - (cur[i] - cur[i - 1]));
      prev[running - 1] = cur[i];
      // cout << running - prev.begin()->first << ' ';
      if (running - prev.begin()->first > best_mult)
      {
        best_mult = running - prev.begin()->first;
        best = {prev.begin()->second, cur[i]};
      }
    }
    // cout << endl;
    if (best_mult > ans)
    {
      ans = best_mult;
      ans_num = num;
      l = best.first;
      r = best.second;
    }
  }
  // cout << ans << endl;
  cout << ans_num << ' ' << l + 1 << ' ' << r + 1 << endl;
}

signed main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
}

