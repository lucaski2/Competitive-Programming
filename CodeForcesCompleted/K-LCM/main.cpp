#include <bits/stdc++.h>
#define ll long long
#define inf 10e18
using namespace std;



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n % 4 == 0)
        {
            cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << endl;
        }
        else if (n % 2 == 0)
        {
            n -= 2;
            cout << 2 << ' '  << n / 2 << ' ' << n / 2 << endl;
        }
        else 
        {
            cout << 1 << ' ' << (n - 1) / 2 << ' ' << (n - 1) / 2 << endl;
        }
    }
}