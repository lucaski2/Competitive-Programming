#include <bits/stdc++.h>
using ll = long long;
using namespace std;
 
const ll mod = 1000000000 + 7;
const char en = '\n';
 
 
template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}
 
void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }
 
 
  // a[i] = n - i
  // n = a[i] + i
  vector<ll> needed_length(n);
  map<ll, vector<ll>> look;
  for (ll i = 0; i < n; i++)
  {
    needed_length[i] = a[i] + i;
    if (look.find(a[i] + i) == look.end())
    {
      look[a[i] + i] = {i};
    }
    else look[a[i] + i].push_back(i);
  }
  
  vector<bool> visited(n, false);
  ll ans = n;
  for (ll i = 0; i < n; i++)
  {
    if (!visited[i] and needed_length[i] == n)
    {
      queue<pair<ll, ll>> q;
      q.push({i, n + i});
      while (!q.empty())
      {
        pair<ll, ll> cur = q.front();
        q.pop();
        ll _, am;
        tie(_, am) = cur;
        ans = max(ans, am);
        if (look.find(am) != look.end())
        {
          for (ll ind : look[am])
          {
            if (!visited[ind])
            {
              q.push({ind, am + ind});
              visited[ind] = true;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}