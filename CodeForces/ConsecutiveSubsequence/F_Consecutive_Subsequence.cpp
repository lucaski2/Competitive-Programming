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
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  map<int, int> dp;

  for (int i = 0; i < n; i++)
  {
    if (dp.find(a[i] - 1) == dp.end())
    {
      dp[a[i]] = 1;
    }
    else
    {
      dp[a[i]] = dp[a[i] - 1] + 1;
    }
  }
  pair<int, int> best = {0, 0};
  for (auto x : dp)
  {
    if (x.second > best.second)
    {
      best = x;
    }
  }

  vector<int> inds;
  int num = best.first;
  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i] == num)
    {
      inds.push_back(i + 1);
      num--;
    }
  }

  reverse(inds.begin(), inds.end());
  cout << inds.size() << endl;
  for (int ind : inds)
  {
    cout << ind << ' ';
  }
  cout << endl;

}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}