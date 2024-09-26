#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    
    for (int i = 0; i < n; i++)
    {
        if (v[i] != i + 1)
        {
            cout << i + 1 << endl;
            break;
        }
    }
}




