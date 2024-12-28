#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
  ll n, q;
  cin >> n >> q;
  vector<vector<vector<pair<ll, ll>>>> reversed(n, vector<vector<pair<ll, ll>>>(n));
  vector<tuple<ll, ll, char>> queries(q);
  vector<vector<bool>> part_of_query(n, vector<bool>(n, false));
  vector<pair<ll, ll>> edges;
  for (ll i = 0; i < q; i++)
  {
    ll a, b;
    char c;
    cin >> b >> a >> c;
    a--; b--;

    queries[i] = make_tuple(a, b, c);
    part_of_query[a][b] = true;

    ll dx = 0, dy = 0;
    if (c == 'U')
    {
      dy = -1;
    }
    else if (c == 'D')
    {
      dy = 1;
    }
    else if (c == 'L')
    {
      dx = -1;
    }
    else if (c == 'R')
    {
      dx = 1;
    }

    ll nx = a + dx;
    ll ny = b + dy;
    if (nx >= 0 && nx < n && ny >= 0 && ny < n)
    {
      reversed[nx][ny].push_back(make_pair(a, b));
    }
    else 
    {
      edges.push_back(make_pair(a, b));
    }
  }
  vector<pair<ll, ll>> changes = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < n; j++)
    {
      if (!part_of_query[i][j])
      {
        for (auto change : changes)
        {
          ll dx = change.first;
          ll dy = change.second;
          ll nx = i + dx;
          ll ny = j + dy;
          if (nx >= 0 && nx < n && ny >= 0 && ny < n)
          {
            reversed[nx][ny].push_back(make_pair(i, j));
          }
          else
          {
            edges.push_back(make_pair(i, j));
            break;
          }
        }
      }
    }
  }


  vector<vector<bool>> visited(n, vector<bool>(n, false));
  for (auto edge : edges)
  {
    ll x = edge.first;
    ll y = edge.second;
    if (!visited[x][y])
    {
      queue<pair<ll, ll>> q;
      q.push(make_pair(x, y));
      visited[x][y] = true;
      // cout << x << " " << y << endl;
      while (!q.empty())
      {
        pair<ll, ll> current = q.front();
        q.pop();
        ll cx = current.first;
        ll cy = current.second;
        for (auto next : reversed[cx][cy])
        {
          ll nx = next.first;
          ll ny = next.second;
          if (!visited[nx][ny])
          {
            visited[nx][ny] = true;
            // cout << nx << " " << ny << endl;
            q.push(make_pair(nx, ny));
          }
        }
      }
    }
  }




  ll ans = 0;
  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < n; j++)
    {
      // cout << visited[i][j] << " ";
      ans += 1 - visited[i][j];
    }
    // cout << endl;
  }

  vector<ll> answer(q);
  for (ll i = q - 1; i >= 0; i--)
  {
    answer[i] = ans;
    ll a = get<0>(queries[i]);
    ll b = get<1>(queries[i]);

    if (visited[a][b]) continue;

    bool will_visit = false;
    for (auto change : changes)
    {
      ll dx = change.first;
      ll dy = change.second;
      ll nx = a + dx;
      ll ny = b + dy;
      if (nx >= 0 && nx < n && ny >= 0 && ny < n)
      {
        if (visited[nx][ny])
        {
          will_visit = true;
          break;
        }
        reversed[nx][ny].push_back(make_pair(a, b));
      }
      else will_visit = true;
    }


    if (!will_visit) continue;




    queue<pair<ll, ll>> q;
    q.push(make_pair(a, b));
    visited[a][b] = true;
    ans--;
    while (!q.empty())
    {
      pair<ll, ll> current = q.front();
      q.pop();
      ll cx = current.first;
      ll cy = current.second;
      for (auto next : reversed[cx][cy])
      {
        ll nx = next.first;
        ll ny = next.second;
        if (!visited[nx][ny])
        {
          visited[nx][ny] = true;
          ans--;
          q.push(make_pair(nx, ny));
        }
      }
    }

  }
  for (ll i = 0; i < q; i++) cout << answer[i] << endl;
}