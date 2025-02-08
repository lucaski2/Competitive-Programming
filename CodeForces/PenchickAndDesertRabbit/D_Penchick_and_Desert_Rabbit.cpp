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



void solve(int tc)
{
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }


  reverse(a.begin(), a.end());

  vector<int> mx(n);
  mx[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    mx[i] = max(a[i], mx[i + 1]);
  }


  vector<int> ans(n);
  ans[0] = *max_element(a.begin(), a.end());
  int lowest = a[0];
  for (int i = 1; i < n; i++)
  {
    if (a[i] > lowest or mx[i] > lowest)
    {
      ans[i] = ans[i - 1];
    }
    else
    {
      ans[i] = mx[i];
    }


    lowest = min(lowest, a[i]);
  }

  reverse(ans.begin(), ans.end());
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << ' ';
  }
  cout << endl;



}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}