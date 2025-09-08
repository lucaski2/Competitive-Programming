#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 7, k = 6;
  vector<vector<int>> grid(n, vector<int>(k));
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < k; j++)
    {
      if (i == 1 and j == 1)
      {
        grid[i][j] = 1;
      }
      else if (i > 1 and j == 1)
      {
        grid[i][j] = 0;
      }
      else if (i < j) grid[i][j] = 0;
      else
      {
        grid[i][j] = grid[i - 1][j - 1] + grid[i - 1][j] * (j - 1);
      }
    }
  }
  for (int j = 1; j < k; j++)
  {
    for (int i = 1; i < n; i++)
    {
      cout << grid[i][j] << ' ';
    }
    cout << endl;
  }
}


