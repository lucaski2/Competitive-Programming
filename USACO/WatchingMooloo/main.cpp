#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll s = 1 + k;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= a[i - 1] + k)
        {
            s += a[i] - a[i - 1];
        }
        else
        {
            s += k + 1;
        }
    }
    cout << s << endl;


}