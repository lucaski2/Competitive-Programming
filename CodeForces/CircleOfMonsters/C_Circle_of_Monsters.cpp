#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here: https://codeforces.com/contest/1334/problem/C
// Start time here: 7:53
// End time here: 8:10

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
  
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
  }

  vector<int> needed_chain(n);
  int s = 0;
  for (int i = 0; i < n; i++)
  {
    needed_chain[i] = max(0ll, a[i] - b[(i == 0 ? n - 1 : i - 1)]);
    s += needed_chain[i];
    // cout << needed_chain[i] << ' ';
    
  }
  // cout << endl;
  int ans = INT64_MAX;
  for (int i = 0; i < n; i++)
  {
    int am = s - needed_chain[i];
    ans = min(ans, a[i] + am);
    // cout << a[i] + am << ' ';
  }
  // cout << endl;
  cout << ans << endl;




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