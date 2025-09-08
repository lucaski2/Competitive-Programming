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
  vector<int> a(n);
  map<int, int> counts;
  
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    counts[a[i]]++;
  }

  int carried = 0;
  bool ok = true;
  
  for (int i = 1; i <= n; i++)
  {
    if (carried == 0 and counts.find(i) == counts.end()) continue;
    carried += counts[i] - 2;

    if (carried < 0) ok = false;
  }

  cout << (ok ? "YES" : "NO") << endl;

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