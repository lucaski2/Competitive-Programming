#include <bits/stdc++.h>
#define int long long
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;

const char en = '\n';



int mod = 2203939;
int pow(int a, int b, int m){ int ans = 1; while(b) { if (b&1) ans = (ans*a) % m; b /= 2; a = (a*a) % m; } return ans; }



void solve(int tc)
{
  ifstream cin("cownomics.in");
  ofstream cout("cownomics.out");
  int n, m;
  cin >> n >> m;

  vector<int> precomp(m, 1);
  int k = 4;
  for (int i = 1; i < m; i++)
    precomp[i] = precomp[i - 1] * 4 % mod;
  
  vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char c;
      cin >> c;
      if (c == 'A') a[i][j] = 0;
      else if (c == 'C') a[i][j] = 1;
      else if (c == 'T') a[i][j] = 2;
      else a[i][j] = 3;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char c;
      cin >> c;
      if (c == 'A') b[i][j] = 0;
      else if (c == 'C') b[i][j] = 1;
      else if (c == 'T') b[i][j] = 2;
      else b[i][j] = 3;
    }
  }

  vector<bool> hash(mod);

  int ans = INT_MAX;
  for (int i = 0; i < m; i++)
  {
    vector<int> hashes1(n);
    vector<int> hashes2(n);
    for (int j = i; j < m; j++)
    {
      for (int l = 0; l < n; l++)
      {
        hashes1[l] += a[l][j] * precomp[j];
        hashes1[l] %= mod;
        hash[hashes1[l]] = true;
      }
      bool ok = true;
      for (int l = 0; l < n; l++)
      { 
        hashes2[l] += b[l][j] * precomp[j];
        hashes2[l] %= mod;
        if (hash[hashes2[l]]) ok = false;
      }
      for (int l = 0; l < n; l++)
        hash[hashes1[l]] = false;
      if (ok)
      {
        ans = min(ans, j - i + 1);
        break;
      }
      
    }
  }


  cout << ans << en;

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