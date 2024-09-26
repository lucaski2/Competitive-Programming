#include <bits/stdc++.h>
#define ll long long
#define leng 1e6
#define inf 10e18
#define en '\n'
using namespace std;

int overlap_1d(int a1, int a2, int b1, int b2) {return max(0, min(a2, b2) - max(a1, b1));}

int overlap_2d(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){ return overlap_1d(ax1, ax2, bx1, bx2) * overlap_1d(ay1, ay2, by1, by2);}

int dist_squared(int x1, int y1, int x2, int y2){ return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);}

int dist(int x1, int y1, int x2, int y2){ return sqrt(dist_squared(x1, y1, x2, y2));}

vector<int> lin(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    return v;
}
vector<vector<int>> lin2d(int n, int m) {
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];} 
    return v;
}
vector<vector<int>> linlayers(int n)
{
    vector<vector<int>> v(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
                case 'N':
                    c1++;
                    break;
                case 'S':
                    c1--;
                    break;
                case 'E':
                    c2++;
                    break;
                case 'W':
                    c2--;
                    break;
                default:
                    break;
            }
        }
        if (c1 % 2 != 0 or c2 % 2 != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        vector<char> ans(n, 'N');
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'N' and c1 > 0)
            {
                ans[i] = 'R';
                c1 -= 1;
            }
            else if (s[i] == 'S' and c1 < 0)
            {
                ans[i] = 'R';
                c1 += 1;
            }
            else if (s[i] == 'E' and c2 > 0)
            {
                ans[i] = 'R';
                c2 -= 1;
            }
            else if (s[i] == 'W' and c2 < 0)
            {
                ans[i] = 'R';
                c2 += 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == 'N')
            {
                ans[i] = 'H';
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i];
        }
        cout << endl;
    }
}
