#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int q; cin >> q;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<vector<int>> st(n, vector<int>(ceil(log2(n)) + 1, 0));

  for (int j = 0; j < ceil(log2(n)) + 1; j++)
  {
    for (int i = 0; i + (1 << j) - 1 < n; i++)
    {
      if (j == 0)
        st[i][j] = a[i];
      else
        st[i][j] = st[i][j - 1] ^ st[i + (1 << (j - 1))][j - 1];
    }
  }

  


  for (int i = 0; i < q; i++)
  {
    int l, r;
    cin >> l >> r;
    l--;r--;
    int optimal_length = 1;
    while (optimal_length <= r - l + 1)
     optimal_length *= 2;
    optimal_length /= 2;
    int ind = l + optimal_length;
    int ans = st[l][log2(optimal_length)];
    while (ind < r)
    {
      if (ind + optimal_length > r)
      {
        optimal_length /= 2;
      }
      else
      {
        ans ^= st[ind][log2(optimal_length)];
        cout << st[ind][log2(optimal_length)];
        ind += optimal_length;
      }
    }
    if (ind == r)
    {
      ans ^= a[ind];
    }
    cout << ans << endl;
  }


}


