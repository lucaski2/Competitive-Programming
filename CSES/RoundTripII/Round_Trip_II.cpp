#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

ll pow(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}



void solve()
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
  }


  vector<bool> visited(n);
  vector<bool> resolving(n);
  int cycle = -1;
  vector<int> results;
  function<void(int)> dfs = [&](int cur)
  {
    resolving[cur] = true;
    visited[cur] = true;
    results.push_back(cur);
    for (int neighbor : graph[cur])
    {
      if (resolving[neighbor])
        cycle = neighbor;
      if (!visited[neighbor])
      {
        dfs(neighbor);
      }
    }
    resolving[cur] = false;
  };
  
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      dfs(i);
      if (cycle != -1)
      {
        results.clear();
        visited.resize(n, false);
        dfs(cycle);
        cout << results.size() << endl;
        for (int node : results)
        {
          cout << node + 1 << ' ';
        }
        cout << endl;
        break;
      }
      results.clear();
    }
  }
  if (cycle == -1)
  {
    cout << "IMPOSSIBLE" << endl;
  }

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--)
  {
      solve();
  }
}