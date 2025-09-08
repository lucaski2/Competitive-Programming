#include <bits/stdc++.h>
// #pragma GCC target ("avx,avx2,fma")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;


const int mod = 1000000000 + 7;
const char en = '\n';

vector<int> a(1001);
void compute()
{
  int mx = 2e8;
  vector<int> cnt(mx);
  for (int i = 1; i < mx; i++)
  {
    for (int j = i; j < mx; j += i)
    {
      cnt[j]++;
    }
    if (cnt[i] > 1000 or a[cnt[i]] > 0) continue;
    a[cnt[i]] = i;
    cout << i << endl;
  }
    ofstream cout("a.out");

  cout << "{";
  for (int i = 0; i < 1000; i++)
    cout << a[i] << ", ";
  cout << a[1000] << "}";
}

void solve(int tc)
{
  int n;
  cin >> n;
  int mx = 8e6;
  vector<int> cnt(mx);
  for (int i = 1; i < mx; i++)
  {
    for (int j = i; j < mx; j += i)
      cnt[j]++;
    if (cnt[i] == n)
    {
      cout << i << endl;
      return;
    }
  }

}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  compute();

  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    // solve(i);
  }
}