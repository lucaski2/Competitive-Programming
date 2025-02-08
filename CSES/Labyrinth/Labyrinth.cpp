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
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> visited(n, vector<bool>(m));
  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  string cur;

  function<void(int, int)> dfs = [&](int x, int y)
  {

    if (grid[x][y] == 'B')
    {
      cout << "YES" << endl;
      cout << cur.size() << endl;
      cout << cur << endl;
      exit(0);
    }
    visited[x][y] = true;



    for (int i = -1; i <= 1; i++)
    {
      for (int j = -1; j <= 1; j++)
      {
        if (i != 0 and j != 0)
        {
          continue;
        }
        int nx = x + i, ny = y + j;
        if (nx < 0 or nx >= n or ny < 0 or ny >= m)
        {
          continue;
        }
        
        if (visited[nx][ny] or grid[nx][ny] == '#') continue;
        if (i == 0 and j == 1)
        {
          cur.append("R");
        }
        else if (i == 0)
        {
          cur.append("L");
        }
        else if (i == 1)
        {
          cur.append("D");
        }
        else cur.append("U");

        dfs(nx, ny);
        cur.pop_back();
      }
    }
  };


  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 'A') dfs(i, j);
    }
  }
  cout << "NO" << endl;


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