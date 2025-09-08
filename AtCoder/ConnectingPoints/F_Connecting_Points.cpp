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
};

vector<int> fact = {1};

int factorial(int n)
{
  while (fact.size() - 1 < n)
    fact.push_back((fact.back() * fact.size()) % mod);

  return fact[n];
}



int pow(int a, int b, int m){ int ans = 1; while(b) { if (b&1) ans = (ans*a) % m; b /= 2; a = (a*a) % m; } return ans; }
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


void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  struct info
  {
    int a, b, dist;
  };

  DSU dsu;
  dsu.init(n + q);

  struct comp
  {
    bool operator()(info a, info b)
    {
      return a.dist > b.dist;
    }
  };

  vector<pair<int, int>> edges;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    edges.push_back({a, b});
  }

  priority_queue<info, vector<info>, comp> pq;
  
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      pq.push({i, j, abs(edges[i].f - edges[j].f) + abs(edges[i].s - edges[j].s)});
    }
  }

  while (q--)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      int a, b;
      cin >> a >> b;
      for (int i = 0; i < edges.size(); i++)
      {
        pq.push({edges.size(), i, abs(edges[i].f - a) + abs(edges[i].s - b)});
      }
      edges.push_back({a, b});
    }
    else if (t == 2)
    {
      int cnt = 0;
      for (int i = 0; i < edges.size(); i++)
        cnt += dsu.e[i] < 0;
      if (cnt == 1)
      {
        cout << -1 << endl;
      }
      else
      {
        int lo = INT_MAX;
        while (pq.size() and pq.top().dist <= lo)
        {
          if (!dsu.sameSet(pq.top().a, pq.top().b))
          {
            dsu.unite(pq.top().a, pq.top().b);
            lo = pq.top().dist;
          }

          pq.pop();
        }
        cout << lo << endl;
      }
    }
    else if (t == 3)
    {
      int a, b;
      cin >> a >> b;
      cout << (dsu.sameSet(a - 1, b - 1) ? "Yes" : "No") << endl;
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