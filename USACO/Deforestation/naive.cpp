#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ll long long
using namespace std;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b)
{
  return get<1>(a) < get<1>(b);
}

template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}
template<class T> using ordered_multiset = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;


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
  ordered_multiset<int> used;

  for (int i = 0; i < k; i++)
  {
    int start = get<0>(restrictions[i]);
    int end = get<1>(restrictions[i]);
    int num_needed = get<2>(restrictions[i]);
    num_needed -= used.order_of_key(start - 1);

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