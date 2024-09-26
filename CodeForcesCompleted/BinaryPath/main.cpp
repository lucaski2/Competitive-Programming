#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<string> grid(2);
        for (int i = 0; i < 2; i++) {
            cin >> grid[i];
        }
        
        string smallest = "";
        vector<int> cur = {0, 0};
        
        while (!(cur[0] == 1 && cur[1] == n - 1)) {
            smallest += grid[cur[0]][cur[1]];
            vector<vector<int> > possibilities;
            
            if (cur[1] < n - 1) {
                possibilities.push_back({cur[0], cur[1] + 1});
            }
            if (cur[0] < 1) {
                possibilities.push_back({cur[0] + 1, cur[1]});
            }
            
            if (possibilities.size() == 1) {
                cur = possibilities[0];
            } else if (grid[possibilities[0][0]][possibilities[0][1]] <= grid[possibilities[1][0]][possibilities[1][1]]) {
                cur = possibilities[0];
            } else {
                cur = possibilities[1];
            }
        }
        smallest += grid[cur[0]][cur[1]];
        
        vector<vector<int> > dp(2, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (grid[i][j] == smallest[i + j]) {
                    if (i > 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (j > 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        
        cout << smallest << endl;
        cout << dp[1][n - 1] << endl;
    }
    
    return 0;
}