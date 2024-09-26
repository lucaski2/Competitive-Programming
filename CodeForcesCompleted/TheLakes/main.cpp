#include <bits/stdc++.h>
#define ll long long
#define leng 1e6
#define mint 1e9
#define mod 1e9 + 7
#define inf 10e18
#define en '\n'
using namespace std;

int overlap_1d(int a1, int a2, int b1, int b2) {return max(0, min(a2, b2) - max(a1, b1));}
int overlap_2d(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){ return overlap_1d(ax1, ax2, bx1, bx2) * overlap_1d(ay1, ay2, by1, by2);}
int dist_squared(int x1, int y1, int x2, int y2){ return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);}
int dist(int x1, int y1, int x2, int y2){ return sqrt(dist_squared(x1, y1, x2, y2));}
vector<int> lin(int n) { vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }
vector<vector<int>> lin2d(int n, int m) { vector<vector<int>> v(n, vector<int>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
vector<vector<int>> linlayers(int n) { vector<vector<int>> v(n, vector<int>()); for (int i = 0; i < n; i++) { int m; cin >> m; for (int j = 0; j < m; j++) {int x; cin >> x;  v[i].push_back(x);}} return v;}
vector<ll> linll(int n) { vector<ll> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }
vector<vector<ll>> lin2dll(int n, int m) { vector<vector<ll>> v(n, vector<ll>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
vector<vector<char>> lin2dc(int n, int m) { vector<vector<char>> v(n, vector<char>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
vector<vector<int>> graph_edges_al(int n, int m) { vector<vector<int>> g(n); for (int i = 0; i < m; i++) { int a, b; cin >> a >> b; a--; b--; g[a].push_back(b); g[b].push_back(a);} return g;}
vector<vector<int>> graph_edges_am(int n, int m) { vector<vector<int>> g(n, vector<int>(n, 0)); for (int i = 0; i < m; i++) { int a, b; cin >> a >> b; a--; b--; g[a][b] = 1; g[b][a] = 1;} return g;}

void dfs(vector<vector<int>> &grid, pair<int, int> node, set<pair<int, int>> &not_visited, vector<int> &component)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i != 0 and j != 0)
            {
                continue;
            }
            pair<int, int> new_node = {node.first + i, node.second + j};
            if (not_visited.find(new_node) != not_visited.end() && grid[new_node.first][new_node.second] != 0)
            {
                not_visited.erase(new_node);
                component.push_back(grid[new_node.first][new_node.second]);
                dfs(grid, new_node, not_visited, component);
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid = lin2d(n, m);
    vector<vector<int>> components(n, vector<int>());
    set<pair<int, int>> not_visited;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
                not_visited.insert({i, j});
        }
    }
    

    while (!not_visited.empty())
    {
        pair<int, int> cur = *not_visited.begin();
        not_visited.erase(cur);
        vector<int> component;
        component.push_back(grid[cur.first][cur.second]);
        dfs(grid, cur, not_visited, component);
        components.push_back(component);
    }
    int ans = 0;
    for (int i = 0; i < components.size(); i++)
    {
        ans = max(ans, accumulate(components[i].begin(), components[i].end(), 0));
    }
    cout << ans << en;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
