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
  int n, m, k;
  cin >> n >> m >> k;
  if (n * m * 2 % k != 0 or k == 1)
  {
    cout << "NO" << endl;
    return;
  }

  int am = n * m * 2 / k;
  // x * y == am
  // x * y == n * m * 2 / k
  // 1: n * m == 12
  // n * m * 2 / k == 8
  // gcd 12, 8 = 4
  // 8 / 4 = 2
  bool odd = false;
  if (k % 2 == 0)
  {
    k /= 2;
  }
  else odd = true;
  int x = gcd(k, n);
  k /= x;
  x = n / x;
  int y = m / k;
  if (x != n and odd) x *= 2;
  else if (odd) y *= 2;
  

  cout << "YES" << endl;
  cout << 0 << ' ' << 0 << endl;
  cout << 0 << ' ' << y << endl;
  cout << x << ' ' << 0 << endl;



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