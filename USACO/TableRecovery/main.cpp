#include <bits/stdc++.h>
#define int long long
using namespace std;

bool valid(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &a)
{

  // Criteria 1: each distinct number in a should have one number pointing to it
  // Criteria 2: the same number in grid should not be pointing to more than one number in a

  map<int, int> pointing;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      // check criteria 2
      if (pointing.find(grid[i][j]) != pointing.end() and pointing[grid[i][j]] != a[i][j])
      {
        return false;
      }
      pointing[grid[i][j]] = a[i][j];
    }
  }

  // map.first is the number in grid which is pointing to map.second in a
  // check criteria 1
  set<int> prevs;

  for (auto map : pointing)
  {
    if (prevs.find(map.second) != prevs.end())
    {
      return false;
    }
    prevs.insert(map.second);
  }

  return true;
}






void solve(int tc)
{
  int n;
  cin >> n;
  // if (n == 1)
  // {
  //   cout << 2 << endl;
  //   return;
  // }
  

  vector<vector<int>> a(n, vector<int>(n));
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  vector<int> order(n);
  for(int i = 0; i < n; i++)
  {
    order[i] = i;
  }

  vector<vector<int>> start(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      start[i][j] = i + j + 2;
    }
  }

  vector<vector<int>> ans(n, vector<int>(n, INT64_MAX));



  do
  {
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
      int ind = order[i];
      for (int j = 0; j < n; j++)
      {
        grid[i][j] = start[ind][j];
      }
    }


    
    // vector<int> column_order(n);
    // for (int i = 0; i < n; i++)
    // {
    //   column_order[i] = i;
    // }

    // do
    // {
    //   vector<vector<int>> new_grid(n, vector<int>(n));
    //   for (int i = 0; i < n; i++)
    //   {
    //     for (int j = 0; j < n; j++)
    //     {
    //       new_grid[i][j] = grid[i][column_order[j]];
    //     }
    //   }

    //   if (valid(n, n, new_grid, a))
    //   {
    //     if (ans > new_grid)
    //     {
    //       ans = new_grid;
    //     }
    //   }
    // } while (next_permutation(column_order.begin(), column_order.end()));

    // use backtracking to try to find the lexographically minimum grid
    
    vector<int> column_order(n);
    for (int i = 0; i < n; i++)
    {
      column_order[i] = i;
    }

    function<void(int)> backtrack = [&](int col)
    {
      if (col == n)
      {
        vector<vector<int>> new_grid(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < n; j++)
          {
            new_grid[i][j] = grid[i][column_order[j]];
          }
        }

        if (valid(n, n, new_grid, a))
        {
          if (ans > new_grid)
          {
            ans = new_grid;
          }
        }
        return;
      }
      else
      {
        vector<vector<int>> new_grid(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < col; j++)
          {
            new_grid[i][j] = grid[i][column_order[j]];
          }
        }
        if (!valid(n, col, new_grid, a))
        {
          return;
        }
      }

      

      for (int i = col; i < n; i++)
      {
        swap(column_order[col], column_order[i]);
        backtrack(col + 1);
        swap(column_order[col], column_order[i]);
      }
      
    };

    backtrack(0);


  }  while (next_permutation(order.begin(), order.end()));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << ans[i][j] << " \n"[j == n - 1];
    }
  }
}


void solve2()
{
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[i][j];
    }
  }


  map<int, int> counts;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      counts[i + j + 2]++;
  
  




}




signed main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  solve(1);
}




