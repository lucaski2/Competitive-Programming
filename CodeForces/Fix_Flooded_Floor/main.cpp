#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod (pow(10, 9) + 7)
#define en '\n'
using namespace std;


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(2));

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[j][i];
    }
  }

  int type = 0;
  for (int i = 0; i < n; i++)
  {
    if (i == n - 1)
    {
      if ((grid[i][0] == '.') ^ (grid[i][1] == '.'))
      {
        type = 2;
      }
    }
    else if (grid[i][0] == '.' and grid[i][1] == '.')
    {
      if (grid[i + 1][0] == '.' and grid[i + 1][1] == '.')
      {
        type = max(type, 1);

        grid[i + 1][0] = '#';
        grid[i + 1][1] = '#';
      }
    }
    else if (grid[i][0] == '.')
    {
      if (grid[i + 1][0] == '#') type = 2;
      else grid[i + 1][0] = '#';

    }
    else if (grid[i][1] == '.')
    {
      if (grid[i + 1][1] == '#') type = 2;
      else grid[i + 1][1] = '#';
    }

  }
  if (type == 0) cout << "Unique" << endl;
  else if (type == 1) cout << "Multiple" << endl;
  else cout << "None" << endl;

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