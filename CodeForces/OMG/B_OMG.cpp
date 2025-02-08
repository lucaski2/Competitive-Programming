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
  vector<int> a(n);
  map<int, int> counter;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    counter[a[i]]++;
  }

  int front = n - 1;
  for (int i = 0; i < n; i++)
  {
    if (counter[a[i]] != 1)
    {
      front = i;
      break;
    }
  }

  int back = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (counter[a[i]] != 1)
    {
      back = i;
      break;
    }
  }
  front++;
  back++;
  cout << front << ' ' << max(front, back) << endl;
  


}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}