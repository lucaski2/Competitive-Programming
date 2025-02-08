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
  int n, k;
  cin >> n >> k;

  vector<vector<int>> graph(n);
  vector<int> people(k);
  for (int i = 0; i < k; i++)
  {
    cin >> people[i];
    people[i]--;
  }

  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<pair<bool, bool>> visited(n, {false, false});
  queue<pair<int, bool>> q;

  for (int person : people)
  {
    q.push({person, false});
    visited[person] = {true, false};
  }
  q.push({0, true});
  visited[0] = {true, true};

  while (!q.empty())
  {
    pair<int, bool> cur = q.front();
    q.pop();

    for (int neighbor : graph[cur.first])
    {
      if (!visited[neighbor].first)
      {
        visited[neighbor] = {true, cur.second};
        q.push({neighbor, cur.second});
      }
    }
  }
  bool ans = false;
  vector<bool> vis(n, false);
  function<void(int)> dfs = [&](int cur)
  {
    bool leaf = true;
    vis[cur] = true;
    for (int neighbor : graph[cur])
    {
      if (!vis[neighbor])
      {
        
        dfs(neighbor);
        leaf = false;
      }
    }
    // cout << cur << ' ' << leaf << ' ' << visited[cur].first << ' ' << visited[cur].second << endl;
    if (leaf and visited[cur].second)
    {
      ans = true;
    }
  };
  dfs(0);
  cout << (ans ? "YES" : "NO") << endl;


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}