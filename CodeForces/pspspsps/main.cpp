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
  string a;
  cin >> a;
  int max_s = -1;
  int min_p = INT32_MAX;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 'p')
    {
      min_p = min(min_p, i);
    }
    if (a[i] == 's')
    {
      max_s = max(max_s, i);
    }
  }
  if (max_s > min_p)
  {
    cout << "NO" << endl;
    return;
  }
  if (a[0] == 's' and a[n - 1] == 'p' and count(a.begin(), a.end(), 's') + count(a.begin(), a.end(), 'p') <= 3)
  {
    cout << "YES" << endl;
  }
  else if (count(a.begin(), a.end(), 's') == 0 or count(a.begin(), a.end(), 'p') == 0)
  {
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
  
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