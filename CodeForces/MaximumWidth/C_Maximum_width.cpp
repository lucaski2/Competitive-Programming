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
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  // find first for each one
  int cur = 0;
  
  vector<int> inds(m);
  for (int i = 0; i < n; i++)
  {
    if (cur < m and s[i] == t[cur])
    {
      cur++;
      inds[cur - 1] = i;
    }
  }
  cur = m - 1;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (cur >= 0 and t[cur] == s[i])
    {
      // cout << i - inds[cur] << endl;
      cur--;
      if (cur >= 0) ans = max(ans, i - inds[cur]);
    }
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