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



void solve()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> ps(n + 1);
  for (ll i = 0; i < n; i++)
  {
    ll a; cin >> a;
    ps[i + 1] = ps[i] + a;
  }

  for (ll i = 0; i < q; i++)
  {
    ll l, r; cin >> l >> r;
    cout << ps[r] - ps[l] << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}