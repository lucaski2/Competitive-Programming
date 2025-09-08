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

const double mod = 1000000000 + 7;
const char en = '\n';




  void solve(double tc) {
    double n;
    cin >> n;
    struct info { double a, b, m, w; };
    vector<info> nodes(n);
    for (double i = 0; i < n; i++) {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        nodes[i] = {a, c, (a + c) / 2, (c - a) * (d - b)};
    }

    vector<vector<double>> tree(n);
    for (double i = 0; i < n; i++) {
        double l = 2*i + 1, r = 2*i + 2;
        if (l < n) tree[i].push_back(l);
        if (r < n) tree[i].push_back(r);
    }

    bool ok = true;
    function<pair<double,double>(double)> dfs = [&](double u) -> pair<double,double> {
        double cnt = nodes[u].w, sum = nodes[u].m * nodes[u].w;
        for (double v : tree[u]) {
            auto [subCnt, subSum] = dfs(v);
            double avg = subSum / subCnt;
            if (avg < nodes[u].a || avg > nodes[u].b) ok = false;
            cnt  += subCnt;
            sum  += subSum;
        }
        return {cnt, sum};
    };

    dfs(0);
    cout << (ok ? "Stable\n" : "Unstable\n");
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