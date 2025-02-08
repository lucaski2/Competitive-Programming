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
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int t = 0; t < 32; t++)
  {
    bool ok = true;
    ll m = -mod;

    for (int i = 0; i < n; i++)
    {
      ll s = 0;
      for (int j = 0; j < t; j++)
      {
        s += (1 << j);
      }

      if (a[i] + s < m)
      {
        ok = false;
      }
      // cout << s << ' ' << a[i] << ' ' << m << endl;
      m = max(m, a[i]);
    }
    if (ok)
    {
      cout << t << endl;
      return;
    }


  }




}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  for (ll i = 1; i <= t; i++)
  {
    solve(i);
  }
}