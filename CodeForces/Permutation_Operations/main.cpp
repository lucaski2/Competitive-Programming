#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n;
  cin >> n;
  
  // on first operation, we add to index where number is n, second where number is 
  map<int, int> indexes;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    indexes[a - 1] = i;
  }

  for (int i = 0; i < n; i++)
  {
    cout << indexes[n - i - 1] + 1 << ' ';
  }
  cout << endl;
  



}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}