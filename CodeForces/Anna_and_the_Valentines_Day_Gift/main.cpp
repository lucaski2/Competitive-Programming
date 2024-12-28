#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

bool c(const string& a, const string& b)
{
  int am1 = 0, am2 = 0;
  
  for (int i = a.size() - 1; i >= 0 and a[i] == '0'; i--)
    am1++;
  for (int i = b.size() - 1; i >= 0 and b[i] == '0'; i--)
    am2++;
  return am1 > am2;
}


void solve()
{
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  sort(a.begin(), a.end(), c);
  // for (int i = 0; i < n; i++)
  //   cout << a[i] << ' ';
  // cout << endl;

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += a[i].size();

  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      int am = 0;
      string cur = a[i];
      for (int i = cur.size() - 1; i >= 0 and cur[i] == '0'; i--)
        am++;
      ans -= am;
    }
  }
  cout << (ans - 1 >= m ? "Sasha" : "Anna") << endl;

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