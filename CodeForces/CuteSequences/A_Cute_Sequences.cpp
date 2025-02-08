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



void solve()
{
  ll a, b, m;
  cin >> a >> b >> m;
  bool ok = false;
  for (ll length = 1; length <= 50; length++) {
    
    ll cur_sum = a;
    ll cur_num = a;

    // check if length is possible
    for (ll i = 1; i < length; i++)
    {
      cur_num = cur_sum + 1;
      cur_sum += cur_num;
    }

    if (cur_num > b)
    {
      continue;
    }

    cur_sum = a, cur_num = a;

    for (ll i = 1; i < length; i++)
    {
      cur_num = cur_sum + m;
      cur_sum += cur_num;
    }

    if (cur_num < b)
    {
      continue;
    }


    ll running_sum = a, last_num = a;

    vector<ll> ans; ans.push_back(a);

    for (ll i = 1; i < length; i++)
    {
      ll l = 1, r = m;
      ll found = -1;
      while (l <= r)
      {
        ll mid = (l + r) / 2;

        // check if too little
        cur_sum = running_sum, cur_num = last_num;
        cur_num = cur_sum + mid;
        cur_sum += cur_num;
        for (ll j = i + 1; j < length; j++)
        {
          cur_num = cur_sum + 1;
          cur_sum += cur_num;
        }
        

        if (cur_num > b)
        {
          r = mid - 1;
        }
        else 
        {
          l = mid + 1;
          found = mid;
        }
      }
      if (found != -1)
      {
        last_num = running_sum + found;
        ans.push_back(last_num);
        running_sum += last_num;
      }
    }

    if (last_num == b)
    {
      if (last_num > 1e14)
      {
        continue;
      }

      cout << length << ' ';
      for (ll am : ans)
      {
        cout << am << ' ';
      }
      cout << endl;
      ok = true;
      break;
    }
  }


  if (!ok)
  {
    cout << -1 << endl;
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