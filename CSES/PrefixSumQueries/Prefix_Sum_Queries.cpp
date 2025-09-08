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
  vector<int> lazy;
  int DEFAULT;
  int combine(int a, int b) { return a + b; }
  void push(int ind, int l, int r)
  {
    if (lazy[ind] == 0) return;
    seggy[ind] += lazy[ind] * (r - l + 1);
    if (l != r) {
      lazy[ind * 2] += lazy[ind];
      lazy[ind * 2 + 1] += lazy[ind];
    }
    lazy[ind] = 0;
  }

  Seggy(int n, int DEFAULT) : len(n), DEFAULT(DEFAULT)
  {
    seggy = vector<int>(n * 2, 0);
    lazy = vector<int>(n * 2, 0);
  };

  void add(int am, int i, int j, int l, int r, int ind)
  {
    push(ind, l, r);
    if (l > j or r < i) return;
    if (l >= i and r <= j)
    {
      lazy[ind] += am;
      push(ind, l, r);
      return;
    }
    int mid = (l + r) / 2;
    add(am, i, j, l, mid, ind * 2);
    add(am, i, j, mid + 1, r, ind * 2 + 1);
    seggy[ind] = seggy[ind * 2] + seggy[ind * 2 + 1];
  }

  void add(int am, int l, int r)
  {
    add(am, l, r, 0, len - 1, 1);
  }

  int query(int l, int r, int cur_l, int cur_r, int ind)
  {
    push(ind, cur_l, cur_r);

    if (cur_l >= l and cur_r <= r) return seggy[ind];
    if (cur_l > r or cur_r < l) return DEFAULT;
    int mid = (cur_l + cur_r) / 2;
    return query(l, r, cur_l, mid, ind * 2) + query(l, r, mid + 1, cur_r, ind * 2 + 1);
  }
  int query(int l, int r)
  {
    return query(l, r, 0, len - 1, 1);
  }
};



void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  while (__builtin_popcount(n) != 1)
  {
    n++;
  }

  Seggy seggy(n, 0);

  while (q--)
  {
    int type;
    cin >> type;
    if (type == 0)
    {
      int a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      seggy.add(c, a, b);
    }
    else
    {
      int a, b;
      cin >> a >> b;
      a--; b--;
      cout << seggy.query(a, b) << endl;
    }
  }

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