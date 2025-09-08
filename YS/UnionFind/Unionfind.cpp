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
class DSU
{
  private:
  vector<int> parents, sizes;
  
  public:

  DSU(int n) : parents(n), sizes(n, 1)
  {
    for (int i = 0; i < n; i++) parents[i] = i;
  }

  int find(int u) 
  {
    if (parents[u] == u) return u;
    return parents[u] = find(parents[u]);
    // return 0;
  }

  void unite(int u, int v)
  {
    if (find(u) == find(v)) return;
    if (parents[find(u)] > parents[find(v)]) swap(u, v);
    sizes[find(u)] += sizes[find(v)];
    parents[find(v)] = find(u);
  }

  bool connected(int u, int v) 
  {
    return find(u) == find(v);
  }
};

void solve(int tc)
{
  int n, q;
  cin >> n >> q;
  DSU dsu(n);
  while (q--)
  {
    int type;
    cin >> type;
    if (type == 0)
    {
      int a, b;
      cin >> a >> b;
      // a--; b--;
      dsu.unite(a, b);
    }
    else
    {
      int a, b;
      cin >> a >> b;
      // a--; b--;
      cout << dsu.connected(a, b) << endl;
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