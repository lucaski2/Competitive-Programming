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
template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

string colors[] = {"BG", "BR", "BY", "GR", "GY", "RY"};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<set<int>> n_inc(6);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = find(colors, colors + 6, s[i]) - colors;
        for (int j = 0; j < 6; j++)
        {
            if (j == a[i])
            {
                continue;
            }
            if (s[i][0] != colors[j][0] and s[i][1] != colors[j][0] and s[i][1] != colors[j][1] and s[i][0] != colors[j][1])
            {
                continue;
            }
            n_inc[j].insert(i);
        }
    }

    for (int _ = 0; _ < q; _++)
    {
        int start, end;
        cin >> start >> end;
        start--;
        end--;
        int n1 = a[start], n2 = a[end];
        if (s[start][0] == s[end][0] or s[start][1] == s[end][0] or s[start][0] == s[end][1] or s[start][1] == s[end][1])
        {
            cout << max(start, end) - min(start, end) << endl;
            continue;
        }
        auto temp1 = n_inc[n1].lower_bound(min(start, end));
        int num1;
        if (temp1 == n_inc[n1].end())
        {
            num1 = mint;
        }
        else
        {
            num1 = *temp1;
        }
        if (num1 < max(start, end))
        {
            cout << max(start, end) - min(start, end) << endl;
            continue;
        }
        auto temp2 = less_or_equal(n_inc[n1], min(start, end));
        int num2;
        if (temp2 == nullopt)
        {
            num2 = mint;
        }
        else
        {
            num2 = *temp2;
        }
        if (num1 > leng and num2 > leng)
        {
            cout << -1 << endl;
            continue;
        }
        num1 -= max(start, end);
        num2 = num2 == mint ? mint : min(start, end) - num2;
        if (num2 > leng)
        {
            cout << num1 * 2 + max(start, end) - min(start, end) << endl;
            continue;
        }
        else if (num1 > leng)
        {
            cout << num2 * 2 + max(start, end) - min(start, end) << endl;
            continue;
        }
        cout << min(num1, num2) * 2 + max(start, end) - min(start, end) << endl;
    }


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
