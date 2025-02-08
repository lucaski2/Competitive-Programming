#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here: https://codeforces.com/contest/1495/problem/A
// Start time here: 7:18
// End time here: 7:31

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

double dist(int d1, int d2)
{
  return sqrt((double)(d1 * d1 + d2 * d2));
}

void solve(int tc)
{
  int n;
  cin >> n;
  vector<int> a;
  vector<int> b;

  for (int i = 0; i < n * 2; i++)
  {
    int x, y;
    cin >> x >> y;
    if (x == 0)
    {
      b.push_back(abs(y));
    }
    else a.push_back(abs(x));
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  double ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += dist(a[i], b[i]);
  }
  cout << ans << endl;



}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  cout << setprecision(15);
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}