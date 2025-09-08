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


const int mod = 1000000000 + 7;
const char en = '\n';


vector<int> factorial(1e6 + 1, 1);
int pow(int a, int b, int m)
{ 
  int ans = 1; 
  while(b) 
  { 
    if (b&1) ans = (ans*a) % m; 
    b /= 2; 
    a = (a*a) % m; 
  } 
  return ans; 
}

void precomp()
{ 
  for (int i = 1; i <= 1e6; i++)
  {
    factorial[i] = (factorial[i - 1] * i) % mod;
  }
}

int choose(int n, int k)
{
  return ((factorial[n] * pow(factorial[k], mod - 2, mod)) % mod * pow(factorial[n - k], mod - 2, mod)) % mod;
}


void solve(int tc)
{
  precomp();



  int k, n, l;
  cin >> k >> n >> l;

  string s;
  cin >> s;
  string temp = s;
  // l -= 1;
  // while (l--)
  // {
  //   s += temp;
  // }


  int ans = 1;
  int Os = 0;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    Os += (s[i] == 'O');
    if (s[i] == 'O') continue;

    ans *= choose(Os, k);
    ans %= mod;
    Os -= k;
  }
  cout << pow(ans, l, mod) << endl;
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