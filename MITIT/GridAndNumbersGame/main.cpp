#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

struct sq
{
  ll x, y, num;

  bool operator<(const sq& other) const
  {
    return num > other.num;
  }
  
};

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> grid(n, vector<ll>(m));

  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < m; j++) cin >> grid[i][j];
  }

  priority_queue<sq> pq;
  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < m; j++) pq.push({i, j, grid[i][j]});
  }

  ll turns = 0;
  for (ll i = 0; i < n * m; i++)
  {
    auto [x, y, num] = pq.top();
    pq.pop();
    
    // find max less than x in neighbors
    ll diff = -1;
    for (ll nx = -1; nx <= 1; nx++)
    {
      for (ll ny = -1; ny <= 1; ny++)
      {
        if (nx == 0 && ny == 0) continue;
        if (nx != 0 && ny != 0) continue;
        ll xx = x + nx;
        ll yy = y + ny;
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if (grid[xx][yy] == num) diff = num - 1;
        else if (grid[xx][yy] < num) diff = max(diff, grid[xx][yy]);
      }
    }
    grid[x][y] = diff + 1;
    // cout << num << ' ' << diff << endl;
    turns += num - diff - 1;
  }
  // cout << turns << endl;
  if (turns % 2 == 0)
  {
    cout << "NO" << en;
  }
  else
  {
    cout << "YES" << en;
  }

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}
