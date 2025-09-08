#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;
using namespace __gnu_pbds;

template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';


void solve(int tc)
{
  int n, k;
  cin >> n >> k;
  int x, a, b, c;
  cin >> x >> a >> b >> c;

  vector<int> d(n);
  d[0] = x;
  for (int i = 1; i < n; i++)
  {
    d[i] = (d[i - 1] * a + b) % c;
  }
  int ans = 0;

  for (int i = 0; i < 32; i++)
  {
    int run = 0;
    for (int j = 0; j < k; j++)
      run += (((1 << i) & d[j]) > 0);
    int s = (run > 0);
    for (int j = k; j < n; j++)
    {
      run += (((1 << i) & d[j]) > 0);
      run -= (((1 << i) & d[j - k]) > 0);
      s ^= (run > 0);
    }
    ans += (1 << i) * s;
  }
  cout << ans << en;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}