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
  ifstream cin("ccski.in");
  ofstream cout("ccski.out");


  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  vector<vector<bool>> points(n, vector<bool>(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  pair<int, int> start = {-1, -1};
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m;j++)
    {
      int a;
      cin >> a;
      points[i][j] = a;
      if (points[i][j])
      {
        start = {i, j};
        cnt++;
      }
    }
  }

  if (cnt == 0 or cnt == 1)
  {
    cout << 0 << endl;
    return;
  }
  int l = 0; int r = 1e9;
  int ans = mod;
  while (l<=r)
  {
    int cn = cnt;
    int mid = (l + r) / 2;

    queue<pair<int, int>> q;
    q.push(start);
    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[start.first][start.second] = true;
    while(!q.empty())
    {
      pair<int, int> te = q.front();
      q.pop();
      int x, y;
      tie(x, y) = te;
      if (points[x][y])
      {
        cn--;
      }

      for (int i = -1; i < 2; i++)
      {
        for (int j = -1; j < 2; j++)
        {
          if (i != 0 and j != 0)
          {
            continue;
          }
          
          int nx = x + i;
          int ny = y + j;

          if (nx >= n or ny >= m or nx < 0 or ny < 0)
          {
            continue;
          }

          if (!visited[nx][ny] and abs(grid[nx][ny] - grid[x][y]) <= mid)
          {
            // cout << nx << ' ' << ny << ' ' << x << ' ' << y << ' ' << grid[nx][ny] << ' ' << grid[x][y] << endl;
            visited[nx][ny] = true;
            q.push({nx, ny});
          }
        }
      }
    }

    if (cn <= 0)
    {
      ans = min(mid, ans);
      r = mid - 1;
    }
    else l = mid + 1;
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