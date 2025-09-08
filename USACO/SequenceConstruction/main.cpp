#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';



void solve()
{
  int n, k;
  cin >> n >> k;

  if (n % 2 == k % 2)
  {
    int am = (1 << k) - 1;
    if (am > n)
    {
      cout << "-1" << endl;
    }
    else 
    {
      cout << 3 << endl;
      cout << am << ' ' << (n - am) / 2 << ' ' << (n - am) / 2 << endl;
    }
    return;
  }
  else
  {
    int am = (1 << k) - 1;
    n -= am;
    n -= 3;
    if (n < 0)
    {
      n += am;
      n += 3;
      if (__builtin_popcount(n) == k)
      {
        cout << 1 << endl;
        cout << n << endl;
      }
      else 
        cout << -1 << endl;
      return;
    }
    cout << 5 << endl;
    cout << am << ' ' << 1 << ' ' << 2 << ' ' << n / 2 << ' ' << n / 2 << endl;

  }


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}
