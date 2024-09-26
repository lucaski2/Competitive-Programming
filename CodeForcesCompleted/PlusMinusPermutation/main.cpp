#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

long long gcd(long long a, long long b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
long long lcm(long long a, long long b) 
{ 
    return (a / gcd(a, b)) * b; 
} 



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        
        ll x_amount = (ll) n / x;
        ll y_amount = (ll) n / y;
        // cout << x_amount << "   " << y_amount << endl;
        ll collisions = (ll) n / lcm(x, y);
        x_amount -= collisions;
        y_amount -= collisions;
        ll total = 0;
        
        ll amount_1 = (n * 2 - x_amount + 1) * ((double)x_amount / 2);

        // cout << amount_1 << endl;

        ll amount_2 = (1 + y_amount) * ((double)y_amount / 2);

        // cout << amount_2 << endl;
        total = amount_1 - amount_2;




        cout << total << endl;
    }
}


