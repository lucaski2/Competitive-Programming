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
  multiset<int> a;
  multiset<int> b;
  int s1 = 0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.insert(x);
    s1 += x;
  }
  int s2 = 0;
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    if (a.find(x) != a.end())
    {
      a.erase(a.find(x));
    }
    else b.insert(x);
    s2 += x;
  }
  if (s1 != s2) 
  {
    cout << "NO" << endl;
    return;
  }
  // if (tc != 1) return;
  bool ok = true;
  while (!a.empty() and !b.empty())
  {
    int num = *b.begin();
    queue<int> nums;
    nums.push(num);
    // cout << num << endl;
    while (!nums.empty())
    {

      int cur = nums.front();
      nums.pop();

      if (cur < *a.begin())
      {
        ok = false;
        break;
      }
      else if (a.find(cur) != a.end())
      {
        a.erase(a.find(cur));
      }
      else
      {
        if (cur % 2 == 0)
        {
          nums.push(cur / 2);
          nums.push(cur / 2);
        }
        else 
        {
          nums.push(cur / 2);
          nums.push(cur / 2 + 1);
        }
      }
      if (nums.size() > n)
      {
        ok = false;
        break;
      }
    }
    b.erase(b.find(num));
    if (!ok) break;
  }
  if (a.empty() and b.empty() and ok)
  {
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
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