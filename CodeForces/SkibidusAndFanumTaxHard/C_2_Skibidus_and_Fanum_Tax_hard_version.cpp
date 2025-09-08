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
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int j = 0; j < m; j++)
    cin >> b[j];

  // if (tc != 3) return;
  
  sort(b.begin(), b.end());
  int last = INT32_MIN;
  for (int i = 0; i < n; i++)
  {
    // choose minimum greater than last
    int l = 0, r = m - 1;
    int lowest = INT32_MAX;
    while (l <= r)
    { 
      int mid = (l + r) / 2;
      int am = b[mid] - a[i];

      if (am >= last)
      {
        lowest = min(am, lowest);
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    int am1 = a[i];
    int am2 = lowest;
    if (lowest == INT32_MAX) am2 = a[i];
    if (min(am1, am2) >= last)
    {
      a[i] = min(am1, am2);
    }
    else a[i] = max(am1, am2);

    // cout << am1 << ' ' << am2 << ' ' << last << endl;

    if (a[i] < last)
    {
      cout << "NO" << endl;
      return;
    }

    last = a[i];

  }
  cout << "YES" << endl;
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