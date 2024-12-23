#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  set<pair<int, int>> houses;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    houses.insert({a, b});
  }
  set<pair<int, int>> houses_visited;
  if (houses.find({x, y}) != houses.end())
  {
    houses_visited.insert({x, y});
  }
  for (int i = 0; i < m; i++)
  {
    char dir;
    int am;
    cin >> dir >> am;
    if (dir == 'U')
      y += am;
    else if (dir == 'D')
      y -= am;
    else if (dir == 'L')
      x -= am;
    else 
      x += am;
    if (houses.find({x, y}) != houses.end())
    {
      houses_visited.insert({x, y});
    }
  }
  cout << x << ' ' << y << ' ' << houses_visited.size() << en;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
