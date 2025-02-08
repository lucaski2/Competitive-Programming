#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

ll pow(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}



void solve()
{
  map<int, int> prev;
  int n, x;
  cin >> n >> x;
  bool ok = false;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if (prev.find(x - a) != prev.end())
    {
      cout << prev[x - a] + 1 << ' ' << i + 1 << endl;
      ok = true;
      break;
    }
    prev[a] = i;
  }
  if (!ok) cout << "IMPOSSIBLE" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--)
  {
      solve();
  }
}