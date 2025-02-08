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



int solve()
{
  int n;
  cin >> n;
  int count = 0;
  while (n > 0)
  {
    count += n%2;
    n >>= 1;
  }
  return (1 << count) - 1;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << solve() << endl;
}