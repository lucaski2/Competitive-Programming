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

  vector<set<int>> sets(n);
  set<int> contained;
  
  for (int i = 0; i < n; i++)
  {
    int m;
    cin >> m;
    
    for (int j = 0; j < m; j++)
    {
      int a;
      cin >> a;
      sets[i].insert(a);
      contained.insert(a);
    }
  }
  int ans = 0;
  for (int num : contained)
  {
    set<int> cur;

    for (set<int> asdf : sets)
    {
      if (asdf.find(num) != asdf.end())
      {
        continue;
      }

      for (int asdf2 : asdf)
      {
        cur.insert(asdf2);
      }
    }

    ans = max(ans, (int)cur.size());


  }
  cout << ans << endl;
  


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