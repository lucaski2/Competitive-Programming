#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const multiset<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

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
  int n, x;
  cin >> n >> x;
  multiset<int> a;
  for (int i = 0; i < n; i++)
  {
    int b;
    cin >> b;
    a.insert(b);
  }
  int ans = 0;
  while (!a.empty())
  {
    int num = *a.begin();
    a.erase(a.begin());

    auto ptr = a.upper_bound(x - num);
    if (ptr != a.begin())
    {
      ptr--;
      a.erase(ptr);
    }
    ans++;
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