#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].first >> a[i].second;

  int l = 0, r = n;
  int ans = 0;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    int cur_left = 0, cur_right = mid - 1;
    for (int i = 0; i < n; i++)
    {
      if (a[i].second >= cur_left and a[i].first >= cur_right)
      {
        cur_left++;
        cur_right--;
      }
      if (cur_right < 0) break;
    }
    if (cur_right < 0)
    {
      l = mid + 1;
      ans = max(ans, mid);
    }
    else r = mid - 1;
  }
  cout << ans << endl;
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