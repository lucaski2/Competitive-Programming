#include <bits/stdc++.h>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;


void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  int mx = 1e3 + 5;
  
  vector<vector<int>> amount(mx, vector<int>(mx));
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    amount[a][b] += a * b;
  }

  vector<vector<int>> psum(mx, vector<int>(mx));
  for (int i = 1; i < mx; i++)
  {
    for (int j = 1; j < mx; j++)
    {
      psum[i][j] = amount[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
    }
  }

  for (int i = 0; i < q; i++)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a++; b++;
    c--; d--;
    cout << psum[c][d] - psum[a - 1][d] - psum[c][b - 1] + psum[a - 1][b - 1] << '\n';
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