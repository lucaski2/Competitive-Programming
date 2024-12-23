#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = pow(10, 9) + 7;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  string s;
  cin >> s;
  int n = s.size();
  int running_sum = 0;
  // .first is number of numbers .second is sum of indexes
  map<int, int> prev_sums;

  int ans = 0;
  for (int i = 0; i < n; i++)
  {

    if (prev_sums.find(running_sum) == prev_sums.end())
    {
      prev_sums[running_sum] = i;
      running_sum += s[i] == '1' ? 1 : -1;

    }
    else
    {
      prev_sums[running_sum] += i;
      int am1 = prev_sums[running_sum] - i;
      int am2 = n - i;
      ans += am1 * am2;
      ans %= mod;
    }
  }
  cout << ans << endl;
  
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