#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

ll pow(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}



void solve(ll tc)
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  ll l = 0; ll r = n / 2;
  ll ans = 0;
  while (l <= r)
  {
    ll mid = (l + r) / 2;
    bool ok = true;
    for (int i = 0; i < mid; i++)
    {
      if (a[i] * 2 > a[n - mid + i])
      {
        ok = false;
      }
    }
    if (ok)
    {
      ans = max(ans, mid);
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  for (ll i = 1; i <= t; i++)
  {
    solve(i);
  }
}