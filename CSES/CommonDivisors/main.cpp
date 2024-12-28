#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';



int mxn = 1000005;
vector<int> counts(mxn, 0);


void solve()
{ 
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    counts[a]++;
  }

  for (int i = mxn - 1; i > 0; i--)
  {
    int cnt = 0;
    for (int j = i; j < mxn; j += i)
    {
      cnt += counts[j];
    }
    if (cnt >= 2)
    {
      cout << i << endl;
      break;
    }
  }

  



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
