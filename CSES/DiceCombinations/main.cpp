#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= min(i + 6, n); j++)
        {
            dp[j] += dp[i];
            dp[j] %= MOD;
        }
    }
    cout << dp[n] << endl;
}
