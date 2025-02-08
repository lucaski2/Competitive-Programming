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
  ll n, s;
  cin >> n >> s;
  vector<ll> a(2 * n);
  ll su = 0;
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
    a[n + i] = a[i];
    su += a[i];
  }

  s %= su;

  if (s == 0)
  {
    cout << "Yes" << endl;
    return;
  }
  set<ll> prev;
  prev.insert(0);
  ll run = 0;
  for (ll i = 0; i < 2 * n; i++)
  {
    
    run += a[i];
    if (prev.find(run - s) != prev.end())
    {
      cout << "Yes" << endl;
      return;
    }
    prev.insert(run);
  }

  cout << "No" << endl;


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