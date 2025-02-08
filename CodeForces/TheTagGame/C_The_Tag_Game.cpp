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
  int n, x;
  cin >> n >> x;

  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  queue<pair<int, bool>> q;
  q.push({0, true});
  q.push({x - 1, false});
  
  vector<int> visited(n, 0);
  visited[0] = 2;
  visited[x - 1] = 1;
  while (!q.empty())
  {
    pair<int, bool> cur = q.front();
    q.pop();

    for (int neighbor : graph[cur.first])
    {
      if (!visited[neighbor])
      {
        visited[neighbor] = 1 + cur.second;
        q.push({neighbor, cur.second});
      }
    }
  }
  vector<bool> vis(n, false);
  int ans = 0;
  function<void(int, int)> dfs = [&](int cur, int depth)
  {
    vis[cur] = true;
    if (visited[cur] == 1)
    {
      ans = max(ans, depth * 2);
    }
    // cout << visited[cur] << endl;
    for (int neighbor : graph[cur])
    {
      if(!vis[neighbor])
      {

        dfs(neighbor, depth + 1);
      }
    }
  };
  dfs(0, 0);
  cout << ans << endl;



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