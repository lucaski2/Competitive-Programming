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



void solve(int tc)
{
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  

  sort(a.begin(), a.end());
  int ptr = 0;

  map<int, int> cur;
  int mult = 0;
  

  for (int i = 0; i < n - m; i++)
  {
    while (a[ptr] - a[i] < m and ptr < n)
    {
      ptr++;
    }
    ptr--;

      


  } 







}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}