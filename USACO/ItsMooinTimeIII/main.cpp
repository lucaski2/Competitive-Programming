#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<vector<int>> p(26), r(26);
    for (int i = 0; i < n; i++){
        p[s[i]-'a'].push_back(i);
    }
    for (int c = 0; c < 26; c++){
        for (int i = 0; i < n; i++){
            if(s[i]-'a' != c) r[c].push_back(i);
        }
    }
    auto f = [&](int l, int r_, int c) -> ll {
        auto &v = p[c];
        int L = lower_bound(v.begin(), v.end(), l) - v.begin();
        int R = upper_bound(v.begin(), v.end(), r_) - v.begin();
        if(R - L < 2) return -1LL;
        int i0;
        if(s[l]-'a' != c) i0 = l;
        else {
            auto &w = r[c];
            auto it = lower_bound(w.begin(), w.end(), l);
            if(it == w.end() || *it > r_) return -1LL;
            i0 = *it;
        }
        int k = v[R-1];
        int j_start = upper_bound(v.begin()+L, v.begin()+R, i0) - v.begin();
        if(j_start >= R) return -1LL;
        double t = (i0 + k) / 2.0;
        int pos1 = lower_bound(v.begin()+j_start, v.begin()+R, t) - v.begin();
        ll best = -1;
        for (int d = -1; d <= 0; d++){
            int pos2 = pos1 + d;
            if(pos2 >= j_start && pos2 < R){
                int j = v[pos2];
                if(i0 < j && j < k)
                    best = max(best, (ll)(j - i0) * (k - j));
            }
        }
        return best;
    };
    while(q--){
        int l, r_; cin >> l >> r_; l--; r_--;
        ll ans = -1;
        for(int c = 0; c < 26; c++){
            ans = max(ans, f(l, r_, c));
        }
        cout << ans << "\n";
    }
    return 0;
}
