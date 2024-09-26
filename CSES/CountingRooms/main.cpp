#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    
    bool visited[n][m];
    memset(visited, false, sizeof(visited));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#')
                continue;
            
            else if (visited[i][j])
                continue;
            
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            
            while (!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                


                vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto [dx, dy] : moves)
                {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (visited[nx][ny])
                        continue;
                    if (grid[nx][ny] == '#')
                        continue;
                    q.push({nx, ny});
                    visited[nx][ny] = true;

                }
            }
            ans++;
        }
    }
    cout << ans << endl;

}

