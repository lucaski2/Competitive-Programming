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

struct price
{
  int k, p, val;

  price(int k, int p, int val) : k(k), p(p), val(val) {}

  bool operator<(const price &p) const
  {
    return val > p.val;
  }
};



void solve(int tc)
{
  int n, m;
  cin >> n >> m;

  priority_queue<price> pq;


  for (int i = 0; i < n; i++)
  {
    int p;
    cin >> p;
    pq.push(price(1, p, p));
  }
  int ans = 0;
  while (true)
  {
    price p = pq.top();
    if (p.val > m)
    {
      break;
    }
    pq.pop();

    cout << p.val << " " << p.k << " " << p.p << endl;

    ans++;
    m -= p.val;
    p.k++;
    
    int new_val = p.k * p.k * p.p;
    new_val -= p.val;
    p.val = new_val;

    pq.push(p);
  }
  cout << m << endl;

  cout << ans << endl;
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