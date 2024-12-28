#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

bool prime(ll n)
{
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0) return false;
  }
  return true;
}



void solve()
{
  ll n;
  cin >> n;
  if (prime(n)) cout << 1 << endl;
  else if (n % 2 == 0) cout << 2 << endl;
  else if (prime(n - 2)) cout << 2 << endl;
  else cout << 3 << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}