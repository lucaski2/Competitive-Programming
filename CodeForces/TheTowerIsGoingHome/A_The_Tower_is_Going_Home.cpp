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

struct seg 
{
  int l, r, h;
};

void solve(int tc)
{
  int n, m;
  cin >> n >> m;

  vector<int> ver(n);
  iter(i, n) cin >> ver[i];
  vector<seg> hor(m);
  iter(i, m) cin >> seg[i].l >> seg[i].r >> seg[i].h;

  // for each line, find lowest opening

  map<int, int> openings;
  iter(i, m)
  {
    if (openings.find(seg[i].h) == openings.end())
    {
      openings[seg[i].h] = (seg[i].l == 1 ? seg[i].r + 1 : 1);
    }
    else
    {
      openings[seg[i].h] = min(openings[seg[i].h], (seg[i].l == 1 ? seg[i].r + 1 : 1));
    }
  }

  vector<int> lefts;
  for (auto ele : openings)
  {
    lefts.push_back(ele.second);
  }

  sort(lefts.begin(), lefts.end());

  sort(ver.begin(), ver.end());
  int ans = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    ans = min(ans, )
  }








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