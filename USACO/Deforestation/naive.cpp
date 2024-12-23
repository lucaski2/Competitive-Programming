#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b)
{
  return get<1>(a) < get<1>(b);
}

template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

struct desc
{
  bool operator()(int a, int b) const
  {
    return a < b;
  }
};

void solve()
{
  int n, k;
  cin >> n >> k;

  set<int> trees;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    trees.insert(x);
  }

  vector<tuple<int, int, int>> restrictions(k);
  for (int i = 0; i < k; i++)
  {
    cin >> get<0>(restrictions[i]) >> get<1>(restrictions[i]) >> get<2>(restrictions[i]);
  }

  sort(restrictions.begin(), restrictions.end(), compare);
  set<int, desc> used;

  for (int i = 0; i < k; i++)
  {
    int start = get<0>(restrictions[i]);
    int end = get<1>(restrictions[i]);
    int ptr = used.lower_bound(start) == used.end() ? -1 : *used.lower_bound(start);
    int num_needed = get<2>(restrictions[i]);
    if (ptr != -1)
    {
      // distance from start 
      num_needed -= distance(used.lower_bound(start), used.end());
    }

    while (num_needed > 0)
    {
      int cur = less_or_equal(trees, end).value();
      trees.erase(cur);
      used.insert(cur);
      num_needed--;
    }
  }

  cout << trees.size() << endl;
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