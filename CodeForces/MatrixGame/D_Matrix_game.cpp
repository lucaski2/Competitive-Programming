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

const int mod = 1000000000 + 7;
const char en = '\n';



int pow(int a, int b, int m){ int ans = 1; while(b) { if (b&1) ans = (ans*a) % m; b /= 2; a = (a*a) % m; } return ans; }



vector<int> fact = {1};
vector<int> inv;
int mx = 1e5 + 1;
void factorial()
{
  if (fact.size() == 1)
    for (int i = 1; i < mx; i++)
      fact.push_back(fact.back() * i % mod);
  if (inv.empty())
    for (int i = 0; i < mx; i++)
      inv.push_back(pow(fact[i], mod - 2, mod));
}

void solve(int tc)
{
  int a, b, k;
  cin >> a >> b >> k;
  
  int n = k * a - k + 1;
  n %= mod;

  int run = 1;
  for (int i = 0; i < a; i++)
  {
    run *= (n - i + mod * (int)1e5) % mod;;
    run %= mod;
  }

  int m = ((run * inv[a] % mod) * k % mod * (b - 1) + 1) % mod;
  cout << n << ' ' << m << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  factorial();
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}