#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define int long long
#define f first 
#define s second

using namespace std;

// Problem URL here:
// Start time here: 
// End time here:


const int mx = 1e5 + 5;
vector<vector<int>> divisors(mx);

void precomp()
{
  for (int i = 2; i < mx; i++)
  {
    for (int j = i; j < mx; j += i)
    {
      divisors[j].push_back(i);
    }
  }

}

void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  map<int, vector<int>> inds;
  for (int i = 0; i < n; i++)
  {
    inds[a[i]].push_back(i);
  }

  for (int i = 0; i < q; i++)
  {
    int k, l, r;
    cin >> k >> l >> r;
    l--; r--;
    int ind = l - 1;
    int ans = 0;
    while (true)
    {
      pair<int, int> best = {INT_MAX, INT_MAX};
      
      for (int div : divisors[k])
      {
        // optimize this?
        auto ptr = upper_bound(all(inds[div]), ind);
        if (ptr == inds[div].end()) continue;

        if (best.f > *ptr)
          best = {*ptr, div};
      }

      // not necessary to optimize

      if (best.f > r) break;
      ans += k * (best.f - ind - 1);
      ind = best.f;

      while (k % best.s == 0) k /= best.s;

      ans += k;
    }

    ans += (r - ind) * k;
    cout << ans << '\n';

  }
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  precomp();
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}