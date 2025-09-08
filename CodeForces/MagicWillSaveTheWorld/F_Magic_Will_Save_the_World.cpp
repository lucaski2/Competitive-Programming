#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

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
  int w, f;
  cin >> w >> f;

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int l = 1, r = 1e6;
  int ans = INT_MAX;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    int water = mid * w;
    int fire = mid * f;
    if (fire > 1e6 or water > 1e6)
    {
      ans = min(ans, mid);
      r = mid - 1;
      continue;
    }
    // maximize the amount of fire that can be used
    
    vector<bool> dp(fire + 1);
    dp[0] = true;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
      vector<bool> cur(fire + 1);
      for (int j = 0; j <= fire; j++)
      {
        if (dp[j] and j + a[i] <= fire)
        {
          cur[j + a[i]] = true;
          m = max(m, j + a[i]);
        }
        cur[j] = max(dp[j], cur[j]);
      }
      dp = cur;
    }
    // cout << m << endl;

    int s = accumulate(a.begin(), a.end(), -m);
    if (water >= s)
    {
      ans = min(ans, mid);
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  // cout << endl;
} 

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}