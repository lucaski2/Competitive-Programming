#include <bits/stdc++.h>
#define int long long
#define double long double
#define all(a) a.begin(), a.end()
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  vector<vector<bool>> dp(k + 1, vector<bool>(k + 1));
  dp[0][0] = 1;
  
  for (int i = 0; i < n; i++)
  {
    vector<vector<bool>> next = dp;
    for (int j = 0; j <= k; j++)
    {
      if (a[i] + j > k) continue;
      for (int l = 0; l <= k; l++)
      {
        if (l + a[i] > k) continue;
        // choice 1, dont do anything
        // choice 2 add to subset
        // choice 3 dont add to subset
        next[j + a[i]][l] = (next[j + a[i]][l] | dp[j][l]);
        next[j + a[i]][l + a[i]] = (next[j + a[i]][l + a[i]] | dp[j][l]);
      }
    }
    dp = next;
  }
  
  vector<int> ans;
  for (int i = 0; i <= k; i++)
    if (dp[k][i]) ans.push_back(i);
  
  cout << ans.size() << endl;
  for (int ele : ans)
    cout << ele << ' ';
  cout << endl;
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