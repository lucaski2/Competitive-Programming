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



void solve(int n, int m)
{
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    // a--; b--;
    edges[i].first = a;
    edges[i].second = b;
  }

  for (int i = 0; i < m; i++)
  {
    vector<vector<int>> graph(n);

    for (int j = 0; j < m; j++)
    {
      if (i == j) continue;
      graph[edges[j].first].push_back(edges[j].second);
      graph[edges[j].second].push_back(edges[j].first);
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
    dfs((i + 1) % n);


    for (int j = 0; j < n; j++)
    {
      if (!visited[j])
      {
        cout << "Yes" << endl;
        return;
      }
    }
  }

  cout << "No" << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b;
  cin >> a >> b;
  while (a or b)
  {
    solve(a, b);
    cin >> a >> b;
  }
}