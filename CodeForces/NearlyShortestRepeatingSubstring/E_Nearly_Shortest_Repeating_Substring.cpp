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

  // find divisors

  vector<int> divisors;
  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      divisors.push_back(i);
    }
  }



  for (int div : divisors)
  {
    vector<vector<int>> diffs(div, vector<int>(26));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      diffs[i % div][s[i]-'a']++;
    }

    for (vector<int> diff : diffs)
    {
      int n1 = 0;
      int n2 = 0;
      for (int j = 0; j < diff.size(); j++)
      {
        if (diff[j] == 0) continue;
        if (n1 == 0)
          n1 = diff[j];
        else if (n2 == 0)
          n2 = diff[j];
        else
          cnt += 100;
      }

      cnt += min(n1, n2);
    }
    if (cnt <= 1)
    {
      cout << div << endl;
      break;
    }
    

  }











}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}