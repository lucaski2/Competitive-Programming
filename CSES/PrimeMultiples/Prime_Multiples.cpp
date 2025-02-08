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



void solve(int tc)
{
  ll n, k;
  cin >> n >> k;
  vector<ll> a(k);

  for (int i = 0; i < k; i++)
  {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 1; i < (1 << k); i++)
  {
    bool ok = true;
    ll cnt = 0;
    ll am = 1;
    for (int j = 0; j < k; j++)
    {
      if ((1 << j) & i)
      {
        if (n / a[j] < am) 
        {
          ok = false;
          break;
        }
        am *= a[j];
        cnt++;
      }

    }
    if (!ok) continue;

    if (cnt % 2 == 0)
    {
      ans -= n / am;
    }
    else ans += n / am;
  }

  cout << ans << endl;




}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}