#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


// int overlap_1d(int a1, int a2, int b1, int b2) {return max(0, min(a2, b2) - max(a1, b1));}
// int overlap_2d(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){ return overlap_1d(ax1, ax2, bx1, bx2) * overlap_1d(ay1, ay2, by1, by2);}
// double dist_squared(int x1, int y1, int x2, int y2){ return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);}
// double dist(int x1, int y1, int x2, int y2){ return sqrt(dist_squared(x1, y1, x2, y2));}
// vector<int> lin(int n) { vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }
// vector<vector<int>> lin2d(int n, int m) { vector<vector<int>> v(n, vector<int>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
// vector<vector<int>> linlayers(int n) { vector<vector<int>> v(n, vector<int>()); for (int i = 0; i < n; i++) { int m; cin >> m; for (int j = 0; j < m; j++) {int x; cin >> x;  v[i].push_back(x);}} return v;}
// vector<ll> linll(int n) { vector<ll> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }
// vector<vector<ll>> lin2dll(int n, int m) { vector<vector<ll>> v(n, vector<ll>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
// vector<vector<char>> lin2dc(int n, int m) { vector<vector<char>> v(n, vector<char>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
// vector<vector<int>> graph_edges_al(int n, int m) { vector<vector<int>> g(n); for (int i = 0; i < m; i++) { int a, b; cin >> a >> b; a--; b--; g[a].push_back(b); g[b].push_back(a);} return g;}
// vector<vector<int>> graph_edges_am(int n, int m) { vector<vector<int>> g(n, vector<int>(n, 0)); for (int i = 0; i < m; i++) { int a, b; cin >> a >> b; a--; b--; g[a][b] = 1; g[b][a] = 1;} return g;}
// template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}
// vector<string> instr(int n) { vector<string> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }


pair<int, int> dfs(int i, int j, vector<string> &grid, vector<vector<bool>> &visited)
{
    visited[i][j] = true;
    pair<int, int> res = {1, 0};
    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (abs(x) + abs(y) == 1)
            {
                int ni = i + x;
                int nj = j + y;
                if (ni < 0 or ni >= grid.size() or nj < 0 or nj >= grid.size() or grid[ni][nj] == '.')
                {
                    res.second++;
                }
                else if (!visited[ni][nj])
                {
                    pair<int, int> p = dfs(ni, nj, grid, visited);
                    res.first += p.first;
                    res.second += p.second;
                }
            }
        }
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int max_area = 0;
    int min_perimeter = mint;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && grid[i][j] == '#')
            {
                pair<int, int> p = dfs(i, j, grid, visited);
                if (p.first > max_area)
                {
                    max_area = p.first;
                    min_perimeter = p.second;
                }
                else if (p.first == max_area)
                {
                    min_perimeter = min(min_perimeter, p.second);
                }
            }
        }
    }
    cout << max_area << " " << min_perimeter << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // make cin to read from a file
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    solve();
}
