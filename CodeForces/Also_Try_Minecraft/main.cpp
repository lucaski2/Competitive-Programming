#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n, m;
  // cin >> n >> m;
  // vector<int> a(n);
  // vector<int> pref1(n);
  // vector<int> pref2(n);
  // for (int i = 1; i < n; i++)
  // {
  //   cin >> a[i];
  //   pref1[i + 1] = a[i];
  //   pref2[i] = a[i];
  // }
  // for (int i = 0; i < n - 1; i++)
  // {
  //   pref1
  // }
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