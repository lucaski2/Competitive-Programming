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



void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  vector<int> cnts(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
    cnts[a[i]]++;
  }

  // there can only be sqrt different counts
  // for each one, you can find it 








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