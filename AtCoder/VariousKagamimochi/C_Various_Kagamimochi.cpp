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
  sort(a.begin(), a.end(), greater<ll>());
  ll ans = 0;

  ll ptr = 1;
  for (ll i = 0; i < n; i++)
  {
    while (ptr < n and a[ptr] > a[i] / 2)
    {
      ptr++;
    }

    if (ptr < n)
    {
      ans += n - ptr;
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