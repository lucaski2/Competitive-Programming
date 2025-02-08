#include <bits/stdc++.h>
#define int long long
using namespace std;

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

bool comp(pair<vector<int>, int> a, pair<vector<int>, int> b)
{
  return a.first[0] < b.first[0];
}

void solve(int tc)
{
  int n, m;
  cin >> n >> m;

  vector<pair<vector<int>, int>> a(n, {vector<int>(n), 0});
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i].first[j];
    }
    a[i].second = i;
    sort(a[i].first.begin(), a[i].first.end());
  }

  sort(a.begin(), a.end(), comp);

  for (int i = 0; i < m; i++)
  {
    int last = -1;
    for (int j = 0; j < n; j++)
    {
      cout << a[j].first[i] << ' ' << last << endl;
      if (a[j].first[i] > last)
      {
        last = a[j].first[i];
      }
      else
      {
        cout << "-1" << endl;
        return;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << a[i].second + 1 << " ";
  }
  cout << endl;



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