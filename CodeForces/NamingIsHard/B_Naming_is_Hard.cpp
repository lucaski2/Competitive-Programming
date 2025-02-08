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
  int n;
  cin >> n;
  vector<int> a(n);
  
  map<int, int> counts;
  
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    counts[a[i]]++;
  }

  vector<bool> distinct(n);
  for (int i = 0; i < n; i++)
  {
    distinct[i] = counts[a[i]] == 1;
  }

  int l = 0;
  int r = 0;
  int ans = 0;
  int cur = 0;
  for (int i = 0; i < n; i++)
  {
    if (distinct[i])
    {
      cur++;
      if (cur > ans)
      {
        ans = cur;
        l = i - cur + 1;
        r = i;
      }
    }
    else cur = 0;
  }
  cout << l + 1 << ' ' << r + 1 << endl;


  


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