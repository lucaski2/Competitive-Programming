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



void solve()
{
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  vector<int> psum(n + 1);
  for (int i = 0; i < n; i++)
    psum[i + 1] = psum[i] + a[i];
  
  int ans = 0;

  int ptr = 0;
  for (int i = 0; i < n; i++)
  {
    while (psum[i + 1] - psum[ptr] > t)
      ptr++;
    
    ans = max(ans, i + 1 - ptr);
  }
  cout << ans << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--)
  {
      solve();
  }
}