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
  int n, m, k;
  cin >> n >> m >> k;
  
  if (abs(n - m) > k)
  {
    cout << -1 << endl;
    return;
  }
  if (max(n, m) < k)
  {
    cout << -1 << endl;
    return;
  }
  char h = (n > m ? '0' : '1');
  char l = (n > m ? '1' : '0');

  string s(n + m, l);
  for (int i = 0; i < k; i++)
    s[i] = h;
  if (n > m) n -= k;
  else m -= k;
  int cnt = 0;

  for (int i = k + 1; i < s.size(); i += 2)
  {
    if (cnt >= min(n, m)) break;
    // cout << "asdf" << endl;
    s[i] = h;
    cnt++;
  }
  cout << s << endl;





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