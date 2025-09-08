#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
#define all(a) a.begin(), a.end()

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
  ifstream cin("hps.in");
  ofstream cout("hps.out");
  int n, k;
  cin >> n >> k;
  
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(3, INT_MIN)));

  function<int(char)> enc = [&](char s)
  {
    if (s == 'P') return 0;
    else if (s == 'H') return 1;
    else return 2;
  };
  dp[0][0][0] = 0;
  dp[0][0][1] = 0;
  dp[0][0][2] = 0;
  for (int i = 0; i < n; i++)
  {
    char s;
    cin >> s;
    int a = enc(s);
    for (int j = 0; j <= k; j++)
    {
      for (int l = 0; l < 3; l++)
      {
        // change or nah
        dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l] + (l == a));
        if (j != k)
        {
          dp[i + 1][j + 1][a] = max(dp[i + 1][j + 1][a], dp[i][j][l] + 1);
        }
      }
    }
  }

  cout << *max_element(all(dp[n][k])) << endl;
  



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