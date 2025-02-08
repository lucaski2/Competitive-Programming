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
  int n, m;
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  bool ok = false;
  bool found = false;
  vector<pair<int, int>> deltas = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 'G') found = true;
      if (grid[i][j] == 'B')
      {
        for (auto [dx, dy] : deltas)
        {
          int x = i + dx;
          int y = j + dy;
          if (x >= 0 && x < n && y >= 0 && y < m)
          {
            if (grid[x][y] == '.')
            {
              grid[x][y] = '#';
            }
            else if (grid[x][y] == 'G')
            {
              ok = true;
            }
          }
        }
      }
    }
  }

  if (ok)
  {
    cout << "No" << en;
    return;
  }

  vector<vector<bool>> visited(n, vector<bool>(m, false));
  queue<pair<int, int>> q;

  if (grid[n - 1][m - 1] == '#' and not found)
  {
    cout << "Yes" << en;
    return;
  }


  if (grid[n - 1][m - 1] == '#')
  {
    cout << "No" << en;
    return;
  }
  q.push({n - 1, m - 1});
  visited[n - 1][m - 1] = true;

  while (!q.empty())
  {
    auto [x, y] = q.front();
    q.pop();
    for (auto [dx, dy] : deltas)
    {
      int nx = x + dx;
      int ny = y + dy;
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#')
      {
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 'G' && !visited[i][j])
      {
        cout << "No" << en;
        return;
      }
      if (grid[i][j] == 'B' && visited[i][j])
      {
        cout << "No" << en;
        return;
      }
    }
  }
  cout << "Yes" << en;








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