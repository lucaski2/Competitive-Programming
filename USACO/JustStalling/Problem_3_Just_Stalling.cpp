#include <bits/stdc++.h>
#define int long long
#define double long double
#define all(a) a.begin(), a.end()
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

int fact(int n)
{
  int ret = 1;
  for (int i = 1; i <= n; i++)
    ret *= i;
  return ret;
}

void solve(int tc)
{
  int n;
  cin >> n;

  int ans = 1;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  
  sort(all(a), greater<int>());
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < n; j++)
      if (b[j] >= a[i]) cnt++;
    
    cnt -= i;
    ans *= cnt;
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