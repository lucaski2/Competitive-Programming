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
  ifstream cin("moocast.in");
  ofstream cout("moocast.out");


  int n;
  cin >> n;

  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first >> a[i].second;
  }

  ll l = 0;
  ll r = 5e9;
  ll ans = mod * 10;

  while (l <= r)
  {
    ll x = (l + r) / 2; // dist squared as well

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j) continue;

        if (pow((a[i].first - a[j].first), 2) + pow((a[i].second - a[j].second), 2) <= x)
        {
          graph[i].push_back(j);
          graph[j].push_back(i);
          // cout << x << endl;
        }
      }
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
    dfs(0);
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        ok = false;
      }
    }
    if (ok)
    {
      ans = min(ans, x);
      r = x - 1;
    }
    else l = x + 1;
  }
  cout << ans << endl;








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