#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int initialize = -1e6;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char> > grid(n, vector<char>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        // if (t != 0)
        // {
        //     continue;
        // }
        vector<vector<int> > dp(n, vector<int>(m, 0));
        vector<vector<vector<int> > > dpNoWater(n, vector<vector<int> >(m, vector<int>(3)));
        vector<int> localLargest(3);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = initialize;
                dpNoWater[i][j][0] = -1;
                dpNoWater[i][j][1] = -1;
                dpNoWater[i][j][2] = initialize;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    if (grid[i][j] == 'D')
                    {
                        dpNoWater[i][j][0] = 0;
                        dpNoWater[i][j][1] = 0;
                        dpNoWater[i][j][2] = 1;
                        dp[i][j] = 1;
                    }
                    else if (grid[i][j] == 'L')
                    {
                        dpNoWater[i][j][0] = 0;
                        dpNoWater[i][j][1] = 0;
                        dpNoWater[i][j][2] = 0;
                    }
                    else
                    {
                        dpNoWater[i][j][0] = 0;
                        dpNoWater[i][j][1] = 0;
                        dpNoWater[i][j][2] = 0;
                        dp[i][j] = 0;
                    }
                    continue;
                }

                // fill in dp with water
                if (grid[i][j] != 'L')
                {
                    int m = initialize;
                    localLargest[0] = -1;
                    localLargest[1] = -1;
                    localLargest[2] = initialize;
                    if (i > 0)
                    {
                        m = max(m, dp[i - 1][j]);
                        if (dpNoWater[i - 1][j][2] > localLargest[2])
                        {
                            localLargest = dpNoWater[i - 1][j];
                        }
                        if (dp[i - 1][j] > localLargest[2])
                        {
                            localLargest[0] = i;
                            localLargest[1] = j;
                            localLargest[2] = dp[i - 1][j];
                        }
                    }
                    if (j > 0)
                    {
                        m = max(m, dp[i][j - 1]);
                        if (dpNoWater[i][j - 1][2] > localLargest[2])
                        {
                            localLargest = dpNoWater[i][j - 1];
                        }
                        if (dp[i][j - 1] > localLargest[2])
                        {
                            localLargest[0] = i;
                            localLargest[1] = j;
                            localLargest[2] = dp[i][j - 1];
                        }
                    }
                    if (grid[i][j] == 'D')
                    {
                        localLargest[2]++;
                        m++;
                    }
                    dp[i][j] = m;
                    dpNoWater[i][j] = localLargest;
                }
                else
                {
                    dp[i][j] = initialize;
                    localLargest[0] = -1;
                    localLargest[1] = -1;
                    localLargest[2] = initialize;

                    if (i > 0)
                    {
                        if (dp[i - 1][j] > localLargest[2])
                        {
                            localLargest[0] = i;
                            localLargest[1] = j;
                            localLargest[2] = dp[i - 1][j];
                        }
                        if (dpNoWater[i - 1][j][2] > localLargest[2] and (dpNoWater[i - 1][j][0] == i or dpNoWater[i - 1][j][1] == j))
                        {
                            localLargest = dpNoWater[i - 1][j];
                        }
                    }
                    if (j > 0)
                    {
                        if (dp[i][j - 1] > localLargest[2])
                        {
                            localLargest[0] = i;
                            localLargest[1] = j;
                            localLargest[2] = dp[i][j - 1];
                        }
                        if (dpNoWater[i][j - 1][2] > localLargest[2] and (dpNoWater[i][j - 1][0] == i or dpNoWater[i][j - 1][1] == j))
                        {
                            localLargest = dpNoWater[i][j - 1];
                        }
                    }
                    dpNoWater[i][j] = localLargest;
                }
                // print dp and dpNoWater
                // for (int i = 0; i < n; i++)
                // {
                //     for (int j = 0; j < m; j++)
                //     {
                //         cout << dp[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
                // for (int i = 0; i < n; i++)
                // {
                //     for (int j = 0; j < m; j++)
                //     {
                //         cout << "( ";
                //         for (int k = 0; k < 3; k++)
                //         {
                //             cout << dpNoWater[i][j][k] << " ";
                //         }
                //         cout << ") ";
                //     }
                //     cout << endl;

                // }

            }
        }
        if (dpNoWater[n - 1][m - 1][2] < 0)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {        
            cout << dpNoWater[n - 1][m - 1][2] << endl;
        }
    }
    return 0;
}