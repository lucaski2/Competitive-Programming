#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            std::cin >> temp[i];
        }

        std::vector<std::pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i].first = temp[i] >> 2; // strip last 2 bits
            a[i].second = temp[i];
        }

        std::map<int, std::pair<std::vector<int>, std::vector<int>>> groups;
        for (int i = 0; i < n; i++) {
            int key = a[i].first;
            if (groups.find(key) == groups.end()) {
                groups[key] = {{}, {}};
            }
            groups[key].first.push_back(a[i].second);
            groups[key].second.push_back(i);
        }

        std::vector<int> ans(n, -1);
        for (auto& group : groups) {
            auto& values = group.second.first;
            auto& indices = group.second.second;
            std::sort(values.begin(), values.end());

            for (size_t j = 0; j < values.size(); j++) {
                ans[indices[j]] = values[j];
            }
        }

        for (int val : ans) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
