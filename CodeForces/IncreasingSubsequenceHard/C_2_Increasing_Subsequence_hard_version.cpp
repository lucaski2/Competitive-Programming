#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

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
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  int l = 0, r = n - 1;
  string ans = "";
  int lowest = 0;
  while (l <= r and (l == r or a[l] != a[r]))
  {
    if (l == r and a[l] > lowest)
    {
      lowest = a[l];
      l++;
      ans += "L";
    }
    else if (a[l] < a[r] and a[l] > lowest)
    {
      lowest = a[l];
      l++;
      ans += "L";
    }
    else if (a[r] < a[l] and a[r] > lowest)
    {
      lowest = a[r];
      r--;
      ans += "R";
    }
    else break;
  }

  // case 1, r > l 
  if (r < l)
  {
    cout << ans.size() << endl;
    cout << ans << endl;
    return;
  }

  // case 2, a[r] and a[l] >= lowest
  if (a[r] <= lowest and a[l] <= lowest)
  {
    cout << ans.size() << endl;
    cout << ans << endl;
    return;
  }
  
  
  // try left
  int cur = l;
  int sz = 0;
  int temp = lowest;
  while (a[cur] > lowest)
  {
    sz++;
    lowest = a[cur];
    cur++;
  }

  cur = r;
  int sz2 = 0;
  int lowest2 = temp;
  while (a[cur] > lowest2)
  {
    sz2++;
    lowest2 = a[cur];
    cur--;
  }

  if (sz > sz2)
  {
    while (sz--)
    {
      ans += "L";
    }
  }

  else
  {
    while (sz2--)
    {
      ans += "R";
    }
  }

  cout << ans.size() << endl;
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