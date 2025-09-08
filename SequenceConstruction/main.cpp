#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int m, k;
  cin >> m >> k;

  // find best
  vector<int> best;
  // for each bit in the popcount, find number for that
  for (int i = 0; i <= 5; i++)
  {
    if (k & (1 << i))
    {
      best.push_back((1 << (1 << i)) - 1);
    }
  }
  int s = 0;
  for (int i = 0; i < best.size(); i++)
    s += best[i];
  
  if (s > m)
  {
    cout << "-1" << endl;
    return;
  }

  // hardest case, if s == m + 1
  // only way to change parity of s is if best[0] == true, if so, you can just idk i have idea i think
  function<void()> printAnswer = [&]()
  {
    cout << best.size() << endl;
    for (int i = 0; i < best.size(); i++)
    {
      cout << best[i] << ' ';
    }
    cout << endl;
  };



  if (s + 1 == m)
  {
    if (best[0] == 1)
    {
      best[0] = 2;
      printAnswer();
      return;
    }
    cout << -1 << endl;
    return;
  }
  else if (s % 2 == m % 2)
  {
    best.push_back((m - s) / 2);
    best.push_back((m - s) / 2);
    printAnswer();
  }
  else
  {
    best.push_back(1);
    best.push_back(2);
    s += 3;
    best.push_back((m - s) / 2);
    best.push_back((m - s) / 2);
    printAnswer();
  }
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
}

