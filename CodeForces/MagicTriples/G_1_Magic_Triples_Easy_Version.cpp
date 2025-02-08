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
const int mxn = 2e5+5;
ll a[mxn];
const int mx = 1e6 + 5;
ll counts[mx];

void solve()
{ 
  ll n;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    counts[a[i]]++;
  }
  

  for (int i = 0; i < n; i++)
  {
    int num = a[i];
    for (int b = 2; b * b * num <= mx; b++)
    {
      ans += counts[b * num] * counts[b * b * num];
    }
  }

  for (int i = 0; i < n; i++)
  {
    ans += max(0ll, counts[a[i]] * (counts[a[i]] - 1) * (counts[a[i]] - 2));
    counts[a[i]] = 0;
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