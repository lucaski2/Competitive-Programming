#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<string> grid;
vector<vector<int>> distM, distA;
vector<vector<char>> moveDir;
vector<vector<pair<int, int>>> parent;
queue<pair<int, int>> q;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> dirChars = {'U', 'D', 'L', 'R'};

// BFS for monsters
void bfsMonsters() {
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + directions[d].first, ny = y + directions[d].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && distM[nx][ny] == INF) {
                distM[nx][ny] = distM[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

// BFS for player
bool bfsPlayer(int sx, int sy) {
    q.push({sx, sy});
    distA[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            // Found an escape, reconstruct the path
            string path;
            while (make_pair(x, y) != make_pair(sx, sy)) {
                path += moveDir[x][y];
                auto [px, py] = parent[x][y];
                x = px, y = py;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n" << path.length() << "\n" << path << "\n";
            return true;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + directions[d].first, ny = y + directions[d].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                if (distA[x][y] + 1 < distM[nx][ny] && distA[nx][ny] == INF) {
                    distA[nx][ny] = distA[x][y] + 1;
                    parent[nx][ny] = {x, y};
                    moveDir[nx][ny] = dirChars[d];
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    distM.assign(n, vector<int>(m, INF));
    distA.assign(n, vector<int>(m, INF));
    moveDir.assign(n, vector<char>(m, 0));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    int sx, sy;

    // Read input and initialize monster BFS
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                distM[i][j] = 0;
                q.push({i, j});
            } else if (grid[i][j] == 'A') {
                sx = i, sy = j;
            }
        }
    }

    bfsMonsters();

    if (!bfsPlayer(sx, sy)) {
        cout << "NO\n";
    }

    return 0;
}
