#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll recursive_search(vector<ll> &apples, ll n, ll sum, ll cur_sum, ll index)
{
    if (index == n)
    {
        return abs(sum - cur_sum - cur_sum);
    }
    return min(recursive_search(apples, n, sum, cur_sum + apples[index], index + 1), recursive_search(apples, n, sum, cur_sum, index + 1));
}


int main()
{
    ll n;
    cin >> n;
    vector<ll> apples(n);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> apples[i];
        s += apples[i];
    }


    ll answer = recursive_search(apples, n, s, 0, 0);
    cout << answer << endl;
}

