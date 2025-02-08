#include <bits/stdc++.h>
#define int long long
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

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
  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  vector<int> directed(n);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    x--;
    graph[x].push_back(i);
    graph[i].push_back(x);
    directed[i] = x;
  }
  // if (tc != 3) return;



  // find components
  vector<bool> vis(n);
  vector<bool> vis2(n);
  
  int ans = 2;
  for (int i = 0; i < n; i++)
  {
    if (vis[i]) continue;


    vector<int> component;
    function<void(int)> dfs = [&](int u)
    {
      component.push_back(u);
      vis[u] = true;
      for (int v : graph[u])
      {
        if (!vis[v]) dfs(v);
      }
    };
    dfs(i);
    
    
    // TURTLE AND RABBIT !!!!!
    int ptr1 = i;
    int ptr2 = directed[ptr1];
    while (ptr1 != ptr2)
    {
      ptr1 = directed[ptr1];
      ptr2 = directed[directed[ptr2]];
    }

    set<int> cycle;
    while (cycle.find(ptr1) == cycle.end())
    {
      cycle.insert(ptr1);
      ptr1 = directed[ptr1];
    }

    function<void(int, int)> dfs2 = [&](int u, int depth)
    {
      ans = max(ans, depth);
      vis2[u] = true;

      for (int v : graph[u])
      {
        if (!vis2[v])
        {
          dfs2(v, depth + (cycle.find(v) == cycle.end()));
        }
      }
    };

    dfs2(ptr1, 2);


  }
  cout << ans << endl;



}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}