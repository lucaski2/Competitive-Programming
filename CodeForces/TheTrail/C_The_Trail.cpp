#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';



void solve(ll tc)
{
  ll n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  vector<vector<ll>> grid(n, vector<ll>(m));

  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }







  ll col_s = 0;

  // go through trail
  pair<ll, ll> pos = {0, 0};

  vector<ll> rows(n, 0);
  vector<ll> cols(m, 0);
  vector<ll> row_sum(n, 0);
  vector<ll> col_sum(m, 0);
  rows[0]++; cols[0]++;
  
  for (ll i = 0; i < n + m - 2; i++)
  {
    if (s[i] == 'D')
    {
      pos.first++;
    }
    else pos.second++;

    rows[pos.first]++;
    cols[pos.second]++;
  }

  for (ll i = 0; i < n; i++)
  {
    row_sum[i] = accumulate(grid[i].begin(), grid[i].end(), 0);
  }
  for (ll i = 0; i < m; i++)
  {
    col_sum[i] = 0;
    for (int j = 0; j < n; j++)
    {
      col_sum[i] += grid[j][i];
    }
  }

  
  while (true)
  {
    pos = {0, 0};
    bool something = false;
    // int cnt = 0;
    // cout << rows[pos.first] << ' ' << cols[pos.second] << endl;
    if (rows[pos.first] == 1 and cols[pos.second])
    {
      ll diff = col_s - row_sum[pos.first];
      row_sum[pos.first] += diff;
      col_sum[pos.second] += diff;
      grid[pos.first][pos.second] = diff;       
      rows[pos.first]--;
      cols[pos.second]--;
      something = true;
      // cnt++;
    }
    // cout << rows[pos.first] << ' ' << cols[pos.second] << endl;

    if (cols[pos.second] == 1 and rows[pos.first])
    {
      ll diff = col_s - col_sum[pos.second];
      row_sum[pos.first] += diff;
      col_sum[pos.second] += diff;
      grid[pos.first][pos.second] = diff;
      
      rows[pos.first]--;
      cols[pos.second]--;
      something = true;
      // cnt++;
    }



    for (ll i = 0; i < n + m - 2; i++)
    {
      if (s[i] == 'D')
      {
        pos.first++;
      }
      else pos.second++;
      if (rows[pos.first] == 1 and cols[pos.second])
      {
        // cout << rows[pos.first] << ' ' << cols[pos.second] << endl;

        ll diff = col_s - row_sum[pos.first];
        row_sum[pos.first] += diff;
        col_sum[pos.second] += diff;
        grid[pos.first][pos.second] = diff;       
        rows[pos.first]--;
        cols[pos.second]--;
        something = true;
        // cnt++;
      }
      if (cols[pos.second] == 1 and rows[pos.first])
      {
        // cout << rows[pos.first] << ' ' << cols[pos.second] << endl;

        ll diff = col_s - col_sum[pos.second];
        row_sum[pos.first] += diff;
        col_sum[pos.second] += diff;
        grid[pos.first][pos.second] = diff;
        
        rows[pos.first]--;
        cols[pos.second]--;
        something = true;
        // cnt++;
      }
    }
    // cout << cnt << endl;
    if (!something)
    {
      break;
    }

  }

  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < m; j++)
    {
      cout << grid[i][j] << ' ';
      
    }
    cout << endl;
  }


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  for (ll i = 1; i <= t; i++)
  {
    solve(i);
  }
}