#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<bool> has(n, false);
  vector<vector<int>> positions(n);
  int cnt = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
    if (a[i] == i)
    {
      has[i] = true;
    }
    else cnt++;
  }
  cout << cnt << endl;






}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    //int t; cin >> t;
    //while(t--){
        solve();
    //}
}
