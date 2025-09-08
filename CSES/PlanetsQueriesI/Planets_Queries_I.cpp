#include <bits/stdc++.h>
// #pragma GCC target ("avx,avx2,fma")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
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



void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
  }

  int log = 30;
  vector<vector<int>> binlift(n, vector<int>(log));
  
  for (int i = 0; i < n; i++)
    binlift[i][0] = a[i];
  
  for (int i = 1; i < log; i++)
  {
    for (int j = 0; j < n; j++)
    {
      binlift[j][i] = binlift[binlift[j][i - 1]][i - 1];
    }
  }

  while (q--)
  {
    int a, b;
    cin >> a >> b;
    a--;

    for (int i = 0; i < log; i++)
    {
      if (b & (1 << i))
      {
        a = binlift[a][i];
      }
    }
    cout << a + 1 << en;
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