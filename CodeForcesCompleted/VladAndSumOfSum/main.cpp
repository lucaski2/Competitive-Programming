#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int sum_of_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int every_1000 = 0;
    for (int i = 1; i < 1000; i++)
    {
        every_1000 += sum_of_digits(i);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        int cur_num = 0;
        while (n >= 1000)
        {
            ans += every_1000;
            ans += sum_of_digits(cur_num) * 999;
            ans += sum_of_digits(cur_num + 1);
            n -= 1000;
            cur_num++;
        }

        for (int i = cur_num * 1000 + 1; i <= cur_num * 1000 + n; i++)
        {
            ans += sum_of_digits(i);
        }
        cout << ans << endl;


    }


}

