#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

bool is_prime(int n)
{
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}



void solve()
{
  int n;
  cin >> n;
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++)
  {
    ans.push_back({1 + i, 1 + (1 + i) % n});
  }

  for (int i = 0; !is_prime(n + i); i++)
  {
    ans.push_back({1 + i, 1 + n / 2 + i});
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}