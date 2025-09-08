#include <bits/stdc++.h>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second
 
using namespace std;
 
 
 
 
template<typename T>
struct Seggy {
    int N, ql, qr;
    vector<T> data;
    T def, val;
    void init(int _N, T _def) {
        N = _N;
        def = _def;
        data.resize(4 * N, def);
    }
    T comb(T a, T b) { return (a < b ? a : b); }
    #define m ((l + r) / 2)
    T qry(int n, int l, int r) {
        if(r < ql || qr < l) { return def; }
        if(ql <= l && r <= qr) { return data[n]; }
        return comb(qry(2*n, l, m), qry(2*n+1, m + 1, r));
    }
    void upd(int n, int l, int r) {
        if(l == r) { data[n] = val; return; }
        if(ql <= m) { upd(2*n, l, m); }
        else { upd(2*n+1, m + 1, r); }
        data[n] = comb(data[2*n], data[2*n+1]);
    }
    #undef m
    T query(int l, int r) { ql = l, qr = r; return qry(1, 0, N - 1); }
    void update(int idx, T v) { ql = idx, val = v; upd(1, 0, N - 1); }
};

template<typename T>
struct sparse_table
{
    const int LOG = 20;
    int n;
    vector<vector<T> > dp;
    T merge(T a, T b){
        return min(a, b);
    }
    sparse_table(vector<T> &a){
        n = a.size();
        dp.resize(LOG);
        dp[0] = a;
 
        for (int id = 1; id < LOG; id++)
        {
            dp[id].resize(n);
            for (int j = 0; j < n; j++)
            {
                dp[id][j] = dp[id - 1][j];
                int next_id = j + (1 << (id - 1));
                if(next_id < n){
                    dp[id][j] = merge(dp[id][j], dp[id - 1][next_id]);
                }
            }
        }
    }
    T query(int l, int r){
        int d = r - l + 1;
        int id = __builtin_clzll(1) - __builtin_clzll(d); 
        int shift = (1LL << id);
        return merge(dp[id][l], dp[id][r - shift + 1]);
    }
};

 
vector<vector<int>> paths;
vector<int> ans;
int n, m;
vector<vector<int>> tree;

pair<int, unique_ptr<map<int, int>>> dfs2(int cur, int par)
{
    auto gret = make_unique<map<int, int>>();
    int an = 0;

    for (int ele : paths[cur])
    {
        (*gret)[ele]++;
        an++;
    }

    for (int neighbor : tree[cur])
    {
        if (neighbor == par) continue;

        auto [am, ret] = dfs2(neighbor, cur);
        an += am;

        if (gret->size() < ret->size())
            gret.swap(ret); // Move the larger map into gret

        for (auto& ele : *ret)
            (*gret)[ele.first] += ele.second;
    }

    ans[cur] += an;

    if (gret->count(cur))
    {
        an -= (*gret)[cur];
        gret->erase(cur);
    }

    return {an, std::move(gret)};
}
 
void solve(int tc)
{
  cin >> n >> m;
 
  tree.resize(n);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
 
  int time = 0;
  
  vector<int> start(n);
  vector<pair<int, int>> et;
  function<void(int, int, int)> dfs = [&](int cur, int par, int depth)
  {
    start[cur] = time++;
    et.push_back({depth, cur});
    for (int neighbor : tree[cur])
    {
      if (neighbor == par) continue;
      dfs(neighbor, cur, depth + 1);
      time++;
      et.push_back({depth, cur});
    }
  };
  dfs(0, -1, 0);

  sparse_table<pair<int, int>> seggy(et);
 
  paths.resize(n);
  ans.resize(n);
  
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    int lca = seggy.query(min(start[a], start[b]), max(start[a], start[b])).s;
    ans[lca]--;
    paths[a].push_back(lca);
    paths[b].push_back(lca);
  }
  dfs2(0, -1);
  for (int ele : ans)
    cout << ele << ' ';
  cout << endl;

}
 

 
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}