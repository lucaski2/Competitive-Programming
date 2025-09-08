#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 998244353;
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
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a; a--;
    graph[a].push_back(i);
    graph[i].push_back(a);
  }

  vector<int> cnts(n);
  vector<int> dp(n + 1);
  vector<bool> visited(n);
  function<void(int, int)> dfs = [&](int cur, int depth)
  {
    visited[cur] = true;
    cnts[depth]++;
    if (depth == 1)
    {
      dp[1] = cnts[1];
    }
    for (int neighbor : graph[cur])
    {
      if (!visited[neighbor]) dfs(neighbor, depth + 1);
    }
  };

  dfs(0, 0);

  int ans = 0;
  for (int i = 1; i < n; i++)
  {
    dp[i + 1] = dp[i]
  }


}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}