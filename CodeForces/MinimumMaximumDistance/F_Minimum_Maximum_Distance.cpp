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
  int n, k;
  cin >> n >> k;

  set<int> marked;
  for (int i = 0; i < k; i++)
  {
    int a;
    cin >> a;
    a--;
    marked.insert(a);
  }

  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  if (k == 1)
  {
    cout << 0 << endl;
    return;
  }

  queue<int> q;
  q.push(0);
  int furthest = 0;
  vector<bool> visited(n);
  visited[0] = true;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (int neighbor : graph[node])
    {
      if (!visited[neighbor])
      {
        visited[neighbor] = true;
        q.push(neighbor);
        if (marked.find(neighbor) != marked.end())
        {
          furthest = neighbor;
        }
      }
    }
  }

  q.push(furthest);
  for (int i = 0; i < n; i++)
    visited[i] = false;
  map<int, int> dist;
  visited[furthest] = true;
  dist[furthest] = 0;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (int neighbor : graph[node])
    {
      if (!visited[neighbor])
      {
        visited[neighbor] = true;
        q.push(neighbor);
        dist[neighbor] = dist[node] + 1;
        if (marked.find(neighbor) != marked.end())
        {
          furthest = dist[neighbor];
        }
      }
    }
  }
  // cout << furthest << ' ' << (furthest + 1 ) / 2 << endl;
  cout << (furthest + 1) / 2 << endl;



}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}