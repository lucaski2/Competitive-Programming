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

int m(string s)
{
  int num = 1;
  for (char x : s)
  {
    num *= x - '0';
  }
  return num;
}

string a, b;
int ans = 0;
string best = a;
void rec(string s, int size, bool has_less_so_far)
{
  if (a.size() != b.size() or a[s.size()] != a[b.size()])
  {
    has_less_so_far = true;
  }
  // optimal size is always b.size() or b.size() - 1
  if (s.size() >= size)
  {
    if (m(s) > ans)
    {
      ans = m(s);
      best = s;
    }
    return;
  }
  
  // choice 1
  if (has_less_so_far)
  {
    string cur = s;
    cur += b[s.size()] - 1;
    if (cur != "0")
    {
      int num = m(cur);
      num *= pow(9, size - cur.size());
      if (num > ans)
      {
        ans = num;
        best = cur;
      }
    }
  }

  s += b[s.size()];
  rec(s, size, has_less_so_far);

}


void solve(int tc)
{
  cin >> a >> b;
  if (pow(10, (b).size() - 1) - 1 >= stoll(a))
  {
    ans = pow(9, (int)((b).size() - 1));
    // cout << b.size() << endl;
    
    best = "";
    for (int i = 0; i < (int)(b.size() - 1); i++)
    {
      best += '9';
    }
  }
  rec("", (b).size(), false);
  while (m(best) < ans)
  {
    best += '9';
  }


  cout << best << endl;

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