#include <bits/stdc++.h>
#define int long long
#define s second 
#define f first
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

  vector<vector<char>> grid(n, vector<char>(m));
  pair<int, int> A;
  pair<int, int> B;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') A = {i, j};
      if (grid[i][j] == 'B') B = {i, j};
    }
  }
  vector<vector<int>> depth(n, vector<int>(m, -1));
  vector<vector<char>> parent(n, vector<char>(m, 0));

  depth[A.f][A.s] = 0;
  
  queue<pair<int, int>> q;
  q.push(A);

  while (!q.empty())
  {
    pair<int, int> cur = q.front();
    q.pop();

    if (grid[cur.f][cur.s] == '#') continue;

    vector<pair<int, int>> delt = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (pair<int, int> del : delt)
    {
      int nx = cur.f + del.f;
      int ny = cur.s + del.s;
      if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
      // cout << nx << ' ' << ny << endl;
      if (depth[nx][ny] >= 0) continue;
      depth[nx][ny] = depth[cur.f][cur.s] + 1;
      if (del.f == -1) parent[nx][ny] = 'L';
      if (del.f == 1) parent[nx][ny] = 'R';
      if (del.s == 1) parent[nx][ny] = 'D';
      if (del.s == -1) parent[nx][ny] = 'U';
      // cout << "asdf" << endl;
      q.push({nx, ny});
    }
  }
  

  if (!parent[B.f][B.s]) 
  {
    cout << "NO" << endl;
    return;
  }


  string ans = "";
  while (parent[B.f][B.s])
  {
    if (parent[B.f][B.s] == 'L') 
    {
      ans += "R";
      B.s--;
    }
    if (parent[B.f][B.s] == 'R')
    {
      ans += "L";
      B.s++;
    }
    if (parent[B.f][B.s] == 'U') 
    {
      ans += "D";
      B.f--;
    }
    if (parent[B.f][B.s] == 'D')
    {
      ans += "U";
      B.f++;
    }
  }

  cout << "YES" << endl << ans.size() << endl;
  cout << ans << endl;


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