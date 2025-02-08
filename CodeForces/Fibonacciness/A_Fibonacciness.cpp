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
  vector<int> a(5);
  cin >> a[0] >> a[1] >> a[3] >> a[4];
  int ans = 0;
  for (int i = -100; i < 100; i++)
  {
    a[2] = i;
    int cnt = 0;
    for (int j = 0; j < 3; j++)
    {
      if (a[j] + a[j + 1] == a[j + 2]) cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans << en;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}