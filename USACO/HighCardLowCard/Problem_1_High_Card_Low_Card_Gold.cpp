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

  ifstream cin("cardgame.in");
  ofstream cout("cardgame.out");


  int n;
  cin >> n;
  
  set<int> bessie;
  for (int i = 1; i <= n * 2; i++)
  {
    bessie.insert(i);
  }
  vector<int> p1, p2;
  for (int i = 0; i < n / 2; i++)
  {
    int a;
    cin >> a;
    p1.push_back(a);
    bessie.erase(a);
  }

  for (int i = 0; i < n / 2; i++)
  {
    int a;
    cin >> a;
    p2.push_back(a);
    bessie.erase(a);
  }

  sort(p1.begin(), p1.end(), greater<int>());
  sort(p2.begin(), p2.end());
  int ans = 0;
  for (int i = 0; i < n / 2; i++)
  {
    int am = *bessie.rbegin();
    if (am > p1[i])
    {
      ans++;
      bessie.erase(am);
    }
  }

  for (int i = 0; i < n / 2; i++)
  {
    auto it = less_or_equal(bessie, p2[i]);
    if (it)
    {
      ans++;
      bessie.erase(*it);
    }
  }

  cout << ans << en;




}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--)
  {
      solve();
  }
}