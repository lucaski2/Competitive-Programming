#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>ps(n + 1, 0);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i]; 
        // cout << ps[i] << ' ' << a[i] << ' ';
        ps[i + 1] = (ps[i] + a[i]);
        ps[i + 1] = ((ps[i + 1] % n) + n) % n;
        // cout << ps[i + 1] << " ";
        // cout << endl;
    }
    vector<ll> counts(n, 0);
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += counts[ps[i]];
        counts[ps[i]]++;
    }
    cout << ans << endl;
    
}



