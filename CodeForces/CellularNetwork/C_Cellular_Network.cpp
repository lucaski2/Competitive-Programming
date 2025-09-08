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
  for (int i = 0; i < m; i++)
    cin >> b[i];
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int l = 0, r = 2e9;
  int ans = INT64_MAX;
  while (l <= r)
  {
    int rad = (l + r) / 2;
    
    multiset<int> nums;
    for (int i = 0; i < n; i++)
    {
      nums.insert(a[i]);
    }

    for (int i = 0; i < m; i++)
    { 
      auto ptr = nums.lower_bound(b[i] - rad);
      while (ptr != nums.end() and *ptr <= b[i] + rad)
      {
        nums.erase(ptr);
        ptr = nums.lower_bound(b[i] - rad);
      }
    }
    if (nums.empty())
    {
      r = rad - 1;
      ans = min(ans, rad);
    }
    else l = rad + 1;
  }
  cout << ans << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}