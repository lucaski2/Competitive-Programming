#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        unordered_map<int, int> b_counts;
        unordered_map<int, int> current;

        for (int i = 0; i < m; i++)
        {
            b_counts[b[i]]++;
        }

        for (auto x: b_counts)
        {
            current[x.first] = 0;
        }

        int current_amount = 0;
        
        for (int i = 0; i < m; i++)
        {
            if (current.find(a[i]) != current.end())
            {
                current[a[i]]++;
            }
        }

        for (auto x: current)
        {
            current_amount += min(x.second, b_counts[x.first]);
        }

        int ans = current_amount >= k ? 1 : 0;

        for (int i = m; i < n; i++)
        {
            int cur_removing = a[i - m];
            int cur_adding = a[i];
            if (b_counts.find(cur_removing) != b_counts.end())
            {
                current[cur_removing]--;
                if (current[cur_removing] < b_counts[cur_removing])
                {
                    current_amount--;
                }
            }
            if (b_counts.find(cur_adding) != b_counts.end())
            {
                current[cur_adding]++;
                if (current[cur_adding] <= b_counts[cur_adding])
                {
                    current_amount++;
                }
            }
            ans += current_amount >= k ? 1 : 0;
        }
        cout << ans << endl;
    }
}