#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;

    // get length of n

    ll length = 0;
    ll temp = n;
    for (int i = 0; temp > 0; i++)
    {
        temp = temp / 10;
        length++;
    }

    // get sum of digits of n

    ll cur;

    cur = n % static_cast<ll>(pow(10, (length + 1) / 2));
    cur = max(cur, n / static_cast<ll>(pow(10, (length - 1) / 2)))
    
    while (true)
    {
        cur -= 1;
        
    }
    
}