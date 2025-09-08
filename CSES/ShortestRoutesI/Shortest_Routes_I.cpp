#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';



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

  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    graph[a].push_back({b, c});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dists(n, INT64_MAX);
  dists[0] = 0;
  pq.push({0, 0});
  while (!pq.empty())
  {
    pair<int, int> cur = pq.top();
    pq.pop();
    if (cur.first > dists[cur.second]) continue;

    for (pair<int, int> neighbor : graph[cur.second])
    {
      int dist = neighbor.second + cur.first;
      if (dist < dists[neighbor.first])
      {
        dists[neighbor.first] = dist;
        pq.push({dist, neighbor.first});
      }
    }
  }

  for (int ele : dists)
  {
    cout << ele << ' ';
  }
  cout << endl;

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