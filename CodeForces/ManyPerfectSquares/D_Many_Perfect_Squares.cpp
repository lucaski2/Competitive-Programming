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
bool perfectSquare(int num) {
  if (num < 0) {
    return false; // Negative numbers cannot be perfect squares
  }
  if (num == 0) {
      return true; //0 is a perfect square
  }
  int root = std::round(std::sqrt(num));
  return root * root == num;
}



vector<int> a;

int eval(int x)
{
  int ans = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (perfectSquare(a[i] + x)) ans++;
  }
  return ans;
}

vector<int> getDivisors(int n)
{
  vector<int> divs;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      divs.push_back(i);
      divs.push_back(n / i);
    }
  }
  return divs;
}




void solve(int tc)
{
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  //a[j] - a[i] = (q-p)(q+p)
  int ans = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int num = a[j] - a[i];

      vector<int> divisors = getDivisors(num);
      for (int divisor : divisors)
      {
        int num1 = divisor;
        int num2 = num / divisor;
        if (num1 > num2) continue;
        // q - p = num1
        // q + p = num2
        // p + num1 = num2 - p
        // 2p = num2-num1
        // p = (num2 - num1) / 2
        if ((num2 - num1) % 2 != 0) continue;
        int p = (num2 - num1) / 2;
        int q = num1 + p;
        // a[i] + x = p^2
        int diff1 = p * p - a[i];
        int diff2 = q * q - a[j];
        if (diff1 == diff2 and diff1 >= 0)
        {
          ans = max(ans, eval(diff1));
          // cout << diff1 << ' ' << eval(diff1) << endl;
        }
      }
    }
  }
  cout << ans << endl;






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