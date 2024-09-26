#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int am = 40000;
int main()
{
    vector<long long> palindromes;

    for (long long i = 1; i <= am; ++i)
    {
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        
        if (s == t)
        {
            palindromes.push_back(i);
        }
    }
    vector<vector<long long>> dp(am + 1, vector<long long>(palindromes.size(), 0));
    dp[0][0] = 1;
    
    for (long long i = 0; i < am; i++)
    {
        for (int j = 0; j < palindromes.size(); j++)
        {
            if (i + palindromes[j] > am)
            {
                break;
            }
            dp[i + palindromes[j]][j] = (dp[i + palindromes[j]][j] + dp[i][j]) % MOD;
            if (j != palindromes.size() - 1)
            {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
        }
    }
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n][palindromes.size() - 1] << endl;
    }
    for (int i = 0; i < 200; i++)
    {
        cout << dp[i][palindromes.size() - 1] << endl;
    }
}