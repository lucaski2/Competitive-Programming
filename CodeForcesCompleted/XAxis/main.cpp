#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int nums[3];
        cin >> nums[0] >> nums[1] >> nums[2];
        sort(nums, nums + 3);
        int minimum = 100000000;
        for (int i = nums[0]; i <= nums[2]; i++)
        {
            minimum = min(minimum, abs(i - nums[1]) + abs(i - nums[2]) + abs(i - nums[0]));
        }
        cout << minimum << endl;
    }
}