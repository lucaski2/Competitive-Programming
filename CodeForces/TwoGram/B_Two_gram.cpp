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
  string s;
  cin >> s;

  map<pair<char, char>, int> cnts;
  for (int i = 0; i < n - 1; i++)
  {
    cnts[{s[i], s[i + 1]}]++;
  }
  pair<char, char> best;
  int cnt = 0;
  for (auto el : cnts)
  {
    if (el.second > cnt)
    {
      best = el.first;
      cnt = el.second;
    }
  }
  cout << best.first << best.second << endl;

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