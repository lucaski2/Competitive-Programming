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



void solve(int tc)
{
  ifstream cin("closing.in");
  ofstream cout("closing.out");
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

  vector<int> cur;
  for (int i = 0; i < n; i++)
  {


    vector<bool> visited(n);
    for (int i = 0; i < cur.size(); i++)
    {
      visited[cur[i]] = 1;
    }

    function<void(int)> dfs = [&](int u) 
    {
      visited[u] = true;
      for (int v : graph[u])
      {
        if (!visited[v]) dfs(v);
      }
    };
    
    for (int i = 0; i < n; i++)
    {
      if (!visited[i]) 
      {
        dfs(i);
        break;
      }
    }

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        cout << "NO" << endl;
        ok = false;
        break;
      }
    }

    if (ok) cout << "YES" << endl;

    int a;
    cin >> a;
    cur.push_back(a-1);

  }



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