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
  set<int> nums;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    nums.insert(a);
  }

  vector<int> cur;
  bool ok = false;
  function<void(int)> dfs = [&](int val)
  {
    // cout << val << endl;
    if (cur.size() == n)
    {
      ok = true;
      for (int num : cur)
      {
        cout << num << ' ';
      }
      cout << endl;
      return;
    }
    if (nums.find(val * 2) != nums.end())
    {
      cur.push_back(val * 2);
      dfs(val * 2);
      cur.pop_back();
    }

    if (val % 3 == 0 and nums.find(val / 3) != nums.end())
    {
      cur.push_back(val / 3);
      dfs(val / 3);
      cur.pop_back();
    }
  };


  for (int start : nums)
  {
    cur.push_back(start);
    dfs(start);
    cur.pop_back();
    if (ok) break;
  }
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