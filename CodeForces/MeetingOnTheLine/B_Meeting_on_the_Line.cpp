#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
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



void solve()
{
  int n;
  cin >> n;

  vector<int> positions(n);
  vector<int> times(n);
  for (int i = 0; i < n; i++)
    cin >> positions[i];
  for (int i = 0; i < n; i++)
    cin >> times[i];
  
  ld l = 0, r = 1e6;
  ld ans = 0;

  while (r - l > pow(10, -6))
  {
    ld time = (r + l) / 2;
    ld left_bound = 0;
    ld right_bound = 1e10;
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
      ld cur = time - times[i];
      if (cur < 0)
      {
        ok = false;
      }
      else
      {
        left_bound = max(left_bound, positions[i] - cur);
        right_bound = min(right_bound, positions[i] + cur);
      }
    } 
    if (left_bound < right_bound or !ok)
    {
      l = time;
    }

    else
    {
      r = time;
      ans = left_bound;
    }
  }
  cout << ans << endl;


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}