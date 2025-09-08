#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
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
int mx = 2e6;
vector<int> fact(mx + 5), inv(mx + 5);

void precomp()
{
  fact[0] = 1;
  for (int i = 1; i < mx; i++)
  {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
    inv[i] = pow(fact[i], mod - 2, mod);
  }
}

void solve(int tc)
{
  string s; cin >> s;
  int n = s.size();

  int cur = fact[n];
  map<char, int> cnts;
  for (int i = 0; i < n; i++)
  {
    cnts[s[i]]++;
  }
  for (auto it : cnts)
  {
    cur *= inv[it.second];
    cur %= mod;
  }
  cout << cur << endl;

}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  precomp();
  // cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}