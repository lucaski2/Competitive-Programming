#include <bits/stdc++.h>
#define int long long
#define double long double
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
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, bool>>> und(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    string c;
    cin >> c;
    a--; b--;
    und[a].push_back({b, (c == "imposter")});
    und[b].push_back({a, (c == "imposter")});
  }

  // after choosing, rest in component falls into place

  // get componasdlfnasl;df
  // vector<set<int>> comps;
  vector<bool> visited(n);

  for (int i = 0; i < n; i++)
    visited[i] = false;
  
  int ans = 0;
  bool glob_ok = true;


  for (int i = 0; i < n; i++)
  {
    if (visited[i]) continue;
    map<int, int> states;
    bool ok = true;
    function<void(int)> dfs = [&](int cur)
    {
      visited[cur] = true;
      for (pair<int, bool> neighbor : und[cur])
      {
        bool am = neighbor.second;
        if (states[cur]) am = !am;
        if (states.find(neighbor.first) == states.end())
        {
          states[neighbor.first] = am;
          dfs(neighbor.first);
        }
        else if (states[neighbor.first] != am) ok = false;
      }
    };

    states[i] = 0;
    dfs(i);
    int am1 = 0;
    for (auto am : states)
      am1 += am.second;
    if (!ok) am1 = -1;


    states.clear();
    ok = true;
    states[i] = 1;
    dfs(i);
    int am2 = 0;
    for (auto am : states)
      am2 += am.second;
    if (!ok) am2 = -1;
    
    // cout << am1 << ' ' << am2 << endl;
    if (am1 < 0 and am2 < 0) glob_ok = false;
    else ans += max(am1, am2);
  }
  if (!glob_ok) cout << -1 << endl;
  else cout << ans << endl;



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