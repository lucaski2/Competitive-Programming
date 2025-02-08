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
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vector<ll> costs(n);
  for (ll i = 0; i < n; i++)
  {
    costs[i] = a[i] - (n - i - 1);
  }
  sort(costs.begin(), costs.end(), greater<ll>());

  ll ans = accumulate(a.begin(), a.end(), 0) - k * (k - 1) / 2;

  for (ll i = 0; i < k; i++)
  {
    ans -= costs[i];
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}