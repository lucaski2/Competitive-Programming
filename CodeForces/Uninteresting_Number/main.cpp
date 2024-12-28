#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  string s;
  cin >> s;
  int n = s.size();

  int num_6 = 0;
  int num_2 = 0;
  int m = 0;
  for (int i = 0; i < n; i++)
  {
    m += s[i] - '0';
    if (s[i] == '2')
    {
      num_2 += 1;
    }
    else if (s[i] == '3')
    {
      num_6 += 1;
    }
  }
  m %= 9;
  bool ok = false;
  for (int i = 0; i <= min(1000, num_2); i++)
  {
    for (int j = 0; j <= min(1000, num_6); j++)
    {
      if ((m + i * 2 + j * 6) % 9 == 0)
      {
        ok |= 1;
      }
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