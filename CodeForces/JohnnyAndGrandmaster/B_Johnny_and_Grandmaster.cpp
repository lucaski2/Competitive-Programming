#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;
using namespace __gnu_pbds;

template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

long long rng() {
  static std::mt19937 gen(
      std::chrono::steady_clock::now().time_since_epoch().count());
  return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}

// Problem URL here:
// Start time here: 
// End time here:

const int mod = 1000000000 + 7;
const char en = '\n';

int pow(int a, int b, int m){ int ans = 1; while(b) { if (b&1) ans = (ans*a) % m; b /= 2; a = (a*a) % m; } return ans; }


void solve(int tc)
{
  int n, k;
  cin >> n >> k;

  map<int, int> cnts;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    cnts[a]++;
  }


  if (k == 1)
  {
    cout << n % 2 << endl;
    return;
  }

  vector<int> st;
  for (auto e : cnts)
    st.push_back(e.f);
  
  while (st.size())
  {
    // cout << "asdf" << endl;
    // cout << cnts.rbegin()->s << endl;
    if (cnts[st.back()] % 2 == 0)
    {
      st.pop_back();
      continue;
    }

    int needed = k;
    bool ok = false;
    for (int cur = st.back() - 1; cur >= 0; cur--)
    {
      if (cnts[cur] >= needed)
      {
        ok = true;
        break;
      }
      needed -= cnts[cur];

      needed *= k;
      if (needed > n) break;
    }

    if (ok)
    {
      needed = k;
      for (int cur = st.back() - 1; cur >= 0; cur--)
      {
        if (cnts[cur] >= needed)
        {
          cnts[cur] -= needed;
          break;
        }
        needed -= cnts[cur];
        cnts[cur] = 0;

        needed *= k;
        if (needed > n) break;
      }
      st.pop_back();
    }
    else
    {
      break;
    }
    // cout << cnts.size() << endl;
  }

  // cout << ele.size() << endl;
  int ans = 0;
  for (int el : st)
  {
    // cout << el << ' ' << cnts[el] << endl;

    if (el == st.back())
    {
      ans += pow(k, el, mod) * (cnts[el] % 2);  
      ans %= mod;
    }
    else
    {
      ans -= pow(k, el, mod) * cnts[el];
      ans += 1e6 * mod;
      ans %= mod;
    }
    // cout << ans << endl;
  }
  cout << ans << en;

}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}