#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';

unordered_map<int, int> ans;

bool ipr(int n)
{
  if (ans.find(n) != ans.end()) return ans[n];
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0) 
    {
      ans[n] = false;
      return false;
    }
  }
  ans[n] = true;
  return true;
}

void solve(int tc)
{
  int n;
  cin >> n;
  if (n == 1)
  {
    cout << 2 << en;
    return;
  }

  for (int i = n + (n % 2 ? 2 : 1); ; i += 2)
  {
    if (ipr(i)) 
    {
      cout << i << en;
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