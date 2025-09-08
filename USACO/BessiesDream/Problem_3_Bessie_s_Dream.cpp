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


struct mi {

  int v;
  mi() : v(0) {}
	mi(int _v):v((long long)(_v % mod)) { v += (v < 0) * mod; }
	friend mi operator+(mi a, const mi& b) { return mi(a.v + b.v); }
	friend mi operator-(mi a, const mi& b) { return mi(a.v - b.v); }
	friend mi operator*(mi a, const mi& b) { return mi((int)a.v*b.v); }
	friend mi operator/(mi a, const mi& b) { return a * inv(b); }
	friend mi pow(mi a, int p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mi inv(const mi& a) { return pow(a, mod-2); }
	mi& operator+=(const mi& o) { return (*this) = (*this) + o; }
	mi& operator-=(const mi& o) { return (*this) = (*this) - o; }
	mi& operator*=(const mi& o) { return (*this) = (*this) * o; }
	mi& operator/=(const mi& o) { return (*this) = (*this) / o; }
  auto operator<=>(const mi&) const = default;
};


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
  int x, y, dist, smell;
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

  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];
  }

  /*
  If a tile is red, then it is impassable.
  If a tile is pink, then it can be walked on normally.
  If a tile is orange, then it can be walked on normally, but will make Bessie smell like oranges.
  If a tile is blue, then it contains piranhas that will only let Bessie pass if she smells like oranges.
  If a tile is purple, then Bessie will slide to the next tile in that direction
  (unless she is unable to cross it). If this tile is also a purple tile, then Bessie will continue to 
  slide until she lands on a non-purple tile or hits an impassable tile. 
  Sliding through a tile counts as a move. Purple tiles will also remove Bessie's smell.
  */

  vector<vector<int>> rows(n);
  vector<vector<int>> columns(m);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] != 4) {
        rows[i].push_back(j)
        columns[j].push_back(i);
      }
    }
  }

  priority_queue<state, vector<state>, comp> pq;
  pq.push({0, 0, 0, 0});

  vector<vector<vector<int>>> dists(n, vector<int>(m, vector<int>(2, INT64_MAX)));
  dists[0][0][0] = 0;

  while (!pq.empty())
  {
    state cur = pq.top();
    pq.pop();

    if (dists[cur.x][cur.y] < cur.dist) continue;

    vector<pair<int, int>> neighbors = {{cur.x + 1, cur.y}, {cur.x, cur.y + 1}, {cur.x - 1, cur.y}, {cur.x, cur.y - 1}};
    for (pair<int, int> ne : neighbors)
    {
      if (ne.f < 0 or ne.s < 0 or ne.f >= n or ne.s >= m) continue;
      if (grid[ne.f][ne.s] == 0) continue;
      if (grid[ne.f][ne.s] == 1)
      {
        int next = cur.dist + 1;
        if (next < dists[ne.f][ne.s][cur.smell])
        {
          pq.push({ne.f, ne.y, next, cur.smell});
          dists[ne.f][ne.y][cur.smell] = next;
        }
        continue;
      }

      if (grid[ne.f][ne.s] == 2)
      {
        int next = cur.dist + 1;
        if (next < dists[ne.f][ne.s][1])
        {
          pq.push({ne.f, ne.y, next, 1});
          dists[ne.f][ne.y][1] = next;
        }
        continue;
      }
      if (grid[ne.f][ne.s] == 3)
      {
        int next = cur.dist + 1;
        if (next < dists[ne.f][ne.s][cur.smell] and cur.smell)
        {
          pq.push({ne.f, ne.y, next, cur.smell});
          dists[ne.f][ne.y][cur.smell] = next;
        }
        continue;
      }

      else
      {
        


      }

    }

  }


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