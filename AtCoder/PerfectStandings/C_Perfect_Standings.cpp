#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Helper function to generate combinations
void generateCombinations(int n, int r, int index, vector<int>& current, vector<vector<int>>& allCombinations) {
    if (current.size() == r) {
        allCombinations.push_back(current);
        return;
    }
    for (int i = index; i < n; ++i) {
        current.push_back(i);
        generateCombinations(n, r, i + 1, current, allCombinations);
        current.pop_back();
    }
}

int main() {
    vector<int> a(5);
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }

    vector<pair<int, string>> scores;

    for (int i = 1; i <= 5; ++i) {
        vector<vector<int>> combinations;
        vector<int> current;
        generateCombinations(5, i, 0, current, combinations);

        for (const auto& comb : combinations) {
            string cur = "";
            int sum = 0;
            string st = "ABCDE";
            for (int idx : comb) {
                cur += st[idx];
                sum += a[idx];
            }
            scores.push_back({sum, cur});
        }
    }

    // Sort scores in descending order of sums
    sort(scores.begin(), scores.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return (a.first != b.first ? (a.first > b.first) : (a.second < b.second));
    });

    // Print the combinations
    for (const auto& score : scores) {
        cout << score.second << endl;
    }

    return 0;
}
