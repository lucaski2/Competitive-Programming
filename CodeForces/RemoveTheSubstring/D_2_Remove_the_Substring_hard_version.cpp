#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';



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
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  // if (s != "baaba") return;
  vector<int> earliest(m);
  for (int i = 0, j = 0; i < n; i++)
  {
    if (j < m and s[i] == t[j])
    {
      earliest[j] = i;
      j++;
    }
  }

  vector<int> latest(m);
  for (int i = n - 1, j = m - 1; i >= 0; i--)
  {
    if (j >= 0 and s[i] == t[j])
    {
      latest[j] = i;
      j--;
    }
  }

  int ans = latest[0];
  ans = max(ans, n - earliest[m - 1] - 1);
  for (int i = 0; i < m - 1; i++)
  {
    // cout << latest[i] - earliest[i] << endl;
    ans = max(ans, latest[i + 1] - earliest[i] - 1);
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