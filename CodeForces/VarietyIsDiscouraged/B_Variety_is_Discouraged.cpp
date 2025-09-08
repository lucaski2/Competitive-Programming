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
  map<int, int> cnt;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    cnt[a[i]]++;
  }
  bool ok = false;
  for (int i = 0; i < n; i++)
  {
    if (cnt[a[i]] == 1) ok = true;
  }
  if (!ok)
  {
    cout << 0 << endl;
    return;
  }

  int l = 0, r = 0;
  pair<int, int> best = {0, -1};

  while (r < n)
  {
    
    if (cnt[a[r]] > 1)
    {
      l = r + 1;
      r = l;
    }

    else
    {
      if (r - l > best.second - best.first)
      {
        best = {l, r};
      }
      r++;
    }


  }
  cout << best.first + 1 << " " << best.second + 1 << endl;




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