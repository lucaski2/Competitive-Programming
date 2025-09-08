#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = -1e18; 

void solve(int tc) {
    ifstream cin("time.in");
    ofstream cout("time.out");
    
    int n, m, c;
    cin >> n >> m >> c;
    
    vector<int> rewards(n);
    for (int i = 0; i < n; i++)
        cin >> rewards[i];
    
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; 
        a--; b--; 
        graph[a].push_back(b);
    }
    
    int mx = 1005;
    vector<vector<int>> dp(mx, vector<int>(n, INF));
    dp[0][0] = 0;
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while (!q.empty()) {
        auto [city, day] = q.front();
        q.pop();
        
        if (day + 1 >= mx) continue;
        
        for (int neighbor : graph[city]) {
            int newReward = dp[day][city] + rewards[neighbor];
            if (newReward > dp[day + 1][neighbor]) {
                dp[day + 1][neighbor] = newReward;
                q.push({neighbor, day + 1});
            }
        }
    }
    

    int ans = 0;
    for (int t = 0; t < mx; t++) {
        if (dp[t][0] != INF)
            ans = max(ans, dp[t][0] - c * t * t);
    }
    
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    for (int i = 1; i <= t; i++){
        solve(i);
    }
    
    return 0;
}
