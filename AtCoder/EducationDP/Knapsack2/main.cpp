#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main()
{
    int n, w;
    cin >> n >> w;
    vector<vector<ll> > v(n, vector<ll>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    set<ll> values;
    vector<vector<ll> > dp(n + 1, vector<ll>(100001, 1000000000));
    values.insert(0);
    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (ll it : values)
        {
            if (dp[i][it] + v[i][0] <= w)
            {
                dp[i + 1][it + v[i][1]] = min(dp[i + 1][it + v[i][1]], dp[i][it] + v[i][0]);
                values.insert(it + v[i][1]);
            }
            dp[i + 1][it] = min(dp[i + 1][it], dp[i][it]);
        }
    }

    cout << *(values.rbegin()) << endl;

}
