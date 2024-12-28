#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{

  ifstream cin("maxcross.in");
  ofstream cout("maxcross.out");

  int n, k, b;
  cin >> n >> k >> b;

  vector<int> a(n);
  for (int i = 0; i < b; i++)
  {
    int x;
    cin >> x;
    a[x - 1] =  1;
  }

  vector<int> psum(n + 1);
  for (int i = 0; i < n; i++)
  {
    psum[i + 1] = psum[i] + a[i];
  }
  int ans = pow(10, 6);
  for (int i = k; i <= n; i++)
  {
    int am = psum[i] - psum[i - k];
    ans = min(ans, am);
  }
  cout << ans << endl;

  
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
