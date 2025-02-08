#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

bool comp(pair<vector<int>, int> &a, pair<vector<int>, int> &b)
{
  for (int i = 0; i < a.first.size(); i++)
  {
    if (a.first[i] < b.first[i])
    {
      return true;
    }
    else if (a.first[i] > b.first[i])
    {
      return false;
    }
  }
  return false;
}


void solve()
{
  int n, k;
  cin >> n >> k;
  vector<pair<vector<int>, int>> a(n, {vector<int>(k), 0});

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k; j++)
    {
      cin >> a[i].first[j];
    }
    a[i].second = i;
  }

  sort(a.begin(), a.end(), comp);

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < k; j++)
    {
      if (a[i].first[j] > a[i + 1].first[j])
      {
        cout << "NO" << en;
        return;
      }
    }
  }
  cout << "YES" << en;
  for (int i = 0; i < n; i++)
  {
    cout << a[i].second + 1 << " ";
  }
  cout << en;

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
