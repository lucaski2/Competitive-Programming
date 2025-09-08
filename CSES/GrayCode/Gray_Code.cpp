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

void conv(int num, int n)
{
  string ret = "";
  for (int i = n - 1; i >= 0; i--)
  {
    if (num & (1 << i))
    {
      ret += '1';
    }
    else ret += '0';
  }
  cout << ret << endl;
}

void solve(int tc)
{
  int n;
  cin >> n;
  vector<int> ans;
  vector<bool> visited((1 << n));
  function<void(int)> dfs = [&](int x)
  {
    visited[x] = true;
    ans.push_back(x);
    for (int ind = 0; ind < n; ind++)
    {
      if (!visited[(1 << ind) ^ x])
      {
        dfs((1 << ind) ^ x);
      }  
    }
  };
  dfs(0);
  for (int el : ans)
  {
    conv(el, n);
  }
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