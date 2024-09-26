#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        vector<int> a(n), b(n);
        int fin;
        map<int, int> nums;
        
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            nums[x]++;
            if (i == m - 1)
            {
                fin = x;
            }
        }
        int no = false;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            if (nums.find(b[i]) != nums.end() and nums[b[i]] > 0)
            {
                nums[b[i]]--;
            }
            else
            {
                cout << "NO" << endl;
                no = true;
                break;
            }
        }
        if (!no)
        {
            if (count(b.begin(), b.end(), fin) == 0)
            {
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
        }
        
    }
}
