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
  int n, k, m;
  cin >> n >> k >> m;
  string s;
  cin >> s;
  
  int cur_ind = 0;
  bool ok = true;
  string fin;
  for (int i = 0; i < n; i++)
  {
    set<int> cur;
    while (true)
    {
      if (cur_ind == m)
      {
        ok = false;
        break;
      }
      cur.insert(s[cur_ind]);
      if (cur.size() == k)
      {
        fin += s[cur_ind];
        break;
      }
      cur_ind++;
    }
    if (!ok)
    {
      for (int j = 0; j < k; j++)
      {
        if (cur.find(j + 'a') == cur.end())
        {
          fin += j + 'a';
          break;
        }
      }
      break;
    }
  }
  if (ok)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
    for (; fin.size() < n;)
    {
      fin += 'a';
    }
    cout << fin << endl;

  }
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