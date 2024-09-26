#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int> > stages(n - 1, std::vector<int>(3));
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> stages[i][0] >> stages[i][1] >> stages[i][2];
        stages[i][2]--; // Adjusting for 0-based indexing
    }

    std::vector<double> dp(n, std::numeric_limits<double>::infinity());
    dp[0] = 0;

    for (int _ = 0; _ < 1000; ++_) {
        for (int i = 0; i < n - 1; ++i) {
            dp[i + 1] = std::min(dp[i + 1], dp[i] + stages[i][0]);
            dp[stages[i][2]] = std::min(dp[stages[i][2]], dp[i] + stages[i][1]);
        }
    }

    std::cout << dp[n - 1] << std::endl;

    return 0;
}