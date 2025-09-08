#include <bits/stdc++.h>
// #define int long long
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
  vector<int> temp(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    temp[i] = a[i];
  }
  
  // coord compression
  sort(temp.begin(), temp.end());
  
  map<int, int> inds;
  int last = 0;
  for (int i = 0; i < n; i++)
  {
    if (inds.find(temp[i]) == inds.end())
    {
      inds[temp[i]] = last;
      last++;
    }
  }

  for (int i = 0; i < n; i++)
  {
    a[i] = inds[a[i]];
  }
  while (__builtin_popcount(last) != 1)
  {
    last++;
  }
  vector<int> segtree(last * 2);


  function<void(int, int)> add = [&](int ind, int am)
  {
    ind += last;
    for (; ind > 0; ind /= 2)
    {
      segtree[ind] = max(segtree[ind], am);
    }
  };

  function<int(int, int, int, int, int)> query = [&](int l, int r, int cur_l, int cur_r, int ind)
  {
    if (cur_l >= l and cur_r <= r) return segtree[ind];
    if (cur_l > r or cur_r < l) return 0;
    
    int mid = (cur_l + cur_r) / 2;

    return max(query(l, r, cur_l, mid, ind * 2), query(l, r, mid + 1, cur_r, ind * 2 + 1));
  };
  int ans = 0;
  for (int i = 0; i < n; i++)
  { 
    int am = query(0, a[i] - 1, 0, last - 1, 1) + 1;
    add(a[i], am);
    ans = max(ans, am);
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