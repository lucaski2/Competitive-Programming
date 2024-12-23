#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b)
{
  return get<1>(a) < get<1>(b);
}

template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}


void update(vector<int> &seg_tree, int ind, int value)
{
  seg_tree[ind + seg_tree.size() / 2] += value;
  ind = ind + seg_tree.size() / 2;
  while (ind > 1)
  {
    seg_tree[ind >> 1] = seg_tree[ind] + seg_tree[ind ^ 1];
    ind >>= 1;
  }
}

int query(vector<int> &seg_tree, int l)
{
  int res = 0;
  int r = seg_tree.size() / 2;
  int n = seg_tree.size() / 2;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1)
  {
    if (l & 1)
    {
      res += seg_tree[l++];
    }
    if (r & 1)
    {
      res += seg_tree[--r];
    }
  }
  return res;
}




int get_ind (vector<int>& bounds, int value)
{
  return lower_bound(bounds.begin(), bounds.end(), value) - bounds.begin();
}

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
  vector<int> bounds;
  for (tuple<int, int, int> restriction : restrictions)
  {
    if (bounds.size() == 0 or get<1>(restriction) != bounds[bounds.size() - 1])
    {
      bounds.push_back(get<1>(restriction));
    }
  }
  vector<int> seg_tree(2 * bounds.size(), 0);

  for (int i = 0; i < k; i++)
  {
    int start = get<0>(restrictions[i]);
    int end = get<1>(restrictions[i]);
    int num_needed = get<2>(restrictions[i]);
    num_needed -= query(seg_tree, get_ind(bounds, start));
    while (num_needed > 0)
    {
      int cur = less_or_equal(trees, end).value();
      trees.erase(cur);
      update(seg_tree, get_ind(bounds, cur), 1);
      num_needed--;
    }
  }

  cout << trees.size() << endl;



  // for (int i = 0; i < k; i++)
  // {
  //   int start = get<0>(restrictions[i]);
  //   int end = get<1>(restrictions[i]);
  //   int ptr = used.lower_bound(start) == used.end() ? -1 : *used.lower_bound(start);
  //   int num_needed = get<2>(restrictions[i]);
  //   if (ptr != -1)
  //   {
  //     // distance from start 
  //     num_needed -= distance(used.lower_bound(start), used.end());
  //   }

  //   while (num_needed > 0)
  //   {
  //     int cur = less_or_equal(trees, end).value();
  //     trees.erase(cur);
  //     used.insert(cur);
  //     num_needed--;
  //   }
  // }



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
