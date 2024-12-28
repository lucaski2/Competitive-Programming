#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n, a, b;
  cin >> n >> a >> b;
  int g = gcd(a, b);

  vector<int> c(n);
  for (int i = 0; i < n; i++)
  {
    cin >> c[i];
    c[i] %= g;
  }

  sort(c.begin(), c.end());
  int ans = c[n - 1] - c[0];

  for (int i = 1; i < n; i++)
  {
    ans = min(ans, c[i - 1] + g - c[i]);
  }
  cout << ans << en;






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