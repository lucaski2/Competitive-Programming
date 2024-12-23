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


  int ans = 0;
  for (int i = 0; i <= n; i++)
  {
    bool ok = true;
    int num1 = n;
    int num2 = i;
    for (int j = 1; j <= k - 2; j++)
    {
      int temp = num1;
      num1 = num2;
      num2 = temp - num1;
      ok = min(ok, num1 >= num2);
      ok = min(ok, min(num1, num2) >= 0);
      if (!ok) break;
    }
    ans += min(ok, true);
  }
  cout << ans << en;

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