#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll mod = 1000000000 + 7;
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
  string s;
  cin >> s;
  ll n;
  n = s.size();

  map<ll, ll> cnts;
  mod = 2019;
  cnts[0] = 1;
  int pw = 1;
  int ans = 0;
  int num = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    num += (s[i] - '0') * pw;
    num %= mod;

    ans += cnts[num];
    cnts[num]++;
    
    pw = pw * 10 % mod;
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