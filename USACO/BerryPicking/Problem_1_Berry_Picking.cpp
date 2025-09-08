#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second
#define iter(i, n) for (int i = 0; i < n; i++)

using namespace std;

using vi = vector<int>;


using namespace __gnu_pbds;


template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';


int pow(int a, int b, int m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}


void solve(int tc)
{ 
  ifstream cin("berries.in");
  ofstream cout("berries.out");
  int n, k;
  cin >> n >> k;
  int ans = 0;
  vector<int> a(n);
  iter(i, n) cin >> a[i];

  // basket size
  for (int i = 1; i <= 1000; i++)
  {
    vector<int> cur = a;
    vector<int> baskets;
    int cnt_max = 0;

    iter(j, n)
    {
      while (cur[j] > 0)
      {
        baskets.push_back(min(cur[j], i));
        cur[j] -= min(cur[j], i);
      }
      if (cnt_max >= k) break;
    }
    sort(baskets.begin(), baskets.end());
    int cnt = 0;
    while (!baskets.empty() and cnt < k / 2)
    {
      baskets.pop_back();
      cnt++;
    }
    cnt = 0;
    int cur_am = 0;
    while (!baskets.empty() and cnt < k / 2)
    {
      cur_am += baskets.back();
      baskets.pop_back();
      cnt++;
    }
    ans = max(ans, cur_am);
  }
  cout << ans << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}