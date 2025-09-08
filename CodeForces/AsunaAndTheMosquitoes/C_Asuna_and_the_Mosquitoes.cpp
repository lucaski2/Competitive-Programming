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
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  // 1 1 2 2
  // if odd, keeps parity
  // if even, immediately changes to odd
  // 2 3 4 5 9
  // 2 3 0 5 13
  // 1 3 0 5 14
  // 1 1 0 0 21
  
  // if you fully eat it will become odd
  // if we start with odd, we can eat all evens besides one
  // then we eat all odds - num_odds + 1

  vector<int> odds;
  vector<int> evens;
  for (int i = 0; i < n; i++)
  {
    if (a[i] % 2 == 0) evens.push_back(a[i]);
    else odds.push_back(a[i]);
  }
  sort(all(odds));
  sort(all(evens));
  int am;
  if (odds.size() == 0)
  {
    cout << evens.back() << endl;
    return;
  }
  else if (evens.empty())
  {
    cout << odds.back() << endl;
    return;
  }
  else if (odds.back() > evens.back())
  {
    am = odds.back();
    odds.pop_back();
  }
  else
  {
    am = evens.back();
    evens.pop_back();
  }

  if (am % 2 == 0)
  {
    // do odds first
    while (odds.size() > 1)
    {
      am += odds.back() - 1;
      odds.pop_back();
    }
    am += odds.back();
    // am is odd

    while (!evens.empty())
    {
      am += evens.back();
      evens.pop_back();
    }
    cout << am << endl;
    return;
  }
  // odd

  while (evens.size() > 1)
  {
    am += evens.back();
    evens.pop_back();
  }
  if (!odds.empty()) am += evens.back() - 1;
  else am += evens.back();
  while (odds.size() > 1)
  {
    am += odds.back() - 1;
    odds.pop_back();
  }
  if (!odds.empty()) am += odds.back();
  cout << am << endl;




  





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