#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int mx = 6e5;
  vector<int> factorial(mx + 5, 1);
  for (int i = 1; i < mx; i++)
  {
    factorial[i] = (factorial[i - 1] * i) % x;
  }
  int s = 0;
  for (int i = 0; i < n; i++)
  {
    s += factorial[a[i]];
  }
  s %= x;
  cout << s << endl;
  cout << (s == 0 ? "YES" : "NO") << endl;


}