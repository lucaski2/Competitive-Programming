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

vector<int> segtree;
int n, q;

void add(int l, int r, int cur_l, int cur_r, int am, int ind)
{
  if (cur_l >= l and cur_r <= r)
  {
    segtree[ind] += am;
    return;
  }

  if (cur_l > r or cur_r < l) return;
  

  int mid = (cur_l + cur_r) / 2;
  add(l, r, cur_l, mid, am, ind * 2);
  add(l, r, mid + 1, cur_r, am, ind * 2 + 1);
}

int query(int ind)
{
  ind += n;
  int am = segtree[ind];
  // find sum of all increases along tree

  for (ind /= 2; ind; ind /= 2)
  {
    am += segtree[ind];
  }
  return am;
}

// void build()
// {
//   for (int i = 0; i < n; i++)
//   {
//     segtree[n + i] = a[i];
//   }
// }


void solve(int tc)
{
  cin >> n >> q;
  vector<int> a(n);
  
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  while (__builtin_popcount(n) != 1)
  {
    n++;
    a.push_back(0);
  }

  segtree.resize(2 * n, 0);

  for (int i = 0; i < n; i++)
    segtree[n + i] = a[i];


  for (int i = 0; i < q; i++)
  {
    int type;
    cin >> type;
    // cout << type << endl;
    if (type == 2)
    {
      int k;
      cin >> k;
      cout << query(k - 1) << endl;
    }
    else
    {
      int l, r, x;
      cin >> l >> r >> x;
      add(l - 1, r - 1, 0, n - 1, x, 1);
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