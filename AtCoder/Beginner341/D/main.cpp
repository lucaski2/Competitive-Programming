#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = lcm(n, m);
    ll time_before_gcd = int(l / n) + int(l / m) - 2;
    ll cur_num = 0;
    ll am = k / time_before_gcd;
    k %= time_before_gcd;
    cur_num = am * l;
    if (k == 0)
    {
        k = time_before_gcd;
        cur_num -= l;
    }
    ll until_n = n;
    ll until_m = m;
    
    while (k > 0)
    {
        k -= 1;
        cur_num += min(until_n, until_m);
        ll temp = min(until_n, until_m);
        until_n -= temp;
        until_m -= temp;
        if (!until_n)
        {
            until_n = n;
        }
        else
        {
            until_m = m;
        }
    }
    cout << cur_num << endl;

}

