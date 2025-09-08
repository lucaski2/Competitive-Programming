#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; 
    cin >> t;
    while(t--){
        int n, m; 
        cin >> n >> m;
        vector<long long> cnt(m, 0);
        for (int i = 0; i < n; i++){
            long long x;
            cin >> x;
            cnt[x % m]++;
        }
 
        int ans = 0;
 
        // Special case for remainder 0.
        if(cnt[0] > 0) 
            ans++;
 
        // Process pairs r and m-r.
        // If m is even, we process r = 1,..., m/2 - 1; otherwise, r = 1,..., floor((m-1)/2).
        int lim = (m % 2 == 0 ? m/2 - 1 : m/2);
        for (int r = 1; r <= lim; r++){
            long long a = cnt[r], b = cnt[m - r];
            if(a == 0 && b == 0) continue;
            if(a == 0 || b == 0){
                ans += a + b; // each element must be alone.
            } else {
                // Both groups are nonempty.
                int diff = abs((int)a - (int)b);
                ans += max(1, diff);
            }
        }
 
        // Special case for r = m/2 (only when m is even).
        if(m % 2 == 0 && cnt[m/2] > 0)
            ans++;
 
        cout << ans << "\n";
    }
    return 0;
}
