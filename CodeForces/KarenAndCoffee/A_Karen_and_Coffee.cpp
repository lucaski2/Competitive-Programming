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
  int n, k, q;
  cin >> n >> k >> q;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<int> inds;
  int mx = 2e5 + 5;
  int ptr = 0;
  for (int i = 1; i < mx; i++)
  {
    while (!pq.empty() and pq.top() < i)
    {
      pq.pop();
    }

    while (ptr < n and a[ptr].first <= i)
    {
      pq.push(a[ptr].second);
      ptr++;
    }
    if (pq.size() >= k)
    {
      inds.push_back(i);
    }
  }

  while (q--)
  {
    int a, b;
    cin >> a >> b;
    // a--; b--;
    cout << upper_bound(inds.begin(), inds.end(), b) - lower_bound(inds.begin(), inds.end(), a) << endl;
  }

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