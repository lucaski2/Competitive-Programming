#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

struct c1
{
  bool operator()(const pair<int, int>& a, const pair<int, int>& b)
  {
    return a.first < b.first;
  }
};
struct c2
{
  bool operator()(const pair<int, int>& a, const pair<int, int>& b)
  {
    return a.second > b.second;
  }
};


void solve()
{
  int n;
  cin >> n;
  map<pair<int, int>, int> contained;
  priority_queue<pair<int, int>, vector<pair<int, int>>, c1> max_l;
  priority_queue<pair<int, int>, vector<pair<int, int>>, c2> min_r;

  for (int i = 0; i < n; i++)
  {
    int l, r;
    char c;
    cin >> c >> l >> r;
    if (c == '+')
    {
      max_l.push({l, r});
      min_r.push({l, r});
      contained[{l, r}]++;
    }
    else
    {
      contained[{l, r}]--;
    }

    while (!max_l.empty() and contained[max_l.top()] == 0)
    {
      max_l.pop();
    }
    while (!min_r.empty() and contained[min_r.top()] == 0)
    {
      min_r.pop();
    }
    if (max_l.empty())
    {
      cout << "NO" << en;
    }
    else
    {
      if (max_l.top().first > min_r.top().second)
      {
        cout << "YES" << en;
      }
      else cout << "NO" << en;
    }
    

  }


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}