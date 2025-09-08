#include <bits/stdc++.h>

// #pragma GCC target ("avx,avx2,fma")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second
 
using namespace std;

 
 
int mod = 5;
 

 

void solve(int tc)
{
  int n, q;
  cin >> n >> q;
 
  vector<int> g(n);
  vector<int> r(n);
 
  int sz = sqrtl(n);
 
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    a--;
    g[i] = a;
    r[a] = i;
  }
 
  vector<int> ptrs(n);
 
  for (int i = 0; i < n; i++)
  {
    int cur = i;
    for (int j = 0; j < sz; j++)
    {
      cur = g[cur];
    }
    ptrs[i] = cur;
  }
 
  while (q--)
  {
    int t;
    cin >> t;
 
    if (t == 2)
    {
      int i, k;
      cin >> i >> k;
      i--;
      while (k >= sz)
      {
        i = ptrs[i];
        k -= sz;
      }
      while (k--)
      {
        i = g[i];
      }
      cout << i + 1 << endl;
    }
    else
    {
      int i, j;
      cin >> i >> j;
      i--; j--;
 
      // the thing pointing to element x doesnt change
      // int l = g[i];
      // int r = g[j];
      swap(r[g[i]], r[g[j]]);
      swap(g[i], g[j]);
      
      // r[g[i]] = i;
      // r[g[j]] = j;
 
      function<void(int)> reset = [&](int cur)
      {
        int ptr = cur;
        for (int c = 0; c < sz - 1; c++)
        {
          ptr = r[ptr];
        }
        int ptr2 = ptr;
        for (int c = 0; c < sz; c++)
          ptr2 = g[ptr2];
 
        for (int c = 0; c < sz; c++)
        {
          ptrs[ptr] = ptr2;
          ptr = g[ptr];
          ptr2 = g[ptr2];
        }
      };
 
      reset(i);
      reset(j);
    }
  }
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