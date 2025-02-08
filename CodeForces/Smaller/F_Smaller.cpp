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
  int q;
  cin >> q;
  vector<int> count1(26, 0), count2(26, 0);
  count1[0] = 1;
  count2[0] = 1;
  int len1 = 1, len2 = 1;
  for (int i = 0; i < q; i++)
  {
    int t, k;
    string s;
    cin >> t >> k >> s;
    // if (tc != 3) continue;
    for (int j = 0; j < s.size(); j++)
    {
      if (t == 1)
      {
        count1[s[j]-'a'] += k;

      }
      else
      {
        count2[s[j] - 'a'] += k;
      }
    }

    if (t == 2) len2 += k * s.size();
    else len1 += k * s.size();

    if (len2 != count2[0]) 
    {
      cout << "YES" << endl;
      continue;
    }

    if (len1 == count1[0])
    {
      cout << (len1 < len2 ? "YES" : "NO") << endl;
      continue;
    }

    cout << "NO" << endl;


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