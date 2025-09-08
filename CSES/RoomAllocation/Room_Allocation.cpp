#include <bits/stdc++.h>
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
  
  multimap<pair<int, int>, int> rngs;

  vector<int> ans(n);

  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    rngs.insert({{a, b}, i});
  }
  int am = 0;
  while (!rngs.empty())
  {
    am++;

    auto rng = rngs.lower_bound({0, -1});
    while (rng != rngs.end())
    {
      pair<int, int> cur = rng->first;
      int ind = rng->second;
      rngs.erase(rng);
      rng = rngs.lower_bound({cur.second, INT_MAX});
      ans[ind] = am;
    }
  }
  if (count(all(ans), 0))
  {
    cout << "IMPOSSISLJDFL:kjas;lkjdfa;lskjdf" << endl;
    return;
  }

  cout << am << endl;
  iter(i, n)
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
  // cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}