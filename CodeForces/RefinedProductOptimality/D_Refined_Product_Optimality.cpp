#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
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

void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  vector<pair<int, int>> a(n), b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i].first;
    b[i].second = i;
  }

  // use map to store start index to arr index

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  map<int, int> a_start;
  map<int, int> b_start;
  int cur = 1;
  for (int i = 0; i < n; i++)
  {
    a_start[a[i].second] = i;
    b_start[b[i].second] = i;
    cur *= min(a[i].first, b[i].first);
    cur %= mod;
  }
  cout << cur << ' ';
  for (int i = 0; i < q; i++)
  {
    int type, ind;
    cin >> type >> ind;
    ind--;

    
      
  }
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}