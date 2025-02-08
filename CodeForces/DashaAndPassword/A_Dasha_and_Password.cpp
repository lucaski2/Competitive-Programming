#include <bits/stdc++.h>
#define int long long
using namespace std;

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
  vector<string> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int ans = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        if (i != k and i != j and j != k) {}
        else continue;
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        int am1 = INT_MAX;
        for (int x = 0; x < m; x++)
        {
          if (count(alphabet.begin(), alphabet.end(), a[i][x]))
          {
            am1 = min(min(x, m - x), am1);
          }
        }
        int am2 = INT_MAX;
        alphabet = "1234567890";
        for (int x = 0; x < m; x++)
        {
          if (count(alphabet.begin(), alphabet.end(), a[j][x]))
          {
            am2 = min(min(x, m - x), am2);
          }
        }
        int am3 = INT_MAX;
        alphabet = "#*&";
        for (int x = 0; x < m; x++)
        {
          if (count(alphabet.begin(), alphabet.end(), a[k][x]))
          {
            am3 = min(min(x, m - x), am3);
          }
        }
        
        ans = min(ans, am1 + am2 + am3);

      }
    }
  }

  cout << ans << endl;

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