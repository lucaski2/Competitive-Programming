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
  ifstream cin("reduce.in");
  ofstream cout("reduce.out");
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  multiset<int> x;
  multiset<int> y;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first >> a[i].second;
    x.insert(a[i].first);
    y.insert(a[i].second);
  }
  int ans = INT32_MAX;
  for (int i = 0; i < n; i++)
  {
    x.erase(x.find(a[i].first));
    y.erase(y.find(a[i].second));
    ans = min(ans, (*x.rbegin() - *x.begin()) * (*y.rbegin() - *y.begin()));

    x.insert(a[i].first);
    y.insert(a[i].second);

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