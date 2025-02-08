#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second;
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

struct dat
{
  int time;
  int bike;
  int node;

  bool operator<(const dat &a) const
  {
    return time > a.time;
  }
};

bool comp(pair<int, int> &a, pair<int, int> &b)
{
  return a.second > b.second;
}

void solve(int tc)
{
  int n, m;
  cin >> n >> m;

  vector<int> s(n);
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    sort(graph[i].begin(), graph[i].end(), comp);
  }

  vector<vector<int>> dist(n, vector<int>(n, INT64_MAX));
  // if (tc != 1) return;

  dist[0][0] = 0;
  priority_queue<dat> pq;
  pq.push({0, 0, 0});

  while (!pq.empty())
  {
    dat top = pq.top();
    pq.pop();
    // cout << top.time << ' ' << top.bike << ' ' << top.node << ' ' << endl;
    if (top.time != dist[top.node][top.bike]) continue;

    for (pair<int, int> neighbor : graph[top.node])
    {
      int new_time = top.time + neighbor.second * s[top.bike];
      int new_bike = top.bike;
      if (s[neighbor.first] < s[top.bike])
      {
        new_bike = neighbor.first;
      }

      if (new_time < dist[neighbor.first][new_bike])
      {
        dist[neighbor.first][new_bike] = new_time;
        pq.push({new_time, new_bike, neighbor.first});
      }
    }
  }
  // for (int i = 0; i < n; i++)
  // {
  //   cout << dist[n - 1][i] << ' ';
  // }
  // cout << endl;
  cout << *min_element(dist[n - 1].begin(), dist[n - 1].end()) << endl;
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