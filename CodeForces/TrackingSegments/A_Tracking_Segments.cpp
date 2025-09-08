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
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> a(m);

  for (int i = 0; i < m; i++)
  {
    cin >> a[i].first >> a[i].second;
    a[i].f--;
    a[i].s--;
  }


  int ans = INT_MAX;

  int q;
  cin >> q;
  vector<int> queries(q);
  for (int i = 0; i < q; i++)
    cin >> queries[i];
  // cout << q << endl;

  int l = 0, r = q;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    vector<bool> is_1(n);
    for (int i = 0; i < mid; i++)
    {
      is_1[queries[i] - 1] = true;
    }


    vector<int> pref_sum(n + 1);
    for (int i = 0; i < n; i++)
    {
      pref_sum[i + 1] = pref_sum[i] + is_1[i];
    }
    bool ok = false;
    for (pair<int, int> seg : a)
    {
      bool cur = ((seg.s - seg.f + 1) < 2 * (pref_sum[seg.s + 1] - pref_sum[seg.f]));
      if (cur) ok = true;
    }

    if (ok)
    {
      ans = min(ans, mid);
      r = mid - 1;
    }
    else l = mid + 1;
  }
  if (ans == INT_MAX) cout << -1 << endl;
  else cout << ans << endl;


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