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

// void find_max()
// {
//   for (ll i = 0; i < 1e10; i++)
//   {
//     if (1 + i + i * i > 1e18)
//     {
//       cout << i << endl;
//       return;
//     }
//     if (i % 100000 == 0)
//     {
//       cout << "Checkpoint" << i / 100000 << endl;
//     }
//   }
// }

void solve()
{
  ll n;
  cin >> n;

  ll l = 2;
  ll r = 1e9;

  while (l <= r)
  {
    ll mid = (l + r) / 2;
    ll am = 1 + mid + mid * mid;
    cout << am << endl;
    if (am == n)
    {
      cout << "YES" << endl;
      return;
    }
    else if (am > n)
    {
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  cout << "NO" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}