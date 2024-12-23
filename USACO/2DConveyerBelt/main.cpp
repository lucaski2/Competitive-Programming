#include <bits/stdc++.h>
#define ll long long

using namespace std;


void solve(vector<vector<vector<pair<int, int>>>> &graph, vector<vector<bool>> &used)
{
  int n = graph.size();
  queue<pair<int, int>> q;
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  vector<vector<bool>> inComponent(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!visited[i][j] && used[i][j])
      {
        vector<pair<int, int>> component;
        q.push({i, j});
        visited[i][j] = true;
        bool ok = true;
        while (!q.empty())
        {
          pair<int, int> cur = q.front();
          q.pop();
          component.push_back(cur);
          for (pair<int, int> next : graph[cur.first][cur.second])
          {
            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= n)
            {
              ok = false;
            }
            else if (!visited[next.first][next.second] and used[next.first][next.second])
            {
              visited[next.first][next.second] = true;
              q.push(next);
            }
            else if (!visited[next.first][next.second] and !used[next.first][next.second])
            {
              // try outward path
              queue<pair<int, int>> q2;
              q2.push(next);
              component.push_back(next);
              bool hit_edge = false;
              visited[next.first][next.second] = true;
              while (!q2.empty())
              {
                pair<int, int> cur2 = q2.front();
                q2.pop();

                if (used[cur2.first][cur2.second])
                {
                  for (pair<int, int> next2 : graph[cur2.first][cur2.second])
                  {
                    if (next2.first < 0 || next2.first >= n || next2.second < 0 || next2.second >= n)
                    {
                      hit_edge = true;
                    }
                    else if (!visited[next2.first][next2.second])
                    {
                      visited[next2.first][next2.second] = true;
                      component.push_back(next2);
                      q2.push(next2);
                    }
                  }
                }
                else
                {
                  for (pair<int, int> dir : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
                  {
                    pair<int, int> next2 = {cur2.first + dir.first, cur2.second + dir.second};
                    if (next2.first < 0 || next2.first >= n || next2.second < 0 || next2.second >= n)
                    {
                      hit_edge = true;
                    }
                    else if (!visited[next2.first][next2.second])
                    {
                      visited[next2.first][next2.second] = true;
                      q2.push(next2);
                    }
                  }
                }
              }
              if (hit_edge)
              {
                ok = false;
              }
            }
          }
        }
        cout << component.size() << endl;
        if (ok)
        {
          for (pair<int, int> p : component)
          {
            inComponent[p.first][p.second] = true;
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << (inComponent[i][j] ? 'X' : '.');
    }
    cout << endl;
  }
  cout << endl;

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     for (pair<int, int> next : graph[i][j])
  //     {
  //       cout << i << " " << j << " " << next.first << " " << next.second << endl;
  //     }
  //   }
  // }
  visited.resize(n, vector<bool>(n, false));
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (inComponent[i][j])
      {
        ans++;
      }
      else if (!visited[i][j])
      {
        // bfs
        q.push({i, j});
        bool hit_edge = false;
        visited[i][j] = true;
        int cur_size = 0;
        while (!q.empty())
        {

          pair<int, int> cur = q.front();
          q.pop();
          // cout << cur.first << " " << cur.second << endl;
          cur_size++;
          for (pair<int, int> change : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
          {
            pair<int, int> next = {cur.first + change.first, cur.second + change.second};
            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= n)
            {
              hit_edge = true;
              continue;
            }
            if (!inComponent[next.first][next.second] and used[next.first][next.second])
            {
              hit_edge = true;
            }
            if (!visited[next.first][next.second] and !inComponent[next.first][next.second])
            {
              visited[next.first][next.second] = true;
              q.push(next);
              cur_size++;
            }
          }
        }
        if (!hit_edge)
        {
          ans += cur_size;
        }
      }
    }
  }
  cout << "Sol: ";
  cout << ans << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;

  vector<vector<vector<pair<int, int>>>> graph(n, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>()));
  vector<vector<bool>> used(n, vector<bool>(n, false));

  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    char s;
    cin >> s;
    pair<int, int> dir;
    if (s == 'R')
    {
      dir = {0, 1};
    }
    else if (s == 'L')
    {
      dir = {0, -1};
    }
    else if (s == 'U')
    {
      dir = {-1, 0};
    }
    else if (s == 'D')
    {
      dir = {1, 0};
    }
    used[a][b] = true;

    graph[a][b].push_back({a + dir.first, b + dir.second});
    // check if a + dir.first, b + dir.second is in bounds
    if (a + dir.first < 0 || a + dir.first >= n || b + dir.second < 0 || b + dir.second >= n)
    {} else graph[a + dir.first][b + dir.second].push_back({a, b});
    solve(graph, used);
  }
  return 0;
}
