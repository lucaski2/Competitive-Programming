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



vector<int> nums;

void precomp(string s)
{
  if (s.length() >= 20) return;
  if (s.length() - count(s.begin(), s.end(), '0') > 3) return;
  // cout << s << endl;
  // cout << 'a';
  int num = stoll(s);
  nums.push_back(num);

  for (int i = 0; i < 10; i++)
  {
    // cout << 'b';
    string cur = to_string(num * 10 + i);
    
    precomp(cur);
  }
}


void solve(int tc)
{
  int l, r;
  cin >> l >> r;
  cout << upper_bound(nums.begin(), nums.end(), r) - lower_bound(nums.begin(), nums.end(), l) << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;

  for (int i = 1; i < 10; i++)
  {
    precomp(to_string(i));
  }
  sort(nums.begin(), nums.end());
  // cout << nums.size() << endl;

  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}