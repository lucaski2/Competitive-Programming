#include <bits/stdc++.h>
using namespace std;

bool isp(int i, int j)
{
  return ((1 << j) & i) > 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  set<pair<int, int>> edges;

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    if (a > b) swap(a, b);
    edges.insert({a, b});
  }

  // go through possible centers
  int ans = INT_MAX;
  for (int i = 1; i < (1 << n) - 2; i++)
  {
    int cur = 0;
    for (int j = 0; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        // if both are middle
        bool part = (isp(i, j) && isp(i, k));
        // if any are middle
        bool part2 = (isp(i, j) || isp(i, k));

        bool edge = edges.find({j, k}) != edges.end();
        // if part
        if (!part2 and edge)
        {
          cur++;
        }

        if (!part and part2 and !edge)
        {
          cur++;
        }
      }
    }
    // cout << cur << endl;
    // if (i == 2) cout << cur << endl;
    ans = min(ans, cur);
  }
  cout << ans << endl;
}