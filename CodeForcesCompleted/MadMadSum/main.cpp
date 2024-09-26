#include <bits/stdc++.h>
#include <iostream>
#include <set>
#define ll long long

using namespace std;

int sum(vector<int> &a)
{
    int n = a.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}





int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> temp(n);
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll ans = sum(a);

        while (sum(a) != 0)
        {
            s.clear();
            int largest = 0;
            for (int i = 0; i < n; i++)
            {
                if (s.find(a[i]) != s.end() && a[i] > largest)
                {
                    largest = a[i];
                }
                s.insert(a[i]);
                temp[i] = largest;
            }
            a = temp;
            ans += sum(a);
        }

        cout << ans << endl;



    }


}