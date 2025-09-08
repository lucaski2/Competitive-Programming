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
  int n, x;
  cin >> n >> x;
  
  vector<int> dp(x + 1, 0);
  vector<int> cur(x + 1, 0);
  
  vector<int> prices(n);
  vector<int> pages(n);
  for (int i = 0; i < n; i++)
    cin >> prices[i];
  for (int i = 0; i < n; i++)
    cin >> pages[i];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < x; j++)
    {
      int am = j + prices[i];
      if (am > x) continue;
      cur[am] = max(cur[am], dp[j] + pages[i]);
    }
    dp = cur;

  }
  cout << *max_element(dp.begin(), dp.end()) << endl;

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