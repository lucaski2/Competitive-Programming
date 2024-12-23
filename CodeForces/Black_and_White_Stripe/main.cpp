#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> psum(n + 1, 0);
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
  {
    char a = s[i];
    int num = a != 'B';
    psum[i + 1] = psum[i] + num;
  }
  int ans = pow(10, 9);
  for (int i = 0; i + k <= n; i++)
  {
    ans = min(ans, psum[i + k] - psum[i]);
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