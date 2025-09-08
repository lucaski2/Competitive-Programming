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

// memoize used binary string, index

vector<int> get_factors(int n)
{
  vector<int> ret;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ret.push_back(i);
    }
    while (n % i == 0)
    {
      n /= i;
    }
  }
  if (n > 1) ret.push_back(n);

  return ret;
}


void solve(int tc)
{
  int n;
  cin >> n;
  vector<int> lengths(n), costs(n);
  for (int i = 0; i < n; i++)
    cin >> lengths[i];
  for (int i = 0; i < n; i++)
    cin >> costs[i];
  
  vector<vector<int>> factors(n);
  for (int i = 0; i < n; i++)
  {
    factors[i] = get_factors(lengths[i]);
  }
  // if (n != 3) return;

  int ans = INT32_MAX;

  for (int i = 0; i < n; i++)
  {
    if (lengths[i] == 1)
    {
      ans = min(ans, costs[i]);
      continue;
    }


    vector<int> cur_factors = factors[i];
    int m = cur_factors.size();
    int configs = (1 << m);
    // cout << configs << endl;
    vector<vector<int>> dp(n + 1, vector<int>(configs, INT32_MAX));
    dp[0][0] = 0;
    for (int j = 0; j < n; j++)
    {
      int cur_num = 0;
      for (int ind = 0; ind < m; ind++)
      {
        if (find(factors[j].begin(), factors[j].end(), cur_factors[ind]) == factors[j].end())
        {
          cur_num |= (1 << ind);
        }
      }

      for (int k = 0; k < configs; k++)
      {
        dp[j + 1][k] = dp[j][k];
      }
      for (int k = 0; k < configs; k++)
      {
        dp[j + 1][k | cur_num] = min(dp[j + 1][k | cur_num], dp[j][k] + costs[j]);
        // cout << dp[j + 1][k | cur_num] << ' ' << (k | cur_num) << ' ' << dp[j][k] + costs[j] << endl;
        // if ((k|cur_num) > configs) cout << (k | cur_num) << ' ' << configs << endl;
      }
    }

    ans = min(ans, dp[n][configs - 1] + costs[i]);
  }

  if (ans == INT32_MAX) cout << -1 << endl;
  else cout << ans << endl;

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