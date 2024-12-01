#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b)
{
    return get<2>(a) < get<2>(b);
}

void solve()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> cows(n);

    for (int i = 0; i < n; i++)
    {
        cin >> get<0>(cows[i]);
    }
    for (int i = 0; i < n; i++)
        cin >> get<1>(cows[i]);
    for (int i = 0; i < n; i++)
        cin >> get<2>(cows[i]);

    sort(cows.begin(), cows.end(), compare);

    int min_time = 0;
    int max_time = 1e9;
    for (int i = 0; i < n - 1; i++)
    {
        // linear equation
        // y = get<1> (cows[i]) * x + get<0> (cows[i])
        // y = get<1> (cows[i + 1]) * x + get<0> (cows[i + 1])
        // cout << (get<0>(cows[i]) - get<0>(cows[i + 1])) / (get<1>(cows[i]) - get<1>(cows[i + 1])) << endl;
        if (get<1>(cows[i]) > get<1>(cows[i + 1]))
        {
            if (get<0>(cows[i]) <= get<0>(cows[i + 1]))
            {
                min_time = max(min_time, 1 + -(int)ceil(((double)get<0>(cows[i]) - (double)get<0>(cows[i + 1])) / ((double)get<1>(cows[i]) - (double)get<1>(cows[i + 1]))));
            }
        }
        else if (get<1>(cows[i]) < get<1>(cows[i + 1]))
        {
            if (get<0>(cows[i]) <= get<0>(cows[i + 1]))
            {
                cout << -1 << endl;
                return;
            }
            max_time = min(max_time, -(int)floor(((double)get<0>(cows[i]) - (double)get<0>(cows[i + 1])) / ((double)get<1>(cows[i]) - (double)get<1>(cows[i + 1]))));
        }
        else
        {
            if (get<0>(cows[i]) <= get<0>(cows[i + 1]))
            {
                cout << "-1" << endl;
                return;
            }
        }
    }
    // cout << min_time << " " << max_time << endl;
    if (min_time >= max_time)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << max(0, min_time) << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}