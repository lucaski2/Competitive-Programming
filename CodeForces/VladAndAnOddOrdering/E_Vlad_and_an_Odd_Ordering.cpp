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
  ll n, k;
  cin >> n >> k;
  // check odd 
  if (k <= (n + 1) / 2)
  {
    cout << "1 ";
    cout << k * 2 - 1 << endl;
  }
  else if (k <= (n + 1) / 2 + (n + 2) / 4)
  {
    cout << "2 ";
    cout << 2 + (k - ((n + 1) / 2) - 1) * 4 << endl;
  }

  else 
  {
    cout << "3 ";
    cout << 4 * (k - ((n + 1) / 2 + (n + 2) / 4)) << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}