#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  int l = 0, r = 1e18;
  int ans = INT64_MAX;
  while (l <= r)
  {
    int mid = (l + r) / 2;

    int am = 0;
    for (int i = 0; i < n; i++)
    {
      am += mid / a[i];
      if (am >= k) break;
    }
    if (am >= k)
    {
      r = mid - 1;
      ans = min(ans, mid);
    }
    else l = mid + 1;
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