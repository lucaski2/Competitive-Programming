#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
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
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  // 2d dp???
  // either let everything pass or shift everything to the right by 1
  // you can go from 2d dp to vector<vector<int>> (n, vector<int>(2))
  // because truthers must be every other 

  vector<map<pair<int, bool>, int>> dp(n + 1);

  // key: liars, is_true

  dp[1][{1, false}]++;
  if (a[0] == 0)
  {
    dp[1][{0, true}]++;
  }

  for (int i = 1; i < n; i++)
  {
    for (auto it : dp[i])
    {
      int liars = it.first.first;
      bool is_true = it.first.second;
      int combs = it.second;

      if (is_true)
      {
        // push truth and lie
        // truth
        if (a[i] == liars)
        {
          dp[i + 1][{liars, true}] += combs;
          dp[i + 1][{liars, true}] %= mod;
        }
        dp[i + 1][{liars + 1, false}] += combs;
        dp[i + 1][{liars + 1, false}] %= mod;
      }
      else
      {
        // only push truth
        if (a[i] == liars)
        {
          dp[i + 1][{liars, true}] += combs;
          dp[i + 1][{liars, true}] %= mod;
        }
      }
    }
  }
  int ans = 0;
  for (auto it : dp[n])
  {
    ans += it.second;
  }
  cout << ans % mod << endl;




}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}