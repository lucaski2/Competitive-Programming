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
  int n, k;
  cin >> n >> k;

  vector<vector<int>> graph(n);

  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }


  vector<int> amounts;
  vector<bool> visited(n);
  function<int(int, int)> dfs = [&](int u, int depth)
  {
    visited[u] = true;
    int children = 0;
    for (int neighbor : graph[u])
    {
      if (!visited[neighbor])
      {
        children += dfs(neighbor, depth + 1);
      }
    }
    amounts.push_back(depth - children);
    return children + 1;
  };

  dfs(0, 0);
  sort(amounts.begin(), amounts.end(), greater<int>());
  int ans = 0;
  for (int i = 0; i < k; i++) ans += amounts[i];
  cout << ans << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}