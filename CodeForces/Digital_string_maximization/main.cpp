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

  for (int i = 0; i < n; i++)
  {
    int m = i;
    for (int j = i + 1; j < min(n, i + 10); j++)
    {
      if (s[j] - j + i > s[m] - m + i)
      {
        m = j;
      }
    }
    for (int j = m; j > i; j--)
    {
      int temp = s[j];
      s[j] = s[j - 1];
      s[j - 1] = temp;
      int cur = s[j - 1] - '0';
      cur--;
      s[j - 1] = '0' + cur;
    }
  }
  cout << s << en;


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