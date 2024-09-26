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

        vector<int> a(n);
        vector<int> b(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i <= n; i++)
        {
            cin >> b[i];
        }

        ll min_dif = 1000000000;
        ll s = 0;
        
        for (int i = 0; i < n; i++)
        {
            ll cur = abs(a[i] - b[b.size() - 1]);
            ll cur2 = abs(b[i] - b[b.size() - 1]);
            if (cur < min_dif)
            {
                min_dif = cur;
            }
            if (cur2 < min_dif)
            {
                min_dif = cur2;
            }
            s += abs(a[i] - b[i]);
        }


        ll ending = b[b.size() - 1];
        bool need_to_add = true;

        for (int i = 0; i < n; i++)
        {
            if (ending >= min(a[i], b[i]) && ending <= max(a[i], b[i]))
            {
                need_to_add = false;
                break;
            }
        }
        if (need_to_add)
        {
            s += min_dif;
        }

        cout << s + 1 << endl;

        
    }
}