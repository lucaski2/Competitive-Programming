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

void dfs(vector<set<int>> &g, int node, set<int> &not_visited, vector<int> &component)
{
    for (int i : g[node])
    {
        if (not_visited.find(i) != not_visited.end())
        {
            not_visited.erase(i);
            component.push_back(i);
            dfs(g, i, not_visited, component);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        vector<int> temp = lin(a);
        for (int i = 0; i < a - 1; i++)
        {
            int cur1 = temp[i];
            int cur2 = temp[i + 1];
            cur1--;
            cur2--;
            g[cur1].insert(cur2);
            g[cur2].insert(cur1);
        }
    }
    set<int> not_visited;
    map<int, int> which_component;
    for (int i = 0; i < n; i++)
    {
        not_visited.insert(i);
    }
    vector<int> component;

    while (!not_visited.empty())
    {
        int cur = *not_visited.begin();
        not_visited.erase(cur);
        component.clear();
        component.push_back(cur);
        dfs(g, cur, not_visited, component);
        for (int i = 0; i < component.size(); i++)
        {
            which_component[component[i]] = (int)component.size();
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << which_component[i] << ' ';
    }
    cout << en;


}
