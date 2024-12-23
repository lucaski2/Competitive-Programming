#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<int> temp(n);

  for (int i = 0; i < n; i++) cin >> temp[i];

  vector<int> a(n);
  for (int i = 0; i < n - 1; i++)
  {
    a[i] = temp[i + 1] - temp[i];
  }

  vector<vector<int>> st(n, vector<int>(ceil(log2(n) + 1)));

  for (int j = 0; j < ceil(log2(n)); j++)
  {
    for (int i = 0; i + (1 << j) - 1 < n; i++)
    {

      if (j == 0) st[i][j] = a[i];
      else st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }

  vector<int> pref_sum(n + 1);
  for (int i = 1; i < n; i++)
  {
    pref_sum[i] = abs(temp[i - 1] - temp[i]) + pref_sum[i - 1];
  }

  for (int i = 0; i < q; i++)
  {
    int l, r;
    cin >> l >> r;
    l--; r--;
    if (l == r or pref_sum[r] == pref_sum[l - 1]) 
    {
      cout << 0 << ' ';
    }
    else 
    {
      int length = 1 << (31 - __builtin_clz(r - l));
      cout << gcd(st[l][log2(length)], st[r - length][log2(length)]) << ' ';
    }
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
