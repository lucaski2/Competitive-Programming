#include <bits/stdc++.h>
#define ll long long
#define leng 1e6
#define mint 2147483647
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
vector<ll> linll(int n) { vector<ll> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }
vector<vector<ll>> lin2dll(int n, int m) { vector<vector<ll>> v(n, vector<ll>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
vector<vector<char>> lin2dc(int n, int m) { vector<vector<char>> v(n, vector<char>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
vector<vector<int>> graph_edges_al(int n, int m) { vector<vector<int>> g(n); for (int i = 0; i < m; i++) { int a, b; cin >> a >> b; a--; b--; g[a].push_back(b); g[b].push_back(a);} return g;}

void dfs(int cur, set<int> &not_used, vector<int> &component, vector<vector<int>> &graph)
{
    for (int i = 0; i < graph[cur].size(); i++)
    {
        if (not_used.find(graph[cur][i]) != not_used.end())
        {
            not_used.erase(graph[cur][i]);
            component.push_back(graph[cur][i]);
            dfs(graph[cur][i], not_used, component, graph);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a = lin(n);
    vector<vector<int>> graph = graph_edges_al(n, m);
    set<int> not_used;
    for (int i = 0; i < n; i++) not_used.insert(i);
 

    vector<vector<int>> components;
    while (!not_used.empty())
    {
        vector<int> component;
        int cur = *not_used.cbegin();
        component.push_back(cur);
        not_used.erase(cur);
        dfs(cur, not_used, component, graph);
        components.push_back(component);
        
    }

    ll ans = 0;
    for (int i = 0; i < components.size(); i++)
    {
        int mi = mint;
        for (int j = 0; j < components[i].size(); j++)
        {
            mi = min(mi, a[components[i][j]]);
        }
        ans += mi;
    }
    cout << ans << endl;
}
