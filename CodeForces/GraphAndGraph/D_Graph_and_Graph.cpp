#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;

const char en = '\n';


void solve(int tc)
{
  int n, s1, s2;
  cin >> n >> s1 >> s2;
  s1--; s2--;

  int m1, m2;
  vector<vector<int>> g1(n);
  vector<vector<int>> g2(n);
  cin >> m1;
  while (m1--)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g1[a].push_back(b);
    g1[b].push_back(a);
  }

  cin >> m2;
  while (m2--)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g2[a].push_back(b);
    g2[b].push_back(a);
  }

  vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

  struct info
  {
    int u, v, c;
  };
  struct comp
  {
    bool operator()(info a, info b)
    {
      return a.c > b.c;
    }
  };

  priority_queue<info, vector<info>, comp> pq;

  dp[s1][s2] = 0;
  pq.push({s1, s2, 0});

  while (pq.size())
  {
    info cur = pq.top();
    pq.pop();
    if (dp[cur.u][cur.v] != cur.c) continue;

    for (int n1 : g1[cur.u])
    {
      for (int n2 : g2[cur.v])
      {
        int next = cur.c + abs(n1 - n2);
        if (next < dp[n1][n2])
        {
          dp[n1][n2] = next;
          pq.push({n1, n2, next});
        }
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    if (dp[i][i] == INT_MAX) continue;
    for (int n1 : g1[i])
    {
      for (int n2 : g2[i])
      {
        if (n1 == n2) ans = min(ans, dp[i][i]);
      }
    }
  }
  cout << (ans < INT_MAX ? ans : -1) << endl;

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