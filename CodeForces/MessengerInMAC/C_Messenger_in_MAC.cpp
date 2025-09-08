#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
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

bool comp(pair<int, int> &a, pair<int, int> &b)
{
  return (a.s != b.s ? a.s < b.s : a.f > b.f);
}

void solve(int tc)
{
  int n, c;
  cin >> n >> c;

  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].f >> a[i].s;
  
  sort(a.begin(), a.end(), comp);

  vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1, {-1, -1}));

  dp[0][0] = {c, -1};

  // maximize c
  // if dp[i][j] is not already possible, replace with the current cost and the number
  // pair a is better than pair b if 
  // (b[a] - b[b]) > (p[b] - p[a])
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      dp[i + 1][j] = dp[i][j];
    }

    for (int j = 0; j < n; j++)
    { 
      
      if (dp[i][j].f < 0) continue;

      pair<int, int> cur = {0, 0};

      if (j == 0)
      {
        // first one
        cur.f = dp[i][j].f - a[i].f;
      }
      else 
      {
        cur.f = dp[i][j].f - a[i].f - (a[i].s - dp[i][j].s);
      }

      cur.s = a[i].s;
      if (cur.f < 0) continue;

      if (dp[i + 1][j + 1].first < 0)
      {
        dp[i + 1][j + 1] = cur;
        continue;
      }
      // up to here works

      // compare
      bool repl = false;
      if (dp[i + 1][j + 1].f >= cur.f)
      {
        repl = ((dp[i + 1][j + 1].f - cur.f) < (cur.s - dp[i + 1][j + 1].s));
      }
      if (dp[i + 1][j + 1].f < cur.f)
      {
        repl = ((cur.f - dp[i + 1][j + 1].f) > (dp[i + 1][j + 1].s - cur.s));
      }
      if (repl)
      {
        dp[i + 1][j + 1] = cur;
      }
    }
  }

  // cout << dp[n][1].first << ' ' << dp[n][1].second << endl;



  for (int i = n; i >= 0; i--)
  {
    if (dp[n][i].first >= 0)
    {
      // cout << dp[n][i].first << ' ' << dp[n][i].second << ' ';
      cout << i << endl;
      return;
    }
  }
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