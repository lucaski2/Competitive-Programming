#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n, d;
  cin >> n >> d;
  vector<int> ans;
  ans.push_back(1);

  if (d % 3 == 0 or n >= 3)
  {
    ans.push_back(3);
  }
  if (d % 5 == 0)
  {
    ans.push_back(5);
  }
  if (d % 7 == 0 or n >= 3)
  {
    ans.push_back(7);
  }
  if (d == 9 or (d % 3 == 0 and n >= 3) or n >= 6)
  {
    ans.push_back(9);
  }
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << ' ';
  }
  cout << endl;


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