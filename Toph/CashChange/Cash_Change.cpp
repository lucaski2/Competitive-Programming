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
  int n;
  cin >> n;
  vector<int> a = {500, 100, 50, 10, 5, 1};
  int ptr = 0;
  vector<int> ans;
  while (n > 0)
  {
    while (a[ptr] > n)
    {
      ptr++;
    }
    ans.push_back(a[ptr]);
    n -= a[ptr];
  }
  for (int i = ans.size() - 1; i >= 0; i--)
  {
    cout << ans[i] << ' ';
  }
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}