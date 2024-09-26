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
vector<vector<int>> linlayers(int n) { vector<vector<int>> v(n, vector<int>()); for (int i = 0; i < n; i++) { int m; cin >> m; for (int j = 0; j < m; j++) {int x; cin >> x;  v[i].push_back(x);}}}
vector<ll> linll(int n) { vector<ll> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }
vector<vector<ll>> lin2dll(int n, int m) { vector<vector<ll>> v(n, vector<ll>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }

ll b_search(ll n, ll k)
{
    // binary search for kth positive integer not divisible by n
    ll l = 1, r = 1e12;
    while (l < r)
    {
        int m = (l + r) / 2;

        if (m - m / n >= k)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}


void solve()
{
    ll n, k;
    cin >> n >> k;
    cout << b_search(n, k) << en;
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
