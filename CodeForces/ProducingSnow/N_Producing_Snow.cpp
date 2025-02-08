#include <bits/stdc++.h>
#define int long long
using namespace std;

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



void solve(int tc)
{
  int n;
  cin >> n;
  vector<int> v(n), t(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++)
    cin >> t[i];

  int melted = 0;
  priority_queue<int, vector<int>, greater<int>> piles;
  for (int i = 0; i < n; i++)
  { 
    piles.push(v[i] + melted);
    int cur = 0;
    // cout << piles.top() << endl;
    while (!piles.empty() and piles.top() - melted <= t[i])
    {
      cur += piles.top() - melted;
      piles.pop();
    }
    cur += piles.size() * t[i];
    melted += t[i];
    cout << cur << ' ';
  }
  cout << endl;



}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}