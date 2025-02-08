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
  int q;
  cin >> q;

  vector<pair<int, int>> qu;
  int ptr = 0;
  int diff = 0;
  for (int i = 0; i < q; i++)
  {
    int type;
    cin >> type;
    if (type == 2)
    {
      diff += qu[ptr].first;
      ptr++;
    }
    else if (type == 1)
    {
      int l;
      cin >> l;
      if (ptr == qu.size())
      {
        qu.push_back({l, 0});
      }
      else 
      {
        qu.push_back({l, qu[qu.size() - 1].first + qu[qu.size() - 1].second});
      }
    }

    else
    {
      int k;
      cin >> k;
      cout << qu[ptr + k - 1].second - diff << endl;;
    }


  }


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