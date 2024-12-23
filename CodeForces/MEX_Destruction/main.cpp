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
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int s = 0;
  if (accumulate(a.begin(), a.end(), 0) == 0)
  {
    cout << 0 << endl;
    return;
  }
  // 1 operation
  bool started = false;
  bool ended = false;
  bool ok = true;
  for (int num : a)
  {
    if (num != 0 and not started)
    {
      started = true;
    }
    else if (num == 0 and started and not ended)
    {
      ended = true;
    }
    else if (num != 0 and ended)
    {
      ok = false;
    }
    else
    {

    }
  }
  if (ok) cout << 1 << endl;
  else cout << 2 << endl;


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