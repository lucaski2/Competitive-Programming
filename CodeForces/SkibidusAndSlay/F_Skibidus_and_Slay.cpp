#include <bits/stdc++.h>
// #define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first
#define s second

using namespace std;

const int mod = 1000000000 + 7;
const char en = '\n';

int pow(int a, int b, int m)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

void solve(int tc)
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> inds(n);
  
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    inds[--a[i]].push_back(i);
  }
  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  map<int, int> cnt;
  string ans(n, '0');
  
  for (int i = 0; i < n; i++)
  {
    for (int ele : inds[i])
    {
      cnt[ele]++;
      for (int neighbor : graph[ele])
      {
        cnt[neighbor]++;
        if (cnt[neighbor] >= 2) ans[i] = '1';
      }
      if (cnt[ele] >= 2) ans[i] = '1';
    }
    cnt.clear();
  }
  cout << ans << endl;



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
