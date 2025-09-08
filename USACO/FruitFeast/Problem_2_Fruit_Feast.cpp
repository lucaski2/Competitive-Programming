#include <bits/stdc++.h>
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
  ifstream cin("feast.in");
  ofstream cout("feast.out");
  int n, a, b;
  cin >> n >> a >> b;
  
  vector<bool> cur(n + 1);
  vector<bool> used(n + 1);
  cur[0] = true;

  for (int i = 0; i <= n; i++)
  {
    if (!cur[i]) continue;

    used[i / 2] = true;
    if (i + a <= n)
    {
      cur[i + a] = true;
    }
    if (i + b <= n)
    {
      cur[i + b] = true;
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++)
  {
    if (!used[i])
      continue;
    ans = i;
    if (i + a <= n) used[i + a] = true;
    if (i + b <= n) used[i + b] = true;
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