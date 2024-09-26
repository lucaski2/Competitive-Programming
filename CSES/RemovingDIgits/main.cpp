#include <bits/stdc++.h>
using namespace std;

void get_digits(int n, vector<int> &placement)
{
    int ind = 0;
    while (n > 0)
    {
        placement[ind] = n % 10;
        n /= 10;
        ind++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> placement(10);

    vector<int> dp(n + 1, 10000000);
    dp[n] = 0;

    for (int i = n; i > 0; i--)
    {
        get_digits(i, placement);
        for (int num : placement)
        {
            if (i - num < 0)
            {
                continue;
            }
            dp[i - num] = min(dp[i - num], dp[i] + 1);
        }
    }
    cout << dp[0] << endl;
}
