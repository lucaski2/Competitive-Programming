#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

int pow(int a, int b, int m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}

bool ps(int n)
{
  int root = round(sqrt(n));
  return root * root != n;
}

void solve(int tc)
{
  int n;
  cin >> n;

  vector<int> elements;
  for (int i = 1; i <= n; i++)
    elements.push_back(i);
  

  int s = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (ps(s + elements.back()))
    {
      s += elements.back();
      ans.push_back(elements.back());
      elements.pop_back();
      
    }
    else
    {
      if (elements.size() > 1)
      {
        int el = elements.back();
        elements.pop_back();
        s += elements.back();
        ans.push_back(elements.back());
        elements.pop_back();
        elements.push_back(el);
      }
      else
      {
        cout << "-1" << endl;
        return;
      }
    }
  }

  for (int num : ans)
  {
    cout << num << ' ';
  }
  cout << endl;

}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}