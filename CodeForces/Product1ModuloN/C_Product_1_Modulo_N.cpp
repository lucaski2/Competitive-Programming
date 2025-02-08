#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n;
  cin >> n;
  ll p = 1;
  for (int i = 1; i < n; i++)
  {
    if (gcd(i, n) == 1)
    {
      p *= i;
      p %= n;
    }
  }
  vector<int> ans;
  for (int i = 1; i < n; i++)
  {
    if (gcd(i, n) == 1 and (i != p or p == 1))
    {
      ans.push_back(i);
    }
  }
  // cout << p << endl;
  cout << ans.size() << endl;
  for (int a : ans)
  {
    cout << a << ' ';
  }
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--)
  {
      solve();
  }
}