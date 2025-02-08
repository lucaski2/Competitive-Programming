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
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < n; i++)
  {
    if (a[i] > b[i])
    {
      cout << "NO" << en;
      return;
    }
  }






  for (int i = 0; i < n; i++)
  {
    int ind = 0;
    int num = INT32_MAX;


    for (int j = 0; j < n; j++)
    {
      if (a[j] == b[j])
      {
        continue;
      }

      if (b[j] < num)
      {
        num = b[j];
        ind = j;
      }
    }

    if (num == INT32_MAX)
    {
      break;
    }

    // find shit on left
    bool ok = false;
    int end1;
    for (int j = ind - 1; j >= 0; j--)
    {
      if (a[j] > b[ind])
      {
        break;
      }
      if (b[j] < b[ind])
      {
        break;
      }
      if (a[j] == b[ind])
      {
        ok = true;
        end1 = j;
        break;
      }
    }

    bool ok2 = false;
    int end2;
    for (int j = ind + 1; j < n; j++)
    {
      if (a[j] > b[ind]) break;
      if (b[j] < b[ind]) break;
      if (a[j] == b[ind]) 
      {
        ok2 = true;
        end2 = j;
        break;
      }
    }
    // for (int i = 0; i < n; i++)
    //   cout << a[i] << ' ';
    // cout << endl;
    if (ok)
    {
      for (int j = end1; j <= ind; j++)
      {
        a[j] = b[ind];
      }
    }
    else if (ok2)
    {
      for (int j = ind; j <= end2; j++)
      {
        a[j] = b[ind];
      }
    }
    else 
    {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;





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