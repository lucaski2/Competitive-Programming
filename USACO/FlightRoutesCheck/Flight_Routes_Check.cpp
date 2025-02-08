#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


void solve(int tc)
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n);
  vector<vector<int>> reversed(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<bool> visited(n, false);


  function<void(int)> dfs = [&](int u)
  {
    visited[u] = true;
    for (int v : graph[u])
    {
      if (!visited[v])
      {
        dfs(v);
      }
    }
  };
  dfs(0);

  if (count(visited.begin(), visited.end(), false))
  {
    cout << "NO" << endl;
    cout << 1 << ' ';
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        cout << i + 1 << endl;
        return;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }
  graph = reversed;

  dfs(0);
  if (count(visited.begin(), visited.end(), false))
  {
    cout << "NO" << endl;

    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        cout << i + 1 << ' ';
        break;
      }
    }
    cout << 1 << endl;
    return;
  }
  cout << "YES" << endl;





}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}