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



void solve(int tc)
{
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> elements;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    elements[a[i]] = 0;
  }
  int ind = 0;
  for (auto it : elements)
  {
    elements[it.first] = ind;
    ind++;
  }

  for (int i = 0; i < n; i++)
  {
    a[i] = elements[a[i]];
  }

  


  int am = n;
  while (__builtin_popcount(am) != 1) am++;
  vector<int> segtree(am * 2);
  vector<int> segtree2(am * 2);

  function<void(int, int)> add = [&](int ind, int incr)
  {
    for (ind += am; ind > 0; ind /= 2)
    {
      segtree[ind] += incr;
    }
  };

  function<int(int, int, int, int, int)> query = [&](int l, int r, int cur_l, int cur_r, int ind)
  {
    if (cur_l >= l and cur_r <= r) return segtree[ind];
    if (cur_l > r or cur_r < l) return 0ll;

    int mid = (cur_l + cur_r) / 2;
    return query(l, r, cur_l, mid, ind * 2) + query(l, r, mid + 1, cur_r, ind * 2 + 1);
  };

  function<void(int, int)> add2 = [&](int ind, int incr)
  {
    for (ind += am; ind > 0; ind /= 2)
    {
      segtree2[ind] += incr;
    }
  };

  function<int(int, int, int, int, int)> query2 = [&](int l, int r, int cur_l, int cur_r, int ind)
  {
    if (cur_l >= l and cur_r <= r) return segtree2[ind];
    if (cur_l > r or cur_r < l) return 0ll;

    int mid = (cur_l + cur_r) / 2;
    return query2(l, r, cur_l, mid, ind * 2) + query2(l, r, mid + 1, cur_r, ind * 2 + 1);
  };
  
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    add2(a[i], 1);
  }
  for (int i = 0; i < n; i++)
  {
    ans += query(a[i] + 1, am - 1, 0, am - 1, 1) * query2(0, a[i] - 1, 0, am - 1, 1);
    // cout << query2(a[i] + 1, n - 1, 0, n - 1, 1) << ' ' << query(0, a[i] - 1, 0, n - 1, 1) << endl;
    add2(a[i], -1);
    add(a[i], 1);
  }
  cout << ans << endl;
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