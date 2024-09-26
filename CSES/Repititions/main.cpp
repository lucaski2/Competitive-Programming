#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    string ss;
    cin >> ss;

    int cur_streak = 1;
    int largest_streak = 0;
    int last = ss[0];

    for (int i = 1; i < ss.size(); i++)
    {
        if (ss[i] == last)
        {
            cur_streak++;
        }
        else
        {
            largest_streak = max(largest_streak, cur_streak);
            cur_streak = 1;
            last = ss[i];
        }
    }
    largest_streak = max(largest_streak, cur_streak);
    cout << largest_streak << endl;
}

