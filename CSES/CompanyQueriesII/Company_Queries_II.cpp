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



void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  vector<vector<int>> tree(n);
  for (int i = 0; i < n - 1; i++)
  {
    int a;
    cin >> a;
    tree[a-1].push_back(i + 1);
  }

  int time = 0;
  Seggy<pair<int, int>> seggy;
  seggy.init(2 * n, {INT_MAX, INT_MAX});
  vector<int> start(n);

  function<void(int, int)> dfs = [&](int cur, int depth)
  {
    start[cur] = time;
    seggy.update(time++, {depth, cur});
    for (int neighbor : tree[cur])
    {
      dfs(neighbor, depth + 1);
      seggy.update(time++, {depth, cur});
    }
  };
  dfs(0, 0);


  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    cout << seggy.query(min(start[a], start[b]), max(start[a], start[b])).s + 1 << endl;
  }
}

void solve2(int tc)
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> tree(n);
    for(int i = 0; i < n - 1; i++){
        int p;
        cin >> p; 
        tree[p-1].push_back(i+1);
    }

    // we'll have exactly 2*n stamps (entry+exit for every node)
    int M = 2 * n;
    Seggy<pair<int,int>> seggy;
    seggy.init(M, {INT_MAX, INT_MAX});

    vector<int> start(n), euler_node(M);
    int timer = 0;

    function<void(int,int)> dfs = [&](int u, int depth){
        // record first‐occurrence
        start[u] = timer;
        // record in seg-tree: depth + position
        seggy.update(timer, {depth, timer});
        euler_node[timer] = u;
        timer++;

        for(int v : tree[u]){
            dfs(v, depth+1);
            // after coming back, re-stamp u
            seggy.update(timer, {depth, timer});
            euler_node[timer] = u;
            timer++;
        }
    };

    dfs(0, 0);

    while(q--){
        int a, b;
        cin >> a >> b;
        --a; --b;
        int L = min(start[a], start[b]);
        int R = max(start[a], start[b]);
        auto [depth_min, pos] = seggy.query(L, R);
        int lca = euler_node[pos];
        cout << (lca+1) << "\n";
    }
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