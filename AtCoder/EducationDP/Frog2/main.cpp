#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

ll dp[100001];

int main()
{
    int n, k;
    vector<int> heights;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        heights.push_back(x);
        dp[i] = INT_MAX;
    }

    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < min(i + k + 1, n); j++)
        {
            dp[j] = min(dp[j], dp[i] + abs(heights[i] - heights[j]));
        }
    }

    cout << dp[n - 1] << endl;

}








