#include <bits/stdc++.h>
#define int long long
using namespace std;

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
  int c, n;
  cin >> c >> n;

  // for each range, see if u can also use (l - 1, r) and (l, r + 1)

  set<pair<int, int>> agreements;

  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    agreements.insert({a, b});
  }

  vector<vector<int>> dp(c, vector<int>(c));

  for (int s = 1; s < c; s++)
  {
    
  }



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