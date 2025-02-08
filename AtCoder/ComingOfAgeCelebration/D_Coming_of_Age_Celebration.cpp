#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

ll pow(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}



void solve(ll tc)
{
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  vector<ll> has_zero;


  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

  ll am_out = 0;

  for (ll i = 0; i < n; i++)
  {
    while (!pq.empty() and pq.top().first - am_out <= 0)
    {
      pq.pop();
    }
    am_out++;
    pq.push({a[i] + pq.size() + am_out, i});
  }

  vector<ll> ans(n, 0);
  while (!pq.empty())
  {
    ans[pq.top().second] = pq.top().first - am_out;
    pq.pop();
  }

  for (ll i = 0; i < n; i++)
  {
    cout << ans[i] << ' ';
  }
  cout << endl;




}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  for (ll i = 1; i <= t; i++)
  {
    solve(i);
  }
}