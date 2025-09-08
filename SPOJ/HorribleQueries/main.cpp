#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

int pow(int a, int b, int m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}

struct LazySeggy
{
  vector<int> segtree, lazy;
  int n;
  LazySeggy(int n)
  {
    this->n = n;
    segtree.resize(n * 2); 
    lazy.resize(n * 2);
  }

  void add(int l, int r, int cur_l, int cur_r, int am, int ind)
  {
    if (cur_l >= l and cur_r <= r)
    {
      lazy[ind] += am;
      segtree[ind] += am * (cur_r - cur_l + 1);
      return;
    }
    if (cur_l > r or cur_r < l) return;

    int mid = (cur_l + cur_r) / 2;
    
    add(l, r, cur_l, mid, am, ind * 2);
    add(l, r, mid + 1, cur_r, am, ind * 2 + 1);
  }

  int query(int l, int r, int cur_l, int cur_r, int ind)
  {
    segtree[ind] += (cur_r - cur_l ) * lazy[ind];
    if (cur_l >= l and cur_r <= r)
    {
      return segtree[ind];
    }
    if (cur_l > r or cur_r < l) return 0ll;

    int mid = (cur_l + cur_r) / 2;
    lazy[ind * 2] += lazy[ind];
    lazy[ind * 2 + 1] += lazy[ind];
    lazy[ind] = 0;
    
    return query(l, r, cur_l, mid, ind * 2) + query(l, r, mid + 1, cur_r, ind * 2 + 1);
  }

};



void solve(int tc)
{
  int n, q;
  cin >> n >> q;
  vector<int> a(n);

  while (__builtin_popcount(n) != 1) n++;
  LazySeggy seggy(n);
  // for (int i = 0; i < st; i++)
  // {
  //   seggy.add(i, i, 0, n - 1, a[i], 1);
  // }
  for (int i = 0; i < q; i++)
  {
    int type; cin >> type;
    if (type == 0)
    {
      int l, r, am;
      cin >> l >> r >> am;
      l--; r--;
      seggy.add(l, r, 0, n - 1, am, 1);
    }
    else 
    {
      int l, r;
      cin >> l >> r;
      l--; r--;
      // cout << l << ' ' << r << endl;
      cout << seggy.query(l, r, 0, n - 1, 1) << endl;
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