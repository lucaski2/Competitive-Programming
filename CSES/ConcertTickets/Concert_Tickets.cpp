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
  cin >> m >> n;

  vector<int> a(n);
  multiset<int> b;
  for (int i = 0; i < m; i++)
  {
    int c;
    cin >> c;
    b.insert(c);
  }
  for (int i = 0; i < n; i++)
    cin >> a[i];
  

  for (int i = 0; i < n; i++)
  {
    auto ptr = b.upper_bound(a[i]);
    if (ptr == b.begin())
    {
      cout << -1 << endl;
    }
    else
    {
      ptr--;
      cout << *ptr << endl;
      b.erase(ptr);
    }
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