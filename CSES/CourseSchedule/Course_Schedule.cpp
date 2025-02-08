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
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<int> in_degree(n);
  for (int i = 0; i < m; i++)
  {
    int a, b; cin >> a >> b;
    a--; b--;
    in_degree[b]++;
    adj[a].push_back(b);
  }
  
  queue<int> q;
  vector<int> ans;

  for (int i = 0; i < n; i++)
  {
    if (in_degree[i] == 0) q.push(i);
  }

  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    ans.push_back(node);

    for (int neighbor : adj[node])
    {
      in_degree[neighbor]--;
      if (!in_degree[neighbor])
      {
        q.push(neighbor);
      }
    }
  }

  if (ans.size() != n)
  {
    cout << "IMPOSSIBLE" << endl;
  }
  else 
  {
    for (int am : ans)
    {
      cout << am + 1 << ' ';
    }
    cout << endl;
  }


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--)
  {
      solve();
  }
}