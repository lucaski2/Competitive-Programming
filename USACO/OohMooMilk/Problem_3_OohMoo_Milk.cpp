#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;
using namespace __gnu_pbds;

template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1000000000 + 7;
const char en = '\n';


void prnt(vector<int> a)
{
  for (int am : a)
  {
    cout << am << ' ';
  }
  cout << endl;
}


int solve(int n, int d, int a, int b, vector<int> &lst)
{
  

  multiset<int> ams;
  for (int i = 0; i < n; i++)
  {
    ams.insert(lst[i]);
  }
  multiset<int> rems1;
  for (int i = 0; i < a; i++)
  {
    rems1.insert(*ams.rbegin() + d);
    ams.erase(ams.find(*ams.rbegin()));
  }

  for (int ele : rems1)
  {
    ams.insert(ele);
  }


  // go until flattens?

  vector<int> elements;
  for (int ele : ams)
  {
    elements.push_back(ele);
  }

  reverse(all(elements));



  // add to [b, a]

  // the elements that are greater than elements[b] will never be decreased enough, so just subtract from final amount

  int am = b * d;
  int start = 0;
  for (int i = 0; i < b; i++)
  {
    if (elements[i] - d > elements[b])
    {
      am -= d;
      elements[i] -= d;
      start++;
    }
  }

  vector<int> psum(n + 1);
  for (int i = 0; i < n; i++)
  {
    psum[i + 1] = psum[i] + elements[i];
  }
  prnt(elements);

  int best = 0; 
  for (int i = start; i < n; i++)
  {
    // if elements from start to i work then stuff yk
    int psum_am = psum[i] - psum[start];
    psum_am -= (i  - start) * elements[i];
    if (psum_am >= am) break;
    // it works i think :pray:
    best = i;
  }

  

  for (int i = start; i < best; i++)
  {
    int diff = elements[i] - elements[best];
    am -= diff;
    elements[i] -= diff;
  }
  prnt(elements);

  // number of elements to decrease is best - start + 1;
  int dec = best - start + 1;
  int start_am = am;
  for (int i = start; i <= best; i++)
  {
    am -= start_am / dec;
    elements[i] -= start_am / dec;
  }
  prnt(elements);
  cout << start << ' ' << best + 1 << endl;
  for (int i = best; i >= start; i--)
  {
    if (am > 0)
    {
      elements[i] -= 1;
      am--;
    }
  }
  prnt(elements);

  cout << am << endl;

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += elements[i] * elements[i];
    ans %= mod;
  }

  prnt(elements);

  return ans % mod;
}


int solve2(int n, int d, int a, int b, vector<int> &lst)
{
  sort(all(lst), greater<int>());

  for (int i = 0; i < a; i++)
  {
    lst[i] += d;
  }
  int mx = b * d;
  int l = 0, r = INT_MAX;
  int best = INT64_MAX;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    vector<int> cur = lst;

    int am = 0;
    for (int i = 0; i < n; i++)
    {
      int ele = min(max(0ll, lst[i] - mid), d);
      am += ele;
      cur[i] -= ele;
    }
    // cout << am << endl;

    if (am <= mx)
    {
      best = min(best, mid);
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }

  int ans = 0;
  // cout << best << endl;
  vector<bool> marked(n);
  for (int i = 0; i < n; i++)
  {
    int ele = min(max(0ll, lst[i] - best), d);
    if (ele == d) marked[i] = true;
    lst[i] -= ele;
    mx -= ele;
  }
  // cout << "best: " << best << endl;

  for (int i = 0; i < n; i++)
  {
    // if (marked[i]) cout << "asdf" << endl;
    if (!marked[i] and mx > 0)
    {
      lst[i]--;
      mx--;
    }
    ans += lst[i] * lst[i];
    // cout << lst[i] << ' ';
    ans %= mod;
  }

  return ans;
}




int naive(int n, int d, int a, int b, vector<int> &lst)
{
  multiset<int> ams;
  for (int i = 0; i < n; i++)
  {
    ams.insert(lst[i]);
  }
  multiset<int> rems1;
  for (int i = 0; i < d; i++)
  {
    for (int i = 0; i < a; i++)
    {
      rems1.insert(*ams.rbegin() + 1);
      ams.erase(ams.find(*ams.rbegin()));
    }

    for (int ele : rems1)
    {
      ams.insert(ele);
    }
    rems1.clear();
  }

  for (int i = 0; i < d; i++)
  {
    for (int i = 0; i < b; i++)
    {
      rems1.insert(*ams.rbegin() - 1);
      ams.erase(ams.find(*ams.rbegin()));
    }

    for (int ele : rems1)
    {
      ams.insert(ele);
    }
    rems1.clear();
  }

  int ans = 0;
  for (int ele : ams)
  {
    ans += ele * ele;
    ans %= mod;
  }

  return ans;
}


void stressTest()
{
  for (int i = 0; i < 100; i++)
  {
    int n = 9, d = 8, a = 5, b = 3;
    vector<int> lst(n);
    for (int j = 0; j < n; j++)
    {
      lst[j] = rand() % 30;
    }
    int am1 = solve(n, d, a, b, lst);
    int am2 = naive(n, d, a, b, lst);
    if (am1 == am2)
    {
      cout << "Test " << i + 1 << " passed" << endl;
    }
    else
    {
      cout << "WRONG" << endl;
      cout << am1 << ' ' << am2 << endl;
      cout << n << ' ' << d << ' ' << a << ' ' << b << endl;
      for (int j = 0; j < n; j++)
        cout << lst[j] << ' ';
      cout << endl;
      return;
    }

  }




}



signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;

  int n, d;
  cin >> n >> d;
  int a, b;
  cin >> a >> b;
  vector<int> lst(n);
  for (int i = 0; i < n; i++)
    cin >> lst[i];
  
  for (int i = 1; i <= t; i++)
  {
    cout << solve2(n, d, a, b, lst) << endl;
  }
  // stressTest();
}