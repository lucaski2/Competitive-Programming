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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  int s = accumulate(a.begin(), a.end(), 0);
  
  int q;
  cin >> q;
  while (q--)
  {
    int x, y;
    cin >> x >> y;

    if (x > a.back())
    {
      int needed = x - a.back() + (max(0ll, y - (s - a.back())));
      cout << needed << endl;
      continue;
    }

    if (x < a[0])
    {
      int needed = max(0ll, y - (s - a[0]));
      continue;
    }
    int ind = upper_bound(a.begin(), a.end(), )

  }


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