#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define INF 1000000000000
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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(m);
    for (int i = 0; i < m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        edges[i] = {a, b, w};
    }
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    for (int i = 0; i < m; i++)
    {
        dp[edges[i][0]][edges[i][1]] = min(dp[edges[i][0]][edges[i][1]], edges[i][2]);
        dp[edges[i][1]][edges[i][0]] = min(dp[edges[i][1]][edges[i][0]], edges[i][2]);
    }

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    

    // floyd warshall
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                dp[i][k] = min(dp[i][k], dp[i][j] + dp[j][k]);
                dp[k][i] = min(dp[k][i], dp[k][j] + dp[j][i]);
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        vector<int> cur_edges(k);
        for (int j = 0; j < k; j++)
        {
            cin >> cur_edges[j];
            cur_edges[j]--;
        }

        // go through all possible permutations of the edges

        ll ans = INF;
        sort(cur_edges.begin(), cur_edges.end());
        do
        {
            int cur = 0;
            ll cur_ans = 0;
            for (int j = 0; j < k; j++)
            {
                int n1 = edges[cur_edges[j]][0];
                int n2 = edges[cur_edges[j]][1];
                ll dist1 = dp[cur][n1];
                ll dist2 = dp[cur][n2];
                if (dist1 > dist2)
                {
                    swap(n1, n2);
                    swap(dist1, dist2);
                }
                cur_ans += dist1;
                cur = n2;
                cur_ans += edges[cur_edges[j]][2];
            }
            cur_ans += dp[cur][n - 1];
            ans = min(ans, cur_ans);
        } while (next_permutation(cur_edges.begin(), cur_edges.end())); 
        cout << ans << endl;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

}
