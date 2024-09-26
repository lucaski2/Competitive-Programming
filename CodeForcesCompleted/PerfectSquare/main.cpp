#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char sq[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> sq[i][j];
            }
        }

        int changes = 0;

        for (int i = 0; i < ceil(n / 2.0); i++)
        {
            for (int j = 0; j < ceil(n / 2.0); j++)
            {
                int max = 0;
                // the char at all rotations of the matrix
                int things[4] = {(int)sq[i][j], (int)sq[j][n - i - 1], (int)sq[n - i - 1][n - j - 1], (int)sq[n - j - 1][i]};
                int largest = *max_element(things, things + 4);
                for (int i = 0; i < 4; i++)
                {
                    changes += abs(largest - things[i]);
                }
            }
        }
        cout << changes << endl;

    }
}


