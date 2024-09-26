#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

vector <ll> greater_than_cells_around(const vector<vector<ll> >& a, int i, int j, int n, int m)
{
    vector<ll> v;
    if (i > 0) v.push_back(a[i - 1][j]);
    if (i < n - 1) v.push_back(a[i + 1][j]);
    if (j > 0) v.push_back(a[i][j - 1]);
    if (j < m - 1) v.push_back(a[i][j + 1]);
    return v;
}



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<ll> > a(n, vector<ll>(m));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vector<ll> v = greater_than_cells_around(a, i, j, n, m);

                // get max in v
                ll largest = *max_element(v.begin(), v.end());
                if (a[i][j] > largest && v.size() > 0)
                {
                    a[i][j] = largest;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}





