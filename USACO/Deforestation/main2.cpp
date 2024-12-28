#include <bits/stdc++.h>
using namespace std;


int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    vector<tuple<int, int, int>> restrictions(k);
    for (int i = 0; i < k; i++)
    {
      cin >> get<0>(restrictions[i]) >> get<1>(restrictions[i]) >> get<2>(restrictions[i]);
    }

    sort(restrictions.begin(), restrictions.end());
    sort(a.begin(), a.end());

    // go through each restriction and binary search to find the first element that is greater than or equal to the start and the last element less than or equal to the end

    for (int i = 0; i < k; i++)
    {
      auto left_bound = lower_bound(a.begin(), a.end(), get<0>(restrictions[i]));
      auto right_bound = upper_bound(a.begin(), a.end(), get<1>(restrictions[i]));
      get<2>(restrictions[i]) = (right_bound - left_bound) - get<2>(restrictions[i]);
    }


    int rest_ind = 0;
    int cur_removed = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cur_rests;

    for (int i = 0; i < n; i++)
    {
      while (cur_rests.size() > 0 and cur_rests.top().second < a[i])
      {
        cur_rests.pop();
      }

      while (rest_ind < k and get<0>(restrictions[rest_ind]) <= a[i])
      {
        cur_rests.push({get<2>(restrictions[rest_ind]) + cur_removed, get<1>(restrictions[rest_ind])});
        rest_ind++;
      }

      if (cur_rests.size() == 0 or cur_rests.top().first - cur_removed > 0)
      {
        // cout << cur_rests.size() << ' ' << cur_removed << endl;
        cur_removed++;
      }
      // print all element in cur_rests
      // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp = cur_rests;
      // while (temp.size() > 0)
      // {
      //   cout << temp.top().first << ' ' << temp.top().second << endl;
      //   temp.pop();
      // }
      // cout << endl;


    }
    cout << cur_removed << endl;
  }
}