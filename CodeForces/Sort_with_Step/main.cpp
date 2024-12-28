#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] % k != i % k)
    {
      ans++;
    }
  }
  if (ans == 0) cout << 0 << endl;
  else cout << (ans == 2 ? 1 : -1) << en;
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