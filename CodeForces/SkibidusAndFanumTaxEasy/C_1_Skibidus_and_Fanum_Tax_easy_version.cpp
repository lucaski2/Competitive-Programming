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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int b;
  cin >> b;

  for (int i = 0; i < n; i++)
  {
    int am1 = a[i];
    int am2 = b - a[i];
    if (i == 0)
    {
      a[i] = min(am1, am2);
      continue;
    }

    int last = a[i - 1];

    if (min(am1, am2) >= last)
    {
      a[i] = min(am1, am2);
    }
    else
    {
      a[i] = max(am1, am2);
    }



  }

  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] > a[i + 1])
    {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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