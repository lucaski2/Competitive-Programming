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
  int levels;
  
  void init(int n, int DEFAULT, int levels)
  {
    len = n;
    seggy = vector<int>(n * 2);
    this->levels = levels;
  };
  void add(int ind, int am, int query_ind, int l, int r, bool depth)
  {
    int mid = (l + r) / 2;
    if (l == r)
    {
      seggy[query_ind] = am;
      return;
    }
    if (mid >= ind) add(ind, am, query_ind * 2, l, mid, 1 - depth);
    else add(ind, am, query_ind * 2 + 1, mid + 1, r, 1 - depth);

    if ((levels - depth) % 2 == 1)
    {
      seggy[query_ind] = seggy[query_ind * 2] | seggy[query_ind * 2 + 1];
    }
    else 
    {
      seggy[query_ind] = seggy[query_ind * 2] ^ seggy[query_ind * 2 + 1];
    }
  }
  int query() { return seggy[1]; }
};

void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  Seggy seggy;
  seggy.init((1 << n), 0, n);
  for (int i = 0; i < (1 << n); i++)
  {
    int a;
    cin >> a;
    seggy.add(i + 1, a, 1, 1, (1 << n), 0);
  }
 
  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    seggy.add(a, b, 1, 1, (1 << n), 0);
    cout << seggy.query() << en;
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