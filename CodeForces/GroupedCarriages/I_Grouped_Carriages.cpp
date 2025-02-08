#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve(int tc)
{
  int n;
  cin >> n;
  
  vector<int> a(n);
  vector<int> d(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> d[i];
  
  int l = 0, r = 1e10;
  int ans = 1e10;
  while (l <= r)
  {
    int mid = (l + r) / 2;
  
    vector<vector<pair<int, int>>> starts(n);
    
    for (int i = 0; i < n; i++)
    {
      if (mid >= a[i])
      {
        continue;
      }
      starts[max(0ll, i - d[i])].push_back({min(n - 1, i + d[i]), a[i] - mid});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
      for (pair<int, int> it : starts[i])
      {
        pq.push(it);
      }
      
      
      if (!pq.empty() and pq.top().first < i)
      {
        ok = false;
        break;
      }
      
      int am = mid - a[i];
      
      while (am > 0 and !pq.empty())
      {
        int mx = min(am, pq.top().second);
        if (mx == pq.top().second)
        {
          pq.pop();
        }
        am -= mx;
      }

    }
    if (pq.size() != 0) ok = false;
    
    if (ok)
    {
      ans = min(ans, mid);
      r = mid - 1;
    }
    else l = mid + 1;
  }
  
  cout << ans << endl;
  
}



signed main()
{
  int t = 1;
  for (int tc = 1; tc <= t; tc++)
  {
    solve(tc);
  }
}


