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
  string s;
  cin >> s;

  set<char> chars;
  set<char> nums;
  string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string num = "1234567890";
  for (char a : al)
  {
    chars.insert(a);
  }
  for (char nu : num)
  {
    nums.insert(nu);
  }


  // check if type 1
  int n = s.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (chars.find(s[i]) != chars.end())
    {
      cnt++;
    }
  }
  bool type;
  if (cnt == 2)
  {
    if (s[0] == 'R' and nums.find(s[1]) != nums.end())
    {
      type = 1;
    }
    else type = 0;
  }

  else type = 0;

  if (type)
  {
    // row column
    int num1 = 0;
    int end = 0;
    for (int i = 1; chars.find(s[i]) == chars.end(); i++)
    {
      num1 *= 10;
      num1 += s[i] - '0';
      end = i;
    }

    int num2 = 0;
    for (int i = end + 1; i < n; i++)
    {
      num2 *= 10;
      num1 += s[i] - '0';
    }

    // convert to base 26
    
    


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