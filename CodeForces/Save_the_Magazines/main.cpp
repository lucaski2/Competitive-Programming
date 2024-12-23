#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

int nearest(vector<int> &lids, int ind)
{
  for (int i = ind - 1; i >= 0; i--)
  {
    if (lids[i] == 0)
    {
      return i;
    }
  }
  return -1;
}


void solve()
{
  int n;
  cin >> n;
  vector<int> lids(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    char k;
    cin >> k;
    lids[i] = static_cast<int>(k) - '0';
  }
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  
  vector<int> cur;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (lids[i]) ans += a[i];
    if (lids[i] == 0 and !cur.empty())
    {
      int num1 = a[i];
      int num2 = *min_element(cur.begin(), cur.end());
      if (num1 > num2)
      {
        ans += num1;
        ans -= num2;
      }
      cur = {};
    }
    else if (lids[i] == 1)
    {
      cur.push_back(a[i]);
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