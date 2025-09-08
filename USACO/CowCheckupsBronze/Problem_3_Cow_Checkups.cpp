#include <bits/stdc++.h>
#define int long long
using namespace std;

// Problem URL here: https://usaco.org/index.php?page=viewproblem2&cpid=1469
// Start time here: 6:22 pm
// End time here: 7:02 pm

const int mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

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
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int j = 0; j < n; j++)
    cin >> b[j];
  

  vector<int> ans(n + 1);
  vector<vector<short>> dp(n, vector<short>(n));

  for (int i = 0; i < n; i++)
  {
    int s = 0;
    for (int j = 0; j < n; j++)
    {
      s += a[j] == b[j];
    }

    ans[s]++;
    int l = i;
    int r = i;
    l--; r++;
    int last = s;
    for (; l >= 0 and r < n; l--, r++)
    {
      // check diff from switch
      int before = (a[l] == b[l]) + (a[r] == b[r]);
      int after = (a[l] == b[r]) + (a[r] == b[l]);
      int cur = last + (after - before);
      ans[cur]++;
      last = cur;
    }
  }

  for (int i = 0; i < n - 1; i++)
  {
    int s = 0;
    for (int j = 0; j < n; j++)
    {
      if (i == j or j == i + 1)
        continue;

      s += a[j] == b[j];
    }

    s += (a[i] == b[i + 1]) + (a[i + 1] == b[i]);
    int l = i;
    int r = i + 1;
    ans[s]++;
    l--; r++;

    int last = s;


    for (; l >= 0 and r < n; l--, r++)
    {
      // check diff from switch
      int before = (a[l] == b[l]) + (a[r] == b[r]);
      int after = (a[l] == b[r]) + (a[r] == b[l]);
      int am = last + (after - before);
      ans[am]++;
      last = am;
    }

  }


  for (int i = 0; i < n + 1; i++)
  {
    cout << ans[i] << endl;
  }

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