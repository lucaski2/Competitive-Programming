#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    vector<int> rows(n, 0);
    vector<int> cols(m, 0);
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                continue;
            }
            if (visited[i][j])
            {
                continue;
            }
            int min_x = i, max_x = i, min_y = j, max_y = j;
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            int size = 0;

            while (!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                size++;
                min_x = min(min_x, x);
                max_x = max(max_x, x);
                min_y = min(min_y, y);
                max_y = max(max_y, y);
                if (x > 0 && grid[x - 1][y] == '#' && !visited[x - 1][y])
                {
                    q.push({x - 1, y});
                    visited[x - 1][y] = true;
                }
                if (x < n - 1 && grid[x + 1][y] == '#' && !visited[x + 1][y])
                {
                    q.push({x + 1, y});
                    visited[x + 1][y] = true;
                }
                if (y > 0 && grid[x][y - 1] == '#' && !visited[x][y - 1])
                {
                    q.push({x, y - 1});
                    visited[x][y - 1] = true;
                }
                if (y < m - 1 && grid[x][y + 1] == '#' && !visited[x][y + 1])
                {
                    q.push({x, y + 1});
                    visited[x][y + 1] = true;
                }
            }
            for (int i = max(0, min_x - 1); i <= min(n - 1, max_x + 1); i++)
            {
                rows[i] += size;
            }
            for (int i = max(0, min_y - 1); i <= min(m - 1, max_y + 1); i++)
            {
                cols[i] += size;
            }
        }
    }
    vector<int> counts(n, 0);
    vector<int> count_cols(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                counts[i]++;
                count_cols[j]++;
            }
        }
    }

    int ans = 0;
    for (int row = 0; row < n; row++)
    {
        ans = max(ans, counts[row] + rows[row]);
    }

    for (int col = 0; col < m; col++)
    {
        ans = max(ans, count_cols[col] + cols[col]);
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
