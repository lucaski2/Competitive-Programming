#include <bits/stdc++.h>
#define ll long long
#define mll 2147483647
#define mod (1000000007)
#define en '\n'
using namespace std;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}




void solve()
{
  std::ifstream cin("triangles.in");
  std::ofstream cout("triangles.out");
  ll n;
  cin >> n;
  vector<pair<ll, ll>> polls(n);

  
  unordered_map<ll, vector<ll>> x_axis;
  unordered_map<ll, vector<ll>> y_axis;
  for (ll i = 0; i < n; i++)
  {
    ll x, y;
    cin >> x >> y;
    polls[i].first = x;
    polls[i].second = y;
    if (x_axis.find(x) == x_axis.end())
      x_axis[x] = {y};
    else 
      x_axis[x].push_back(y);

    if (y_axis.find(y) == y_axis.end())
      y_axis[y] = {x};
    else
      y_axis[y].push_back(x);
  }
  ll ans = 0;
  for (ll i = 0; i < n; i++)
  {
    // consider if this is right angle
    vector<ll> v1 = x_axis[polls[i].first];
    vector<ll> v2 = y_axis[polls[i].second];
    
    ll s1 = 0;
    for (int a : v1)
    {
      s1 += abs(polls[i].second - a);
    }
    ll s2 = 0;
    for (int b : v2)
    {
      s2 += abs(polls[i].first - b);
    }
    // cout << s1 << endl;
    ans += s1 * s2 % mod;
    ans %= mod;

  }
  cout << ans % mod << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
