#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<ll, ll> counts;
    ll ans = 0;
    ll cur_s = 0;
    for (int i = 0; i <= n; i++)
    {
        if (counts.find(cur_s - k) != counts.end())
        {
            ans += counts[cur_s - k];
        }
        counts[cur_s]++;
        cur_s += a[i];
    }
    cout << ans << endl;


}
