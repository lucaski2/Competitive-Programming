#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  // sum of elements must be greater than a and less than k

  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];
  ll s = accumulate(a.begin(), a.end(), 0);
  if (s <= x)
  {
    cout << 0 << endl;
    return;
  }

  sort(a.begin(), a.end());
  ll temp = x;
  x = s - y;
  y = s - temp;
  ll ans = 0;
  for (ll i = 0; i < n; i++)
  {
    auto l_bound = lower_bound(a.begin(), a.begin() + i, x - a[i]);
    auto u_bound = upper_bound(a.begin(), a.begin() + i, y - a[i]);
    u_bound = prev(u_bound);

    if (l_bound <= u_bound)
    {
      ll in = ans;
      ans += u_bound - l_bound + 1;
      // if (a[i] * 2 >= x && a[i] * 2 <= y)
      //   ans--;
      // cout << ans - in << ' ' << i << endl;
    }
  }

  cout << ans << endl;
  // cout << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // ll t;
  // cin >> t;
  // while (t--)
  // {
  //     solve();
  // }
}