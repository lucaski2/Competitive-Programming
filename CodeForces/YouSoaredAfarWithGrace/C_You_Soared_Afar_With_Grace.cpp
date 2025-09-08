#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define ll long long
#define all(a) (a).begin(), (a).end()
#define f first
#define s second

using namespace std;
using namespace __gnu_pbds;

const int mod = 1000000007;
const char en = '\n';

int enc(int a, int b, int n)
{
  return a * (n + 1LL) + b;
}

void solve(int tc)
{
  int n;
  cin >> n;

  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    cin >> b[i];

  vector<int> pos_a(n + 1), pos_b(n + 1);
  for (int i = 1; i <= n; ++i)
  {
    pos_a[a[i]] = i;
    pos_b[b[i]] = i;
  }

  vector<int> fix;
  unordered_map<int, int> pf;
  vector<pair<int, int>> ps;
  for (int x = 1; x <= n; ++x)
  {
    int i = pos_a[x], j = pos_b[x];
    if (i == j)
    {
      fix.push_back(i);
    }
    else
    {
      int u = min(i, j);
      int v = max(i, j);
      int key = enc(u, v, n);
      if (pf.find(key) == pf.end())
      {
        pf[key] = 1;
        ps.push_back({u, v});
      }
      else
      {
        pf[key]++;
      }
    }
  }

  if ((n % 2 == 0 && !fix.empty()) || (n % 2 == 1 && fix.size() != 1))
  {
    cout << -1 << "\n";
    return;
  }
  for (const auto &ele : pf)
  {
    if (ele.second != 2)
    {
      cout << -1 << "\n";
      return;
    }
  }

  vector<int> targ(n + 1, 0);
  int left = 1, right = n;
  for (const auto &pr : ps)
  {
    if (left >= right)
      break;
    targ[left] = pr.first;
    targ[right] = pr.second;
    ++left;
    --right;
  }
  if (n % 2 == 1)
    targ[(n + 1) / 2] = fix[0];

  vector<int> cur(n + 1);
  for (int i = 1; i <= n; ++i)
    cur[i] = i;
  vector<int> poses(n + 1);
  for (int i = 1; i <= n; ++i)
    poses[cur[i]] = i;

  vector<pair<int, int>> ops;
  for (int i = 1; i <= n; ++i)
  {
    if (cur[i] == targ[i])
      continue;
    int j = poses[targ[i]];
    ops.push_back({i, j});
    swap(cur[i], cur[j]);
    swap(a[i], a[j]);
    swap(b[i], b[j]);
    poses[cur[i]] = i;
    poses[cur[j]] = j;
  }

  for (int i = 1; i <= n; ++i)
    assert(b[i] == a[n + 1 - i]);

  cout << ops.size() << "\n";
  for (const auto &op : ops)
    cout << op.first << " " << op.second << "\n";
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}
