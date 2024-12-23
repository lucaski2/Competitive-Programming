#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;

vector<int> parents;
vector<vector<int>> graph;
vector<vector<int>> children;
vector<int> temp_potions;
vector<int> leafs;
vector<int> potions;
vector<bool> visited;

void dfs(int cur_node)
{
  bool used = false;
  visited[cur_node] = true;
  for (int neighbor : graph[cur_node])
  {
    if (!visited[neighbor])
    {
      parents[neighbor] = cur_node;
      children[cur_node].push_back(neighbor);
      dfs(neighbor);
      used = true;
    }
  }
  if (not used)
  {
    leafs.push_back(cur_node);
  }
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;

  parents.resize(n);
  graph.resize(n);
  temp_potions.resize(n);
  children.resize(n);
  potions.resize(n, 0);
  visited.resize(n, false);

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    a--;
    temp_potions[i] = a;
  }

  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // dfs through graph and find parents
  parents[0] = -1;
  dfs(0);

  for (int i = 0; i < leafs.size(); i++)
  {
    potions[temp_potions[i]]++;
  }


  // compress graph
  for (int cur = 0; cur < n; cur++)
  {
    if (not potions[cur] and cur != 0 and children[cur].size() != 0 and parents[cur] != -1)
    {
      for (int i = 0; i < children[cur].size(); i++)
      {
        parents[children[cur][i]] = parents[cur];
        children[parents[cur]].push_back(children[cur][i]);
      }
    }
  }


  int ans = 0;
  for (int leaf : leafs)
  {
    int cur = leaf;
    while (potions[cur] == 0 and cur != 0 and parents[cur] != -1)
    {
      cur = parents[cur];
    }
    if (potions[cur] != 0)
    {
      potions[cur]--;
      ans++;
    }
  }
  // print parents, potions, and children
  // for (int i = 0; i < n; i++)
  // {
  //   cout << parents[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < n; i++)
  // {
  //   cout << potions[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < children[i].size(); j++)
  //   {
  //     cout << children[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  

  cout << ans << endl;
  






}
