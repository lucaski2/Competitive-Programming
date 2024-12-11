#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  // you can do it in 1 or 2
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  // simplify to a/b and c/d to get the same denominator
  ll x = a * d;
  ll y = b * c;
  a = x;
  b = y;
  if (a == b)
  {
    cout << "0\n";
    return;
  }
  if (a > b)
  {
    swap(a, b);
  }
  if (b % a == 0 || a == 0 || b == 0)
  {
    cout << 1 << en;
    return;
  }
  cout << 2 << en;


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