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
  if (n == 1)
  {
    if (k == 0)
    {
      cout << 1 << endl;
    }
    else cout << "-1" << endl;
    return;
  }

  int min_pos = n / 2;
  if (min_pos > k)
  {
    cout << -1 << endl;
    return;
  }

  else if (k == min_pos)
  {
    for (int i = 2; i <= n + 1; i++)
    {
      cout << i << ' ';
    }
    cout << endl;
    return;
  }
  else
  {
    int num1_gcd = k - (n - 2) / 2;
    cout << num1_gcd << ' ' << num1_gcd * 2 << ' ';
    for (int i = 1; i <= n - 2; i++)
    {
      cout << num1_gcd * 2 + i << ' ';
    }
    cout << endl;
    return;
  }



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
