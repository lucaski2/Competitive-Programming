#include <iostream>
#include <cmath>

using namespace std;

int things[200001];
int psum[200002];

int f(int n)
{
    int ret = 0;
    while (n > 0)
    {
        ret++;
        n /= 3;
    }
    return ret;
}


int main() {
    int s = 0;
    for (int i = 1; i < 200001; i++)
    {
        things[i] = f(i);
        s += things[i];
        psum[i] = s;
        // cout << s << endl;
        // if (i > 100)
        // {
        //     break;
        // }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << psum[r] - psum[l - 1] + things[l] << endl;
    }
}