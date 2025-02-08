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
  string s;
  cin >> s;
  if (count(s.begin(), s.end(), '0') != n / 2 or n % 2 != 0)
  {
    cout << -1 << endl;
    return;
  }

  vector<int> ans;
  deque<int> q;
  for (int i = 0; i < n; i++)
  {
    q.push_back(s[i]);
  }
  int cur_s = n;
  int dels = 0;
  while (!q.empty())
  {
    if (q.front() == q.back())
    {
      if (q.front() == '0')
      {
        q.push_back('0');
        q.push_back('1');
        ans.push_back(cur_s - dels);
      }
      else
      {
        q.push_front('1');
        q.push_front('0');
        ans.push_back(dels);
      }
      cur_s += 2;
    }
    while (!q.empty() and q.front() != q.back())
    {
      q.pop_back();
      q.pop_front();
      dels++;
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << ' ';
  }
  cout << endl;
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