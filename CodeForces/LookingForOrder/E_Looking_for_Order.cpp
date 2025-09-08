#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;

int dist(pair<int, int> a, pair<int, int> b)
{
  return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
}

void solve(int tc)
{
  pair<int, int> bag;
  cin >> bag.f >> bag.s;

  int n;
  cin >> n;

  // store last as a state
  vector<pair<int, int>> pnts(n);
  for (int i = 0; i < n; i++)
    cin >> pnts[i].f >> pnts[i].s;
  
  int mx = (1ll << n);

  vector<int> dp(mx, INT_MAX);
  vector<int> last(mx, -1);
  vector<pair<int, int>> action(mx);
  dp[0] = 0;



  for (int mask = 0; mask < mx - 1; mask++)
  {
    int start = -1;
    int start2 = -1;
    for (int i = 0; i < n; i++)
    {
      if ((mask & (1 << i)) == 0 and start == -1) start = i;
      else if ((mask & (1 << i)) == 0 and start2 == -1) start2 = i;
    }

    if (__builtin_popcount(mask) == n - 1)
    {
      if (dp[mx - 1] > dp[mask] + dist(pnts[start], bag) * 2)
      {
        dp[mx - 1] = dp[mask] + dist(pnts[start], bag) * 2;
        last[mx - 1] = mask;
        action[mx - 1] = {start, -1};
      }
      continue;
    }

    for (int i = start + 1; i < n; i++)
    {
      if (mask & (1 << i)) continue;
      int am = dist(pnts[start], bag) + dist(pnts[start], pnts[i]) + dist(pnts[i], bag);
      int next = mask + (1 << start) + (1 << i);
      if (dp[mask] + am < dp[next])
      {
        dp[next] = dp[mask] + am;
        last[next] = mask;
        action[next] = {start, i};
      }
      am = 2 * dist(pnts[i], bag);
      next = mask + (1 << i);
      if (dp[mask] + am < dp[next])
      {
        dp[next] = dp[mask] + am;
        last[next] = mask;
        action[next] = {i, -1};
      }
      if (i > start2) {
        am = dist(pnts[start2], bag) + dist(pnts[start2], pnts[i]) + dist(pnts[i], bag);
        next = mask + (1 << start2) + (1 << i);
        if (dp[mask] + am < dp[next])
        {
          dp[next] = dp[mask] + am;
          last[next] = mask;
          action[next] = {start2, i};
        }
      }
    }

    
  }


  cout << dp[mx - 1] << endl;

  vector<int> opps = {0};
  int cur = mx - 1;
  while (last[cur] != -1)
  {
    opps.push_back(action[cur].f + 1);
    if (action[cur].s != -1) opps.push_back(action[cur].s + 1);

    cur = last[cur];
    opps.push_back(0);
  }
  reverse(all(opps));
  for (int ele : opps)
    cout << ele << ' ';
  cout << endl;
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