#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second
#define iter(i, n) for (int i = 0; i < n; i++)

using namespace std;

using vi = vector<int>;


// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';


template<class T> using ordered_statistics_tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int pow(int a, int b, int m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}



void solve(int tc)
{
  ifstream cin("bphoto.in");
  ofstream cout("bphoto.out");
  int n;
  cin >> n;
  vi a(n);
  iter(i, n)
  {
    cin >> a[i];
  }
  ordered_statistics_tree<pair<int, int>> left;
  ordered_statistics_tree<pair<int, int>> right;
  iter(i, n)
  {
    right.insert({a[i], i});
  }

  int ans = 0;

  iter(i, n)
  {
    int left_am = left.size() - left.order_of_key({a[i], INT_MAX});
    int right_am = right.size() - right.order_of_key({a[i], INT_MAX});
    if (left_am * 2 < right_am or right_am * 2 < left_am) ans++;

    right.erase({a[i], i});
    left.insert({a[i], i});
  }
  cout << ans << endl;
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