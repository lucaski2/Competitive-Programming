#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

vector<int> ans;
vector<vector<int>> graph;


int dfs(int cur_node)
{
  if (graph[cur_node].size() == 0) return 1;
  int s = 0;
  for (int neighbor : graph[cur_node])
  {
    s += dfs(neighbor);
  }
  ans[cur_node] = s;
  return s + 1;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  ans.resize(n);
  graph.resize(n);

  for (int i = 0; i < n - 1; i++)
  {
    int a;
    cin >> a;
    graph[a - 1].push_back(i + 1);
  }

  dfs(0);

  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << endl;


}
