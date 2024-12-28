#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  string s;
  string t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  set<char> ts;
  for (int i = 0; i + 1 < m; i++)
  {
    ts.insert(t[i]);
  }
  string ans;
  for (int i = 0; i + 1 < n; i++)
  {
    if (ts.find(s[i]) != ts.end())
    {
      string cur_ans;
      for (int j = 0; j <= i; j++)
      {
        cur_ans += s[j];
      }
      string temp;
      for (int j = m - 1; (j >= 0 and (t[j] != s[i] or j == m - 1)); j--)
      {
        temp += t[j];
      }

      reverse(temp.begin(), temp.end());
      cur_ans += temp;
      if (cur_ans.size() < ans.size() or ans.empty())
      {
        ans = cur_ans;
      }
    }
  }
  if (ans.empty())
  {
    cout << -1 << endl;
  }
  else cout << ans << endl;

  


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}