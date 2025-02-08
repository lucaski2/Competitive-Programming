#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

struct query
{
  int tlx, tly, brx, bry;
};


void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  int q;
  cin >> q;


  // find total sum of areas, if > 1e6 then subtask2 otherwise subtask1

  vector<query> queries(q);
  int su = 0;
  for (int i = 0; i < q; i++)
  {
    cin >> queries[i].tlx >> queries[i].tly >> queries[i].brx >> queries[i].bry;
    su += (queries[i].brx - queries[i].tlx + 1) * (queries[i].bry - queries[i].tly + 1);

  }

  if (su >= 1e6)
  {
    // subtask 2



  }


  else
  {

    vector<vector<bool>> visited(n, vector<bool> (m));
    // cout << queries.size() << endl;
    for (query qu : queries)
    {
      bool ok = true;
      for (int x = qu.tlx; x <= qu.brx; x++)
      {
        for (int y = qu.tly; y <= qu.bry; y++)
        {
          
          if (visited[x][y]) continue;



          function<void(int, int, int, int, int)> dfs = [&](int x, int y, int prev, int parx, int pary)
          {
            visited[x][y] = true;
            if (grid[x][y] < prev) return;
            int degree = 0;
            for (int nx = -1; nx <= 1; nx++)
            {
              for (int ny = -1; ny <= 1; ny++)
              {
                if (nx == 0 && ny == 0) continue;
                if (nx != 0 && ny != 0) continue;
                int xx = x + nx;
                int yy = y + ny;
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if (xx > qu.brx || xx < qu.tlx || yy > qu.bry || yy < qu.tly) continue;
                if (xx == parx && yy == pary) continue;
                if (grid[xx][yy] != grid[x][y]) return;

                if (visited[xx][yy]) ok = false;
                if (visited[xx][yy]) return;

                degree++;
                dfs(xx, yy, grid[x][y], x, y);
              }
            }
          };

          dfs(x, y, grid[x][y], -1, -1);
          if (!ok) break;

        }
      }
      if (!ok)
      {
        cout << "No" << endl;
      }
      else cout << "Yes" << endl;
    }
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
