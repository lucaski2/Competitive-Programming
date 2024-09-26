#include <bits/stdc++.h>
#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n];
    int b[m];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    
    sort(a, a + n);
    sort(b, b + m);

    int a_ind = 0;
    int b_ind = 0;
    ll amount_paid = 0;

    while (a_ind < n && b_ind < m)
    {
        if (a[a_ind] >= b[b_ind])
        {
            amount_paid += a[a_ind];
            a_ind++;
            b_ind++;
        }
        else
        {
            a_ind++;
        }
    }
    if (b_ind == m)
    {
        cout << amount_paid << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

}