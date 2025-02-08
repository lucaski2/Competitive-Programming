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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n), b(n), c(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i].first;
    b[i].second = i;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> c[i].first;
    c[i].second = i;
  }

  sort(a.begin(), a.end(), greater<pair<int, int>>());
  sort(b.begin(), b.end(), greater<pair<int, int>>());
  sort(c.begin(), c.end(), greater<pair<int, int>>());
  int ans = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        if (a[i].second != b[j].second and b[j].second != c[k].second and c[k].second != a[i].second)
        {
          ans = max(ans, a[i].first + b[j].first + c[k].first);
        }
      }
    }
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