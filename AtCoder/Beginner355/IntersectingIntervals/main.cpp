#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

int binary_search(const vector<vector<int> > &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (arr[mid][0] <= target && (mid == arr.size() - 1 || arr[mid+1][0] > target))
        {
            return mid;
        }
        else if (arr[mid][0] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}




int main()
{
    int n;
    cin >> n;
    vector<vector<int> > arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    sort(arr.begin(), arr.end(), sortcol);
    ll s = 0;

    for (int i = 0; i < n; i++)
    {
        int index = binary_search(arr, arr[i][1]);

        s += index - i;
    }
    cout << s << endl;
}








