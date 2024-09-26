#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        int m;
        std::cin >> m;

        std::map<int, std::vector<int>> a_counts;
        for (int i = 0; i < n; i++) {
            a_counts[a[i]].push_back(i);
        }

        std::vector<std::vector<int>> a_counts_vec;
        for (const auto& pair : a_counts) {
            a_counts_vec.push_back(pair.second);
        }
        std::sort(a_counts_vec.begin(), a_counts_vec.end());

        for (int i = 0; i < m; i++) {
            std::string s;
            std::cin >> s;

            if (s.length() != n) {
                std::cout << "NO" << std::endl;
                continue;
            }

            std::map<char, std::vector<int>> counts;
            for (int j = 0; j < n; j++) {
                counts[s[j]].push_back(j);
            }

            std::vector<std::vector<int>> counts_vec;
            for (const auto& pair : counts) {
                counts_vec.push_back(pair.second);
            }
            std::sort(counts_vec.begin(), counts_vec.end());

            if (counts_vec == a_counts_vec) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}