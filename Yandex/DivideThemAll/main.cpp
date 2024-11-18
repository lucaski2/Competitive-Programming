#include <bits/stdc++.h>
#define ld long double
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<ld, ld>> centers(n);

    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            ld r, x, y;
            cin >> r >> x >> y;
            centers[i] = {x, y};
        }

        if (type == 1)
        {
            vector<pair<ld, ld>> corners(4);
            for (int j = 0; j < 4; j++)
            {
                ld x, y;
                cin >> x >> y;
                corners[j] = {x, y};
            }
            ld x = (corners[0].first + corners[1].first + corners[2].first + corners[3].first) / 4;
            ld y = (corners[0].second + corners[1].second + corners[2].second + corners[3].second) / 4;
            centers[i] = {x, y};
        }
    }
    sort(centers.begin(), centers.end());
    vector<ld> slopes;
    if (n == 1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        ld x1 = centers[i].first;
        ld y1 = centers[i].second;
        ld x2 = centers[i + 1].first;
        ld y2 = centers[i + 1].second;
        ld slope = (y2 - y1) / (x2 - x1);
        slopes.push_back(slope);
    }
    for (int i = 0; i < slopes.size() - 1; i++)
    {
        if (abs(slopes[i] - slopes[i + 1]) > 0.0000001)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;

}



