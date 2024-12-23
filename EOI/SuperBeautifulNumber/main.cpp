#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;

void asdf(set<ll> &bnums, vector<ll> &cur, vector<bool> &used)
{
  if (cur.size() != 0 and cur[0] == 0) return;
  if (cur.size() != 0 and cur[cur.size() - 1] % 2 == 0)
  {
    ll num = 0;
    for (int i = 0; i < cur.size(); i++)
    {
      num += cur[i];
      num *= 10;
    }
    num /= 10;
    bnums.insert(num);
  }
  if (cur.size() == 10)
  {
    return;
  }

  for (int i = 0; i < 10; i++)
  {
    if (!used[i])
    {
      cur.push_back(i);
      used[i] = true;
      asdf(bnums, cur, used);
      used[i] = false;
      cur.pop_back();
    }
  }
}



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  set<ll> things;
  vector<ll> cur;
  vector<bool> used(10, false);
  asdf(things, cur, used);


  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    auto ptr = things.upper_bound(n);
    if (ptr == things.end())
      cout << -1 << en;
    else 
      cout << *ptr << en;
  }
}
