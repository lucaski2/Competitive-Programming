#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int k, m, n;
  cin >> k >> m >> n;
  vector<int> p(k), t(k), f(m);

  for (int i = 0; i < k; ++i) cin >> p[i] >> t[i];
  for (int i = 0; i < m; ++i) cin >> f[i];
  for (int i = 0; i < k; ++i) p[i] *= 2; // To avoid non-integer numbers
  for (int i = 0; i < m; ++i) f[i] *= 2;

  vector<int> cows(n);
  int best = 0;
  for (cows[0] = 0; cows[0] < 30; ++cows[0])
    for (cows[1] = 0; cows[1] < 30; ++cows[1]) {
      int cur = 0;
      for (int patch = 0; patch < k; ++patch) {
        vector<int> our(n);
        for (int i = 0; i < n; ++i) our[i] = abs(cows[i] - p[patch]);
        vector<int> their(m);
        for (int i = 0; i < m; ++i) their[i] = abs(f[i] - p[patch]);
        sort(our.begin(), our.end());
        sort(their.begin(), their.end());
        if (our[0] < their[0]) cur += t[patch];
      }
      best = max(best, cur);
    }
  cout << best << endl;
}