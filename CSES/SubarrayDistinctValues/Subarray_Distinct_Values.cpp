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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  map<int, int> cur;
  cur[a[0]]++;
  int ans = 0;
  int l = 0, r = 1;
  for (; l < n; l++)
  {
    if (l != 0)
    {
      cur[a[l - 1]]--;
      if (cur[a[l - 1]] == 0)
      {
        cur.erase(a[l - 1]);
      }
    }

    while (r < n and (cur.size() < k or cur.find(a[r]) != cur.end()))
    {
      cur[a[r]]++;
      r++;
    }

    ans += r - l;
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