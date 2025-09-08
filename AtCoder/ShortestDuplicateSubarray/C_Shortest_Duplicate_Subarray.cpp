#include <bits/stdc++.h>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second
#define iter(i, n) for (int i = 0; i < n; i++)

using namespace std;

using vi = vector<int>;


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
  vi a(n);
  iter(i, n)
  {
    cin >> a[i];
  }

  map<int, int> last;
  int ans = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    if (last.find(a[i]) != last.end())
    {
      ans = min(ans, i - last[a[i]] + 1);
    }
    last[a[i]] = i;
  }
  if (ans == INT_MAX) cout << -1 << endl;
  else cout << ans << endl;



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