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
  string s;
  cin >> s;

  map<char, int> counts;
  for (int i = 0; i < n; i++)
  {
    counts[s[i]]++;
  }

  pair<char, int> most = {'a', 0};
  pair<char, int> least = {'a', 1000000};
  
  for (auto ele : counts)
  {

    if (ele.second < least.second)
    {
      least = {ele.first, ele.second};
    }
    if (ele.second >= most.second)
    {
      most = {ele.first, ele.second};
    }
  }
  // cout << most.first << ' ' << most.second << ' ' << least.first << ' ' << least.second << endl;

  for (int i = 0; i < n; i++)
  {
    if (s[i] == least.first)
    {
      s[i] = most.first;
      break;
    }
  }
  cout << s << endl;

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