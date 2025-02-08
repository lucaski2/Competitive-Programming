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
  int n;
  cin >> n;

  vector<string> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  bool ok = false;
  for (int i = 0; i < n; i++)
  {
    if (a[i][0] == a[i][a[i].size() - 1])
    {
      ok = true;
    }
  }
  if (ok) 
  {
    cout << "YES" << endl;
    return;
  }

  set<string> prevs;
  for (int i = 0; i < n; i++)
  {
    if (prevs.find(a[i]) != prevs.end())
    {
      cout << "YES" << endl;
      return;
    }

    string cur = a[i];
    reverse(cur.begin(), cur.end());
    prevs.insert(cur);    
  }

  // 2 letters than 3
  prevs.clear();
  for (int i = 0; i < n; i++)
  {
    // insert 2 and look for 3
    if (a[i].size() == 2)
    {
      prevs.insert(a[i]);
    }

    if (a[i].size() == 3)
    {
      string cur = a[i];
      reverse(cur.begin(), cur.end());
      cur.pop_back();
      if (prevs.find(cur) != prevs.end())
      {
        cout << "YES" << endl;
        return;
      }
    }
  }

  prevs.clear();
  for (int i = 0; i < n; i++)
  {
    string cur1 = a[i];
    reverse(cur1.begin(), cur1.end());
    if (prevs.find(cur1) != prevs.end())
    {
      cout << "YES" << endl;
      return;
    }

    string cur = a[i];
    if (cur.size() == 3)
    {
      cur.pop_back();
      prevs.insert(cur);
    }
  }
  cout << "NO" << endl;
  



  







}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}