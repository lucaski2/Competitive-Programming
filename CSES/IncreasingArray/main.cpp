#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int s = 0;
    for (int i = 1; i < n; i++)
    {

        if (v[i] < v[i - 1])
        {
            int diff = v[i - 1] - v[i];
            cout << i << " " << diff << endl;
            s += diff;
            v[i] += diff;
        }
    }
    cout << s << endl;
}