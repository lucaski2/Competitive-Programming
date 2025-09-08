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


void solve(int tc)
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> cnts(200);
  vector<bool> is(200);
  int distinct = 0;
  for (int i = 0; i < n; i++)
    is[s[i] - 'A'] = true;



  iter(i, 200) distinct += is[i];

  int cur = 0;
  int right = 0;
  int ans = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    while (cur < distinct and right < n)
    {
      cnts[s[right]]++;
      cur += (cnts[s[right]] == 1);
      right++;
    }

    if (cur == distinct) ans = min(ans, right - i);
    // cout << i << ' ' << right << endl;
    cnts[s[i]]--;
    cur -= (cnts[s[i]] == 0);
  }
  cout << ans << endl;
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