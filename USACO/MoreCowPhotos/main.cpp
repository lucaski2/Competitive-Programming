#include <bits/stdc++.h>
using namespace std;


int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> counts(n);
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      counts[a - 1]++;
    }
    int longest = 0;
    bool used = false;
    for (int i = n - 1; i >= 0; i--)
    {
      if (counts[i] and !used) 
      {
        longest++;
        used = true;
      }
      else if (counts[i] >= 2) longest += 2;
    }
    cout << longest << '\n';
  }
}
