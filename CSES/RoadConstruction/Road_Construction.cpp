#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';



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
  multiset<int> largest;
  int cnt = 0;
  
  public:

  DSU(int n) : parents(n), sizes(n, 1)
  {
    for (int i = 0; i < n; i++) parents[i] = i;
    for (int i = 0; i < n; i++) largest.insert(1);
    cnt = n;
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
    if (parents[find(u)] < parents[find(v)]) swap(u, v);
    largest.erase(largest.find(sizes[find(u)]));
    largest.erase(largest.find(sizes[find(v)]));
    sizes[find(u)] += sizes[find(v)];
    largest.insert(sizes[find(u)]);
    cnt -= 1;
    parents[find(v)] = find(u);
  }

  bool connected(int u, int v) 
  {
    return find(u) == find(v);
  }

  int getCnt() 
  {
    return cnt;
  }


  int getLargest() {
    return *largest.rbegin();
  }

};

void solve(int tc)
{
  int n, q;
  cin >> n >> q;
  DSU dsu(n);
  while (q--)
  {
    int a, b;
    cin >> a >> b;
    dsu.unite(a, b);
    cout << dsu.getCnt() << ' ' << dsu.getLargest() << endl;
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