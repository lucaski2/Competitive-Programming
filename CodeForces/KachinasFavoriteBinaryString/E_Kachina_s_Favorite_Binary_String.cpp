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
  string s = "";
  int cur = 0;
  for (int i = 2; i <= n; i++)
  {
    cout << "? " << 1 << ' ' << i << endl;
    cout.flush();

    int a;
    cin >> a;
    if (a == 0)
    {
      continue;
    }
    if (cur == 0)
    {
      for (int j = 0; j < i - 1 - a; j++)
      {
        s.push_back('1');
      }
      for (int j = 0; j < a; j++)
      {
        s.push_back('0');
      }
        s.push_back('1');
    }

    else if (cur != a)
    {
        s.push_back('1');
    }
    else s.push_back('0');
    
    cur = a;
  }
  if (cur == 0)
  {
    cout << "! IMPOSSIBLE" << endl;
    return;
  }
  cout << "! " << s << endl;

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