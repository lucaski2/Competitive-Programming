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
  int mx = 1e5 + 5;
  vector<int> cnts(mx);

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    cnts[a]++;
  }

  vector<int> dp(mx + 1);
  for (int i = 0; i < mx; i++)
  {
    dp[i + 2] = max(dp[i + 2], dp[i] + cnts[i] * i);
    dp[i + 1] = max(dp[i + 1], dp[i]);
  }
  cout << dp[mx];


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