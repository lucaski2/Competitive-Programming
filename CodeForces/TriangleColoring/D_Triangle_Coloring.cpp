#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second
#define iter(i, n) for (int i = 0; i < n; i++)

using namespace std;

using vi = vector<int>;


using namespace __gnu_pbds;


template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// Problem URL here:
// Start time here: 
// End time here:

const int mod = 998244353;
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

int factorial(int n)
{
  int am = 1;
  for(int i = 1; i <= n; i++) am = (am * i) % mod;
  return am;
}

int choose(int n, int k)
{
  // return 1;
  return ((factorial(n) * pow(factorial(k), mod - 2, mod)) % mod * pow(factorial(n - k), mod - 2, mod)) % mod;
}




void solve(int tc)
{
  int n;
  cin >> n;
  n /= 3;
  int am = 1;
  iter(i, n)
  {
    vector<int> cur(3);
    cin >> cur[0] >> cur[1] >> cur[2];

    am *= count(all(cur), *min_element(all(cur)));
    am %= mod;
  }
  am *= choose(n, n / 2);
  am %= mod;
  cout << am << endl;



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