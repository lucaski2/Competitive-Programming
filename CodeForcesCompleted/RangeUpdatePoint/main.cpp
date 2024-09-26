#include <bits/stdc++.h>
using namespace std;

int sum_digits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int a[200002];
set<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;
        s.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 9) s.insert(i);
        }

        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int l, r;
                cin >> l >> r;
                l--;
                r--;
                while (l <= r and s.size() > 0)
                {
                    auto cur = s.lower_bound(l);
                    if (cur == s.end() or *cur > r)
                    {
                        break;
                    }
                    int c = *cur;
                    a[c] = sum_digits(a[c]);
                    if (a[c] < 10)
                    {
                        s.erase(c);
                    }
                    l = c + 1;
                }
            }
            else
            {
                int x;
                cin >> x;
                x--;
                cout << a[x] << endl;
            }
        }


    }


}