#include <bits/stdc++.h>
#include <iostream>
#include <set>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        set<ll> diffs;
        ll cur_even = 0;
        ll cur_odd = 0;
        bool p = true;
        diffs.insert(0);
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                cur_even += v[i];
            }
            else
            {
                cur_odd += v[i];
            }

            if (diffs.find(cur_even - cur_odd) != diffs.end())
            {
                cout << "YES" << endl;
                p = false;
                break;
            }
            else
            {
                diffs.insert(cur_even - cur_odd);
            }
        }
        if (p)
        {
            cout << "NO" << endl;
        }
        
    }        
}