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
  int n, t;
  cin >> n >> t;
  int k;
  cin >> k;
  int l = 1, r = n;
  // find leftmost index 
  int ans = 0;
  while (l <= r)
  {
    int mid = (l + r) / 2;

    cout << '?' << ' ' << 1 << ' ' << mid << endl;
    cout.flush();

    int am;
    cin >> am;

    // zeros is mid - am
    if (mid - am >= k)
    {
      ans = mid;
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }

  cout << "! " << ans << endl;






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