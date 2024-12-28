#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  deque<pair<ll, ll>> line;
  map<ll, vector<ll>> wins;

  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
    line.push_back({a[i], i});
  }

  for (ll i = 0; i < n; i++)
  {
    pair<ll, ll> p1 = line.front();
    line.pop_front();
    pair<ll, ll> p2 = line.front();
    line.pop_front();

    pair<ll, ll> winner;
    if (p1.first > p2.first)
    {
      winner = p1;
      line.push_back(p2);
    }
    else 
    {
      winner = p2;
      line.push_back(p1);
    }

    wins[winner.second].push_back(i);
    line.push_front(winner);
  }

  for (ll i = 0; i < q; i++)
  {
    ll ind, k;
    cin >> ind >> k;
    ind--; k--;

    ll won = upper_bound(wins[ind].begin(), wins[ind].end(), k) - wins[ind].begin();
    if (a[ind] == n)
    {
      won += max(0ll, k - n + 1);
    }
    cout << won << endl;




  }

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