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

bool check(int n)
{
  string s = to_string(n);
  if (count(s.begin(), s.end(), '7') > 0)
  {
    return true;
  }
  return false;
}

void solve(int tc)
{
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 1; i <= 10; i++)
  {
    nums.push_back(pow(10, i) - 1);
  }
  if (check(n))
  {
    cout << 0 << endl;
    return;
  }
  for (int i = 1; i < 100; i++)
  {
    for (int num : nums)
    {
      if (check(n + num * i))
      {
        cout << i << endl;
        return;
      }
    }
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