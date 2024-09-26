#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

ll dp[101][100001];

int main()
{
    int n, w;
    cin >> n >> w;
    vector<vector<ll> > grid(n, vector<ll> (2));
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i][0] >> grid[i][1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < w; j++)
        {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + grid[i][0] > w)
            {
                continue;
            }
            dp[i + 1][j + grid[i][0]] = max(dp[i + 1][j + grid[i][0]], dp[i][j] + grid[i][1]);
        }
    }
    cout << *max_element(dp[n], dp[n] + w + 1) << "\n";


}

