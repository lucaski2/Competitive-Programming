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
  bool ok = false;
  for (int k = 2; k < n; k++)
  {
    if (1 + k + k * k > n)
    {
      break;
    }
    int val = 1;
    int mult = 1;
    while (val < n)
    {
      val += pow(k, mult);
      mult++;
    }
    if (val == n)
    {
      ok = true;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << en;

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