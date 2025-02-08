#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1e9 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}
const ll mxn = 1e6 + 5;
vector<ll> fact(mxn, 1);


 
// To compute x^y under modulo m
ll power(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}

ll modInverse(ll a, ll m)
{
    return power(a, m - 2, m);
}


void fill()
{
  for (ll i = 1; i < mxn; i++)
  {
    // if (fact[i - 1] == 0)
    // {
    //   fact[i] = fact[i - 2] * (i - 1) * i % mod;
    // }
    // else fact[i] = fact[i - 1] * i % mod;
    fact[i] = fact[i - 1] * i % mod;
  }
  
}

void solve()
{
  ll a, b;
  cin >> a >> b;
  ll am = fact[a] * (ll)modInverse(fact[b] * fact[a - b]% mod, mod) % mod;
  cout << am % mod << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  fill();
  while (t--)
  {
      solve();
  }
}