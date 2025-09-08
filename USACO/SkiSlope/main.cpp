#include <bits/stdc++.h>
using namespace std;
 
const int L = 11;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> p(n+1), d(n+1), w(n+1);
    vector<vector<int>> v(n+1);
    for (int i = 2; i <= n; i++){
        int a, b, c; 
        cin >> a >> b >> c; 
        p[i] = a;
        d[i] = b;
        w[i] = c;
        v[a].push_back(i);
    }
    vector<long long> x(n+1, 0);
    vector<vector<int>> t(n+1);
    function<void(int)> f = [&](int i){
        for (int j : v[i]){
            x[j] = x[i] + w[j];
            t[j] = t[i];
            t[j].push_back(d[j]);
            sort(t[j].begin(), t[j].end(), greater<int>());
            if(t[j].size() > L) t[j].resize(L);
            f(j);
        }
    };
    f(1);
 
    vector<vector<pair<int,long long>>> y(L);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < L; j++){
            int r = 0;
            if(t[i].size() > j) r = t[i][j];
            y[j].push_back({r, x[i]});
        }
    }
    vector<vector<pair<int,long long>>> z(L);
    for (int i = 0; i < L; i++){
        sort(y[i].begin(), y[i].end(), [](auto &p, auto &q){ return p.first < q.first; });
        long long m = -1;
        for(auto &pr : y[i]){
            m = max(m, pr.second);
            z[i].push_back({pr.first, m});
        }
    }
 
    int m; cin >> m;
    while(m--){
        int s, k; 
        cin >> s >> k;
        if(k >= L) k = L-1;
        auto &a = z[k];
        int lo = 0, hi = a.size()-1;
        long long ans = 0;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(a[mid].first <= s){
                ans = a[mid].second;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
