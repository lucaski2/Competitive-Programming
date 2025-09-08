#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second
 
using namespace std;
using namespace __gnu_pbds;
 
template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// Problem URL here:
// Start time here: 
// End time here:
 
const char en = '\n';
 
void solve(int tc)
{
    int l1,b1,l2,b2,l3,b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    vector<pair<int,int>> rects = {{l1,b1}, {l2,b2}, {l3,b3}};
    int ar = l1*b1 + l2*b2 + l3*b3;
    int s = sqrt((long double)ar);
    if (s*s != ar) { cout << "NO" << en; return; }
    bool ok = false;
    if (rects[0].f==s and rects[1].f==s and rects[2].f==s and rects[0].s+rects[1].s+rects[2].s==s) ok = true;
    if (rects[0].s==s and rects[1].s==s and rects[2].s==s and rects[0].f+rects[1].f+rects[2].f==s) ok = true;
    for (int i = 0; i < 3; i++) {
        int l = rects[i].f, b = rects[i].s;
        int j = (i+1)%3, k = (i+2)%3;
        if (l == s) {
            int remH = s - b;
            if (remH > 0 and rects[j].s==remH and rects[k].s==remH and rects[j].f+rects[k].f==s) ok = true;
        }
        if (b == s) {
            int remW = s - l;
            if (remW > 0 and rects[j].f==remW and rects[k].f==remW and rects[j].s+rects[k].s==s) ok = true;
        }
    }
    cout << (ok ? "YES" : "NO") << en;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}
