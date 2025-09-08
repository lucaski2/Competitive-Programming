#include <bits/stdc++.h>
// #pragma GCC target ("avx,avx2,fma")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
#define int long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;



ld dist(pair<ld, ld> a, pair<ld, ld> b)
{
  return (abs(a.f - b.f) * abs(a.f - b.f) + abs(a.s - b.s) * abs(a.s - b.s));
}

bool touch(pair<ld, ld> a, pair<ld, ld> b)
{
  ld d = dist(a, b);
  // cout << d << ' ' << a.s + b.s << endl;
  return d <= (a.s + b.s) * (a.s + b.s);
}


void solve(int tc)
{
  int n;
  cin >> n;

  vector<pair<ld, ld>> points(n);
  for (int i = 0; i < n; i++)
    cin >> points[i].f >> points[i].s;
  sort(all(points));
  vector<pair<ld, ld>> st;
  
  for (int i = 0; i < n; i++)
  {
    ld rad = INT_MAX;

    while (st.size())
    {
      pair<ld, ld> cur = st.back();
      ld eps = 1e-9;
      ld l = eps, r = points[i].s;
      ld best = eps;
      while (l + eps <= r)
      {
        ld mid = (l + r) / 2;
        if (!touch(cur, {points[i].f, mid}))
        {
          l = mid + eps;
          best = mid;
        }
        else r = mid - eps;
      }
      rad = min(best, rad);

      if (best > cur.s)
      {
        st.pop_back();
      }
      else
      {
        break;
      }
    }
    rad = min(rad, points[i].s);
    cout << setprecision(3) << fixed << rad << '\n';

    st.push_back({points[i].f, rad});
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