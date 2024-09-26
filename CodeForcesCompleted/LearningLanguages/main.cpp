#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;

int overlap_1d(int a1, int a2, int b1, int b2) {return max(0, min(a2, b2) - max(a1, b1));}
int overlap_2d(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){ return overlap_1d(ax1, ax2, bx1, bx2) * overlap_1d(ay1, ay2, by1, by2);}
double dist_squared(int x1, int y1, int x2, int y2){ return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);}
double dist(int x1, int y1, int x2, int y2){ return sqrt(dist_squared(x1, y1, x2, y2));}
vector<int> lin(int n) { vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }
vector<vector<int>> lin2d(int n, int m) { vector<vector<int>> v(n, vector<int>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
vector<vector<int>> linlayers(int n) { vector<vector<int>> v(n, vector<int>()); for (int i = 0; i < n; i++) { int m; cin >> m; for (int j = 0; j < m; j++) {int x; cin >> x;  v[i].push_back(x);}} return v;}
vector<ll> linll(int n) { vector<ll> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }
vector<vector<ll>> lin2dll(int n, int m) { vector<vector<ll>> v(n, vector<ll>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
vector<vector<char>> lin2dc(int n, int m) { vector<vector<char>> v(n, vector<char>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
vector<vector<int>> graph_edges_al(int n, int m) { vector<vector<int>> g(n); for (int i = 0; i < m; i++) { int a, b; cin >> a >> b; a--; b--; g[a].push_back(b); g[b].push_back(a);} return g;}
vector<vector<int>> graph_edges_am(int n, int m) { vector<vector<int>> g(n, vector<int>(n, 0)); for (int i = 0; i < m; i++) { int a, b; cin >> a >> b; a--; b--; g[a][b] = 1; g[b][a] = 1;} return g;}
template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}
vector<string> instr(int n) { vector<string> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }


void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (int x : graph[node])
    {
        if (!visited[x])
        {
            dfs(graph, visited, x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<unordered_set<int>> langs(n, unordered_set<int>());
    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            langs[i].insert(x - 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool common = false;
            for (int x : langs[i])
            {
                if (langs[j].count(x))
                {
                    common = true;
                    break;
                }
            }
            if (common)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    int count = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(graph, visited, i);
            count++;
        }
    }

    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        if (!langs[i].empty())
        {
            ok = true;
            break;
        }
    }
    cout << (ok ? count - 1 : count) << endl;
}
