#include <bits/stdc++.h>
#define ll long long
#define inf 10e18
#define leng 2e5
using namespace std;

int overlap_1d(int a1, int a2, int b1, int b2) {return max(0, min(a2, b2) - max(a1, b1));}

int overlap_2d(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {return overlap_1d(ax1, ax2, bx1, bx2) * overlap_1d(ay1, ay2, by1, by2);}

int dist_squared(int x1, int y1, int x2, int y2) {return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);}

int dist(int x1, int y1, int x2, int y2) {return sqrt(dist_squared(x1, y1, x2, y2));}

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
    return v;
}


int main()
{
    int n;
    cin >> n;
    vector<int> a = lin(n);
    vector<int> last1(n);
    vector<int> last2(n);
    int last = -leng;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            last = i;
        }
        last1[i] = i - last;
    }
    last = leng * 2;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            last = i;
        }
        last2[i] = last - i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << min(last1[i], last2[i]) << " ";
    }
    cout << endl;

}
