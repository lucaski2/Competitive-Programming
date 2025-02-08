#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
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

struct sorter
{
  vector<int> &arr;
  map<int, int> mp;
  sorter(vector<int> &a) : arr(a) {
    vector<pair<int, int>> temp;
    for (int i = 0; i < arr.size(); i++)
    {
      temp.push_back({arr[i], i});
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++)
    {
      mp[temp[i].second] = i;
    }
  }

  bool get_ind(int i)
  {
    return arr[mp[i]];
  }
};


void solve(int tc)
{
  int n, q;
  cin >> n >> q;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];


  




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