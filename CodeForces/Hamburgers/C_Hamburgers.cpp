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

struct ingr
{
  int burger;
  int cur;
  int cost;
};

void solve(int tc)
{
  string s;
  cin >> s;
  vector<ingr> ingredients(3);
  int a, b, c, x, y, z, m;
  cin >> a >> b >> c >> x >> y >> z >> m;
  ingredients[0] = {count(s.begin(), s.end(), 'B'), a, x};
  ingredients[1] = {count(s.begin(), s.end(), 'S'), b, y};
  ingredients[2] = {count(s.begin(), s.end(), 'C'), c, z};

  int l = 0, r = 1e15;
  int ans = 0;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    int cost_needed = 0;
    for (int i = 0; i < 3; i++)
    {
      int am = ingredients[i].cost * ingredients[i].burger * mid - ingredients[i].cost * ingredients[i].cur;
      cost_needed += max(0ll, am);
    }

    if (m < cost_needed)
    {
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
      ans = max(ans, mid);
    }
  }
  cout << ans << endl;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}