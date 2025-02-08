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
  vector<int> b(n); 
  int num = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<int> temp1 = a;
  vector<int> temp2 = b;
  sort(temp1.begin(), temp1.end());
  sort(temp2.begin(), temp2.end());
  for (int i = 0; i < n; i++)
  {
    if (temp1[i] != temp2[i]) 
    {
      cout << "NO" << endl;
      return;
    }
  }

  











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