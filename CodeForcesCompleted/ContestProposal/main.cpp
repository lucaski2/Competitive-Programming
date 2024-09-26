#include <bits/stdc++.h>
#include <iostream>
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
        vector <ll> v1;
        vector <ll> v2;
        for (int i = 0; i < n; i++)
        {
            ll val;
            cin >> val;
            v1.push_back(val);
        }
        for (int i = 0; i < n; i++)
        {
            ll val;   
            cin >> val;
            v2.push_back(val); 
        }
        bool done = false;
        int cnt = 0;
        for (int i = 0; i < 100; i++)
        {
            // check condition
            done = true;
            for (int i = 0; i < min((int)v1.size(), (int)v2.size()); i++)
            {
                if (v1[i] > v2[i])
                {
                    done = false;
                    break;
                }
            }
            if (done)
            {
                break;
            }
            v1.insert(v1.begin(), 0);
            cnt += 1;
        }
        cout << cnt << endl;

    }
}