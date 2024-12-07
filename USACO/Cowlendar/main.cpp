#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
  {
    cin >> i;
  }
  vector<ll> no_dup;
  set<ll> s;
  for (int i = 0; i < n; i++)
  {
    if (s.find(a[i]) == s.end())
    {
      no_dup.push_back(a[i]);
      s.insert(a[i]);
    }
  }

  n = no_dup.size();
  a.resize(n);
  for (int i = 0; i < n; i++)
  {
    a[i] = no_dup[i];
  }

  ll max_val = *min_element(a.begin(), a.end()) / 4;

  ll largest = *max_element(a.begin(), a.end());

  ll ans = (max_val + 1) * max_val / 2;
  
  // go through each element up to sqrt(max_val) and check if it is a valid, if not subtract it from ans

  //



}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
