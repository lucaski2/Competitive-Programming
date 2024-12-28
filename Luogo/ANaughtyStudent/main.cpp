#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n;
  cin >> n;
  vector<int> reports(n);
  int a;
  cin >> a;
  for (int i = 0; i < a; i++)
  {
    int cur;
    cin >> cur;
    cur--;
    reports[cur]++;
  }
  cin >> a;
  for (int i = 0; i < a; i++)
  {
    int cur;
    cin >> cur;
    cur--;
    reports[cur]++;
  }
  cin >> a;
  for (int i = 0; i < a; i++)
  {
    int cur;
    cin >> cur;
    cur--;
    reports[cur]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += reports[i] != 1;
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
