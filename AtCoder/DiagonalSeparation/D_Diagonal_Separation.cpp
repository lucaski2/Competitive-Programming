#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void generateCombinations(int n, int r, vector<vector<int>> &combs, vector<int> &current, int start) {
    if (current.size() == r) {
        combs.push_back(current);
        return;
    }
    for (int i = start; i < n; ++i) {
        current.push_back(i);
        generateCombinations(n, r, combs, current, i + 1);
        current.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Compute the XOR of the entire array
    int full = 0;
    for (int i = 0; i < n; ++i) {
        full ^= a[i];
    }

    // Determine the number of elements to un-XOR
    int effectiveK = (k > n / 2) ? n - k : k;

    // Generate combinations
    vector<vector<int>> combs;
    vector<int> current;
    generateCombinations(n, effectiveK, combs, current, 0);

    // Calculate the maximum XOR value
    int ans = 0;
    for (const auto &comb : combs) {
        int cur = full;
        for (int idx : comb) {
            cur ^= a[idx];
        }
        ans = max(ans, cur);
    }

    cout << ans << endl;
    return 0;
}
