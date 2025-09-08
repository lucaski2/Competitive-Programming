#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;
using namespace __gnu_pbds;

template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';


int pow(int a, int b, int m){ int ans = 1; while(b) { if (b&1) ans = (ans*a) % m; b /= 2; a = (a*a) % m; } return ans; }
int factorial(int n) { int am = 1; for (int i = 1; i <= n; i++) am = (am * i) % mod; return am; }
int choose(int n, int k) { return (factorial(n) * pow(factorial(k), mod - 2, mod)) % mod * pow(factorial(n - k), mod - 2, mod) % mod; }
int permute(int n, int k) { return (factorial(n) * pow(factorial(n - k), mod - 2, mod)) % mod; }
struct DSU {
  vector<int> e; void init(int N) { e = vector<int>(N,-1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
  bool sameSet(int a, int b) { return get(a) == get(b); }
  int size(int x) { return -e[get(x)]; }
  bool unite(int x, int y) { // union by size
    x = get(x), y = get(y); if (x == y) return 0;
    if (e[x] > e[y]) swap(x,y);
    e[x] += e[y]; e[y] = x; return 1;
  }
};
struct Seggy {
  int len;
  vector<int> seggy;
  int DEFAULT;
  int combine(int a, int b) { return a + b; }
  Seggy(int n, int DEFAULT) : len(n), DEFAULT(DEFAULT)
  {
    seggy = vector<int>(n * 2, INT64_MAX);
  };
  void add(int ind, int am)
  {
    for (ind += len; ind > 0; ind /= 2) seggy[ind] = combine(seggy[ind], am);
  }
  int query(int l, int r, int cur_l, int cur_r, int ind)
  {
    if (cur_l >= l and cur_r <= r) return seggy[ind];
    if (cur_l > r or cur_r < l) return DEFAULT;
    int mid = (cur_l + cur_r) / 2;
    return combine(query(l, r, cur_l, mid, ind * 2), query(l, r, mid + 1, cur_r, ind * 2 + 1));
  }
};



void solve(int tc)
{
  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // get diameter
  vector<bool> visited(n);
  vector<int> depth(n);
  vector<int> parent(n);
  int start = 0;
  function<void(int)> dfs = [&](int cur)
  {
    for (int neighbor : graph[cur])
    {
      if (neighbor != parent[cur])
      {
        depth[neighbor] = depth[cur] + 1;
        parent[neighbor] = cur;
        if (depth[start] < depth[neighbor]) start = neighbor;
        dfs(neighbor);
      }
    }
  };

  depth[0] = 0;
  parent[0] = -1;
  dfs(0);
  depth[start] = 0;
  parent[start] = -1;
  dfs(start);

  // get diameter
  vector<int> part_of_diameter(n, -1);
  int ele = start;
  // int depth = 0;
  int largest = depth[start];
  while (ele != -1)
  {
    part_of_diameter[ele] = max(depth[ele], largest - depth[ele]);
    ele = parent[ele];
    // depth++;
  }

  function<void(int)> dfs2 = [&](int cur)
  {
    for (int neighbor : graph[cur])
    {
      if (part_of_diameter[neighbor] == -1)
      {
        part_of_diameter[neighbor] = part_of_diameter[cur] + 1;
        dfs2(neighbor);
      }
    }
  };

  for (int i = 0; i < n; i++)
  {
    if (part_of_diameter[i] == -1) continue;

    dfs2(i);
  }

  vector<int> cnts = part_of_diameter;
  sort(all(cnts));

  int ind = 0;
  for (int i = 1; i <= n; i++)
  {
    while (ind < n and cnts[ind] < i) ind++;
    cout << min(n, ind + 1) << ' ';
  }
  cout << endl;




}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}