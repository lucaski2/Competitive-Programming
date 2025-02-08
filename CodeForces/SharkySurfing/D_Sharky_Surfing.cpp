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
  int n, m, l;
  cin >> n >> m >> l;

  vector<pair<int, int>> hurdles(n);
  for (int i = 0; i < n; i++)
    cin >> hurdles[i].first >> hurdles[i].second;
  vector<pair<int, int>> powers(m);
  for (int i = 0; i < m; i++)
    cin >> powers[i].first >> powers[i].second;

  // if (tc != 1) return;


  int power = 1;
  int ptr = 0;
  priority_queue<int> prevs;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {

    while (ptr < m and powers[ptr].first < hurdles[i].first)
    {
      prevs.push(powers[ptr].second);
      ptr++;
    }

    while (hurdles[i].second - hurdles[i].first + 2 > power)
    {

      if (prevs.empty())
      {
        cout << -1 << endl;
        return;
      }

      ans++;
      power += prevs.top();
      prevs.pop();
    }
    // cout << power << endl;
    // cout << ans << endl;
    // cout << prevs.size() << ' ' << ptr << ' ' << powers[ptr].first << ' ' << hurdles[i].first << endl;
    // if (hurdles[i].second - hurdles[i].first + 2 > power)
    // {
    //   cout << -1 << endl;
    //   return;
    // }
  }
  cout << ans << endl;


}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}