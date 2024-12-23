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
  vector<int> marbles(n);
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    marbles[a - 1]++;
  }
  int num1 = 0;
  int num2 = 0;
  for (int marble : marbles)
  {
    if (marble == 0) continue;
    else if (marble == 1) num1++;
    else num2++;
  }
  cout << num2 + (num1 + 1) / 2 * 2 << endl;

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