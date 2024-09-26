#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        a[s - 1] = i;
    }
    set<int> st;

    for (int i = 0; i < k; i++)
    {
        st.insert(a[i]);
    }
    int ans = *st.rbegin() - *st.begin();


    for (int i = k; i < n; i++)
    {
        // print st

        // for (auto it : st)
        // {
        //     cout << it << " ";
        // }
        // cout << ans;
        // cout << endl;


        st.insert(a[i]);
        st.erase(a[i - k]);
        ans = min(ans, *st.rbegin() - *st.begin());

    }
    cout << ans << endl;


}