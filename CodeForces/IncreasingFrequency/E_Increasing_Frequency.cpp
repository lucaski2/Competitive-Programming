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
  int n, c;
  cin >> n >> c;
  int mx = 5e5;
  vector<int> a(n);
  vector<vector<int>> inds(mx + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    inds[a[i]].push_back(i);
  }
  int norm_amount = inds[c].size();
  int ans = inds[c].size();
  vector<vector<int>> sums(mx + 1);

  for (int i = 1; i <= mx; i++)
  {
    if (i == c or inds[i].empty())
    {
      continue;
    }

    auto last = inds[c].begin();
    for (int ind : inds[i])
    {
      auto ptr = lower_bound(inds[c].begin(), inds[c].end(), ind);
      sums[i].push_back(last - ptr);
      // if (n == 9 and i == 3)
      // {
      //   cout << last - ptr << endl;
      // }
      sums[i].push_back(1);
      last = ptr;
    }
    // cout << "asdf" << endl;
    // cout << "asdf2" << endl;
    int running = 0;
    set<int> prevs;
    prevs.insert(0);
    for (int num : sums[i])
    {
      running += num;
      ans = max(ans, norm_amount + (running - *prevs.begin()));

      prevs.insert(running);
    }
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