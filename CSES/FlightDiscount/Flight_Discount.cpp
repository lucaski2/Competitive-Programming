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

struct state 
{
  int node, dist;
  bool used;
};

struct comp
{
  bool operator()(state a, state b)
  {
    return a.dist > b.dist;
  }
};

void solve(int tc)
{
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    graph[a-1].push_back({b-1, w});
    // graph[b-1].push_back({a-1, w});
  }

  vector<pair<int, int>> dists(n, {INT64_MAX, INT64_MAX});

  priority_queue<state, vector<state>, comp> pq;
  pq.push({0, 0,  false});

  while (!pq.empty())
  {
    state cur = pq.top();
    pq.pop();
    if (dists[cur.node].first < cur.dist and !cur.used) continue;
    if (dists[cur.node].second < cur.dist and cur.used) continue;
    if (cur.node == n - 1 and cur.used) break;
    for (pair<int, int> neighbor : graph[cur.node])
    {
      int fut_dist1 = cur.dist + neighbor.second / 2;
      int fut_dist2 = cur.dist + neighbor.second;
      if (cur.used)
      {
        if (fut_dist2 < dists[neighbor.first].second)
        {
          dists[neighbor.first].second = fut_dist2;
          pq.push({neighbor.first, fut_dist2, true});
        }
      }
      else
      {
        if (fut_dist1 < dists[neighbor.first].second)
        {
          dists[neighbor.first].second = fut_dist1;
          pq.push({neighbor.first, fut_dist1, true});
        }
        if (fut_dist2 < dists[neighbor.first].first)
        {
          dists[neighbor.first].first = fut_dist2;
          pq.push({neighbor.first, fut_dist2, false});
        }
      }
    }
  }

  cout << dists[n - 1].second << endl;
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