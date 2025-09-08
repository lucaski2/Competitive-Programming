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


struct Seggy
{
  vector<int> tree;
  int sz;
  Seggy(int n) : tree(n * 2), sz(n) {}

  void add(int ind, int am)
  {
    for (ind += sz; ind > 0; ind /= 2)
    {
      tree[ind] += am;
    }
  }

  int query(int l, int r, int cur_l, int cur_r, int ind)
  {
    if (cur_l > r or cur_r < l) return 0;
    if (cur_l >= l and cur_r <= r) return tree[ind];

    int mid = (cur_l + cur_r) / 2;
    return query(l, r, cur_l, mid, ind * 2) + query(l, r, mid + 1, cur_r, ind * 2 + 1);
  }
};


void solve(int tc)
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    
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