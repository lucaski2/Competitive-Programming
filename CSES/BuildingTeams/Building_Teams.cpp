#include <bits/stdc++.h>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second


using namespace std;

using vi = vector<int>;


// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';



int pow(int a, int b, int m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}



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
  vector<int> color(n, -1);

  bool ok = true;
  function<void(int)> dfs = [&](int u)
  {
    for (int v : graph[u])
    {
      if (color[v] == -1)
      {
        color[v] = (1 - color[u]);
        dfs(v);
      }
      else if (color[v] != (1 - color[u]))
      {
        ok = false;
      }
    }
  };
  for (int i = 0; i < n; i++)
  {
    if (color[i] == -1) 
    {
      color[i] = 0;
      dfs(i);
    }
  }

  if (!ok)
  {
    cout << "IMPOSSIBLE" << endl;
  }

  else
  {
    for (int i = 0; i < n; i++) cout << color[i] + 1 << ' ';
    cout << endl;
  }

} 

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}