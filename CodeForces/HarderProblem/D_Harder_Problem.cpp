#include <bits/stdc++.h>
#define int long long
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



void solve(int tc)
{
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> not_used;
  for (int i = 0; i < n; i++)
    not_used.insert(i);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
    not_used.erase(a[i]);
  }
  vector<int> b(n);
  set<int> used;
  for (int i = 0; i < n; i++)
  {
    if (used.find(a[i]) == used.end())
    {
      b[i] = a[i];
    }
    else
    {
      b[i] = *not_used.begin();
      not_used.erase(*not_used.begin());
    }
    used.insert(a[i]);
  }

  for (int i = 0; i < n; i++) 
    cout << b[i] + 1 << ' ';
  cout << endl;

}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}