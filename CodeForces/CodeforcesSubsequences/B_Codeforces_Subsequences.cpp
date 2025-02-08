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
  ll k;
  cin >> k;
  
  vector<ll> amounts(10, 1);
  ll subs = 1;
  while (subs < k)
  {
    amounts[distance(amounts.begin(), min_element(amounts.begin(), amounts.end()))]++;
    subs = 1;
    for (ll am : amounts)
    {
      subs *= am;
    }
  }
  string s = "codeforces";
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < amounts[i]; j++)
    {
      cout << s[i];
    }
  }
  cout << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  while (t--)
  {
      solve();
  }
}