#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int cur = 0;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    cur += a;
    cout << a / (i + 1) << ' ';
  }
  cout << endl;



}

