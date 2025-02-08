#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here: https://codeforces.com/contest/1778/problem/C
// Start time here: 9:05
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

vector<vector<int>> generate_comb(vector<int> &a, int k)
{
  // generate all combinations of length k of a
  vector<vector<int>> res;
  int n = a.size();
  vector<int> cur;
  function<void(int)> gen = [&](int ind)
  {
    if (cur.size() == k)
    {
      res.push_back(cur);
      return;
    }
    if (ind == n) return;
    cur.push_back(a[ind]);
    gen(ind + 1);
    cur.pop_back();
    gen(ind + 1);
  };

  gen(0);
  return res;

}



void solve(int tc)
{
  int n, k;
  cin >> n >> k;

  string temp1;
  string temp2;
  cin >> temp1 >> temp2;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
  {
    a[i] = temp1[i] - 'a';
    b[i] = temp2[i] - 'a';
  }
  // if (tc != 1) return;
  set<int> s;
  for (int i = 0; i < n; i++)
  {
    s.insert(a[i]);
  }
  vector<int> chars;
  for (int el : s)
  {
    chars.push_back(el);
  }
  vector<vector<int>> combs = generate_comb(chars, min(k, (int)chars.size()));
  int ans = 0;
  for (vector<int> comb : combs)
  {
    vector<bool> is_true(26);
    for (int el : comb)
    {
      is_true[el] = true;
    }

    int am = 0;

    int cur_am = 0;
    for (int i = 0; i < n; i++)
    {
      if (a[i] == b[i] or is_true[a[i]])
      {
        cur_am++;
      }
      else
      {
        am += (cur_am + 1) * (cur_am) / 2;
        cur_am = 0;
      }
    }
    if (cur_am > 0)
    {
      am += (cur_am) * (cur_am + 1) / 2;
    }

    ans = max(ans, am);
  }
  cout << ans << endl;
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