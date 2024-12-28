#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

const int mxn = 1e5+5;

int a[mxn], temp[mxn];


void solve()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  




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