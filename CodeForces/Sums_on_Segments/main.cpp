#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }


  set<int> prevs;
  set<int> ans;
  prevs.insert(0);
  prevs.insert(a[0]);
  ans.insert(0);
  ans.insert(a[0]);
  
  int running = a[0];
  for (int i = 1; i < n; i++)
  {
    running += a[i];
    if (a[i] + a[i - 1] != 0 and a[i] == 1)
    {
      // only grab lowest element
      int el = *prevs.begin();
      ans.insert(running - el);
    }

    else if (a[i] + a[i - 1] != 0 and a[i] == -1)
    {
      // only grab largest element
      int el = *prevs.rbegin();
      ans.insert(running - el);
    }

    else if ((a[i] != 1 and a[i] != -1) or (a[i - 1] != -1 and a[i - 1] != 1))
    {
      for (int el : prevs)
      {
        ans.insert(running - el);
      }
    }

    if (ans.find(running) == ans.end())
    {
      ans.insert(running);
    }
    if (ans.find(a[i]) == ans.end())
    {
      ans.insert(a[i]);
    }

    prevs.insert(running);
  }
  cout << ans.size() << endl;
  for (int el : ans)
  { 
    cout << el << ' ';
  }
  cout << endl;
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