#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
using namespace std;

// Problem URL here: https://codeforces.com/problemset/problem/1359/C
// Start time here: 1:45
// End time here:

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
  int h, c, t;
  cin >> h >> c >> t;

  int l = 2;
  int r = INF;
  int best = 1;
  
  if (h == t)
  {
    cout << 1 << endl;
    return;
  }
  if (t <= (h + c) / 2.0)
  {
    cout << 2 << endl;
    return;
  }

  while (l <= r)
  {
    int mid = (l + r) / 2;
    double am = (h * mid + c * (mid - 1)) / ((double)(mid * 2 - 1));
    double bam = (h * best + c * (best - 1)) / ((double)(best * 2 - 1));
    double d1 = abs(am - t);
    double d2 = abs(bam - t);
    if (d1 < d2)
    {
      best = mid;
    }

    if (am < t)
    {
      r = mid - 1;
    }
    else l = mid + 1;
  }
  cout << best * 2 - 1 << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}