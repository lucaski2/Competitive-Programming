#include <bits/stdc++.h>
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#define all(a) (a).begin(), (a).end()
#define f first
#define s second
using namespace std;

const char en = '\n';
static const int MX = 1e6 + 5;
vector<vector<int>> prime(MX);
vector<vector<int>> divisors(MX);

void precomp()
{
  for (int i = 2; i < MX; ++i)
  {
    if (prime[i].empty())
    {
      for (int j = i; j < MX; j += i)
      {
        int cur = j;
        while (cur % i == 0)
        {
          prime[j].push_back(i);
          cur /= i;
        }
      }
    }
  }

  for (int i = 2; i < MX; ++i)
  {
    for (int j = i; j < MX; j += i)
    {
      int cur = j;
      while (cur % i == 0)
      {
        divisors[j].push_back(i);
        cur /= i;
      }
    }
  }
}

int ans;
int k;

void solve(int x)
{
  queue<int> q;
  map<int, int> depth;
  depth[x] = 0;
  q.push(x);
  while (depth.find(1) == depth.end())
  {
    int cur = q.front();
    q.pop();

    for (int div : divisors[cur])
    {
      if (div > k) break;
      int next = cur / div;
      if (depth.find(next) != depth.end()) continue;
      depth[next] = depth[cur] + 1;
      q.push(next);
    }
  }
  ans += depth[1];
}


void solve()
{
  int x, y;
  cin >> x >> y >> k;

  int g = gcd(x, y);
  x /= g;
  y /= g;

  if (x > 1 and *max_element(all(prime[x])) > k or y > 1 and *max_element(all(prime[y])) > k)
  {
    cout << -1 << endl;
    return;
  }

  ans = 0;
  solve(x); solve(y);
  
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  precomp();
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
