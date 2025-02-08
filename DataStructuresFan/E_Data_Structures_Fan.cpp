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
  vector<vector<int>> psum(n + 1, vector<int>(32, 0));

  for (int i = 0; i < n; i++)
  {
    int c;
    cin >> c;
    a[i] = c;
    for (int j = 0; j < 32; j++)
    {
      if (c & (1 << j))
      {
        psum[i + 1][j] = psum[i][j] + 1;
      }
    }
  }

  vector<bool> s(n);
  for (int i = 0; i < n; i++)
  {
    char c;
    cin >> c;
    s[i] = c - '0';
  }


  int xor1 = 0;
  int xor2 = 0;


  for (int i = 0; i < n; i++)
  {
    if (s[i]) xor1 ^= a[i];
    else xor2 ^= a[i];
  }

  int q; cin >> q;

  for (int i = 0; i < q; i++)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int l, r;
      cin >> l >> r;
      for (int j = 0; j < 32; j++)
      {
        xor1 ^= (1 << j) * ((psum[r][j] - psum[l - 1][j]) % 2);
        xor2 ^= (1 << j) * ((psum[r][j] - psum[l - 1][j]) % 2);
      }
    }
    else
    {
      int asdf;
      cin >> asdf;
      if (asdf == 1)
      {
        cout << xor1 << ' ';
      }
      else cout << xor2 << ' ';
    }
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