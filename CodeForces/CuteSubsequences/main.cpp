#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int s = 0;
  priority_queue<int, vector<int>, greater<int>> st;

  for (int i = 0; i < k; i++)
  {
    st.push(a[i]);
    s += a[i];
  }
  int ans = s + k;

  for (int i = k; i < n; i++)
  {
    ans = max(ans, s - st.top() + a[i] + i + 1);

    s += a[i];
    st.push(a[i]);
    s -= st.top();
    st.pop();
  }

  cout << ans << '\n';
}