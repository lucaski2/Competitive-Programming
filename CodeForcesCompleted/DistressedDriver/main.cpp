#include<bits/stdc++.h>
#include<iostream>
#define ll long long int
#define inf 1e18
using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<ll> > v(n, vector<ll>(2, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin(), v.end());


    
    ll dp[n + 1][k + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= k; j++)
        {
            if (v[i][0] < dp[i][j])
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] - v[i][0] + v[i][1]);
            }
            else
            {
                dp[i + 1][j] = min(dp[i + 1][j], v[i][1]);
            }
            if (j != k)
            {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            }
        }
        // print dp
        
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j <= k; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }

    // print dp
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (dp[n][k] == inf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[n][k] << endl;
    }

}