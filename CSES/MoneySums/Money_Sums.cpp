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
  int n;
  cin >> n;
  int mx = 1000*n;
  vector<bool> dp(mx + 1);
  vector<bool> cur(mx + 1);
  dp[0] = true;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    for (int j = 0; j <= mx; j++)
    {
      cur[j] = max(cur[j], dp[j]);
      int am = j + a;
      if (am > mx) continue;
      cur[am] = max(dp[am], dp[j]);
    }
    dp = cur;
  }
  vector<int> ans;
  for (int i = 1; i <= mx; i++)
  {
    if (dp[i]) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (int it : ans)
    cout << it << ' ';
  cout << endl;

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