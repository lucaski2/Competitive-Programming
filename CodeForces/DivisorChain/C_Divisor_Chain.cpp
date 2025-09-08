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

int skibidi(int n)
{
  int ret = 1;
  
  for (int i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
    {
      ret = i;
      n /= i;
    }
  }
  // if (n > 1) return n;
  return ret;
}


void solve(int tc)
{
  int n;
  cin >> n;

  vector<int> ans;
  ans.push_back(n);
  while (n > 1)
  {
    if (n % 2 == 1)
    {
      n -= skibidi(n);
      ans.push_back(n);
    }
    else
    {
      n /= 2;
      ans.push_back(n);
    }
  }
  cout << ans.size() << endl;
  iter (i, ans.size())
  {
    cout << ans[i] << ' ';
  }
  cout << endl;
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