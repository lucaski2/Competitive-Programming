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
  int k;
  cin >> k;
  // cout << k << endl;
  // find two integers such that a * b == k - 2
  int target = k - 2;
  set<int> prevs;
  bool ok = false;
  for (int i = 0; i < k; i++)
  {
    int a;
    cin >> a;
    if (target % a == 0)
    {
      if (prevs.find(a) != prevs.end() and !ok)
      {
        cout << target / a << ' ' << a << endl;
        ok = true;
      }
      prevs.insert(target / a);
      // cout << a << endl;
    }
  }
  // cout << target << endl;
  // cout << endl;



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