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
  vector<int> nodes;
  int a, b, c;
  cin >> a >> b >> c;
  for (int k = 0; k < c; k++) nodes.push_back(0);
  for (int j = 0; j < b; j++) nodes.push_back(1);

  for (int i = 0; i < a; i++) nodes.push_back(2);

  int depth = 0;
  vector<int> cur;
  cur.push_back(nodes.back());
  nodes.pop_back();
  bool ok = true;
  while (!cur.empty())
  {
    vector<int> new_cur;

    for (int node : cur)
    {
      for (int i = 0; i < node; i++)
      {
        if (nodes.empty())
        {
          ok = false;
          break;
        }
        new_cur.push_back(nodes.back());
        nodes.pop_back();
      }
    }
    cur = new_cur;
    depth++;
  }
  // cout << cur.size() << ' ' << nodes.size() << ' ';
  if (!nodes.empty() or !ok)
  {
    cout << -1 << endl;
  }
  else cout << depth - 1 << endl;



}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
      solve();
  }
}