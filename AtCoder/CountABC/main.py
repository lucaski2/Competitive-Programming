'''
void solve(int tc)
{
  int n;
  cin >> n;
  int ans = (n - 1) * n / 2 + n;

  int a = 1;
  
  while (a <= n)
  {
    int l = a, r = n;
    int best = a;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (n / mid != n / a) r = mid - 1;
      else 
      {
        best = mid;
        l = mid + 1;
      }

      // break;
    }

    ans -= (best - a + 1) * (n / a);
    a = best + 1;
    // break;
  }
  
  cout << ans << endl;
}
'''


n = int(input())

ans = (n - 1) * n // 2 + n

a = 1

while (a <= n):
  l, r = a, n
  while (l <= r):
    mid = (l + r) // 2
    if (n // mid != n // a):
      r = mid - 1
    else:
      l = mid + 1
      best = mid
  ans -= (best - a + 1) * (n // a)
  a = best + 1
print(ans % 998244353)
