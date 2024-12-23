#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < m; i++)
  {
    cin >> a[i];
  }

  set<int> s;

  for (int i = 1; i <= n; i++)
  {
    s.insert(i);
  }


  for (int i = 0; i < k; i++)
  {
    int x;
    cin >> x;
    s.erase(x);
  }

  for (int i = 0; i < m; i++)
  {
    bool ok = true;
    int num = a[i];
    for (int am : s)
    {
      if (am != num)
      { 
        ok = false;
        break;
      }
    }
    cout << (ok ? "1" : "0");
  }
  cout << en;


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