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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];
  
  vector<vector<bool>> visited(n, vector<bool>(m));
  int s = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == '.')
      {
        grid[i][j] = 'X';
        s++;
      }
    }
  }

  k = s - k;

  function<void(int, int)> dfs = [&](int x, int y)
  {
    if (k > 0)
    {
      grid[x][y] = '.';
      k--;
    }

    visited[x][y] = true;
    vector<pair<int, int>> choices = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (pair<int, int> choice : choices)
    {
      int nx = x + choice.first;
      int ny = y + choice.second;
      if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
      if (visited[nx][ny]) continue;
      if (grid[nx][ny] == '#') continue;
      
      dfs(nx, ny);
    }
  };


  bool start = false;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!start and grid[i][j] == 'X')
      {
        dfs(i, j);
        start = true;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << grid[i][j];
    }
    cout << endl;
  }

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