#include <bits/stdc++.h>
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;

struct Fenwick
{
  vector<int> tree;

  int N;
  void init(int _N) 
  {
    N = _N;
    tree.resize(N + 1, 0);
  }
  
  void update(int i, int k)
  {
    while (i <= N)
    {
      tree[i] += k;
      i += (i & (-i));
    }
  }

  int query(int i)
  {
    int ans = 0;
    while (i > 0)
    {
      ans += tree[i];
      i -= (i & (-i));
    }
    return ans;
  }
};


void solve(int tc)
{
  int n, q;
  cin >> n >> q;
  Fenwick tree;
  tree.init(n);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    tree.update(x, 1);
  }

  for (int i = 0; i < q; i++)
  {
    int x;
    cin >> x;
    if (x > 0)
    {
      tree.update(x, 1);
      continue;
    }
    x = -x;
    int l = 0, r = n;
    int ans = INT_MAX;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (tree.query(mid) >= x)
      {
        r = mid - 1;
        ans = mid;
      }
      else l = mid + 1;
    }
    // cout << ans << endl;
    tree.update(ans, -1);
  }
  // cout << n << endl;
  for (int i = 1; i <= n; i++)
  { 
    // cout << tree.query(i) << endl;
    if (tree.query(i))
    {
      cout << i << endl;
      return;
    }
  }
  cout << 0 << endl;
}


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}