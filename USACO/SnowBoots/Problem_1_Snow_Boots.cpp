#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define s second
#define f first 

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
  ifstream cin("snowboots.in");
  ofstream cout("snowboots.out");
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].f;
    a[i].s = i;
  }

  struct info
  {
    int d, m, i;
    static bool comp(info a, info b)
    {
      return a.d > b.d;
    }
  };
  
  vector<info> queries(q);
  for (int i = 0; i < q; i++)
  {
    cin >> queries[i].d >> queries[i].m;
    queries[i].i = i;
  }
  sort(all(queries), info::comp);

  sort(all(a));
  reverse(all(a));
  
  struct lcmp
  {
    bool operator() (pair<int, int> a, pair<int, int> b) const
    {
      return (a.s == b.s ? a.f < b.f : a.s < b.s);
    }
  };
  vector<bool> ans(q);
  vector<int> mxdist(q);

  set<pair<int, int>> lb;
  set<pair<int, int>, lcmp> rb;
  multiset<int> sizes;
  int ptr = 0;
  for (int i = 0; i < q; i++)
  {
    while (ptr < n and a[ptr].f > queries[i].d)
    {
      int ind = a[ptr].s;
      auto lptr = lb.lower_bound({ind, -1});
      auto rptr = rb.lower_bound({-1, ind - 1});
      bool lis = (lptr != lb.end() and lptr->f == ind + 1);
      bool ris = (rptr != rb.end() and rptr->s == ind - 1);
      if (lis and ris)
      {
        // cout << 'z';
        pair<int, int> ls = *rptr;
        pair<int, int> rs = *lptr;
        lb.erase(ls);
        rb.erase(ls);
        lb.erase(rs);
        rb.erase(rs);
        sizes.erase(sizes.find(ls.s - ls.f + 1));
        sizes.erase(sizes.find(rs.s - rs.f + 1));
        pair<int, int> next = {ls.f, rs.s};
        lb.insert(next);
        rb.insert(next);
        sizes.insert(next.s - next.f + 1);
      }
      else if (lis)
      {
        // cout << 'a';
        pair<int, int> rs = *lptr;
        lb.erase(rs);
        rb.erase(rs);
        sizes.erase(sizes.find(rs.s - rs.f + 1));
        pair<int, int> next = {ind, rs.s};
        lb.insert(next);
        rb.insert(next);
        sizes.insert(next.s - next.f + 1);
      }
      else if (ris)
      {
        // cout << 'b';
        pair<int, int> ls = *rptr;
        lb.erase(ls);
        rb.erase(ls);
        sizes.erase(sizes.find(ls.s - ls.f + 1));
        pair<int, int> next = {ls.f, ind};
        lb.insert(next);
        rb.insert(next);
        sizes.insert(next.s - next.f + 1);
      }
      else
      {
        // cout << 'c';
        sizes.insert(1);
        lb.insert({ind, ind});
        rb.insert({ind, ind});
      }

      ptr++;
    }
    
    if (!sizes.empty() and *sizes.rbegin() >= queries[i].m)
      ans[queries[i].i] = 0;
    else ans[queries[i].i] = 1;
    // if (!sizes.empty())
    //   mxdist[queries[i].i] = *sizes.rbegin();
  }
  // cout << endl;
  for (bool ele : ans)
    cout << ele << en;
  // for (int ele : mxdist)
  //   cout << ele << ' ';
  // cout << endl;


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