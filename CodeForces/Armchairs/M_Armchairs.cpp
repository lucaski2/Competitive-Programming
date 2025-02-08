#include <bits/stdc++.h>
#define int long long
using namespace std;

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
  vector<bool> a(n);
  int open_chairs = n;
  int people = 0;
  
  vector<int> open, close;
  
  for (int i = 0; i < n; i++)
  {
    char c;
    cin >> c;
    a[i] = c == '1';
    open_chairs -= a[i];
    if (!a[i])
    {
      open.push_back(i);
    }
    else
    {
      close.push_back(i);
    }
  }
  people = n - open_chairs;

  vector<vector<int>> dp(people + 1, vector<int>(open_chairs + 1, INT_MAX));
  
  dp[0][0] = 0;
  
  for (int i = 0; i < people; i++)
  {
    int am = INT_MAX;
    for (int j = 0; j <= open_chairs; j++)
    {
      if (i < j)
      {
        dp[i + 1][j] = am + abs(close[i] - open[j - 1]);
      }
      am = min(am, dp[i][j]);
    }
  }

  // if (people == 0)
  // {
  //   cout << 0 << endl;
  //   return;
  // }


  cout << *min_element(dp[people].begin(), dp[people].end()) << endl;



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