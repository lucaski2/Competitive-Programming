#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < x; i++)
    {
        for (int coin : a)
        {
            if (i + coin > x)
            {
                continue;
            }
            dp[i + coin] += dp[i];
            dp[i + coin] %= MOD;
        }
    }
    cout << dp[x] << endl;
}