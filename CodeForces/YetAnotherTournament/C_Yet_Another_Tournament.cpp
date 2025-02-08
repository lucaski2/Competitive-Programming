#include <bits/stdc++.h>
#define int long long
using namespace std;

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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }



  int l = 0, r = n - 1;
  int best = -1;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    bool ok = false;
    // check 1, sum excluding mid is > mid
    vector<int> cur;
    for (int i = 0; i < n; i++)
    {
      if (i != mid)
      {
        cur.push_back(a[i]);
      }
    }

    sort(cur.begin(), cur.end());
    int am = m;
    for (int i = 0; i < n - 1; i++)
    {
      if (am < cur[i])
      {
        break;
      }
      am -= cur[i];
      if (i >= mid)
      {
        ok = true;
        break;
      }
    }

    am = m;
    if (a[mid] <= m)
    {
      am -= a[mid];
      int ind = 1;
      for (int i = 0; i < n - 1; i++)
      {
        if (am < cur[i])
        {
          break;
        }
        am -= cur[i];
        ind++;
      }
      if (ind >= mid) ok = true;
    }

    if (ok)
    {
      best = max(best, mid);
      l = mid + 1;
    }
    else r = mid - 1;
  }
  cout << n - best << endl;

}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}