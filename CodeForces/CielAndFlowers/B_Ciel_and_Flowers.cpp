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
  int a, b, c;
  cin >> a >> b >> c;
  int ans = a / 3 + b / 3 + c / 3;
  int am1 = a % 3;
  int am2 = b % 3;
  int am3 = c % 3;
  if (am1 == 0) swap(am1, am3);
  if (am2 == 0) swap(am2, am3);
  if (am3 == 0 and (am1 > 0 and am2 > 0 and min(a, min(b, c)) != 0))
  {
    ans -= 1;
    ans += min(am1, am2);
  }
  else ans += min(am1, min(am2, am3));
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