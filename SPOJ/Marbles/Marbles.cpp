#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1e17 + 13;
const int inf = INT64_MAX;
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

int fact(int s, int e)
{
  int ret = 1;
  for (int i = s; i <= e; i++)
  {
    // ret *= i;
    if (inf / i > )
  }
  return ret;
}

int choose(int n, int k)
{
  int am = 0;
  if (n - k >= k)
  {
    am = fact(n - k + 1, n);
    am /= fact(1, k);
  }
  else
  {
    am = fact(k + 1, n);
    am /= fact(1, n - k);
  }
  return am;
}


void solve(int tc)
{
  int n, k;
  cin >> n >> k;
  int am = choose(n - 1, k - 1);
  // cout << fact(n - 1) << ' ' << fact(n - k) << ' ' << fact(k) << endl;
  // if (am < 0) am += mod;
  cout << am << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >>  t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}