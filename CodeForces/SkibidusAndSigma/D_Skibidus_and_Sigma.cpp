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

bool comp(pair<vector<int>, int> &a, pair<vector<int>, int> &b)
{
  return a.second > b.second;
}

void solve(int tc)
{ 
  int n, m;
  cin >> n >> m;
  vector<pair<vector<int>, int>> a(n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int x;
      cin >> x;
      a[i].first.push_back(x);
      a[i].second += x;
    }
  }
  sort(a.begin(), a.end(), comp);
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int run = 0;
    for (int j = 0; j < m; j++)
    {
      ans += a[i].first[j] * ((n - i) * (m) - j);
    }
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