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
  int k;
  cin >> k;
  string s, t;
  cin >> s >> t;

  if (s.size() == t.size())
  {
    int diff = 0;
    for (int i = 0; i < s.size(); i++)
    {
      diff += s[i] != t[i];
    }
    cout << (diff <= 1 ? "Yes" : "No") << endl;
  }

  else if (s.size() == t.size()  - 1)
  {
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] != t[i])
      {
        s.insert(i, 1, t[i]);
        break;
      }
    }
    if (s.size() != t.size())
    {
      cout << "Yes" << endl;
      return;
    }
    cout << (s == t ? "Yes" : "No") << endl;
  }
  else if (s.size() == t.size() + 1)
  {
    for (int i = 0; i < t.size(); i++)
    {
      if (s[i] != t[i])
      {
        s.erase(i, 1);
        break;
      }
    }
    if (s.size() != t.size())
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << (s == t ? "Yes" : "No") << endl;
    }  
  
  }
  else
  {
    cout << "No" << endl;
  }

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