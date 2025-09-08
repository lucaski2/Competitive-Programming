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



void solve(int tc)
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  

  vector<int> forward(n);
  for (int i = 0; i < n; i++)
    forward[i] = a[i] + i;
  
  vector<int> backward(n);

  for (int i = n - 1, count = 0; i >= 0; i--, count++)
  {
    backward[i] = a[i] + count;
  }

  vector<int> forward_max(n + 1);
  vector<int> backward_max(n + 1);
  for (int i = 0; i < n; i++)
  {
    forward_max[i] = max((i == 0 ? 0 : forward_max[i - 1]), forward[i]);
  }
  for (int i = n - 1; i >= 0; i--)
  {
    backward_max[i] = max((i == n - 1 ? 0 : backward_max[i + 1]), backward[i]);
  }

  int ans = 0;
  for (int i = 1; i < n - 1; i++)
  {
    ans = max(ans, forward_max[i - 1] + backward_max[i + 1] + a[i] - n + 1);
  }
  cout << ans << endl;


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