#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const char en = '\n';


void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  reverse(all(a));

  int log = 30;
  vector<vector<int>> psum(log, vector<int>(n + 1));

  for (int i = 0; i < log; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if ((1 << i) & a[j]) psum[i][j + 1] = 1;
      psum[i][j + 1] += psum[i][j];
    }
  }

  while (q--)
  {
    int s;
    cin >> s;
    // if (tc != 3) continue;
    int ind = 0;
    bool ok = false;
    while (ind < n and s > 0 and !ok)
    {
      int lo = n;
      for (int mask = log - 1; mask >= 0; mask--)
      {
        int l = ind, r = n - 1;
        int best = ((1 << mask) & s ? n - 1 : n);
        while (l <= r)
        {
          int mid = (l + r) / 2;
          
          int am = psum[mask][mid + 1] - psum[mask][ind];
          if (am > 0)
          {
            best = min(best, mid);
            r = mid - 1;
          }
          else l = mid + 1;
        }
        if ((1 << mask) & s)
        {
          // cout << lo << ' ' << best << ' ' << s << endl;
          if (lo <= best)
          {
            ind = lo;
            ok = true;
          }
          else
          {
            
            for (int i = 0; i < log; i++)
            {
              s ^= (1 << i) * ((psum[i][best] - psum[i][ind]) % 2);
            }
            if (a[best] > s)
            {
              ind = best;
              ok = true;
            }
            else 
            {
              ind = best + 1;
              for (int i = 0; i < log; i++)
              {
                s ^= (1 << i) * ((psum[i][best + 1] - psum[i][best]) % 2);
              }
            }
          }
          break;
        }
        else lo = min(lo, best);
      }
    }
    cout << ind << ' ';
  }
  cout << en;

  

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