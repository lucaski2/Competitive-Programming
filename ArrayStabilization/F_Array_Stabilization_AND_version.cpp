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
  int n, d;
  cin >> n >> d;
  vector<bool> a(n);

  for (int i = 0; i < n; i++)
  {
    int c;
    cin >> c;
    a[i] = c == 1;
  }

  vector<bool> visited(n, false);
  int ans = 0;
  bool ok = true;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      vector<bool> cur;

      for (int cur_node = i; !visited[cur_node]; )
      {
        cur.push_back(a[cur_node]);
        visited[cur_node] = 1;
        cur_node = (cur_node + d) % n;
      }

      vector<int> stuff(cur.size(), -1);


      // for (int it : cur)
      // {
      //   cout << it << ' ';
      // }
      // cout << endl;

      if (!count(cur.begin(), cur.end(), false))
      {
        ok = false;
        break;
      }
      int cur_num = 0;
      bool started = false;
      for (int j = 0; stuff[j] == -1; )
      {
        if (!cur[j])
        {
          started = true;
          cur_num = -1;
        }
        if (started)
        {
          cur_num++;
          stuff[j] = cur_num;
        }
        j = (j + 1) % stuff.size();
      }

      ans = max(ans, *max_element(stuff.begin(), stuff.end()));
    }
  }
  cout << (ok ? ans : -1) << endl;








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