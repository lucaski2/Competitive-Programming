#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> ans;
    long long earliest = 0;
    for (int i = 0; i < 32; i++)
    {
        long long cur = -1;
        vector<long long> cur_ans;
        for (int j = 0; j < n; j++)
        {
            if (a[j] & (1 << i))
            {
                cur_ans.push_back(a[j]);
                if (cur == -1)
                    cur = a[j];
                else
                    cur &= a[j];
            }
        }
        if (cur != -1)
        {
            if ((cur & -cur) > (earliest & -earliest))
            {
                earliest = cur;
                ans = cur_ans;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}