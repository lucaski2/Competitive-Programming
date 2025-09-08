#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;



// Problem URL here:
// Start time here: 
// End time here:

const char en = '\n';


int mx = 1e6 + 5;
vector<int> tot(mx, 1);
vector<vector<pair<int, int>>> factors(mx);
vector<int> psum(mx);

void precomp()
{
  for (int i = 2; i < mx; i++)
  {
    if (factors[i].size()) continue;
    for (int j = i; j < mx; j += i)
    {
      int am = j;
      int cnt = 0;
      while (am % i == 0)
      {
        am /= i;
        cnt++;
      }
      factors[j].push_back({i, cnt});
    }
  }

  for (int i = 2; i < mx; i++)
    for (pair<int, int> fact : factors[i]) 
      tot[i] *= pow(fact.f, fact.s - 1) * (fact.f - 1);
  
  for (int i = 1; i < mx; i++)
    psum[i] = psum[i - 1] + tot[i];
}

void solve(int tc)
{
  int n, m;
  cin >> n >> m;

  // get number of coprime ordered pairs under x
  
  vector<int> am(n + 1);
  int s = 0;

  for (int i = 1; i < n; i++)
  {
    int cur = (psum[n / (i + 1)] - 1) / i;
    s += cur * i;
    am[i] = cur;
  }
  if (s < m)
  {
    cout << -1 << endl;
    return;
  }

  int ans = 0;
  
  for (int i = n - 1; i >= 1; i--)
  {
    int rem = min(am[i], m / i);
    ans += (i + 1) * rem;
    m -= i * rem;

  }

  cout << ans << en;
  

}

signed main()
{
  precomp();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}