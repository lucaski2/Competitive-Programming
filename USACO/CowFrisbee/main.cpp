#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;

template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    set<ll> avail;
    for (ll i = 0; i < n; i++) avail.insert(i);
    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        ll cur_height, ind;
        tie(cur_height, ind) = a[i];
        avail.erase(ind);
        auto l = less_or_equal(avail, ind);
        auto r = avail.upper_bound(ind);  
        if (l != nullopt)
        {
            ans += (ind - l.value()) + 1;
        }
        
        if (r != avail.end())
        {
            ans += (*r - ind) + 1;
        }
        
    }
    cout << ans << endl;



}
