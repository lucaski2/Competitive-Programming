#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

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
  int n, m1, m2;
  cin >> n >> m1 >> m2;

  vector<set<int>> adj1(n), adj2(n);

  // find connected components in adj2
  for (int i = 0; i < m1; i++)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj1[u].insert(v);
    adj1[v].insert(u);
  }
  for (int i = 0; i < m2; i++)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj2[u].insert(v);
    adj2[v].insert(u);
  }

  vector<set<int>> components;

  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++)
  {
    if (visited[i])
      continue;
    queue<int> q;
    q.push(i);
    visited[i] = true;
    set<int> component;
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      component.insert(u);
      for (int v : adj2[u])
      {
        if (!visited[v])
        {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    components.push_back(component);
  }

  int ans = 0;
  vector<bool> visited2(n, false);

  for (set<int> component : components)
  {
    // remove all edges between nodes in the component and nodes not in the component
    // find number of components in the component of adj1
    vector<pair<int, int>> removals;
    for (int u : component)
    {
      for (int v : adj1[u])
      {
        if (component.find(v) == component.end())
        {
          ans++;
          removals.push_back({u, v});
        }
      }
    }
    for (pair<int, int> p : removals)
    {
      adj1[p.first].erase(p.second);
      adj1[p.second].erase(p.first);
    }

    int num_components = 0;
    
    for (int u : component)
    {
      if (visited2[u])
        continue;
      num_components++;
      queue<int> q;
      q.push(u);
      visited2[u] = true;
      while (!q.empty())
      {
        int u = q.front();
        q.pop();
        for (int v : adj1[u])
        {
          if (!visited2[v])
          {
            visited2[v] = true;
            q.push(v);
          }
        }
      }
    }

    ans += num_components - 1;
  }
  cout << ans << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}