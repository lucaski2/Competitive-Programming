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

  set<int> s;
  int m = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (s.find(a[i]) != s.end())
    {
      m = max(m, a[i]);
    }
    s.insert(a[i]);
  }
  if (m == 0)
  {
    cout << -1 << endl;
    return;
  }

  vector<int> b = a;
  // remove one m from b
  b.erase(find(b.begin(), b.end(), m));
  b.erase(find(b.begin(), b.end(), m));
  
  int diff = 2 * m;

  n -= 2;

  set<int> diffs;
  int min_diff = mod;
  pair<int, int> ans;
  for (int i = 0; i < n; i++)
  {
    
    auto it = less_or_equal(diffs, b[i]);
    auto it2 = diffs.lower_bound(b[i]);
    if (it != nullopt)
    { 
      int am = b[i] - *it;
      if (am < min_diff)
      {
        min_diff = am;
        ans = {*it, b[i]};
      }
    }
    if (it2 != diffs.end())
    {
      int am = *it2 - b[i];

      if (am < min_diff)
      {
        min_diff = am;
        ans = {b[i], *it2};
      }
    }
    
    diffs.insert(b[i]);
  }

  if (min_diff == mod or min_diff >= diff)
  {
    cout << -1 << endl;
    return;
  }
  cout << m << " " << m << ' ' << ans.first << " " << ans.second << endl;


}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}