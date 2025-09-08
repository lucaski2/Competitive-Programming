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

unordered_map<int, int> gd(int n)
{
  unordered_map<int, int> ret;
  for (int i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
    {
      n /= i;
      ret[i]++;
    }
  }
  if (n > 1) ret[n]++;
  return ret;
}

void solve(int tc)
{
  int a, b, k;
  cin >> a >> b >> k;

  unordered_map<int, int> da = gd(a);
  unordered_map<int, int> db = gd(b);
  int cnt1 = 0;
  int cnt2 = 0;
  for (auto el : da) cnt1 += el.second;
  for (auto el : db) cnt2 += el.second;


  if (cnt1 + cnt2 < k)
  {
    cout << "NO" << endl;
    return;
  }
  bool dl = false;
  bool dr = false;
  for (auto el : da)
  {
    if (el.second > db[el.first])
      dl = true;
  }
  for (auto el : db)
  {
    if (el.second > da[el.first]) dr = true;
  }
  if (k == 1 and ((dl and dr) or !(dl or dr)))
  {
    cout << "NO" << endl;
  }
  else 
    cout << "YES" << endl;
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