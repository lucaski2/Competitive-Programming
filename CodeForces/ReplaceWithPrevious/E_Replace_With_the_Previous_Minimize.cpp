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

int find_ind(int ind, vector<set<int>> &chars)
{
  for (int i = 0; i < 26; i++)
  {
    if (chars[i].find(ind) != chars[i].end())
    {
      return i;
    }
  }
}

void solve(int tc)
{
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  k = min(k, 25);
  int cur_ind = 0;
  for (; cur_ind < n; cur_ind++)
  {
    if (s[cur_ind] - 'a' > k)
    {
      break;
    }
  }

  // cout << cur_ind << endl;


  int m = 0;
  for (int i = 0; i < cur_ind; i++)
  {
    m = max(m, s[i] - 'a');
  }

  for (int i = 0; i < n; i++)
  {
    if (s[i] - 'a' <= m)
    {
      s[i] = 'a';
    }
  }


  k -= m;
  // cout << k << endl;

  while (k > 0 and s[cur_ind] != 'a')
  {
    char cur_char = s[cur_ind];
    for (int i = 0; i < n; i++)
    {
      if (s[i] == cur_char)
      {
        s[i]--;
      }
    }
    k--;
  }

  cout << s << endl;






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