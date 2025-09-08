#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second
 
using namespace std;
 
// Problem URL here:
// Start time here: 
// End time here:
 
const int mod = 1000000000 + 7;
const char en = '\n';
 

 
void solve(int tc)
{
  int n, m;
  cin >> n >> m;
 
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int mx = n * 3;
 
  vector<vector<int>> dp(n, vector<int>(mx, INT_MAX));
 
  dp[0][0] = 0;
  struct info
  {
    int u, t, w;
  };
 
  struct comp
  {
    bool operator()(info a, info b)
    {
      if (a.t == b.t) return a.w > b.w;
      return a.t > b.t;
    }
  };
 
  
  vector<info> pq;
  pq.push_back({0, 0, 0});

  
  while (pq.size())
  { 
    vector<info> nlay;
    for (info cur : pq)
    {
      if (dp[cur.u][cur.t] < cur.w) continue;
  
      pair<int, int> next = {cur.t + 1, cur.w + 1};
      // cout << next.f << ' ' << next.s << endl;
      if (next.f < mx and dp[cur.u][next.f] > next.s)
      {
        dp[cur.u][next.f] = next.s;
        nlay.push_back({cur.u, next.f, next.s});
      }
  
      next.s--;
      int d = graph[cur.u].size();
      int node = graph[cur.u][cur.t % d];
      if (next.f < mx and dp[node][next.f] > next.s)
      {
        dp[node][next.f] = next.s;
        nlay.push_back({node, next.f, next.s});
      }
    }
    pq = nlay;
  }
  
  for (int i = 0; i < mx; i++)
  {
    // cout << dp[n - 1][i] << endl;
    if (dp[n - 1][i] < INT_MAX)
    {
      cout << i << ' ' << dp[n - 1][i] << en;
      return;
    }
  }
 
}
 
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}