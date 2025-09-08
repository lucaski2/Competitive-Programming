#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
#define all(a) a.begin(), a.end()
#define f first
#define s second

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
const int mx = 1e5 + 5;
vector<vector<pair<int, int>>> factors(mx);
vector<bool> prime(mx, true);

void solve(int tc)
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }


  // seive
  prime[1] = false;
  for (int i = 2; i < mx; i++)
  {
    if (!prime[i]) continue;
    for (int j = i; j < mx; j += i)
    {
      int cnt = 0;
      int num = j;  
      while (num % i == 0)
      {
        num /= i;
        cnt++;
      }
      cnt %= k;
      if (cnt != 0) factors[j].push_back({i, cnt});
      if (j != i) prime[j] = false;
    }
  }
  int ans = 0;
  map<vector<pair<int, int>>, int> cnts;
  for (int i = 0; i < n; i++)
  {

    vector<pair<int, int>> needed;
    for (pair<int, int> ele : factors[a[i]])
    {
      needed.push_back({ele.f, k - ele.s});
    }
    ans += cnts[needed];
    cnts[factors[a[i]]]++;
  }
  cout << ans << endl;

  
  



}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}