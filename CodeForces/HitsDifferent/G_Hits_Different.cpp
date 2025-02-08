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

const int mxn = 1e6;
vector<int> prevs(mxn + 5);


void solve(int tc)
{
  int n;
  cin >> n;

  if (prevs[mxn] != 0)
  {
    cout << prevs[mxn] << endl;
    return;
  }

  // find row
  int row = 1;
  int cur = 1;
  while (cur < n)
  {
    row++;
    cur += row;
  }

  vector<bool> visited(n + 1);

  queue<pair<int, int>> q;
  q.push({n, row});
  visited[n] = true;
  int ans = 0;
  while (!q.empty())
  {
    pair<int, int> a = q.front();
    q.pop();

    ans += a.first * a.first;

    int num1 = a.first - a.second;
    int num2 = a.first - a.second + 1;
    if (num1 > (a.second - 1) * (a.second - 2) / 2 and !visited[num1])
    {
      visited[num1] = true;
      q.push({num1, a.second - 1});
    }
    if (num2 <= (a.second) * (a.second - 1) / 2 and !visited[num2])
    {
      visited[num2] = true;
      q.push({num2, a.second - 1});
    }
  }
  prevs[n] = ans;
  cout << ans << endl;
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