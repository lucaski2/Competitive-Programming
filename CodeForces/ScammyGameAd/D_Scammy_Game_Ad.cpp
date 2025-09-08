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

struct tipo
{
  bool t;
  int am;
};

void solve(int tc)
{
  int n;
  cin >> n;
  vector<pair<tipo, tipo>> a(n);
  for (int i = 0; i < n; i++)
  {
    char t1, t2;
    int am1, am2;
    cin >> t1 >> am1 >> t2 >> am2;
    a[i].first.t = (t1 == 'x');
    a[i].second.t = (t2 == 'x');
    a[i].first.am = am1;
    a[i].second.am = am2;
  }
  int l = 1;
  int r = 1;

  for (int i = 0; i < n; i++)
  {

    bool left = true;
    for (int j = i + 1; j < n; j++)
    {
      if (a[j].f.t and !a[j].s.t) break;
      if (a[j].f.t and a[j].s.t and a[j].f.am > a[j].s.am) break;
      if (a[j].f.t and a[j].s.t and a[j].f.am < a[j].s.am)
      {
        left = false;
        break;
      }
      if (a[j].s.t and !a[j].f.t)
      {
        left = false;
        break;
      }
    }

    int am = 0;
    if (a[i].f.t) am += (a[i].f.am - 1) * l;
    else am += a[i].f.am;
    if (a[i].s.t) am += (a[i].s.am - 1) * r;
    else am += a[i].s.am;
    if (left) l += am;
    else r += am;
  }
  cout << l + r << endl;






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