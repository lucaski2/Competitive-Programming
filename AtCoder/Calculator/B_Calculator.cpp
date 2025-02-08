#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

ll pow(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}



void solve(int tc)
{
  string s;
  cin >> s;
  int ans = 0;
  int n = s.size();
  bool skip = false;
  for (int i = 0; i < n; i++)
  {
    if (i != n - 1 and s[i] == s[i + 1] and s[i] == '0' and !skip)
    {
      ans += 1;
      skip = true;
    }
    else if (skip)
    {
      skip = false;
    }
    else ans++;
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }

  

}