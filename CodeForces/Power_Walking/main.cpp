#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  map<int, int> counts;
  for (int i = 0; i < n; i++) counts[a[i]]++;

  vector<int> b;
  for (auto [key, value] : counts) b.push_back(value);

  sort(b.begin(), b.end());
  int m = b.size();

  int cur = m;
  int ind = 0;
  int num = 0;
  for (int i = 0; i < n; i++)
  {
    num++;
    if (num != 1)
    {
      cur++;
    }
    if (b[ind] == num)
    {
      ind++;
      num = 0;
    }

    cout << cur << " ";
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